#include <iostream> //Usado para o CIN e COUT
#include <vector>   //Usado para o std::vector
#include <unordered_map>      //Usado para o std::map
#include <limits.h> //Usado para o INT_MAX
#include <queue>


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

  std::priority_queue <int, std::string> currentDists;

}

