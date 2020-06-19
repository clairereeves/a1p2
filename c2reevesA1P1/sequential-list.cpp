#include <iostream>
#include "sequential-list.h"
using namespace std;


SequentialList::SequentialList(unsigned int cap)
{
data_ = new DataType[cap];
capacity_ = cap;
size_ = 0;
}

SequentialList::~SequentialList()
{
    delete data_;
    data_ = nullptr;
}

unsigned int SequentialList::size() const
{
    return size_;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    return size() == 0;
}

bool SequentialList::full() const
{
    return (capacity() == size());
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    if (empty()){
        cout << "Empty List!" << endl;
        empty();
    }
    else if ((index >= size() && size()!=0) || index < 0){
        return data_[size()-1];
          }
    else {
        return data_[index];
        }
}


unsigned int SequentialList::search(DataType val) const {

    if (empty()) {
        return size();
    } else {
        int t = 0;
        do {
            if (data_[t] == val) {
                return t;
            }
            t++;
        } while (data_[t - 1] != val && t < size());

        t = 0;
        do {
            t++;
        } while (data_[t - 1] != val && t < size());

        if (t >= size()) {
            return size();
        }
    }
}
    void SequentialList::print() const{
        if (empty()) {
            cout << "empty list" << endl;
        }
        else {
            for (int i = 0; i < size(); i++) {
                cout << data_[i] << endl;
            }
        }
        cout << endl;
    }

    bool SequentialList::insert(DataType val, unsigned int index) {
        if (full() || index > size()) {
            return false;
        } else if (empty()) {
            if(index == 0){
                return true;
            }
            else{
                return false;
            }
        } else {
            for (unsigned int i = size(); i > index; i--) {
                data_[i] = data_[i - 1];
            }
            data_[index] = val;
            size_++;
            return true;
        }
    }

    bool SequentialList::insert_front(DataType val) {
        if (full()) {
            return false;
        } else {
            insert(val, 0);
        }
    }

    bool SequentialList::insert_back(DataType val) {
        if (full()) {
            return false;
        } else {
            insert(val, size());
        }
    }

    bool SequentialList::remove(unsigned int index) {
        if (empty() || index > size()) {
            return false;
        } else {
            for (unsigned int i = index; i < size(); i++) {
                data_[i] = data_[i + 1];
            }
            size_--;
            return true;
        }
    }

    bool SequentialList::remove_front() {
        if (empty()) {
            return false;
        } else {
            remove(0);
        }
    }

    bool SequentialList::remove_back() {
        if (empty()) {
            return false;
        } else {
            remove(size() - 1);
        }
    }

    bool SequentialList::replace(unsigned int index, DataType val) {
        if (index > capacity()) {
            return false;
        } else {
            data_[index] = val;
            return true;
        }
    }

