#include <iostream>
#include "ArrayLinkedList.h"

using namespace std;

int main(){
    ArrayLinkedList<int> a(10);
    a.set_value(0, 0);
    a.set_value(4, 4);
    a.set_value(6, 6);
    a.set_value(5, 5);
    a.set_value(8, 8);
    a.set_value(3, 3);
    a.set_value(7, 5);
    a.set_value(9, 9);


    a.print_list();
}