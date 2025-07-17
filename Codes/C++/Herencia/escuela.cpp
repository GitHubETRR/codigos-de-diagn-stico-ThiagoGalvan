#include <iostream>

using namespace std;

typedef enum{
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
    cout << "\nHola, soy " << n << " " << a << " \nMi dni es: " << d << " y mi edad es " << e << endl;
}

class alumno : public persona {
    private:
        int numero_alumno;
        int pruebas_aprobadas;
        int pruebas_desaprobadas;
        float promedio;
        int asistencia;

    public:
    void setCodigoAlumno(int);
    void setResultadoPrueba(int);
    void cargarAsistencia(bool);
    void calcularPromedio();//la voy a hacer despues para poner archivos y para guardar las notas

};

void alumno::setCodigoAlumno(int num) {
    numero_alumno = num;
}

void alumno::setResultadoPrueba(int resultado) {
    if (resultado => 7) {
        pruebas_aprobadas++;
    } else {
        pruebas_desaprobadas++;
    }
}

void alumno::cargarAsistencia(bool asistencia) {
    if (asistencia==1) {
        asistencia++;
    }
}

int main(){
    int opcion;
    cout << "Bienvenido al sistema de gestion escolar" << endl;
    cout << "1. Crear un usuario" << endl;
    cout << "2. Crear un alumno" << endl;
    cout << "3. Crear un profesor" << endl;
    cin >> opcion;

    switch (opcion){
    case CREAR_USUARIO:{
        
        string nombre;
        string apellido;
        int dni;
        int edad;

        cout << "Ingrese el nombre: ";
        cin >> nombre;
        cout << "Ingrese el apellido: ";
        cin >> apellido;
        cout << "Ingrese el DNI: ";
        cin >> dni;
        cout << "Ingrese la edad: ";
        cin >> edad;

        persona p1(nombre, apellido,dni, edad);
        break;
    }

    case CREAR_ALUMNO:{

        cout <<"Esta funcion no esta definida" << endl;
        break;
    }

    case CREAR_PROFESOR:{
        cout <<"Esta funcion no esta definida" << endl;
        break;
    }
    case SALIR:{
        cout << "Hasta luego" << endl;
        break;
    }
    default:
        break;
    }
    

}

