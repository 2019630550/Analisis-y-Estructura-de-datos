import tkinter as tk
import random

# Dimensiones de la ventana y el cuadrado
WINDOW_SIZE = 500
NUM_SAMPLES = 1000

# Función para calcular pi usando el método de Monte Carlo
def monte_carlo_pi(canvas, num_samples):
    inside_circle = 0

    for _ in range(num_samples):
        x = random.uniform(-1, 1)
        y = random.uniform(-1, 1)
        
        # Escalar los puntos para que se dibujen en el lienzo
        canvas_x = (x + 1) * (WINDOW_SIZE / 2)
        canvas_y = (y + 1) * (WINDOW_SIZE / 2)
        
        if x**2 + y**2 <= 1:
            inside_circle += 1
            canvas.create_oval(canvas_x, canvas_y, canvas_x, canvas_y, outline="blue")
        else:
            canvas.create_oval(canvas_x, canvas_y, canvas_x, canvas_y, outline="red")
    
    pi_estimate = (inside_circle / num_samples) * 4
    return pi_estimate

# Configuración de la ventana principal
root = tk.Tk()
root.title("Aproximación de π con Monte Carlo")

# Crear el lienzo
canvas = tk.Canvas(root, width=WINDOW_SIZE, height=WINDOW_SIZE, bg="white")
canvas.pack()

# Dibujar el cuadrado y el cuarto de círculo
canvas.create_rectangle(0, 0, WINDOW_SIZE, WINDOW_SIZE, outline="black")
canvas.create_arc(0, 0, WINDOW_SIZE, WINDOW_SIZE, start=0, extent=90, outline="black", style=tk.ARC)

# Calcular π y mostrar los puntos
pi_estimate = monte_carlo_pi(canvas, NUM_SAMPLES)

# Mostrar el resultado en la ventana
label = tk.Label(root, text=f"Estimación de π usando {NUM_SAMPLES} muestras: {pi_estimate}")
label.pack()

# Iniciar el bucle principal de Tkinter
root.mainloop()
