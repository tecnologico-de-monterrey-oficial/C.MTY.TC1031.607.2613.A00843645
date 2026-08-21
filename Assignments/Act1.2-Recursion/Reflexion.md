// Daniela Chávez Ibarra
// A00843645

¿En qué casos notaste que la versión recursiva fue más lenta o usó más memoria que la iterativa? ¿A qué se debió?
En el caso de fibonacciRecursive ya que estoy haciendo una recursividad doble porque llamo a fibonacciRecursive(n-1)+fibonacciRecursive(n-2)

Para la suma 1..n, sumFormula resuelve en un solo paso lo que a sumIterative y sumRecursive les toma n pasos. ¿Qué te dice esto sobre buscar una fórmula antes de escribir código?
Que una fórmula realiza menos operaciones, en este caso solo 3 sin importar qué tan grande sea n. 

Si bacteriasRecursive tuviera que calcular n = 100,000 días, ¿qué problema esperarías encontrar y cómo lo resolverías?
Al intentarlo, mi código se congeló ahí y ya no desplegó el resultado ni el de los siguientes ejercicios. 
