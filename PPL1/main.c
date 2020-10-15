#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "miBiblioteca.h"
#include "bibliotecaMascota.h"

#define TAM_MASCOTAS 10
#define TAM_DESCRIPCION 6
#define TAM_TAMANIO 3
#define TAM_PAIS 5

int main()
{
    int contadorIdMascota;
    int contadorIdRaza;
    int opcion;

    eDescripcion descripciones[TAM_DESCRIPCION];
    eTamanio tamanios[TAM_TAMANIO];
    ePais paises[TAM_PAIS];
    eMascota mascotas[TAM_MASCOTAS];

    contadorIdMascota = 0;
    contadorIdRaza = 0;

    //Inicializacion
    InicializarArrayDescripcion(descripciones, TAM_DESCRIPCION);
    InicializarArrayTamanio(tamanios, TAM_TAMANIO);
    InicializarArrayPais(paises, TAM_PAIS);
    InicializarArrayMascotas(mascotas, TAM_MASCOTAS);

    //Hardcodeo
    HardCodearArrayDescripcion(descripciones, 6, &contadorIdRaza);
    HardCodearArrayTamanio(tamanios, 3);
    HardCodearArrayPais(paises, 5);
    HardCodearArrayMascotas(mascotas, 7, &contadorIdMascota);

    do
    {
        opcion = MostrarMenu(1, 11);

        switch(opcion)
        {
            case 1:
                contadorIdMascota++;
                contadorIdMascota = RealizarAltasDeMascotas(mascotas,descripciones,tamanios,paises,TAM_MASCOTAS,TAM_DESCRIPCION,TAM_TAMANIO,contadorIdMascota);
                break;

            case 2:
                DarDeAltaUnaMascotaBaja(mascotas, TAM_MASCOTAS);
                break;

            case 3:
                BajarMascota(mascotas, TAM_MASCOTAS);
                break;

            case 4:
                contadorIdRaza++;
                contadorIdRaza = RealizarAltasDeRazas(descripciones,paises, TAM_DESCRIPCION,TAM_PAIS, contadorIdRaza);
                break;

            case 5:
                RealizarModificacionesDeDatosDeUnaMascota(mascotas,descripciones,tamanios,TAM_MASCOTAS,TAM_DESCRIPCION,TAM_TAMANIO);
                break;

            case 6:
                ListarRazasConSusMascotas(mascotas, descripciones, TAM_MASCOTAS, TAM_DESCRIPCION);
                break;

            case 7:
                MostrarListadoMascotasConRazaYOrigen(mascotas,descripciones,paises,TAM_MASCOTAS,TAM_DESCRIPCION,TAM_PAIS);
                break;

            case 8:
                ListarMascotasRespectoASuTamanio(mascotas, tamanios, TAM_MASCOTAS, TAM_TAMANIO);
                break;

            case 9:
                MostarPaisConMasMascotas(mascotas, paises, TAM_MASCOTAS, TAM_PAIS);
                break;

            case 10:
                OrdenarMascotasPorCodigoTelefonico(mascotas,TAM_MASCOTAS);
                MostrarListadoMascotasConRazaYOrigen(mascotas,descripciones,paises,TAM_MASCOTAS,TAM_DESCRIPCION,TAM_PAIS);
                break;

            default:
                break;
        }
        system("pause");
        system("cls");
    }
    while(opcion != 11);


    return 0;
}
