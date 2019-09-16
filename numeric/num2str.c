#include <mruby.h>
#include <mruby/numeric.h>

int
main(void)
{
  mrb_state *mrb = mrb_open();

  mrb_int i1 = 123;
  mrb_value x1 = mrb_fixnum_value(i1);
  mrb_float f1 = 4.56;
  mrb_value y1 = mrb_float_value(mrb, f1);
  mrb_value val_x = mrb_fixnum_to_str(mrb, x1, 10);
  mrb_value val_y = mrb_float_to_str(mrb, y1, "%1.1f");
  mrb_p(mrb, val_x);
  mrb_p(mrb, val_y);

  mrb_close(mrb);
  return 0;
}
