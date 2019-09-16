#include <mruby.h>

mrb_value
mk_str(mrb_state *mrb, mrb_int n)
{
  char buf[256];

  snprintf(buf, sizeof(buf), "string-%ld", n);
  return mrb_str_new_cstr(mrb, buf);
}

int
main(void)
{
  mrb_state *mrb = mrb_open();
  int arena_idx = mrb_gc_arena_save(mrb);

  for (mrb_int i; i <= 120; i++) {
    mrb_value val = mk_str(mrb, i);
    mrb_p(mrb, val);
    mrb_gc_arena_restore(mrb, arena_idx);
  }

  mrb_close(mrb);
  return 0;
}
