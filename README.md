# sort
sort algorithms
[Sorting Algorithm Animations](https://www.toptal.com/developers/sorting-algorithms)


## Bubble 

The principle of bubble sorting is very simple. Begin with the first element,
it compares the value of the current one and the next one, and exchange the bigger one to right.

### Implementation of Bubble Sorting

```cpp
void bubble_sort(vector<int> &num){
    for (unsigned i=0; i<num.size()-1;i++){
        for(unsigned j = 0; j < num.size()- i-1;i++){
            if(num[j]>num[j+1]){     //if the element on the left is bigger, swap it to the right
                int temp =num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
}
```

### Complexity
The complexity of it is O(n^2)





## Insertion Sorting
Basically, the principle of insertion sorting is from left to right, we pick one element out. Then we compare this element with the elements before it, and find a suitable place for it. In this way, the part of the array before this element is sorted.

### Steps

* Begin from the first element, we pick the current element x, compare it with the element y before it. If x<y, then we exchange the position of these two elements.
* Repeat this operation for all the elements before it, until all the elements before it are sorted.
* Move to the next element, insert it to the sorted part before it, until we move to the last elements.


### Implementation of Insertion Sorting

```cpp
void insertion_sort(vector<int> &num){
    for(unsigned i = 1; i < num.size(); i++){
        for(unsigned j = i; j > 0;j--){
            if(num[j]<num[j-1]){
                int temp=num[j];
                num[j]=num[j-1];
                num[j-1]=temp;
            }
        }
    }
}
```


### Complexity
Time complexity O(n^2), space complexity O(n)


## Selection Sort
For selection sort, each time it find the least or the biggest element and put it on the head of the array. 

### Step

* Begin with the first element. Choose the smallest element behind it. Exchange it with the element we are on;
* Move to next element, repeat the first step until the last element.


### Implementation
```cpp

void selection_sort(vector<int> & num){
    for (unsigned i=0; i< num.size();i++){
        int min =i;
        for(unsigned j=i + 1;j<num.size();j++){
            if (num[j] < num[min]) min=j;
        }
        int temp = num[i];
        num[i] = num[min];
        num[min]=temp;

    }

}
```
### Complexity
The time complexity if O(n^2), space complexity is O(n)


## Shell Sort


## Merge Sort

## Quick Sort


## Heap Sort


