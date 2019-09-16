#include <mruby.h>
#include <mruby/compile.h>

int
main(void)
{
  mrb_value val;
  mrb_state *mrb = mrb_open();

  mrbc_context *cxt = mrbc_context_new(mrb);
  val = mrb_load_string_cxt(mrb, "a = 2*3", cxt);
  mrb_p(mrb, val);
  val = mrb_load_string_cxt(mrb, "a1", cxt);
  if (mrb->exc) {
    printf("tt:%d, class:%s\n", mrb->exc->tt, mrb_class_name(mrb, mrb->exc->c));
    mrb_print_error(mrb);
  } else {
    mrb_p(mrb, val);
  }

  mrbc_context_free(mrb, cxt);
  mrb_close(mrb);
  return 0;
}
