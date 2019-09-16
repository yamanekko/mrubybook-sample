#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/class.h>

int
main(void)
{
  mrb_state *mrb = mrb_open();

  struct RClass *foo_class = mrb_define_class(mrb, "Foo", mrb->object_class);
  struct RClass *buz_mod = mrb_define_module_under(mrb, foo_class, "Buz");
  struct RClass *bar_class = mrb_define_class_under(mrb, buz_mod, "Bar", mrb->object_class);

  printf("name: %s\n", mrb_class_name(mrb, bar_class));
  struct RClass *module1 = mrb_class_outer_module(mrb, bar_class);
  printf("name: %s\n", mrb_class_name(mrb, module1));
  struct RClass *class2 = mrb_class_outer_module(mrb, module1);
  printf("name: %s\n", mrb_class_name(mrb, class2));

  mrb_close(mrb);
  return 0;
}
