#include <iostream>

#define QNT_MAX 2000000

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int testCases, lenVec, currentCoins, *vec;
  long* DP, maxQnt;

  std::cin >> testCases;

  for(int i = 0; i < testCases; i++){

    std::cin >> lenVec >> maxQnt;

    DP = new long[maxQnt + 1], vec = new int[lenVec];

    for(long j = 0; j <= maxQnt; j++)
      DP[j] = QNT_MAX;

    DP[0] = 0;

    for(int j = 0; j < lenVec; j++)
      std::cin >> vec[j];

    for(long j = 1; j <= maxQnt; j++){

      for(int k = 0; k < lenVec; k++){

        if(vec[k] <= j){

          currentCoins = DP[j - vec[k]];

          if(currentCoins != QNT_MAX && (currentCoins + 1) < DP[j])
            DP[j] = currentCoins + 1;

        }

      }

    }

    std::cout << DP[maxQnt] << std::endl;

    delete[] DP; delete[] vec;

  }

  return 0;
}
