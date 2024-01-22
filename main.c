
#include "funciones.h"

int main() {
    FILE *archivo;
    int opcion;

    // Apertura del archivo en modo texto (lectura y escritura)
    archivo = fopen("inventario_repuestos.txt", "a+");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    while (opcion != 5){
        printf("\n1. Agregar Repuesto\n2. Editar Repuesto\n3. Eliminar Repuesto\n4. Listar Repuestos\n5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarRepuesto(archivo);
                break;
            case 2:
                editarRepuesto(archivo);
                break;
            case 3:
                eliminarRepuesto(archivo);
                break;
            case 4:
                listarRepuestos(archivo);
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    }

    // Cierre del archivo al salir del programa
    fclose(archivo);

    return 0;
}
