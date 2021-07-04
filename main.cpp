#include <stdlib.h>
#include <stdio.h>
#include <math.h> // Libreria que trae las funciones matemáticas, log10.
#include <time.h> // Librería que trae las funciones srand, time y rand para generar valores aleatorios
#include <limits.h>

#define TRUE 1
#define FALSE 0

//Variables Globales
int torres[2][10][6] = {};                          // Array Inicializado. (Simular torre).
const int size_tt = (sizeof(torres) / sizeof(int)); // Logintud del array guardado en una variable constante.

struct Jefe // Se crea la estructura del jefe.
{
    float cedula[size_tt] = {0};
    int edad[size_tt] = {0};
    char sexo[size_tt] = {0};
    char pareja[size_tt] = {0};
};

struct Nino // Se crea la estructura de los niños.
{
    int edad[size_tt][5] = {0};
    int cantidad[size_tt] = {0};
    char sexo[size_tt][5] = {0};
};

struct Habitabilidad // Se crea la estructura de la habitabilidad de los apartamentos.
{
    int ocupado[size_tt], estado[size_tt];
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
        int opcion;
        do
        {
            system("clear||cls"); // Limpia pantalla
            printf("Administracion del Conjunto Residencial: \n");
            printf("\t1- Realizar encuestas.\n");
            printf("\t2- Reportes.\n");
            printf("\t3- Salir.\n");

            printf("\tSeleccione una opcion: ");
            scanf("%d", &opcion);           // Aceptamos una entrada del usuario.
        } while (opcion < 1 && opcion > 3); // Se valida el menu para que el usuario no introduzca una opción diferente a la que queremos.

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
    do
    {
        system("clear||cls");
        do
        {
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
        } while (opcion < 1 && opcion > 8);

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

    int dec = 0;
    int counts = 0;
    char otro;

    for (int u = 0; u < 2; u++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int o = 0; o < 6; o++)
            {
                system("clear||cls"); // Limpia pantalla
                printf("Informacion de la Torre %d, Piso: %d, Apartamento: %d\n", u + 1, i + 1, o + 1);

                printf("Censo Residencial\n\n");

                printf("\n\tDatos del jefe de familia: \n");

                // Introducción Automática de datos Jefe ----Start----
                // Cédula
                jefe.cedula[counts] = alea_num(0000000, 9999999);
                printf("\tCédula: V-%.0f\n", jefe.cedula[counts]);
                // Edad
                jefe.edad[counts] = alea_num(20, 80);
                printf("\tEdad: %d\n", jefe.edad[counts]);
                // Pareja
                dec = alea_num(1, 2);
                switch (dec)
                {
                case 1:
                    jefe.pareja[counts] = 's';
                    break;
                case 2:
                    jefe.pareja[counts] = 'n';
                    break;
                }
                printf("\t¿Tiene pareja (s/n)? %c\n", jefe.pareja[counts]);
                // Sexo
                dec = alea_num(1, 2);
                switch (dec)
                {
                case 1:
                    jefe.sexo[counts] = 'm';
                    break;
                case 2:
                    jefe.sexo[counts] = 'f';
                    break;
                }
                printf("\t¿Cuál es su genero? (m/f): %c\n", jefe.sexo[counts]);
                // Introducción Automática de datos Jefe ----End----

                // Introducción Automática de datos Infante ----Start----
                // Cantidad
                nino.cantidad[counts] = alea_num(0, 5);
                printf("\n\t\tCuantos niños hay en el apartamento: %d", nino.cantidad[counts]);

                for (int h = 0; h < nino.cantidad[counts]; h++)
                {
                    printf("\n\t\tInformacion del niño #%d: \n", h + 1);

                    // Edad
                    nino.edad[counts][h] = alea_num(0, 17);
                    printf("\t\t\tEdad: %d", nino.edad[counts][h]);

                    // Sexo
                    dec = alea_num(1, 2);
                    switch (dec)
                    {
                    case 1:
                        nino.sexo[counts][h] = 'm';
                        break;
                    case 2:
                        nino.sexo[counts][h] = 'f';
                        break;
                    }
                    printf("\n\t\t\tCual es su genero? (m/f): %c\n", nino.sexo[counts][h]);
                }
                // Introducción Automática de datos Infante ----End----

                // Introducción Automática de datos Apartamento ----Start----
                habitabilidad.ocupado[counts] = alea_num(1, 2);
                switch (habitabilidad.ocupado[counts])
                {
                case 1:
                    printf("\n\n\tEl apartamento esta ocupado.");
                    break;
                case 2:
                    printf("\n\tEl apartamento esta desocupado.");
                }

                habitabilidad.estado[counts] = alea_num(1, 3);
                printf("\n\tEl apartamento es: ");
                switch (habitabilidad.estado[counts])
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
                // Encuesta Pareja ===END===
                // system("sleep 0.3s");
                system("clear||cls"); // Limpia pantalla
                torres[u][i][o] = counts++;
            }
        }
    }
}

void v_completa()
{
    int t, p, a, index;
    printf("Introduzca la inforamcion del apatarmento que desea buscar: \n");

    do
    {
        printf("Torre: ");
        scanf(" %d", &t);

        if (t < 1 || t > 2)
        {

            printf("\nEl número de torre es invalido, solo hay 2 torres.");
            printf("\nPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (t < 1 || t > 2);

    do
    {
        printf("Piso: ");
        scanf("%d", &p);

        if (p > 10)
        {

            printf("\nEl número de piso es invalido, solo hay 10 pisos.");
            printf("\nPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (p > 10);

    do
    {
        printf("Apartamento: ");
        scanf("%d", &a);

        if (a > 6)
        {
            printf("\nEl número de apartamento es invalido, solo hay 6 apartamentos.");
            printf("\nPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (a > 6);

    // La pocisión de indice para los arrays que contiene los datos.
    system("clear||cls");
    printf("La inforamcion solicitada es la siguiente: \n\n");
    printf("\tEl apartamento #%d, del piso: %d, de la torre: %d\n", a, p, t);

    index = t * p * a;
    switch (habitabilidad.ocupado[index])
    {
    case 1: // Ocupado
        printf("\n\t\tEsta ocupado y es ");

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

        printf("\n\tJefe de familia: \n");
        printf("\t\tCedula: V-%.0f", jefe.cedula[index]);
        printf("\tEdad: %d", jefe.edad[index]);
        printf("\tSexo: %c", jefe.sexo[index]);

        switch (nino.cantidad[index])
        {
        case 0:
            printf("\n\tEste apartamento no tiene niños.");
            printf("\n\nPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;                     // option TWO to clean stdin
            getchar();
            break;
        default:
            printf("\n\n\tInfantes: %d\n", nino.cantidad[index]);
            for (int h = 0; h < nino.cantidad[index]; h++)
            {
                printf("\n\t\tInfante #%d", h + 1);
                printf("\n\t\tEdad: %d, ", nino.edad[index][h]);
                printf("Sexo: %c", nino.sexo[index][h]);
            }
            printf("\n\nPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;                     // option TWO to clean stdin
            getchar();
            break;
        }
        break;

    case 2: // Desocupado
        printf("\n\t\tEsta desocupado y es ");

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

        printf("\n\tJefe de familia: \n");
        printf("\t\tCedula: V-%.0f", jefe.cedula[index]);
        printf("\tEdad: %d", jefe.edad[index]);
        printf("\tSexo: %c", jefe.sexo[index]);

        switch (nino.cantidad[index])
        {
        case 0:
            printf("\n\tEste apartamento no tiene niños.");
            printf("\n\nPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;                     // option TWO to clean stdin
            getchar();
            break;
        default:
            printf("\n\n\tInfantes: %d\n", nino.cantidad[index]);
            for (int h = 0; h < nino.cantidad[index]; h++)
            {
                printf("\n\t\tInfante #%d", h + 1);
                printf("\n\t\tEdad: %d, ", nino.edad[index][h]);
                printf("Sexo: %c", nino.sexo[index][h]);
            }
            printf("\n\nPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;                     // option TWO to clean stdin
            getchar();
            break;
        }
        break; // Desocupado
    }
}

void buscar_jefe()
{
    int i = 0;
    system("clear||cls");
    float buscar;
    printf("Buscar por la cedula del Jefe de familia");
    printf("\nIntroduzca la cedula que quiere buscar: V-");
    scanf("%f", &buscar);

    while (jefe.cedula[i] != buscar)
    {
        if (jefe.cedula[i] == buscar)
        {
            break;
        }
        else if (i > 120)
        {
            printf("\n\tLa cedula es invalidad");
            printf("\n\tPresione ENTER para continuar");
            while (getchar() != '\n') // limpiar stdin
                ;                     // option TWO to clean stdin
            getchar();
            buscar_jefe();
        }
        i++;
    }

    for (int q = 0; q < 2; q++)
    {
        for (int w = 0; w < 10; w++)
        {
            for (int r = 0; r < 6; r++)
            {
                if (torres[q][w][r] == i)
                {
                    switch (habitabilidad.ocupado[i])
                    {
                    case 1: // Ocupado
                        printf("\n\t\tEsta ocupado y es ");

                        switch (habitabilidad.estado[i])
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

                        printf("\n\tJefe de familia: \n");
                        printf("\t\tCedula: V-%.0f", jefe.cedula[i]);
                        printf("\tEdad: %d", jefe.edad[i]);
                        printf("\tSexo: %c", jefe.sexo[i]);

                        switch (nino.cantidad[i])
                        {
                        case 0:
                            printf("\n\tEste apartamento no tiene niños.");
                            printf("\n\nPresiona ENTER para continuar.");
                            while (getchar() != '\n') // limpiar stdin
                                ;                     // option TWO to clean stdin
                            getchar();
                            break;
                        default:
                            printf("\n\n\tInfantes: %d\n", nino.cantidad[i]);
                            for (int h = 0; h < nino.cantidad[i]; h++)
                            {
                                printf("\n\t\tInfante #%d", h + 1);
                                printf("\n\t\tEdad: %d, ", nino.edad[i][h]);
                                printf("Sexo: %c", nino.sexo[i][h]);
                            }
                            printf("\n\nPresiona ENTER para continuar.");
                            while (getchar() != '\n') // limpiar stdin
                                ;                     // option TWO to clean stdin
                            getchar();
                            break;
                        }
                        break;

                    case 2: // Desocupado
                        printf("\n\t\tEsta desocupado y es ");

                        switch (habitabilidad.estado[i])
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

                        printf("\n\tJefe de familia: \n");
                        printf("\t\tCedula: V-%.0f", jefe.cedula[i]);
                        printf("\tEdad: %d", jefe.edad[i]);
                        printf("\tSexo: %c", jefe.sexo[i]);

                        switch (nino.cantidad[i])
                        {
                        case 0:
                            printf("\n\tEste apartamento no tiene niños.");
                            printf("\n\nPresiona ENTER para continuar.");
                            while (getchar() != '\n') // limpiar stdin
                                ;                     // option TWO to clean stdin
                            getchar();
                            break;
                        default:
                            printf("\n\n\tInfantes: %d\n", nino.cantidad[i]);
                            for (int h = 0; h < nino.cantidad[i]; h++)
                            {
                                printf("\n\t\tInfante #%d", h + 1);
                                printf("\n\t\tEdad: %d, ", nino.edad[i][h]);
                                printf("Sexo: %c", nino.sexo[i][h]);
                            }
                            printf("\n\nPresiona ENTER para continuar.");
                            while (getchar() != '\n') // limpiar stdin
                                ;                     // option TWO to clean stdin
                            getchar();
                            break;
                        }
                        break; // Desocupado
                    }
                    reportes();
                }
            }
        }
    }
}

void rl_porcentaje()
{
    int m = 0, f = 0;
    float mp = 0, fp = 0;
    for (int i = 0; i < 120; i++)
    {

        if (jefe.sexo[i] == 'm')
        {
            m++;
        }
        else if (jefe.sexo[i] == 'f')
        {
            f++;
        }
        system("clear||cls");
        printf("Hay %d personas Masculinos y %d personas Femeninas\n", m, f);
        printf("\tLa relacion porcentual es: \n");
        mp = (float)m / 120 * 100;
        printf("\t%.2f% Hombres.", mp);
        fp = (float)f / 120 * 100;
        printf("\t%.2f% Mujeres.\n", fp);
    }

    printf("\n\tPresione ENTER para continuar");
    while (getchar() != '\n') // limpiar stdin
        ;                     // option TWO to clean stdin
    getchar();
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
        printf("\n\t\tTorre (1 o 2): ");
        scanf("%d", &torre);

        if (torre < 1 || torre > 2)
        {

            printf("\n\t\tEl número de torre es invalido, solo hay 2 torres.");
            printf("\n\tPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (torre < 1 || torre > 2);

    do
    {
        printf("\n\t\tPiso (1 al 10): ");
        scanf("%d", &piso);

        if (piso > 10)
        {

            printf("\n\t\tEl número de piso es invalido, solo hay 10 pisos.");
            printf("\n\tPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (piso > 10);

    index = torre * piso * 6;
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
    getchar();
}

void valor_modal()
{
}

void estadistica()
{
}
int digits(float value)
{
    return (log10(value) + 1);
}
float alea_num(float min, float max)
{
    return min + rand() / (RAND_MAX / (max - min + 1));
}
