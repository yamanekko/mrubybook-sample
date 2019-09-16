#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/string.h>

int
main(void)
{
  mrb_state *mrb = mrb_open();

  const char *s1 = "ABCD";
  mrb_value str = mrb_str_new_cstr(mrb, s1);

  char *s01 = mrb_str_to_cstr(mrb, str);

  char *s11 = RSTRING_PTR(str);
  int len11 = RSTRING_LEN(str);

  char *s02 = mrb_str_to_cstr(mrb, str);
  char *s12 = RSTRING_PTR(str);
  int len12 = RSTRING_LEN(str);

  printf("s01:'%s' at %p\n", s01, s01);
  printf("s02:'%s' at %p\n", s02, s02);
  printf("s11:'%s' at %p len=%d\n", s11, s11, len11);
  printf("s12:'%s' at %p len=%d\n", s12, s12, len12);

  mrb_close(mrb);
  return 0;
}
