#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NOMBRE 100
#define ARCHIVO "inventario.txt"

typedef struct Producto {
    char nombre[MAX_NOMBRE];
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
producto_t* AgregarProducto(producto_t* lista);
void MostrarProductos(producto_t* lista);
void BuscarProducto(producto_t* lista, int codigo);
void ModificarCantidad(producto_t* lista, int codigo);
producto_t* EliminarProducto(producto_t* lista, int codigo);
void LiberarMemoria(producto_t* lista);
void GuardarEnArchivo(producto_t* lista);
producto_t* CargarDesdeArchivo();

int main() {
    opcion_t opcion;
    int codigo;
    producto_t* lista = CargarDesdeArchivo(); 

    do {
        opcion = Bienvenida();
        switch (opcion) {
            case AGREGAR_PRODUCTO:
                lista = AgregarProducto(lista);
                sleep(1.5);
                system("cls");
                break;
            case MOSTRAR_PRODUCTOS:
                MostrarProductos(lista);
                break;
            case BUSCAR_PRODUCTO:
                printf("Ingrese el codigo del producto a buscar: ");
                scanf("%d", &codigo);
                BuscarProducto(lista, codigo);
                break;
            case MODIFICAR_CANTIDAD:
                printf("Ingrese el codigo del producto a modificar: ");
                scanf("%d", &codigo);
                ModificarCantidad(lista, codigo);
                break;
            case ELIMINAR_PRODUCTO:
                printf("Ingrese el codigo del producto a eliminar: ");
                scanf("%d", &codigo);
                lista = EliminarProducto(lista, codigo);
                break;
            default:
                break;
        }
    } while (opcion != SALIR);

    GuardarEnArchivo(lista);  
    LiberarMemoria(lista);
    return 0;
}

int Bienvenida() {
    int opcion;
    printf("\n--- Menu de Inventario ---\n");
    printf("%d. Agregar producto\n", AGREGAR_PRODUCTO);
    printf("%d. Mostrar productos\n", MOSTRAR_PRODUCTOS);
    printf("%d. Buscar producto\n", BUSCAR_PRODUCTO);
    printf("%d. Modificar cantidad\n", MODIFICAR_CANTIDAD);
    printf("%d. Eliminar producto\n", ELIMINAR_PRODUCTO);
    printf("%d. Salir\n", SALIR);
    printf("Ingrese su opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

producto_t* AgregarProducto(producto_t* lista) {
    producto_t* nuevo = (producto_t*)malloc(sizeof(producto_t));
    if (nuevo == NULL) {
        printf("Error de memoria\n");
        return lista;
    }

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nuevo->nombre);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &nuevo->precio);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &nuevo->cantidad);
    nuevo->siguiente = NULL;

    int codigo = 1;
    producto_t* aux = lista;
    if (aux != NULL) {
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
            codigo++;
        }
        codigo++;
        aux->siguiente = nuevo;
    } else {
        lista = nuevo;
    }

    nuevo->codigo = codigo;
    printf("Producto agregado correctamente con codigo %d.\n", nuevo->codigo);
    return lista;
}

void MostrarProductos(producto_t* lista) {
    producto_t* aux = lista;
    while (aux != NULL) {
        printf("\nNombre: %s\nCodigo: %d\nPrecio: %.2f\nCantidad: %d\n",
                aux->nombre, aux->codigo, aux->precio, aux->cantidad);
        aux = aux->siguiente;
    }
}

void BuscarProducto(producto_t* lista, int codigo) {
    producto_t* aux = lista;
    while (aux != NULL) {
        if (aux->codigo == codigo) {
            printf("\nNombre: %s\nCodigo: %d\nPrecio: %.2f\nCantidad: %d\n",
                    aux->nombre, aux->codigo, aux->precio, aux->cantidad);
            return;
        }
        aux = aux->siguiente;
    }
    printf("Producto no encontrado.\n");
}

void ModificarCantidad(producto_t* lista, int codigo) {
    producto_t* aux = lista;
    while (aux != NULL) {
        if (aux->codigo == codigo) {
            printf("Producto encontrado. Cantidad actual: %d\n", aux->cantidad);
            printf("Ingrese nueva cantidad: ");
            scanf("%d", &aux->cantidad);
            printf("Cantidad actualizada.\n");
            return;
        }
        aux = aux->siguiente;
    }
    printf("Producto no encontrado.\n");
}

producto_t* EliminarProducto(producto_t* lista, int codigo) {
    producto_t* aux = lista;
    producto_t* anterior = NULL;

    while (aux != NULL) {
        if (aux->codigo == codigo) {
            if (anterior == NULL) {
                lista = aux->siguiente;
            } else {
                anterior->siguiente = aux->siguiente;
            }

            producto_t* ordenar = aux->siguiente;
            free(aux);
            printf("Producto eliminado.\n");


            while (ordenar != NULL) {
                ordenar->codigo--;
                ordenar = ordenar->siguiente;
            }

            return lista;
        }

        anterior = aux;
        aux = aux->siguiente;
    }

    printf("Producto no encontrado.\n");
    return lista;
}

void LiberarMemoria(producto_t* lista) {
    producto_t* aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
}

void GuardarEnArchivo(producto_t* lista) {
    FILE* archivo = fopen(ARCHIVO, "w");
    if (!archivo) {
        printf("No se pudo guardar el archivo.\n");
        return;
    }

    producto_t* aux = lista;
    while (aux != NULL) {
        fprintf(archivo, "%s %d %f %d\n", aux->nombre, aux->codigo, aux->precio, aux->cantidad);
        aux = aux->siguiente;
    }

    fclose(archivo);
    printf("Productos guardados correctamente.\n");
}

producto_t* CargarDesdeArchivo() {
    FILE* archivo = fopen(ARCHIVO, "r");
    if (!archivo) {
        return NULL; 
    }

    producto_t* lista = NULL;
    producto_t* ultimo = NULL;

    while (!feof(archivo)) {
        producto_t* nuevo = (producto_t*)malloc(sizeof(producto_t));
        if (fscanf(archivo, "%s %d %f %d\n", nuevo->nombre, &nuevo->codigo, &nuevo->precio, &nuevo->cantidad) == 4) {
            nuevo->siguiente = NULL;
            if (lista == NULL) {
                lista = nuevo;
                ultimo = nuevo;
            } else {
                ultimo->siguiente = nuevo;
                ultimo = nuevo;
            }
        } else {
            free(nuevo); 
        }
    }

    fclose(archivo);
    printf("Productos cargados desde archivo.\n");
    return lista;
}


