#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/array.h>

int
main(void)
{
  mrb_value val;
  mrb_state *mrb = mrb_open();

  val = mrb_load_string(mrb, "1+2");
  mrb_p(mrb, val);

  mrbc_context *cxt = mrbc_context_new(mrb);
  val = mrb_load_string_cxt(mrb, "a = 2*3", cxt);
  mrb_p(mrb, val);
  val = mrb_load_string_cxt(mrb, "a", cxt);
  mrb_p(mrb, val);

  mrbc_context_free(mrb, cxt);
  mrb_close(mrb);
  return 0;
}
