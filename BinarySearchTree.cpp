#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
        string info;
        Node *leftchild;
        Node *rightchild;

        // construcktor for the node class
        Node (string i, Node *l, Node *r){
            info = i;
            leftchild = l;
            rightchild = r;
        }
};

class BinaryTree
{
    public:
    Node *ROOT;

    BinaryTree()
    {
        ROOT = NULL; //initializing ROOT to NULL
    }

    //insert a node in the binary search tree
        void insert(string elemen){
            Node *newNode = new Node (elemen, NULL, NULL);
            newNode -> info = elemen;
            newNode -> leftchild = NULL;
            newNode -> rightchild = NULL;

            Node *parent = NULL;
            Node *currentNode = NULL;

            search(elemen, parent, currentNode);

            if (parent == NULL){
                ROOT = newNode;
                return;
            }

            if (elemen < parent -> info){
                parent -> leftchild = newNode;
                return;
            }
            else if (elemen > parent -> info){
                parent -> rightchild = newNode;
            }
        }



