#include <iostream>
#include <sstream>
using namespace std;

template <class T>
struct Node{
    T value;
    Node * prev;
    Node * next;
    Node(T value, Node * prev = nullptr, Node * next = nullptr){
        this->value = value;
        this->prev = prev;
        this->next = next;
    }

    Node(Node * prev = nullptr, Node * next = nullptr){
        this->prev = prev;
        this->next = next;
    }
};

template<class T>
class DList; //forward declaration

template <class T>
class It {
private:
    Node<T> * node;
public:
    It(Node<T> * node){
        this->node = node;
    }
    void operator++(int){
        node = node->next;
    }
    void operator--(int){
        node = node->prev;
    }
    T& operator*(){
        return node->value;
    }
    bool operator!=(It<T> other){
        return node != other.node;
    }
    bool operator==(It<T> other){
        return node == other.node;
    }

    friend class DList<T>;
};

template <class T>
struct DList {
    Node<T> * head;
    Node<T> * tail;
    DList(){
        head = new Node<T>;
        tail = new Node<T>;
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
        head = new Node<T>();
        tail = new Node<T>();
        auto last = head;
        stringstream ss(serial);
        T value;
        while(ss >> value){
            auto node = new Node<T>(value, last);
            last->next = node;
            last = node;
        }
        last->next = tail;
        tail->prev = last;
    }

    //remove de inicio ate fim, nao incluindo fim
    void clear(It<T> inicio, It<T> fim){
        while(inicio != fim)
            inicio = erase(inicio);
    }

    void insert(It<T> it, T value){
        Node<T> * pos = it.node;

        auto node = new Node<T>(value, pos->prev, pos);
        pos->prev->next = node;
        pos->prev = node;
    }

    void push_back(T value){
        insert(It<T>(tail), value);
    }

    void push_front(int value){
        insert(It<T>(head->next), value);
    }

    //begin primeiro nó valido
    It<T> begin(){
        return It<T>(head->next);
    }

    //um depois do ultimo valido
    It<T> end(){
        return It<T>(tail);
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

    It<T> find(T value){
        auto node = head->next;
        while(node != tail){
            if(node->value == value)
                return It<T>(node);
            node = node->next;
        }
        return It<T>(tail);
    }

    //apaga it e retorna quem ficou no lugar dele
    It<T> erase(It<T> it){
        auto node = it.node;
        auto prox = node->next;
        node->next->prev = node->prev;
        node->prev->next = node->next;
        delete(node);
        return prox;
    }

    void pop_front(){
        if(head->next != tail)
            erase(It<T>(head->next));
    }

    void pop_back(){
        if(head->next != tail)
            erase(It<T>(tail->prev));
    }
    bool isEmpty(){
        return head->next == tail;
    }

    T& front(){
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


int main()
{
    DList<int> list;
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

    DList<int> novaList(serial);
    cout << novaList.toString() << endl;

    DList<int> lvazia;
    cout << lvazia.toString() << endl;

    return 0;
}

#include <list>
class Ambiente{
    list<char> texto;
    list<char>::iterator cursor;
    Ambiente(){
        cursor = texto.end();
    }

    void ler(){
        char c;
        while(c != '!'){
            cin >> c;
            if((c >= 'a') && (c <= 'z'))
                texto.insert(cursor, c);

        }
    }
};







