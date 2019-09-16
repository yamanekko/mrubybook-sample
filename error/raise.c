#include <mruby.h>
#include <math.h>

mrb_value
sqrt_or_error(mrb_state *mrb, mrb_value self)
{
  mrb_float flt;

  mrb_get_args(mrb, "f", &flt);
  if (flt < 0) {
    mrb_raisef(mrb, E_ARGUMENT_ERROR, "out of domain: %S", mrb_float_value(mrb, flt));
  } else {
    return mrb_float_value(mrb, sqrt(flt));
  }
}

int
main(void)
{
  mrb_value val;
  mrb_state *mrb = mrb_open();

  struct RClass *c = mrb_define_class(mrb, "Foo", mrb->object_class);
  mrb_define_class_method(mrb, c, "sqrt", sqrt_or_error, MRB_ARGS_NONE());

  val = mrb_funcall(mrb, mrb_obj_value(c), "sqrt", 1, mrb_float_value(mrb, 2.0));
  mrb_p(mrb, val);
  val = mrb_funcall(mrb, mrb_obj_value(c), "sqrt", 1, mrb_float_value(mrb, -1.0));
  if (mrb->exc) {
    mrb_print_error(mrb);
  } else {
    mrb_p(mrb, val);
  }

  mrb_close(mrb);
  return 0;
}
