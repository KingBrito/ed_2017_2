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

class Tree{
public:
    Node * root {nullptr};

    Tree(){

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

    void nshow(Node * node, int nivel = 0){

        if(node == nullptr){
            cout << string(2 * nivel, ' ') <<  "#" << endl;
            return;
        }
        //if(node->left != nullptr || node->right != nullptr)
            nshow(node->left, nivel + 1);
        cout << string(2 * nivel, ' ') <<  node->value << endl;
        //if(node->left != nullptr || node->right != nullptr)
            nshow(node->right, nivel + 1);
    }











    void fshow(Node * node, int nivel = 0, ostream & fout = std::cout){
        int tab = 4;
        if(node == nullptr){
            fout << string(tab * nivel, ' ') << "#" << endl;
            return;
        }
        fout << string(tab * nivel, ' ') << node->value << endl;
        fshow(node->left, nivel + 1, fout);
        fshow(node->right, nivel + 1, fout);
    }

    void _show(Node * node, string her, Node * ref = nullptr, int value = 0){
        if(node != nullptr)
            if((node->left != nullptr) || (node->right != nullptr))
                _show(node->left, her + "l");

        for(int i = 0; i < ((int)her.size() - 1); i++){
            if(her[i] != her[i + 1])
                cout << "│   ";
            else
                cout << "    ";
        }
        if(her != ""){
            if(her.back() == 'l')
                cout << "<───";
            else
                cout << ">───";
        }
        if(node == nullptr){
            cout << "#" << endl;
            return;
        }
        cout << node->value;
        if(ref == node)
            cout << "(" << value << ")";
        cout << endl;

        if((node->left != nullptr) || (node->right != nullptr))
            _show(node->right, her + "r");
    }

    void show(Node * ref = nullptr, int value = 0){
        cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVV" << endl;
        _show(root, "", ref, value);
        cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl << endl;
    }
};

int main()
{
    Tree tree;
    while(true){
        int value;
        cin >> value;
        tree.pushRand(value);
        tree.nshow(tree.root);
    }

    return 0;
}













