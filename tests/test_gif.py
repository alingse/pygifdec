import pygifdec


def test_all():
    gif = pygifdec.open("cube.gif")
    assert gif.width == 500
    assert gif.height == 500
    assert gif.size == 500 * 500 * 3

    frame = bytearray(gif.size)
    gif.render_frame(frame)
    gif.get_frame()
    gif.render_frame(frame)

    gif.close()
