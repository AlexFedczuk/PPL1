#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "miBiblioteca.h"

void PedirUnaCadena(char cadena[], int buffer, char mensaje[])
{
    printf(mensaje);
    fflush(stdin);
    gets(cadena);

    while(strlen(cadena) > buffer)
    {
        printf("\nError! No ingrese mas de %d caracteres!\n", buffer);
        printf(mensaje);
        fflush(stdin);
        gets(cadena);
    }
}

void FormalizarApellidoNombreParte1(char apellidoNombre[], char apellido[], char nombre[])
{
    strcpy(apellidoNombre, apellido);
    strcat(apellidoNombre, ", ");
    strcat(apellidoNombre, nombre);
    strlwr(apellidoNombre);
}

void FormalizarApellidoNombreParte2(int buffer, char apellidoNombre[])
{
    int i;

    for(i = 0; i < buffer; i++)
    {
        if(i == 0)
        {
            apellidoNombre[i] = toupper(apellidoNombre[i]);
        }else
        {
            if(apellidoNombre[i] == ' ')
            {
                apellidoNombre[i + 1] = toupper(apellidoNombre[i + 1]);
            }
        }
    }
}

int PedirUnNumeroEntero(char mensaje[])
{
    int numeroIngresado;

    printf(mensaje);
    fflush(stdin);
    scanf("%d", &numeroIngresado);

    return numeroIngresado;
}

float PedirUnNumeroFlotante(char mensaje[])
{
    float numeroIngresado;

    printf(mensaje);
    fflush(stdin);
    scanf("%f", &numeroIngresado);

    return numeroIngresado;
}

char PedirUnCaracter(char mensaje[])
{
    char caracterIngresado;

    printf(mensaje);
    fflush(stdin);
    scanf("%c", &caracterIngresado);

    return caracterIngresado;
}

void PedirUnString(char string[], char mensaje[])
{
    char stringIngresado[25];

    printf(mensaje);
    fflush(stdin);
    gets(stringIngresado);

    strcpy(string, stringIngresado);
}

void FormalizarUnNombre(char nombre[], int buffer)
{
    int i;

    for(i = 0; i < buffer; i++)
    {
        if(i == 0)
        {
            nombre[i] = toupper(nombre[i]);
        }else
        {
            if(nombre[i] == ' ')
            {
                nombre[i + 1] = toupper(nombre[i + 1]);
            }else
            {
                nombre[i] = tolower(nombre[i]);
            }
        }
    }
}

void FormalizarAApellidoYNombre(char apellidoNombre[], char apellido[], char nombre[])
{
    strcpy(apellidoNombre, apellido);
    strcpy(apellidoNombre, " ");
    strcpy(apellidoNombre, nombre);
}

int SumarDosNumerosEnteros(int primerOperador, int segundoOperador)
{
    int resultado;

    resultado = primerOperador + segundoOperador;

    return resultado;
}

float SumarDosNumerosFlotantes(float primerOperador, float segundoOperador)
{
    float resultado;

    resultado = primerOperador + segundoOperador;

    return resultado;
}

int RestarDosNumerosEnteros(int primerOperador, int segundoOperador)
{
    int resultado;

    resultado = primerOperador - segundoOperador;

    return resultado;
}

float RestarDosNumerosFlotantes(float primerOperador, float segundoOperador)
{
    float resultado;

    resultado = primerOperador - segundoOperador;

    return resultado;
}

int MultiplicarDosNumerosEnteros(int primerOperador, int segundoOperador)
{
    int resultado;

    resultado = primerOperador * segundoOperador;

    return resultado;
}
float MultiplicarDosNumerosFlotantes(float primerOperador, float segundoOperador)
{
    float resultado;

    resultado = primerOperador - segundoOperador;

    return resultado;
}

int DividirDosNumerosEnteros(int primerOperador, int segundoOperador)
{
    int resultado;

    if(segundoOperador != 0)
    {
        resultado = (float)primerOperador / segundoOperador;
    }

    return resultado;
}
float DividirDosNumerosFlotantes(float primerOperador, float segundoOperador)
{
    float resultado;

    if(segundoOperador != 0)
    {
        resultado = primerOperador / segundoOperador;
    }

    return resultado;
}

float CalcularUnPromedio(int total, int divisor)
{
    float resultado;

    if(divisor != 0)
    {
        resultado = (float)total / divisor;
    }

    return resultado;
}

/*void OrdenarAlfabeticamente(int tam)//En desarrollo...
{
    int auxInt;
    float auxFloat;
    char auxString[20];

    int i;
    int j;

    for(i = 0; i < tam - 1; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            //if(legajos[i] > legajos[j])// Este criterio de ordenamiento es para ordenar los legajos!
            if(strcmp(nombres[i], nombres[j]) > 0)// Este criterio es para ordenar alfabeticamente, de A a Z!
            {
                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxFloat = sueldos[i];
                sueldos[i] = sueldos[j];
                sueldos[j] = auxFloat;

                strcpy(auxString,nombres[i]);
                strcpy(nombres[i],nombres[j]);
                strcpy(nombres[j],auxString);
            }
        }
    }
}*/

void InicializarLosElementosDeUnArray(eEstructura lista[], int tam)
{
    int i;

    if(lista != NULL && (tam > 0 && tam < tam + 1))
    {
        for(i = 0; i < tam; i++)
        {
            lista[i].id = 0;
            strcpy(lista[i].nombre, " ");
            strcpy(lista[i].apellido, " ");
            lista[i].salario = 0;
            lista[i].sector = 0;
            lista[i].isEmpty = 1;
        }
    }
}

void InicializarUnContadorTipoArray(int contadorArray[], int buffer)
{
    int i;

    for(i = 0; i < buffer; i++)
    {
        contadorArray[i] = 0;
    }
}

void PedirDatosDeUnaEntidadParaUnArray(eEstructura lista[], int tam)
{
    int id;
    char nombre[25];
    char apellido[25];
    float salario;
    int sector;
    char respuesta;

    if(lista != NULL && (tam > 0 && tam < tam + 1))
    {
        do
        {
            id = PedirUnNumeroEntero("Ingrese id: ");

            PedirUnaCadena(nombre, 25, "Ingrese nombre: ");

            PedirUnaCadena(apellido, 25, "Ingrese apellido: ");

            salario = PedirUnNumeroFlotante("Ingrese salario: ");

            sector = PedirUnNumeroEntero("Ingrese sector: ");

            AgregarDatosDeUnaEntidadAlArray(lista, tam, id, nombre, apellido, salario, sector);

            printf("Desea cargar otro empleado(s/n)?: ");
            fflush(stdin);
            scanf("%c", &respuesta);
            respuesta = tolower(respuesta);
            if(respuesta == 'n')
            {
                break;
            }
        }
        while(respuesta != 'n');
    }
}


void AgregarDatosDeUnaEntidadAlArray(eEstructura lista[], int tam, int id, char nombre[], char apellido[], float salario, int sector)
{
    int indiceVacio;

    indiceVacio = BuscarPrimerEspacioVacioEnUnArray(lista, tam);

    if(lista != NULL && (tam > 0 && tam < tam + 1) && indiceVacio != -1)
    {
        lista[indiceVacio].id = id;
        strcpy(lista[indiceVacio].nombre, nombre);
        strcpy(lista[indiceVacio].apellido, apellido);
        lista[indiceVacio].salario = salario;
        lista[indiceVacio].sector = sector;
        lista[indiceVacio].isEmpty = 0;
    }
}


int BuscarPrimerEspacioVacioEnUnArray(eEstructura lista[], int tam)
{
    int indiceVacio;

    int i;

    indiceVacio = -1;

    if(lista != NULL && (tam > 0 && tam < tam + 1))
    {
        for(i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                indiceVacio = i;
                break;
            }
        }
    }

    return indiceVacio;
}

void ModificarUnaEntidad(eEstructura lista[], int tam)
{
    int idIngresado;
    int indiceEncontrado;
    int opcion;

    int bandera;

    if(lista != NULL && (tam > 0 && tam < tam + 1))
    {
        ImprimirEntidades(lista, tam);
        idIngresado = PedirUnNumeroEntero("\nIngrese el ID del ENTE que desea modificar: ");

        indiceEncontrado = BuscarEntidadPorId(lista, tam, idIngresado);

        bandera = 0;

        if(indiceEncontrado != -1)
        {
            do
            {
                opcion = MostrarUnSubMenuDeModificaciones(1, 5, &bandera);

                switch(opcion)
                {
                    case 1:
                        PedirUnaCadena(lista[indiceEncontrado].nombre, 25, "\nIngrese el nuevo nombre: ");
                        break;
                    case 2:
                        PedirUnaCadena(lista[indiceEncontrado].apellido, 25, "\nIngrese el nuevo apellido: ");
                        break;
                    case 3:
                        lista[indiceEncontrado].salario = PedirUnNumeroFlotante("\nIngrese el nuevo sueldo: ");
                        break;
                    case 4:
                        lista[indiceEncontrado].sector = PedirUnNumeroEntero("\nIngrese el numero del nuevo sector: ");
                        break;
                    default:
                        break;
                }
                system("pause");
                system("cls");
            }
            while(opcion != 5);
        }
    }


}

int MostrarUnSubMenuDeModificaciones(int opcionMinima, int opcionMaxima, int* bandera)
{
    int opcionIngresada;

    do
    {
        if(bandera == 0)
        {
            printf("\nQue desea modificar?\n");
        }else
        {
            printf("Desea modificar algo mas?\n");
        }
        printf("1. NOMBRE\n");
        printf("2. APELLIDO \n");
        printf("3. SALARIO\n");
        printf("4. SECTOR\n");
        printf("5. CONTINUAR\n\n");
        printf("Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcionIngresada);

        *bandera = 1;

        if(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima)
        {
            printf("\nError! Opcion invalida!\n");
            printf("Ingresar una opcion del sub-menu: ");
            fflush(stdin);
            scanf("%d", &opcionIngresada);
        }
    }
    while(opcionIngresada < opcionMinima  || opcionIngresada > opcionMaxima);

    return opcionIngresada;
}

void ImprimirEntidades(eEstructura lista[], int tam)
{
    int i;

    FormalizarNombresDeUnArray(lista, tam, 25);
    FormalizarApellidosDeUnArray(lista, tam, 25);

    if(lista != NULL && (tam > 0 && tam < tam + 1))
    {
        printf("\n   1.   ***** Listado de ENTES *****\n\n");
        printf("   ID      APELLIDO     NOMBRE     SALARIO        SECTOR");

        for(i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                printf("\n   %04d    %s    %10s     %10.2f            %d\n", lista[i].id,
                                                                             lista[i].apellido,
                                                                             lista[i].nombre,
                                                                             lista[i].salario,
                                                                             lista[i].sector);
            }
        }
    }
}

void FormalizarNombresDeUnArray(eEstructura lista[], int tam, int buffer)
{
    int i;
    int j;

    if(lista != NULL && (tam > 0 && tam < tam + 1) && buffer != -1)
    {
        for(i = 0; i < tam; i++)
        {
            for(j = 0; j < buffer; j++)
            {
                if(j == 0)
                {
                    lista[i].nombre[j] = toupper(lista[i].nombre[j]);
                }else
                {
                    if(lista[i].nombre[j] == ' ')
                    {
                        lista[i].nombre[j + 1] = toupper(lista[i].nombre[j + 1]);
                    }else
                    {
                        lista[i].nombre[j] = tolower(lista[i].nombre[j]);
                    }
                }
            }
        }
    }

}
/*
void FormalizarNombresDeMascotas(eMascota lista[], int tam, int buffer)
{
    int i;
    int j;

    if(lista != NULL && (tam > 0 && tam < tam + 1) && buffer != -1)
    {
        for(i = 0; i < tam; i++)
        {
            for(j = 0; j < buffer; j++)
            {
                if(j == 0)
                {
                    lista[i].nombreMascota[j] = toupper(lista[i].nombreMascota[j]);
                }else
                {
                    if(lista[i].nombreMascota[j] == ' ')
                    {
                        lista[i].nombreMascota[j + 1] = toupper(lista[i].nombreMascota[j + 1]);
                    }else
                    {
                        lista[i].nombreMascota[j] = tolower(lista[i].nombreMascota[j]);
                    }
                }
            }
        }
    }
}
*/

void FormalizarApellidosDeUnArray(eEstructura lista[], int tam, int buffer)
{
    int i;
    int j;

    if(lista != NULL && (tam > 0 && tam < tam + 1) && buffer != -1)
    {
        for(i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                for(j = 0; j < buffer; j++)
                {
                    if(j == 0)
                    {
                        lista[i].apellido[j] = toupper(lista[i].apellido[j]);
                    }else
                    {
                        if(lista[i].apellido[j] == ' ')
                        {
                            lista[i].apellido[j + 1] = toupper(lista[i].apellido[j + 1]);
                        }else
                        {
                            lista[i].apellido[j] = tolower(lista[i].apellido[j]);
                        }
                    }
                }
            }
        }
    }
}

int BuscarEntidadPorId(eEstructura lista[], int tam, int idABuscar)
{
    int indiceDelId;

    int i;

    indiceDelId = -1;

    if(lista != NULL && (tam > 0 && tam < 1001) && idABuscar > 0)
    {
        for(i = 0; i < tam; i++)
        {
            if(lista[i].id == idABuscar)
            {
                indiceDelId = i;
                break;
            }
        }
    }

    return indiceDelId;
}

void RealizarUnaBajaDeUnaEntidad(eEstructura lista[], int tam)
{
    int idIngreado;
    int opcion;

    int bandera;

    bandera = 0;

    if(lista != NULL && (tam > 0 && tam < tam + 1))
    {
        opcion = MostrarUnSubMenuDeBajas(1, 3, &bandera);
        do
        {
            switch(opcion)
            {
                case 1:
                    ImprimirEntidades(lista, tam);
                    idIngreado = PedirUnNumeroEntero("\nIngrese el ID de la ENTIDAD que desea eliminar: ");

                    if(RemoverUnaEntidadDeUnArray(lista, tam, idIngreado) == 0)
                    {
                        printf("\nDando de BAJA la ENTIDAD ingresada...\n");
                    }
                    break;
                case 2:
                    ImprimirEntidades(lista, tam);
                    idIngreado = PedirUnNumeroEntero("\nIngrese el ID de la ENTIDAD que desea eliminar: ");

                    if(EliminarUnaEntidadDeUnArray(lista, tam, idIngreado) == 0)
                    {
                        printf("\nEliminando la ENTIDAD ingresada...\n");
                    }
                    break;
                default:
                    break;
            }
            system("pause");
            system("cls");
        }
        while(opcion != 3);
    }
}

int RemoverUnaEntidadDeUnArray(eEstructura lista[], int tam, int idIngresado)
{
    int resultado;

    int i;

    resultado = 1;

    if(lista != 0 && (tam > 0 && tam < tam + 1) && idIngresado > 0)
    {
        for(i = 0; i < tam; i++)
        {
            if(lista[i].id == idIngresado && lista[i].isEmpty == 0)
            {
                lista[i].isEmpty = 1;

                resultado = 0;
                break;
            }
        }
    }

    return resultado;
}

int EliminarUnaEntidadDeUnArray(eEstructura lista[], int tam, int idIngresado)
{
    int resultado;

    int i;

    resultado = 1;

    if(lista != 0 && (tam > 0 && tam < tam + 1) && idIngresado > 0)
    {
        for(i = 0; i < tam; i++)
        {
            if(lista[i].id == idIngresado && lista[i].isEmpty == 0)
            {
                //lista[i].id = 0;
                strcpy(lista[i].nombre, " ");
                strcpy(lista[i].apellido, " ");
                lista[i].salario = 0;
                lista[i].sector = 0;
                lista[i].isEmpty = 1;

                resultado = 0;
                break;
            }
        }
    }

    return resultado;
}

int MostrarUnSubMenuDeBajas(int opcionMinima, int opcionMaxima, int* bandera)
{
    int opcionIngresada;

    do
    {
        if(bandera == 0)
        {
            printf("\nQue operacion desea realizar?\n");
        }else
        {
            printf("Desea realizar una operacion mas?\n");
        }
        printf("1. Dar de baja ENTIDAD\n");
        printf("2. Eliminar ENTIDAD \n");
        printf("3. CONTINUAR\n\n");
        printf("Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcionIngresada);

        *bandera = 1;

        if(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima)
        {
            printf("\nError! Opcion invalida!\n");
            printf("Ingresar una opcion del sub-menu: ");
            fflush(stdin);
            scanf("%d", &opcionIngresada);
        }
    }
    while(opcionIngresada < opcionMinima  || opcionIngresada > opcionMaxima);

    return opcionIngresada;
}

int CalcularTotalNumerosEnteros(eEstructura lista[], int tam)
{
    int acumulador;

    int i;

    acumulador = 0;

    if(lista != NULL && (tam > 0 && tam < tam + 1))
    {
        for(i = 0; i < tam; i ++)
        {
            if(lista[i].isEmpty == 0)
            {
                //acumulador = acumulador + lista[i];
            }
        }
    }

    return acumulador;
}

float CalcularTotalNumerosFlotantes(eEstructura lista[], int tam)
{
    float acumulador;

    int i;

    acumulador = 0;

    if(lista != NULL && (tam > 0 && tam < tam + 1))
    {
        for(i = 0; i < tam; i ++)
        {
            if(lista[i].isEmpty == 0)
            {
                //acumulador = acumulador + lista[i].salario;
            }
        }
    }

    return acumulador;
}

int CalcularCantidadDeEntidades(eEstructura lista[], int tam)
{
    int contador;

    int i;

    contador = 0;

    if(lista != NULL && (tam > 0 && tam < tam + 1))
    {
        for(i = 0; i < tam; i ++)
        {
            if(lista[i].isEmpty == 0)
            {
                contador++;
            }
        }
    }

    return contador;
}
