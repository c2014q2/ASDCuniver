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


void printareLista(LinkedList* list)
{
    Node* currentNode = list->start;
    while (currentNode !=nullptr)
    {
        std::cout<<(currentNode->value)<<" ";
        currentNode = currentNode->next;

    }
}

Node* insertAfter(LinkedList* list, Node* nodeBefore, int value)  //nu sunt sigur daca am inteles conditia corect
{
    
    Node* node = new Node;
    node->value = value;
    node->next = nullptr;
    if (nodeBefore == nullptr)
    {
        node->next = list->start;
        list->start = node;
    }
    else 
    {
        node->next = nodeBefore->next;
            nodeBefore->next = node;
    }


    return node;
}

void deleteAfter(LinkedList* list, Node* nodeBefore)  
{
    if (nodeBefore == nullptr)
    {
        if (list->start != nullptr) 
        {
            Node* container = list->start;
            list->start = list->start->next;
            delete container;
        }
    }
    else
    { 
        if (nodeBefore->next != nullptr)
        {
            Node* container = nodeBefore->next;
            nodeBefore->next = nodeBefore->next->next;
            if (container == list->end) list->end = nodeBefore;
            delete container;
       
        }

    }
      
}





Node* accesareElementDupaIndexInLista(LinkedList* list, int index)
{
    Node* currentNode = list->start;
        for(int i = 0; i<index ; i++)
        {
            currentNode = currentNode->next;
        }
   // std::cout<<(currentNode->value);
    return currentNode;
}


int main()
{   
    Node* test;
    LinkedList list;
    list.start = nullptr;
    list.end = nullptr;
 
 addElementToEnd(&list,1);
 addElementToEnd(&list,2);
 addElementToEnd(&list,3);
 addElementToStart(&list,4);

 Node* index0 = accesareElementDupaIndexInLista(&list, 0);
insertAfter(&list, index0, 6 );
 
deleteAfter(&list, index0);
 printareLista(&list);
 
 return 0;
}