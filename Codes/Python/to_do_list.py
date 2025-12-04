tareas = {
    "escuela": [],
    "casa": [],
    "personal": []
}

def mostrar_tareas():
    print("\n=== LISTA DE TAREAS ===")
    for categoria, lista in tareas.items():
        print(f"\n▶ {categoria.upper()}:")
        if len(lista) == 0:
            print("  (sin tareas)")
        else:
            for indice, tarea in enumerate(lista, start=1):
                print(f"  {indice}. {tarea}")

def agregar_tarea():
    print("\n=== AGREGAR TAREA ===")
    categoria = input("Categoría (escuela / casa / personal): ").lower()

    if categoria not in tareas:
        print("Categoría inválida.")
        return

    descripcion = input("Descripción de la tarea: ")
    tareas[categoria].append(descripcion)
    print("Tarea agregada correctamente.")

def eliminar_tarea():
    print("\n=== ELIMINAR TAREA ===")
    categoria = input("Categoría (escuela / casa / personal): ").lower()

    if categoria not in tareas:
        print("Categoría inválida.")
        return

    mostrar_tareas()
    try:
        numero = int(input("Número de la tarea a eliminar: "))
        if 1 <= numero <= len(tareas[categoria]):
            tareas[categoria].pop(numero - 1)
            print("Tarea eliminada.")
        else:
            print("Número inválido.")
    except:
        print("Entrada inválida.")

def Programa():
    while True:
        print("\n======= MENÚ =======")
        print("1. Mostrar tareas")
        print("2. Agregar tarea")
        print("3. Eliminar tarea")
        print("4. Salir")

        opcion = input("Elegí una opción: ")

        if opcion == "1":
            mostrar_tareas()
        elif opcion == "2":
            agregar_tarea()
        elif opcion == "3":
            eliminar_tarea()
        elif opcion == "4":
            print("¡Hasta luego!")
            break
        else:
            print("Opción inválida, intentá de nuevo.")


Programa()
