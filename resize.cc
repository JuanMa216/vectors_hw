#include <iostream>
#include <cassert>
#include <ctime>
#include <fstream>  
#include <cstdlib> 

using namespace std;

template <typename T>
class Vector {
private:
    T* storage_;
    unsigned int capacity_;
    unsigned int size_;

public:
    Vector() {
        capacity_ = 5;
        storage_ = new T[capacity_];
        size_ = 0;
    }  

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
        unsigned int capacity2 = capacity_ + 1;  // Prueba con *1.5, *2, +1, +2.
        T* storage2 = new T[capacity2];
        for (unsigned int i = 0; i < size_; i++) {
            storage2[i] = storage_[i];
        }
        delete[] storage_;
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
};

int main() {
    srand(time(0)); 

    ofstream archivo("datos.dat", ios::out);
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    archivo << "resize+1" << endl;
    archivo << "size capacity" << endl;

    Vector<int> x;
    for (int i = 1; i <= 100000; i++) {
        x.push_back(rand() % 1000);
        if (i % 1000 == 0) {
            archivo << x.size() << " " << x.capacity() << endl;
        }
    }

    archivo.close();

    return 0;
}
