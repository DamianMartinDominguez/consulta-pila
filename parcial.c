/* existe un archivo llamado datos.dat de tipo binario cuya organizacion es secuencial con la siguiente estructura: cl(clave) entera, D(DESCRIPCION) cadena de 30 caracteres,
tipo(tipo de datos)entero sin signo,valor entero, b('A'=alta  'B'= baja)se pide:

realizar una funcion que pase como parametro la clave, entre otros parametros, y apile dos valores: la clave y su posicion fisica respecto al archivo(registro 1, 2, etc),
si el campo "tipo" tiene el bit 0 con valor 1, en caso de no encontrarlo crear un nuevo registro en el archivo(sin apilarlo). La funcion retornara un puntero a la pila
realizarl el main() con la llamada a dicha funcion. No utilizar variables globales.
*/


#include<stdio.h>
#include<stdlib.h>

typedef struct
              {
                 int cl;
                 char D[30];
                 unsigned char tipo;
               }
struct pila{
            struct datos d;
            struct pila *l;
            };

void generaArchivo(void);
void setPila(struct pila **p);
