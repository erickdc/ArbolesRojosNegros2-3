#include "TwoTreeThree.h"

static int screenWidth= 1024;
static int screenHeight = 768 ;

TwoTreeThree::TwoTreeThree()
{
    root = new Node(-1,((screenWidth/2)-Node::radius),50);
    root->child[0] = new Node(-1,((screenWidth/2)-Node::radius),50);
    root->child[0]->parent = root;
}

TwoTreeThree::~TwoTreeThree()
{
    //dtor
}

bool TwoTreeThree::insert(int data){
    Node *newNode = new Node(data,((screenWidth/2)-Node::radius),50);
    Node *spot = root->child[0];

    if (spot->child[0] == NULL) {
        // First insertion
        newNode->parent = spot;
        spot->child[0] = newNode;
    }
    else {
        spot = findSpot(spot, data);
        if (spot == NULL) return false;

        spot->insert(new Node(data,((screenWidth/2)-Node::radius),50), data);
    }

    return true;
}

void TwoTreeThree::print(){
    print(root->child[0]);
    //cout << endl;
}

Node* TwoTreeThree::findSpot(Node *node, int data){
    if (node == NULL) return NULL;

    while (!node->isLeaf()) {
        if (node->key[0] == data || node->key[1] == data)
            return NULL;
        if (node->key[0] == -1 || data < node->key[0])
            node = node->child[0];
        else if (node->key[1] == -1 || data < node->key[1])
            node = node->child[1];
        else
            node = node->child[2];
    }

    if (node->key[0] == data) return NULL;
    return node->parent;
}

void TwoTreeThree::print(Node *node, int tabs){
    /*for (int i = 0; i < tabs; ++i) {
        cout << "\t";
    }

    if (node == NULL) {
        cout << "`--> NULL" << endl;
        return;
    }

    cout << "`--> " << node->sibNumber()
         << ": ( " << node->key[0] << ", " << node->key[1] << ")" << endl;*/

    if (!node->isLeaf()) {
        //++tabs;
        print(node->child[0], tabs);
        print(node->child[1], tabs);
        print(node->child[2], tabs);
    }
}
