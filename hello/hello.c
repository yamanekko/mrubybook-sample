#include <mruby.h>
#include <mruby/compile.h>

int
main(void)
{
  mrb_state *mrb = mrb_open();
  mrb_load_string(mrb, "p 'Hello, World!'");
  mrb_close(mrb);
  return 0;
}
