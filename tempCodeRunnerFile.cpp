#include <iostream>

using namespace std;


class pareja {
private:
// Datos miembro de la clase "pareja"
int a, b;
public:
// Metodos / Funciones miembro de la clase "pareja"
void Lee(int &a2, int &b2);
void Guarda(int a2, int b2) {
a = a2;
b = b2;
}
};
void pareja::Lee(int &a2, int &b2) {
a2 = a;
b2 = b;
}
int main(){
pareja par1;
int x, y;
par1.Guarda(12, 32);
par1.Lee(x, y);
cout << "Valor de par1.a: " << x << endl;
cout << "Valor de par1.b: " << y << endl;
return 0;
}
