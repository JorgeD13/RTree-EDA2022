# Import the required libraries
from tkinter import *

# Create an instance of tkinter frame or window
win=Tk()

# Set the size of the window
win.geometry("900x600")

# Define a function to draw the line between two points
def draw_line(event):
   x1=event.x
   y1=event.y
   x2=event.x
   y2=event.y
   # Draw an oval in the given co-ordinates
   canvas.create_oval(x1,y1,x2,y2,fill="black", width=10)

def delete_line(event):
   # Delete all points
   canvas.delete('all')

def draw_polygon_start(event):
   x, y = event.x, event.y
   if canvas.old_coords:
      x1, y1 = canvas.old_coords
      canvas.create_line(x, y, x1, y1)
   else:
      canvas.start_coords = x, y
   canvas.old_coords = x, y
   canvas.points.append((x, y))

def draw_polygon_end(event):
   if len(canvas.points) > 1:
      draw_polygon_start(event)
      x1, y1 = canvas.start_coords
      x2, y2 = canvas.old_coords
      canvas.create_line(x1, y1, x2, y2)
      canvas.old_coords = None
      canvas.start_coords = None
      draw_bounding_box()

def draw_bounding_box():
   min_x = 100000
   min_y = 100000
   max_x = -100000
   max_y = -100000

   for item in canvas.points:
      if item[0] < min_x:
         min_x = item[0]
      if item[0] > max_x:
         max_x = item[0]
      if item[1] < min_y:
         min_y = item[1]
      if item[1] > max_y:
         max_y = item[1]

   canvas.create_rectangle(min_x, max_y, max_x, min_y, outline="#ff0000")
   canvas.points = []

# Create a canvas widget
canvas=Canvas(win, width=900, height=600, background="white")
canvas.grid(row=0, column=0)
canvas.pack()

# polygon variables
canvas.start_coords = None
canvas.old_coords = None
canvas.points = []

canvas.focus_set()
canvas.bind('<Button-1>', draw_line)
canvas.bind('<Button-3>', delete_line)
canvas.bind('<a>', draw_polygon_start)
canvas.bind('<s>', draw_polygon_end)

click_num=0

win.mainloop()