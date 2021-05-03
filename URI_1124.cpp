#include <iostream>
#include <cmath>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string result = "NS";
  int vec[4], op, C1X, C1Y, C2X, C2Y;

  while(1){

    for(int i = 0; i < 4; i++)
      std::cin >> vec[i];

    if(vec[0] == 0)
      break;

    C1X = vec[2], C1Y = vec[2], C2X = vec[1] - vec[3], C2Y = vec[0] - vec[3];

    op = (2 * vec[2]) + (2 * vec[3]);

    std::cout << result[vec[0] >= (2 * vec[2]) && vec[1] >= (2 * vec[2]) && vec[0] >= (2 * vec[3]) && vec[1] >= (2 * vec[3]) && ((op <= vec[0]) || (op <= vec[1]) || (double(std::sqrt(std::pow(C2X - C1X, 2) + std::pow(C2Y - C1Y, 2))) >= (vec[2] + vec[3])))] << std::endl;

  }

  return 0;
}
