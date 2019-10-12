# bipartite-checker
A [bipartite](https://en.wikipedia.org/wiki/Bipartite_graph) checker for 3 specific graph family. Implementation is on C++ using LEDA library.


1. Create a certifying algorithm to check the bilaterality of a given graph G = (V, E).
2. Compare with the LEDA bipartite checker.

Graph family:
* Synthetic Graph nested square
(nodes, edges) = (n, m) ∈ {(10000, 19996), (40000, 79996), (90000, 179996)}
 
![72662444_450236178920267_5457073399190781952_n](https://user-images.githubusercontent.com/44173610/66703301-cb29f280-ed19-11e9-8728-39d845db19f7.png)

* Cycle Graph
(nodes, edges) = (n, m) ∈ {(10001, 10001), (400001, 40001), (90001, 90001)}

![72719889_908362566203223_7348709079478435840_n](https://user-images.githubusercontent.com/44173610/66703313-fad8fa80-ed19-11e9-9e9a-6bb6cd286cc7.png)

* Synthetic Graph of 4 levels
k nodes, 2k edges between 2 levels.

k ∈ {(500), (1000), (1500)}.

requirements: Let ![CodeCogsEqn](https://user-images.githubusercontent.com/44173610/66703854-91f48100-ed1f-11e9-837a-f306580e2c75.gif) nodes of level Li, 1 < i < 4. The 2k edges between two levels Li, Li+1, 1 < i < 3, created like this: first we choose k edges ![CodeCogsEqn (5)](https://user-images.githubusercontent.com/44173610/66704095-da14a300-ed21-11e9-8a70-2be046278cee.gif), 1 <= j <= k, next we choose a random node u of Li level and create the rest k edges ![CodeCogsEqn (6)](https://user-images.githubusercontent.com/44173610/66704097-dc76fd00-ed21-11e9-83ec-07fec8e3d9bb.gif), 1 <= j <= k. In the end, after the creation of edges between 2 levels, we create randomly two more edges: the first one between level L1 and leve L3, and the second one between level L2 and level L4. For the first(second) node choose randomly a node from u ∈ L1(u ∈ L2) and a node from v ∈ L3(v ∈ L4) and create the edge.  


![72475794_2405982429451021_7013493096843313152_n](https://user-images.githubusercontent.com/44173610/66703315-ff051800-ed19-11e9-81d0-5252667d9206.png)
