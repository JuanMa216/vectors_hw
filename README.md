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

- **Best Case (O(n))**: If the input vector already contains unique elements, the function simply iterates through it once, adding each element to the new vector without needing duplicate checks. This results in O(n) complexity.

- **Worst Case (O(n²))**: If every element in the input vector is a duplicate (e.g., `{1, 1, 1, 1, 1}`), the function compares each new element with all elements in `noDuplicates`, leading to a nested loop where each iteration performs up to `O(n)` comparisons, resulting in an overall complexity of O(n²).

- **Average Case (O(n²))**: Since each element needs to be compared against the growing `noDuplicates` vector, the function exhibits quadratic behavior in the average case.

### Overall Complexity:
- **Best case**: O(n)
- **Worst case**: O(n²)
- **Average case**: O(n²)

### Conclusion  
The `removeDuplicates` function has an **O(n²) worst-case complexity** due to the nested loops. While efficient for cases where the input has few duplicates, it becomes costly when processing large lists with many repeated elements. 
