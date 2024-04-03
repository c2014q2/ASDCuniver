using namespace std;

#include <iostream>
struct Node 
{
int value;
Node* next;
};

struct LinkedList
{
    
    Node* start;
    Node* end;
};

void addElementToEnd(LinkedList* list, int value)
{
    Node* node = new Node;
    node->value = value;
    node->next = nullptr;

    if (list->end!=nullptr)
    {
        list->end->next = node;
    }
    list->end = node;

    if (list->start == nullptr)
    {
        list->start = node;
    }

    //return node;
}

Node* addElementToStart(LinkedList* list, int value)
{
    Node* node = new Node;
    node->value = value;
    node->next = list->start;
    list->start = node;

    if(list->end == nullptr)list->end = node;
    
    return node;
}


void parcurgereLista(LinkedList* list)
{
    Node* currentNode = list->start;
    while (currentNode !=nullptr)
    {
        std::cout<<(currentNode->value)<<" ";
        currentNode = currentNode->next;

    }
}


int main()
{
    LinkedList list;
    list.start = nullptr;
    list.end = nullptr;
 
 addElementToEnd(&list,1);
 addElementToEnd(&list,2);
 addElementToEnd(&list,3);
 addElementToStart(&list,4);

 parcurgereLista(&list);


 return 0;
}