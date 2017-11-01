
#include <list>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <SFML/Graphics.hpp>

#include "../libs/sortview.h"
#include "../libs/player.h"

static SortView sview;

void minimum_sort(std::vector<int> &vet){
    int tam = vet.size();
    for(int i = 0; i < tam/2; i++){
        int menor = i;
        int maior = i;
        for(int j = i + 1; j < tam-i; j++){
            sview.show(vet, {i,j, menor, maior, tam-i-1}, "byrrc");
            if(vet[j] < vet[menor]){
                menor = j;
            }else if(vet[j] > vet[maior]){
                maior = j;
            }
        }
        sview.show(vet, {i, menor, maior, tam-i-1}, "brrc");
        std::swap(vet[i], vet[menor]);
        if (maior == i)
            std::swap(vet[tam-1-i], vet[menor]);
        else
            std::swap(vet[tam-1-i], vet[maior]);
        sview.show(vet, {i, menor, maior, tam-i-1}, "brrc");

    }
}

void bubble_sort(std::vector<int> &vet){
    int tam = vet.size();
    for(int i = tam - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            sview.show(vet, {i, j, j + 1}, "rgb");
            if(vet[j] > vet[j + 1]){
                std::swap(vet[j], vet[j + 1]);
                sview.show(vet, {i, j, j + 1}, "rgb");
            }
        }
    }
}

void reverse_bubble_sort(std::vector<int> &vet){
    int tam = vet.size();
    for(int i = 0; i < tam - 1; i++){
        for(int j = tam - 1; j > i; j--){
            sview.show(vet, {i, j, j - 1}, "rgb");
            if(vet[j - 1] > vet[j]){
                std::swap(vet[j], vet[j - 1]);
                sview.show(vet, {i, j, j - 1}, "rgb");
            }
        }
    }
}

void insertion_sort(std::vector<int> &vet){
    int tam = vet.size();
    for(int i = 1; i < tam; i++){
        for(int j = i; j > 0; j--){
            if(vet[j - 1] < vet[j])
                break;
            std::swap(vet[j], vet[j - 1]);
            sview.show(vet, {i, j, j - 1}, "rgb");
        }
    }
}

template <class C, class T>
void insertListOrd(C& container, T& it_begin, T it_end, int value){
    if(value < *it_begin){
        it_begin = container.insert(it_begin, value);
        return;
    }
    for(T it = it_begin; it != it_end; it++){
        if(value < *it){
            container.insert(it, value);
            return;
        }
    }
    container.insert(it_end, value);
}

void insertionSort(std::vector<int> vet){
    std::list<int> lista(vet.begin(), vet.end());
    if(lista.size() == 1)
        return;
    std::list<int>::iterator it = std::next(lista.begin());
    int i = 1;
    while(it != lista.end()){
        auto value = *it;
        it = lista.erase(it);
        auto _begin = lista.begin();
        insertListOrd(lista, _begin , it, value);
        sview.show(std::vector<int>(lista.begin(), lista.end()),
        {i++}, "r");
    }
}

void intercala(std::vector<int>& vet, int b, int m, int e){
    std::vector<int> aux;
    aux.reserve(e - b);
    int x = b;
    int y = m;
    while((x != m) &&(y != e)){
        int *ganhador = (vet[x] < vet[y])? &x : &y;
        aux.push_back(vet[*ganhador]);
        *ganhador += 1;
        sview.show(aux);
        sview.show(vet, {b, m, e, x, y}, "rgbyc");
    }
    while(x != m){
        aux.push_back(vet[x++]);
        sview.show(aux);
        sview.show(vet, {b, m, e, x, y}, "rgbyc");
    }
    while(y != e){
        aux.push_back(vet[y++]);
        sview.show(aux);
        sview.show(vet, {b, m, e, x, y}, "rgbyc");
    }
    for(int i = 0; i < (int) aux.size(); i++)
        vet[i + b] = aux[i];
}

#include <algorithm>
void mergeSort(std::vector<int>& vet, int b, int e){
    if(e == b + 1)
        return;
    int m = (b + e) / 2;
    mergeSort(vet, b, m);
    mergeSort(vet, m, e);
    intercala(vet, b, m, e);
    //std::inplace_merge(vet.begin() + b,
                       //vet.begin() + m,
                       //vet.begin() + e);
    sview.set_faixa(b, e);
    sview.show(vet, {b, m, e}, "rgb");
}

void quickSort(std::vector<int>& vet, int b, int e){
    int pivo = vet[b];
    int i = b;
    int f = e;
    while(i <= f){
        while((vet[i] < pivo) && (i < e))
            i++;
        while((vet[f] > pivo) && (f > b))
            f--;
        if(i <= f)
            std::swap(vet[i++], vet[f--]);
    }
    if(f > b)
        quickSort(vet, b, f);
    if(e > i)
        quickSort(vet, i, e);
    sview.show(vet);
}

std::vector<int> init_vet(int qtd, int min, int max){
    std::vector<int> vet;
    vet.reserve(qtd);
    for(int i = 0; i < qtd; i++){
        vet.push_back(rand() % (max - min + 1) + min);
    }
    return vet;
}

int main_sorts(){
    srand(2);
    my_player->autoplay = false;
    sview.set_bar_view();
    sview.set_thickness(8);

    std::vector<int> vet = init_vet(70, 50, 300);

    quickSort(vet, 0, vet.size() - 1);

    my_player->wait();
    return 0;
}


int main(){
    main_sorts();
    return 0;
}

