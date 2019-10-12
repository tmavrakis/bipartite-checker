# bipartite-checker
A bipartite checker for 3 specific graph family. Implementation is on C++ using LEDA library.


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

requirements: Let 

![72475794_2405982429451021_7013493096843313152_n](https://user-images.githubusercontent.com/44173610/66703315-ff051800-ed19-11e9-81d0-5252667d9206.png)
