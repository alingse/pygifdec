from distutils.core import setup, Extension

pygifdec = Extension('pygifdec',
                     sources=['./src/pygifdec.c', './src/gifdec.c'],
                     include_dirs=['./src'],
                     headers=["src/gifdec.h"],
                     # extra_compile_args=['-g', '-shared', '-fPIC'],
                     )

setup(name='pygifdec',
      version='0.0.2',
      description='a pygifdec',
      ext_modules=[pygifdec],
      packages=['src'],
      package_data={'src': ['gifdec.h']},
      )
