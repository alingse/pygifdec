from distutils.core import setup, Extension

pygifdec = Extension('pygifdec',
                     sources=['./src/pygifdec.c', './src/gifdec.c'],
                     include_dirs=['./src'])

setup(name='pygifdec',
      version='0.0.1',
      description='a pygifdec',
      ext_modules=[pygifdec])
