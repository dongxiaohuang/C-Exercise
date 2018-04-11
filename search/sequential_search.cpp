#include "sequential_search.h"
// better than binary_search iff the list i
int sequential_search(int *list, int len, int target)
{
        for(int i = 0; i < len; ++i)
        {
                if(list[i] == target)
                        return i;
        }
        return -1;
}
