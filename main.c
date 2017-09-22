#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    ePersona personas[20];
    int opcion;
    int i;
    int auxDni;

    inicializar(personas);

    do
    {
        printf("------Ingrese una opcion------\n");
        printf("\n1. Agregar una persona: \n");
        printf("2. Eliminar una persona: \n");
        printf("3. Ordenar por nombre e imprimir: \n");
        printf("4. Imprimir grafico\n");
        printf("5. Salir\n\n");

        scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
        cargarPersona(personas);
        break;
    case 2:
        buscarDni(personas);
        break;
    case 3:
        ordenarPersona(personas);
        mostrar(personas);
        break;
    case 4:
        grafico(personas);
        break;



    }


    }while(opcion !=5);

    return 0;
}
