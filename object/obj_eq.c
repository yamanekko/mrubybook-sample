#include <mruby.h>

int
main(void)
{
  mrb_state *mrb = mrb_open();

  mrb_value str1 = mrb_str_new_lit(mrb, "hi");
  mrb_value str2 = mrb_str_new_lit(mrb, "hi");

  printf("mrb_obj_equal:%d\n", mrb_obj_equal(mrb, str1, str2));
  printf("mrb_obj_eq:%d\n", mrb_obj_eq(mrb, str1, str2));
  printf("mrb_equal:%d\n", mrb_equal(mrb, str1, str2));
  printf("mrb_eql:%d\n", mrb_eql(mrb, str1, str2));

  mrb_close(mrb);
  return 0;
}
