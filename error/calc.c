#include <math.h>
#include <mruby.h>
#include <mruby/numeric.h>
#include <mruby/compile.h>
#include <mruby/error.h>

mrb_value
body1_func(mrb_state *mrb, mrb_value arg)
{
  mrb_float flt = mrb_as_float(mrb, arg);
  if (flt < 0) {
    mrb_raisef(mrb, E_ARGUMENT_ERROR, "out of domain: %S", mrb_float_value(mrb, flt));
  } else {
    return mrb_float_value(mrb, sqrt(flt));
  }
}

static mrb_value
ensure_func(mrb_state *mrb, mrb_value arg)
{
  mrb_load_string(mrb, "puts '...calc done.'");
  return arg;
}

mrb_value
rescue_func(mrb_state *mrb, mrb_value arg)
{
  mrb_load_string(mrb, "puts 'ERROR!'");
  return arg;
}

mrb_value
body0_func(mrb_state *mrb, mrb_value arg)
{
  mrb_value val;
  mrb_value nil = mrb_nil_value();
  struct RClass *e_class = E_ARGUMENT_ERROR;

  mrb_load_string(mrb, "puts '...calc started.'");
  val = mrb_rescue_exceptions(mrb, body1_func, arg, rescue_func, nil, 1, &e_class);
  if (mrb_test(val)) {
    mrb_p(mrb, val);
  }
  return val;
}

mrb_value
calc_sqrt(mrb_state *mrb, mrb_value self)
{
  mrb_value arg;
  mrb_value nil = mrb_nil_value();

  mrb_get_args(mrb, "o", &arg);
  return mrb_ensure(mrb, body0_func, arg, ensure_func, nil);
}

int
main(void)
{
  mrb_state *mrb = mrb_open();

  struct RClass *c = mrb_define_class(mrb, "Calc", mrb->object_class);
  mrb_define_class_method(mrb, c, "sqrt", calc_sqrt, MRB_ARGS_REQ(1));

  mrb_load_string(mrb, "Calc.sqrt(2.0)");
  mrb_load_string(mrb, "Calc.sqrt(-1.0)");

  mrb_close(mrb);
  return 0;
}
