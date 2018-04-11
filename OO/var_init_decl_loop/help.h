int sum_arr(int *l)
{
  int sum = 0;
  for(auto e : l) // wrong
    sum += e;
  return sum;
}
