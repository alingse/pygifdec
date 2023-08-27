from distutils.core import setup, Extension

pygifdec = Extension('pygifdec',
                     sources=['./src/gifdec.c'],
                     include_dirs=['./src/'])

setup(name='pygifdec',
      version='1.0',
      description='a python wrapper for gifdec',
      ext_modules=[pygifdec])
