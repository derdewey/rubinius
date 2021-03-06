#include <string.h>

#include "ruby.h"
#include "rubyspec.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef HAVE_RB_PROC_NEW
VALUE proc_spec_concat_func(VALUE args) {
  int i;
  char buffer[500] = {0};
  for(i = 0; i < RARRAY_LEN(args); ++i) {
    VALUE v = RARRAY_PTR(args)[i];
    strcat(buffer, StringValuePtr(v));
    strcat(buffer, "_");
  }
  buffer[strlen(buffer) - 1] = 0;
  return rb_str_new2(buffer);

}

VALUE proc_spec_underline_concat_proc(VALUE self) {
  return rb_proc_new(proc_spec_concat_func, Qnil);
}
#endif

VALUE proc_spec_rb_Proc_new_helper(void) {
  return rb_funcall(rb_cProc, rb_intern("new"), 0);
}

VALUE proc_spec_rb_Proc_new(VALUE self, VALUE do_call) {
  if(RTEST(do_call)) {
    rb_funcall(self, rb_intern("nil?"), 0);
  }

  return proc_spec_rb_Proc_new_helper();
}

void Init_proc_spec() {
  VALUE cls;
  cls = rb_define_class("CApiProcSpecs", rb_cObject);

#ifdef HAVE_RB_PROC_NEW
  rb_define_method(cls, "underline_concat_proc", proc_spec_underline_concat_proc, 0);
#endif

  rb_define_method(cls, "rb_Proc_new", proc_spec_rb_Proc_new, 1);
}

#ifdef __cplusplus
}
#endif
