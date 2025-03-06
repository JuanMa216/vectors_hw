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
