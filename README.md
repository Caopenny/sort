# sort
sort algorithms

[TOC]

## Bubble 

The principle of bubble sorting is very simple. Begin with the first element,
it compares the value of the current one and the next one, and exchange the bigger one to right.



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

