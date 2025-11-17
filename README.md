# 🧠 Simulador de Algoritmos de Planificación de Disco (FCFS, SCAN, C-SCAN)

Este proyecto implementa un **simulador de planificación de disco** usando C++, basado en los algoritmos:

- **FCFS (First-Come, First-Served)**
- **SCAN (Elevator / LOOK)**
- **C-SCAN (Circular SCAN)**

Además, se incluyen scripts en **Python** para generar **gráficas** comparativas del movimiento total del cabezal requerido por cada algoritmo.

Este proyecto forma parte del *Assignment III* del curso de Sistemas Operativos.

---

## 📁 Estructura del Proyecto

📦 proyecto
┣ 📄 main.cpp

┣ 📄 DiskTypes.h

┣ 📄 DiskSimulator.h

┣ 📄 DiskSimulator.cpp

┣ 📄 FCFSScheduler.h

┣ 📄 FCFSScheduler.cpp

┣ 📄 ScanScheduler.h

┣ 📄 ScanScheduler.cpp

┣ 📄 CScanScheduler.h

┣ 📄 CScanScheduler.cpp


┣ 📄 entrada1.txt

┣ 📄 resultados_graficas.txt ← generado automáticamente

┣ 📄 salida_fcfs.txt ← generado automáticamente

┣ 📄 salida_scan.txt ← generado automáticamente

┣ 📄 salida_cscan.txt ← generado automáticamente

┣ 📄 graficas_disk.py ← script para generar gráficas


---

## 📥 Archivo de entrada (`entrada1.txt`)

El simulador lee toda la información desde un archivo de texto que contiene:

<MAX_CYLINDERS>
  
<INITIAL_HEAD>
  
<PREVIOUS_REQUEST>
  
<N_REQUESTS>
  
<lista de N peticiones separadas por espacios>


Ejemplo incluido:

5000

2150

1805

10

2069 1212 2296 2800 544 1618 356 1523 4965 3681


Puedes modificar este archivo para realizar diferentes pruebas sin recompilar el programa.

---

## 🛠️ Compilación

### 🔹Compilar con `g++`

Dentro del proyecto:

```bash
g++ -std=c++17 main.cpp DiskSimulator.cpp FCFSScheduler.cpp ScanScheduler.cpp CScanScheduler.cpp -o disk_sim
```

---

## ▶️ Ejecución

Una vez compilado:

```bash
./disk_sim
```

El programa:

Carga los datos desde entrada1.txt

Ejecuta los algoritmos:

FCFS

SCAN

C-SCAN

Imprime los desplazamientos totales del cabezal

Genera los siguientes archivos:

salida_fcfs.txt

salida_scan.txt

salida_cscan.txt

resultados_graficas.txt

resultados_graficas.txt tiene este formato:

FCFS 12011
SCAN 6403
C-SCAN 6115

y es usado por el script Python para generar gráficas.

---

## 📊 Generación de Gráficas (Python + Matplotlib)

El script:

```bash
graficas_disk.py
```

lee resultados_graficas.txt y construye:

comparacion_movimiento.png

comparacion_eficiencia.png

---

## Requisitos

pip install matplotlib

---

## Ejecutar

python graficas_disk.py

Esto mostrará las gráficas y las guardará como imágenes PNG para incluirlas en el informe.

## 🧪 ¿Qué muestran las gráficas?

Gráfica 1 — Movimiento total:

Compara cuántos cilindros recorrió el cabezal para cada algoritmo.

Gráfica 2 — Eficiencia relativa:

Representa la eficiencia comparativa normalizada del movimiento del cabezal, destacando qué algoritmo es más rápido y consistente.

## ✔️ Notas adicionales

Puedes cambiar todos los datos simplemente editando entrada1.txt.

El programa está diseñado para extenderse (por ejemplo: añadir SSTF).

Funciona en Windows, Linux y macOS.

## 👨‍💻 Autor

Kevin Yavari Yoshioka
Proyecto académico — Sistemas Operativos
Pontificia Universidad Javeriana Cali

---
