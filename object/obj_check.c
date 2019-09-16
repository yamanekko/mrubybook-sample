#include <mruby.h>

int
main(void)
{
  mrb_state *mrb = mrb_open();

  mrb_value str = mrb_str_new_lit(mrb, "S");

  printf("mrb_string_p:%d\n", mrb_string_p(str));
  printf("mrb_hash_p:%d\n", mrb_hash_p(str));

  printf("mrb_nil_p:%d\n", mrb_nil_p(mrb_nil_value()));
  printf("mrb_true_p:%d\n", mrb_true_p(mrb_true_value()));

  printf("mrb_test:%d\n", mrb_test(mrb_fixnum_value(1)));
  printf("mrb_test:%d\n", mrb_test(mrb_false_value()));

  mrb_close(mrb);
  return 0;
}
