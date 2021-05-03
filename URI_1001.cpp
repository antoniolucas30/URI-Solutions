#include <iostream>
#include <queue>

struct Node{

  int posI, posJ, dist;

};


bool **vecPresenca;



int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int **matrix, qntRows, qntCols;
  Node posInicial;

  std::cin >> qntRows >> qntCols;

  matrix = new int*[qntRows];
  vecPresenca = new bool*[qntRows];

  for(int i = 0; i < qntRows; i++){

    matrix[i] = new int[qntCols];
    vecPresenca[i] = new bool[qntCols];

    for(int j = 0; j < qntCols; j++){
      
      std::cin >> matrix[i][j];

      if(matrix[i][j] == 2)
        posInicial.posI = i, posInicial.posJ = j, posInicial.dist = 0;
    }
  }

  return 0;
}

void LeeAlgorithm(int** matrix, Node qualPos){

  std::queue <Node> queueNodes;
  Node nodeAtual;

  queueNodes.push(qualPos);

  while(!queueNodes.empty()){

    nodeAtual = queueNodes.front();

    queueNodes.pop();

    for(int i = 0; i < 4; i++){}

  }

}
