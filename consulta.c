#include<stdio.h>
#include<stdlib.h>


struct datos{
            int id;
            char n[30];
            unsigned int tipo;
            };

struct pila{
            struct datos d;
            struct pila *l;
            };

void generaArchivo(void);
void setPila(struct pila **p);

int main()
{
 FILE *pf;

 struct pila *p= NULL, *aux=NULL;
 generaArchivo();

 setPila(&p);
 if((pf=fopen("activos.dat","wb"))==NULL)
        {
            printf("no se puede abrir el archivo");
            return ;
        }
 printf("el valor de p es: %d, %d",p,*p);
 while(p)
 {
    printf("%4d %-20s 0x%x\n",p->d.id, p->d.n, p->d.tipo);
    aux=p;
    p=p->l;
    free(aux);
 }
 //system("pause");
 return 0;
}

void setPila(struct pila **p)
{
  struct datos bf;
  struct pila *aux;
  FILE *fp;
  if((fp=fopen("paciente.dat","rb"))== NULL)
    {
    printf("\n error en el archivo\n");

    return 1;
    }
  fread(&bf,sizeof(struct datos),1,fp);
  while(!feof(fp))
  {

  if(bf.tipo & 0x10)//si quiero que este el bit 4 que es la posicion 5 en 1
  //if(!(bf.tipo & 0x10)) si quiero que este el bit 4 que es la posicion 5 en 0
  {
  aux = (struct pila*)malloc(sizeof(struct pila));
  if(aux)
  {
    aux->d=bf;

    aux->l=p;
    p= aux;

}
}
fread(&bf,sizeof(struct datos),1,fp);

}
fclose(fp);
}

void generaArchivo(void)
{
struct datos bf[]={ 1,"juan primero",0x11,
                    2,"juan segundo",0x12,
                    3,"juan tercero",0x13,
                    4,"juan cuarto",0x14,
                    5,"juan quinto",0x15,
                    6,"juan sexto",0x16,
                    7,"juan septimo",0x17,
                    8,"juan octavo",0x18,};
FILE *fp=fopen("paciente.dat","wb");

fwrite(bf,sizeof(struct datos),8,fp);
printf("se genero archivo");
printf("\n\n");
fclose(fp);
}
