/* superrider.c generated by valac, the Vala compiler
 * generated from superrider.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gobject/gvaluecollector.h>


#define SUPERRIDER_TYPE_CLASS (superrider_class_get_type ())
#define SUPERRIDER_CLASS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SUPERRIDER_TYPE_CLASS, SuperriderClass))
#define SUPERRIDER_CLASS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SUPERRIDER_TYPE_CLASS, SuperriderClassClass))
#define SUPERRIDER_IS_CLASS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SUPERRIDER_TYPE_CLASS))
#define SUPERRIDER_IS_CLASS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SUPERRIDER_TYPE_CLASS))
#define SUPERRIDER_CLASS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SUPERRIDER_TYPE_CLASS, SuperriderClassClass))

typedef struct _SuperriderClass SuperriderClass;
typedef struct _SuperriderClassClass SuperriderClassClass;

#define SUPERRIDER_TYPE_MEMBER (superrider_member_get_type ())
#define SUPERRIDER_MEMBER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SUPERRIDER_TYPE_MEMBER, SuperriderMember))
#define SUPERRIDER_MEMBER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SUPERRIDER_TYPE_MEMBER, SuperriderMemberClass))
#define SUPERRIDER_IS_MEMBER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SUPERRIDER_TYPE_MEMBER))
#define SUPERRIDER_IS_MEMBER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SUPERRIDER_TYPE_MEMBER))
#define SUPERRIDER_MEMBER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SUPERRIDER_TYPE_MEMBER, SuperriderMemberClass))

typedef struct _SuperriderMember SuperriderMember;
typedef struct _SuperriderMemberClass SuperriderMemberClass;
typedef struct _SuperriderClassPrivate SuperriderClassPrivate;
#define _g_list_free0(var) ((var == NULL) ? NULL : (var = (g_list_free (var), NULL)))
#define _g_type_class_unref0(var) ((var == NULL) ? NULL : (var = (g_type_class_unref (var), NULL)))
typedef struct _SuperriderMemberPrivate SuperriderMemberPrivate;
typedef struct _SuperriderParamSpecClass SuperriderParamSpecClass;
typedef struct _SuperriderParamSpecMember SuperriderParamSpecMember;

struct _SuperriderClass {
	GTypeInstance parent_instance;
	volatile int ref_count;
	SuperriderClassPrivate * priv;
	GList* members;
	GType type;
	GTypeClass* klass;
};

struct _SuperriderClassClass {
	GTypeClass parent_class;
	void (*finalize) (SuperriderClass *self);
};

struct _SuperriderMember {
	GTypeInstance parent_instance;
	volatile int ref_count;
	SuperriderMemberPrivate * priv;
	GList* chain;
	gint offset;
	SuperriderClass* cl;
};

struct _SuperriderMemberClass {
	GTypeClass parent_class;
	void (*finalize) (SuperriderMember *self);
};

struct _SuperriderParamSpecClass {
	GParamSpec parent_instance;
};

struct _SuperriderParamSpecMember {
	GParamSpec parent_instance;
};


extern GData* superrider_classes;
GData* superrider_classes = {0};
static gpointer superrider_class_parent_class = NULL;
static gpointer superrider_member_parent_class = NULL;

gpointer superrider_class_ref (gpointer instance);
void superrider_class_unref (gpointer instance);
GParamSpec* superrider_param_spec_class (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void superrider_value_set_class (GValue* value, gpointer v_object);
void superrider_value_take_class (GValue* value, gpointer v_object);
gpointer superrider_value_get_class (const GValue* value);
GType superrider_class_get_type (void) G_GNUC_CONST;
void superrider_unref_class (SuperriderClass* cl);
SuperriderClass* superrider_class_new (GType type);
SuperriderClass* superrider_class_construct (GType object_type, GType type);
static void _superrider_unref_class_gdestroy_notify (void* data);
SuperriderClass* superrider_get_class (GType type);
gpointer superrider_member_ref (gpointer instance);
void superrider_member_unref (gpointer instance);
GParamSpec* superrider_param_spec_member (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void superrider_value_set_member (GValue* value, gpointer v_object);
void superrider_value_take_member (GValue* value, gpointer v_object);
gpointer superrider_value_get_member (const GValue* value);
GType superrider_member_get_type (void) G_GNUC_CONST;
SuperriderMember* superrider_class_get_member (SuperriderClass* self, gint offset);
void superrider_member_push (SuperriderMember* self, void* vfunc);
void superrider_superride (GType type, gint offset, void* vfunc);
void* superrider_member_peek_super (SuperriderMember* self);
void* superrider_peek_super (GType type, gint offset);
void* superrider_member_peek_current (SuperriderMember* self);
void* superrider_peek_base (GType type, gint offset);
void superrider_release_all (void);
enum  {
	SUPERRIDER_CLASS_DUMMY_PROPERTY
};
static SuperriderMember* superrider_class_lookup_member (SuperriderClass* self, gint offset);
SuperriderMember* superrider_member_new (SuperriderClass* cl, gint offset);
SuperriderMember* superrider_member_construct (GType object_type, SuperriderClass* cl, gint offset);
GList* superrider_class_get_children (SuperriderClass* self);
static void superrider_class_finalize (SuperriderClass* obj);
enum  {
	SUPERRIDER_MEMBER_DUMMY_PROPERTY
};
static void** superrider_member_pointer (SuperriderMember* self);
void superrider_member_pop (SuperriderMember* self);
static void superrider_member_finalize (SuperriderMember* obj);



void superrider_unref_class (SuperriderClass* cl) {
	superrider_class_unref (cl);
}


static void _superrider_unref_class_gdestroy_notify (void* data) {
	superrider_unref_class (data);
}


SuperriderClass* superrider_get_class (GType type) {
	SuperriderClass* result = NULL;
	SuperriderClass* c;
	c = g_datalist_id_get_data (&superrider_classes, g_type_qname (type));
	if (c == NULL) {
		SuperriderClass* new_c;
		new_c = superrider_class_new (type);
		g_datalist_id_set_data_full (&superrider_classes, g_type_qname (type), new_c, _superrider_unref_class_gdestroy_notify);
		result = new_c;
		return result;
	}
	result = c;
	return result;
}


void superrider_superride (GType type, gint offset, void* vfunc) {
	SuperriderClass* cl;
	SuperriderMember* m;
	cl = superrider_get_class (type);
	m = superrider_class_get_member (cl, offset);
	superrider_member_push (m, vfunc);
}


void* superrider_peek_super (GType type, gint offset) {
	void* result = NULL;
	SuperriderClass* cl;
	SuperriderMember* m;
	cl = superrider_get_class (type);
	m = superrider_class_get_member (cl, offset);
	result = superrider_member_peek_super (m);
	return result;
}


void* superrider_peek_base (GType type, gint offset) {
	void* result = NULL;
	SuperriderClass* cl;
	SuperriderMember* m;
	cl = superrider_get_class (g_type_parent (type));
	m = superrider_class_get_member (cl, offset);
	result = superrider_member_peek_current (m);
	return result;
}


void superrider_release_all (void) {
	g_datalist_clear (&superrider_classes);
}


SuperriderClass* superrider_class_construct (GType object_type, GType type) {
	SuperriderClass* self;
	GTypeClass* _tmp0_;
	self = (SuperriderClass*) g_type_create_instance (object_type);
	self->type = type;
	self->klass = (_tmp0_ = g_type_class_ref (type), _g_type_class_unref0 (self->klass), _tmp0_);
	return self;
}


SuperriderClass* superrider_class_new (GType type) {
	return superrider_class_construct (SUPERRIDER_TYPE_CLASS, type);
}


static SuperriderMember* superrider_class_lookup_member (SuperriderClass* self, gint offset) {
	SuperriderMember* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	{
		GList* m_collection;
		GList* m_it;
		m_collection = self->members;
		for (m_it = m_collection; m_it != NULL; m_it = m_it->next) {
			SuperriderMember* m;
			m = m_it->data;
			{
				if (m->offset == offset) {
					result = m;
					return result;
				}
			}
		}
	}
	result = NULL;
	return result;
}


SuperriderMember* superrider_class_get_member (SuperriderClass* self, gint offset) {
	SuperriderMember* result = NULL;
	SuperriderMember* cm;
	SuperriderMember* new_cm;
	g_return_val_if_fail (self != NULL, NULL);
	cm = superrider_class_lookup_member (self, offset);
	if (cm != NULL) {
		result = cm;
		return result;
	}
	new_cm = superrider_member_new (self, offset);
	self->members = g_list_prepend (self->members, new_cm);
	result = new_cm;
	return result;
}


GList* superrider_class_get_children (SuperriderClass* self) {
	GList* result = NULL;
	GType* _tmp1_;
	gint _type_children_size_;
	gint type_children_length1;
	gint _tmp0_;
	GType* type_children;
	GList* rt;
	g_return_val_if_fail (self != NULL, NULL);
	type_children = (_tmp1_ = g_type_children (self->type, &_tmp0_), type_children_length1 = _tmp0_, _type_children_size_ = type_children_length1, _tmp1_);
	rt = NULL;
	{
		gint i;
		i = 0;
		{
			gboolean _tmp2_;
			_tmp2_ = TRUE;
			while (TRUE) {
				if (!_tmp2_) {
					i++;
				}
				_tmp2_ = FALSE;
				if (!(i < type_children_length1)) {
					break;
				}
				rt = g_list_prepend (rt, superrider_get_class (type_children[i]));
			}
		}
	}
	result = rt;
	type_children = (g_free (type_children), NULL);
	return result;
}


static void superrider_value_class_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void superrider_value_class_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		superrider_class_unref (value->data[0].v_pointer);
	}
}


static void superrider_value_class_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = superrider_class_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer superrider_value_class_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* superrider_value_class_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		SuperriderClass* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = superrider_class_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* superrider_value_class_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	SuperriderClass** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = superrider_class_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* superrider_param_spec_class (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	SuperriderParamSpecClass* spec;
	g_return_val_if_fail (g_type_is_a (object_type, SUPERRIDER_TYPE_CLASS), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer superrider_value_get_class (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SUPERRIDER_TYPE_CLASS), NULL);
	return value->data[0].v_pointer;
}


void superrider_value_set_class (GValue* value, gpointer v_object) {
	SuperriderClass* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SUPERRIDER_TYPE_CLASS));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, SUPERRIDER_TYPE_CLASS));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		superrider_class_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		superrider_class_unref (old);
	}
}


void superrider_value_take_class (GValue* value, gpointer v_object) {
	SuperriderClass* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SUPERRIDER_TYPE_CLASS));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, SUPERRIDER_TYPE_CLASS));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		superrider_class_unref (old);
	}
}


static void superrider_class_class_init (SuperriderClassClass * klass) {
	superrider_class_parent_class = g_type_class_peek_parent (klass);
	SUPERRIDER_CLASS_CLASS (klass)->finalize = superrider_class_finalize;
}


static void superrider_class_instance_init (SuperriderClass * self) {
	self->ref_count = 1;
}


static void superrider_class_finalize (SuperriderClass* obj) {
	SuperriderClass * self;
	self = SUPERRIDER_CLASS (obj);
	{
		{
			GList* m_collection;
			GList* m_it;
			m_collection = self->members;
			for (m_it = m_collection; m_it != NULL; m_it = m_it->next) {
				SuperriderMember* m;
				m = m_it->data;
				{
					superrider_member_unref (m);
				}
			}
		}
	}
	_g_list_free0 (self->members);
	_g_type_class_unref0 (self->klass);
}


GType superrider_class_get_type (void) {
	static volatile gsize superrider_class_type_id__volatile = 0;
	if (g_once_init_enter (&superrider_class_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { superrider_value_class_init, superrider_value_class_free_value, superrider_value_class_copy_value, superrider_value_class_peek_pointer, "p", superrider_value_class_collect_value, "p", superrider_value_class_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (SuperriderClassClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) superrider_class_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SuperriderClass), 0, (GInstanceInitFunc) superrider_class_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType superrider_class_type_id;
		superrider_class_type_id = g_type_register_fundamental (g_type_fundamental_next (), "SuperriderClass", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&superrider_class_type_id__volatile, superrider_class_type_id);
	}
	return superrider_class_type_id__volatile;
}


gpointer superrider_class_ref (gpointer instance) {
	SuperriderClass* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void superrider_class_unref (gpointer instance) {
	SuperriderClass* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		SUPERRIDER_CLASS_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


SuperriderMember* superrider_member_construct (GType object_type, SuperriderClass* cl, gint offset) {
	SuperriderMember* self;
	g_return_val_if_fail (cl != NULL, NULL);
	self = (SuperriderMember*) g_type_create_instance (object_type);
	self->offset = offset;
	self->cl = cl;
	return self;
}


SuperriderMember* superrider_member_new (SuperriderClass* cl, gint offset) {
	return superrider_member_construct (SUPERRIDER_TYPE_MEMBER, cl, offset);
}


static void** superrider_member_pointer (SuperriderMember* self) {
	void** result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = (void**) (((gchar*) self->cl->klass) + self->offset);
	return result;
}


void superrider_member_push (SuperriderMember* self, void* vfunc) {
	GList* children;
	g_return_if_fail (self != NULL);
	self->chain = g_list_prepend (self->chain, *superrider_member_pointer (self));
	children = superrider_class_get_children (self->cl);
	{
		GList* ccl_collection;
		GList* ccl_it;
		ccl_collection = children;
		for (ccl_it = ccl_collection; ccl_it != NULL; ccl_it = ccl_it->next) {
			SuperriderClass* ccl;
			ccl = (SuperriderClass*) ccl_it->data;
			{
				SuperriderMember* m;
				m = superrider_class_get_member (ccl, self->offset);
				if (superrider_member_peek_current (m) == (*superrider_member_pointer (self))) {
					superrider_member_push (m, vfunc);
				}
			}
		}
	}
	*superrider_member_pointer (self) = vfunc;
	_g_list_free0 (children);
}


void superrider_member_pop (SuperriderMember* self) {
	g_return_if_fail (self != NULL);
	if (self->chain != NULL) {
		*superrider_member_pointer (self) = self->chain->data;
		self->chain = g_list_delete_link (self->chain, self->chain);
	}
}


void* superrider_member_peek_current (SuperriderMember* self) {
	void* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = *superrider_member_pointer (self);
	return result;
}


void* superrider_member_peek_super (SuperriderMember* self) {
	void* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	if (self->chain != NULL) {
		result = self->chain->data;
		return result;
	}
	result = NULL;
	return result;
}


static void superrider_value_member_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void superrider_value_member_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		superrider_member_unref (value->data[0].v_pointer);
	}
}


static void superrider_value_member_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = superrider_member_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer superrider_value_member_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* superrider_value_member_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		SuperriderMember* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = superrider_member_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* superrider_value_member_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	SuperriderMember** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = superrider_member_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* superrider_param_spec_member (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	SuperriderParamSpecMember* spec;
	g_return_val_if_fail (g_type_is_a (object_type, SUPERRIDER_TYPE_MEMBER), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer superrider_value_get_member (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SUPERRIDER_TYPE_MEMBER), NULL);
	return value->data[0].v_pointer;
}


void superrider_value_set_member (GValue* value, gpointer v_object) {
	SuperriderMember* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SUPERRIDER_TYPE_MEMBER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, SUPERRIDER_TYPE_MEMBER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		superrider_member_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		superrider_member_unref (old);
	}
}


void superrider_value_take_member (GValue* value, gpointer v_object) {
	SuperriderMember* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SUPERRIDER_TYPE_MEMBER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, SUPERRIDER_TYPE_MEMBER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		superrider_member_unref (old);
	}
}


static void superrider_member_class_init (SuperriderMemberClass * klass) {
	superrider_member_parent_class = g_type_class_peek_parent (klass);
	SUPERRIDER_MEMBER_CLASS (klass)->finalize = superrider_member_finalize;
}


static void superrider_member_instance_init (SuperriderMember * self) {
	self->ref_count = 1;
}


static void superrider_member_finalize (SuperriderMember* obj) {
	SuperriderMember * self;
	self = SUPERRIDER_MEMBER (obj);
	{
		while (TRUE) {
			if (!(self->chain != NULL)) {
				break;
			}
			*superrider_member_pointer (self) = self->chain->data;
			self->chain = g_list_delete_link (self->chain, self->chain);
		}
	}
	_g_list_free0 (self->chain);
}


GType superrider_member_get_type (void) {
	static volatile gsize superrider_member_type_id__volatile = 0;
	if (g_once_init_enter (&superrider_member_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { superrider_value_member_init, superrider_value_member_free_value, superrider_value_member_copy_value, superrider_value_member_peek_pointer, "p", superrider_value_member_collect_value, "p", superrider_value_member_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (SuperriderMemberClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) superrider_member_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SuperriderMember), 0, (GInstanceInitFunc) superrider_member_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType superrider_member_type_id;
		superrider_member_type_id = g_type_register_fundamental (g_type_fundamental_next (), "SuperriderMember", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&superrider_member_type_id__volatile, superrider_member_type_id);
	}
	return superrider_member_type_id__volatile;
}


gpointer superrider_member_ref (gpointer instance) {
	SuperriderMember* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void superrider_member_unref (gpointer instance) {
	SuperriderMember* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		SUPERRIDER_MEMBER_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}




