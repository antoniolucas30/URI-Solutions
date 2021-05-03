#include <iostream> //Usado para o CIN e COUT
#include <vector>   //Usado para o std::vector
#include <unordered_map>      //Usado para o std::map
#include <limits.h> //Usado para o INT_MAX

int Dijkstra(std::unordered_map <std::string, std::vector <std::string>>& Graph, std::string source, std::string destination);
//Acima, prototipei minha fun

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int totalNodes, totalEdges;
  std::string nodeU, nodeV;
  std::unordered_map <std::string, std::vector <std::string>> Graph;

  std::cin >> totalNodes >> totalEdges;

  for(int i = 0; i < totalEdges; i++){

    std::cin >> nodeU >> nodeV;

    Graph[nodeU].push_back(nodeV);
    Graph[nodeV].push_back(nodeU);

  }

  std::cout << Dijkstra(Graph, "Entrada", "*") + Dijkstra(Graph, "*", "Saida") << std::endl;

  return 0;
}

int Dijkstra(std::unordered_map <std::string, std::vector <std::string>>& Graph, std::string source, std::string destination){

  std::unordered_map <std::string, long> dists, Nodes;
  std::unordered_map <std::string, long>::iterator itErase;
  int currentDist;
  std::string currentNode, nodeFor;

  for(std::unordered_map <std::string, std::vector <std::string>>::iterator it1 = Graph.begin(); it1 != Graph.end(); it1++){
    
    dists[(*it1).first] = INT_MAX;
    Nodes[(*it1).first] = 0;

  }
  dists[source] = 0;

  while(!Nodes.empty()){

    currentDist = INT_MAX;
    currentNode = (*Nodes.begin()).first;
    itErase = Nodes.begin();

    for(std::unordered_map <std::string, long>::iterator itFind = Nodes.begin(); itFind != Nodes.end(); itFind++){
  
      if(dists[(*itFind).first] < currentDist){

        currentDist = dists[(*itFind).first];
        currentNode = (*itFind).first;
        itErase = itFind;

      }
  
    }

    Nodes.erase(itErase);

    for(std::vector <std::string>::iterator itFind = Graph[currentNode].begin(); itFind != Graph[currentNode].end(); itFind++){

      nodeFor = (*itFind);
      currentDist = dists[currentNode] + 1;

      if(currentDist < dists[nodeFor])
        dists[nodeFor] = currentDist;

    }
    

  }

  return dists[destination];

}
