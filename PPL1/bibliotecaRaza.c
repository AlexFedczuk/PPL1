#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "miBiblioteca.h"
#include "bibliotecaRaza.h"

/**--------------------Inicializacion------------------------*/
void InicializarArrayDescripcion(eDescripcion lista[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        lista[i].idDescripcion = 0;
        strcpy(lista[i].descripcion, " ");
    }
}

void InicializarArrayTamanio(eTamanio lista[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        lista[i].idTamanio = 0;
        strcpy(lista[i].tamanio, " ");
    }
}

void InicializarArrayPais(ePais lista[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        lista[i].idPais = 0;
        strcpy(lista[i].nombreDePais, " ");
        strcpy(lista[i].continente, " ");
        lista[i].codigoTelefonico = 0;
    }
}

/**--------------------Hard codeo---------------------------*/
void HardCodearArrayDescripcion(eDescripcion lista[], int tam, int* idContador)
{
    int idDescripcion[6] = {1,2,3,4,5,6};
    char descripcion[6][25] = {"Doberman","Pastor Belgan","Persa","Siames","Dogo Argentino","Pastor Aleman"};

    *idContador = 4;

    for(int i = 0; i < tam; i++)
    {
        lista[i].idDescripcion = idDescripcion[i];
        strcpy(lista[i].descripcion, descripcion[i]);
    }
}
void HardCodearArrayTamanio(eTamanio lista[], int tam)
{
    int idTamanio[3] = {1,2,3};
    char tamanio[3][25] = {"chico","mediano","grande"};

    for(int i = 0; i < tam; i++)
    {
        lista[i].idTamanio = idTamanio[i];
        strcpy(lista[i].tamanio, tamanio[i]);
    }
}
void HardCodearArrayPais(ePais lista[], int tam)
{
    int idPais[5] = {1,2,3,4,5};
    char pais[5][25] = {"Alemania","Belgica","Persia","Tailandia","Argentina"};
    char continente[5][25] = {"Europa","Europa","Asia","Asia","America del Sur"};
    int codigoTelefonico[5] = {49,32,98,66,54};

    for(int i = 0; i < tam; i++)
    {
        lista[i].idPais = idPais[i];
        strcpy(lista[i].nombreDePais, pais[i]);
        strcpy(lista[i].continente, continente[i]);
        lista[i].codigoTelefonico = codigoTelefonico[i];
    }
}

int RealizarAltasDeRazas(eDescripcion listaDescripciones[], ePais listaPaises[], int tamDescripciones, int tamPais, int contadorIdRaza)
{
    int idRaza;
    char nombreRaza[25];
    char respuesta;
    int bandera;

    bandera = 0;

    do
    {
        if(bandera == 0)
        {
            idRaza = contadorIdRaza;
        }else
        {
            idRaza++;
        }
        MostrarListadoDePaises(listaPaises, tamPais);

        PedirUnaCadena(nombreRaza, 25, "\nIngrese el nombre de la Raza: ");

        CargarRaza(listaDescripciones, tamDescripciones, idRaza, nombreRaza);

        printf("Desea cargar otra Raza?(s/n)\n");
        printf("Ingrese aqui: ");
        fflush(stdin);
        scanf("%c", &respuesta);
        respuesta = tolower(respuesta);
        if(respuesta == 'n')
        {
            break;
        }

        bandera = 1;
    }
    while(respuesta != 'n');

    return idRaza;
}

void CargarRaza(eDescripcion listaDescripciones[], int tamDescripciones, int idRaza, char nombreRaza[])
{
    int espacioVacio;

    espacioVacio = BuscarPrimerEspacioVacioEnElArrayDescripcions(listaDescripciones, tamDescripciones);

    if(listaDescripciones != 0 && tamDescripciones > 0 && espacioVacio != -1)
    {
        listaDescripciones[espacioVacio].idDescripcion = idRaza;
        strcpy(listaDescripciones[espacioVacio].descripcion, nombreRaza);
    }
}

int BuscarPrimerEspacioVacioEnElArrayDescripcions(eDescripcion listaDescripciones[], int tamDescripcion)
{
    int indiceVacio;

    int i;

    indiceVacio = -1;

    if(listaDescripciones != NULL && tamDescripcion > 0)
    {
        for(i = 0; i < tamDescripcion; i++)
        {
            if(strcmp(listaDescripciones[i].descripcion, " ") == 0)
            {
                indiceVacio = i;
                break;
            }
        }
    }

    return indiceVacio;
}

void MostrarListadoDePaises(ePais listaPaises[], int tamPais)
{
    printf("Paises disponibles:\n");
    for(int i = 0; i < tamPais; i++)
    {
        if(strcasecmp(listaPaises[i].nombreDePais, " ") != 0)
        {
            printf("%d. %s\n",listaPaises[i].idPais,listaPaises[i].nombreDePais);
        }
    }
}
