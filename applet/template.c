/* template.c generated by valac, the Vala compiler
 * generated from template.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>

#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))



#define TEMPLATE_NORMAL 0
#define TEMPLATE_KEYWORD 1
char* template_replace (const char* template, char** subs, int subs_length1);
char* template_replace_simple (const char* template, const char* keyword, const char* value);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);



char* template_replace_simple (const char* template, const char* keyword, const char* value) {
	char* result = NULL;
	char** _tmp1_;
	gint _subs_size_;
	gint subs_length1;
	char** _tmp0_ = NULL;
	char** subs;
	g_return_val_if_fail (template != NULL, NULL);
	g_return_val_if_fail (keyword != NULL, NULL);
	g_return_val_if_fail (value != NULL, NULL);
	subs = (_tmp1_ = (_tmp0_ = g_new0 (char*, 2 + 1), _tmp0_[0] = g_strdup (keyword), _tmp0_[1] = g_strdup (value), _tmp0_), subs_length1 = 2, _subs_size_ = subs_length1, _tmp1_);
	result = template_replace (template, subs, subs_length1);
	subs = (_vala_array_free (subs, subs_length1, (GDestroyNotify) g_free), NULL);
	return result;
}


char* template_replace (const char* template, char** subs, int subs_length1) {
	char* result = NULL;
	const char* p;
	gunichar c = 0U;
	gint state;
	const char* keyword;
	gunichar keyword_open;
	GString* sb;
	g_return_val_if_fail (template != NULL, NULL);
	p = template;
	state = TEMPLATE_NORMAL;
	keyword = NULL;
	keyword_open = (gunichar) 0;
	sb = g_string_new ("");
	while (TRUE) {
		if (!(0 != (c = g_utf8_get_char (p)))) {
			break;
		}
		switch (state) {
			case TEMPLATE_NORMAL:
			{
				switch (c) {
					case '@':
					case '%':
					{
						keyword_open = c;
						keyword = p;
						state = TEMPLATE_KEYWORD;
						break;
					}
					default:
					{
						g_string_append_unichar (sb, c);
						break;
					}
				}
				break;
			}
			case TEMPLATE_KEYWORD:
			{
				switch (c) {
					default:
					{
						if (c == keyword_open) {
							gboolean found;
							found = FALSE;
							{
								gint i;
								i = 0;
								{
									gboolean _tmp0_;
									_tmp0_ = TRUE;
									while (TRUE) {
										const char* st_keyword;
										const char* st_value;
										const char* pp;
										const char* qq;
										gunichar cc;
										gunichar dd;
										if (!_tmp0_) {
											i = i + 2;
										}
										_tmp0_ = FALSE;
										if (!(i < subs_length1)) {
											break;
										}
										st_keyword = subs[i];
										st_value = subs[i + 1];
										pp = keyword;
										qq = st_keyword;
										cc = (gunichar) 0;
										dd = (gunichar) 0;
										while (TRUE) {
											gboolean _tmp1_ = FALSE;
											if (0 != (cc = g_utf8_get_char (pp))) {
												_tmp1_ = 0 != (dd = g_utf8_get_char (qq));
											} else {
												_tmp1_ = FALSE;
											}
											if (!_tmp1_) {
												break;
											}
											if (cc != dd) {
												break;
											}
											qq = g_utf8_next_char (qq);
											pp = g_utf8_next_char (pp);
										}
										if (dd == 0) {
											g_string_append (sb, st_value);
											found = TRUE;
											break;
										}
									}
								}
							}
							if (!found) {
								g_string_append_unichar (sb, c);
								g_string_append (sb, keyword);
								g_string_append_unichar (sb, c);
							}
							state = TEMPLATE_NORMAL;
							keyword = NULL;
						}
						break;
					}
				}
				break;
			}
		}
		p = g_utf8_next_char (p);
	}
	result = g_strdup (sb->str);
	_g_string_free0 (sb);
	return result;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}




