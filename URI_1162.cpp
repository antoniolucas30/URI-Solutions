#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int totalTests;
  int result;
  int lenVec;
  int* vec;

  std::cin >> totalTests;

  for(int i = 0; i < totalTests; i++){

    result = 0;

    std::cin >> lenVec;

    vec = new int[lenVec];

    for(int j = 0; j < lenVec; j++)
      std::cin >> vec[j];

    for(int j = 0; j < lenVec; j++){

      for(int k = 1; k < lenVec; k++){

        if(vec[k - 1] > vec[k]){
          
          result++;
      
          std::swap(vec[k - 1], vec[k]);

        }

      }

    }

    std::cout << "Optimal train swapping takes " << result << " swaps.\n";

    delete[] vec;

  }

  return 0;
}
