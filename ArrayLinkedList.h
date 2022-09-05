#include <iostream>
#ifndef SPARSE_ARRAY_ARRAYLINKEDLIST_H
#define SPARSE_ARRAY_ARRAYLINKEDLIST_H

using namespace std;


template <typename T>
struct Node{
    T data{};
    int index{};
    Node<T>* next;
    Node<T>* prev;

    Node(T val, int index): data(val), index(index){}
};

template <typename T>
class ArrayLinkedList {
private:
    Node<T>* head{};
    Node<T>* tail{};
    int array_size{};          //once initialized will remain constant
    int linked_list_size{};    //changes with every insertion



    void link_nodes(Node<T>* first, Node<T>* second){
        first->next = second;
        second->prev = first;
    }

    void insert_back(Node<T> *cur){
        if(!linked_list_size){
            head = tail = cur;
        }else {
            tail->next = cur;
            cur->prev = tail;
            tail = cur;
            cur->next = nullptr;
        }
        linked_list_size++;
    }

    void insert_front(Node<T> *cur){
        if(!linked_list_size){
            head = tail = cur;
        }else {
            cur->next = head;
            head->prev = cur;
            head = cur;
            cur->prev = nullptr;
        }
        linked_list_size++;
    }

    void insert_after(Node<T>* prev, Node<T> *cur){
        if(prev == tail){
            insert_end(cur);
        }
        else{
            cur->next = prev->next;
            prev->next->prev = cur;
            cur->prev = prev;
            prev->next = cur;
        }
    }

public:
    ArrayLinkedList(int size):array_size(size){}

    ~ArrayLinkedList(){
        for(Node<T> *cur = head, *nxt = nullptr; cur;){
            nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    void print_list(){
        for(auto cur = head; cur; cur = cur->next){
            cout << cur->data << ' ';
        }
        cout << '\n';
    }
    void print_list_reversed(){
        for(auto cur = tail; cur; cur = cur->prev){
            cout << cur->data << ' ';
        }
        cout << '\n';
    }


    //returns the node of the given index, if not found returns the node of the last index before the given index
    //e.g. if there are indices 0, 1, 4, 6 and we search for node of index 5, the node with index 4 will be returned
    Node<T>* get_by_index(int index);

    void set_value(T val, int index);

    void print_array();

    T get_value(int index);

    void add(ArrayLinkedList<T>*);

    ArrayLinkedList(const ArrayLinkedList<T>&) = delete;

    ArrayLinkedList &operator =(const ArrayLinkedList<T> &another) = delete;
};



#endif //SPARSE_ARRAY_ARRAYLINKEDLIST_H
