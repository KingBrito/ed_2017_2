#include <iostream>
using namespace std;

struct Vector{
    int qtd;
    int capacidade;
    int* data;

    Vector(int capacidade){
        qtd = 0;
        this->capacidade = capacidade;
        data = new int[capacidade];
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
};
int main()
{
    Vector vet(4), vet2(4);

    vet.push_back(0);
    vet.push_back(1);
    vet.push_back(2);
    vet.push_back(3);
    vet2.push_back(0);
    vet2.push_back(1);
    vet2.push_back(2);
    vet2.push_back(4);

    cout.operator << ((vet.operator == (vet2)) << endl;

    //for(int i = 0; i < vet.size(); i++){
    //    cout << vet.operator[](i) << endl;
    //}



    return 0;

}










