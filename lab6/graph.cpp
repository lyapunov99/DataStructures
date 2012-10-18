#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int NODES = 10;

void BFS(bool web[][NODES])
{

  // YOUR CODE HERE
  
  
}

void DFSRecurse(int x, bool web[][NODES], bool breadcrumbs[])
{

  // YOUR CODE HERE


}

void DFS(bool web[][NODES])
{
  bool breadcrumbs[NODES];
  for (int i=1; i < NODES; i++)
    breadcrumbs[i] = false;
  DFSRecurse(0, web, breadcrumbs);
}

void DFSStack(bool web[][NODES])
{
  
  // YOUR CODE HERE
  
  
}

int main()
{
  // create an adjacency matrix for a graph with NODES number of nodes
  bool web[NODES][NODES];
  
  // Initialize it on an empty graph
  for (int i=0; i < NODES; i++)
    for (int j=0; j < NODES; j++)
      web[i][j] = false;
  
  // Add some edges
  web[0][1] = true;
  web[0][4] = true;
  web[0][6] = true;
  web[1][0] = true;
  web[1][2] = true;
  web[1][3] = true;
  web[2][1] = true;
  web[2][3] = true;
  web[3][1] = true;
  web[3][2] = true;
  web[3][4] = true;
  web[4][0] = true;
  web[4][3] = true;
  web[4][6] = true;
  web[4][8] = true;
  web[5][2] = true;
  web[5][6] = true;
  web[5][7] = true;
  web[6][0] = true;
  web[6][4] = true;
  web[6][5] = true;
  web[7][5] = true;
  web[7][8] = true;
  web[8][4] = true;
  web[8][7] = true;
  web[8][9] = true;
  web[9][8] = true;
	
  // Do a BFS
  cout << "My BFS is :" << endl;
  BFS(web);
  cout << endl;
  cout << "One possible solution for a BFS is :" << endl;
  cout << "0 1 4 6 2 3 8 5 7 9 " << endl;
  cout << endl;
	
  // Now do a recursive DFS
  cout << "My recursive DFS is :" << endl;
  DFS(web);
  cout << endl;
  cout << "One possible solution for a recursive DFS is :" << endl;
  cout << "0 1 2 3 4 6 5 7 8 9" << endl;
  cout << endl;

  // Optional: Do a stack-based DFS
  cout << "My stack-based DFS is :" << endl;
  DFSStack(web);
  cout << endl;
  cout << "One possible solution for a stack-based DFS is :" << endl;
  cout << "0 6 5 7 8 9 2 3 4 1" << endl;
  cout << endl;

  return 0;
}
