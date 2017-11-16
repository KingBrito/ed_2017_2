#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

enum State {Vazio, Existe, Removido};

struct Node {
    int value;
    State state;

    Node() = default;

    Node(int value){
        this->state = Existe;
        this->value = value;
    }

    bool operator ==(int value){
        if(this->state == Existe)
            if(this->value == value)
                return true;
        return false;
    }
};


class Hash {
    int * _data;
    int _capacity;
    int _size;

public:
    Hash(int capacity){
        this->_capacity = capacity;
        this->_data = new int[capacity];
        this->_size = 0;
    }

    ~Hash(){
        delete [] this->_data;
        this->_data = nullptr;
    }

    bool inserir(int value){

    }

    bool remover(int value){

    }

    void reinserir_todos(int capacity){

    }

    //retornar onde o elemento esta
    //ou onde deveria estar
    int search(int value){

    }

    //return se existe ou não
    bool exists(int value){

    }

};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

