#include "binary_search.h"

int binary_search(int list[], int left, int right, int target)
{
  // the list should be in order
        int mid = (left + right)/2;
        if(left <= right) {
                if (list[mid] == target)
                        return mid;
                if(list[mid] > target)
                        return binary_search(list, left, mid-1,target);
                if(list[mid] < target)
                        return binary_search(list, mid+1, right,target);
        }
        return -1;


}
