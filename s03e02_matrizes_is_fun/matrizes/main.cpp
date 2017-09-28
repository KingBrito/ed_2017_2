#include "libs/ed_base.h"
#include "libs/ed_mat.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <algorithm>

using namespace std;

int nlinhas = 20;
int ncolunas = 35;

//MAPA DE CORES
//r red
//g green
//b blue
//m magenta
//c cyan -
//y yellow
//w white
//k black

void showMat(matriz<char>& matc, matriz<int>& mati, Par inicio, Par fim, Par par){
    mat_draw(matc);//desenha a matriz
    mat_focus(inicio, 'm');
    mat_focus(fim, 'b');
    mat_focus(par, 'y');//faz uma bolinha em par
    mat_draw(mati);
    ed_show();//mostra na tela
}

vector<Par> get_vizinhos(Par pos){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(pos.l, pos.c - 1));
    vizinhos.push_back(Par(pos.l - 1, pos.c));
    vizinhos.push_back(Par(pos.l, pos.c + 1));
    vizinhos.push_back(Par(pos.l + 1, pos.c));
    return vizinhos;
}

vector<Par> shuffle(vector<Par> vet){
    for(int i = 0; i < (int) vet.size(); i++)
        std::swap(vet[i], vet[rand() % vet.size()]);
    return vet;
}

void queimar(matchar &matc, matriz<int>& mati, Par inicio, Par fim, Par par, int nivel){
    //PONTOS DE PARADA
    if(!matc.is_inside(par))//se estiver fora da matriz
        return;

    if(matc.get(par) != 'g')//se nao for arvore
        return;

    //ACAO
    matc.get(par) = 'r';
    mati.get(par) = nivel;

    //DESENHO
    showMat(matc, mati, inicio, fim, par);

    //RECURSAO
    for(Par viz : shuffle(get_vizinhos(par)))
        queimar(matc, mati, inicio, fim, viz, nivel + 1);

    //ACAO APOS A RECURSAO
    matc.get(par) = 'c';

    //DESENHO
    showMat(matc, mati, inicio, fim, par);
}


int main(){
    srand(time(NULL));
    //cria uma matriz de caracteres de 15 linhas por 20 colunas, e preenche todos os elementos
    //com 'y'
    matriz<char> matc(nlinhas, ncolunas, 'g');
    matriz<int>  mati(nlinhas, ncolunas, 0);


    //chama o metodo de desenho livre onde a cor primeira default eh branca
    mat_paint_brush(matc, "wg");

    Par inicio = mat_get_click(matc, "escolha uma arvore para iniciar");
    Par fim = mat_get_click(matc, "escolha uma arvore para terminar");

    queimar(matc, mati, inicio, fim, inicio, 0);//chama a função recursiva

    ed_lock();//impede que termine abruptamente

    return 0;
}


