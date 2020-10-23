/* 1. Write a program, using templates, to sort a list of n elements. Give user the option to perform sorting
using:
 1) Insertion sort
 2) Bubble sort, or
 3) Selection sort.
*/

#include <iostream>
using namespace std;

template<class t>
void bubble_sort(t arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[i+1] < arr[i])
            {
                t temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

template <class t>
void insertion_sort(t arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        t key = arr[i];
        int j = i-1;

        // moving elements which are greater than the 'key'
        // in  the subarray [0,...,i-1], to one position ahead
        // of their current position.
        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

template <class t>
void selection_sort(t arr[], int n)
{
    int i, j;

    for(i=0; i<n-1; i++)
    {
        t min_index = i;

        for(j=i+1; j<n; j++)
            if(arr[min_index] > arr[j])
                min_index= j;

        t temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

template<class t>
void printArray(t arr[], int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

}


template <class t>
void take_array()
{
    cout<<"\nEnter size of List: ";
    int n;
    cin>>n;

    t arr[n];

    for(int i=0; i<n; i++)
    {
        cout<<"\nEnter Element "<<i+1<<": ";
        cin>>arr[i];
    }

    cout<<"\nMENU \n1. Sort Using Bubble Sort. \n2. Sort Using Selection Sort. \n3. Sort Using Insertion Sort."
          "\n\nEnter Your Choice: ";
    int ch;
    cin>>ch;

    switch(ch)
    {
        case 1:
            bubble_sort(arr, n);
            break;

        case 2:
            selection_sort(arr, n);
            break;

        case 3:
            insertion_sort(arr, n);
            break;

        default:
            cout<<"\nInvalid Choice!";
            break;
    }

    cout<<"\nSorted Array: ";
    printArray(arr, n);
    cout<<"\n";
}

int main() {

    char ch = 'y';
    do {

        take_array<int>();
        cout<<"\nContinue(y/n): ";
        cin>>ch;

    }while(ch == 'y');

    return 0;
}
