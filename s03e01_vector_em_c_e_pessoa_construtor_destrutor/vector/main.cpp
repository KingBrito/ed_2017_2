#include <iostream>
using namespace std;

class Vector{
    int qtd;
    int capacidade;
    int* data;
public:

    Vector(int capacidade){
        qtd = 0;
        this->capacidade = capacidade;
        data = new int[capacidade];
    }
    ~Vector(){
        delete [] data;
    }

    void duplicate(){
        int * data2 = data;
        data pede o dobro de memoria
        copia de data2 para data
        desaloca data2
        atualiza capacidade
    }

    void push_back(int value){
        if(qtd == capacidade)
            return;
        data[qtd] = value;
        qtd++;
    }
    void pop_back(){
        if(qtd == 0)
            return;
        qtd--;
    }
    int& front(){
        static int dummy = 0;
        if(qtd >= 1)
            return data[0];
        cerr << "acessando posição invalida." << endl;
        return dummy;
    }
    int& back(){
        static int dummy = 0;
        if(qtd >= 1)
            return data[qtd-1];
        cerr << "acessando posição invalida." << endl;
        return dummy;
    }
    int& get(int indice){
        static int dummy = 0;
        if((indice >= 0) && (indice < qtd))
            return data[indice];
        cerr << "acessando posição invalida." << endl;
        return dummy;
    }

    int& operator[](int indice){
        return get(indice);
    }

    int size(){
        return qtd;
    }

    bool operator == (Vector& other){
        if(qtd != other.qtd)
            return false;
        for(int i = 0; i < qtd; i++)
            if (data[i] != other.data[i])
                return false;
        return true;
    }
    void show(){
        cout << "[ ";
        for(int i = 0; i < qtd; i++)
            cout << data[i] << " ";
        cout << "]\n";
    }
};

int main()
{
    Vector vec(5);
    string op = "";
    while(op != "fim"){
        cout << "digite comando ou help: ";
        cin >> op;
        if(op == "help"){
            cout << "show" << endl
                 << "push $value" << endl
                 << "pop" << endl;
        }
        if(op == "show"){
            vec.show();
        }
        if(op == "push"){
            int value;
            cin >> value;
            vec.push_back(value);
            vec.show();
        }
        if(op == "pop"){
            vec.pop_back();
            vec.show();
        }

    }
    return 0;
}










