#include <iostream>
#include <vector>
#include <unistd.h>
#include <fstream>
#include <sstream>
using namespace std;


typedef enum{
    CREAR_ALUMNO = 1,
    CREAR_PROFESOR,
    MOSTRAR_ALUMNOS,
    MOSTRAR_PROFESORES,
    CARGAR_ASISTENCIA,
    CARGAR_RESULTADO_PRUEBA,
    MOSTRAR_PROMEDIOS,
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
        string getNombre() const;
        string getApellido() const;
        int getDNI() const;
        int getEdad() const;
};

persona :: persona(string n, string a, int d, int e) {
    nombre = n;
    apellido = a;
    dni = d;
    edad = e;
}


//Funciones de los getters de persona
string persona::getNombre()const{ return nombre; }
string persona::getApellido()const{ return apellido; }
int persona::getDNI()const{ return dni; }
int persona::getEdad()const{ return edad; }



class alumno : public persona{
    private:
        static int contadorAlumno;
        int numero_alumno;
        int pruebas_aprobadas;
        int pruebas_desaprobadas;
        float promedio;
        int asistencia;
        vector<int> resultados_pruebas;
    public:
        alumno(string, string, int, int);// constructor   
        // GETTERS DE LOS ALUMNOS
        int getNumeroAlumno() const;
        int getAsistencia() const;
        int getPruebasAprobadas() const;
        int getPruebasDesaprobadas() const;
        float getPromedio() const;
        vector<int> getResultados()const; 
        // SETTERS DE LOS ALUMNOS
        
        void cargarResultadoPrueba(int);
        void cargarAsistencia(int);
        void set_pruebas_aprobadas(int);
        void set_pruebas_desaprobadas(int);
        void set_promedio(float);

};

// Funcion del Constructor de alumno    
int alumno::contadorAlumno = 0;
alumno::alumno(string nombre, string apellido, int dni, int edad) : persona(nombre,apellido,dni,edad) {
    numero_alumno = ++contadorAlumno;
    pruebas_aprobadas = 0;
    pruebas_desaprobadas = 0;
    promedio = 0;
    asistencia = 0;
}

//Funcion de los getters de los alumnos
int alumno::getNumeroAlumno() const { return numero_alumno; }
int alumno::getAsistencia() const { return asistencia; }
int alumno::getPruebasAprobadas() const {
    int cont = 0;
    for (int nota : resultados_pruebas) if (nota >= 7) cont++;
    return cont;
}
int alumno::getPruebasDesaprobadas() const {
    int cont = 0;
    for (int nota : resultados_pruebas) if (nota < 7) cont++;
    return cont;
}
float alumno::getPromedio() const {
    if (resultados_pruebas.empty()) return 0;
    float suma = 0;
    for (int nota : resultados_pruebas) 
    suma += nota;
    return suma / resultados_pruebas.size();
}
vector<int> alumno::getResultados()const { return resultados_pruebas; }

//Funcion de los setters de los alumnos
void alumno::cargarResultadoPrueba(int resultado) {
    resultados_pruebas.push_back(resultado);
}

void alumno::cargarAsistencia(int a) { asistencia += a; }
void alumno::set_pruebas_aprobadas(int aprobadas) { pruebas_aprobadas = aprobadas; }
void alumno::set_pruebas_desaprobadas(int desaprobadas) { pruebas_desaprobadas = desaprobadas; }
void alumno::set_promedio(float prom) { promedio = prom; }

// =====================
// CLASE PROFESOR
// =====================
class profesor : public persona {
private:
    static int contadorProfesor;
    int numero_profesor;
    int codigo_profesor;
    int antiguedad;
    string materia;

public:
    profesor(string, string, int, int, int, string);

    // GETTERS
    int getCodigoProfesor()const;
    int getAntiguedad()const;
    string getMateria()const;

    void setCodigoProfesor(int);
    void setAntiguedad(int);
    void setMateria(string);
};

// Funcion del Constructor de profesor
int profesor::contadorProfesor = 0;
profesor::profesor(string nombre, string apellido, int dni, int edad, int cod, string mat) : persona(nombre,apellido,dni,edad) {
    codigo_profesor = ++contadorProfesor;
    antiguedad = 0;
    materia = mat;
}

//Funcion de los getters de los profesores
int profesor::getCodigoProfesor()const{ return codigo_profesor; }
int profesor::getAntiguedad()const{ return antiguedad; }
string profesor::getMateria()const{ return materia; }


//Funciones para que no haya tanto texto
int Bienvenida();
alumno CrearAlumno();
profesor CrearProfesor();
void guardarAlumnos();
void cargarAlumnos();
void guardarProfesores();
void cargarProfesores();
// VECTORES GLOBALES(PARA REEMPLAZAR LAS LISTAS ENLAZADAS CON PUNTEROS)
vector<alumno> lista_alumnos;
vector<profesor> lista_profesores;

int main() {
    cargarAlumnos();
    cargarProfesores();
    int opcion;
    do {
        opcion = Bienvenida();
        switch (opcion) {
            case CREAR_ALUMNO: {
                alumno a1 = CrearAlumno();
                lista_alumnos.push_back(a1);
                guardarAlumnos();
                break;
            }

            case CREAR_PROFESOR: {
                profesor p1 = CrearProfesor();
                lista_profesores.push_back(p1);
                guardarProfesores();
                break;
            }
    
            case MOSTRAR_ALUMNOS:
                if (lista_alumnos.empty()){
                    cout << "No hay alumnos cargados aun.\n";
                    cout << "Presione enter para volver al menu.\n";
                    cin.ignore();
                    cin.get();
                    system("cls");
                    break;
                }
                cout << "\n=== LISTA DE ALUMNOS ===\n";
                for(const auto& alumno_actual : lista_alumnos){
                    cout<< " | Numero alumno: " << alumno_actual.getNumeroAlumno()<< " | ";
                    cout << alumno_actual.getNombre() << " " << alumno_actual.getApellido();
                    cout<< " | DNI: " << alumno_actual.getDNI();
                    cout<< " | Promedio: " << alumno_actual.getPromedio();
                    cout<< " | Aprobadas: " << alumno_actual.getPruebasAprobadas();
                    cout<< " | Desaprobadas: " << alumno_actual.getPruebasDesaprobadas() << endl;

                }
                cout << "Presione enter para volver al menu.\n";
                cin.ignore();
                cin.get();
                system("cls");
                break;

            case MOSTRAR_PROFESORES:
                if (lista_profesores.empty()){
                cout << "No hay profesores cargados aun.\n";
                cout << "Presione enter para volver al menu.\n";
                cin.ignore();
                cin.get();
                system("cls");
                break;
                }
                cout << "\n=== LISTA DE PROFESORES ===\n";
                for(const auto& profesor_actual : lista_profesores){
                    cout << " | Codigo profesor: " << profesor_actual.getCodigoProfesor()<< " | ";
                    cout << profesor_actual.getNombre() << " " << profesor_actual.getApellido();
                    cout << " | DNI: " << profesor_actual.getDNI()<<" | ";
                    cout << " | Materia: " << profesor_actual.getMateria() << endl;
                }
                cout << "Presione enter para volver al menu.\n";
                cin.ignore();
                cin.get();
                system("cls");
                break;

            case CARGAR_ASISTENCIA:
                int asistencia;
                bool asistencia_valida;
                
                if (lista_alumnos.empty()){
                    cout << "No hay alumnos cargados aun.\n";
                    cout << "Presione enter para volver al menu.\n";
                    cin.ignore();
                    cin.get();
                    system("cls");
                    break;
                }
                
                
                for (auto& alumno_actual : lista_alumnos)
                {
                    do{
                        asistencia_valida=false;
                        cout << "'1' para presente, '0' para ausente.\n";
                        cout << alumno_actual.getNombre() << " " << alumno_actual.getApellido() << ": ";
                        cin >> asistencia;
                        if (asistencia==1||asistencia==0){asistencia_valida=true;}
                        
                        else{cout << "Valor invalido. Asistencia no registrada.\n";}
                    }while (asistencia_valida==false);
                    alumno_actual.cargarAsistencia(asistencia);
                    
                }
                guardarAlumnos();
                cout << "Presione enter para volver al menu.\n";
                cin.ignore();
                cin.get();
                system("cls");
                break;      

            case CARGAR_RESULTADO_PRUEBA:
                if (lista_alumnos.empty()){
                    cout << "No hay alumnos cargados aun.\n";
                    cout << "Presione enter para volver al menu.\n";
                    cin.ignore();
                    cin.get();
                    system("cls");
                    break;
                }

                int nota;
                bool nota_valida;

                for (auto& alumno_actual : lista_alumnos){
                    do{
                        cout << "Ingrese nota 1<>10 para "; 
                        cout<< alumno_actual.getNombre() << " "; 
                        cout<< alumno_actual.getApellido() << ": ";
                        cin >> nota;

                        nota_valida = (nota >= 1 && nota <= 10);

                        if(!nota_valida)
                            cout << "\nNota invalida. Debe estar entre 1 y 10.\n";

                    }while (!nota_valida);

                    alumno_actual.cargarResultadoPrueba(nota);
                    
                }
                cout << "Presione enter para volver al menu.\n";
                cin.ignore();
                cin.get();
                system("cls");
                guardarAlumnos();
                break;
                
            case MOSTRAR_PROMEDIOS:
                if (lista_alumnos.empty()){
                    cout << "No hay alumnos cargados aun.\n";
                    cout << "Presione enter para volver al menu.\n";
                    cin.ignore();
                    cin.get();
                    system("cls");
                    break;
                }
                cout << "\n=== PROMEDIOS DE ALUMNOS ===\n";
                for(const auto& alumno_actual : lista_alumnos){
                    cout<< " | Numero alumno: " << alumno_actual.getNumeroAlumno()<< " | ";
                    cout << alumno_actual.getNombre() << " " << alumno_actual.getApellido();
                    cout<< " | Promedio: " << alumno_actual.getPromedio()<< endl;  
                }
                cout << "Presione enter para volver al menu.\n";
                cin.ignore();
                cin.get();
                system("cls");
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
    cout << CARGAR_ASISTENCIA<< ". Cargar Asistencia\n";
    cout << CARGAR_RESULTADO_PRUEBA<< ". Cargar Resultado Prueba\n";
    cout << MOSTRAR_PROMEDIOS<< ". Mostrar Promedios\n";
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
    alumno a1(nombre, apellido, dni, edad);
    cout << "\nAlumno creado correctamente con ID " << a1.getNumeroAlumno() << ".\n";
    cout << "Presione enter para volver al menu.\n";
    cin.ignore();
    cin.get();
    system("cls");
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
    cout << "Ingrese la materia: ";
    cin >> materia;

    profesor p1(nombre, apellido, dni, edad, codigo_profesor, materia);
    cout << "\nProfesor creado correctamente con ID " << p1.getCodigoProfesor() << ".\n";
    cout << "Presione enter para volver al menu.\n";
    cin.ignore();
    cin.get();
    system("cls");
    return p1;
}

void guardarAlumnos() {
    ofstream archivo("alumnos.csv");

    for (auto& alumno : lista_alumnos) {
        archivo << alumno.getNumeroAlumno() << ","
                << alumno.getNombre() << ","
                << alumno.getApellido() << ","
                << alumno.getDNI() << ","
                << alumno.getEdad() << ","
                << alumno.getAsistencia();
        for (auto& nota : alumno.getResultados()){
            archivo << "," << nota;
        }
        archivo << endl;
    }
    archivo.close();
    cout << "Archivo alumnos.csv guardado correctamente.\n";
}

void cargarAlumnos() {
    ifstream archivo("alumnos.csv");
    if (!archivo) return;

    string linea;
    while (getline(archivo, linea)) {
        stringstream stream(linea);

        string numStr, nombre, apellido, dniStr, edadStr, promedioStr, aprobadasStr, desaprobadasStr, asistenciaStr;

        getline(stream, numStr, ',');
        getline(stream, nombre, ',');
        getline(stream, apellido, ',');
        getline(stream, dniStr, ',');
        getline(stream, edadStr, ',');
        getline(stream, asistenciaStr, ',');

        alumno al(nombre, apellido, stoi(dniStr), stoi(edadStr));
        al.cargarAsistencia(stoi(asistenciaStr));

        string notaStr;
        while (getline(stream, notaStr, ',')) {
            al.cargarResultadoPrueba(stoi(notaStr));
        }
        
        lista_alumnos.push_back(al);
    }
    archivo.close();
}
void guardarProfesores() {
    ofstream archivo("profesores.csv");

    for (auto& profesor : lista_profesores) {
        archivo << profesor.getCodigoProfesor() << ","
                << profesor.getNombre() << ","
                << profesor.getApellido() << ","
                << profesor.getDNI() << ","
                << profesor.getEdad() << ","
                << profesor.getMateria()
                << endl;
    }
    archivo.close();
    cout << "Archivo profesores.csv guardado correctamente.\n";
}

void cargarProfesores() {
    ifstream archivo("profesores.csv");
    if (!archivo) return;

    string linea;
    while (getline(archivo, linea)) {
        stringstream stream(linea);

        string codStr, nombre, apellido, dniStr, edadStr, materia;

        getline(stream, codStr, ',');
        getline(stream, nombre, ',');
        getline(stream, apellido, ',');
        getline(stream, dniStr, ',');
        getline(stream, edadStr, ',');
        getline(stream, materia, ',');

        profesor prof(nombre, apellido, stoi(dniStr), stoi(edadStr), stoi(codStr), materia);
        
        lista_profesores.push_back(prof);
    }
    archivo.close();
}
