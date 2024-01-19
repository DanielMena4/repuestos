#ifndef funciones_H_INCLUDED
#define funciones_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *archivo;

struct inventario_rep
{
    char nombre[50];
    char cantidad[20];
    char precio[20];

}inventario;

void crear()
{
    char direccion [] = "D:\\inventario_repuestos.txt";
    archivo = fopen(direccion, "wt");
    if (archivo == NULL)
    {
        printf("Error al tratar de crear el archivo");
        return 1;
    }
    fprintf(archivo,"\t : Inventario : \n");
    printf("\n\t: Ingrese los datos del repuesto : \n");
    
    fflush(stdin);
    printf("\nNombre: "); scanf("%s",inventario.nombre);
    printf("\nPrecio: "); scanf("%s",inventario.precio);
    printf("\nCantidad: "); scanf("%s",inventario.cantidad);

    fprintf(archivo,"\n\nNombre : ");
    fwrite(inventario.nombre,1,strlen(inventario.nombre),archivo);

    fprintf(archivo,"\nPrecio : ");
    fwrite(inventario.precio,1,strlen(inventario.precio),archivo);
        
    fprintf(archivo,"\nCantidad : ");
    fwrite(inventario.cantidad,1,strlen(inventario.cantidad),archivo);
    
    fclose(archivo);   
}

void agregar()
{
    char direccion [] = "D:\\inventario_repuestos.txt";
    char rpt = 's';
    archivo = fopen(direccion, "at");   
    if (archivo == NULL)
    {
        printf("Error al tratar de abrir el archivo");
        return 1;
    }
    printf("\n\t: Ingrese los datos del repuesto : \n");
    do
    {
        printf("\nNombre: "); scanf("%s",inventario.nombre);
        printf("\nPrecio: "); scanf("%s",inventario.precio);
        printf("\nCantidad: "); scanf("%s",inventario.cantidad);

        fprintf(archivo,"\n\nNombre : ");
        fwrite(inventario.nombre,1,strlen(inventario.nombre),archivo);

        fprintf(archivo,"\nPrecio : ");
        fwrite(inventario.precio,1,strlen(inventario.precio),archivo);
        
        fprintf(archivo,"\nCantidad : ");
        fwrite(inventario.cantidad,1,strlen(inventario.cantidad),archivo);
        fflush(stdin);

        printf("Desea agregar mas repuestos (s) : ");
        scanf("%c",&rpt);
    }while(rpt == 's');
    fclose(archivo);   
}

void visualizar()
{
    char direccion [] = "D:\\inventario_repuestos.txt";
    int c;
    archivo = fopen(direccion, "r");   
    if (archivo == NULL)
    {
        printf("Error al tratar de crear el archivo");
        return 1;
    }
    while ((c=fgetc(archivo))!=EOF)
    {
        if(c =='\n')
        {
            printf("\n");
        }
        else
        {
            putchar(c);
        }
    }
    
    fclose(archivo);   
}
#endif 