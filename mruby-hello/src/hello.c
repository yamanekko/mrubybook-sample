#include <mruby.h>
#include <mruby/compile.h>

static mrb_value
mrb_mruby_hello_initialize(mrb_state *mrb, mrb_value self)
{
  return self;
}

static mrb_value
mrb_mruby_hello_world(mrb_state *mrb, mrb_value self)
{
  return mrb_load_string(mrb, "p 'Hello, World!'");
}

void
mrb_mruby_hello_gem_init(mrb_state* mrb)
{
  struct RClass *class = mrb_define_class(mrb, "Hello", mrb->object_class);
  mrb_define_method(mrb, class, "initialize", mrb_mruby_hello_initialize, MRB_ARGS_NONE());
  mrb_define_method(mrb, class, "hello_world", mrb_mruby_hello_world, MRB_ARGS_NONE());
}

void
mrb_mruby_hello_gem_final(mrb_state *mrb)
{
}
