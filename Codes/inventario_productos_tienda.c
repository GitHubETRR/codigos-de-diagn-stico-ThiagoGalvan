#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Producto {
    char nombre[100];
    int codigo;
    int cantidad;
    float precio;
    struct Producto* siguiente;
} producto_t;

typedef enum {
    SALIR,
    AGREGAR_PRODUCTO,
    MOSTRAR_PRODUCTOS,
    BUSCAR_PRODUCTO,
    MODIFICAR_CANTIDAD,
    ELIMINAR_PRODUCTO
} opcion_t;

int Bienvenida();
producto_t* AgregarProducto(producto_t* cabeza);
void MostrarProductos(producto_t* cabeza);
void BuscarProducto(producto_t* cabeza, int codigo);
void ModificarCantidad(producto_t* cabeza, int codigo);
producto_t* EliminarProducto(producto_t* cabeza, int codigo);
void LiberarMemoria(producto_t* cabeza);

int main() {
    opcion_t opcion;
    int codigo;
    producto_t* cabeza = NULL;

    do {
        opcion = Bienvenida();
        switch (opcion) {
            case AGREGAR_PRODUCTO:
                cabeza = AgregarProducto(cabeza);
                break;
            case MOSTRAR_PRODUCTOS:
                MostrarProductos(cabeza);
                break;
            case BUSCAR_PRODUCTO:
                printf("Ingrese el codigo del producto a buscar: ");
                scanf("%d", &codigo);
                BuscarProducto(cabeza, codigo);
                break;
            case MODIFICAR_CANTIDAD:
                printf("Ingrese el codigo del producto a modificar: ");
                scanf("%d", &codigo);
                ModificarCantidad(cabeza, codigo);
                break;
            case ELIMINAR_PRODUCTO:
                printf("Ingrese el codigo del producto a eliminar: ");
                scanf("%d", &codigo);
                cabeza = EliminarProducto(cabeza, codigo);
                break;
            default:
                break;
        }
    } while (opcion != SALIR);

    LiberarMemoria(cabeza);
    return 0;
}

int Bienvenida() {
    int opcion;
    printf("\n--- Menu de Inventario ---\n");
    printf("1. Agregar producto\n");
    printf("2. Mostrar productos\n");
    printf("3. Buscar producto\n");
    printf("4. Modificar cantidad\n");
    printf("5. Eliminar producto\n");
    printf("0. Salir\n");
    printf("Ingrese su opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

producto_t* AgregarProducto(producto_t* cabeza) {
    producto_t* nuevo = (producto_t*)malloc(sizeof(producto_t));
    if (nuevo==NULL) {
        printf("Error de memoria\n");
        return 1;
    }
    printf("Ingrese el nombre del producto: ");
    scanf("%s", nuevo->nombre);
    printf("Ingrese el codigo del producto: ");
    scanf("%d", &nuevo->codigo);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &nuevo->precio);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &nuevo->cantidad);
    nuevo->siguiente = cabeza;
    printf("Producto agregado correctamente\n");
    return nuevo;
}

void MostrarProductos(producto_t* cabeza) {
    producto_t* actual = cabeza;
    while (actual != NULL) {
        printf("\nNombre: %s\nCodigo: %d\nPrecio: %.2f\nCantidad: %d\n",
               actual->nombre, actual->codigo, actual->precio, actual->cantidad);
        actual = actual->siguiente;
    }
}

void BuscarProducto(producto_t* cabeza, int codigo) {
    producto_t* actual = cabeza;
    while (actual != NULL) {
        if (actual->codigo == codigo) {
            printf("\nNombre: %s\nCodigo: %d\nPrecio: %.2f\nCantidad: %d\n",
                   actual->nombre, actual->codigo, actual->precio, actual->cantidad);
            return;
        }
        actual = actual->siguiente;
    }
    printf("Producto no encontrado.\n");
}

void ModificarCantidad(producto_t* cabeza, int codigo) {
    producto_t* actual = cabeza;
    while (actual != NULL) {
        if (actual->codigo == codigo) {
            printf("Producto encontrado. Cantidad actual: %d\n", actual->cantidad);
            printf("Ingrese nueva cantidad: ");
            scanf("%d", &actual->cantidad);
            printf("Cantidad actualizada.\n");
            return;
        }
        actual = actual->siguiente;
    }
    printf("Producto no encontrado.\n");
}

producto_t* EliminarProducto(producto_t* cabeza, int codigo) {
    producto_t* actual = cabeza;
    producto_t* anterior = NULL;

    while (actual != NULL) {
        if (actual->codigo == codigo) {
            if (anterior == NULL) {
                cabeza = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            printf("Producto eliminado.\n");
            return cabeza;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    printf("Producto no encontrado.\n");
    return cabeza;
}

void LiberarMemoria(producto_t* cabeza) {
    producto_t* actual;
    while (cabeza != NULL) {
        actual = cabeza;
        cabeza = cabeza->siguiente;
        free(actual);
    }
}
