#include <mruby.h>

void
define_foo_buz(mrb_state *mrb)
{
  struct RClass *foo_class = mrb_define_class(mrb, "Greeting", mrb->object_class);
  mrb_define_module_under(mrb, foo_class, "Hello");
  return;
}

int
main(void)
{
  mrb_state *mrb = mrb_open();

  define_foo_buz(mrb);

  struct RClass * parent_class = mrb_class_get(mrb, "Greeting");
  struct RClass * hello_module = mrb_module_get_under(mrb, parent_class, "Hello");
  struct RClass * world_class = mrb_define_class_under(mrb,  hello_module, "World", mrb->object_class);

  printf("name: %s\n", mrb_class_name(mrb, world_class));

  mrb_close(mrb);
  return 0;
}
