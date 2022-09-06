#include <iostream>
#include "ArrayLinkedList.h"

using namespace std;

int main(){
    ArrayLinkedList<int> a(10);
    cout << a.get_linked_length() << '\n';
    a.print_indices();
    a.print_list();
}