#include <iostream>
#include <cstdlib>//rand e srand
#include <ctime>//time

using namespace std;

class Node{
public:
    int value;
    Node * left;
    Node * right;
    Node(int value = 0, Node * l = nullptr, Node * r = nullptr){
        this->value = value;
        this->left = l;
        this->right = r;
    }
};


//class List{

//    Node ** mfind(Node ** elo, int value){
//        Node * node = *elo;
//        if(node == nullptr)
//            return elo;
//        if(node->value == value)
//            return elo;
//        return mfind(&node->next, value);
//    }

//    void remove(int value){
//        auto elo = mfind(&head, value);
//        auto node = *elo;
//        if(node == nullptr)
//            return;
//        *elo = (*elo)->next;
//        delete(node);
//    }
//};



class Tree{
public:
    Node * root {nullptr};

    Tree(){

    }

    Node ** mfind(Node ** elo, int value){
        Node * node = *elo;
        if(node == nullptr)
            return elo;
        if(node->value == value)
            return elo;
        if(value > node->value)
            return mfind(&node->right, value);
        return mfind(&node->left, value);
    }

    void inserir(int value){
        Node ** elo = mfind(&root, value);
        if(*elo == nullptr)
            *elo = new Node(value);
    }

    void _remove(Node ** elo){
        auto node = *elo;
        if(node->left == nullptr && node->right == nullptr){
            *elo = nullptr;
            delete node;
            return;
        }
        if(node->left == nullptr){
            *elo = node->right;
            delete node;
            return;
        }
        if(node->right == nullptr){
            *elo = node->left;
            delete node;
            return;
        }
        Node ** elo_ant = &(node)->left;
        Node * antecessor = *elo_ant;
        while(antecessor->right != nullptr){
            elo_ant = &antecessor->right;
            antecessor = *elo_ant;
        }
        int value_ant = antecessor->value;
        _remove(elo_ant);
        node->value = value_ant;
    }

    void remove(int value){
        Node **elo = mfind(&root, value);
        if(*elo != nullptr)
            _remove(elo);
    }

    Node * clone(Node * other){
        if(other == nullptr)
            nullptr;
        Node * node = new Node(other->value);
        node->left = clone(node->left);
        node->right = clone(node->right);
        return node;
    }

    _mata_tudo(Node){

    }

    Node _remove(Node * node, int value){
        if(null)
            null
                    if(quem vai moorer)
                    mata_tudo(node)
                    return null
                    _remove(left)
                    right
                    return node
    }

    ~Tree(){

    }

    Tree(Tree other){
        root = clone(other->root);
    }

    Tree(string serial){
        ?
    }

    void _serialize(Node * node, stringstream& ss){
        if(node == nullptr){
            ss << " #";
            return;
        }
        ss << " " + node->value;
        _serialize(node->left, ss);
        _serialize(node->right, ss);
    }

    string serialize(){
        stringstream ss;
        _serialize(root, ss);
        return ss.str();
    }

    bool requals(Node * node, Node * other){
        if(node == nullptr && other == nullptr)
            return true;
        if(node != nullptr && other != nullptr)
            if(node->value == other->value)
                return requals(node->left, other->left) &&
                        requals(node->right, other->right);
        return false;
    }

    bool equals(Tree other){
        return requals(root, other.root);
    }

    Node * _pushRand(Node * node, int value){
        if(node == nullptr)
            return new Node(value);
        if(rand() % 2 == 0)
            node->left = _pushRand(node->left, value);
        else
            node->right = _pushRand(node->right, value);
        return node;
    }

    void pushRand(int value){
        root = _pushRand(root, value);
    }

    void nshow(Node * node = nullptr, int nivel = -1){
        if(nivel == -1){
            node = root;
            nivel = 0;
        }
        if(node == nullptr){
            cout << string(2 * nivel, ' ') <<  "#" << endl;
            return;
        }
        if(node->left != nullptr || node->right != nullptr)
            nshow(node->left, nivel + 1);
        cout << string(2 * nivel, ' ') <<  node->value << endl;
        if(node->left != nullptr || node->right != nullptr)
            nshow(node->right, nivel + 1);
    }

    int sum(Node * node){
        if(node == nullptr)
            return 0;
        return node->value + sum(node->left) + sum(node->right);
    }

    int menor(Node * node){
        if(node->left != nullptr && node->right != nullptr)
            return std::min(node->value,
                            std::min(menor(node->left), menor(node->right)));
        if(node->left != nullptr)
            return std::min(node->value, menor(node->left));
        if(node->right != nullptr)
            return std::min(node->value, menor(node->right));
        return node->value;
    }

    Node * menor_xik(Node * node){
        if(node == nullptr)
            return nullptr;
        auto mleft = menor(node->left);
        auto mright = menor(node->right);
        Node * nmenor = node;
        if(mleft  && (mleft->value < nmenor->value))
            nmenor = mleft;
        if(mright && (mright->value < nmenor->value))
            nmenor = mright;
        return nmenor;
    }

    int nivel(Node * node, Node * procurado){
        if(node == nullptr)
            return 0;
        if(node == procurado)
            return 1;
        auto aux = std::max(altura(node->left), altura(node->right));
        return (aux ? aux + 1 : 0);
    }

    int altura(Node * node){
        if(node == nullptr)
            return 0;
        return 1 + std::max(altura(node->left), altura(node->right));

    }

    Node * find(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value)
            return node;
        auto aux = find(node->left, value);
        if(aux)
            return aux;
        return find(node->right, value);

    }
};

int main()
{
    Tree tree;
    while(true){
        int value;
        cin >> value;

        tree.pushRand(value);
        tree.nshow();
    }

    return 0;
}


digite comando:
ins 4
del 3
somar
menor









