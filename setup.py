from distutils.core import setup, Extension

pygifdec = Extension('pygifdec',
                     sources=['./src/pygifdec.c'],
                     include_dirs=['./src/include/'])

setup(name='pygifdec',
      version='1.0',
      description='a python wrapper for gifdec',
      ext_modules=[pygifdec])
