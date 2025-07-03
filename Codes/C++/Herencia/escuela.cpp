#include <iostream>

using namespace std;

class persona {
    private:
        string nombre;
        string apellido;
        int dni;
        int edad;
    public: 
        persona (string, string, int, int);
        void presentarse(string, string); 
}

void presentarse(nombre, apellido) {
            cout << "Hola, soy " << nombre << " " << apellido << endl;
        }

persona :: persona(string n, string a, int d, int e) {
    nombre = n;
    apellido = a;
    dni = d;
    edad = e;
}



int main(){
}
