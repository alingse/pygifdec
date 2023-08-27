
#include <Python.h>
#include "./pygifdec.h"


static PyMethodDef pygifdecMethods[] = {};

static struct PyModuleDef pygifdec_module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_doc = "",
    .m_name = "pygifdec",
    .m_methods = pygifdecMethods,
};

PyMODINIT_FUNC PyInit_pygifdec(void) {
  return PyModule_Create(&pygifdec_module);
}
