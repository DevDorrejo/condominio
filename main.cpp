#include <stdlib.h>
#include <stdio.h>
#include <math.h> // Libreria que trae las funciones matemáticas, log10.
#include <time.h> // Librería que trae las funciones srand, time y rand para generar valores aleatorios
#include <locale.h>

#define TRUE 1
#define FALSE 0

//Variables Globales

int torres[2][10][6] = {};                              // Array Inicializado. (Simular torre).
const int size_tt = (sizeof(torres) / sizeof(int) + 1); // Logintud del array guardado en una variable constante.

struct Jefe // Se crea la estructura del jefe.
{
    float cedula[size_tt];
    int edad[size_tt];
    char sexo[size_tt], pareja[size_tt];
};

struct Nino // Se crea la estructura de los niños.
{
    int edad[size_tt][5], cantidad[size_tt];
    char sexo[size_tt][5];
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

    int dec, counts = 1, count;
    char otro;

    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            for (int z = 1; z <= 6; z++)
            {
                torres[i][j][z] = counts;
                system("clear||cls"); // Limpia pantalla
                printf("Censo Residencial\n\n");

                printf("Informacion de la Torre %d, Piso: %d, Apartamento: %d\n", i, j, z);

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
                    printf("\n\t\tInformacion del niño #%d: \n", h);

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
                // system("sleep 0.4s");
                // Introducción Automática de datos Apartamento ----End----

                // // Introducción Manual de datos ----Start----
                // // Encuesta Cedula ===START===

                // do // Validar datos cuando el usuario lo ingresa.
                // {
                //     printf("\t\tCedula: V-");
                //     scanf("%f", &jefe.cedula[counts]);

                //     count = digits(jefe.cedula[counts]);
                //     if (count < 7 || count > 7)
                //     {
                //         printf("\tFormato de la cedula incorrecta, por favor intente de nuevo.");
                //         printf("\n\tPresiona ENTER para continuar.");
                //         while (getchar() != '\n') // limpiar stdin
                //             ;
                //         getchar();
                //     }
                // } while (count != 7);
                // // Encuesta Cedula ===END===

                // // Encuesta Edad ===START===
                // do
                // {
                //     printf("\t\tEdad: ");
                //     scanf("%d", &jefe.edad[counts]);

                //     if (jefe.edad[counts] < 18)
                //     {
                //         printf("\nLa edad de la persona es menor de edad.");
                //         printf("\nPresiona ENTER para continuar.");
                //         while (getchar() != '\n') // limpiar stdin
                //             ;
                //         getchar();
                //     }
                // } while (jefe.edad[counts] < 18);
                // // Encuesta Edad ===END===

                // // Encuesta Pareja ===START===
                // do
                // {
                //     printf("\t\tTiene pareja (s/n)? ");
                //     scanf(" %c", &jefe.pareja[counts]);
                //     if (jefe.pareja[counts] != 's' && jefe.pareja[counts] != 'n')
                //     {
                //         printf("\tDebe de introducir (s/n).");
                //         printf("Presiona ENTER para continuar.");
                //         while (getchar() != '\n') // limpiar stdin
                //             ;
                //         getchar();
                //     }
                // } while (jefe.pareja[counts] != 's' && jefe.pareja[counts] != 'n');
                // // Encuesta Pareja ===END===

                // // Encuesta Genero ===START===
                // do
                // {
                //     printf("\t\tCual es su genero? (m/f): ");
                //     scanf(" %c", &jefe.sexo[counts]);
                //     if (jefe.sexo[counts] != 'm' && jefe.sexo[counts] != 'f')
                //     {
                //         printf("\tDebe de introducir (m/f).");
                //         printf("Presiona ENTER para continuar.");
                //         while (getchar() != '\n') // limpiar stdin
                //             ;
                //         getchar();
                //     }
                // } while (jefe.sexo[counts] != 'm' && jefe.sexo[counts] != 'f');
                // // Encuesta Genero ===END===

                // // Niños en el apartamento
                // printf("\n\tDatos de los niños: \n");

                // printf("\t\tCuantos niños hay en el apartamento: ");
                // scanf("%d", &nino.cantidad[counts]);

                // for (int h = 1; h <= nino.cantidad[counts]; h++)
                // {
                //     printf("\t\tInformacion del niño #%d: \n", h);

                //     // Encuesta Edad ===START===
                //     do
                //     {
                //         printf("\t\tEdad: ");
                //         scanf("%d", &nino.edad[counts][h]);

                //         if (nino.edad[counts][h] > 17)
                //         {
                //             printf("\nLa edad de la persona es mayor de edad.");
                //             printf("\nPresiona ENTER para continuar.");
                //             while (getchar() != '\n') // limpiar stdin
                //                 ;
                //             getchar();
                //         }

                //     } while (nino.edad[counts][h] > 17);
                //     // Encuesta Edad ===END===

                //     // Encuesta Sexo ===START===
                //     do
                //     {
                //         printf("\t\tCual es su genero? (m/f): ");
                //         scanf(" %c", &nino.sexo[counts][h]);
                //         if (nino.sexo[counts][h] != 'm' && nino.sexo[counts][h] != 'f')
                //         {
                //             printf("\tDebe de introducir (m/f).");
                //             printf("Presiona ENTER para continuar.");
                //             while (getchar() != '\n') // limpiar stdin
                //                 ;
                //             getchar();
                //         }
                //     } while (nino.sexo[counts][h] != 'm' && nino.sexo[counts][h] != 'f');
                //     // Encuesta Edad ===END===
                //     printf("\n");
                // }

                // // Apartamento situación (Alquilado, Propio, Familiar o Tercero) ====START====
                // printf("\n\tDatos del apartamento: \n");
                // do
                // {
                //     printf("\t\tEl apartamento es: ");
                //     printf("\n\t\t\t1. Alquilado.");
                //     printf("\n\t\t\t2. Propio.");
                //     printf("\n\t\t\t3. Familiar o Tercero.");
                //     printf("\n\t\t\tOpcion: ");
                //     scanf("%d", &habitabilidad.estado[counts]);

                //     if (habitabilidad.estado[counts] > 3)
                //     {
                //         printf("\tDebe de introducir un valor valido 1, 2 o 3.");
                //         printf("Presiona ENTER para continuar.");
                //         while (getchar() != '\n') // limpiar stdin
                //             ;
                //         getchar();
                //     }
                // } while (habitabilidad.estado[counts] < 1 || habitabilidad.estado[counts] > 3);
                // // Apartamento situación (Alquilado, Propio, Familiar o Tercero) ====END====

                // // Apartamento estados (Ocupado o Desocupado) ====START====
                // do
                // {
                //     printf("\t\tEl apartamento esta: ");
                //     printf("\n\t\t\t1. Ocupado.");
                //     printf("\n\t\t\t2. Desocupado.");
                //     printf("\n\t\t\tOpcion: ");
                //     scanf("%d", &habitabilidad.ocupado[counts]);

                //     if (habitabilidad.ocupado[counts] > 2)
                //     {
                //         printf("\tDebe de introducir un valor valido 1 o 2.");
                //         printf("Presiona ENTER para continuar.");
                //         while (getchar() != '\n') // limpiar stdin
                //             ;
                //         getchar();
                //     }
                // } while (habitabilidad.ocupado[counts] > 1 && habitabilidad.ocupado[counts] < 2);
                // // Apartamento estados (Ocupado o Desocupado) ====END====

                // // idea de salir del bucle.

                // printf("\nedesea introducir otro registro? (s/n): ");
                // scanf(" %c", &otro);
                // if (otro == 'n')
                // {
                //     i = j = 1000;
                //     break;
                // }
                // // Introducción Manual de datos ----END----

                system("clear||cls"); // Limpia pantalla
                // Encuesta Pareja ===END===
                counts++;
            }
        }
    }
}

void v_completa()
{
    int t, p, ap, index;
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
        scanf("%d", &ap);

        if (ap > 6)
        {
            printf("\nEl número de apartamento es invalido, solo hay 6 apartamentos.");
            printf("\nPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (ap > 6);

    // La pocisión de indice para los arrays que contiene los datos.
    system("clear||cls");
    printf("La inforamcion solicitada es la siguiente: \n\n");
    printf("\tEl apartamento #%d, del piso: %d, de la torre: %d\n", ap, p, t);

    index = t * p * ap;
    switch (habitabilidad.ocupado[index])
    {
    case 1:
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

        printf("\n\nPresiona ENTER para continuar.");
        while (getchar() != '\n') // limpiar stdin
            ;                     // option TWO to clean stdin
        getchar();
        break;
    case 2:
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
                printf("\n\t\tEdad: %d, Sexo: %c", nino.edad[index][h], nino.sexo[index][h]);
            }
            printf("\n\nPresiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;                     // option TWO to clean stdin
            getchar();
            break;
        }
    }
}

void buscar_jefe()
{
    int i = 1;
    system("clear||cls");
    float buscar;
    printf("Buscar por la cedula del Jefe de familia");
    printf("\nIntroduzca la cedula que quiere buscar: V-");
    scanf("%f", &buscar);

    do
    {
        if (jefe.cedula[i] != buscar)
        {

            printf("%d = %.0f\n", jefe.cedula[i], buscar);
            ++i;
            if (i == 121)
            {
                printf("%d = %.0f\n", jefe.cedula[i], buscar);

                printf("La cedula introducida no existe.");
                printf("\n\tPresione ENTER para continuar");
                while (getchar() != '\n') // limpiar stdin
                    ;                     // option TWO to clean stdin
                getchar();
                reportes();
            }
        }
        else
        {
            break;
        }
    } while (1);

    for (int q = 1; q <= 2; q++)
    {
        for (int w = 1; w <= 10; w++)
        {
            for (int r = 1; r <= 6; r++)
            {
                if (torres[q][w][r] == i)
                {
                    if (habitabilidad.ocupado[i] == 1) // Ocupado
                    {
                        printf("\tEl apartamento #%d, del piso: %d, de la torre: %d\n", w, r, q);
                        printf("\tEsta ocupado y es ");

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
                        printf("\t\tEdad: %d", jefe.edad[i]);
                        printf("\t\tSexo: %c\n\n", jefe.sexo[i]);

                        if (nino.cantidad[i] == 0) // No hay niños.
                        {
                            printf("\tEl jefe no tiene infantes.\n\n");

                            printf("\n\tPresione ENTER para continuar");
                            while (getchar() != '\n') // limpiar stdin
                                ;                     // option TWO to clean stdin
                            getchar();
                        }
                        else
                        {
                            printf("\tEl jefe tiene %d infantes\n", nino.cantidad[i]);
                            for (int t = 0; t < nino.cantidad[i]; t++)
                            {
                                printf("\t\tInfante #%d", i);
                                printf("\t\tEdad: %d, Sexo: %c\n", nino.edad[i][t], nino.sexo[i][t]);
                            }
                            printf("\n\tPresione ENTER para continuar");
                            while (getchar() != '\n') // limpiar stdin
                                ;                     // option TWO to clean stdin
                            getchar();
                        }
                    }

                    else if (habitabilidad.ocupado[i] == 2) // Desocupado
                    {
                        printf("\tEl apartamento #%d, del piso: %d, de la torre: %d\n", w, r, q);
                        printf("\t\tEsta desocupado y es ");

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
                    }
                }
            }
        }
    }
}

void rl_porcentaje()
{
    int mp, m = 0, fp, f = 0;

    for (int i = 1; i <= size_tt; i++)
    {

        if (jefe.sexo[i] == 'm')
        {
            m++;
        }
        else if (jefe.sexo[i] == 'f')
        {
            f++;
        }

        printf("Hay %d persona Masculinos y %d persona Femeninas", m, f);
        printf("La relaci%n porcentual es: \n");
        mp = (m / size_tt) * 100;
        printf("%d Hombres.", mp);
        fp = (f / size_tt) * 100;
        printf("\t%d Mujeres.", fp);
    }
}

void caso_especial()
{
    int torre, piso;
    int edad[size_tt];
    printf("Busqueda de casos especiales.");

    printf("Introduzca torre y piso para iniciar la busqueda de casos especiales.");

    do
    {
        printf("Torre: ");
        scanf("%d", &torre);

        if (torre < 1 || torre > 2)
        {

            printf("El número de torre es invalido, solo hay 2 torres.");
            printf("Presiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (torre > 1 && torre < 2);

    do
    {
        printf("Piso: ");
        scanf("%d", &piso);

        if (piso > 10)
        {

            printf("El número de piso es invalido, solo hay 10 pisos.");
            printf("Presiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (piso > 10);

    for (int q = 1; q <= torre; q++)
    {
        for (int w = 1; w <= piso; w++)
        {
            for (int r = 1; r <= 6; r++)
            {
            }
        }
    }
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
