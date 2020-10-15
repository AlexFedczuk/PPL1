#include "bibliotecaRaza.h"

typedef struct
{
    int id;
    char nombre[25];
    int edad;
    char sexo;
    char tipo[10];
    int isEmpty;
    int idDescripcion;
    int idTamanio;
    int idPais;
    int codigoTelefonico;
}eMascota;

/**--------------------Inicializacion------------------------*/
void InicializarArrayMascotas(eMascota lista[], int tam);

/**--------------------Hard codeo---------------------------*/
void HardCodearArrayMascotas(eMascota lista[], int tam, int* idContador);

/**--------------------Parte 1---------------------------*/
void MostrarListadoMascotasConRazaYOrigen(eMascota listaMascota[],
                                          eDescripcion listaDescripcion[],
                                          ePais listaPais[],
                                          int tamMascota,
                                          int tamDescripcion,
                                          int tamPais);
int BuscarIndiceDeLaRazaDeLaMascota(eMascota listaMascota[],
                                    eDescripcion listaDescripcion[],
                                    int tamDescripcion,
                                    int indice);
int BuscarIndiceDelPaisDeLaMascota(eMascota listaMascota[],
                                   ePais listaPais[],
                                   int tamPais,
                                   int indice);
int BuscarIndiceDelTamanioDeLaMascota(eMascota listaMascota[],
                                      eTamanio listaTamanio[],
                                      int tamTamanio,
                                      int indice);
/**--------------------Parte 2---------------------------*/
int MostrarMenu(int opcionMinima, int opcionMaxima);
int RealizarAltasDeMascotas(eMascota listaMascotas[],
                             eDescripcion listaDescripciones[],
                             eTamanio listaTamanio[],
                             ePais listaPaises[],
                             int tamMascota,
                             int tamDescripcion,
                             int tamTamanios,
                             int contadorId);
char PedirSexoDeLaMascota();
void PedirTipoDeMascota(char cadena[]);
int PedirRazaDeLaMascota(eDescripcion listaDescripciones[], int tamDescripcion);
int PedirRazaDeLaMascotaTipoPerro(eDescripcion listaDescripciones[], int tamDescripcion);
int PedirRazaDeLaMascotaTipoGato(eDescripcion listaDescripciones[], int tamDescripcion);
int PedirTamanioDeLaMascota(eTamanio listaTamanios[], int tamTamanio);
void CargarMascota(eMascota listaMascotas[],
                   int tamMascota,
                   int idMascota,
                   char nombreMascota[],
                   int edadMascota,
                   char sexoMascota,
                   char tipoMascota[],
                   int idDescripcion,
                   int idPais,
                   int idTamanio);
int BuscarPrimerEspacioVacioEnElArrayMascotas(eMascota lista[], int tam);
void ListarRazasConSusMascotas(eMascota listaMascotas[],eDescripcion listaDescripciones[],
                                  int tamMascota, int tamDescripcion);
void ListarMascotasDeLaRaza(eMascota listaMascotas[],
                            eDescripcion listaDescripciones[],
                            int tamMascota,
                            int indiceDescripcion);

/**--------------------Parte 3---------------------------*/
void ListarMascotasRespectoASuTamanio(eMascota listaMascotas[],
                                      eTamanio listaTamanios[],
                                      int tamMascota,
                                      int tamTamanio);
void ListarMascotasConSuTamanio(eMascota listaMascotas[],
                                eTamanio listaTamanios[],
                                int tamMascota,
                                int indiceTamanio);
void BajarMascota(eMascota listaMascota[],
                  int tamMascota);

/**--------------------Parte 4---------------------------*/
void RealizarModificacionesDeDatosDeUnaMascota(eMascota listaMascotas[],
                                               eDescripcion listaDescripciones[],
                                               eTamanio listaTamanios[],
                                               int tamMascota,
                                               int tamDescripcion,
                                               int tamTamanio);
int BuscarIndiceDeMascotaPorId(eMascota listaMascotas[], int tamMascota, int idABuscar);
void ModificarDatosDeUnaMascota(eMascota listaMascotas[],
                                eDescripcion listaDescripciones[],
                                eTamanio listaTamanios[],
                                int tamMascota,
                                int tamDescripcion,
                                int tamTamanios,
                                int indice);
int MostrarMenuDeModificacionesDeMascotas(int bandera);
void MostarPaisConMasMascotas(eMascota listaMascotas[],
                              ePais listaPaises[],
                              int tamMascota,
                              int tamPaises);

/**--------------------Parte 5---------------------------*/
void OrdenarMascotasPorCodigoTelefonico(eMascota listaMascotas[],int tamMascota);

//---------------------------------------------------------
void MostrarListadoDeMascotasEnAltas(eMascota listaMascota[], int tamMascota);
void MostrarListadoDeMascotasEnBajas(eMascota listaMascota[], int tamMascota);
void DarDeAltaUnaMascotaBaja(eMascota listaMascota[], int tamMascota);


