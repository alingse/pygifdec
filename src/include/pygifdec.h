#include <Python.h>

static PyObject *open(PyObject * self, PyObject *args);

static PyMethodDef pygifdecMethods[] = {
    {
        .ml_name = "open",
        .ml_doc = "open gif file",
        .ml_meth = (PyCFunction)open,
        .ml_flags = METH_VARARGS,
    },
};

static struct PyModuleDef pygifdec_module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_doc = "",
    .m_name = "pygifdec",
    .m_methods = pygifdecMethods,
};

PyMODINIT_FUNC PyInit_pygifdec(void);
