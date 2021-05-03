#include <iostream>
#include <utility>

long Knapsack(std::pair <int, int>* VecCanhao, long** DP, int currentIndex, int currentWeight, int lenVec);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int testCases, lenVec, destruction, maxWeight;
  std::pair <int, int>* VecCanhao;
  long **DP, result;

  std::cin >> testCases;

  for(int i = 0; i < testCases; i++){

    std::cin >> lenVec;

    VecCanhao = new std::pair <int, int>[lenVec], DP = new long*[lenVec + 1];

    for(int j = 0; j < lenVec; j++)
      std::cin >> VecCanhao[j].first >> VecCanhao[j].second;

    std::cin >> maxWeight;

    for(int j = 0; j <= lenVec; j++){

      DP[j] = new long[maxWeight + 1];

      for(int k = 0; k <= maxWeight; k++)
        DP[j][k] = -1;

    }

    std::cin >> destruction;

    result = Knapsack(VecCanhao, DP, 0, maxWeight, lenVec);

    if(result >= destruction)
      std::cout << "Missao completada com sucesso" << std::endl;
    
    else
      std::cout << "Falha na missao" << std::endl;

    for(int j = 0; j <= lenVec; j++)
      delete[] DP[j];

    delete[] VecCanhao; delete[] DP;

  }

  return 0;
}

long Knapsack(std::pair <int, int>* VecCanhao, long** DP, int currentIndex, int currentWeight, int lenVec){

  int tmpPut, tmpDontPut;

  if(currentIndex == lenVec || currentWeight == 0)
    return (DP[currentIndex][currentWeight] = 0);

  if(DP[currentIndex][currentWeight] != -1)
    return (DP[currentIndex][currentWeight]);

  tmpDontPut = Knapsack(VecCanhao, DP, currentIndex + 1, currentWeight, lenVec);

  if(VecCanhao[currentIndex].second <= currentWeight){

    tmpPut = VecCanhao[currentIndex].first + Knapsack(VecCanhao, DP, currentIndex + 1, currentWeight - VecCanhao[currentIndex].second, lenVec);

    return (DP[currentIndex][currentWeight] = std::max(tmpDontPut, tmpPut));

  }

  return (DP[currentIndex][currentWeight] = tmpDontPut);

}
