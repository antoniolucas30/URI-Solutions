#include <iostream>
#include <map>
#include <vector>

void DFS(std::map <std::string, std::vector <std::string>>& Graph, std::map <std::string, bool> nodeInPath, std::string source, std::string destination, int currentTravel, int* result);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int totalNodes, totalEdges, currentDist = 0, result = -1;
  std::string nodeU, nodeV;
  std::map <std::string, std::vector <std::string>> Graph;
  std::map <std::string, bool> nodeInPath;

  std::cin >> totalNodes >> totalEdges;

  for(int i = 0; i < totalEdges; i++){

    std::cin >> nodeU >> nodeV;

    Graph[nodeU].push_back(nodeV);
    Graph[nodeV].push_back(nodeU);

    nodeInPath[nodeU] = false;
    nodeInPath[nodeV] = false;

  }

  DFS(Graph, nodeInPath, "Entrada", "*", 0, &result);

  currentDist += result;
  result = -1;

  DFS(Graph, nodeInPath, "*", "Saida", 0, &result);

  std::cout << currentDist + result << std::endl;

  return 0;
}

void DFS(std::map <std::string, std::vector <std::string>>& Graph, std::map <std::string, bool> nodeInPath, std::string source, std::string destination, int currentTravel, int* result){

  int lenCurrentNode = Graph[source].size();
  std::string nodeFor;

  if(source == destination){

    if((*result) == -1 || currentTravel < (*result))
      (*result) = currentTravel;

    return;

  }
  
  nodeInPath[source] = true;

  for(int i = 0; i < lenCurrentNode; i++){

    nodeFor = Graph[source][i];

    if(!nodeInPath[nodeFor])
      DFS(Graph, nodeInPath, nodeFor, destination, (currentTravel + 1), result);

  }

}
