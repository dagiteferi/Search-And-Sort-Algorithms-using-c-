
#include <iostream>
#include <cmath> // header for floor function
using namespace std;

// Function prototypes
void accept_array(int array[], int n); // Function to insert size & element of array. Defined after int main().
int sequential_search(int array[], int x,int n); // Function to do sequential search.
int Binary_Search(int array[], int x,int n,int rt,int lt); // Binary search without Recursive ascending order.
int Binary_search_Recursive(int array[], int x,int n,int rt,int lt); // Function to do Binary search ascending order.
int Binary_Search_descending (int array[], int x,int n,int rt,int lt); // Binary search of descending order.
void Bubble_sort(int array[],int n); // Bubble sort function prototype. Defined after int main().
void Bubble_sort_descending(int array[],int n); // Bubble sort descending function prototype. Defined after int main().
void Insertion_sort(int array[],int n,int key); // Insertion sort function prototype. Defined after int main().
void selection_sort(int array[],int n,int sml_idx); // Selection sort function prototype. Defined after int main().

int main()
{
    int n, x, rt, lt, key, sml_idx;
    int choice;
    char choice1;
    cout << "enter the size of array: ";
    cin >> n;
    int array[n];
    accept_array(array , n); // Call accept array function to accept array elements from user.

    cout << "What do you want to do on the inserted array :" << endl;
    cout << "Enter '1' for Searching of array: " << endl;
    cout << "Enter '2' for Sorting of array: " << endl;
    cin >> choice;

    // If user chooses to search in the array
    if(choice == 1){
        cout << "enter the value do you want to search from the array: ";
        cin >> x;
        cout << "ok!! for Searching array you have four option: " << endl;
        cout << "enter '@' for sequential search: " << endl;
        cout << "enter '#' for Binary Search ascending: " << endl;
        cout << "enter '%' for Binary search Recursive: " << endl;
        cout << "enter '&' for Binary Search for descending: " << endl;
        cin >> choice1;

        // Call the search function based on user's choice
        if(choice1 == '@'){
            sequential_search(array ,x, n);
        } else if(choice1 == '#') {
            Binary_Search(array,x,n, rt, lt);
        } else if(choice1 == '%') {
            Binary_search_Recursive(array,x,n, rt, lt);
        } else if(choice1 == '&') {
            Binary_Search_descending ( array,  x, n, rt, lt);
        } else {
            cout << "incorrect option " << endl;
            return 0;
        }
    }
    // If user chooses to sort the array
    else if(choice == 2){
        cout << "ok!! for Sorting array you have four option: " << endl;
        cout << "enter 'A' for Bubble sort: " << endl;
        cout << "enter 'B' for Bubble sort descending order " << endl;
        cout << "enter 'C' for Insertion sort: " << endl;
        cout << "enter 'D' for selection sort: " << endl;
        cin >> choice1;

        // Call the  sort function based on user's choice
        if(choice1 == 'A'){
            Bubble_sort(array, n);
            cout << "Sorted array using Bubble sort :" << endl;
            for(int i=0; i < n; i++){
                cout << array[i] << " ";
            }
        } else if(choice1 == 'B') {
            Bubble_sort_descending(array, n);
            cout << "Sorted array using Bubble sort descending :" << endl;
            for(int i=0; i < n; i++){
                cout << array[i] << " ";
            }
        } else if(choice1 == 'C') {
            Insertion_sort(array, n, key);
            cout << "Sorted array using Insertion sort :" << endl;
            for(int i=0; i < n; i++){
                cout << array[i] << " ";
            }
        } else if(choice1 == 'D') {
            selection_sort(array, n, sml_idx);
            cout << "Sorted array using selection sort :" << endl;
            for(int i=0; i < n; i++){
                cout << array[i] << " ";
            }
        } else {
            cout << "incorrect option " << endl;
            return 0;
        }
    } else {
        cout << "incorrect option " << endl;
        return 0;
    }
}
//function definations

void accept_array(int array[], int n){
    for(int i=0;i<n; i++){
        cout<<"enter the element of array: ";
        cin>>array[i];
    }

}
int sequential_search(int array[], int x,int n){ //x is the value to be search and n is the size of array.
    for(int i=0;i<n; i++){
            if (array[i] == x){
                cout<<x<<" the element you searched in found at index of  "<<i<<endl;
                return i;
            }

        }
              cout<<x<<" the element you searched is not found "<<endl;
              return (-1);

}

int Binary_Search(int array[], int x,int n,int rt,int lt) {
     lt = 0, rt = n - 1;
     int mid = floor((rt+lt)/2);
    while(lt <= rt) {
        mid = (lt + rt)/2;
        if(array[mid] == x){

            cout<<x<<" the element you searched in found at index of  "<<mid<<endl;
            return mid;
        }else if(x<array[mid]){
         rt = mid - 1;
    }else{
       lt = mid + 1;
    }
}
cout<<x<<" is not found in the list"<<endl<<endl;
return -1;
}

int Binary_search_Recursive(int array[], int x,int n, int rt, int lt){
    int mid = floor((rt+lt)/2);
    while (lt >= rt){
        if (array[mid]== x){
            cout<<x<<" the element you searched is found at index of using binary search "<<mid<<endl;
            return mid;
        }
        if(lt==rt){
            cout<<x<<" the element you searched is not found "<<endl;
            return(-1);
        }
        if(array[mid]>x){
            return Binary_search_Recursive(array,x,n, rt, mid-1);
        }
        if(array[mid]<x){
            return Binary_search_Recursive(array,x,n, mid+1, lt);
        }
    }
}
int Binary_Search_descending(int array[], int x, int n, int rt, int lt) {
    int mid = floor((rt+lt)/2);
    while (lt >= rt){
    if (lt <= rt) {
        int mid = (rt + lt) / 2;
        }if (array[mid] == x) {
            cout << x << " the element you searched is found at index of using binary search " << mid << endl;
            return mid;
        }
        if (array[mid] < x) {
            return Binary_Search_descending(array, x, n, rt, mid - 1);
        }
        if (array[mid] > x) {
            return Binary_Search_descending(array, x, n, mid + 1, lt);
        }

    }

    cout << x << " the element you searched is not found " << endl;
    return -1;
}


void Bubble_sort(int array[], int n) {
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n-i; j++) {
            if(array[j] > array[j+1]) {
                // Swap
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void Bubble_sort_descending(int array[],int n) {
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n-i; j++) {
            if(array[j] < array[j+1]) {
                // Swap
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void Insertion_sort(int array[],int n,int key){
    for(int i=1;i<n;i++){
        key=array[i];
        int j =i-1;
        while(j>=0 && array[j]>key){
                //swap
            array[j+1]=array[j];
        j=j-1;
        array[j+1]=key;


        }

    }

}
void selection_sort(int array[],int n,int sml_idx){
    for(int i=0;i<n-1; i++){
        sml_idx=i;
        for(int j=i+1;j<n;j++){
            if(array[j]<array[sml_idx]){
                //swap
                    array[sml_idx]=array[j];
                    array[j+1]=sml_idx;

            }
        }
    }


}





