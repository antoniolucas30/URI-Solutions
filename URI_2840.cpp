#include <iostream>
#include <cmath>

#define PI 3.1415

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long radius, quantity;

  std::cin >> radius >> quantity;

  std::cout << int(quantity / ((4.0/3) * PI * std::pow(radius, 3))) << std::endl;

  return 0;
}
