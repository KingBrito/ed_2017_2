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

const char PAREDE = 'k';
const char VAZIO = 'w';
const char MIGALHA = 'y';
const char CAMINHO = 'c';

vector<Par> delta_par = {Par(-1, 0), Par(0, -1), Par(1, 0), Par(0, 1)};

//MAPA DE CORES
//r red
//g green
//b blue
//m magenta
//c cyan -
//y yellow
//w white
//k black

vector<Par> shuffle(vector<Par> vet){
    std::random_shuffle(vet.begin(), vet.end());
    return vet;
}

int contar_viz_abertos(matchar &mat, Par par){
    int cont = 0;
    for(auto d : delta_par){
        auto viz = par + d;

        if(!mat.is_inside(viz))
            cont++;
        else if(mat.get(viz) == VAZIO)
            cont++;
    }
    return cont;
}

void criar_lab(matchar &mat, Par par) {
    if(!mat.is_inside(par))
        return;
    if(mat.get(par) != PAREDE)
        return;
    if(contar_viz_abertos(mat, par) > 1)
        return;
    mat.get(par) = VAZIO;
    mat_draw(mat);//desenha a matriz
    mat_focus(par, 'g');//faz uma bolinha em par
    ed_show();

    for(auto d : shuffle(delta_par)) {
        auto viz = par + d;
        criar_lab(mat, viz);
    }
}

matchar criar_lab(){

    //cria uma matriz de caracteres de 15 linhas por 20 colunas, e preenche todos os elementos
    //com 'y'
    matchar mat(15, 25, PAREDE);

    //chama o metodo de desenho livre onde a cor primeira default eh branca

    Par inicio = mat_get_click(mat, "ponto para iniciar");
    criar_lab(mat, inicio);

    return mat;
}




void draw(matchar &mat, Par inicio, Par fim, Par par){
    mat_draw(mat);//desenha a matriz
    mat_focus(inicio, 'g');//faz uma bolinha em par
    mat_focus(fim, 'r');//faz uma bolinha em par
    mat_focus(par, 'm');//faz uma bolinha em par
    ed_show();//mostra na tela
}

bool rec_achar(matchar &mat, Par inicio, Par fim, Par par, list<Par>& path)
{
    //PONTOS DE PARADA
    if(!mat.is_inside(par))//se estiver fora da matriz
        return false;
    if(mat.get(par) != VAZIO)//se nao for arvore
        return false;

    if(par == fim){
        mat.get(par) = CAMINHO;
        draw(mat, inicio, fim, par);
        path.push_front(par);
        return true;
    }

    //ACAO
    mat.get(par) = MIGALHA;

    //DESENHO
    draw(mat, inicio, fim, par);

    //RECURSAO
    for(auto desl : shuffle(delta_par)){
        auto viz = par + desl;
        if(rec_achar(mat, inicio, fim, viz, path)){
            mat.get(par) = CAMINHO;
            path.push_front(par);
            draw(mat, inicio, fim, par);
            return true;
        }
    }
    mat.get(par) = 'b';
    draw(mat, inicio, fim, par);
    return false;
}

int main(){

    //cria uma matriz de caracteres de 15 linhas por 20 colunas, e preenche todos os elementos
    //com 'y'
    matchar mat = criar_lab();

    //chama o metodo de desenho livre onde a cor primeira default eh branca

    Par inicio = mat_get_click(mat, "ponto para iniciar");
    Par fim = mat_get_click(mat, "ponto para terminar");
    list<Par> path;
    rec_achar(mat, inicio, fim, inicio, path);//chama a função recursiva
    for(auto par : path)
        cout << par.l << " " << par.c << endl;

    ed_lock();//impede que termine abruptamente

    return 0;
}


