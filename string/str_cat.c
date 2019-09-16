#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/string.h>

int
main(void)
{
  mrb_state *mrb = mrb_open();

  mrb_value str = mrb_str_new_lit(mrb, "str1");

  const char *s2 = "str2";
  mrb_str_cat(mrb, str, s2, 4);

  const char *s3 = "str3";
  mrb_str_cat_cstr(mrb, str, s3);

  mrb_str_cat_lit(mrb, str, "str4");

  mrb_value str5 = mrb_str_new_lit(mrb, "str5");
  mrb_str_cat_str(mrb, str, str5);

  mrb_p(mrb, str);

  mrb_close(mrb);
  return 0;
}
