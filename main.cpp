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
int torres[2][10][6] = {};                        // Array Inicializado. (Simular torre).
const int size_tt = sizeof(torres) / sizeof(int); // Logintud del array guardado en una variable constante.

struct Jefe // Se crea la estructura del jefe.
{
    float cedula[size_tt];
    int edad[size_tt];
    char sexo[size_tt], pareja[size_tt];
};

struct Nino // Se crea la estructura de los niños.
{
    int edad[size_tt][5];
    char sexo[size_tt][5];
    int cantidad[size_tt];
};

struct Habitabilidad // Se crea la estructura de la habitabilidad de los apartamentos.
{
    int ocupado[size_tt];
    int estado[size_tt][1];
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
    int menu;
    do
    {
        do
        {
            system("clear||cls"); // Limpia pantalla
            printf("Administraci%cn del Conjunto Residencial: \n", o);
            printf("\t1- Realizar encuestas.\n");
            printf("\t2- Reportes\n");
            printf("\t3- Salir.\n");

            printf("\tSeleccione una opci%cn: ", o);
            scanf("%d", &menu);         // Aceptamos una entrada del usuario.
        } while (menu < 1 && menu > 3); // Se valida el menu para que el usuario no introduzca una opción diferente a la que queremos.

        switch (menu)
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
    } while (menu != 3);
}

void reportes()
{
    int menu;
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
            scanf("%d", &menu);
        } while (menu < 1 && menu > 8);

        switch (menu)
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

    int dec, counts = 0, count;
    char otro;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int z = 0; z < 6; z++)
            {
                system("clear||cls"); // Limpia pantalla
                printf("Censo Residencial\n\n");

                printf("Informaci%cn de la Torre %d, Piso: %d, Apartamento: %d\n", o, i + 1, j + 1, z + 1);

                // Encuesta Cedula ===START===
                printf("\n\tDatos del jefe de familia: \n");

                printf("\t\tCédula: V-");
                scanf("%f", &jefe.cedula[counts]);
                do // Validar datos cuando el usuario lo ingresa.
                {
                    count = digits(jefe.cedula[counts]);
                    if (count < 7 || count > 7)
                    {
                        printf("\tFormato de la cédula incorrecta, por favor intente de nuevo: ");
                        printf("Presiona ENTER para continuar.");
                        while (getchar() != '\n') // limpiar stdin
                            ;
                        getchar();
                    }
                } while (count != 7);
                // Encuesta Cedula ===END===

                // Encuesta Edad ===START===
                printf("\t\tEdad: ");
                scanf("%d", &jefe.edad[counts]);
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

                printf("\n\tDatos del apartamento: \n");
                do
                {
                    printf("\t\tEl apartamento es: ");
                    printf("\n\t\t\t1. Alquilado.");
                    printf("\n\t\t\t2. Propio.");
                    printf("\n\t\t\t3. Familiar o Tercero.");
                    scanf("%d", &habitabilidad.estado[counts][1]);

                    if (habitabilidad.estado[counts][1] > 3)
                    {
                        printf("\tDebe de introducir un valor v&clido 1, 2 o 3.", a);
                        printf("Presiona ENTER para continuar.");
                        while (getchar() != '\n') // limpiar stdin
                            ;
                        getchar();
                    }
                } while (habitabilidad.estado[counts][1] > 1 && habitabilidad.estado[counts][1] < 3);

                do
                {
                    printf("El apartamento esta: ");
                    printf("\n\t\t1. Ocupado.");
                    printf("\n\t\t2. Desocupado.");
                    scanf("%d", &habitabilidad.ocupado[counts]);

                    if (habitabilidad.estado[counts][1] > 3)
                    {
                        printf("\tDebe de introducir un valor v&clido 1 o 2.", a);
                        printf("Presiona ENTER para continuar.");
                        while (getchar() != '\n') // limpiar stdin
                            ;
                        getchar();
                    }
                } while (habitabilidad.ocupado[counts] > 1 && habitabilidad.ocupado[counts] < 2);
                
                //idea de salir del bucle.

                // printf("\n%cDesea introducir otro registro? (s/n): ", inte);
                // scanf(" %c", &otro);
                // if (otro == 'n')
                // {
                //     break;
                // }

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

        if (t > 2)
        {

            printf("El número de torre es inv%clido, solo hay 2 torres.", a);
            printf("Presiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (t > 2);

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

    index = t * p * ap; // La pocisión de indice para los arrays que contiene los datos.
    system("clear||cls");
    printf("La inforamción solicitada es la siguiente: \n\n");

    printf("\tEl apartamento #: %d, del piso: %d, de la torre: %d\n", ap, p, t);

    if (habitabilidad.ocupado[index] == 0)
    {
        printf("\t\tEstá desocupado");
        printf("\n\tPresione ENTER para continuar");

        while (getchar() != '\n') // limpiar stdin
            ;                     // option TWO to clean stdin
        getchar();
    }
    else
    {
        printf("\tEst%c ocupado y es ", a);

        if (habitabilidad.estado[index][1] == 1)
        {
            printf("alquilado.\n");
        }
        else if (habitabilidad.estado[index][1] == 2)
        {
            printf("propio.\n");
        }
        else if (habitabilidad.estado[index][1] == 3)
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
            for (size_t i = 0; i < nino.cantidad[index]; i++)
            {
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