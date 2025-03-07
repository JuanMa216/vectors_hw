#include <iostream>
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
    unsigned int capacity () const {
        return capacity_;
    }

    unsigned int size() const {
        return size_;
    }

    void push_back(const T& elem) {
        if (size_ == capacity_)
        {
            resize();
        }
    storage_[size_] = elem;
    size_++;
    }

    void pop_back() {
        if(size_ == 0) throw std::underflow_error("Cannot pop from an empty array");
        size_--;
    }

    bool empty() const {return size_ == 0;}

    T& at(unsigned int pos){
        assert(pos < size_ && pos>=0); 
        return storage_[pos];
    }
    
    const T& at(unsigned int pos) const {
        assert(pos < size_ && pos>=0);
        return storage_[pos];
    }

};

template <typename T>
class stack {
    private:
    Vector<T> data;
    int top_ = -1;

    public:
    stack() {}

    void push(const T& elem) {
        data.push_back(elem);
        top_ = data.size() - 1;
    }

    void pop() {
        if (data.size() == 0) throw std::underflow_error("Cannot pop from an empty stack");
        data.pop_back();
        top_--;
    }

    T& peek() {  
        if (data.empty()) {
            throw std::out_of_range("Error: Intento de hacer peek() en un stack vacío.");
        }
        return data.at(top_);  
    }
    
    const T& peek() const {  
        if (data.empty()) {
            throw std::out_of_range("Error: Intento de hacer peek() en un stack vacío.");
        }
        return data.at(top_);  
    }

    bool empty() const {
        return data.empty();
    }

    unsigned int size() const {
        return data.size();
    }

    void print() {
        if(data.empty()) return;

        for (int i = top_; i >= 0; i--)
        {
            cout << data.at(i) << " ";
        }
    cout << endl;
    }
    
};

int main() {
    stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.print(); //Expected: 5 4 3 2 1
    stack.pop();
    stack.pop();
    stack.print(); //Expected: 3 2 1
    cout << stack.peek() << endl; //Expected: 3
    stack.peek() = 4;
    stack.print(); //Expected: 4 2 1
    cout << stack.size() << endl; //Expected: 3
    return 0;
}