#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/value.h>
#include <mruby/variable.h>

int
main(void)
{
  mrb_value val;
  mrb_state *mrb = mrb_open();

  mrb_load_string(mrb, "module SugoiModule;class Util;def self.sugoi_classmethod;p 1;end;end;end");

  mrb_value my_module = mrb_const_get(mrb, mrb_obj_value(mrb->object_class), mrb_intern_lit(mrb, "SugoiModule"));
  val = mrb_funcall(mrb, mrb_const_get(mrb, my_module, mrb_intern_lit(mrb, "Util")), "sugoi_classmethod", 0, NULL);

  mrb_p(mrb, val);
  mrb_close(mrb);
  return 0;
}
