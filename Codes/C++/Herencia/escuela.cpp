#include <iostream>

using namespace std;

typdef enum{
    SALIR,
    CREAR_USUARIO,
    CREAR_ALUMNO,
    CREAR_PROFESOR
}opcion_t;

class persona {
    private:
        string nombre;
        string apellido;
        int dni;
        int edad;
    public: 
        persona (string, string, int, int); 
};

persona :: persona(string n, string a, int d, int e) {
    nombre = n;
    apellido = a;
    dni = d;
    edad = e;
    cout << "Hola, soy " << n << " " << a << " \nMi dni es: " << d << " y mi edad es " << e << endl;
}

int main(){
    int opcion;
    cout << "Bienvenido al sistema de gestion escolar" << endl;
    cout << "1. Crear un usuario" << endl;
    cout << "2. Crear un alumno" << endl;
    cout << "3. Crear un profesor" << endl;
    cin >> opcion;

    switch (opcion){
    case CREAR_USUARIO:
        persona p1("Juan", "Perez", 12345678, 30);
        break;
    case CREAR_ALUMNO:
        cout <<"Esta funcion no esta definida" << endl;
        break;

    case CREAR_PROFESOR:
        cout <<"Esta funcion no esta definida" << endl;
        break;
    case SALIR:
        cout << "Hasta luego" << endl;
        break;
    default:
        break;
    }
    

}

