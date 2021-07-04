#include <stdlib.h>
#include <stdio.h>
#include <math.h> // Libreria que trae las funciones matemáticas, log10.
#include <time.h> // Librería que trae las funciones srand, time y rand para generar valores aleatorios
#include <locale.h>

#define TRUE 1
#define FALSE 0

// Vocales con acentos
char a = 160;
char e = 130;
char i = 161;
char o = 162;
char u = 163;
char elle = 164; // Imprime la ñ.
char inte = 424; // Aunque cree overflow, mostrará el simbolo ?.

//Variables Globales

int torres[2][10][6] = {};                              // Array Inicializado. (Simular torre).
const int size_tt = (sizeof(torres) / sizeof(int)) + 1; // Logintud del array guardado en una variable constante.

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
void casos();
void valor_modal();
void estadistica();
int digits(float value);
float alea_num(float min, float max);

int main()
{
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
            printf("Administraci%cn del Conjunto Residencial: \n", o);
            printf("\t1- Realizar encuestas.\n");
            printf("\t2- Reportes.\n");
            printf("\t3- Salir.\n");

            printf("\tSeleccione una opci%cn: ", o);
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
            printf("\t1- Visualizar informaci%cn completa de un apartamento.\n", o);
            printf("\t2- Buscar informaci%cn del jefe de familia.\n", o);
            printf("\t3- Relaci%cn porcentual de genero.\n", o);
            printf("\t4- Casos especiales.\n");
            printf("\t5- Valor modal.\n");
            printf("\t6- Estad%cstica de habitabilidad.\n", i);
            printf("\t7- Men%c anterior.\n", u);
            printf("\t8- Salir.\n");

            printf("Seleccione una opci%cn: ", o);
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
            casos();
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

int digits(float value)
{
    return (log10(value) + 1);
}
float alea_num(float min, float max)
{
    return min + rand() / (RAND_MAX / (max - min + 1));
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

                printf("Informaci%cn de la Torre %d, Piso: %d, Apartamento: %d\n", o, i, j, z);

                // Encuesta Cedula ===START===
                printf("\n\tDatos del jefe de familia: \n");

                printf("\t\tC%cdula: V-", e);
                scanf("%f", &jefe.cedula[counts]);
                do // Validar datos cuando el usuario lo ingresa.
                {
                    count = digits(jefe.cedula[counts]);
                    if (count < 7 || count > 7)
                    {
                        printf("\tFormato de la c%cdula incorrecta, por favor intente de nuevo.", e);
                        printf("\nPresiona ENTER para continuar.");
                        while (getchar() != '\n') // limpiar stdin
                            ;
                        getchar();
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
                        getchar();
                    }

                } while (jefe.edad[counts] < 18);
                // Encuesta Edad ===END===

                // Encuesta Pareja ===START===

                do
                {
                    printf("\t\t%cTiene pareja (s/n)? ", inte);
                    scanf(" %c", &jefe.pareja[counts]);
                    if (jefe.pareja[counts] != 's' && jefe.pareja[counts] != 'n')
                    {
                        printf("\tDebe de introducir (s/n).");
                        printf("Presiona ENTER para continuar.");
                        while (getchar() != '\n') // limpiar stdin
                            ;
                        getchar();
                    }
                } while (jefe.pareja[counts] != 's' && jefe.pareja[counts] != 'n');

                // Encuesta Pareja ===END===

                // Encuesta Genero ===START===
                do
                {
                    printf("\t\t%cCu%cl es su genero? (m/f): ", inte, a);
                    scanf(" %c", &jefe.sexo[counts]);
                    if (jefe.sexo[counts] != 'm' && jefe.sexo[counts] != 'f')
                    {
                        printf("\tDebe de introducir (m/f).");
                        printf("Presiona ENTER para continuar.");
                        while (getchar() != '\n') // limpiar stdin
                            ;
                        getchar();
                    }
                } while (jefe.sexo[counts] != 'm' && jefe.sexo[counts] != 'f');

                // Niños en el apartamento
                printf("\n\tDatos de los niños: \n");

                printf("\t\t%cCu%cntos niños hay en el apartamento: ", inte, a);
                scanf("%d", &nino.cantidad[counts]);

                for (int h = 0; h < nino.cantidad[counts]; h++)
                {
                    printf("\t\tInformaci%cn del niño #%d: \n", o, h + 1);
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
                            getchar();
                        }

                    } while (nino.edad[counts][h] > 17);
                    // Encuesta Edad ===END===

                    // Encuesta Sexo ===START===
                    do
                    {
                        printf("\t\t%cCu%cl es su genero? (m/f): ", inte, a);
                        scanf(" %c", &nino.sexo[counts][h]);
                        if (nino.sexo[counts][h] != 'm' && nino.sexo[counts][h] != 'f')
                        {
                            printf("\tDebe de introducir (m/f).");
                            printf("Presiona ENTER para continuar.");
                            while (getchar() != '\n') // limpiar stdin
                                ;
                            getchar();
                        }
                    } while (nino.sexo[counts][h] != 'm' && nino.sexo[counts][h] != 'f');
                    // Encuesta Edad ===END===
                    printf("\n");
                }

                // Estado el apartamento
                fflush(stdin);
                printf("\n\tDatos del apartamento: \n");
                do
                {
                    printf("\t\tEl apartamento es: ");
                    printf("\n\t\t\t1. Alquilado.");
                    printf("\n\t\t\t2. Propio.");
                    printf("\n\t\t\t3. Familiar o Tercero.");
                    printf("\n\t\t\tOpci%cn: ", o);
                    scanf("%d", &habitabilidad.estado[counts]);

                    if (habitabilidad.estado[counts] > 3)
                    {
                        printf("\tDebe de introducir un valor v&clido 1, 2 o 3.", a);
                        printf("Presiona ENTER para continuar.");
                        while (getchar() != '\n') // limpiar stdin
                            ;
                        getchar();
                    }
                } while (habitabilidad.estado[counts] < 1 || habitabilidad.estado[counts] > 3);

                do
                {
                    printf("\t\tEl apartamento esta: ");
                    printf("\n\t\t\t1. Ocupado.");
                    printf("\n\t\t\t2. Desocupado.");
                    printf("\n\t\t\tOpci%cn: ", o);
                    scanf("%d", &habitabilidad.ocupado[counts]);
                    printf("counts %d, %d", counts, habitabilidad.ocupado[counts]);

                    if (habitabilidad.ocupado[counts] > 2)
                    {
                        printf("\tDebe de introducir un valor v&clido 1 o 2.", a);
                        printf("Presiona ENTER para continuar.");
                        while (getchar() != '\n') // limpiar stdin
                            ;
                        getchar();
                    }
                } while (habitabilidad.ocupado[counts] > 1 && habitabilidad.ocupado[counts] < 2);

                //idea de salir del bucle.

                printf("\n%cDesea introducir otro registro? (s/n): ", inte);
                scanf(" %c", &otro);
                if (otro == 'n')
                {
                    i = j = 1000;
                    break;
                }

                counts++;
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
    printf("Introduzca la inforamci%cn del apatarmento que desea buscar: \n", o);

    do
    {
        printf("Torre: ");
        scanf("%d", &t);

        if (t < 1 || t > 2)
        {

            printf("El número de torre es inv%clido, solo hay 2 torres.", a);
            printf("Presiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (t > 1 && t < 2);

    do
    {
        printf("Piso: ");
        scanf("%d", &p);

        if (p > 10)
        {

            printf("El número de piso es inv%clido, solo hay 10 pisos.", a);
            printf("Presiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (t > 10);

    do
    {
        printf("Apartamento: ");
        scanf("%d", &ap);

        if (ap > 6)
        {

            printf("El número de apartamento es inv%clido, solo hay 6 apartamentos.", a);
            printf("Presiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (ap > 6);

    // La pocisión de indice para los arrays que contiene los datos.
    system("clear||cls");
    printf("La inforamci%cn solicitada es la siguiente: \n\n", o);

    printf("\tEl apartamento #%d, del piso: %d, de la torre: %d\n", ap, p, t);
    index = t * p * ap;
    if (habitabilidad.ocupado[index] == 0)
    {
        printf("\t\tEst%c desocupado", a);
        printf("\n\tPresione ENTER para continuar");

        while (getchar() != '\n') // limpiar stdin
            ;                     // option TWO to clean stdin
        getchar();
    }
    else
    {
        printf("\tEst%c ocupado y es ", a);

        if (habitabilidad.estado[index] == 1)
        {
            printf("alquilado.\n");
        }
        else if (habitabilidad.estado[index] == 2)
        {
            printf("propio.\n");
        }
        else if (habitabilidad.estado[index] == 3)
        {
            printf("de un familiar o tercero.\n");
        }

        printf("\n\tJefe de familia: \n");
        printf("\t\tC%cdula: V-%.0f", e, jefe.cedula[index]);
        printf("\t\tEdad: %d", jefe.edad[index]);
        printf("\t\tSexo: %c\n\n", jefe.sexo[index]);

        if (nino.cantidad[index] == 0)
        {
            printf("\tEste apartamento no tiene niños.");
        }
        else
        {
            printf("\tInfantes: %d\n", nino.cantidad[index]);
            for (int i = 0; i < nino.cantidad[index]; i++)
            {
                printf("\t\tInfante #%d", i + 1);
                printf("\t\tEdad: %d, Sexo: %c", nino.edad[index][i], nino.sexo[index][i]);
            }
        }
        while (getchar() != '\n') // limpiar stdin
            ;                     // option TWO to clean stdin
        getchar();
    }
}

void buscar_jefe()
{
    system("clear||cls");
    int buscar;
    printf("Buscar por la c%cdula del Jefe de familia", e);

    printf("\nIntroduzca la c%cdula que quiere buscar: ", e);
    scanf("%d", &buscar);

    for (int i = 1; i <= size_tt; i++)
    {
        if (buscar == jefe.cedula[i])
        {
            for (int q = 1; q <= 2; q++)
            {
                for (int w = 1; w <= 10; w++)
                {
                    for (int r = 1; e <= 6; e++)
                    {
                        if (torres[q][w][r] == i)
                        {
                            printf("\tEl apartamento #%d, del piso: %d, de la torre: %d\n", w, r, q);

                            if (habitabilidad.ocupado[i] == 0)
                            {
                                printf("\t\tEst%c desocupado", a);
                                printf("\n\tPresione ENTER para continuar");

                                while (getchar() != '\n') // limpiar stdin
                                    ;                     // option TWO to clean stdin
                                getchar();
                            }
                            else
                            {
                                printf("\tEst%c ocupado y es ", a);

                                if (habitabilidad.estado[i] == 1)
                                {
                                    printf("alquilado.\n");
                                }
                                else if (habitabilidad.estado[i] == 2)
                                {
                                    printf("propio.\n");
                                }
                                else if (habitabilidad.estado[i] == 3)
                                {
                                    printf("de un familiar o tercero.\n");
                                }

                                printf("\n\tJefe de familia: \n");
                                printf("\t\tC%cdula: V-%.0f", e, jefe.cedula[i]);
                                printf("\t\tEdad: %d", jefe.edad[i]);
                                printf("\t\tSexo: %c\n\n", jefe.sexo[i]);

                                if (nino.cantidad[i] == 0)
                                {
                                    printf("\tEste apartamento no tiene niños.");
                                }
                                else
                                {
                                    printf("\tInfantes: %d\n", nino.cantidad[i]);
                                    for (int t = 0; t < nino.cantidad[i]; t++)
                                    {
                                        printf("\t\tInfante #%d", i);
                                        printf("\t\tEdad: %d, Sexo: %c\n", nino.edad[i][t], nino.sexo[i][t]);
                                    }
                                }

                                while (getchar() != '\n') // limpiar stdin
                                    ;                     // option TWO to clean stdin
                                getchar();
                                break;
                            }
                        }
                    }
                }
            }
        }
        else
        {
            printf("La c%cdula introducida no existe.", e);
            while (getchar() != '\n') // limpiar stdin
                ;                     // option TWO to clean stdin
            getchar();
            break;
        }
    }
}

void rl_porcentaje()
{
}

void casos()
{
}

void valor_modal()
{
}

void estadistica()
{
}