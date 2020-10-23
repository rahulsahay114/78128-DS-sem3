/* 2. Given a list of N elements, which follows no particular arrangement, you are required to search an
element x in the list. The list is stored using array data structure.
If the search is successful, the output should be the index at which the element occurs,
otherwise returns -1 to indicate that the element is not present in the list.

Assume that the elements of the list are all distinct. Write a program to perform the desired task. */

#include <iostream>
using namespace std;

int search_el(int a[], int n, int key)
{
    int k = -1;
    for(int i=0; i<n; i++)
        if(a[i] == key)
            k = i+1;

    return k;
}

int main()
{
    int a[5] = {10,14,114,124,2};

    cout<<"\nEnter Key to search: ";
    int key;
    cin>>key;

    int i = search_el(a, 5, key);

    if(i != -1)
        cout<<"\nElement Found at: "<<i;

    else
        cout<<"\nElement not found.";

    return 0;
}