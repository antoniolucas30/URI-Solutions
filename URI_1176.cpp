#include <iostream>

int main(){

  unsigned long long tests, pos, x, y, tmp, result;

  std::cin >> tests;

  for(int i = 0; i < tests; i++){

    x = 0, y = 1;

    std::cin >> pos;

    if(pos >= 2){

      for(int i = 2; i <= pos; i++){

        result = x + y;

        x = y;
        y = result;

      }

      std::cout << result << '\n';

    }

    else if(!pos)
      std::cout << x << '\n';

    else
      std::cout << y << '\n';

  }

  return 0;
}
