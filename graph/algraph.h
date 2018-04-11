#ifndef AL_GRAPH_H
#define AL_GRAPH_H
#include <iostream>
#define INFINITY 65535
using namespace std;
#define MAXLEN = 100;
typedef struct EdgeNode{
  int index;
  int weight;
  EdgeNode* next = NULL;
}EdgeNode;

typedef struct VertexNode{
  int index;
  EdgeNode* firstNode = NULL;
};

typedef struct ALGraph{
  VertexNode vex[MAXLEN];
  int vetexNum;
};

void createALGraph(ALGraph* ag){
  cout << "please input the length of vertex" <<endl;
  cin >> ag->vetexNum;
  for (auto i = 0; i < ag->vetexNum; i++) {
    cout << " please input the "<<i << " vertex"<< endl;
    cin >> vex[i].index;
  }
  for (auto i = 0; i < ag->vetexNum; i++) {
    char flag;
    int n,w;
    cout << "is there any adjacant node, 'y' or 'n'"<<endl;
    cin >> flag
    while(flag != 'n'){
      cout << "please input the adjacant node for node"<<i<<endl;
      cin >> n;
      cout << "please input the weight between them"<<endl;
      cin >> w;

      cout << "continue? 'y' or 'n'"<<endl;
      cin >> flag
      }
  }

}
#endif
