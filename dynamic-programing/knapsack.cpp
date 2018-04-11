#include "knapsack.h"
#include <iostream>
using namespace std;
int knapsack(int *weight, int *value, int items, int maxLoad ){
  int n = items -1;
  int result;
  if(n < 0 || maxLoad ==0)
    return 0;
  if(weight[n] > maxLoad)
    return knapsack(weight, value, items-1, maxLoad);
  else{
    int temp1 = knapsack(weight, value, items-1, maxLoad);
    int temp2 = knapsack(weight, value, items-1, maxLoad-weight[n])+value[n];
    result = max(temp1, temp2);
  }
  return result;
}


int knapsack_as(int *weight, int *value, int items, int maxLoad, int **ks){
  int n = items -1;
  int c = maxLoad -1;
  int result;
  if(ks[n][c] != UNDEFINE){
    return ks[n][c];
  }
  if(n < 0 || maxLoad ==0)
    {ks[n][c] = 0;
    return 0;}
  if(weight[n] > maxLoad)
  {
    ks[n][c] = knapsack(weight, value, n, maxLoad);
    return knapsack(weight, value, n, maxLoad);
  }
  else{
    int temp1 = knapsack(weight, value, n, maxLoad);
    int temp2 = knapsack(weight, value, n, maxLoad-weight[n])+value[n];
    result = max(temp1, temp2);
    ks[n][c] = result;
    cout << "n= " <<n << "c = "<<c << " : "<<result;
  }
  return result;
}

int max(int i, int j){
  return i>j ? i:j;
}

int knapsack_dp(int *weight, int *value, int items, int maxLoad){
  //every weight and value and gain
  int **ks = new int*[items];
  for (auto i = 0; i < items; i++) {
    ks[i] = new int[maxLoad];
  }
  for(auto i =0; i < items; i++){
    for(auto j = 0; j < maxLoad; j++)
    {
      ks[i][j] = UNDEFINE;
    }
  }
  int result = knapsack_as(weight, value, items, maxLoad, ks);
  for(auto i =0; i < items; i++){
    for(auto j = 0; j < maxLoad; j++)
    {
      cout << ks[i][j] ;;
    }
    cout << endl;
  }
  delete [] ks;
  return result;
}
