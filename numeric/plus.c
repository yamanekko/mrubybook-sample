#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/numeric.h>

int
main(void)
{
  mrb_value val;
  mrb_state *mrb = mrb_open();

  mrb_value n1 = mrb_fixnum_value(12);
  mrb_value n2 = mrb_fixnum_value(34);
  val = mrb_num_add(mrb, n1, n2);
  mrb_p(mrb, val);
  val = mrb_num_mul(mrb, n1, n2);
  mrb_p(mrb, val);
  mrb_close(mrb);
  return 0;
}
