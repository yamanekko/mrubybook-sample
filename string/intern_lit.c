#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/string.h>

int
main(void)
{
  mrb_state *mrb = mrb_open();

  mrb_sym sym = mrb_intern_lit(mrb, "ABCD");
  mrb_value val = mrb_symbol_value(sym);
  mrb_p(mrb, val);

  mrb_sym sym2 = mrb_symbol(val);
  const char *str = mrb_sym2name(mrb, sym2);
  printf("sym : %d\n", sym);
  printf("sym2: %d\n", sym2);
  printf("name: '%s'\n", str);

  mrb_close(mrb);
  return 0;
}
