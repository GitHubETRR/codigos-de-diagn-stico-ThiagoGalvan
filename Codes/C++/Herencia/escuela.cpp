#include <iostream>

using namespace std;

typedef enum{
    CREAR_ALUMNO = 1,
    CREAR_PROFESOR,
    SALIR
}opcion_t;

//Clase persona
class persona {
    private:
        string nombre;
        string apellido;
        int dni;
        int edad;
    public: 
        persona (string, string, int, int); 
};
//Constructor de la clase persona
persona :: persona(string n, string a, int d, int e) {
    nombre = n;
    apellido = a;
    dni = d;
    edad = e;
    cout << "\nHola, soy " << n << " " << a << " \nMi dni es: " << d << " y mi edad es " << e << endl;
}



//Clase alumno con la herencia de persona
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
    alumno(string, string, int, int, int);

};

//Metodos de la clase alumno
void alumno::setCodigoAlumno(int num) {
    numero_alumno = num;
}
void alumno::setResultadoPrueba(int resultado) {
    while (resultado < 0 || resultado > 10){
        cout << "Error, ingrese un resultado valido (0-10): ";
        cin >> resultado;
    }
    if (resultado >= 7){
        pruebas_aprobadas++;
    } else {
        pruebas_desaprobadas++;
    }
}
void alumno::cargarAsistencia(bool presente) {
    if (presente==1) {
        asistencia++;
    }
}
//Constructor de la clase alumno
alumno::alumno(string n, string a, int d, int e, int num) : persona(n,a,d,e) {
    numero_alumno = num;
    pruebas_aprobadas = 0;
    pruebas_desaprobadas = 0;
    promedio = 0;
    asistencia = 0;
}




//Clase profesor con la herencia de persona
class profesor : public persona {
    private:
        int codigo_profesor;
        int antiguedad;
        string materia;

    public:
        void setCodigoProfesor(int);
        void setAntiguedad(int);
        void setMateria(string);
        profesor(string, string, int, int, int, string);

};

//Metodos de la clase profesor
void profesor::setCodigoProfesor(int cod) {
    codigo_profesor = cod;
}
void profesor::setAntiguedad(int antig) {
    antiguedad = antig;
}
void profesor::setMateria(string mat) {
    materia = mat;
}

//Constructor de la clase profesor
profesor::profesor(string n, string a, int d, int e, int cod, string mat) : persona(n,a,d,e) {
    codigo_profesor = cod;
    antiguedad = 0;
    materia = mat;
}


int main(){
    int opcion;
    cout << "Bienvenido al sistema de gestion escolar" << endl;
    cout << "1. Crear un alumno" << endl;
    cout << "2. Crear un profesor" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion){
    case CREAR_ALUMNO:{
        string nombre;
        string apellido;
        int dni;
        int edad;
        int numero_alumno;

        cout << "Ingrese el nombre: ";
        cin >> nombre;
        cout << "Ingrese el apellido: ";
        cin >> apellido;
        cout << "Ingrese el DNI: ";
        cin >> dni;
        cout << "Ingrese la edad: ";
        cin >> edad;
        
        alumno a1(nombre, apellido,dni,edad, numero_alumno);
        break;
    }

    case CREAR_PROFESOR:{

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


