import pygifdec
from pygifdec import *

import unittest


class TestAll(unittest.TestCase):
    """test case for multiples args kwargs functions"""

    def test_open(self):
        g = pygifdec.open('./cube.gif')
