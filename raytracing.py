import tkinter as tk
import logging

WINDOW_WIDTH = 200
WINDOW_HEIGHT = 200
WINDOW_SCALE = 3

log = logging.Logger("main", logging.INFO)

def viewport_to_canvas(x, y):
    return {"x": x * WINDOW_SCALE, "y": y * -WINDOW_SCALE, "d": 1}


def put_pixel(canvas: tk.Canvas, x: int, y: int, color: str):
    canvas_coordinates = viewport_to_canvas(x, y)
    scaled_pixel_width = 1 * WINDOW_SCALE
    canvas.create_rectangle (
        WINDOW_SCALE * WINDOW_WIDTH  / 2 + canvas_coordinates['x'] - scaled_pixel_width / 2,
        WINDOW_SCALE * WINDOW_HEIGHT / 2 + canvas_coordinates['y'] - scaled_pixel_width / 2,
        WINDOW_SCALE * WINDOW_WIDTH  / 2 + canvas_coordinates['x'] + scaled_pixel_width - scaled_pixel_width / 2,
        WINDOW_SCALE * WINDOW_HEIGHT / 2 + canvas_coordinates['y'] + scaled_pixel_width - scaled_pixel_width / 2 ,
        fill=color
    )


def draw_viewport(canvas: tk.Canvas):
    x_midpoint = WINDOW_WIDTH * WINDOW_SCALE / 2 
    y_midpoint = WINDOW_HEIGHT * WINDOW_SCALE / 2
    color = "#444444"
    canvas.create_line(x_midpoint, 0, x_midpoint, WINDOW_HEIGHT * WINDOW_SCALE, fill = color)
    canvas.create_line(0, y_midpoint, WINDOW_WIDTH * WINDOW_SCALE, y_midpoint, fill=color)


def render(canvas):
    draw_viewport(canvas)
    put_pixel(canvas, 50,50, "#FFFFFF")

if __name__ == "__main__":
    window = tk.Tk()
    canvas = tk.Canvas(window, width=WINDOW_WIDTH * WINDOW_SCALE, height=WINDOW_HEIGHT * WINDOW_SCALE, bg="#000000")
    log.info("Created canvas")

    render(canvas)

    canvas.pack()
    window.mainloop()

