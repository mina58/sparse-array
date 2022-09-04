//
// Created by Mina on 04-Sep-22.
//

#ifndef SPARSE_ARRAY_ARRAYLINKEDLIST_H
#define SPARSE_ARRAY_ARRAYLINKEDLIST_H


template <typename T>
struct Node{
    T data{};
    int index{};
    int next_index{};
    int prev_index{};
    Node<T>* next;
    Node<T>* prev;

    Node(T val, int index);
};

template <typename T>
class ArrayLinkedList {
private:
    int head_index{};
    int tail_index{};
    Node<T>* head{};
    Node<T>* tail{};
    int array_size{};          //once initialized will remain constant
    int linked_list_size{};    //changes with every insertion

public:
    ArrayLinkedList(int size);
    void set_value(T val, int index);
    void print_array();
    void print_array_nonzero();
    T get_value(int index);
    void add(ArrayLinkedList<T>*);
    ArrayLinkedList(const ArrayLinkedList<T>&) = delete;
    ArrayLinkedList &operator =(const ArrayLinkedList<T> &another) = delete;
};

#endif //SPARSE_ARRAY_ARRAYLINKEDLIST_H
