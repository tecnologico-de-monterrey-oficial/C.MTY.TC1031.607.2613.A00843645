# Evidencia 1: Sistema de Ordenamiento y Búsqueda de Logs
**Nombre:** Daniela Chávez Ibarra  
**Matrícula:** A00843645  

---

## 📹 Video Explicativo
[Enlace al video en Google Drive](https://drive.google.com/drive/folders/1QApqPNJKwr79vBWBAh1Et8g82-6jL32q?usp=sharing)

---

## 🛠️ Instrucciones de Compilación y Ejecución

### Requisitos
* Compilador C++11 (`g++`)


## Formato de Fechas Esperado
Al utilizar el módulo de Búsqueda por Rango de Fechas (Opción 3), la consola solicitará los datos uno por uno. Debes ingresarlos respetando la siguiente convención:

Mes: Abreviatura de 3 letras en inglés con la primera mayúscula (ej. Sep, Oct, Nov).

Día: Número entero del día (ej. 1, 05, 29).

Año: 4 dígitos numéricos (ej. 2024).

Hora: Formato de 24 horas HH:MM:SS con ceros a la izquierda (ej. 08:00:00, 14:30:15).


### Política de Uso de Inteligencia Artificial
Lo que se PERMITIÓ en el proyecto:
Explicación de sintaxis y librerías: Consulta de sintaxis para manejo de archivos (fstream), conversión de streams (sstream) y medición de tiempos (chrono).

Retroalimentación y revisión de código: Uso de IA como asistente para detectar advertencias de compilación, scope/rutas relativas y manejo defensivo del búfer de cin.

Lo que NO se permitió:
Generación automatizada de punta a punta del proyecto a través de agentes o copilotos sin revisión manual.

Copiado directo de algoritmos clave o funciones de búsqueda sin adaptación ni validación paso a paso por parte del estudiante.

### Uso Crítico de la IA (Caso de Corrección):
Durante el desarrollo del módulo de búsqueda por rango, la IA sugirió inicialmente un algoritmo de Búsqueda Secuencial (O(n)) para encontrar las coincidencias del rango. Se identificó de forma crítica que esto incumplía con la eficiencia requerida para logs masivos, por lo que se descartó dicha propuesta y se implementó una Búsqueda Binaria de Rangos ($O(\log n)$) basada en lowerBound y upperBound, resolviendo además el manejo adecuado de timestamps duplicados en log607-2.txt.

### Compilación
Desde la raíz del proyecto, ejecuta el siguiente comando en la terminal:
```bash
g++ -std=c++11 -Iinclude src/Log.cpp src/main.cpp -o main

