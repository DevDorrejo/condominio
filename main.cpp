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
void censo_jefe();
void ninos_apartamento();
void habita();

void r_encuestas();
void reportes();
void v_completa();
void buscar_jefe();
void rl_porcentaje();
void casos();
void valor_modal();
void estadistica();
float alea_num(float min, float max);
int digits(float value);

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
            censo_jefe(); // llamamos a la función.
            ninos_apartamento();
            habita();
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

void censo_jefe()
{

    int dec, counts = 0;
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
                printf("\t\nDatos del jefe de familia: \n");
                jefe.cedula[counts] = alea_num(0000000, 9999999);
                printf("\tCédula: V-%.0f\n", jefe.cedula[counts]);

                // printf("\tCédula: V-%.0f");
                // scanf("%f", &jefe.cedula[counts]);
                // do // Validar datos cuando el usuario lo ingresa.
                // {
                //     count = digits(jefe.cedula[counts]);
                //     if (count < 7 || count > 7)
                //     {
                //         printf("\tFormato de la cédula incorrecta, por favor intente de nuevo: ");
                //         scanf("%f", &jefe.cedula[counts]);
                //     }
                // } while (count != 7);
                // Encuesta Cedula ===END===

                // Encuesta Edad ===START===
                jefe.edad[counts] = alea_num(20, 80);
                printf("\tEdad: %d\n", jefe.edad[counts]);
                // printf("\tEdad: ",);
                //scanf("%d", &jefe.edad[counts]);
                // Encuesta Edad ===END===

                // Encuesta Pareja ===START===
                dec = alea_num(0, 1);
                if (dec == 1)
                {
                    jefe.pareja[counts] = 's';
                }
                else if (dec == 0)
                {
                    jefe.pareja[counts] = 'n';
                }
                printf("\t¿Tiene pareja (s/n)? %c\n", jefe.pareja[counts]);

                // printf("\t¿Tiene pareja (s/n)? ");
                // scanf(" %c", &jefe.pareja[counts]);
                // while (jefe.pareja != 's' && jefe.pareja != 'n')
                // {
                //     printf("\tDebe de introducir (s/n): ");
                //     scanf("%c", &jefe.pareja);
                // }
                // Encuesta Pareja ===END===

                // Encuesta Genero ===START===
                dec = 0;
                dec = alea_num(0, 1);
                if (dec == 1)
                {
                    jefe.sexo[counts] = 'm';
                }
                else if (dec == 0)
                {
                    jefe.sexo[counts] = 'f';
                }
                printf("\t¿Cuál es su genero? (m/f): %c\n", jefe.sexo[counts]);

                // printf("\t¿Cuál es su genero? (m/f): \n");
                // scanf(" %c", &jefe.sexo);
                // while (jefe.sexo != 'm' && jefe.sexo != 'f')
                // {
                //     printf("\tDebe de introducir (m/f): ");
                //     scanf("%c", &jefe.sexo);
                // }
                // Encuesta Pareja ===END===
                counts++;
            }
        }
    }
}

void ninos_apartamento()
{
    int dec, counts = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int z = 0; z < 6; z++)
            {
                system("clear||cls"); // Limpia pantalla
                printf("Datos de los niños: \n");
                printf("Informaci%cn de la Torre %d, Piso: %d, Apartamento: %d\n", o, i + 1, j + 1, z + 1);

                nino.cantidad[counts] = alea_num(0, 5);
                printf("Cuantos niños hay en el apartamento: %d\n", nino.cantidad[counts]);
                // printf("Cuantos niños hay en el apartamento: ");
                // scanf("%d", &cantidad);

                for (int a = 0; a < nino.cantidad[counts]; a++)
                {
                    // Encuesta Edad ===START===
                    nino.edad[counts][a] = alea_num(0, 17);
                    printf("\n\tEdad: %d años\n", nino.edad[counts][a]);
                    // printf("\n\tEdad: \n");
                    //scanf("%d", &jefe.edad[counts]);

                    // Encuesta Edad ===END===

                    dec = alea_num(0, 1);
                    if (dec == 1)
                    {
                        nino.sexo[counts][a] = 'm';
                    }
                    else if (dec == 0)
                    {
                        nino.sexo[counts][a] = 'f';
                    }
                    printf("\t¿Cuál es su genero? (m/f): %c\n", nino.sexo[counts][a]);
                }
                counts++;
                system("clear||cls"); // Limpia pantalla
            }
            system("clear||cls"); // Limpia pantalla
        }
    }
}

void habita()
{
    int counts = 0, estado;
    system("clear||cls"); // Limpia pantalla
    printf("Datos de los apartamentos: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int z = 0; z < 6; z++)
            {
                printf("Informaci%cn de la Torre %d, Piso: %d, Apartamento: %d\n", o, i + 1, j + 1, z + 1);

                estado = alea_num(0, 1);
                if (estado == 1)
                {
                    printf("El apartamento esta ocupado.");
                    habitabilidad.ocupado[counts] = 1;
                }
                else
                {
                    printf("El apartamento esta desocupado.");
                    habitabilidad.ocupado[counts] = 0;
                }
                habitabilidad.estado[counts][1] = alea_num(1, 3);
                printf("\nEl apartamento es: ");

                if (habitabilidad.estado[counts][1] == 1)
                {
                    printf("Alquilado.\n");
                }
                else if (habitabilidad.estado[counts][1] == 2)
                {
                    printf("Propio.\n");
                }
                else if (habitabilidad.estado[counts][1] == 3)
                {
                    printf("Familiar o Tercero.\n");
                }

                // printf("El apartamento es: ");
                // scanf("%d", &habitabilidad.estado[counts][1]);
                // printf("1. Alquilado.");
                // printf("2. Propio.");
                // printf("3. Familiar o Tercero.");

                system("clear||cls"); // Limpia pantalla
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

            printf("El número de piso es inv%clido, solo hay 6 pisos.", a);
            printf("Presiona ENTER para continuar.");
            while (getchar() != '\n') // limpiar stdin
                ;
            getchar();
        }
    } while (ap > 6);

    index = t * p * ap; // La pocisión de indice para los arrays que contiene los datos.
    system("clear||cls");

    printf("\nEl apartamento #: %d, del piso: %d, de la torre: %d\n", ap, p, t);

    if (habitabilidad.ocupado[index] == 0)
    {
        printf("Está desocupado");
    }
    else
    {
        printf("Est%c ocupado y es ", a);

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

        printf("La inforamción solicitada es la siguiente: \n");
        printf("\tJefe de familia: \n");
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
                printf("\t\t Infante: %d, Edad: %d, Sexo: %c", elle, nino.edad[index][i], nino.sexo[index][i]);
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