#include <iostream>
#include <vector>
using namespace std;



typedef enum{
    CREAR_ALUMNO = 1,
    CREAR_PROFESOR,
    MOSTRAR_ALUMNOS,
    MOSTRAR_PROFESORES,
    SALIR
}opcion_t;

// =====================
// CLASE PERSONA
// =====================
class persona {
private:
    string nombre;
    string apellido;
    int dni;
    int edad;
public: 
    persona (string, string, int, int); 

    // GETTERS
    string getNombre();
    string getApellido();
    int getDNI();
    int getEdad();
};

persona :: persona(string n, string a, int d, int e) {
    nombre = n;
    apellido = a;
    dni = d;
    edad = e;
}

string persona::getNombre(){ return nombre; }
string persona::getApellido(){ return apellido; }
int persona::getDNI(){ return dni; }
int persona::getEdad(){ return edad; }

// =====================
// CLASE ALUMNO
// =====================
class alumno : public persona {
private:
    int numero_alumno;
    int pruebas_aprobadas;
    int pruebas_desaprobadas;
    float promedio;
    int asistencia;

public:
    alumno(string, string, int, int, int);

    // GETTERS
    int getNumeroAlumno();
    int getAsistencia();
    int getPruebasAprobadas();
    int getPruebasDesaprobadas();
    float getPromedio();
    void setCodigoAlumno(int);

    void setResultadoPrueba(int);
    void cargarAsistencia(bool);
};

alumno::alumno(string n, string a, int d, int e, int num) : persona(n,a,d,e) {
    numero_alumno = num;
    pruebas_aprobadas = 0;
    pruebas_desaprobadas = 0;
    promedio = 0;
    asistencia = 0;
}

int alumno::getNumeroAlumno(){ return numero_alumno; }
int alumno::getAsistencia(){ return asistencia; }
int alumno::getPruebasAprobadas(){ return pruebas_aprobadas; }
int alumno::getPruebasDesaprobadas(){ return pruebas_desaprobadas; }
float alumno::getPromedio(){ return promedio; }

// =====================
// CLASE PROFESOR
// =====================
class profesor : public persona {
private:
    int codigo_profesor;
    int antiguedad;
    string materia;

public:
    profesor(string, string, int, int, int, string);

    // GETTERS
    int getCodigoProfesor();
    int getAntiguedad();
    string getMateria();

    void setCodigoProfesor(int);
    void setAntiguedad(int);
    void setMateria(string);
};

profesor::profesor(string n, string a, int d, int e, int cod, string mat) : persona(n,a,d,e) {
    codigo_profesor = cod;
    antiguedad = 0;
    materia = mat;
}

int profesor::getCodigoProfesor(){ return codigo_profesor; }
int profesor::getAntiguedad(){ return antiguedad; }
string profesor::getMateria(){ return materia; }

// =====================
// VECTORES GLOBALES
// =====================
int Bienvenida();
alumno CrearAlumno();
profesor CrearProfesor();
vector<alumno> lista_alumnos;
vector<profesor> lista_profesores;

int main() {
    int opcion;
    do {
        opcion = Bienvenida();
        switch (opcion) {
            case CREAR_ALUMNO: {
                alumno a1 = CrearAlumno();
                lista_alumnos.push_back(a1);
                break;
            }

            case CREAR_PROFESOR: {
                profesor p1 = CrearProfesor();
                lista_profesores.push_back(p1);
                break;
            }

            case MOSTRAR_ALUMNOS:
                cout << "\n=== LISTA DE ALUMNOS ===\n";
                for(auto& a : lista_alumnos){
                    cout << a.getNombre() << " " << a.getApellido() 
                        << " | DNI: " << a.getDNI()
                        << " | Numero alumno: " << a.getNumeroAlumno() << endl;
                }
                break;

            case MOSTRAR_PROFESORES:
                cout << "\n=== LISTA DE PROFESORES ===\n";
                for(auto& p : lista_profesores){
                    cout << p.getNombre() << " " << p.getApellido() 
                        << " | DNI: " << p.getDNI()
                        << " | Codigo profesor: " << p.getCodigoProfesor() << endl;
                }
                break;

            case SALIR:
                cout << "Hasta luego" << endl;
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != SALIR);

    return 0;
}

int Bienvenida() {
    int opcion;
    cout << "\n--- Menu de Escuela ---\n";
    cout << CREAR_ALUMNO<< ". Crear Alumno\n" ;
    cout << CREAR_PROFESOR<< ". Crear Profesor\n";
    cout << MOSTRAR_ALUMNOS<< ". Mostrar Alumnos\n";
    cout << MOSTRAR_PROFESORES<< ". Mostrar Profesores\n";
    cout << SALIR<< ". Salir\n";
    cout << "Ingrese su opcion: ";
    cin >> opcion;
    return opcion;
}

alumno CrearAlumno() {
    string nombre, apellido;
    int dni, edad, numero_alumno;
    cout << "Ingrese el nombre: ";
    cin >> nombre;
    cout << "Ingrese el apellido: ";
    cin >> apellido;
    cout << "Ingrese el DNI: ";
    cin >> dni;
    cout << "Ingrese la edad: ";
    cin >> edad;
    cout << "Ingrese el numero de alumno: ";
    cin >> numero_alumno;

    alumno a1(nombre, apellido, dni, edad, numero_alumno);
    return a1;
}
profesor CrearProfesor() {
    string nombre, apellido, materia;
    int dni, edad, codigo_profesor;
    cout << "Ingrese el nombre: ";
    cin >> nombre;
    cout << "Ingrese el apellido: ";
    cin >> apellido;
    cout << "Ingrese el DNI: ";
    cin >> dni;
    cout << "Ingrese la edad: ";
    cin >> edad;
    cout << "Ingrese el codigo de profesor: ";
    cin >> codigo_profesor;
    cout << "Ingrese la materia: ";
    cin >> materia;

    profesor p1(nombre, apellido, dni, edad, codigo_profesor, materia);
    return p1;
}