#ifndef PESSOA_H
#define PESSOA_H

#include <cstring>
#include <iostream>

using namespace std;

class Pessoa{
private:
    char * nome;

public:
    Pessoa(const char * meunome){
        cout << meunome << " foi criado" << endl;
        this->nome = new char[strlen(meunome) + 1];
        strcpy(this->nome, meunome);
    }

    ~Pessoa(){
        cout << this->nome << " morreeeeeeeeu" << endl;
        delete [] this->nome;
    }
};

int mainPessoa()
{
    {
        Pessoa * helvis = new Pessoa("Helvis Presley");
        (void) helvis;
        {
            Pessoa marcio("Marcio Maria");
            (void) marcio;
        }
        {
            Pessoa marcio("Eldéh Kandidu");
            (void) marcio;
        }
        delete helvis;
    }
    return 0;
}

#endif // PESSOA_H

