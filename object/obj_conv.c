#include <mruby.h>
#include <mruby/array.h>
#include <mruby/hash.h>
#include <mruby/string.h>
#include <mruby/class.h>

int
main(void)
{
  mrb_state *mrb = mrb_open();

  mrb_value str = mrb_str_new_lit(mrb, "hi");
  const mrb_value vals[] = {str};
  mrb_value ary = mrb_ary_new_from_values(mrb, 1, vals);
  mrb_value hsh = mrb_hash_new(mrb);
  mrb_hash_set(mrb, hsh, str, mrb_fixnum_value(42));
  mrb_value cls = mrb_obj_value(mrb->object_class);

  struct RString *rstr = mrb_str_ptr(str);
  struct RArray *rary = mrb_ary_ptr(ary);
  struct RHash *rhsh = mrb_hash_ptr(hsh);
  struct RClass *rcls = mrb_class_ptr(cls);

  mrb_p(mrb, mrb_obj_value(rstr));
  mrb_p(mrb, mrb_obj_value(rary));
  mrb_p(mrb, mrb_obj_value(rhsh));
  mrb_p(mrb, mrb_obj_value(rcls));

  mrb_close(mrb);
  return 0;
}
