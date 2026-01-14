// intlist.cpp
// Implements class IntList
// Satvik Balakrishnan 01/13/2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    this->head = nullptr;
    this->tail = nullptr;
    
    Node* sourceCurr = source.head;

    while(sourceCurr != nullptr){
        push_back(sourceCurr->info);
        sourceCurr = sourceCurr->next;
    }

}

// destructor deletes all nodes
IntList::~IntList() {

    Node* temp = head;
    Node* toDelete = head;

    while(temp!=nullptr){
        toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
   
}


// return sum of values in list
int IntList::sum() const {
    int totalSum = 0;

    Node* curr = head;
    while(curr!=nullptr){
        totalSum += curr->info;
        curr = curr->next;
    }

   return totalSum;
    
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {

    Node* curr = head;
    while(curr!=nullptr){
        if(curr->info == value) return true;
        curr = curr->next;
    }

    return false;



}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {

    if(head==nullptr){
        return 0;
    }

    int maxValue = head->info;

    Node* curr = head;
    while(curr!=nullptr){
        if(curr->info > maxValue) maxValue = curr->info;
        curr = curr->next;
    }

   return maxValue;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(head==nullptr){
        return 0.0;
    }

    return double(sum()) / count();
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newHead = new Node;
    newHead->info = value;
    
    if(head==nullptr){
        newHead->next = nullptr;
        head = newHead;
        tail = newHead;
    }else{
        newHead->next = head;
        head = newHead;
    }

}

// append value at end of list
void IntList::push_back(int value) {

    Node* newTail = new Node;
    newTail->info = value;
    newTail->next = nullptr;

    if(head==nullptr){
        head = newTail;
        tail = newTail;
        
    } else {
        tail->next = newTail;
        tail = newTail;
    }

    
 
}

// return count of values
int IntList::count() const {
   int counter = 0;
   Node* curr = head;
   while(curr!=nullptr){
    counter++;
    curr = curr->next;
   }

   return counter;
   
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    Node* temp = head;
    Node* toDelete = head;

    while(temp!=nullptr){
        toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    this->head = nullptr;
    this->tail = nullptr;
    
    Node* sourceCurr = source.head;

    while(sourceCurr != nullptr){
        push_back(sourceCurr->info);
        sourceCurr = sourceCurr->next;
    }

    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr; 
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

