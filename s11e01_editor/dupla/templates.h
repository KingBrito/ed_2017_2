#ifndef TEMPLATES_H
#define TEMPLATES_H

class HotDog{

public:
    string salsicha;
    string pao;
    HotDog(string salsicha, string pao){
        this->salsicha = salsicha;
        this->pao = pao;
    }

    HotDog operator+(HotDog other){
        return HotDog(salsicha + other.salsicha, string("Big") + pao);
    }
};

ostream& operator<<(ostream &os, HotDog hd){
    os << "Pao: " << hd.pao << ", " << "Recheio: " << hd.salsicha;
    return os;
}

template <class Coisa>
Coisa somaDois(Coisa um, Coisa dois){
    return um + dois;
}

#include <vector>
template <class T>
ostream& operator<<(ostream &os, vector<T> vetor){
    for(auto elem : vetor)
        os << elem << " ";
    return os;
}

#include <vector>
template <class T>
string join(vector<T> coisas, string delimit){
    stringstream ss;
    for(int i = 0; i < (int) coisas.size() - 1; i++)
        ss << coisas[i] << delimit;
    ss << coisas.back();
    return ss.str();
}


#include <sstream>
#include <vector>
int main_template(){
    vector<int> vet;
    stringstream ss;
    ss << HotDog("ovo", "pao");
    cout << ss.str();
    cout << somaDois(1, 2) << endl;
    cout << somaDois(string("um "), string("dois")) << endl;
    cout << somaDois(HotDog("calabresa", "italiano"), HotDog("apimentada", "parmesao")) << endl;

    vector<int> vet2 = { 1, 2, 3, 4, 5, 6, 7, 8};
    cout << join(vet2, ", ") << endl;
    return 0;
}

#endif // TEMPLATES_H

