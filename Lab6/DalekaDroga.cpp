//
//  main.cpp
//  dijkstry
//
//  Created by Sophie Popow on 25/04/2020.
//  Copyright © 2020 Sophie Popow. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

# define INF 0x3f3f3f3f

int dijkstry(int** graph, int start, int end, int n){
  queue <int> Nodes;
  
  int visited[n];
  int distance[n];
  
  for (int i = 0; i < n; i++) {
      visited[i] = false;
      distance[i] = INF;
  }
  
  visited[start] = true;
  distance[start] = 0;
  Nodes.push(start);
  
  while(!Nodes.empty()){
      int Node = Nodes.front();
      Nodes.pop();
      
      for (int i = 0; i < n; i++) {
          if(graph[Node][i] && !visited[i]){
              visited[i] = true;
              Nodes.push(i);
          }
          if (graph[Node][i] && distance[i] > distance[Node] + graph[Node][i]) {
              distance[i] = distance[Node] + graph[Node][i];
          }
      }
  }
  
  return distance[end];
}



int main(int argc, const char * argv[]) {
    int n,k;
    int start,end;
    
    cin>>n>>k;
    cin>>start>>end;
    
    int** graph = new int*[n];
    int* graphRows = new int[n*n];
   
    for (int i =0; i<n; i++) {
        graph[i] = graphRows + (i*n);
    }
    
    int A,B,X;
    for (int i = 0; i < k; i++) {
        cin>>A>>B>>X;
        graph[A][B] = X;
        graph[B][A] = X;
    }
    
    cout<<dijkstry(graph, start, end, n)<<endl;
    
    return 0;
}
