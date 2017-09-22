#define TAM 20

typedef struct
{
    char nombre[50];
    int edad;
    long int dni;
    int estado;

} ePersona;

/** \brief Buscar un lugar libre, y toma los datos de la estructura.
 *
 * \param Toma los lugares, y los escribe con el nombre, DNI y edad.
 * \return No retorna datos.
 *
 */

void cargarPersona(ePersona arreglo[]);

/** \brief Busca el DNI y cambia el estado a 0, para poder ocupar ese lugar por una nueva persona.
 *
 * \param Toma DNI a borrar.
 * \return No retorna datos.
 *
 */

void buscarDni(ePersona arreglo[]);

/** \brief Inicializa los estados a 0.
 *
 * \param Pone todos los estados a 0 para cargarlos.
 * \return No retorna datos.
 *
 */

void inicializar(ePersona arreglo[]);

/** \brief Ordena los nombres de las personas, y los elementos de la estrutura, por orden alfabetico.
 *
 * \param Toma nombres y los ordena.
 * \return No retorna datos.
 *
 */

void ordenar(ePersona arreglo[]);

/** \brief Muestra los datos de todas la personas ingresadas.
 *
 * \param Muestra los datos de las personas con estado 1.
 * \return No retorna datos.
 *
 */

void mostrar(ePersona arreglo[]);

/** \brief Realiza el grafico con los parametros de edad establecidos.
 *
 * \param Toma los datos de cada de cada persona ingresada con estado 1.
 * \return No retorna datos.
 *
 */

void grafico(ePersona arreglo[]);

/** \brief No deja ingresar numeros cuando se deba ingresar el nombre.
 *
 * \param No ingresa numeros.
 * \return Retorna el entero correspondiente a cada caso.
 *
 */

int soloLetra(char Array[]);
