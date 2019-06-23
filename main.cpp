#include <iostream>
#include "Hash.cpp"

using namespace std;

int main(){

    Hash hashTable;

    // int x = a.HashString("Adem");
    // int y = a.HashString("Yenice");
    // int z = a.HashString("9gag");

    // a.addToTable(x, "Adem");
    // a.addToTable(y, "Yenice");
    // a.addToTable(z, "9gag");

    hashTable.addToTable(hashTable.HashString("Adem"), "Adem");
    hashTable.addToTable(hashTable.HashString("Yenice"), "Yenice");
    hashTable.addToTable(hashTable.HashString("İstanbul"), "İstanbul");
    hashTable.addToTable(hashTable.HashString("Ankara"), "Ankara");
    hashTable.addToTable(hashTable.HashString("İzmir"), "İzmir");
    hashTable.addToTable(hashTable.HashString("Trabzon"), "Trabzon");
    hashTable.addToTable(hashTable.HashString("Manisa"), "Manisa");
    hashTable.addToTable(hashTable.HashString("Giresun"), "Giresun");
    hashTable.addToTable(hashTable.HashString("Elazığ"), "Elazığ");

    // hashTable.deleteFromList(hashTable.HashString("Yenice"), "Yenice");

    hashTable.printAllList();

    Node * tempNode = hashTable.getFromTable(hashTable.HashString("İzmir"), "İzmir");
    if (tempNode != NULL)
    {
        cout << tempNode->value << " " << tempNode->next << endl;
    }
    

    return 0;
}