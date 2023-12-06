#include <Python.h>
#include <object.h>
#include "gifdec.h"

typedef struct GIF
{
    PyObject_HEAD;
    PyObject *width;
    PyObject *height;
    gd_GIF *gd_GIF_ptr;
} GIF;

static PyObject *GIF_close(PyObject *self, PyObject *args)
{
    GIF *gif = (GIF *)self;
    // printf("in close function the gd_GIF pointer is %d \n", gif->gd_GIF_ptr);
    gd_close_gif(gif->gd_GIF_ptr);
    Py_RETURN_NONE;
}

static PyMethodDef methods_of_GIF[] = {
    {"close", GIF_close, METH_NOARGS, "close the gif"},
    {NULL, NULL, 0, NULL}};

static PyTypeObject PyGIF = {
    PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "pygifdec.GIF",
    .tp_basicsize = sizeof(GIF),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_doc = "GIF object",
    .tp_methods = methods_of_GIF,
};

static PyObject *open_gif(PyObject *self, PyObject *args)
{
    const char *fname;
    if (!PyArg_ParseTuple(args, "s", &fname))
    {
        return NULL;
    }
    gd_GIF *gif = gd_open_gif(fname);
    if (gif == NULL)
    {
        Py_RETURN_NONE;
    }

    GIF *result = (GIF *)PyObject_New(GIF, &PyGIF);
    result->gd_GIF_ptr = gif;
    // printf("in open fucntion the gd_GIF pointer is %d \n", result->gd_GIF_ptr);
    return (PyObject *)result;
}

static PyMethodDef methods[] = {
    {"open", open_gif, METH_VARARGS, "open a GIF object"},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef pygifdec = {
    PyModuleDef_HEAD_INIT, "pygifdec", NULL, -1, methods};

PyMODINIT_FUNC PyInit_pygifdec(void)
{
    PyObject *module = PyModule_Create(&pygifdec);
    if (PyType_Ready(&PyGIF) < 0)
        return NULL;

    Py_INCREF(&PyGIF);
    PyModule_AddObject(module, "GIF", (PyObject *)&PyGIF);

    return PyModule_Create(&pygifdec);
}
