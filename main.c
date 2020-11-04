#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define ESC       27
#define SPACE     32
#define BACKS     8
#define COMMA     44
#define PUNTO     46
#define PunDouble 58
#define PunYComma 59
#define ENTER     13


char c, nombre[100], corregido[] = "";
int SelectMenu = 0;
char linea[1024];
//char letra;
int cont;
FILE*FF;

//PARAMETRIZACION DE LAS FUNCIONES
void Leer_Archivo();
int imprimir_menu();

errno_t cppy(char *string, char *string1);

intptr_t strcat2(char corregido[1], char nombre[100]);

void ENCABEZADO()
{
    printf("\n\t***FUNDAMENTOS DE PROGRAMACION**\n");
    printf("\tManejo de Punteros y Cadenas de Caracteres\n\n");
};

int imprimir_menu()
{
    system("CLS");
    ENCABEZADO();
    printf("\n\n**MENU**");
    char menu[][100]={"1- Ingresar parrafo ", "2- Leer archivo existente ", "3- Guardar el documento en la ruta de su preferencia", "4- Analisis del texto digitado","5- Salir"};
    int longitud_arreglo = sizeof(menu) / sizeof(menu[0]);
    for (int i=0; i<longitud_arreglo; i++)
    {
        printf("\n %s",menu[i]);
    }
    printf("\n\n----> ");
    scanf("%d",&SelectMenu);

    return SelectMenu;
};

void capturar_archivo()
{
    //guardar lineas de archivos sin formatear
    char Bc, Fc;
    system("CLS");
    ENCABEZADO();
    bool terminar = false;
    FILE*pf;
    printf("\n\tDigite el nombre del archivo --> ");
    scanf("%s",&nombre);
    pf=fopen(nombre,"wt");

    if (pf == NULL)
    {
        printf("Error de acceso a fichero.\n");
        exit(0);
    }
    else
    {
        cppy(corregido, "");
        strcat(corregido, nombre);
        strcat(corregido, "_fixed");
        FF = fopen(corregido,"wt");

        printf("\tIntroduce el texto, para concluir presione $ + ENTER  \n\n");
        do
        {
            scanf("%c", &c);
            fputc(c, pf);

            if(c=='$')
            {
                terminar = true;
            }else
            {
                //aqui cada entrada debe ser revisada y corregida para colocar en el archivo fixed.
                Fc = terminar*(Bc, c);
                //fputc(Fc, FF);
                Bc = c;
            }
        }while(!terminar);
        fclose(pf);
        fclose(FF);

        // Hasta aqui captura de archivo sin formatear
        printf("\t\n\n\n[Archivo guardado satisfactoriamente]\n");
        system("PAUSE");
    }
}

/*void strcat(char corregido[1], char nombre[100]) {

};*/

void Leer_Archivo(char file[])
{
    FILE*pff;
    pff = fopen(file, "rt");

    if (pff == NULL)
    {
        printf("Error de acceso a fichero.\n");
    }else
    {
        //imprimir linea a linea tal cual encontre el archivo
        while(fgets(linea, 1024, (FILE*) pff))
        {
            printf("%s", linea);
        }
        fclose(pff);
    }
    printf("\n\n\n");
};


void Buscar_Archivo()
{
    printf("Digite el nombre del archivo --> ");
    scanf("%s",&nombre);
    system("CLS");
    ENCABEZADO();
    Leer_Archivo(nombre);
    printf("\t[TEXTO CORREGIDO]\n\n");
    cppy(corregido, "");
    strcat(corregido, nombre);
    strcat(corregido, "_fixed");
    Leer_Archivo(corregido);
    system("PAUSE");
}

errno_t cppy(char *string, char *string1) {
    return 0;
};

char corrector(char BC, char CC)
{

    return 0;
};


//PROGRAMA

int main()
{
    bool salir = false;

    do{
        imprimir_menu();
        switch(SelectMenu)
        {
            case 1:
                capturar_archivo();
                // Imprimir Archivo Capturado
                Leer_Archivo(nombre);
                break;
            case 2:
                Buscar_Archivo();
                break;
            case 3:

                //leer_contenido_archivo();
                break;
            case 4:
                //analizar_contenido_archivo();
                break;
            case 5:
                salir = true;
            default :
                printf("Funci%cn elegida no es v%clida",162,160);
                break;
        }

    }while(!salir);

    return 0;
};