#include "sequential-list.h"
#include <iostream>

using namespace std;

const int ZERO = 0;
//CREATING A NEW SEQUENTIAL LIST GIVEN NUMBER OF ELEMENTS
SequentialList::SequentialList(unsigned int cap)
{
    capacity_ = cap;
    data_ = new DataType[cap];
    size_ = 0;
}

//DELETING SEQUENTIAL LIST
SequentialList::~SequentialList()
{
    delete [] data_;
}

//RETURNS SIZE - NUMBER OF ELEMENTS IN LIST
unsigned int SequentialList::size() const
{
    return size_;
}

//RETURNS CAPACITY - MAXIMUM NUMBER OF ELEMENTS DATA CAN HOLD
unsigned int SequentialList::capacity() const
{
    return capacity_;
}

//CHECKS IF SIZE IS EQUAL TO 0
bool SequentialList::empty() const
{
    return size_ == 0;
}

//CHECKS IF SIZE IS EQUAL TO CAPACITY
bool SequentialList::full() const
{
    return size_ == capacity_;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    //RETURNS VALUE AT INDEX ONLY IF INDEX IS LESS THAN THE LIST SIZE
   if(index < size_)
   {
       return data_[index];
   }
   //OTHERWISE RETURNS THE LAST ELEMENT WHICH IS AT INDEX SIZE_ - 1
   return data_[size_ - 1];

}

unsigned int SequentialList::search(DataType val) const
{
    //FOR LOOP GOES THROUGH ENTIRE LIST
    for(int index = 0; index < size_; index++)
    {
        //IF VALUE AT INDEX IS FOUND, RETURNS THE INDEX VALUE
        if(data_[index] == val)
        {
            return index;
        }
    }
    //OTHERWISE, THE SIZE OF THE LIST IS RETURNED
    return size_;

}

void SequentialList::print() const
{
    //GOES THROUGH THE LIST USING A FOR LOOP TO PRINT ALL VALUES IN LIST
    for(int index = 0; index < size_; index++)
    {
        cout << data_[index] << endl;
    }
    
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    //IF THE LIST IS FULL OR INDEX IS INVALID, THAT IS INDEX GREATER THAN THE SIZE OF THE LIST, RETURNS FALSE
    if(full() || index > size_)
    {
        return false;
    }
    //OTHERWISE, GOING THRU THE LIST IN REVERSE AND EXCHANGING THE CURRENT VALUE WITH THE PREVIOUS ONE IN LIST
    //THAT IS ALL VALUES MOVE FORWARD IN THE LIST
    for(int count = size_; count > index; count--)
    {
        data_[count] = data_[count - 1];
    }
    //SETTING VALUE AT GIVEN INDEX TO GIVEN VALUE AND SIZE INCREMENTS BY 1, RETURNS TRUE
    data_[index] = val;
    size_++;
    return true;


}

bool SequentialList::insert_front(DataType val)
{
    //IF THE LIST IS FULL, RETURNS FALSE
    if(full())
    {
        return false;
    }
    //OTHERWISE, USING A FOR LOOP TO GO THRU THE LIST IN THE REVERSE DIRECTION AND ALL VALUES MOVE FORWARD IN LIST
    for(int index = size_; index > ZERO; index--)
    {
        data_[index] = data_[index - 1];
    }
    //VALUE AT INDEX 0 IS SET TO GIVEN VALUE, SIZE INCREMENTS BY 1, RETURNS TRUE
    data_[ZERO] = val;
    size_++;
    return true;

}

bool SequentialList::insert_back(DataType val)
{
    //IF THE LIST IS FULL, RETURNS FALSE
    if(full())
    {
        return false;
    }
    //LIST AT INDEX SIZE WHICH IS 1 GREATER THAN LAST INDEX IS SET TO GIVEN VALUE, SIZE INCREMENTS BY 1, RETURNS TRUE
    data_[size_] = val;
    size_++;
    return true;

}

bool SequentialList::remove(unsigned int index)
{
    //IF LIST IS FULL OR INDEX IS INVALID, RETURNS FALSE
    if(full() || index >= size_)
    {
        return false;
    }
    //GOING THRU THE LIST FROM GIVEN INDEX TO THE SECOND LAST INDEX AND SHIFTING ALL VALUES BACKWARDS
    for(int count = index; count < size_ - 1; count++)
    {
        data_[count] = data_[count + 1];
    }
    //SIZE DECREASES BY 1, RETURNS TRUE
    size_--;
    return true;

}

bool SequentialList::remove_front()
{
    //SIMPLY REMOVES THE VALUE AT INDEX 0
    return remove(0);
}

bool SequentialList::remove_back()
{
    //SIMPLY REMOVES THE VALUE AT LAST INDEX
    return remove(size_ - 1);
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    //IF INDEX IS VALID, VALUE AT INDEX IS REPLACED BY GIVEN VALUE, RETURNS TRUE
    if(index < size_)
    {
        data_[index] = val;
        return true;
    }
    //OTHERWISE, RETURNS FALSE
    return false;
}

