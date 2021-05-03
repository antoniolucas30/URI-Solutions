#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int numInstances, right2, right3, lenStr, first, currentInstance = 0;
  std::string n1, n2, n3;

  std::cin >> numInstances;
  std::cin.ignore();
  
  for(int i = 0; i < numInstances; i++){

    right2 = 0, right3 = 0, first = -1;

    std::getline(std::cin, n1); std::getline(std::cin, n2); std::getline(std::cin, n3);

    lenStr = n1.length();

    for(int j = 0; j < lenStr; j++){

      if(n2[j] == n1[j])
        right2++;

      if(n3[j] == n1[j])
        right3++;

      if(n2[j] == n1[j] && n3[j] != n1[j] && first == -1)
        first = 0;

      else if(n2[j] != n1[j] && n3[j] == n1[j] && first == -1)
        first = 1;

    }

    std::cout << "Instancia " << ++currentInstance << '\n';

    if(right2 > right3)
      std::cout << "time 1\n";

    else if(right2 < right3)
      std::cout << "time 2\n";

    else if(first == 0)
      std::cout << "time 1\n";

    else if(first == 1)
      std::cout << "time 2\n";

    else
      std::cout << "empate\n";

    std::cout << '\n';

  }

  return 0;
}
