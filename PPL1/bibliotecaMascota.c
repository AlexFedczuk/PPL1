#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bibliotecaMascota.h"
#include "miBiblioteca.h"

/**--------------------Inicializacion------------------------*/
void InicializarArrayMascotas(eMascota lista[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        lista[i].id = 0;
        strcpy(lista[i].nombre, " ");
        lista[i].edad = 0;
        lista[i].sexo = ' ';
        strcpy(lista[i].tipo, " ");
        lista[i].isEmpty = 1;
        lista[i].idDescripcion = 0;
        lista[i].idTamanio = 0;
        lista[i].idPais = 0;
        lista[i].codigoTelefonico = 0;
    }
}

/**--------------------Hard codeo---------------------------*/
void HardCodearArrayMascotas(eMascota lista[], int tam, int* idContador)
{
    int id[7] = {1, 2, 3, 4, 5, 6, 7};
    char nombre[7][25] = {"Michi", "Atos", "Fibi", "Luna", "Coco", "Mufa", "Nina"};
    int edad[7] = {13, 14, 4, 7, 12, 11, 8};
    char sexo[7] = {'f', 'm', 'f', 'f', 'm', 'm', 'f'};
    char tipo[7][10] = {"Gato","Gato","Gato","Perro","Perro","Perro","Perro"};
    int isEmpty[7] = {0, 0, 0, 0, 0, 0, 0};
    int idDescripcion[7] = {4,3,3,2,1,5,6};
    int idTamanio[7] = {1,1,2,3,3,2,2};
    int idPais[7] = {4,3,3,2,1,5,1};
    int codigoTelefonico[7] = {66,98,98,32,49,54,49};

    *idContador = 5;

    for(int i = 0; i < tam; i++)
    {
        lista[i].id = id[i];
        strcpy(lista[i].nombre, nombre[i]);
        lista[i].edad = edad[i];
        lista[i].sexo = sexo[i];
        strcpy(lista[i].tipo, tipo[i]);
        lista[i].isEmpty = isEmpty[i];
        lista[i].idDescripcion = idDescripcion[i];
        lista[i].idTamanio = idTamanio[i];
        lista[i].idPais = idPais[i];
        lista[i].codigoTelefonico = codigoTelefonico[i];
    }
}

void MostrarListadoMascotasConRazaYOrigen(eMascota listaMascota[],
                                          eDescripcion listaDescripcion[],
                                          ePais listaPais[],
                                          int tamMascota,
                                          int tamDescripcion,
                                          int tamPais)
{
    int j;
    int k;
    //int l;

    j = -1;
    k = -1;
    //l = -1;

    if((listaMascota != NULL && listaDescripcion != NULL && listaPais != NULL) &&
       (tamMascota > 0 && tamDescripcion > 0 && tamPais > 0))
    {
        printf("\n***Lista de Mascotas con su Raza y Pais de Origen***\n");
        printf("\nID   NOMBRE   EDAD   SEXO    TIPO             RAZA          PAIS\n");
        for(int i = 0; i < tamMascota; i++)
        {
            j = BuscarIndiceDeLaRazaDeLaMascota(listaMascota, listaDescripcion, tamDescripcion, i);
            k = BuscarIndiceDelPaisDeLaMascota(listaMascota, listaPais, tamPais, i);
            //l = BuscarIndiceDelTamanioDeLaMascota(listaMascota, listaTamanio, tamTamanio, i);
            if(listaMascota[i].isEmpty == 0)
            {
                printf("%02d   %6s   %4d   %4c   %5s   %14s   %11s\n",listaMascota[i].id,
                                                                      listaMascota[i].nombre,
                                                                      listaMascota[i].edad,
                                                                      listaMascota[i].sexo,
                                                                      listaMascota[i].tipo,
                                                                      listaDescripcion[j].descripcion,
                                                                      listaPais[k].nombreDePais);
            }
        }
    }
}

int BuscarIndiceDeLaRazaDeLaMascota(eMascota listaMascota[],
                                    eDescripcion listaDescripcion[],
                                    int tamDescripcion,
                                    int indice)
{
    for(int i = 0; i < tamDescripcion; i++)
    {
        if(listaMascota[indice].idDescripcion == listaDescripcion[i].idDescripcion)
        {
            return i;
        }
    }

    return -1;
}

int BuscarIndiceDelPaisDeLaMascota(eMascota listaMascota[],
                                   ePais listaPais[],
                                   int tamPais,
                                   int indice)
{
    for(int i = 0; i < tamPais; i++)
    {
        if(listaMascota[indice].idPais == listaPais[i].idPais)
        {
            return i;
        }
    }

    return -1;
}

int BuscarIndiceDelTamanioDeLaMascota(eMascota listaMascota[],
                                      eTamanio listaTamanio[],
                                      int tamTamanio,
                                      int indice)
{
    for(int i = 0; i < tamTamanio; i++)
    {
        if(listaMascota[indice].idPais == listaTamanio[i].idTamanio)
        {
            return i;
        }
    }

    return -1;
}

int MostrarMenu(int opcionMinima, int opcionMaxima)
{
    int opcionIngresada;

    printf("1. Realizar Alta(s) de Nueva(s) Mascota(s)\n");
    printf("2. Realizar una Alta de una Mascota en Baja\n");
    printf("3. Realizar una Baja Logica de una Mascota\n");
    printf("4. Alta de RAZA\n");
    printf("5. Modificar Datos de una Mascota\n");
    printf("6. Mostrar listado de Razas con las mascotas que pertenecen a esa Raza\n");
    printf("7. Mostrar listado de Mascotas con Raza y Origen\n");
    printf("8. Mostrar listado de Mascotas Ordenadas por Peso\n");
    printf("9. Mostrar el pais de origen que tenga mss mascotas en nuestra veterinaria.\n");
    printf("10. Listar por Codigo telefonico\n");
    printf("11. Salir\n");
    printf("Elija una opcion: ");
    scanf("%d", &opcionIngresada);

    do
    {
        if(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima)
        {
            printf("\nError! Opcion ingresada es invalida!\n");
            printf("Elija una de las opciones del menu: ");
            scanf("%d", &opcionIngresada);
        }
    }
    while(opcionIngresada < opcionMinima || opcionIngresada > opcionMaxima);

    return opcionIngresada;
}

int RealizarAltasDeMascotas(eMascota listaMascotas[],
                             eDescripcion listaDescripciones[],
                             eTamanio listaTamanio[],
                             ePais listaPaises[],
                             int tamMascota,
                             int tamDescripcion,
                             int tamTamanios,
                             int contadorId)
{
    int idMascota;
    char nombreMascota[25];
    int edadMascota;
    char sexoMascota;
    char tipoMascota[10];
    int idDescripcion;
    int idTamanio;
    int idPais;
    char respuesta;

    int bandera;

    bandera = 0;

    do
    {
        if(bandera == 0)
        {
            idMascota = contadorId;
        }else
        {
            idMascota++;
        }

        //idMascota = PedirUnNumeroEntero("Ingrese el ID de la Mascota: ");
        PedirUnaCadena(nombreMascota, 25, "Ingrese el nombre de la Mascota: ");
        FormalizarUnNombre(nombreMascota, 25);
        edadMascota = PedirUnNumeroEntero("Ingrese la edad de la Mascota: ");
        sexoMascota = PedirSexoDeLaMascota();
        PedirTipoDeMascota(tipoMascota);
        if(strcmp(tipoMascota, "Perro") == 0)
        {
            idDescripcion = PedirRazaDeLaMascotaTipoPerro(listaDescripciones, tamDescripcion);
        }else
        {
            if(strcmp(tipoMascota, "Gato") == 0)
            {
                idDescripcion = PedirRazaDeLaMascotaTipoGato(listaDescripciones, tamDescripcion);
            }
        }
        idPais = idDescripcion;
        idTamanio = PedirTamanioDeLaMascota(listaTamanio, tamTamanios);

        CargarMascota(listaMascotas,
                      tamMascota,
                      idMascota,
                      nombreMascota,
                      edadMascota,
                      sexoMascota,
                      tipoMascota,
                      idDescripcion,
                      idPais,
                      idTamanio);

        printf("Desea cargar otra Mascota?(s/n)\n");
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

    return idMascota;
}

char PedirSexoDeLaMascota()
{
    char caracterIngresado;

    do
    {
        caracterIngresado = PedirUnCaracter("Ingrese el sexo de la Mascota(m/f): ");
        caracterIngresado = tolower(caracterIngresado);

        if(caracterIngresado != 'f' && caracterIngresado != 'm')
        {
            printf("\nError! Opcion ingresada es invalida!\n");
            printf("Ingrese una de las dos opciones dadas!\n");
        }
    }
    while(caracterIngresado != 'f' && caracterIngresado != 'm');

    return caracterIngresado;
}

void PedirTipoDeMascota(char cadena[])
{
    char tipoIngresado[10];

    do
    {
        PedirUnaCadena(tipoIngresado, 10, "Ingrese el tipo de la mascota(perro/gato): ");
        FormalizarUnNombre(tipoIngresado, 10);

        if(strcmp(tipoIngresado, "Perro") != 0 && strcmp(tipoIngresado, "Gato") != 0)
        {
            printf("\nError! Opcion ingresada es invalida!\n");
            printf("Ingrese una de las dos opciones dadas!\n");
        }
    }
    while(strcmp(tipoIngresado, "Perro") != 0 && strcmp(tipoIngresado, "Gato") != 0);

    strcpy(cadena, tipoIngresado);
}

int PedirRazaDeLaMascota(eDescripcion listaDescripciones[], int tamDescripcion)
{
    int idIngresado;

    do
    {
        printf("\n***Lista de Razas disponibles***\n");
        for(int i = 0; i < tamDescripcion; i++)
        {
            printf("%d. %s\n", i+1,  listaDescripciones[i].descripcion);
        }

        idIngresado = PedirUnNumeroEntero("Ingrese una de las razas disponibles: ");

        if(idIngresado < 1 || idIngresado > 4)
        {
            printf("\nError! Opcion ingresada es invalida!\n");
            printf("Elija una de las opciones del listado de razas!\n");
        }
    }
    while(idIngresado < 1 || idIngresado > 4);

    return idIngresado;
}

int PedirRazaDeLaMascotaTipoPerro(eDescripcion listaDescripciones[], int tamDescripcion)
{
    int idIngresado;

    do
    {
        printf("\n***Lista de Razas disponibles del Tipo Perro***\n");
        for(int i = 0; i < tamDescripcion; i++)
        {
            if((i+1) < 3)
            {
                printf("%d. %s\n", i+1,  listaDescripciones[i].descripcion);
            }
        }

        idIngresado = PedirUnNumeroEntero("Ingrese una de las razas disponibles: ");

        if(idIngresado < 1 || idIngresado > 2)
        {
            printf("\nError! Opcion ingresada es invalida!\n");
            printf("Elija una de las opciones del listado de razas!\n");
        }
    }
    while(idIngresado < 1 || idIngresado > 2);

    return idIngresado;
}

int PedirRazaDeLaMascotaTipoGato(eDescripcion listaDescripciones[], int tamDescripcion)
{
    int idIngresado;

    do
    {
        printf("\n***Lista de Razas disponibles del Tipo Gato***\n");
        for(int i = 0; i < tamDescripcion; i++)
        {
            if((i+1) > 2)
            {
                printf("%d. %s\n", i+1,  listaDescripciones[i].descripcion);
            }
        }

        idIngresado = PedirUnNumeroEntero("Ingrese una de las razas disponibles: ");

        if(idIngresado < 3 || idIngresado > 4)
        {
            printf("\nError! Opcion ingresada es invalida!\n");
            printf("Elija una de las opciones del listado de razas!\n");
        }
    }
    while(idIngresado < 3 || idIngresado > 4);

    return idIngresado;
}

int PedirTamanioDeLaMascota(eTamanio listaTamanio[], int tamTamanios)
{
    int idIngresado;

    do
    {
        printf("\n***Lista de Tamanios de Mascotas***\n");
        for(int i = 0; i < tamTamanios; i++)
        {
            printf("%d. %s\n", i+1, listaTamanio[i].tamanio);
        }
        idIngresado = PedirUnNumeroEntero("Ingrese uno de los tamanios: ");

        if(idIngresado < 1 || idIngresado > 3)
        {
            printf("\nError! Opcion ingresada es invalida!\n");
            printf("Elija una de las opciones del listado de tamanios!\n");
        }
    }
    while(idIngresado < 1 || idIngresado > 3);

    return idIngresado;
}

void CargarMascota(eMascota listaMascotas[],
                   int tamMascota,
                   int idMascota,
                   char nombreMascota[],
                   int edadMascota,
                   char sexoMascota,
                   char tipoMascota[],
                   int idDescripcion,
                   int idPais,
                   int idTamanio)
{
    int espacioVacio;

    espacioVacio = BuscarPrimerEspacioVacioEnElArrayMascotas(listaMascotas, tamMascota);

    if(listaMascotas != 0 && tamMascota > 0 && espacioVacio != -1)
    {
        listaMascotas[espacioVacio].id = idMascota;
        strcpy(listaMascotas[espacioVacio].nombre, nombreMascota);
        listaMascotas[espacioVacio].edad = edadMascota;
        listaMascotas[espacioVacio].sexo = sexoMascota;
        strcpy(listaMascotas[espacioVacio].tipo, tipoMascota);
        listaMascotas[espacioVacio].idDescripcion = idDescripcion;
        listaMascotas[espacioVacio].idPais = idPais;
        listaMascotas[espacioVacio].idTamanio = idTamanio;
        listaMascotas[espacioVacio].isEmpty = 0;
    }
}

int BuscarPrimerEspacioVacioEnElArrayMascotas(eMascota listaMascotas[], int tamMascota)
{
    int indiceVacio;

    int i;

    indiceVacio = -1;

    if(listaMascotas != NULL && tamMascota > 0)
    {
        for(i = 0; i < tamMascota; i++)
        {
            if(listaMascotas[i].isEmpty == 1)
            {
                indiceVacio = i;
                break;
            }
        }
    }

    return indiceVacio;
}

void ListarRazasConSusMascotas(eMascota listaMascotas[],eDescripcion listaDescripciones[],
                               int tamMascota, int tamDescripcion)
{
    if((listaMascotas != NULL && listaDescripciones != NULL) && (tamMascota > 0 && tamDescripcion > 0))
    {
        printf("\n***Lista Razas y las Mascotas que pertenecen a tal***\n");

        for(int i = 0; i < tamDescripcion; i++)
        {
            ListarMascotasDeLaRaza(listaMascotas, listaDescripciones, tamMascota, i);
        }
    }
}

void ListarMascotasDeLaRaza(eMascota listaMascotas[],
                            eDescripcion listaDescripciones[],
                            int tamMascota,
                            int indiceDescripcion)
{
    printf("\n **%s**\n", listaDescripciones[indiceDescripcion].descripcion);
    printf("ID   NOMBRE   EDAD   SEXO    TIPO\n");
    for(int j = 0; j < tamMascota; j++)
    {
        if((listaMascotas[j].idDescripcion == listaDescripciones[indiceDescripcion].idDescripcion) &&
            listaMascotas[j].isEmpty == 0)
        {
            printf("%02d   %6s   %4d   %4c   %5s\n",listaMascotas[j].id,
                                                    listaMascotas[j].nombre,
                                                    listaMascotas[j].edad,
                                                    listaMascotas[j].sexo,
                                                    listaMascotas[j].tipo);
        }
    }
}

void MostrarListadoDeMascotasEnAltas(eMascota listaMascota[], int tamMascota)
{
    printf("ID   NOMBRE   EDAD   SEXO    TIPO\n");
    for(int i = 0; i < tamMascota; i++)
    {
        if(listaMascota[i].isEmpty == 0)
        {
            printf("%02d   %6s   %4d   %4c   %5s\n",listaMascota[i].id,
                                                    listaMascota[i].nombre,
                                                    listaMascota[i].edad,
                                                    listaMascota[i].sexo,
                                                    listaMascota[i].tipo);
        }
    }
}

void MostrarListadoDeMascotasEnBajas(eMascota listaMascota[], int tamMascota)
{
    printf("ID   NOMBRE   EDAD   SEXO    TIPO\n");
    for(int i = 0; i < tamMascota; i++)
    {
        if(listaMascota[i].isEmpty == 1)
        {
            printf("%02d   %6s   %4d   %4c   %5s\n",listaMascota[i].id,
                                                    listaMascota[i].nombre,
                                                    listaMascota[i].edad,
                                                    listaMascota[i].sexo,
                                                    listaMascota[i].tipo);
        }
    }
}

void DarDeAltaUnaMascotaBaja(eMascota listaMascota[], int tamMascota)
{
    int idIngresado;

    MostrarListadoDeMascotasEnBajas(listaMascota, tamMascota);
    idIngresado = PedirUnNumeroEntero("Ingrese el ID de la Mascota que quiere dar de Alta: ");

    for(int i = 0; i < tamMascota; i++)
    {
        if(listaMascota[i].id == idIngresado && listaMascota[i].isEmpty == 1)
        {
            listaMascota[i].isEmpty = 0;
            break;
        }
    }
}

//------------------------------------------------------------

void ListarMascotasRespectoASuTamanio(eMascota listaMascotas[], eTamanio listaTamanios[], int tamMascota, int tamTamanio)
{
    printf("ID   NOMBRE   EDAD   SEXO    TIPO      PESO\n");
    for(int j = 0; j < tamTamanio; j++)
    {
        ListarMascotasConSuTamanio(listaMascotas, listaTamanios, tamMascota, j);
    }
}

void ListarMascotasConSuTamanio(eMascota listaMascotas[], eTamanio listaTamanios[], int tamMascota, int indiceTamanio)
{
    for(int i = 0; i < tamMascota; i++)
    {
        if(listaMascotas[i].idTamanio == listaTamanios[indiceTamanio].idTamanio && listaMascotas[i].isEmpty == 0)
        {
            printf("%02d   %6s   %4d   %4c   %5s   %7s\n",listaMascotas[i].id,
                                                          listaMascotas[i].nombre,
                                                          listaMascotas[i].edad,
                                                          listaMascotas[i].sexo,
                                                          listaMascotas[i].tipo,
                                                          listaTamanios[indiceTamanio].tamanio);
        }
    }
}

void BajarMascota(eMascota listaMascota[], int tamMascota)
{
    int idIngreado;

    MostrarListadoDeMascotasEnAltas(listaMascota, tamMascota);
    if(listaMascota != NULL && tamMascota > 0)
    {
        idIngreado = PedirUnNumeroEntero("\nIngrese el ID de la Mascota desea eliminar: ");

        if(idIngreado > 0)
        {
            for(int i = 0; i < tamMascota; i++)
            {
                if(listaMascota[i].id == idIngreado && listaMascota[i].isEmpty == 0)
                {
                    listaMascota[i].isEmpty = 1;
                    break;
                }
            }
        }
    }
}

void RealizarModificacionesDeDatosDeUnaMascota(eMascota listaMascotas[],
                                               eDescripcion listaDescripciones[],
                                               eTamanio listaTamanios[],
                                               int tamMascota,
                                               int tamDescripcion,
                                               int tamTamanio)
{
    int idIngresado;
    int indice;

    MostrarListadoDeMascotasEnAltas(listaMascotas, tamMascota);

    idIngresado = PedirUnNumeroEntero("\nIngrese el ID de la Mascota que desea modificar: ");

    indice = BuscarIndiceDeMascotaPorId(listaMascotas, tamMascota, idIngresado);

    ModificarDatosDeUnaMascota(listaMascotas,
                               listaDescripciones,
                               listaTamanios,
                               tamMascota,
                               tamDescripcion,
                               tamTamanio,
                               indice);
}

int BuscarIndiceDeMascotaPorId(eMascota listaMascotas[], int tamMascota, int idABuscar)
{
    int indiceDelId;

    int i;

    indiceDelId = -1;

    if(listaMascotas != NULL && tamMascota > 0 && idABuscar > 0)
    {
        for(i = 0; i < tamMascota; i++)
        {
            if(listaMascotas[i].id == idABuscar)
            {
                indiceDelId = i;
                break;
            }
        }
    }

    return indiceDelId;
}

void ModificarDatosDeUnaMascota(eMascota listaMascotas[],
                                eDescripcion listaDescripciones[],
                                eTamanio listaTamanios[],
                                int tamMascota,
                                int tamDescripcion,
                                int tamTamanios,
                                int indice)
{
    int opcion;
    int bandera;

    bandera = 0;

    if(indice != -1)
    {
        do
        {
            opcion = MostrarMenuDeModificacionesDeMascotas(bandera);

            bandera = 1;

            if(opcion < 1 || opcion > 7)
            {
                printf("\nError! Opcion invalida!\n");
                printf("Ingresar una opcion del sub-menu: ");
                fflush(stdin);
                scanf("%d", &opcion);
            }else
            {
                switch(opcion)
                {
                    case 1:
                        PedirUnaCadena(listaMascotas[indice].nombre, 25, "\nIngrese el nombre de la Mascota: ");
                        break;

                    case 2:
                        listaMascotas[indice].edad = PedirUnNumeroEntero("\nIngrese la edad de la Mascota: ");
                        break;

                    case 3:
                        listaMascotas[indice].sexo = PedirSexoDeLaMascota();
                        break;

                    case 4:
                        PedirTipoDeMascota(listaMascotas[indice].tipo);
                        break;

                    case 5:
                        if(strcmp(listaMascotas[indice].tipo, "Perro") == 0)
                        {
                            listaMascotas[indice].idDescripcion = PedirRazaDeLaMascotaTipoPerro(listaDescripciones, tamDescripcion);
                        }else
                        {
                            if(strcmp(listaMascotas[indice].tipo, "Gato") == 0)
                            {
                                listaMascotas[indice].idDescripcion = PedirRazaDeLaMascotaTipoGato(listaDescripciones, tamDescripcion);
                            }
                        }
                        break;

                    case 6:
                        listaMascotas[indice].idTamanio = PedirTamanioDeLaMascota(listaTamanios, tamTamanios);
                        break;

                    default:
                        break;
                }
            }
        }
        while(opcion != 7);
    }
}

int MostrarMenuDeModificacionesDeMascotas(int bandera)
{
    int opcion;

    if(bandera == 0)
    {
        printf("\nQue desea modificar?\n");
    }else
    {
        printf("Desea modificar algo mas?\n");
    }
    printf("1. Nombre\n");
    printf("2. Edad \n");
    printf("3. Sexo\n");
    printf("4. Tipo\n");
    printf("5. Raza\n");
    printf("6. Tamanio\n");
    printf("7. Continuar\n\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void MostarPaisConMasMascotas(eMascota listaMascotas[],
                              ePais listaPaises[],
                              int tamMascota,
                              int tamPaises)
{
    int contador[tamPaises];
    int paisMaximo;
    int indicePaisMaximo;

    InicializarUnContadorTipoArray(contador, tamPaises);

    for(int i = 0; i < tamPaises; i++)
    {
        for(int j = 0; j < tamMascota; j++)
        {
            if(listaMascotas[j].idPais == listaPaises[i].idPais && listaMascotas[j].isEmpty == 0)
            {
                contador[i]++;
            }
        }
    }

    for(int i = 0; i < tamPaises; i++)
    {
        if(i == 0 || paisMaximo < contador[i])
        {
            paisMaximo = contador[i];
            indicePaisMaximo = i;
        }
    }

    printf("El pais con mas mascotas es %s\n",listaPaises[indicePaisMaximo].nombreDePais);
}


void OrdenarMascotasPorCodigoTelefonico(eMascota listaMascotas[],int tamMascota)
{
    int i;
    int j;

    eMascota mascotaAux;

    for(i = 0; i < tamMascota; i++)
    {
        for(j = i + 1; j < tamMascota; j++)
        {
            if(listaMascotas[i].codigoTelefonico < listaMascotas[j].codigoTelefonico)
            {
                mascotaAux = listaMascotas[i];
                listaMascotas[i] = listaMascotas[j];
                listaMascotas[j] = mascotaAux;
            }
        }
    }
}
