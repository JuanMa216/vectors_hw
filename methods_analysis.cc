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
    Vector<int> n(100);
    
    RandomVector(&n, 100);
    Vector<int> temp1 = n; // Copia 1.
    Vector<int> temp2 = n; // Copia 2.
    Vector<int> temp3 = n; // Copia 3
    Vector<int> temp4 = n; // Copia 4.
    Vector<int> temp5 = n; // Copia 5.
    Vector<int> temp6 = n; // Copia 6.
    Vector<int> temp7 = n; // Copia 7.
    Vector<int> temp8 = n; // Copia 8.
    Vector<int> temp9 = n; // Copia 9.
    Vector<int> temp10 = n; // Copia 10.
    Vector<int> tempfin = n; // Copia final
    //cout <<"Tamaño: " << n.size() << endl;

    // Medir tiempo de inserción(Posicion 0);
    unsigned int pos = 0; // Posición específica para medir el tiempo de inserción
    auto start_insert = high_resolution_clock::now();
    temp1.insert(pos, 42);
    auto end_insert = high_resolution_clock::now();
    auto duration_insert = duration_cast<nanoseconds>(end_insert - start_insert);
    // Mostrar el tiempo en pantalla
    cout << "Tiempo de inserción en la posición " << pos << ": " << duration_insert.count() << " ns" << endl;

    // Medir tiempo de inserción(Posicion 10);
    pos = 10; // Posición específica para medir el tiempo de inserción
    start_insert = high_resolution_clock::now();
    temp2.insert(pos, 42);
    end_insert = high_resolution_clock::now();
    duration_insert = duration_cast<nanoseconds>(end_insert - start_insert);
    // Mostrar el tiempo en pantalla
    cout << "Tiempo de inserción en la posición " << pos << ": " << duration_insert.count() << " ns" << endl;

    // Medir tiempo de inserción(Posicion 20);
    pos = 20; // Posición específica para medir el tiempo de inserción
    start_insert = high_resolution_clock::now();
    temp3.insert(pos, 42);
    end_insert = high_resolution_clock::now();
    duration_insert = duration_cast<nanoseconds>(end_insert - start_insert);
    // Mostrar el tiempo en pantalla
    cout << "Tiempo de inserción en la posición " << pos << ": " << duration_insert.count() << " ns" << endl;

    // Medir tiempo de inserción(Posicion 30);
    pos = 30; // Posición específica para medir el tiempo de inserción
    start_insert = high_resolution_clock::now();
    temp4.insert(pos, 42);
    end_insert = high_resolution_clock::now();
    duration_insert = duration_cast<nanoseconds>(end_insert - start_insert);
    // Mostrar el tiempo en pantalla
    cout << "Tiempo de inserción en la posición " << pos << ": " << duration_insert.count() << " ns" << endl;

    // Medir tiempo de inserción(Posicion 40);
    pos = 40; // Posición específica para medir el tiempo de inserción
    start_insert = high_resolution_clock::now();
    temp5.insert(pos, 42);
    end_insert = high_resolution_clock::now();
    duration_insert = duration_cast<nanoseconds>(end_insert - start_insert);
    // Mostrar el tiempo en pantalla
    cout << "Tiempo de inserción en la posición " << pos << ": " << duration_insert.count() << " ns" << endl;

    // Medir tiempo de inserción(Posicion 50);
    pos = 50; // Posición específica para medir el tiempo de inserción
    start_insert = high_resolution_clock::now();
    temp6.insert(pos, 42);
    end_insert = high_resolution_clock::now();
    duration_insert = duration_cast<nanoseconds>(end_insert - start_insert);
    // Mostrar el tiempo en pantalla
    cout << "Tiempo de inserción en la posición " << pos << ": " << duration_insert.count() << " ns" << endl;

    // Medir tiempo de inserción(Posicion 60);
    pos = 60; // Posición específica para medir el tiempo de inserción
    start_insert = high_resolution_clock::now();
    temp7.insert(pos, 42);
    end_insert = high_resolution_clock::now();
    duration_insert = duration_cast<nanoseconds>(end_insert - start_insert);
    // Mostrar el tiempo en pantalla
    cout << "Tiempo de inserción en la posición " << pos << ": " << duration_insert.count() << " ns" << endl;

    // Medir tiempo de inserción(Posicion 70);
    pos = 70; // Posición específica para medir el tiempo de inserción
    start_insert = high_resolution_clock::now();
    temp8.insert(pos, 42);
    end_insert = high_resolution_clock::now();
    duration_insert = duration_cast<nanoseconds>(end_insert - start_insert);
    // Mostrar el tiempo en pantalla
    cout << "Tiempo de inserción en la posición " << pos << ": " << duration_insert.count() << " ns" << endl;

    // Medir tiempo de inserción(Posicion 80);
    pos = 80; // Posición específica para medir el tiempo de inserción
    start_insert = high_resolution_clock::now();
    temp9.insert(pos, 42);
    end_insert = high_resolution_clock::now();
    duration_insert = duration_cast<nanoseconds>(end_insert - start_insert);
    // Mostrar el tiempo en pantalla
    cout << "Tiempo de inserción en la posición " << pos << ": " << duration_insert.count() << " ns" << endl;

    // Medir tiempo de inserción(Posicion 90);
    pos = 90; // Posición específica para medir el tiempo de inserción
    start_insert = high_resolution_clock::now();
    temp10.insert(pos, 42);
    end_insert = high_resolution_clock::now();
    duration_insert = duration_cast<nanoseconds>(end_insert - start_insert);
    // Mostrar el tiempo en pantalla
    cout << "Tiempo de inserción en la posición " << pos << ": " << duration_insert.count() << " ns" << endl;

    // Medir tiempo de inserción(Posicion 90);
    pos = 100; // Posición específica para medir el tiempo de inserción
    start_insert = high_resolution_clock::now();
    tempfin.insert(pos, 42);
    end_insert = high_resolution_clock::now();
    duration_insert = duration_cast<nanoseconds>(end_insert - start_insert);
    // Mostrar el tiempo en pantalla
    cout << "Tiempo de inserción en la posición " << pos << ": " << duration_insert.count() << " ns" << endl;
    
    return 0;
}
