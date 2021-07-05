#include <stdlib.h>
#include <stdio.h>
#include <math.h> // Libreria que trae las funciones matemáticas, log10.
#include <time.h> // Librería que trae las funciones srand, time y rand para generar valores aleatorios
#include <limits.h>

#define TRUE 1
#define FALSE 0

//Variables Globales
// Logintud del array guardado en una variable constante.
const int torres = 2;
const int pisos = 10;
const int apartamentos = 6;
const int c_hijos = 5;

int conjunto[torres][pisos][apartamentos] = {}; // Array Inicializado. (Simular torre).
const int size_tt = (sizeof(conjunto) / sizeof(int));
struct Jefe // Se crea la estructura del jefe.
{
    float cedula[size_tt] = {0};
    int edad[size_tt] = {0};
    char sexo[size_tt] = {' '};
    char pareja[size_tt] = {' '};
};

struct Nino // Se crea la estructura de los niños.
{
    int edad[size_tt][c_hijos] = {0};
    int cantidad[size_tt] = {0};
    char sexo[size_tt][c_hijos] = {' '};
};

struct Habitabilidad // Se crea la estructura de la habitabilidad de los apartamentos.
{
    int ocupado[size_tt] = {0};
    int estado[size_tt] = {0};
};

// Declaración global de los structs.
struct Nino nino;
struct Jefe jefe;
struct Habitabilidad habitabilidad;

// Inicialización de funciones
void menu();
void censo();

void r_encuestas();
void reportes();
void v_completa();
void buscar_jefe();
void rl_porcentaje();
void caso_especial();
void valor_modal();
void estadistica();

// funciones extras.
int digits(float value);              // saber la cantidad de digitos.
float alea_num(float min, float max); // generar valores random.

int main()
{
    srand(time(NULL));
    system("clear||cls");
    printf("Censo Residencial\n\n");
    menu();
    return 0;
}

void menu()
{
    do
    {
        char temp;
        int opcion = 0;
        do
        {
            system("clear||cls"); // Limpia pantalla
            ;                     // Limpiamos stdin
            printf("Administracion del Conjunto Residencial: \n");
            printf("\t1- Realizar encuestas.\n");
            printf("\t2- Reportes.\n");
            printf("\t3- Salir.\n");

            printf("\tSeleccione una opcion: "); // Aceptamos una entrada del usuario.
            scanf("%d", &opcion);
            scanf("%c", &temp);
            system("clear||cls");
            // validar caracteres.
        } while (opcion != 0 && opcion > 1 && opcion < 3 && temp != '\n' && getchar() != '\n'); // Se valida el menu para que el usuario no introduzca una opción diferente a la que queremos.

        switch (opcion)
        {
        case 1:
            // Censo
            system("clear||cls");
            censo(); // llamamos a la función.
            break;

        case 2:
            // Reportes
            reportes();
            break;
        case 3:
            exit(0); // functión para cerrar el programa.
            break;
        }
    } while (1);
}

void reportes()
{
    int opcion;
    char temp;
    do
    {
        system("clear||cls");
        do
        {
            opcion = 0;
            temp = ' ';
            system("clear||cls");
            printf("Elija el tipo de cambio que desee hacer: \n");
            printf("\t1- Visualizar informacion completa de un apartamento.\n");
            printf("\t2- Buscar informacion del jefe de familia.\n");
            printf("\t3- Relacion porcentual de genero.\n");
            printf("\t4- Casos especiales.\n");
            printf("\t5- Valor modal.\n");
            printf("\t6- Estadistica de habitabilidad.\n");
            printf("\t7- Menu anterior.\n");
            printf("\t8- Salir.\n");

            printf("Seleccione una opcion: ");
            scanf("%d", &opcion);
            scanf("%c", &temp); // validar caracteres.
            system("clear||cls");

        } while (opcion != 0 && opcion > 1 && opcion < 8 && temp != '\n' && getchar() != '\n');

        switch (opcion)
        {
        case 1:
            v_completa();
            break;
        case 2:
            buscar_jefe();
            break;
        case 3:
            rl_porcentaje();
            break;
        case 4:
            caso_especial();
            break;
        case 5:
            valor_modal();
            break;
        case 6:
            estadistica();
            break;
        case 7:
            main();
            break;
        case 8:
            exit(0); // functión para cerrar el programa.
            break;
        }
    } while (1);
}

void censo()
{

    int dec = 0, counts = 0, count = 0;
    char otro;
    for (int t = 0; t < torres; t++)
    {
        for (int p = 0; p < pisos; p++)
        {
            for (int a = 0; a < apartamentos; a++)
            {
                system("clear||cls"); // Limpia pantalla
                printf("Informacion de la Torre %d, Piso: %d, Apartamento: %d\n", t + 1, p + 1, a + 1);

                printf("Censo Residencial\n\n");

                // Encuesta Cedula ===START===
                do // Validar datos cuando el usuario lo ingresa.
                {
                    printf("\n\tDatos del jefe de familia: \n");
                    printf("\t\tCedula: V-");
                    scanf("%f", &jefe.cedula[counts]);

                    count = digits(jefe.cedula[counts]);
                    if (count < 7 || count > 7)
                    {
                        printf("\tFormato de la cedula incorrecta, por favor intente de nuevo.");
                        printf("\n\tPresiona ENTER para continuar.");
                        while (getchar() != '\n') // limpiar stdin
                            ;
                    }
                } while (count != 7);
                // Encuesta Cedula ===END===

                // Encuesta Edad ===START===
                do
                {
                    printf("\t\tEdad: ");
                    scanf("%d", &jefe.edad[counts]);

                    if (jefe.edad[counts] < 18)
                    {
                        printf("\nLa edad de la persona es menor de edad.");
                        printf("\nPresiona ENTER para continuar.");
                        while (getchar() != '\n') // limpiar stdin
                            ;
                    }
                } while (jefe.edad[counts] < 18);
                // Encuesta Edad ===END===

                // Encuesta Pareja ===START===
                do
                {
                    printf("\t\tTiene pareja (s/n)? ");
                    scanf(" %c", &jefe.pareja[counts]);
                    if (jefe.pareja[counts] != 's' && jefe.pareja[counts] != 'n')
                    {
                        printf("\tDebe de introducir (s/n).");
                        printf("Presiona ENTER para continuar.");
                        while (getchar() != '\n') // limpiar stdin
                            ;
                    }
                } while (jefe.pareja[counts] != 's' && jefe.pareja[counts] != 'n');
                // Encuesta Pareja ===END===

                // Encuesta Genero ===START===
                do
                {
                    printf("\t\tCual es su genero? (m/f): ");
                    scanf(" %c", &jefe.sexo[counts]);
                    if (jefe.sexo[counts] != 'm' && jefe.sexo[counts] != 'f')
                    {
                        printf("\tDebe de introducir (m/f).");
                        printf("Presiona ENTER para continuar.");
                        while (getchar() != '\n') // limpiar stdin
                            ;
                    }
                } while (jefe.sexo[counts] != 'm' && jefe.sexo[counts] != 'f');
                // Encuesta Genero ===END===

                // Niños en el apartamento
                printf("\n\tDatos de los niños: \n");

                printf("\t\tCuantos niños hay en el apartamento: ");
                scanf("%d", &nino.cantidad[counts]);

                for (int h = 1; h <= nino.cantidad[counts]; h++)
                {
                    printf("\t\tInformacion del niño #%d: \n", h);

                    // Encuesta Edad ===START===
                    do
                    {
                        printf("\t\tEdad: ");
                        scanf("%d", &nino.edad[counts][h]);

                        if (nino.edad[counts][h] > 17)
                        {
                            printf("\nLa edad de la persona es mayor de edad.");
                            printf("\nPresiona ENTER para continuar.");
                            while (getchar() != '\n') // limpiar stdin
                                ;
                        }

                    } while (nino.edad[counts][h] > 17);
                    // Encuesta Edad ===END===

                    // Encuesta Sexo ===START===
                    do
                    {
                        printf("\t\tCual es su genero? (m/f): ");
                        scanf(" %c", &nino.sexo[counts][h]);
                        if (nino.sexo[counts][h] != 'm' && nino.sexo[counts][h] != 'f')
                        {
                            printf("\tDebe de introducir (m/f).");
                            printf("Presiona ENTER para continuar.");
                            while (getchar() != '\n') // limpiar stdin
                                ;
                        }
                    } while (nino.sexo[counts][h] != 'm' && nino.sexo[counts][h] != 'f');
                    // Encuesta Edad ===END===
                    printf("\n");
                }

                // Apartamento situación (Alquilado, Propio, Familiar o Tercero) ====START====
                printf("\n\tDatos del apartamento: \n");
                do
                {
                    printf("\t\tEl apartamento es: ");
                    printf("\n\t\t\t1. Alquilado.");
                    printf("\n\t\t\t2. Propio.");
                    printf("\n\t\t\t3. Familiar o Tercero.");
                    printf("\n\t\t\tOpcion: ");
                    scanf("%d", &habitabilidad.estado[counts]);

                    if (habitabilidad.estado[counts] > 3)
                    {
                        printf("\tDebe de introducir un valor valido 1, 2 o 3.");
                        printf("Presiona ENTER para continuar.");
                        while (getchar() != '\n') // limpiar stdin
                            ;
                        getchar();
                    }
                } while (habitabilidad.estado[counts] < 1 || habitabilidad.estado[counts] > 3);
                // Apartamento situación (Alquilado, Propio, Familiar o Tercero) ====END====

                // Apartamento estados (Ocupado o Desocupado) ====START====
                do
                {
                    printf("\t\tEl apartamento esta: ");
                    printf("\n\t\t\t1. Ocupado.");
                    printf("\n\t\t\t2. Desocupado.");
                    printf("\n\t\t\tOpcion: ");
                    scanf("%d", &habitabilidad.ocupado[counts]);

                    if (habitabilidad.ocupado[counts] > 2)
                    {
                        printf("\tDebe de introducir un valor valido 1 o 2.");
                        printf("Presiona ENTER para continuar.");
                        while (getchar() != '\n') // limpiar stdin
                            ;
                        getchar();
                    }
                } while (habitabilidad.ocupado[counts] > 1 && habitabilidad.ocupado[counts] < 2);
                // Apartamento estados (Ocupado o Desocupado) ====END====

                // idea de salir del bucle.
            }
            printf("\nedesea introducir otro registro? (s/n): ");
            scanf(" %c", &otro);
            if (otro == 'n')
            {
                t = p = 1000;
                break;
            }
        }
    }
    menu();
}

void v_completa()
{
    system("clear||cls");
    int t = 0, p = 0, a = 0, index = 0;
    printf("Introduzca la inforamcion del apatarmento que desea buscar: \n");

    do
    {
        printf("Torre: ");
        scanf(" %d", &t);

        if (t < 1 || t > torres)
        {

            printf("\nEl número de torre es invalido, solo hay 2 torres.");
            printf("\nPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (t < 1 || t > torres);

    do
    {
        printf("Piso: ");
        scanf("%d", &p);

        if (p > pisos)
        {

            printf("\nEl número de piso es invalido, solo hay 10 pisos.");
            printf("\nPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (p > pisos);
    do
    {
        printf("Apartamento: ");
        scanf("%d", &a);

        if (a > apartamentos)
        {
            printf("\nEl número de apartamento es invalido, solo hay 6 apartamentos.");
            printf("\nPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (a > apartamentos);
    // La pocisión de indice para los arrays que contiene los datos.
    system("clear||cls");
    printf("La inforamcion solicitada es la siguiente: \n\n");
    printf("\tEl apartamento #%d, del piso: %d, de la torre: %d\n", a, p, t);

    index = t * p * a;
    index -= 1; // Se resta uno para ajustar la memoria.
    switch (habitabilidad.ocupado[index])
    {
    case 1: // Ocupado
        printf("\n\tJefe de familia: \n");
        printf("\t\tCedula: V-%.0f", jefe.cedula[index]);
        printf("\tEdad: %d", jefe.edad[index]);
        printf("\tSexo: %c", jefe.sexo[index]);

        switch (nino.cantidad[index])
        {
        case 0:
            printf("\n\n\tEste apartamento no tiene niños.");
            break;
        default:
            printf("\n\n\tInfantes: %d\n", nino.cantidad[index]);
            for (int h = 0; h < nino.cantidad[index]; h++)
            {
                printf("\n\t\tInfante #%d", h + 1);
                printf("\n\t\tEdad: %d, ", nino.edad[index][h]);
                printf("Sexo: %c", nino.sexo[index][h]);
            }

            break;
        }
        printf("\n\n\t\tEsta ocupado y es ", a, p, t);
        switch (habitabilidad.estado[index])
        {
        case 1:
            printf("alquilado.\n");
            break;
        case 2:
            printf("propio.\n");
            break;
        case 3:
            printf("de un familiar o tercero.\n");
            break;
        }
        printf("\n\nPresiona ENTER para continuar.");
        while (getchar() != '\n') // limpiar stdin
            ;                     // option TWO to clean stdin
        getchar();
        break;

    case 2: // Desocupado
        printf("\n\tJefe de familia: \n");
        printf("\t\tCedula: V-%.0f", jefe.cedula[index]);
        printf("\tEdad: %d", jefe.edad[index]);
        printf("\tSexo: %c", jefe.sexo[index]);

        switch (nino.cantidad[index])
        {
        case 0:
            printf("\n\n\tEste apartamento no tiene niños.");
            break;
        default:
            printf("\n\n\tInfantes: %d\n", nino.cantidad[index]);
            for (int h = 0; h < nino.cantidad[index]; h++)
            {
                printf("\n\t\tInfante #%d", h + 1);
                printf("\n\t\tEdad: %d, ", nino.edad[index][h]);
                printf("Sexo: %c", nino.sexo[index][h]);
            }
            break;
        }
        printf("\n\n\t\tEsta ocupado y es ", a, p, t);
        switch (habitabilidad.estado[index])
        {
        case 1:
            printf("alquilado.\n");
            break;
        case 2:
            printf("propio.\n");
            break;
        case 3:
            printf("de un familiar o tercero.\n");
            break;
        }
        break; // Desocupado
    }
    printf("\n\nPresiona ENTER para continuar.");
    while (getchar() != '\n') // limpiar stdin
        ;
    reportes();
}

void buscar_jefe()
{
    system("clear||cls");
    int index = 0, piso = 0, apartamento = 0, torre = 0;
    float buscar = 0;
    printf("Buscar por la cedula del Jefe de familia");
    printf("\nIntroduzca la cedula que quiere buscar: V-");
    scanf("%f", &buscar);

    for (int i = 0; i < size_tt; i++)
    {
        if (jefe.cedula[i] == buscar)
        {
            index = i;
            break;
        }

        if (i == size_tt)
        {
            printf("\n\tLa cedula es invalidad");
            printf("\n\tPresione ENTER para continuar");
            while (getchar() != '\n') // limpiar stdin
                ;                     // option TWO to clean stdin
            getchar();
            reportes();
        }
    }

    // Obtener el número de torre, piso y apartamento en las posiciones del array para despues mostrar en los enunciados.
    for (int q = 0; q < torres; q++)
    {
        for (int w = 0; w < pisos; w++)
        {
            for (int r = 0; r < apartamentos; r++)
            {
                if (conjunto[q][w][r] == index)
                {
                    torre = q;
                    piso = w;
                    apartamento = r;
                    r = w = q = 1000;
                    break;
                }
            }
        }
    }

    switch (habitabilidad.ocupado[index])
    {
    case 1: // Ocupado
        printf("\n\tJefe de familia: \n");
        printf("\t\tCedula: V-%.0f", jefe.cedula[index]);
        printf("\tEdad: %d", jefe.edad[index]);
        printf("\tSexo: %c", jefe.sexo[index]);

        switch (nino.cantidad[index])
        {
        case 0:
            printf("\n\tEste apartamento no tiene niños.");
            break;
        default:
            printf("\n\n\tInfantes: %d\n", nino.cantidad[index]);
            for (int h = 0; h < nino.cantidad[index]; h++)
            {
                printf("\n\t\tInfante #%d", h + 1);
                printf("\n\t\tEdad: %d, ", nino.edad[index][h]);
                printf("Sexo: %c", nino.sexo[index][h]);
            }
            printf("\n\n\tEl apartamento %d, del piso %d, torre %d.\n\t\tEsta ocupado y es ", apartamento + 1, piso + 1, torre + 1);
            switch (habitabilidad.estado[index])
            {
            case 1:
                printf("alquilado.\n");
                break;
            case 2:
                printf("propio.\n");
                break;
            case 3:
                printf("de un familiar o tercero.\n");
                break;
            }
            printf("\n\nPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            break;
        }
        break;

    case 2: // Desocupado
        printf("\n\tJefe de familia: \n");
        printf("\t\tCedula: V-%.0f", jefe.cedula[index]);
        printf("\tEdad: %d", jefe.edad[index]);
        printf("\tSexo: %c", jefe.sexo[index]);

        switch (nino.cantidad[index])
        {
        case 0:
            printf("\n\tEste apartamento no tiene niños.");
            break;
        default:
            printf("\n\tInfantes: %d\n", nino.cantidad[index]);
            for (int h = 0; h < nino.cantidad[index]; h++)
            {
                printf("\t\tInfante #%d\n", h + 1);
                printf("\t\tEdad: %d, ", nino.edad[index][h]);
                printf("Sexo: %c", nino.sexo[index][h]);
            }
            printf("\n\n\tEl apartamento %d, del piso %d, torre %d.\n\t\tEsta ocupado y es ", apartamento + 1, piso + 1, torre + 1);
            switch (habitabilidad.estado[index])
            {
            case 1:
                printf("alquilado.\n");
                break;
            case 2:
                printf("propio.\n");
                break;
            case 3:
                printf("de un familiar o tercero.\n");
                break;
            }
            break;
        }
        break; // Desocupado
    }
    printf("\n\nPresiona ENTER para continuar.");
    while (getchar() != '\n') // limpiar stdin
        ;
    reportes();
}

void rl_porcentaje()
{
    int m = 0, f = 0;
    float mp = 0, fp = 0;
    for (int i = 0; i < size_tt; i++)
    {

        switch (jefe.sexo[i])
        {
        case 'm':
            m++;
            break;

        case 'f':
            f++;
            break;
        }

        system("clear||cls");
        printf("Hay %d personas Masculinos y %d personas Femeninas\n", m, f);
        printf("\tLa relacion porcentual es: \n");
        mp = (float)m / 120 * 100; // Se utiliza el TypeCast para convertir los datos de las variable m y f a tipos de datos float.
        printf("\t%.2f% Hombres.", mp);
        fp = (float)f / 120 * 100;
        printf("\t%.2f% Mujeres.\n", fp);
    }

    printf("\n\tPresione ENTER para continuar");
    while (getchar() != '\n') // limpiar stdin
        ;
    reportes();
}

void caso_especial()
{
    system("clear||cls");
    int torre, piso, primero, segundo, tercero, index, p_index, s_index, t_index;
    primero = segundo = tercero = INT_MIN;

    printf("Busqueda de casos especiales.\n\n");
    printf("\tIntroduzca torre y piso para iniciar la busqueda de casos especiales.");

    do
    {
        printf("\n\t\tTorre (1 o %d): ", torres);
        scanf("%d", &torre);

        if (torre < 1 || torre > torres)
        {

            printf("\n\t\tEl número de torre es invalido, solo hay %d torres.", torres);
            printf("\n\tPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (torre < 1 || torre > torres);

    do
    {
        printf("\n\t\tPiso (1 al %): ", pisos);
        scanf("%d", &piso);

        if (piso > pisos)
        {

            printf("\n\t\tEl número de piso es invalido, solo hay %d pisos.", pisos);
            printf("\n\tPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (piso > pisos);

    index = torre * piso * pisos;
    for (int i = 0; i < index; i++)
    {
        if ((jefe.edad[i] >= 55 && jefe.sexo[i] == 'm' && jefe.pareja[i] == 'n' && nino.cantidad[i] == 0) || (jefe.edad[i] >= 55 && jefe.sexo[i] == 'f' && jefe.pareja[i] == 'n' && nino.cantidad[i] >= 2))
        {
            // Si el númer actual is mayor que el primero
            if (jefe.edad[i] > primero)
            {
                tercero = segundo;
                segundo = primero;
                s_index = p_index;
                primero = jefe.edad[i];
                p_index = i;
            }
            // Si la edad del jefe esta entre el primero y el segundo, actualiza el segundo.
            else if (jefe.edad[i] > segundo)
            {
                tercero = segundo;
                t_index = s_index;
                segundo = jefe.edad[i];
                s_index = i;
            }

            else if (jefe.edad[i] > tercero)
            {
                tercero = jefe.edad[i];
                t_index = i;
            }
        }
    }

    printf("\nLos top 3 son los siguientes: \n\n");
    printf("\tJefe de familia: \n");

    printf("\t\tTop 1: \n");
    printf("\t\t\tEdad: %d", jefe.edad[p_index]);
    printf("\n\t\t\tSexo: %c", jefe.sexo[p_index]);
    printf("\n\t\t\tInfantes: %d", nino.cantidad[p_index]);
    for (int i = 0; i < nino.cantidad[p_index]; i++)
    {
        printf("\n\t\t\t\tSexo: %c", nino.sexo[p_index][i]);
    }

    printf("\n\n\t\tTop 2: \n");
    printf("\t\t\tEdad: %d", jefe.edad[s_index]);
    printf("\n\t\t\tSexo: %c", jefe.sexo[s_index]);
    printf("\n\t\t\tInfantes: %d", nino.cantidad[s_index]);
    for (int i = 0; i < nino.cantidad[s_index]; i++)
    {
        printf("\n\t\t\t\tSexo: %c", nino.sexo[s_index][i]);
    }
    printf("\n\n\t\tTop 3: \n");
    printf("\t\t\tEdad: %d", jefe.edad[t_index]);
    printf("\n\t\t\tSexo: %c", jefe.sexo[t_index]);
    printf("\n\t\t\tInfantes: %d", nino.cantidad[t_index]);
    for (int i = 0; i < nino.cantidad[t_index]; i++)
    {
        printf("\n\t\t\t\tSexo: %c", nino.sexo[t_index][i]);
    }
    printf("\n\tPresiona ENTER para continuar.");
    while (getchar() != '\n') // limpiar stdin
        ;
    reportes();
}

void valor_modal()
{
    // Calcular la moda
    system("clear||cls");
    printf("Obtención del valor modal por edad de los jefes de familia por torres.");
    int m[torres] = {0}, q[torres] = {0};

    for (int t = 0; t < torres; t++)
    {
        printf("\n\nModa de la torre %d", t + 1);

        switch (t)
        {
        case 0:
            printf("\n\t\tEdad de los jefes:\n");
            for (int a = 0; a < size_tt / 2; a++)
            {
                printf("%d, ", jefe.edad[a]);
            }

            for (int i = 0; i < size_tt / 2; i++)
            {
                int count = 0;
                for (int j = 0; j < size_tt / 2; j++)
                    if (jefe.edad[j] == jefe.edad[i])
                        ++count;

                if (count > m[t])
                {
                    m[t] = count; //guardamos el mayor por el momento
                    q[t] = jefe.edad[i];
                }
            }
            break;

        case 1:
            printf("\n\t\tEdad de los jefes:\n");
            for (int a = size_tt / 2; a < size_tt; a++)
            {
                printf("%d, ", jefe.edad[a]);
            }

            for (int i = size_tt / 2; i < size_tt; i++)
            {
                int count = 0;
                for (int j = size_tt / 2; j < size_tt; j++)
                    if (jefe.edad[j] == jefe.edad[i])
                        ++count;

                if (count > m[t])
                {
                    m[t] = count; //guardamos el mayor por el momento
                    q[t] = jefe.edad[i];
                }
            }
            break;
        }
        //m tiene las repeticiones pero no se esta contando a si misma por eso m+1
        printf("\n\tTorre: #%d: \n\tla moda es: %d y tiene %d repeticiones ", t + 1, q[t], m[t]);
    }
    printf("\n\tPresiona ENTER para continuar.");
    while (getchar() != '\n') // limpiar stdin
        ;
    reportes();
}

void estadistica()
{
    float op, dp, o, d; // Estados de Ocupado y Desocupado.
    system("clear||cls");
    printf("Estadistica de habitabilidad del Conjunto Residencial.");
    for (int q = 0; q < torres; q++)
    {
        switch (q)
        {
        case 0:
            o = d = 0;
            op = dp = 0;
            for (int r = 0; r < size_tt / 2; r++)
            {

                switch (habitabilidad.ocupado[r])
                {
                case 1:
                    o++;
                    break;
                case 2:
                    d++;
                    break;
                }
            }
            break;
        case 1:
            o = d = 0;
            op = dp = 0;
            for (int r = size_tt / 2; r < size_tt; r++)
            {
                switch (habitabilidad.ocupado[r])
                {
                case 1:
                    o++;
                    break;
                case 2:
                    d++;
                    break;
                }
            }
            break;
        }
        printf("\nTorre #%d\n", q + 1);
        if (o > size_tt / 2 || d > size_tt / 2)
        {
            truncf(o /= 2);
            truncf(d /= 2);
        }
        printf("Hay %.0f Apartamentos Ocupados y %.0f Apartamentos Desocupados.\n", o, d);
        printf("\tLa relacion porcentual es: \n");
        op = o / size_tt * 100;
        printf("\t%.2f% Ocupados.", op);
        dp = d / size_tt * 100;
        printf("\t%.2f% Desocupados.\n", dp);
    }

    printf("\nRelacion conceptual del conjunto residencial.\n");
    o = d = 0;
    op = dp = 0;

    for (int r = 0; r < size_tt; r++)
    {

        switch (habitabilidad.ocupado[r])
        {

        case 1:
            o++;
            break;
        case 2:
            d++;
            break;
        }
    }
    printf("Hay %.0f Apartamentos Ocupados y %.0f Apartamentos Desocupados.\n", o, d);
    printf("\tLa relacion porcentual es: \n");
    op = o / size_tt * 100;
    printf("\t%.2f% Ocupados.", op);
    dp = d / size_tt * 100;
    printf("\t%.2f% Desocupados.\n", dp);
    printf("\n\tPresione ENTER para continuar");
    while (getchar() != '\n') // limpiar stdin
        ;                     // option TWO to clean stdin
    reportes();
}

int digits(float value)
{
    return (log10(value) + 1);
}
float alea_num(float min, float max)
{
    return min + rand() / (RAND_MAX / (max - min + 1));
}