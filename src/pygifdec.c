#include "pygifdec.h"
#include "gifdec.h"

PyMODINIT_FUNC PyInit_pygifdec(void) {
  return PyModule_Create(&pygifdec_module);
}

static PyObject *open(PyObject * self, PyObject *args) {
  const char * fname;
  PyObject *to_return;

  if (!PyArg_ParseTuple(args, "s", &fname)) {
    return NULL;
  }
  gd_GIF * ret = gd_open_gif(fname);
  to_return = Py_BuildValue("O", ret);
  return to_return;
}
