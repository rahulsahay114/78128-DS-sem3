/*3. Given a list of N elements, which is sorted in ascending order, you are required to search an element x
in the list.

The list is stored using array data structure. If the search is successful, the output should be
the index at which the element occurs, otherwise returns -1 to indicate that the element is not present
in the list.

Assume that the elements of the list are all distinct. Write a program to perform the desired
task.*/

#include <iostream>
using namespace std;

int search_el(int arr[], int n, int key)
{
    int flag = -1;

    for(int i=0; i<n; i++)
    {
        if(arr[i] == key)
        {
            flag = i;
        }
    }

    return flag;
}

int main() {

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    cout<<"\nEnter Key to Find: ";
    int key;
    cin>>key;

    int index = search_el(arr, 10, key);

    if(index == -1)
    {
        cout<<"\nNot Found!";
    }

    else
    {
        cout<<"\nFound at: "<<index+1;
    }

    return 0;
}
