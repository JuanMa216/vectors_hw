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

template<typename T>
Vector<T> mergeSortedVectors(Vector<T>& v1, Vector<T>& v2) {
    int len1 = v1.size();
    int len2 = v2.size();

    if (len1 == 0) return v2;
    if (len2 == 0) return v1;
    if (len1 == 0 && len2 == 0) return Vector<T>();

    Vector<T> result;

    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (v1[i] < v2[j]) {
            result.push_back(v1[i]);
            i++;
        } else {
            result.push_back(v2[j]);
            j++;
        }
    }

    while (i < len1) {
        result.push_back(v1[i]);
        i++;
    }

    while (j < len2) {
        result.push_back(v2[j]);
        j++;
    }

    return result;
}



int main() {
    Vector<int> vector1 = {1, 3, 5};
    Vector<int> vector2 = {2, 4, 6};
    Vector<int> mergedVector = mergeSortedVectors(vector1, vector2);
    
    mergedVector.print(); // Expected: {1, 2, 3, 4, 5, 6}
    
    Vector<int> vector3 = {1, 2, 3};
    Vector<int> vector4 = {};
    Vector<int> mergedVector2 = mergeSortedVectors(vector3, vector4);
    mergedVector2.print(); // Expected: {1, 2, 3}
    
    Vector<int> vector5 = {};
    Vector<int> vector6 = {4,5,6};
    Vector<int> mergedVector3 = mergeSortedVectors(vector5, vector6);
    mergedVector3.print(); // Expected: {4, 5, 6}
    
    Vector<int> vector7 = {1,1,1,1};
    Vector<int> vector8 = {1,1,1,1};
    Vector<int> mergedVector4 = mergeSortedVectors(vector7, vector8);
    mergedVector4.print(); // Expected: {1,1,1,1,1,1,1,1}
    
return 0;
}
