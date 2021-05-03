#include <iostream>
#include <iomanip>
#include <cmath>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  double result, currentDist, *vecX, *vecY;
  int testCases;
  
  while(std::cin >> testCases && testCases != 0){

    vecX = new double[testCases], vecY = new double[testCases];
    result = -1;

    for(int i = 0; i < testCases; i++){

      std::cin >> vecX[i] >> vecY[i];

    }

    for(int i = 0; i < testCases - 1; i++){

      for(int j = i + 1; j < testCases; j++){

        currentDist = std::sqrt(std::pow(vecX[j] - vecX[i], 2) + std::pow(vecY[j] - vecY[i], 2));

        if(result == -1 || currentDist < result)
          result = currentDist;

      }

    }

    if(result >= 10000 || testCases == 1)
      std::cout << "INFINITY" << std::endl;
    else
      std::cout << std::fixed << std::setprecision(4) << result << std::endl;

    delete[] vecX; delete[] vecY;

  }

  return 0;
}
