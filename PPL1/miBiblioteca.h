typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;
}eEstructura;

/** \brief Esta funcion se encarga simplemente de solicitar al usuario
 una cadena de caracteres(Por ej: nombre, apellido, etc).
 *
 * \param cadena[] char. Este parametro sera el que se cargara con la
 cadena de caracteres que halla ingresado el usuario.
 * \param buffer int. La cantidad de caracteres que COMO MUCHO
 puede ocupar el string.
 * \param mensaje[] char. El mensaje que se le comunicara al usuario
 para instruirlo.
 * \return void
 *
 */
void PedirUnaCadena(char cadena[], int buffer, char mensaje[]);

/** \brief Esta funcion se ocupa de la primera parte de formalizar
un nombre y apellido, se ocupa de CONCATENAR 'apellido, nombre' y
pasar todo a minuscula.
 *
 * \param apellidoNombre[] char. El array donde se cargara el apellido
 y nombre concatenado.
 * \param apellido[] char. El apellido a procesar.
 * \param nombre[] char. El nombre a procesar.
 * \return void
 *
 */
void FormalizarApellidoNombreParte1(char apellidoNombre[], char apellido[], char nombre[]);

/** \brief Esta funcion se encarga de finalizar la formalizacion del
'apellido, nombre', dejando la primera letra del apellido/nombre con
mayuscula y el resto minuscula.
 *
 * \param buffer int. La cantidad de caracteres que puede ocupar
 COMO MUCHO el string
 * \param apellidoNombre[] char. El 'apellido, nombre' a terminar
de procesar
 * \return void
 *
 */
void FormalizarApellidoNombreParte2(int buffer, char apellidoNombre[]);

/**----------------- Inicializaciones ---------------------*/
void InicializarLosElementosDeUnArray(eEstructura lista[], int tam);
void InicializarUnContadorTipoArray(int contadorArray[], int buffer);

/**----------------- Hard Codeo ---------------------*/

/**----------------- Ingreso de Datos & Altas ---------------------*/
int PedirUnNumeroEntero(char mensaje[]);
float PedirUnNumeroFlotante(char mensaje[]);
char PedirUnCaracter(char mensaje[]);
void PedirUnString(char string[], char mensaje[]);
void PedirDatosDeUnaEntidadParaUnArray(eEstructura lista[], int tam);
void AgregarDatosDeUnaEntidadAlArray(eEstructura lista[], int tam, int id, char nombre[], char apellido[], float salario, int sector);

/**----------------- Modificacion de datos ---------------------*/
void ModificarUnaEntidad(eEstructura lista[], int tam);

/**----------------- Eliminacion de datos o Entidades & Bajas ---------------------*/
int RemoverUnaEntidadDeUnArray(eEstructura lista[], int tam, int idIngresado);
void RealizarUnaBajaDeUnaEntidad(eEstructura lista[], int tam);
int EliminarUnaEntidadDeUnArray(eEstructura lista[], int tam, int idIngresado);

/**----------------- Muestra de datos & Informes ---------------------*/
void ImprimirEntidades(eEstructura lista[], int tam);

/**----------------- Busqueda de Datos ---------------------*/
int BuscarPrimerEspacioVacioEnUnArray(eEstructura lista[], int tam);
int BuscarEntidadPorId(eEstructura lista[], int tam, int idABuscar);

/**----------------- Mostrar Menu y Devolver Opcion Ingresada  ---------------------*/
int MostrarUnSubMenuDeModificaciones(int opcionMinima, int opcionMaxima, int* bandera);
int MostrarUnSubMenuDeBajas(int opcionMinima, int opcionMaxima, int* bandera);

/**--------------------------------Formalizar----------------------------------*/
void FormalizarUnNombre(char nombre[], int buffer);
void FormalizarAApellidoYNombre(char apellidoNombre[], char apellido[], char nombre[]);
void FormalizarNombresDeUnArray(eEstructura lista[], int tam, int buffer);
void FormalizarApellidosDeUnArray(eEstructura lista[], int tam, int buffer);

/**--------------------------------Calcular------------------------------------*/
int SumarDosNumerosEnteros(int primerOperador, int segundoOperador);
float SumarDosNumerosFlotantes(float primerOperador, float segundoOperador);

int RestarDosNumerosEnteros(int primerOperador, int segundoOperador);
float RestarDosNumerosFlotantes(float primerOperador, float segundoOperador);

int MultiplicarDosNumerosEnteros(int primerOperador, int segundoOperador);
float MultiplicarDosNumerosFlotantes(float primerOperador, float segundoOperador);

int DividirDosNumerosEnteros(int primerOperador, int segundoOperador);
float DividirDosNumerosFlotantes(float primerOperador, float segundoOperador);

int CalcularTotalNumerosEnteros(eEstructura lista[], int tam);
float CalcularTotalNumerosFlotantes(eEstructura lista[], int tam);
int CalcularCantidadDeEntidades(eEstructura lista[], int tam);
float CalcularUnPromedio(int total, int divisor);

/**------ En desarrollo... -------------------------------------------------------*/

void OrdenarAlfabeticamente();//En desarrollo...
