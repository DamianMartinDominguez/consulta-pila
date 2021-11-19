/* existe un archivo llamado datos.dat de tipo binario cuya organizacion es secuencial con la siguiente estructura: cl(clave) entera, D(DESCRIPCION) cadena de 30 caracteres,
tipo(tipo de datos)entero sin signo,valor entero, b('A'=alta  'B'= baja)se pide:

realizar una funcion que pase como parametro la clave, entre otros parametros, y apile dos valores: la clave y su posicion fisica respecto al archivo(registro 1, 2, etc),
si el campo "tipo" tiene el bit 0 con valor 1, en caso de no encontrarlo crear un nuevo registro en el archivo(sin apilarlo). La funcion retornara un puntero a la pila
realizar el main() con la llamada a dicha funcion. No utilizar variables globales.
*/



#include<stdio.h>
#include<stdlib.h>

typedef struct datos
              {
                 int cl;
                 char descripcion[30];
                 unsigned char tipo;
               } datos_t;
struct pila{
            struct datos d;
            struct pila *l;
            };

void generaArchivo(void);

void crearPila(struct pila **l);

main()
{
    datos_t nuevo;
    struct pila *p = NULL, *aux= NULL;//apuntan todos a null
    aux = (struct pila*)malloc(sizeof(struct pila));//se asigna memoria dinamica
    if(aux==NULL)
     {
       printf("\n no hay memoria disponible\n");
       return 0;
      }
    do
    {
        printf("\n el registro contiene :\n Nombre:%s  \nEdad: %d \nLegajo: %ld", p->d.cl,p->d.descripcion,p->d.tipo);
        aux = p;
        p = p->l;
        free(aux);
    }while(p->l != NULL);
  printf("\n----------------------------------------------------------------");
    printf("\n el registro contiene :\n Nombre:%s  \nEdad: %d \nLegajo: %ld", p->d.cl,p->d.descripcion,p->d.tipo);
    printf("\n----------------------------------------------------------------");
    printf("\nfin");
    free(p);

    return 0;
}




void crearPila (struct pila **l)
{
    struct pila *aux,*p;
    struct datos bf;
    FILE *fp;

    if((fp=fopen("datos.dat","rb"))==NULL)
        {
            printf("no se puede abrir el archivo");
            return;
        }

    fread(&bf,sizeof(struct datos),1,fp);
    while(!feof(fp))
    {
        if(bf.tipo & 0x01)// si tiene 1 en el bit 0
        {
            fread(&bf,sizeof(struct datos),1,fp);
            aux=(struct pila *) malloc (sizeof(struct pila));
            aux->d=bf;
            aux->l=p;
            p=aux;
          return p;
        }
       if(!(bf.tipo & 0x01))// si tiene 0 en el bit 0
        {
         fclose(fp);
         FILE *fp=fopen("datos.dat","ab");
         fwrite(bf,sizeof(struct datos),1,fp);
      }
    }
    fclose(fp);
}
