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

        //this function searches the current node of the spesific node
        //as well as the current node of its parent
        void search(string element, Node *&parent, Node *&currentNode){
        currentNode = ROOT;
        parent = NULL;

        while ((currentNode != NULL) &&
                (currentNode->info != element))
        {
            parent = currentNode;

            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }
        void inorder(Node *ptr){
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }
    }
        void preorder(Node *ptr){
            if (ROOT == NULL){
                cout << "Tree is empty";
                return;
            }

            if (ptr != NULL){
                cout << ptr -> info << " ";
                preorder(ptr->leftchild);
                preorder(ptr->rightchild);
            }
        }
        void postorder(Node *ptr){
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << " ";
        }
    }

};

int main(){
    BinaryTree obj;

    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. perform inorder traversal" << endl;
        cout << "3. perform preorder traversal" << endl;
        cout << "4. perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice: ";

        char ch;
        cin >> ch;



