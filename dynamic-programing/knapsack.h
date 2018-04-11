#ifndef KNAPSACK_H
#define KNAPSACK_H
#define MAXLEN 10
#define UNDEFINE -1
int knapsack(int *weight, int *value, int items, int maxLoad);
int knapsack_as(int *weight, int *value, int items, int maxLoad, int **ks);
int max(int i, int j);
int knapsack_dp(int *weight, int *value, int items, int maxLoad);
#endif
