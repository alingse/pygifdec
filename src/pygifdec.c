#include <Python.h>

static PyObject* add(PyObject* self, PyObject* args) {
    double a, b, result;
    if (!PyArg_ParseTuple(args, "dd", &a, &b)) {
        return NULL;
    }
    result = a+b;
    return Py_BuildValue("d", result);
}

static PyMethodDef methods[] = {
    {"add", add, METH_VARARGS, "add functions"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef pygifdec = {
    PyModuleDef_HEAD_INIT, "pygifdec", NULL, -1, methods
};

PyMODINIT_FUNC PyInit_pygifdec(void) {
    return PyModule_Create(&pygifdec);
}
