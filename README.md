# sort
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
Shell sort is an improvement over insertin sort. It compares the element 
separated by a gap of several positions. A data element is srted with multiple passes and with each pass gap value
reduces.
### Steps
* Assign gap value as half the length of the array
* Compare element present at a difference of gap value.
* Sort them and reduce the gap value to half and repeat.


### Implementation


```cpp

void shell_sort(vector<int> & num, int len){
    for(int i = len/2; i >0; i=i/2){
        for (int j =i; j<len; j++){
            for (int k=j-i; k>=0;k--){
                if(num[k+i]> num[k]){
                    break;
                }
                else {
                    int temp = num[k+i];
                    num[k+i]=num[k];
                    num[k]=temp;
                }
            }
        }
    }
}



```



## Merge Sort
Thought: Divide and Conquer. This algorithm split a big array into smaller ones, than put them together
### Step

* Split the unsorted array into small array with only one element. Then we compare two array,
merge the n arrays into n/2 arrays
* Repeat step one to get n/4, n/8, ... arrays, until the final array is sorted

### Implementation of Merge Sort
```cpp
void merge_sort(vector<int> & num, int low, int high){

    if(low>=high) return ;


    int mid=(low+high)/2;
    merge_sort(num, low, mid);
    merge_sort(num, mid+1, high);
    merge_array(num, low, high, mid);
}
void merge_array(vector<int>& num, int low, int high, int mid){

    int l_index=low;//index of the left array
    int r_index = mid+1;//index of the right array
    int k=low;//index of num



    int left[mid-low+1];
    int right [high-mid];
    for(int i =0; i< mid-low+1;i++)left[i]=num[low+i];

    for (int i=0; i<high-mid;i++){ right[i]=num[mid+1+i];}


    while ((l_index< mid +1 )&&(r_index<high +1 )){
        if(left[l_index-low]<right[r_index-mid-1]) {
            num[k]=left[l_index-low];
            l_index++;k++;
        }
        else{
            num[k]=right[r_index-mid-1];
            r_index++;k++;
        }
    }


    while (l_index<mid+1){
        num[k]=left[l_index-low];
        l_index++;k++;

    }
    while (r_index<high + 1){
        num[k]=right[r_index-mid-1];
        r_index++;k++;

    }


}

/*我这个实现真是又臭又长【捂脸】*/
```

## Quick Sort

### Implementation of Quick Sort

```cpp
void quick_sort(vector<int> & num, int low, int high){

    if (low>=high) return;
    int key = num[low];
    int lp = low;
    int rp = high;
    while (lp<rp){
        while (num[rp]>=key && rp > lp) rp--;
        while (num[lp]<= key && lp < rp) lp++;
        int temp =num[rp];
        num[rp]=num[lp];
        num[lp]=temp;

    }
    int temp =num[low];
    num[low]=num[lp];
    num[lp]=temp;
    quick_sort( num, low, lp);
    quick_sort(num,  lp+1, high);


}

```


## Heap Sort

**mapping the array to a binary tree**

### Step

* Build a Max Heap. Compare the element with its parent. If the element is 
bigger than parent, exchange it with its parent. Repeat this until the last element is reached
* Max Heaplify: after removing the last element, re-heaplify the heap. Specifically, 
exchange the first element with the last element, then treat the heap with length n-1. 
Then we again max heaplify the heap.
* Repeat step 2, until all the roots are removed.


### Implementation of Heap Sort

```cpp

void heap_sort(vector<int> &num){
    int n =num.size();

    // Build Max Heap
    for(int i =n/2-1; i>=0;i--){
        max_heapify(num, i,num.size()-1);}
    
    for (int  i = n-1; i>0;i--){
        int temp = num[i];
        num[i] = num[0];
        num[0] = temp;
        max_heapify(num, 0,i-1);
    }
}

//
void max_heapify(vector<int> &num, int beg, int end){
    int curr = beg;
    int child = curr * 2 + 1; //the left child of root curr

    while (child <= end){
        if (child + 1 <= end && num[child]< num[child +1])
        {
            child ++;
        }
        if (num[curr]<num[child])
        {
            //if the current index does not contain a bigger value than its child, swap
            int temp = num[curr];
            num[curr]=num[child];
            num[child]=temp;

            //chang index
            curr=child;
            child = curr * 2 +1;
        }
        else {
            break;
        }
    }

}

```

