//
//  main.cpp
//  Algorithms
//
//  Created by Aidan Blant on 9/11/20.
//  Copyright © 2020 Aidan Blant. All rights reserved.
//

#include <iostream>
using namespace std;

template<typename T>
struct ListNode {
    ListNode(const T &v) : value(v), next(nullptr) {}
    T value;
    ListNode *next;
};

template<typename T>
// Simple Linked List implementation
class LinkedList{
public:
    ListNode<T>* head;
    
    LinkedList() : head(NULL) {} // Empty Linked List initializer
    
    // MARK: Access values
    ListNode<T>* front(){
        return *head;
    }
    
    ListNode<T>* back(){
        if( head == NULL ) return NULL;
        ListNode<T>* curr = head;
        while( curr->next != NULL ){ curr = curr->next; }
        return curr;
    }
    
    // MARK: Add Values
    void push_front(T k){
        ListNode<T>* newNode = new ListNode<T>(k);
        newNode->next = head;
        head = newNode;
    }

    // Insert value k at end of list
    void push_back(T k){
        ListNode<int>* curr = head;
        for (; curr->next != NULL; curr = curr->next);
        ListNode<T>* newNode = new ListNode<T>(k);
        curr->next = newNode;
    }
    
    // MARK: Remove values
    ListNode<T>* pop_front(){
        if( head == NULL ) return NULL;
        ListNode<int> *temp;
        temp = head;
        head = head->next;
        delete(temp);
    }
    
    ListNode<T>* pop(){
        if( head == NULL ) return NULL;
        ListNode<int> *temp;
        temp = head;
        head = head->next;
        return temp;
    }
    
    // Remove elements of given value
    void remove(T k){
        if( head == NULL ) return;
        ListNode<int>* curr = head;
        while( curr != NULL && curr->value == k ){
            ListNode<int> *temp = curr;
            head = head->next;
            delete(temp);
        }
        
        while( curr != NULL && curr->next != NULL ){
            if( curr->next->value == k ){
                ListNode<int>* toDelete = curr->next;
                curr->next = curr->next->next;
                delete(toDelete);
            }else{
                curr = curr->next;
            }
        }
    }
    
    /* TODO: Complete
    ListNode<T>* pop_back(){
        if( head == NULL ) return NULL;
        ListNode<T>* curr= head;
        while( curr->next->next != NULL ){ curr = curr->next; }
        ListNode<T>* popped = curr;
        curr = NULL;
        return popped;
    }*/
    
    
    int length(){
        ListNode<T> *l = head;
        int length = 0;
        for(l; l != NULL; l=l->next){
            length++;
        }
        return length;
    }
    
    bool empty(){
        if( head == NULL ) return true;
        return false;
    }
    
    void printList(){
        ListNode<T> *l = head;
        for( l; l += NULL; l=l->next){
            cout << l->value << " ";
        }
        cout << endl;
    }

    
};

template <typename T>
ListNode<int> * removeKFromList(ListNode<int> * &l, T k) {
    if( l == NULL ) return NULL;
    
    ListNode<T>* curr = l;
    /* This is wrong
    while( curr != NULL && curr->value == k ){
        ListNode<T>* toDelete = curr;
        l->next = curr->next;
        l = curr->next;
        curr = curr->next;
        delete(toDelete);
    }*/

    while( curr != NULL && curr->next != NULL ){
        // Replace next node with next next node
        if( curr->next->value == k ){
            ListNode<T>* toDelete = curr->next;
            curr->next = curr->next->next;
            delete(toDelete);
        }
        curr = curr->next;
    }
    
    return l;
}



int main(int argc, const char * argv[]) {
//    ListNode<int>* head;
    LinkedList<int> *ll = new LinkedList<int>();

    // Test 1
    ll->push_front(4);
    ll->push_front(3);
    ll->push_back(5);
    ll->push_back(6);
    ll->printList();
    
    ll->remove(5);
    ll->remove(6);
    ll->printList();
    
    //    ListNode<int>* newNode = new ListNode<int>(2);
//    head = newNode;
//    cout << "length: " << length(head) << endl;

    return 0;
}
