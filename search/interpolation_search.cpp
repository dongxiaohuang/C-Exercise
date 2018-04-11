#include "interpolation_search.h"

int interpolation_search(int list[], int low, int high, int target)
{
  // the list should be in order
  //interpolation formula !
        int mid = low + ((target-list[low])/(list[high]-list[low]))*(high - low);
        if(low <= high) {
                if (list[mid] == target)
                        return mid;
                if(list[mid] > target)
                        return interpolation_search(list, low, mid-1,target);
                if(list[mid] < target)
                        return interpolation_search(list, mid+1, high,target);
        }
        return -1;
}
