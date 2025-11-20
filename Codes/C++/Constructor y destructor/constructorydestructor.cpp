#include <iostream>
using namespace std;
#define CHONY 1
#define CHIKON 2
#define BERRETA 0
class camara{
    
    public:
        int marca;
    void tomar_foto(void){
        cout<<"Sonria!!!"<<endl;
    }
    void imprimir_marca(void){
        if(marca==CHONY){
            cout<<"Chony"<<endl;
        }else if(marca==CHIKON){
            cout<<"Chikon"<<endl;
        }else{
            cout<<"Berreta sin marca"<<endl;
        }
    }
    camara(int marcax){
        cout<<"Camara creada"<<endl;
        marca=marcax;
    }
    camara(void){
        cout<<"Camara creada"<<endl;
        marca=BERRETA;
    }

    ~camara(void){
        cout<<"Camara borrada"<<endl;
    }
};

int main (void){
    camara * cam=new(camara);
    cam->tomar_foto();
    cam->imprimir_marca();
    delete(cam);
    cout<<"Cerrando..."<<endl;
    return 0;
}


