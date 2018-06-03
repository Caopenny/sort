#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> &num);
void bubble_sort(vector<int> &num);
void selection_sort(vector<int> & num);
void heap_sort(vector<int> &num);
void max_heapify(vector<int> & num, int beg, int end);
void merge_array(vector<int> & num, int low, int high, int mid);
void merge_sort(vector<int> & num, int low, int high);
void shell_sort(vector<int> & num, int len);
void quick_sort(vector<int> & num, int low, int high);







int main() {


    vector<int> L ;
    srand(7);





//bubble sorting
    for (int i=0;i<10;i++){L.push_back(rand()%50+1);}
    cout<<"\n Before Insertion sorting"<<endl;
     for (int i=0;i<10;i++) cout<<L[i]<<' ';
     bubble_sort(L);
     cout<<"\n After Bubble sorting"<<endl;
    for (int i=0;i<10;i++) cout<<L[i]<<' ';
    L.clear();

//insertion sorting
    for (int i=0;i<10;i++){L.push_back(rand()%50+1);}
    cout<<"\n Before Insertion sorting"<<endl;
    for (int i=0;i<10;i++) cout<<L[i]<<' ';
    insertion_sort(L);
    cout<<"\n After Insertion sorting"<<endl;
    for (int i=0;i<10;i++) cout<<L[i]<<' ';
    L.clear();

//insertion sorting
    for (int i=0;i<10;i++){L.push_back(rand()%50+1);}
    cout<<"\n Before Selection sorting"<<endl;
    for (int i=0;i<10;i++) cout<<L[i]<<' ';
    selection_sort(L);
    cout<<"\n After Selection sorting"<<endl;
    for (int i=0;i<10;i++) cout<<L[i]<<' ';
    L.clear();

//heap sorting
    for (int i=0;i<10;i++){L.push_back(rand()%50+1);}
    cout<<"\n Before Heap sorting"<<endl;
    for (int i=0;i<10;i++) cout<<L[i]<<' ';
    heap_sort(L);
    cout<<"\n After Heap sorting"<<endl;
    for (int i=0;i<10;i++) cout<<L[i]<<' ';
    L.clear();



//merge sorting
    for (int i=0;i<10;i++){L.push_back(rand()%50+1);}
    cout<<"\n Before Merge sorting"<<endl;
    for (int i=0;i<10;i++) cout<<L[i]<<' ';
    merge_sort(L, 0, L.size()-1);
    cout<<"\n After Merge sorting"<<endl;
    for (int i=0;i<10;i++) cout<<L[i]<<' ';
    L.clear();



//Shell sorting
    for (int i=0;i<10;i++){L.push_back(rand()%50+1);}
    cout<<"\n Before Shell sorting"<<endl;
    for (int i=0;i<10;i++) cout<<L[i]<<' ';
    shell_sort(L, L.size());
    cout<<"\n After Shell sorting"<<endl;
    for (int i=0;i<10;i++) cout<<L[i]<<' ';
    L.clear();


    //Quick sorting
    for (int i=0;i<10;i++){L.push_back(rand()%50+1);}
    cout<<"\n Before Quick sorting"<<endl;
    for (int i=0;i<10;i++) cout<<L[i]<<' ';
    quick_sort(L, 0,L.size()-1);
    cout<<"\n After Quick sorting"<<endl;
    for (int i=0;i<10;i++) cout<<L[i]<<' ';
    L.clear();

    return 0;

}


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




void bubble_sort(vector<int> &num){
    for (unsigned i=0; i<num.size()-1;i++){
        for(unsigned j = 0; j < num.size()- i-1;j++){
            if(num[j]>num[j+1]){     //if the element on the left is bigger, swap it to the right
                int temp =num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }

}









