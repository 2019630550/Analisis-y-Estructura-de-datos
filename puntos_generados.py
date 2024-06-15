import tkinter as tk
import random

#dimencion de la ventana
WINDOW_WIDTH = 600
WINDOW_HEIGHT = 400

#Cantidad de puntos
NUM_PUNTOS = 100
#Radio de los puntos
POINT_RADIUS = 5

#Funcion para generar un punto aleatorio
def generate_random_point():
    x = random.randint(POINT_RADIUS, WINDOW_WIDTH - POINT_RADIUS)
    y = random.randint(POINT_RADIUS, WINDOW_HEIGHT - POINT_RADIUS)
    return (x, y)

#Funcion para verificar si dos puntos se solapan
def points_overlap(p1, p2):
    distance = ((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2 + (p1[1] - p2[1]) ** 2) ** 0.5
    return distance < 2 * POINT_RADIUS

#Algoritmo de las vegas para generar puntos sin solapamientos
def generate_pionts(num_points):
    points = []
    while len(points) < num_points:
        point = generate_random_point()
        if all(not points_overlap(point, existing_point) for existing_point in points):
            points.append(point)
    return points

#Funcion para dibujar los puntos en el lienzo
def draw_points(canvas, points):
    for (x, y) in points:
        canvas.create_oval(x - POINT_RADIUS, y - POINT_RADIUS, x + POINT_RADIUS, y + POINT_RADIUS, fill="blue")
        
#Crear la ventana principal
root = tk.Tk()
root.title("Puntos aleatorios con Algoritmo Las Vegas")

#Crear el lienzo
canvas = tk.Canvas(root, width=WINDOW_WIDTH, height=WINDOW_HEIGHT, bg="white")
canvas.pack()

#Generar y dibujar los puntos
points = generate_pionts(NUM_PUNTOS)
draw_points(canvas, points)

#Iniciar el bucle principal de Tkinter
root.mainloop()
