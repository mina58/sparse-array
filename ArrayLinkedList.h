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
    const int array_size{};          //once initialized will remain constant
    int linked_list_size{};    //changes with every insertion



    void link_nodes(Node<T>* first, Node<T>* second){
        first->next = second;
        second->prev = first;
    }

    void insert_after(Node<T>* prev, Node<T> *cur){
        if(prev == tail){
            insert_back(cur);
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

    void print_indices(){
        for(auto cur = head; cur; cur = cur->next){
            cout << cur->index << ' ';
        }
        cout << '\n';
    }

    //todo raga3hom private
    void insert_back(Node<T> *cur){
        if(!linked_list_size){
            head = tail = cur;
        }else {
            tail->next = cur;
            cur->prev = tail;
            tail = cur;
            cur->next = nullptr;
        }
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
    }

    int get_linked_length(){
        return linked_list_size;
    }


    //returns the node of the given index, if not found returns the node of the last index before the given index.
    //e.g. if there are indices 0, 1, 4, 6 and we search for node of index 5, the node with index 4 will be returned.
    //returns nullptr if the index is less than the index of the head
    Node<T>* get_by_index(int index){
        if(index >= tail->index){
            return tail;
        }
        if(index < head->index){
            return nullptr;
        }
        if(linked_list_size == 1)
            return head;
        auto cur = head;
        for(; cur && cur->index <= index; cur = cur->next){
            if(cur->index == index)
                return cur;
        }
        return cur->prev;
    }

    void set_value(T val, int index){
        if(!linked_list_size){
            auto node = new Node<T>(val, index);
            insert_back(node);
            linked_list_size++;
            return;
        }
        if(index < 0 || index > array_size){
            cout << "index out of bounds";
            return;
        }
        if(index < head->index){
            auto node = new Node<T>(val, index);
            insert_front(node);
            linked_list_size++;
            return;
        }
        if(index > tail->index){
            auto node = new Node<T>(val, index);
            insert_back(node);
            linked_list_size++;
            return;
        }
        auto prev = get_by_index(index);
        if(prev->index == index){
            prev->data = val;
        }
        else{
            auto node = new Node<T>(val, index);
            insert_after(prev, node);
            linked_list_size++;
        }

    }

    void print_array();

    T get_value(int index);

    void add(ArrayLinkedList<T>*);

    ArrayLinkedList(const ArrayLinkedList<T>&) = delete;

    ArrayLinkedList &operator =(const ArrayLinkedList<T> &another) = delete;
};



#endif //SPARSE_ARRAY_ARRAYLINKEDLIST_H
