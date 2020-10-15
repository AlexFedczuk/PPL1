typedef struct
{
    int idDescripcion;
    char descripcion[25];
}eDescripcion;

typedef struct
{
    int idTamanio;
    char tamanio[10];
}eTamanio;

typedef struct
{
    int idPais;
    char nombreDePais[25];
    char continente[25];
    int codigoTelefonico;
}ePais;

/**--------------------Inicializacion------------------------*/
void InicializarArrayDescripcion(eDescripcion lista[], int tam);
void InicializarArrayTamanio(eTamanio lista[], int tam);
void InicializarArrayPais(ePais lista[], int tam);

/**--------------------Hard codeo---------------------------*/
void HardCodearArrayDescripcion(eDescripcion lista[], int tam, int* contadorId);
void HardCodearArrayTamanio(eTamanio lista[], int tam);
void HardCodearArrayPais(ePais lista[], int tam);

/**--------------------Parte 4---------------------------*/
int RealizarAltasDeRazas(eDescripcion listaDescripciones[], ePais listaPaises[], int tamDescripciones, int tamPais, int contadorIdRaza);
void CargarRaza(eDescripcion listaDescripciones[], int tamDescripciones, int idRaza, char nombreRaza[]);
int BuscarPrimerEspacioVacioEnElArrayDescripcions(eDescripcion listaDescripciones[], int tamDescripcion);

/**--------------------Parte 5---------------------------*/
void MostrarListadoDePaises(ePais listaPaises[], int tamPais);
