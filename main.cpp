#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int torres[2][10][6] = {}; // Array Inicializado

struct Jefe
{
    double cedula;
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
void r_encuestas();
void reportes();
void v_completa();
void buscar_jefe();
void relacion_porcentaje();
void casos();
void valor_modal();
void estadistica();

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
            printf("Elija el tipo de cambio que desee hacer: \n");
            printf("\t1- Realizar encuestas.\n");
            printf("\t2- Reportes\n");
            printf("\t3- Salir.\n");

            printf("Seleccione una opción: ");
            scanf("%d", &menu);
        } while (menu < 1 || menu > 3);

        switch (menu)
        {
        case 1:
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

    printf("Censo Residencial\n\n");

    Child child;
    Jefe jefe;
    Habitabilidad habitabilidad;

    FILE *archivo = fopen("Conjunto_Residencial.dat", "wb");

    if (archivo != NULL)
    {
        fflush(stdin);

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int z = 0; z < 6; z++)
                {
                    printf("Introducir información de la Torre %d, Piso: %d, Apartamento: %d\n", i + 1, j + 1, z + 1);

                    printf("Datos del jefe de familia: \n");
                    printf("Cédula: ");
                    scanf("%d", &jefe.cedula);
                    printf("Edad: ");
                    scanf("%d", &jefe.edad);
                    printf("Tiene pareja (s o n): ");
                    scanf("%c", &jefe.pareja);
                    if (jefe.pareja != 's' || jefe.pareja != 'n')
                    {
                        printf("Debe de introducir s o n");
                        fflush(stdin);
                        scanf("%c", &jefe.pareja);
                    }
                    printf("¿Cuál es su genero? (M o F): ");

                    scanf("%c", &);

                    scanf("", &);

                    scanf("", &);
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
        } while (menu < 1 || menu > 8);

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