#include <iostream>
#include <chrono>
#include <cassert>
#include <random>
#include <cmath>

using namespace std;
using namespace chrono;

template <typename T>
class Vector {
private:
    T* storage_;
    unsigned int size_;
    unsigned int capacity_;

private:
    void resize() {
        cout << "Resize" << endl;
        unsigned int capacity2 = capacity_ * 1.5;
        T* storage2 = new T[capacity2];
        for (unsigned int i = 0; i < size_; i++) {
            storage2[i] = storage_[i];
        }
        delete [] storage_;
        storage_ = storage2;
        capacity_ = capacity2;
    }

public:

    Vector(unsigned int c) {
        capacity_ = c;
        storage_ = new T[capacity_];
        size_ = 0;
    }

    unsigned int size() {
        return size_;
    }

    Vector(initializer_list<T> list) {
        capacity_ = list.size();
        size_ = list.size();
        storage_ = new T[capacity_];
        
        unsigned int i = 0;
        for (const T& elem : list) {
            storage_[i++] = elem;
        }
    }

    Vector(const Vector& other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        storage_ = new T[capacity_];
        for (unsigned int i = 0; i < size_; i++) {
            storage_[i] = other.storage_[i];
        }
    }

    Vector& operator=(const Vector& other) {
        if (this == &other) return *this;
        delete[] storage_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        storage_ = new T[capacity_];
        for (unsigned int i = 0; i < size_; i++) {
            storage_[i] = other.storage_[i];
        }
        return *this;
    }

    const T& operator[](unsigned int index) const {
        return storage_[index];
    }

    void push_front(const T& elem) {
        if (size_ == capacity_) {
            resize();
        }

        for (unsigned int i = size_; i > 0; i--) {
            storage_[i] = storage_[i - 1];
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

    void insert(unsigned int index, T element) {
        assert(index <= size_);

        if (size_ == capacity_) {
            resize();
        }

        for (unsigned int i = size_; i > index; i--) {
            storage_[i] = storage_[i - 1];
        }
        
        storage_[index] = element;
        size_++;
    }

    unsigned int size() const {
        return size_;
    }

    void pop_back() {
        if(size_ == 0) throw std::underflow_error("Cannot pop from an empty list");
        size_--;
    }

    void pop_front() {
        if(size_ == 0) return;
        for (unsigned int i = 0; i < size_ - 1; i++) {
            storage_[i] = storage_[i + 1];
        }
        size_--;
    }

    void erase(unsigned int index) {
        assert(index < size_);
    
        if(index == 0) {
            pop_front();
            return;
        }
    
        if (index == size_ - 1)
        {
            pop_back();
            return;
        }
    
        for (unsigned int i = index; i < size_ ; i++)
        {
            storage_[i] = storage_[i + 1];
        }
        
    size_--;
    }
};

void RandomVector(Vector<int>* v, int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 100);

    for (int i = 0; i < size; i++) {
        v->push_back(distrib(gen));
    }
}

int main() {
    Vector<int> n(101);
    RandomVector(&n, 101);
    for (int pos = 0; pos <= 100; pos += 10) {
        Vector<int> temp = n; // Se crea una copia en cada iteración
    
        auto start_insert = high_resolution_clock::now();
        
        if (pos == temp.size() - 1) { 
            temp.pop_back();
        } else {
            temp.erase(pos);
        }
        
        auto end_insert = high_resolution_clock::now();
        auto duration_insert = duration_cast<nanoseconds>(end_insert - start_insert);
    
        cout << "Tiempo de borrado en la posición " << pos << ": " << duration_insert.count() << " ns" << endl;
    }
    
    return 0;
}