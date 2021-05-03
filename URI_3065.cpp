#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int currentTest = 0;
  int result;
  int numOp;
  int currentNum;
  char expression;

  while(std::cin >> numOp && numOp != 0){

    result = 0;
    expression = '+';

    for(int i = 0; i < numOp; i++){

      if(i != 0)
        std::cin >> expression;

      std::cin >> currentNum;

      if(expression == '+')
        result += currentNum;

      else
        result -= currentNum;

    }

    std::cout << "Teste " << ++currentTest << '\n' << result << "\n\n";

  }

  return 0;
}
