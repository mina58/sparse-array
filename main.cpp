#include <iostream>
#include "ArrayLinkedList.h"

using namespace std;

int main(){
    ArrayLinkedList<int> a(10);
    a.print_list();
    a.print_list_reversed();
}