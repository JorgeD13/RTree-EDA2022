# Import the required libraries
from tkinter import *
from tkinter import ttk
from math import inf

# Create an instance of tkinter frame or window
win=Tk()

# Set the size of the window
win.geometry("1000x1000")

# Define a function to draw the line between two points
def draw_line(event):
   x1=event.x
   y1=event.y
   x2=event.x
   y2=event.y
   # Draw an oval in the given co-ordinates
   canvas.create_oval(x1,y1,x2,y2,fill="black", width=10, tags="ovals")



# Second Canvas
options = Canvas(win, width=290, height=900, background="#eeeeee")

#Add a Label widget in the Canvas
label = Label(options, text= "A simple R-TREE visualization")# 🥺 😖")
label.pack(pady= 30)

#Define a function for exit
def exit_program():
   win.destroy()

#Create Grid
def create_grid(event=None):
    w = canvas.winfo_width() # Get current width of canvas
    h = canvas.winfo_height() # Get current height of canvas
    canvas.delete('grid_line') # Will only remove the grid_line

    # Creates all vertical lines at intevals of 100
    for i in range(0, w, 30):
        canvas.create_line([(i, 0), (i, h)], tag='grid_line', fill='#bdbdbe')

    # Creates all horizontal lines at intevals of 100
    for i in range(0, h, 30):
        canvas.create_line([(0, i), (w, i)], tag='grid_line', fill='#bdbdbe')


def delete_ovals(event):
   x1=event.x
   y1=event.y
   x2=event.x
   y2=event.y   
   # Delete all points
   canvas.delete('ovals')


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
   min_x = inf
   min_y = inf
   max_x = -inf
   max_y = -inf

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
canvas = Canvas(win, height=900, width=690, bg='white')

# polygon variables
canvas.start_coords = None
canvas.old_coords = None
canvas.points = []

canvas.focus_set()

canvas.pack(side="right", fill="both", expand=True)
canvas.bind('<Configure>', create_grid)
canvas.bind('<Button-1>', draw_line)
canvas.bind('<Button-3>', delete_ovals)
canvas.bind('<a>', draw_polygon_start)
canvas.bind('<s>', draw_polygon_end)
click_num=0



#Create a button in canvas widget
options.pack(side="left", fill="both", expand=True)
# ttk.Button(options, text= "Clear", command= delete_ovals).pack()


ttk.Button(options, text= "Exit", command= exit_program).pack()

win.mainloop()







