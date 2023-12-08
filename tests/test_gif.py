import pygifdec


def test_all():
    gif = pygifdec.open("cube.gif")
    gif.close()
