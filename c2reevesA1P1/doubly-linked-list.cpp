#include "doubly-linked-list.h"
#include <iostream>
using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
    //set the value in the node to the data that is set
    value = data;
    //set the value of next and previous to null
    next = nullptr;
    prev = nullptr;

}

DoublyLinkedList::DoublyLinkedList()
{
    //initialize the doubly linked list to size of zero
    size_ = 0;
    //set the head and tail pointer to null
    head_ = nullptr;
    tail_ = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
  /*  while (head_)
    {
        Node* tmp = head_;
        head_ = head_->next;
        delete tmp;
    } */
}

unsigned int DoublyLinkedList::size() const
{
    return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
    //returns the capacity of the list which is arbitrary value
    return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
    //will return true if size equals
    return size() == 0;
}

bool DoublyLinkedList::full() const
{
    //will return true if size of list is the same as capacity
    return size() == capacity();
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
    //used when index is invalid or size = 0
    if (index > size() || index < 0 || tail_ == nullptr) {
        return tail_->value;
    }
    //if index = o and when size is not zero
    if (index == 0 && size() != 0) {
        return head_->value;
    }
    //if index is at the end of the list
    //return the value of the tail pointer
    if (index == size() - 1) {
        return tail_->value;
    }
    //if index is in the middle of the list
    //iterate through the list to find the correct node
    if (size() > 0 && index > 0 && index < size()) {
        //create a temporary pointer previous and current to iterate through the list
        Node *current = head_;
        //start at i equals one and go up to reaching the index
        for (int i = 1; i <= index; i++) {
            current = current->next;
        }
        return current->value;
    }
}
    unsigned int DoublyLinkedList::search(DataType value) const {
        //if size is equal to zero return the size of the list
        if (size() == 0) {
            return size();
        }
        if (size() == 1) {
            if (head_->value == value) {
                return size() - 1;
            } else {
                return size();
            }
        }
        Node *temp = head_;
        int j = 0;
        for (unsigned int i = 0; i < size(); i++) {
            if(head_->value == value){
                i = size();
                return j;
            }
            temp = temp->next;
            if (temp->value == value) {
                i = size();
                return j;
            }
            j++;
        }
    }

    void DoublyLinkedList::print() const {
        if (head_ == nullptr) {
            return;
        }
        //print all nodes
        Node *temp = head_;
        while (temp != nullptr) {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    DoublyLinkedList::Node *DoublyLinkedList::getNode(unsigned int index) const {
    if(size()==0){
        cout << "Node does not exist as the list is empty" << endl;
    }
    if(size()==0){
        return head_;
    }
    if(index == size()-1){
        return tail_;
    }
    if(index>size()){
        cout << "Node does not exist as this index is outside of the size" << endl;
    }
    if(index > 0 && index < size()){
        Node *temp;
        for(int i=1; i<=index; i++){
        temp = temp->next;
       }
        return temp;
    }
    }

    bool DoublyLinkedList::insert(DataType value, unsigned int index) {
        //step 1. check position validity, compare with 0 and size,
        //if not valid, quit, report error, or force into a valid value
        ////omitted in this demo, assuming it is valid
        //checking that index is valid
        //if index is greater than size, it should return false
        //as index will always be less than size except for when size == 0
        //and when index == size
        if (index > size()) {
            return false;
        }
        //step 2. create new node
        Node *newNode = new Node(value);
        //step 3. if special case, when position = 0
        //insert as the new head
        //3.1 when head == nullptr, or size == 0
        //the newNode will become the new head and the new tail
        if (size() == 0 || head_ == nullptr) {
            head_ = newNode;
            tail_ = newNode;
            size_++;
            return true;
        }
        //3.2 when size > 0, (position = 0)
        //insert at the head position
        //// actual code omitted
        //if index is zero, the new node must become headnode
        //the old head nodes previous will point to new Node
        //new Nodes next will point to old head node
        //the head will now point at new Node
        if (index == 0) {
            head_->prev = newNode;
            newNode->next = head_;
            head_ = newNode;
            size_++;
            return true;
        }
        //step 4. when size > 0, position = size
        //insert at the end of the list, the node will become the new tail
        //// actual code omitted
        //if the size is not zero, and index is equal to size it should be inserted at the end of the list
        //old tail nodes next will point at new Node
        //new Nodes previous will point at the old tail node
        //tail will now point at new Node
        if (size() > 0 && index == size()) {
            tail_->next = newNode;
            newNode->prev = tail_;
            tail_ = newNode;
            size_++;
            return true;
        }
        //step 5. when size > 0, position > 0,  position < size
        //insert in the middle of the list
        //iterate through the list to find the position
        //with an additional pointer for the address of the previous node
        //may iterate from head to tail, in a way same as in singly linked list
        //may also iterate from tail to head.
        //alternatively, in a slightly improved version, may check if position is closer to head or tail,
        // then iterate from the closer end.
        //// actual code omitted
        //if the size of the list is greater than zero, and index is greater than zero (not insert at the front)
        //and index is less than size (not insert at the back)
        if (size() > 0 && index > 0 && index < size()) {
            //create a temporary pointer previous and current to iterate through the list
            Node *previous = head_;
            Node *current = head_->next;
            //start at i equals one and go up to reaching the index
            for (int i = 1; i <= index; i++) {
                previous = current;
                current = current->next;
            }
            newNode->prev = previous->prev;
            previous->prev = newNode;
            newNode->next = previous;
            newNode->prev->next = newNode;
            size_++;
            return true;
        }
        //step 6. insert the node between previous and current (assume previous is closer to head)
        // properly link prev and next pointers
        //// actual code omitted

    }

    bool DoublyLinkedList::insert_front(DataType value) {
        insert(value, 0);
    }

    bool DoublyLinkedList::insert_back(DataType value) {
        insert(value, size());
    }

    bool DoublyLinkedList::remove(unsigned int index) {
        //step 1. check position validity, compare with 0 and size,
        //if not valid, quit, report error, or force into a valid value
        ////omitted in this demo, assuming it is valid
        if (index > size()) {
            return false;
        }
        //step 2.1 special case, if position == 0, remove head
        //if this is also the tail, properly set tail pointer
        //use a temp pointer
        //properly set the pointers, don't forget setting head pointer
        //deallocate node memory
        //// actual code omitted
        if (index == 0 && size() == 1) {
     //       Node *temp = head_;
    //        head_ = head_->next;
    //        head_->prev = nullptr;
            delete head_;
            size_--;
            return true;
        }
        if (index == 0 && size() != 1) {
            Node *temp = head_;
            head_ = head_->next;
            head_->prev = nullptr;
            tail_ = nullptr;
            delete temp;
            size_--;
            return true;
        }
        //step 2.2, special case, if position == size - 1, remove tail
        //use a temp pointer
        //properly set the pointers, don't forget setting tail pointer
        //deallocate node memory
        //// actual code omitted
        if (index == size() - 1) {
            Node *temp = tail_;
            tail_ = tail_->prev;
            tail_->next = nullptr;
            delete temp;
            size_--;
            return true;
        }
        //step 3. to prepare for removing a node in the middle of the list, find the pointer to the location
        //may iterate from head to tail, in a way same as in singly linked list
        //may also iterate from tail to head.
        //alternatively, in a slightly improved version, may check if position is closer to head or tail,
        // then iterate from the closer end.
        //// actual code omitted
        if (size() > 0 && index > 0 && index < size()) {
            //create a temporary pointer previous and current to iterate through the list
            Node *previous = head_;
            Node *current = head_->next;
            //start at i equals one and go up to reaching the index
            for (int i = 1; i <= index; i++) {
                previous = current;
                current = current->next;
            }
            current->prev = previous->prev;
            previous->prev->next = current;
            delete previous;
            size_--;
            return true;
        }
        //step 4. after finding the proper pointers after iteration
        // remove the node and properly link the remaining nodes.
        //// actual code omitted

    }

    bool DoublyLinkedList::remove_front() {
        remove(0);
    }

    bool DoublyLinkedList::remove_back() {
        remove(size() - 1);
    }

    bool DoublyLinkedList::replace(unsigned int index, DataType value) {
        //may iterate from head to tail, in a way same as in singly linked list
        //may also iterate from tail to head.
        //alternatively, in a slightly improved version, may check if position is closer to head or tail,
        // then iterate from the closer end.

        //step 1. check position validity, compare with 0 and size,
        //if not valid, quit, report error, or force into a valid value
        ////omitted in this demo, assuming it is valid
        //index is greater than size, nothing to replace
        if(index>size()){
            return false;
        }
        if(index==0){
            head_->value = value;
            return true;
        }
        if(index == size()-1){
            tail_->value = value;
            return true;
        }
        //if index equals zero and size equals zero, there is nothing to replace
        //if index equals size then it will be after the list, also nothing to replace
        if(index==size()){
            return false;
        }
        //step 2. iterate a pointer to the position
        //// actual code omitted
        if(size()>0){
            Node* temp = head_;
            for (unsigned int i=1; i <= index; i++){
               temp = temp->next;
            }
            temp->value = value;
            return true;
        }
    }

