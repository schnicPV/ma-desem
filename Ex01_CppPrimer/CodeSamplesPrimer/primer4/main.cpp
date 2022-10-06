#include <iostream>

using namespace std;
struct Node
{
    int val;
    Node* next;
};

int main()
{
    //pointer to first element
    Node* first = NULL;
    Node* pNode = NULL;
    //build a list with 5 nodes
    for (int i=100; i<=500; i+=100)
    {
        pNode = new Node;
        pNode->val = i;
        pNode->next = first;
        first = pNode;
    }
    //display the list
    pNode = first;
    while (pNode /*!= NULL*/)
    {
        cout << pNode->val << endl;
        pNode = pNode->next;
    }
    //remove the list
    while (pNode /*!= NULL*/)
    {
        pNode = first;
        first = pNode->next;
        delete pNode;

    }
    return 0;
}


