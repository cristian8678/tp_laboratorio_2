#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define TAM 20

void inicializar(ePersona arreglo[])
{
    int i;
    for(i=0; i<TAM; i++)
    {
        arreglo[i].estado=0;
    }
}


void cargarPersona(ePersona arreglo[])
{
    int i,validarNombre;
    int place;
    for(i=0; i<TAM; i++)
    {
        if(arreglo[i].estado==0)
        {
            place=i;
            break;
        }
    }

    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%s",arreglo[place].nombre);
    validarNombre=soloLetra(arreglo[place].nombre);
    while(validarNombre!=0)
    {
        printf("Error!! reingrese el nombre: ");
        fflush(stdin);
        scanf("%s",arreglo[place].nombre);
        validarNombre=soloLetra(arreglo[place].nombre);
    }
    printf("Ingrese D.N.I: ");
    fflush(stdin);
    scanf("%d",&arreglo[place].dni);
    printf("Ingrese la edad: ");
    fflush(stdin);
    scanf("%d",&arreglo[place].edad);
    fflush(stdin);
    system("cls");
    printf("%s\n %d\n %d\n",arreglo[place].nombre,arreglo[place].dni,arreglo[place].edad);
    system("pause");
    system("cls");

    while(arreglo[place].edad<0 || arreglo[place].edad > 100)
    {
        printf("\nPor favor ingrese una edad existente: ");
        fflush(stdin);
        scanf("%d",&arreglo[place].edad);
    }

    arreglo[place].estado=1;

}

void buscarDni(ePersona arreglo[])
{
    long int auxDni;
    int i, error;
    printf("Ingrese el DNI que quiera borrar de la base de datos: \n");
    scanf("%d",&auxDni);

    for(i=0; i<TAM; i++)
    {
        if(auxDni==arreglo[i].dni)
        {
            arreglo[i].estado=0;
            printf("DNI encontrado y borrado \n");
            break;
        }


    }
    if(i==TAM)
    {
        printf("DNI no borrado!\n");
    }
}

void ordenarPersona(ePersona arreglo[])
{
    int i;
    int j;
    ePersona aux;


    for(i=0; i<TAM; i++)
    {
        for(j=i+1; j<TAM; j++)
        {

            if(strcmp(arreglo[i].nombre,arreglo[j].nombre)==1)
            {
                aux=arreglo[i];
                arreglo[i]=arreglo[j];
                arreglo[j]=aux;
            }


        }

    }

}

void mostrar(ePersona arreglo[])
{
    int i;
    for(i=0; i<TAM; i++)
    {
        if(arreglo[i].estado==1)
        {
            printf("\nNombre: %s DNI: %d Edad: %d\n\n", arreglo[i].nombre,arreglo[i].dni,arreglo[i].edad);
        }
    }
}
void grafico(ePersona arreglo[])
{
    int i, hasta18=0, de19a35=0, mayorDe35=0, flag=0, mayor;

    for(i=0; i<TAM; i++)
    {
        if(arreglo[i].edad<=18&&arreglo[i].estado==1)
        {
            hasta18++;
        }
        if(arreglo[i].edad>18&&arreglo[i].edad<36&&arreglo[i].estado==1)
        {
            de19a35++;
        }
        if(arreglo[i].edad>35&&arreglo[i].edad<100&&arreglo[i].estado==1)
        {
            mayorDe35++;
        }
    }

    if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
    {
        mayor = hasta18;
    }
    else
    {
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else
        {
            mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--)
    {
        printf("%02d|",i);

        if(i<= hasta18)
        {
            printf("*");
        }
        if(i<= de19a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d\n", hasta18, de19a35, mayorDe35);
    system("pause");
    system("cls");


}

int soloLetra(char Array[])
{
    int i;
    int resp;
    int tot;
    tot=strlen(Array);
    for(i=0; i<tot; i++)
    {



            if((Array[i] == ' ') || (Array[i] >= 'a' && Array[i] <= 'z') || (Array[i]  >='A' && Array[i] <= 'Z'))
            {
                resp=0;

            }
            else
            {
                resp=1;
                break;
            }
        }
        return resp;


}
