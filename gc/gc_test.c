#include <mruby.h>
#include <mruby/compile.h>

int
main(void)
{
  mrb_state *mrb = mrb_open();

  mrb_load_string(mrb, "puts 'gc disable'");
  mrb->gc.disabled = TRUE; // GCを止める

  mrb_full_gc(mrb); // 呼んでもGCされない

  mrb_load_string(mrb, "puts 'gc enable'");
  mrb->gc.disabled = FALSE; // GCを許可する

  mrb_full_gc(mrb); // GCされる

  mrb_close(mrb);
  return 0;
}
