#include <stdio.h>
#include <iostream>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int data;

    Node(){
        left = NULL;
        right = NULL;
    }
};

class HeapTree{
    public:
    Node* root;
    HeapTree(){
        root = NUll;
    }

    void insert_node(Node* root, int new_key){

    }

    void delete_node(Node* root, int key){

    }

    void search(Node* root, int key){

    }

};

int main()
{
    printf("Hello World");
    Node tree = Node();

    return 0;
}
