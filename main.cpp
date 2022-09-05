#include <iostream>
#include "ArrayLinkedList.h"

using namespace std;

int main(){
    ArrayLinkedList<int> a(10);
    a.insert_back(new Node<int>(1, 1));
    a.insert_back(new Node<int>(2, 3));
}