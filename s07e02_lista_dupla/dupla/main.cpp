#include <iostream>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * prev;
    Node * next;
    Node(int value = 0,
         Node * prev = nullptr,
         Node * next = nullptr){
        this->value = value;
        this->prev = prev;
        this->next = next;
    }
};

class DList;//forward declaration

class It {
private:
    Node * node;
public:
    It(Node * node){
        this->node = node;
    }
    void operator++(int){
        node = node->next;
    }
    void operator--(int){
        node = node->prev;
    }
    int& operator*(){
        return node->value;
    }
    bool operator!=(It other){
        return node != other.node;
    }

    friend class DList;
};

struct DList{
    Node * head;
    Node * tail;
    DList(){
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }

    ~DList(){
        clear(begin(), end());
        delete(head);
        delete(tail);
    }

    //gerar a string que corresponde a estrutura de dados
    string serialize() {
        stringstream ss;
        auto node = head->next;
        while(node != tail){
            ss << node->value << " ";
            node = node->next;
        }
        return ss.str();
    }

    DList(string serial){
        head = new Node;
        tail = new Node;
        auto last = head;
        stringstream ss(serial);
        int value;
        while(ss >> value){
            auto node = new Node(value, last);
            last->next = node;
            last = node;
        }
        last->next = tail;
        tail->prev = last;
    }

    //remove de inicio ate fim, nao incluindo fim
    void clear(It inicio, It fim){
        while(inicio != fim)
            inicio = erase(inicio);
    }

    void insert(It it, int value){
        Node * pos = it.node;

        auto node = new Node(value, pos->prev, pos);
        pos->prev->next = node;
        pos->prev = node;
    }

    void push_back(int value){
        insert(It(tail), value);
    }

    void push_front(int value){
        insert(It(head->next), value);
    }

    //begin primeiro nó valido
    It begin(){
        return It(head->next);
    }

    //um depois do ultimo valido
    It end(){
        return It(tail);
    }

    int size(){
        int cont = 0;
        auto node = head->next;
        while(node != tail){
            cont++;
            node = node->next;
        }
        return cont;
    }

    It find(int value){
        auto node = head->next;
        while(node != tail){
            if(node->value == value)
                return It(node);
            node = node->next;
        }
        return It(tail);
    }

    //apaga it e retorna quem ficou no lugar dele
    It erase(It it){
        auto node = it.node;
        auto prox = node->next;
        node->next->prev = node->prev;
        node->prev->next = node->next;
        delete(node);
        return prox;
    }

    void pop_front(){
        if(head->next != tail)
            erase(It(head->next));
    }

    void pop_back(){
        if(head->next != tail)
            erase(It(tail->prev));
    }
    bool isEmpty(){
        return head->next == tail;
    }

    int& front(){
        return head->next->value;
    }
    int& back(){
        return tail->prev->value;
    }

    string toString(){
        string saida = "[" + this->serialize();
        if(saida.size() > 1)
            saida.back() = ']';
        else
            saida += "]";
        return saida;
    }
};

#include <cstring>
#include <fstream>
void fluxos_exemplos()
{
    {
        stringstream ss;
        ss << "rapadura " << "eh " << 5 << " conto" << endl;
        string comida, verbo;
        int valor;
        ss >> comida >> verbo >> valor;

        cout << comida << verbo << valor << endl;
    }
    {
        char nome[50];
        float valor;
        float qtd;
        char tipo;

        sscanf("banana 1.5 5.0 k", "%s %f %f %c",  nome, &valor, &qtd, &tipo);
        cout << nome << " " << valor << " " << qtd << " " << tipo << endl;
    }
    {
        string nome;
        float valor;
        float qtd;
        char tipo;

        stringstream("banana 1.5 5.0 k") >> nome >> valor >> qtd >> tipo;
        cout << nome << " " << valor << " " << qtd << " " << tipo << endl;
    }

    {
        string nome;
        float valor;
        float qtd;
        char tipo;

        stringstream ss("banana nanica madura organica transgenica;1.5 5.0 k");
        getline(ss, nome, ';');
        ss >> valor >> qtd >> tipo;
        cout << nome << " " << valor << " " << qtd << " " << tipo << endl;
        cout << ss.str() << endl;
    }

    {//isso nao funciona, nao tente isso em casa
        fstream ofs("banana.txt");
        ofs << "Comprei uma banana madura " << "tava pôde " << " bichada" << endl;
        ofs.close();
    }
}

int main()
{
    DList list;
    for(int i = 1; i < 10; i++){
        list.push_back(i);
        list.push_front(i);
    }

    auto it = list.find(1);
    it++;
    list.insert(it, 0);

    it = list.find(0);
    it = list.erase(it);
    list.clear(it, list.end());


    for(auto it = list.begin(); it != list.end(); it++){
        cout << (*it) << " ";
    }

    cout << endl;

    string serial = list.serialize();
    cout << serial << endl;

    DList novaList(serial);
    cout << novaList.toString() << endl;

    DList lvazia;
    cout << lvazia.toString() << endl;

    return 0;
}








