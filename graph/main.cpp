#include "graph.h"

int main()
{
  MGraph g;
  createMGraph(&g);
  for (auto i = 0; i < g.vertexNum; i++) {
    for (auto j = 0; j < g.vertexNum; j++) {
      /* code */
      cout << g.edg[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
