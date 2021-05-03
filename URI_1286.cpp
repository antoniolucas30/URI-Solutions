#include <iostream>
#include <utility>

long Knapsack(std::pair <int, int>* VecPizzas, int** DP, int currentIndex, int currentWeight, int lenVec);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int lenVec, maxQnt, **DP;
  std::pair <int, int>* VecPizzas;

  while(std::cin >> lenVec && lenVec != 0){
  
    VecPizzas = new std::pair <int, int>[lenVec], DP = new int*[lenVec + 1];

    std::cin >> maxQnt;

    for(int i = 0; i <= lenVec; i++){

      DP[i] = new int[maxQnt + 1];

      for(int j = 0; j <= maxQnt; j++)
        DP[i][j] = -1;

      if(i != lenVec)
        std::cin >> VecPizzas[i].first >> VecPizzas[i].second;

    }

    std::cout << Knapsack(VecPizzas, DP, 0, maxQnt, lenVec) << " min." << std::endl;

    for(int j = 0; j <= lenVec; j++)
      delete[] DP[j];

    delete[] VecPizzas; delete[] DP;

  }

  return 0;
}

long Knapsack(std::pair <int, int>* VecPizzas, int** DP, int currentIndex, int currentWeight, int lenVec){

  int tmpPut, tmpDontPut;

  if(currentIndex == lenVec || currentWeight == 0)
    return DP[currentIndex][currentWeight] = 0;

  if(DP[currentIndex][currentWeight] != -1)
    return DP[currentIndex][currentWeight];

  tmpDontPut = Knapsack(VecPizzas, DP, currentIndex + 1, currentWeight, lenVec);

  if(VecPizzas[currentIndex].second <= currentWeight){

    tmpPut = VecPizzas[currentIndex].first + Knapsack(VecPizzas, DP, currentIndex + 1, currentWeight - VecPizzas[currentIndex].second, lenVec);

    return DP[currentIndex][currentWeight] = std::max(tmpPut, tmpDontPut);

  }

  return DP[currentIndex][currentWeight] = tmpDontPut;

}
