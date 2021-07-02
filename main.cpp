#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int torres[2][10][6] = {}; // Array Inicializado

struct Jefe
{
    float cedula;
    int edad;
    char sexo, pareja;
};

struct Child
{
    int edad;
    char sexo;
};

struct Habitabilidad
{
    bool ocupado;
    char estado[3][10] = {"Alquilado", "Propio", "Tercero"};
};

// Inicialización de funciones
void menu();
void r_encuestas();
void reportes();
void v_completa();
void buscar_jefe();
void relacion_porcentaje();
void casos();
void valor_modal();
void estadistica();
int digitos(float value);

int main(int argc, char const *argv[])
{
    printf("Conversor de divisas.\n\n");
    menu();
    return 0;
}

void menu()
{
    int menu;
    do
    {
        system("clear||cls");
        do
        {
            system("clear||cls");
            printf("Administración del Conjunto Residencial: \n");
            printf("\t1- Realizar encuestas.\n");
            printf("\t2- Reportes\n");
            printf("\t3- Salir.\n");

            printf("\tSeleccione una opción: ");
            scanf("%d", &menu);
        } while (menu < 1 && menu > 3);

        switch (menu)
        {
        case 1:
            system("clear||cls");
            r_encuestas();
            break;

        case 2:
            reportes();
            break;
        default:
            break;
        }
    } while (menu != 3);
}

void r_encuestas()
{
    int count;
    printf("Censo Residencial\n\n");

    struct Child child;
    struct Jefe jefe;
    struct Habitabilidad habitabilidad;

    FILE *archivo = fopen("Conjunto_Residencial.dat", "wb");

    if (archivo != NULL)
    {
        fflush(stdin);

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                system("clear||cls");
                for (int z = 0; z < 6; z++)
                {
                    printf("Introducir información de la Torre %d, Piso: %d, Apartamento: %d\n", i + 1, j + 1, z + 1);

                    printf("\t\nDatos del jefe de familia: \n");
                    printf("\tCédula: V-");
                    scanf("%f", &jefe.cedula);
                    do
                    {
                        count = digitos(jefe.cedula);
                        if (count < 7 || count > 7)
                        {
                            printf("\tFormato de la cédula incorrecta, por favor intente de nuevo: ", count);
                            scanf("%f", &jefe.cedula);
                        }
                    } while (count != 7);

                    printf("\tEdad: ");
                    scanf("%d", &jefe.edad);

                    printf("\tTiene pareja (s/n): ");
                    scanf(" %c", &jefe.pareja);
                    while (jefe.pareja != 's' && jefe.pareja != 'n')
                    {
                        printf("\tDebe de introducir (s/n): ");
                        scanf("%c", &jefe.pareja);
                    }

                    printf("\t¿Cuál es su genero? (m/f): ");
                    scanf(" %c", &jefe.sexo);
                    while (jefe.sexo != 'm' && jefe.sexo != 'f')
                    {
                        printf("\tDebe de introducir (m/f): ");
                        scanf("%c", &jefe.sexo);
                    }
                }
            }
        }
    }
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
            printf("\t1- Visualizar información completa de un apartamento.\n");
            printf("\t2- Buscar información de jefe de familia.\n");
            printf("\t3- Relación porcentual de genero.\n");
            printf("\t4- Casos especiales.\n");
            printf("\t5- Valor modal.\n");
            printf("\t6- Estadística de habitabilidad.\n");
            printf("\t7- Menú anterior.\n");
            printf("\t8- Salir.\n");

            printf("Seleccione una opción: ");
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
            relacion_porcentaje();
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
        case 8:
            break;
        }
    } while (1);
}

void v_completa()
{
}

void buscar_jefe()
{
}

void relacion_porcentaje()
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

int digitos(float value)
{
    return (log10(value) + 1);
}