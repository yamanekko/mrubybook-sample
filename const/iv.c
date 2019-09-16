#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/class.h>
#include <mruby/variable.h>
#include <mruby/string.h>

static mrb_value
mrb_foo_output_name(mrb_state *mrb, mrb_value self)
{
  mrb_value name;
  name = mrb_iv_get(mrb, self, mrb_intern_lit(mrb, "@name"));
  printf("name: %s\n", mrb_str_to_cstr(mrb, name));
  return self;
}

static mrb_value
mrb_foo_set_name(mrb_state *mrb, mrb_value self)
{
  mrb_value obj;
  mrb_get_args(mrb, "o", &obj);

  mrb_iv_set(mrb, self, mrb_intern_lit(mrb, "@name"), obj);
  return self;
}

int
main(void)
{
  mrb_state *mrb = mrb_open();

  struct RClass *foo_class = mrb_define_class(mrb, "Foo", mrb->object_class);
  mrb_define_method(mrb, foo_class, "output_name", mrb_foo_output_name, MRB_ARGS_NONE());
  mrb_define_method(mrb, foo_class, "name=", mrb_foo_set_name, MRB_ARGS_REQ(1));

  mrb_load_string(mrb, "foo=Foo.new;foo.name='foo_name';foo.output_name");

  mrb_close(mrb);
  return 0;
}
