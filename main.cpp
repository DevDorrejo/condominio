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
int apartamentos[size_tt];                        // Para úbicar el apartamento.

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
};

struct Habitabilidad // Se crea la estructura de la habitabilidad de los apartamentos.
{
    int ocupado[size_tt];
    int estado[size_tt][1];
};

// Inicialización de funciones
void menu();
void censo_jefe();
void ninos_apartamento();
void habitabilidad();

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
    setlocale(LC_ALL, "");
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
            habitabilidad();
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

    struct Jefe jefe;
    int dec, counts = 0;
    printf("Censo Residencial\n\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int z = 0; z < 6; z++)
            {
                system("clear||cls"); // Limpia pantalla
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
    struct Nino nino;
    int dec, counts, cantidad;
    system("clear||cls"); // Limpia pantalla
    printf("\t\nDatos de los niños: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int z = 0; z < 6; z++)
            {
                printf("Informaci%cn de la Torre %d, Piso: %d, Apartamento: %d\n", o, i + 1, j + 1, z + 1);

                cantidad = alea_num(0, 5);
                printf("Cuantos niños hay en el apartamento: %d\n", cantidad);
                // printf("Cuantos niños hay en el apartamento: ");
                // scanf("%d", &cantidad);

                for (int a = 0; a < cantidad; a++)
                {
                    // Encuesta Edad ===START===
                    nino.edad[counts][a] = alea_num(0, 17);
                    printf("\n\tEdad: %d años\n", nino.edad[counts][a]);
                    // printf("\n\tEdad: \n");
                    //scanf("%d", &jefe.edad[counts]);

                    // Encuesta Edad ===END===

                    dec = 0;
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
                    system("sleep 0.5s");
                }
                counts++;
                system("clear||cls"); // Limpia pantalla
            }
            system("clear||cls"); // Limpia pantalla
        }
    }
}

void habitabilidad()
{
    struct Habitabilidad habitabilidad;
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

                system("sleep 0.5s");
                system("clear||cls"); // Limpia pantalla

                counts++;
            }
        }
    }
}

void v_completa()
{
    
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