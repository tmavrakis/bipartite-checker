#include "LEDA/graph/graph.h"
#include "LEDA/core/list.h"
#include <string>
#include <iostream>
#include "LEDA/graph/node_array.h"
#include <time.h>

using namespace leda;
using namespace std;

list<node> my_BFS(const graph& G, node s, node_array<int>& dist, node_array<edge>& pred){
  list<node> tempL;
  list<node> nList;

  nList.append(s);
  tempL.append(s);
  node v = nList.head(); //return the first element of the list
  dist[v] = 0; //level of root dld 0

  while(tempL.empty() != true){
    edge e;
    v = tempL.pop();
    forall_adj_edges(e, v){
      node w = G.target(e);
      pred[w] = e;

      if(dist[w] == -1) dist[w] = dist[v] + 1;

      if(!(nList.search(w))){
        nList.append(w);
        tempL.append(w);
      }
    }
  }

  return nList;
}

bool my_bipar_checker(const graph& G, list<node>& A, list<node>& B){
  bool anw; 
  int bipar = 2;

  node s;
  s =	G.choose_node();
  node_array<int> dist(G, -1);
  node_array<edge> pred(G);

  list<node> BFS_list = my_BFS(G, s, dist, pred);

  edge e;
  forall_edges(e, G){
    node w = G.target(e);
    node u = G.source(e);
    if(dist[w] != -1 && dist[u] != -1){
      if(((dist[w]%2 == 0) && (dist[u]%2 == 0)) || ((dist[w]%2 == 1) && (dist[u]%2 == 1))){
        bipar = 0;
        break;
      }
      else{
        if(dist[w]%2 == 0 && !(A.search(w))){
          A.append(w);
        }
        else if(dist[w]%2 == 1 && !(B.search(w))){
          B.append(w);
        }
      }
    }
  }

  if(bipar == false) return anw = false;
  else return anw = true;
}

void makeGraph1(graph& G,int num){
  node v[4];

  for (int j = 0; j < num/4; j++)
  {
    v[0] = G.new_node();
    for(int i = 1; i < 4; i++)
    {
      v[i] = G.new_node();
      G.new_edge(v[i-1], v[i]);
      G.new_edge(v[i], v[i-1]);
    }
    G.new_edge(v[3], v[0]);
  }

  list<node> V = G.all_nodes();

  for (unsigned i = 0; i < (num/4 - 1)*4; i++)
  {
    G.new_edge(V.inf(V.get_item(i+4)), V.inf(V.get_item(i)));
    G.new_edge(V.inf(V.get_item(i)), V.inf(V.get_item(i+4)));
  }

}

void makeGraph2(graph& G, int num){
  node u[3];
  for(int i = 0; i < num; i++){
    u[i] = G.new_node();
  }
  list<node> V = G.all_nodes();

  G.new_edge(V.inf(V.first()), V.inf(V.last()));
  G.new_edge(V.inf(V.last()), V.inf(V.first()));

  node v;
  forall_nodes(v, G){
    if(v != V.inf(V.last())){
      G.new_edge(v,V.inf(V.succ(V.search(v))));
      G.new_edge(V.inf(V.succ(V.search(v))), v);
    }
  }

}

void makeGraph3(graph& G, int num){
  node v1[num], v2[num], v3[num], v4[num];

  //"seams" from level i to level i+1
  for(int i = 0; i < num; i++){
    v1[i] = G.new_node();
    v2[i] = G.new_node();
    v3[i] = G.new_node();
    v4[i] = G.new_node();

    //from level 1 to level 2
    G.new_edge(v1[i], v2[i]);
    G.new_edge(v2[i], v1[i]);
    //from level 2 to level 3 
    G.new_edge(v2[i], v3[i]);
    G.new_edge(v3[i], v2[i]);
    //from level 3 to level 4 
    G.new_edge(v3[i], v4[i]);
    G.new_edge(v4[i], v3[i]);
  }

  
  srand ( time(NULL) ); 
  int rand2 = rand() % num;
  int rand3 = rand() % num;

  //"seams" from rand node of level i to level i+1
  for(int i = 0; i < num; i++){
    G.new_edge(v1[rand1], v2[i]);
    G.new_edge(v2[i], v1[rand1]);
  
    G.new_edge(v2[rand2], v3[i]);
    G.new_edge(v3[i], v2[rand2]);
  
    G.new_edge(v3[rand3], v4[i]);
    G.new_edge(v4[i], v3[rand3]);
  }
  //new random nodes
  rand1 = rand() % num;
  rand2 = rand() % num;
  rand3 = rand() % num;
  int rand4 = rand() % num;

  G.new_edge(v1[rand1], v3[rand3]);
  G.new_edge(v3[rand3], v1[rand1]);

  G.new_edge(v2[rand2], v4[rand4]);
  G.new_edge(v4[rand4], v2[rand2]);
}

void menu(graph& G){
  int input;
  std::cout << "MENU\n" << "Choose type of the graph:\n"
  << "1)Synthetic Graph nested square\n2)Cycle Graph\n3)Synthetic Graph of 4 levels" << '\n';

  std::cin >> input;

  std::cout << "Choose the number of nodes and edges." << '\n';
  if(input == 1){
    std::cout << "1)n = 10000, m = 19996\n2)n = 40000, m = 79996\n3)n = 90000 m = 179996" << '\n';
    std::cin >> input;
    if(input == 1) makeGraph1(G, 10000);
    else if(input == 2) makeGraph1(G, 40000);
    else if(input == 3) makeGraph1(G, 90000);
  }
  else if(input == 2){
    std::cout << "1)n = 10001, m = 10001\n2)n = 40001, m = 40001\n3)n = 90001 m = 90001" << '\n';
    std::cin >> input;
    if(input == 1) makeGraph2(G, 10001);
    else if(input == 2) makeGraph2(G, 40001);
    else if(input == 3) makeGraph2(G, 90001);
  }
  else if(input == 3){
    std::cout << "1)n = 500\n2)n = 1000\n3)n = 1500" << '\n';
    std::cin >> input;
    if(input == 1) makeGraph3(G, 500);
    else if(input == 2) makeGraph3(G, 1000);
    else if(input == 3) makeGraph3(G, 1500);
  }
}

int main(int argc, char** argv){

  graph G;
  list<node> A;
  list<node> B;
  list<node> C;
  list<node> D;

  menu(G);

  bool anw = my_bipar_checker(G, A, B);
  std::cout << "Answer of my checker is: "<< anw << '\n';

  anw = Is_Bipartite(G, C, D);
  std::cout << "Answer of LEDA is: "<< anw << '\n';

  return 0;
}
