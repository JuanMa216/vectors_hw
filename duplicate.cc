#include <iostream>
#include <vector>
#include <cassert>
#include <initializer_list>

using namespace std;
template <typename T>

class Vector {
    private:
    T* storage_;
    unsigned int capacity_;
    unsigned int size_;
    public:
    Vector(unsigned int c) {
        capacity_ = c;
        storage_ = new T[capacity_];
        size_ = 0;
    }

    Vector() {
        capacity_ = 5;
        storage_ = new T[capacity_];
        size_ = 0;
    }  

    Vector(std::initializer_list<T> list) {
        capacity_ = list.size();
        size_ = list.size();
        storage_ = new T[capacity_];

        unsigned int i = 0;
        for (const T& elem : list) {
            storage_[i++] = elem;
        }
    }

    public:
    unsigned int capacity() const {
        return capacity_;
    }

    unsigned int size() const {
        return size_;
    }

    T& at(unsigned int pos) {
        assert(pos >= 0 && pos < size_);
        return storage_[pos];
    }

    const T& at(unsigned int pos) const {
        assert(pos >= 0 && pos < size_);
        return storage_[pos];
    }

    const T& operator[](unsigned int index) const {
        return storage_[index];
    }

    private:
    void resize() {
        cout << "Resize" << endl;
        unsigned int capacity2 = capacity_ * 1.5;
        T* storage2 = new T[capacity2];
        for ( unsigned int i = 0; i < size_; i++) {
            storage2[i] = storage_[i];
        }
        delete [] storage_;
        storage_ = storage2;
        capacity_ = capacity2;
    }

    public:
    void push_front(const T& elem) {
        if (size_ == capacity_)
        {
            resize();
        }

        for (unsigned int i = size_; i > 0; i--) {
            swap(storage_[i], storage_[i - 1]);
        }
        storage_[0] = elem;
        size_++;
    }

    void push_back(const T& elem) {
        if (size_ == capacity_) {
            resize();
        }
        storage_[size_] = elem;
        size_++;
    }

    void print() {
        for (unsigned int i = 0; i < size_; i++) {
            cout <<" "<< storage_[i];
        }
        cout << endl;
    }

};

template <typename T>
Vector<T> removeDuplicates(const Vector<T>& vector) {
    Vector<T> noDuplicates;

    if (vector.size() == 0)
    {
        return noDuplicates;
    }
    
    for (unsigned int i = 0; i < vector.size(); i++) {
        bool is_unique = true;
        
        for (unsigned int j = 0; j < noDuplicates.size(); j++) {
            if (noDuplicates.at(j) == vector.at(i)) {
                is_unique = false;
                break;
            }
        }
        
        if (is_unique) {
            noDuplicates.push_back(vector.at(i));
        }
    }

    return noDuplicates;
}


int main() {
Vector<int> numbers = {1, 2, 2, 3, 4, 4, 5};
numbers.print();
Vector<int> uniqueNumbers = removeDuplicates(numbers);
uniqueNumbers.print(); // Expected: {1, 2, 3, 4, 5}
    
Vector<int> numbers2 = {1,1,1,1,1,1};
Vector<int> uniqueNumbers2 = removeDuplicates(numbers2);
uniqueNumbers2.print(); // Expected: {1}
    
Vector<int> numbers3 = {};
Vector<int> uniqueNumbers3 = removeDuplicates(numbers3);
uniqueNumbers3.print(); // Expected: {}
    
Vector<int> numbers4 = {1};
Vector<int> uniqueNumbers4 = removeDuplicates(numbers4);
uniqueNumbers4.print(); // Expected: {1}

    return 0;
}