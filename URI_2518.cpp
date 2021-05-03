#include <iostream>
#include <cmath>
#include <iomanip>

int main(){
  
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int totDegraus, H, C, L;

  while(std::cin >> totDegraus){

    std::cin >> H >> C >> L;

    std::cout << std::fixed << std::setprecision(4) << (L * double(std::sqrt(std::pow(H * totDegraus, 2) + std::pow(C * totDegraus, 2)))) / 10000 << std::endl;

  }

  return 0;
}
