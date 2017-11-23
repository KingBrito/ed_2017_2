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


    bool equals(int value){
        if(this->state == Existe)
            if(this->value == value)
                return true;
        return false;
    }
};


class Hash {
    Node * _data;
    int _capacity;
    int _size;

public:
    Hash(int capacity){
        this->_capacity = capacity;
        this->_data = new Node[capacity];
        this->_size = 0;
    }

    ~Hash(){
        delete [] this->_data;
        this->_data = nullptr;
    }

    bool inserir(int value){
        int ind = search(value);
        if(this->_data[ind].equals(value))
           return false;
        this->_data[ind] = Node(value);
        this->_size++;
    }

    bool remover(int value){
        int ind = search(value);
        if(!this->_data[ind].equals(value))
            return false;
        this->_data[ind].state = Removido;
        this->_size--;
    }

    void reinserir_todos(int capacity){

    }

    //retornar onde o elemento esta
    //ou onde deveria estar
    int search(int value){
        int base = value % this->_capacity;
        int i = 0;
        int ind = base;

        int idel = -1;

        while(!(this->_data[ind].equals(value))
              && !(this->_data[ind].state == Vazio)
              && (i < this->_capacity)){
            if(idel == -1)
                if(this->_data[ind].state == Removido)
                    idel = ind;
            i++;
            ind = (base + i) % this->_capacity;
        }

        if(this->_data[ind].equals(value))
            return ind;
        if(idel != -1)
            return idel;
        return ind;
    }

    //return se existe ou não
    bool exists(int value){
        return this->_data[search(value)].equals(value);
    }

};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

