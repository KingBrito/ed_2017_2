#include <iostream>
#include <list>
using namespace std;

void rodar(list<int>& lista){
    lista.push_back(lista.front());
    lista.pop_front();
}

int main(){
    int n = 0, x = 0;
    cout << "Digite o valor de N e o valor de X" << endl;
    cin >> n >> x;
    list<int> lista;
    for(int i = 1; i <= N; i++)
        lista.push_back(i);
    while(lista.front() != x)
        rodar(lista);
    while(lista.size() != 1){
        rodar(lista);
        lista.pop_front();
    }

    return 0;
}











