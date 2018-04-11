#include "merging_sort.h"
// merge two ordered list into one list

void merging_sort(int list[], int beg, int end)
{
  int mid = (beg + end)/2;
  if(beg < end)
  {
    merging_sort(list, beg, mid);
    merging_sort(list, mid+1, end);
    mergeSortedArray(list, beg, mid, mid+1, end);
  }
}

void mergeSortedArray(int a[], int lbeg, int lend, int rbeg, int rend)
{
  // good style
  int SIZE = rend +1;
  int pa = lbeg, pb = rbeg, pt = lbeg, tmp[SIZE];
  	while(pa <= lend && pb <= rend){
  		if(a[pa] < a[pb]){
  			tmp[pt++] = a[pa++];
  		}else{
  			tmp[pt++] = a[pb++];
  		}
  	}
  	if(pa > lend){
  		while(pb <= rend){	//left sub array exhausted
  			tmp[pt++] = a[pb++];
  		}
  	}else{
  		while(pa <= lend){	//right sub array exhausted
  			tmp[pt++] = a[pa++];
  		}
  	}

  	//write sorted element in array a
  	for(pt = lbeg; pt <= rend; pt++){
  		a[pt] = tmp[pt];
  	}
}
