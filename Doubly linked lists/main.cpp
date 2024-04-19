using namespace std;

#include <iostream>
struct Node 
{
int value;
Node* next;
Node* back;
};

struct LinkedList
{
    
    Node* start;
    Node* end;
};

struct FindNodeResult
{
    Node* behind;
    Node* node;

};

void addElementToEnd(LinkedList* list, int value)
{
    Node* node = new Node;
    node->value = value;
    node->next = nullptr;

    if (list->end!=nullptr)
    {
        node->back = list->end;
        list->end->next = node;
    }
    list->end = node;

    if (list->start == nullptr)
    {
        list->start = node;
        node->back = nullptr;
        
    }
}



Node* addElementToStart(LinkedList* list, int value)
{
    Node* node = new Node;
    node->value = value;
    node->next = list->start;
    node->back = nullptr;
    list->start = node;

    if(list->end == nullptr)list->end = node;
    
    return node;
}



Node* insertAfter(LinkedList* list, Node* nodeBefore, int value)  //nu sunt sigur daca am inteles conditia corect
{
    
    Node* node = new Node;
    node->value = value;
    node->next = nullptr;
    node->back = nodeBefore;
    if (nodeBefore == nullptr)
    {
        node->next = list->start;
        list->start = node;
    }
    else 
    {
        node->next = nodeBefore->next;
        nodeBefore->next->back = node;
        nodeBefore->next = node;
      
    }


    return node;
}

Node* insertBefore(LinkedList* list, Node* nodeAfter, int value)

{
    Node* node = new Node;
    node->value = value;
    node->next = nodeAfter;
    node->back = nullptr;

    if (nodeAfter == nullptr)
    {
        node->next = list->start;
        list->start = node;
    }
    else 
    {
       
        node->back = nodeAfter->back;
        nodeAfter->back->next = node;
        nodeAfter->back = node;
    }


    return node;
}


FindNodeResult find (LinkedList* list, int value)
{
    Node* currentNode = list->start;
    
    bool found = false;
    
    while (currentNode !=nullptr)
    {
        if (currentNode->value == value)
        {

            found = true;
            break;
        }
        
        currentNode = currentNode->next;
    }

    if (found)
    { 
        if (currentNode->back == nullptr)
        {
            std::cout<<"Elementul a fost gasit in primul nod din lista"<<endl;
            
        }
        else 
        {
            std::cout<<"Elementul a fost gasit!";
        }

        return {currentNode->back, currentNode};

    }
    else 
    {
        std::cout<<"Elementul nu a fost gasit in nodurile din lista!";
    }
}


void remove(LinkedList* list, Node* nodeToRemove)
{
    Node* node = list->start;
    Node* back = nodeToRemove->back;
    Node* next = nodeToRemove ->next;
    while(node!=nullptr)
    {
        if(node==nodeToRemove)
        {
            back->next = next;
            next->back = back;
            delete nodeToRemove;
            break;
        }
        node=node->next;
    }
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


Node* accEl(LinkedList* list, int index)
{
    Node* currentNode = list->start;
        for(int i = 0; i<index ; i++)
        {
            currentNode = currentNode->next;
        }
    //std::cout<<(currentNode->value);
    return currentNode;
}



int main()
{     
    LinkedList list;
    list.start = nullptr;
    list.end = nullptr;
    

   addElementToEnd(&list, 4);
   addElementToEnd(&list, 5);
   addElementToEnd(&list, 6);
   addElementToEnd(&list, 7);
   remove(&list, accEl(&list, 1));
   find(&list, 5);
   
   
   
    printareLista(&list);

    return 0;
}