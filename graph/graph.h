#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#define INFINITY 65535
#define MAXLEN 100
using namespace std;

typedef char `VertexType;
typedef int EdgeType;

typedef struct MGraph{
  VertexType vex[MAXLEN];
  EdgeType edg[MAXLEN][MAXLEN];
  int vertexNum;
  int edgeNum;
}MGraph;


void createMGraph(MGraph* m){
  cout << "please input the number of vertex"<<endl;
  cin >>m->vertexNum ;
  cout << "please input the number of edge"<<endl;
  cin >>m->edgeNum ;
  for(auto i = 0; i < m->vertexNum; ++i){
    cout << "please input the vertex" << endl;
    cin >> m->vex[i];
  }

  // initialize the adjacancy matrix
  for (auto i = 0; i < m->vertexNum; i++) {
    for (auto j = 0; j < m->vertexNum; j++) {
      if(i ==j)
        m->edg[i][j] = 0;
      else
       m->edg[i][j] = INFINITY;

    }
  }

  for(auto i = 0; i < m-> edgeNum;++i){
    int idx_i, idx_j;
    cout << "please input the i and j for the adjacancy matrix"<<endl;
    cin >> idx_i;
    cin >> idx_j;
    cout << endl;
    cout << "please input the weight"<<endl;
    cin >>m->edg[idx_i][idx_j];
    m->edg[idx_j][idx_i] = m->edg[idx_i][idx_j];
  }
}
#endif
