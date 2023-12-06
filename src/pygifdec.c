#include <Python.h>
#include "gifdec.h"
#include <object.h>

static PyObject *add(PyObject *self, PyObject *args)
{
    double a, b, result;
    if (!PyArg_ParseTuple(args, "dd", &a, &b))
    {
        return NULL;
    }
    result = a + b;
    return Py_BuildValue("d", result);
}

static PyMethodDef methods_of_GIF[] = {
    {NULL, NULL, 0, NULL}};

static PyTypeObject GIF = {
    PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "pygifdec.GIF",
    .tp_basicsize = sizeof(gd_GIF),
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
    gd_GIF *result = PyObject_New(gd_GIF, &GIF);
    //*result = *gif;
    // copy
    result->fd = gif->fd;
    result->anim_start = gif->anim_start;

    result->width = gif->width;
    result->height = 0;
    // result->height = 1;
    /*
    result->depth = gif->depth;

result->loop_count = gif->loop_count;
result->gce = gif->gce;
result->lct = gif->lct;
result->gct = gif->gct;
result->plain_text = gif->plain_text;
result->comment = gif->comment;
result->application = gif->application;
result->fx = gif->fx;
result->fy = gif->fy;
result->fw = gif->fw;
result->fh = gif->fh;
result->bgindex = gif->bgindex;
*/
    /*
    // Copy the dynamically allocated memory (if any)
    result->palette = malloc(sizeof(gd_Palette));
    if (result->palette == NULL)
    {
        // Failed to allocate memory
        free(result);
        return NULL;
    }
    memcpy(result->palette, gif->palette, sizeof(gd_Palette));

    // Allocate memory for canvas and frame
    result->canvas = malloc(gif->width * gif->height);
    if (result->canvas == NULL)
    {
        // Failed to allocate memory
        free(result->palette);
        free(result);
        return NULL;
    }
    memcpy(result->canvas, gif->canvas, gif->width * gif->height);

    result->frame = malloc(gif->width * gif->height);
    if (result->frame == NULL)
    {
        // Failed to allocate memory
        free(result->canvas);
        free(result->palette);
        free(result);
        return NULL;
    }
    memcpy(result->frame, gif->frame, gif->width * gif->height);
    */
    return (PyObject *)result;
}

static PyMethodDef methods[] = {
    {"add", add, METH_VARARGS, "add functions"},
    {"open_gif", open_gif, METH_VARARGS, "open_gif"},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef pygifdec = {
    PyModuleDef_HEAD_INIT, "pygifdec", NULL, -1, methods};

PyMODINIT_FUNC PyInit_pygifdec(void)
{
    PyObject *module = PyModule_Create(&pygifdec);
    if (PyType_Ready(&GIF) < 0)
        return NULL;

    Py_INCREF(&GIF);
    PyModule_AddObject(module, "GIF", (PyObject *)&GIF);

    return PyModule_Create(&pygifdec);
}
