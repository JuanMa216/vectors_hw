# Vectors: Insert and Erase Methods

## Overview
The `methods.cc` file contains the implementation of the `insert(index, element)` and `erase(index)` methods for dynamic vectors.

## Implementation

### Insert Method
```cpp
void insert(unsigned int index, T element) {
    assert(index < size_);

    if(index == 0) {
        push_front(element);
        return;
    }

    if (index == size_ - 1) {
        push_back(element);
        return;
    }

    if (size_ == capacity_) {
        resize();
    }

    for (unsigned int i = size_; i > index; i--) {
        storage_[i] = storage_[i - 1];
    }

    storage_[index] = element;
    size_++;
}
```
## Erase Method
```cpp
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
```
## Time Complexity Analysis of `insert(unsigned int index, T element)`

### Breakdown of Complexity:

1. **Base Cases (`push_front` and `push_back`)**  
   - `push_front(element)`: Shifts all elements → **O(n)**  
   - `push_back(element)`: Adds an element at the end → **O(1)**  

2. **Resize Check and Allocation (`resize()`)**  
   - `resize()`: Copies all elements into a new array when capacity is exceeded → **O(n)** in the worst case.  

3. **Element Shifting**  
   - The loop `for (unsigned int i = size_; i > index; i--)` shifts all elements to the right.  
   - In the worst case (inserting at index 0), **n elements** are moved → **O(n)**  

### Overall Complexity:  
- **Worst Case**: Inserting at index `0` with `resize()` triggered → **O(n)**  
- **Best Case**: Inserting at the last position without resizing → **O(1)**  
- **Average Case**: Inserting at any position → **O(n)**  

### Conclusion  
The `insert` method has **O(n) worst-case complexity** due to element shifting. 
## Time Complexity Analysis: `erase(index)`

- **Best Case (O(1))**: If the element to be removed is at the beginning (`index == 0`), the method calls `pop_front()`, which operates in constant time O(1).
- **Best Case (O(1))**: If the element is at the last position (`index == size_ - 1`), it calls `pop_back()`, which also runs in O(1).
- **Worst Case (O(n))**: If the element is somewhere in the middle, all elements after `index` must be shifted left, making this operation O(n) in the worst case.

### Overall Complexity:
- **Best case**: O(1)
- **Worst case**: O(n)
- **Average case**: O(n) (since, on average, half of the elements need to be shifted)

### Conclusion  
The `erase` method has an **O(n) worst-case complexity** due to element shifting. While it is efficient for removing elements at the beginning or end, it becomes costly when deleting elements from the middle, as all subsequent elements must be shifted.

# Vectors: removeDuplicates Function
## Overview
The `duplicate.cc` file contains the implementation of the `removeDuplicates(vector)` function for dynamic vectors.
## Implementation

### removeDuplicates Function
```cpp
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
```
## Time Complexity Analysis: `removeDuplicates(vector)`

- **Best Case (O(n))**: The best case occurs when all elements in the input vector are duplicates (e.g., `{1, 1, 1, 1}`). In this scenario, each element is checked once and skipped after the first occurrence, leading to a **single linear pass** through the input vector.

- **Worst Case (O(n²))**: The worst case occurs when all elements in the vector are unique (e.g., `{1, 2, 3, 4, 5}`). Each new element is compared against all elements already stored in `noDuplicates`, resulting in a **nested loop** where each iteration performs up to `O(n)` comparisons. This leads to an overall complexity of **O(n²)**.

- **Average Case (O(n²))**: On average, the function exhibits **quadratic behavior**, as each element is compared against a growing `noDuplicates` vector, making the number of comparisons dependent on the number of unique elements encountered.

### Overall Complexity:
- **Best case**: O(n)
- **Worst case**: O(n²)
- **Average case**: O(n²)

### Conclusion  
The `removeDuplicates` function has an **O(n²) worst-case complexity** due to the nested loops. While efficient for cases where the input has few duplicates, it becomes costly when processing large lists with many repeated elements. 

# mergeSortedVectors
The `merge.cc` file contains the implementation of the `mergeSortedVectors(Vector<T>& v1, Vector<T>& v2)` function for dynamic vectors.

## Implementation

### mergeSortedVectors Function
```cpp
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
```
# **Stack Implementation**  
The `stack.cc` file contains the implementation of the `stack` class, a data structure based on dynamically resizable vectors.  

## **Overview**  
The `stack` class provides a **Last In, First Out (LIFO)** data structure, implemented using a custom `Vector` class. The `Vector` class dynamically resizes its storage as elements are added, ensuring efficient memory management.  

## **Features**  
- **Dynamic resizing:** The stack grows as needed.  
- **Basic operations:** Supports `push()`, `pop()`, `peek()`, `empty()`, and `size()`.  
- **Exception handling:** Prevents access to empty stacks.

## Implementation

### Stack Class
```cpp

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
```
# Dynamic Array Resizing Analysis
The `resize.cc` program was implemented to generate data for various growth policies and store the results in a `.dat` file. These collected data were then transferred to Google Colab, where graphs were generated to visualize the growth of `capacity_`.  

You can find the graphs and analysis of `capacity_` growth at the following link:  

[View the graphs and analysis here](https://colab.research.google.com/drive/1s-slrx3GuVnw2tHbPj4LS9ZfVcEBO9t9)



