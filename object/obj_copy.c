#include <mruby.h>

int
main(void)
{
  mrb_state *mrb = mrb_open();

  mrb_value str = mrb_str_new_lit(mrb, "hoge");
  MRB_SET_FROZEN_FLAG(mrb_obj_ptr(str));

  mrb_value str_clone = mrb_obj_clone(mrb, str);
  mrb_value str_dup = mrb_obj_dup(mrb, str);

  if (MRB_FROZEN_P(mrb_basic_ptr(str_clone))) {
    printf("str_clone is frozen.\n");
  }

  if (MRB_FROZEN_P(mrb_basic_ptr(str_dup))) {
    printf("str_dup is frozen.\n");
  }

  mrb_close(mrb);
  return 0;
}
