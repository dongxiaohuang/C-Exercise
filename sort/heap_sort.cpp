#include "heap_sort.h"
#include "helper.h"
// O(nlogn)
/**
Create an empty heap H
Remove each element of Land add it to H
Remove each element of H and add it to L
HALT
**/

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap


// suitable for almost heap except first one
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
//Time Complexity: Time complexity of heapify is O(Logn). Time complexity of createAndBuildHeap() is O(n) and overall time complexity of Heap Sort is O(nLogn).
void heap_sort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/** it cost $Omega(N)$ time**/
// void heap_adjust(int list[], int len)
// {
//   int parent_node_num = len/2 - 1;// start from 1 because using len
//   // initial the heap
//   for(int i = parent_node_num; i >= 0; --i)
//   {
//     int max_child_index = 2*i + 1;
//     if(2*i+2 <= len - 1 && list[2*i+2] > list[max_child_index])
//       max_child_index = 2*i + 2;
//     if(list[max_child_index] > list[i])
//       swap(list[max_child_index],list[i]);
//   }
// }
