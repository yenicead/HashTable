#include <iostream>
#include "Hash.h"


using namespace std;

Hash::Hash(){    
    for (int i = 0; i < tableSize; i++)
    {
        List[i] = new Node;
        List[i]->value = "";
        List[i]->next = NULL;
    }   
}

Hash::~Hash(){    

    for (int i = 0; i < tableSize; i++)
    {        
        Node * head = List[i];
        Node * tempNode;
        
        while (head->next != NULL)
        {
            tempNode = head;
            head = head->next;
            delete tempNode;
        }       
    }
}

int Hash::HashString(string key){
    int keyValue = 0;
    for (int i = 0; i < key.length(); i++)
    {
        keyValue += (int) key[i];
    }
    
    int indexForKey = keyValue % tableSize;

    return indexForKey;
}

void Hash::addToTable(int index, string key){
    if (List[index] == NULL)
    {
        Node * node = new Node;
        node->value = key;
        node->next = NULL;
        List[index] = node;
    }
    else{
        Node * tempNode = List[index];
        while(tempNode->next != NULL){
            tempNode = tempNode->next;
        }
        Node * newNode = new Node;
        newNode->value = key;
        newNode->next = NULL;
        tempNode->next = newNode;
    }     
}

Node * Hash::getFromTable(int index, string key){
    Node * node = new Node;
    node = List[index];

    if (node->value == key)
    {
        return node;
    }
    else{
        while(node->next != NULL){
            node = node->next;
            if (node->value == key)
            {
                return node;
            }
            
        }
    }    

    // Not found in the given index.
    return NULL;
}

void Hash::printAllList(){
   
    for (int i = 0; i < tableSize; i++)
    {
        Node * tempNode = List[i];
        cout << "--- INDEX : " << i << " ELEMENTS ---" << endl;


        while(tempNode != NULL){
            cout << tempNode->value << endl;
            tempNode = tempNode->next;
        }

        cout << "####################################" << endl;
    }
    
}

bool Hash::deleteFromList(int index, string key){

    Node * tempNode = List[index];
    Node * head;

    if (tempNode->value == key)
    {
        if (tempNode->next != NULL)
        {
            head = tempNode->next;
            delete tempNode;
            List[index] = head;
            return true;
        }   
        else{
            tempNode->value = "";
            tempNode->next = NULL;
            return true;
        }   
    }
    else{
        head = tempNode;
        tempNode = tempNode->next;

        while(tempNode != NULL){
            
            if (tempNode->value == key)
            {
                head->next = tempNode->next;
                delete tempNode;
                return true;
            }
            head = tempNode;
            tempNode = tempNode->next;
        }

        return false;
    }
}