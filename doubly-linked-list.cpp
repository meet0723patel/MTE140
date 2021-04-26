#include "doubly-linked-list.h"
#include <iostream>
#include <new>

using namespace std;

DoublyLinkedList::Node::Node(DataType data):
        value(data), next(NULL), prev(NULL)
{
}
DoublyLinkedList::DoublyLinkedList()
        :head_(NULL), tail_(NULL), size_(0)
{
}
/*DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& list)
:size_(list.size_)
{
	


}*/
DoublyLinkedList::~DoublyLinkedList()
{
    //EMPTY LIST MEANING HEAD AND TAIL ARE BOTH NULL
    if(empty())
    {
        head_ = nullptr;
        tail_ = nullptr;
    }
    else
    {
        Node* curr = head_;
        while (curr != nullptr)
        {
            Node* temp = curr->next;
            delete curr;
            curr = temp;
        }
    }

}
bool DoublyLinkedList::empty() const
{
    //RETURNS IF SIZE OF LIST IS 0
    return size_ == 0;

}
unsigned int DoublyLinkedList::size() const
{
    //RETURNS THE SIZE OF THE LIST
    return size_;

}
void DoublyLinkedList::print() const
{

    //GOING THRU THE LIST AND ALL VALUES IN LIST ARE OUTPUTTED IN EVERY LINE
    Node* curr = head_;
    for(int index = 0; index < size_; index++)
    {
        cout << curr->value << endl;
        curr = curr->next;
    }


}
bool DoublyLinkedList::insert_front(DataType value)
{
    //IF LIST IS EMPTY, BOTH THE HEAD AND TAIL BECOME NEW NODE VALUE, AND THE PREVIOUS AND NEXT BECOME NULL
  if(empty())
   {
       head_ = tail_ = new Node(value);
       head_->prev = nullptr;
       tail_->next = nullptr;
   }
  //OTHERWISE, NEW NODE BECOMES THE FIRST INDEX, AND HEAD IS SHIFTED BACKWARDS, AND HEAD BECOMES NULLPTR
   else
   {
       Node* newNode = new Node(value);
       head_->prev = newNode;
       newNode->next = head_;
       newNode->prev = nullptr;
       head_ = newNode;
   }

   //SIZE INCREMENTS BY 1, RETURNS TRUE
   size_++;
   return true;


}
bool DoublyLinkedList::remove_front()
{
    //IF LIST IS EMPTY, RETURN FALSE
    if(empty())
    {
        return false;
    }
    //IF THE SIZE OF LIST IS 1, THE HEAD VALUE IS DELETED, AND BOTH HEAD, TAIL BECOME NULLPTR
    else if(size_ == 1)
    {
        delete head_;
        head_ = tail_ = nullptr;
    }
    //OTHERWISE, HEAD MOVES FORWARD, THE FIRST INDEX IS DELETED, AND NEW HEAD IS NULLPTR, SIZE DECREASES BY 1
    else{
        head_ = head_->next;
        delete head_->prev;
        head_->prev = nullptr;
        size_--;
    }
    //RETURNS TRUE
    return true;



}
bool DoublyLinkedList::insert_back(DataType value)
{
    //IF THE LIST IS EMPTY, BOTH THE HEAD AND TAIL BECOME NEW VALUE
    //AND TAIL NEXT AND HEAD PREV BECOMES NULLPTR
    if (empty())
    {
        tail_ = head_ = new Node(value);
        tail_->next = nullptr;
        head_->prev = nullptr;;
    }
    //OTHERWISE, TAIL NEXT BECOMES NULLPTR, AND TAIL BECOMES GIVEN VALUE
    else
    {
        Node* newNode = new Node(value);
        tail_->next = newNode;
        newNode->prev = tail_;
        tail_ = newNode;
        tail_->next = nullptr;
    }
    //SIZE INCREMENTS BY 1, RETURNS TRUE
    size_++;
    return true;


}
bool DoublyLinkedList::remove_back()
{
    //IF LIST IS EMPTY, RETURNS FALSE
    if(empty())
    {
        return false;
    }
    //IF SIZE OF LIST IS 1, THE TAIL IS DELETED, AND BOTH TAIL AND HEAD BECOME NULLPTR
    else if(size_ == 1)
    {
        delete tail_;
        tail_ = head_ = nullptr;
    }
    //OTHERWISE, TAIL IS SHIFTED BACKWARDS, AND TAIL NEXT BECOMES NULLPTR, SIZE DECREASES BY 1
    else
    {
        tail_ = tail_->prev;
        delete tail_->next;
        tail_->next = nullptr;
        size_--;
    }
    //RETURNS TRUE
    return true;

}
bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    //IF LIST IS FULL OR INDEX IS INVALID, RETURN FALSE
    if(full() || index > size_)
    {
        return false;
    }
    //SHIFTING HAPPENS, AND GIVEN VALUE IS PLACED AT THE INDEX, SIZE INCREASES BY 1, RETURNS TRUE
    Node* newNode = new Node(value);
    Node* prevNode = getNode(index);

    prevNode->prev->next = newNode;
    newNode->prev = prevNode->prev;
    prevNode->prev = newNode;
    newNode->next = prevNode;
    size_++;
    return true;

}
bool DoublyLinkedList::remove(unsigned int index)
{
    //IF LIST IS EMPTY OR INDEX IS INVALID, RETURN FALSE
    if(empty() || index > size_)
    {
        return false;
    }
    //SHIFTING HAPPENS, AND VALUE IS REMOVED AT GIVEN INDEX AND SIZE DECREASES BY 1, RETURNS TRUE
    Node* tempNode = getNode(index);

    tempNode->prev->next = tempNode->next;
    tempNode->next->prev = tempNode->prev;
    delete tempNode;
    size_--;
    return true;


}
unsigned int DoublyLinkedList::search(DataType value) const
{
    //GOING THRU THE LIST AND IF THE VALUE AT INDEX IS EQUAL TO GIVEN VALUE, THE INDEX IS RETURNED
    Node* curr = head_;
    for(int index = 0; index < size_; index++)
    {
        if(curr->value == value)
        {
            return index;
        }
        curr = curr->next;
    }
    //OTHERWISE, THE SIZE OF LIST IS RETURNED
    return size_;


}
DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    //IF GIVEN INDEX IS VALID
    if(index < size_)
    {
        //GOING THRU THE LIST TILL INDEX IS REACHED, AND THE VALUE AT INDEX IS RETURNED
        Node* curr = head_;
        for(int count = 0; count < index; count++)
        {
            curr = curr->next;
        }

        return curr->value;
    }
    //OTHERWISE, THE VALUE AT LAST INDEX IS RETURNED
    return tail_->value;


}
bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    //IF INDEX IS VALID, THEN THE FOR LOOP RUNS
    if(index < size_)
    {
        //GOING THRU THE LIST TILL 1 LESS THAN GIVEN INDEX, SO CURR NEXT WILL BE AT THE INDEX
        Node* curr = head_;
        for(int count = 0; count < index; count++)
        {
            curr = curr->next;
        }
        //VALUE AT INDEX IS CHANGED TO GIVEN, RETURNS TRUE
        curr->value = value;
        return true;

    }
    return false;

}
DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
    //GOING THRU LIST TILL 1 LESS THAN GIVEN INDEX, SO CURR NEXT WILL BE AT GIVEN INDEX
   Node* curr = head_;
   for(int count = 0; count < index; count++)
   {
       curr = curr->next;
   }
   //RETURNS CURR
   return curr;

}
bool DoublyLinkedList::full() const
{
    //CHECKS IF SIZE IS EQUAL TO THE CAPACITY
    return size_ == CAPACITY;

}
