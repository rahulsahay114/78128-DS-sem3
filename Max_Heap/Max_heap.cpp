#include <iostream>
using namespace std;

class maxheap
{

public:
    int heap_size=0; //no. of elements in the heap
    int size=0; //max size/capacity of heap.
    int* heap;

    //constructor
    maxheap(int s)
    {
        size  = s;
        heap = new int[size];
        heap_size = 0;
    }

    int parent(int x) {return x/2;}

    int left(int x) {return 2*x+1;}
    /*originally return value = 2*x; this works if indices start from 1.
     * But here the indices start from 0. Therefore 2*x will not return the correct left index for a given index 'i'
     * we can fix this by adding an extra 1.*/

    int right(int x) {return 2*x+2;}
    /*originally return value = 2*x; this works if indices start from 1.
     * But here the indices start from 0. Therefore 2*x will not return the correct right index for a given index 'i'
     * we can fix this by adding an extra 1.*/

    void display();
    void max_heapify(int*, int);
    void insert_key(int k);
    void buildmaxheap(int*);
    void increasekey(int* heap, int i, int key);
    void heapsort(int*);

    int heap_max();
    int extract_max();
};

void maxheap::display()
{
    for(int i=0; i<heap_size; i++)
    {
        cout<<heap[i]<<" ";
    }
}

void maxheap::max_heapify(int* heap, int i)
{
    int l = left(i);
    int r = right(i);

    //largest at the given index, then we change it the index value of either left or right in the following comparisons.
    int largest = i;

    if(l <= heap_size && heap[l] > heap[i])
        largest = l;

    if(r <= heap_size && heap[r] > heap[i])
        largest = r;

    if(largest != i)
    {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        max_heapify(heap, largest);
    }
}

void maxheap::buildmaxheap(int* heap)
{
    for(int i = int(heap_size-1)/2; i >=0; i--)
    {
        max_heapify(heap, i);
    }
}

void maxheap::insert_key(int k) {

    if(heap_size == size)
    {
        cout<<"\nOverflow!";
        return;
    }

    else
    {
        int i = heap_size;
        heap_size++;

        heap[i] = k;
        //rebuild the heap
        buildmaxheap(heap);
    }
}

//to increase the value of a node to 'key' at a given index 'i' in the heap 'heap'.
void maxheap::increasekey(int *heap, int i, int key) {

    i--;
    //indices start from 0, therefore we adjust the index value 'i',
    // which was given assuming that the indices start from 1,accordingly

    //key 'k' has to be at least as large as the current value at index 'i'
    if(heap[i] > key)
    {
        cout<<"\nError, key is smaller than current value at given Index.";
        return;
    }

    heap[i] = key; //updating key value at the given index

    /* We start from appending the key at the bottom and then keep travelling
     * upwards until we reach the root (index 0 or i=0) or if the parent is larger than the key given */
    while(i>0 && heap[parent(i)] < heap[i])
    {
        //swapping
        int temp = heap[i];
        heap[i] = heap[parent(i)];
        heap[parent(i)] = temp;

        i = parent(i); //moving upwards by changing the index value to it's parent.
    }
}

int maxheap::heap_max() {

    return heap[0];
}

int maxheap::extract_max() {

    if(heap_size < 0)
    {
        cout<<"Error, Underflow.";
        return -1;
    }

    int max = heap[0];

    heap[0] = heap[heap_size-1]; //'heap_size-1' last index in the 'heap' array.
    heap_size--;
    max_heapify(heap, 0);

    return max;
}


int main() {

    maxheap heap(10);

    heap.insert_key(14);
    heap.insert_key(10);
    heap.insert_key(3);
    heap.insert_key(2);
    heap.insert_key(8);
    heap.insert_key(4);
    heap.insert_key(16);
    heap.insert_key(1);
    heap.insert_key(9);
    heap.insert_key(7);

    cout<<"Original max_heap: "; heap.display();

    heap.increasekey(heap.heap, 4, 11);

    cout<<"\n\nAfter increasekey(heap, 4, 11): ";
    heap.display();

    cout<<"\n\nHeap Maximum: "<<heap.heap_max();

    cout<<"\n\nAfter extract_max(): ";
    heap.extract_max();
    heap.display();

    return 0;
}
