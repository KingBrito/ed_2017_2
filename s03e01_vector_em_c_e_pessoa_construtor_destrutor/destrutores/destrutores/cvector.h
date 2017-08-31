#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
#include <cstdlib>

using namespace std;

struct Vector{
    int * data;//8 bytes
    int capacidade;//4 bytes
    int qtd;//4bytes
};

Vector * vector_create(int capacidade){
    Vector * vector = (Vector *) malloc(sizeof(Vector));
    vector->data = (int *) malloc(capacidade * sizeof(int));
    vector->capacidade = capacidade;
    vector->qtd = 0;
    return vector;
}

void vector_push(Vector * vector, int value){
    if(vector == NULL)
        return;
    if(vector->qtd == vector->capacidade)
        return;
    vector->data[vector->qtd] = value;
    vector->qtd += 1;
}

void vector_pop(Vector * vector){
    if(vector->qtd == 0)
        return;
    vector->qtd -= 1;
}

void vector_destroy(Vector * vector){
    free(vector->data);
    free(vector);
}

void vector_show(Vector * vector){
    cout << "[ ";
    for(int i = 0; i < vector->qtd; i++)
        cout << vector->data[i] << " ";
    cout << "]\n";
}

void mainVector(){
    Vector * vector = vector_create(10);
    for(int i = 10; i >= 0; i--)//nao deve inserir o zero
        vector_push(vector, i);

    vector_show(vector);
}



#endif // CVECTOR_H











