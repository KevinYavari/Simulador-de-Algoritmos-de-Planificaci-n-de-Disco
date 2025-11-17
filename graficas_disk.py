import matplotlib.pyplot as plt

# Leer archivo resultados_graficas.txt
algoritmos = []
movimientos = []

with open("resultados_graficas.txt", "r") as f:
    for line in f:
        parts = line.split()
        if len(parts) == 2:
            nombre = parts[0]
            valor = int(parts[1])
            algoritmos.append(nombre)
            movimientos.append(valor)

print("Algoritmos:", algoritmos)
print("Movimientos:", movimientos)

# ===== Gráfica 1: Barras de movimiento total =====
plt.figure()
plt.bar(algoritmos, movimientos)
plt.xlabel("Algoritmo de planificación de disco")
plt.ylabel("Movimiento total del cabezal (cilindros)")
plt.title("Comparación de movimiento del cabezal")
plt.savefig("comparacion_movimiento.png", dpi=300)

# ===== Gráfica 2: Normalización (tipo rendimiento relativo) =====
max_mov = max(movimientos)
# Mientras menos movimiento, mejor. Podemos normalizar tipo "eficiencia inversa"
eficiencia = [max_mov / m for m in movimientos]

plt.figure()
plt.bar(algoritmos, eficiencia)
plt.xlabel("Algoritmo de planificación de disco")
plt.ylabel("Índice relativo de eficiencia")
plt.title("Comparación relativa de rendimiento")
plt.savefig("comparacion_eficiencia.png", dpi=300)

plt.show()
