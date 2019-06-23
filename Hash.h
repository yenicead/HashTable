#include <iostream>
#include <string>

using namespace std;

class Node{       
    public:
        string value;
        Node * next;       
};

class Hash{
    static const int tableSize = 10;

    public:
        Hash();
        ~Hash();

        Node * List[tableSize];
        int HashString(string key);
        void addToTable(int index, string key);
        Node * getFromTable(int index, string key);
        void printAllList();
        bool deleteFromList(int index, string key);
};


