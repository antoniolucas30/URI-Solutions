#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

bool compare(std::pair <int, std::string> N1, std::pair <int, std::string> N2){

  return N1.first > N2.first;

}

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector <std::pair <int, std::string>> VecTeste;

  VecTeste.push_back(std::make_pair(5, "sssss")); VecTeste.push_back(std::make_pair(5, "aaaaa"));

  std::sort(VecTeste.begin(), VecTeste.end(), compare);

  std::cout << VecTeste[0].second << std::endl;

  int total;
  std::string* vec;

  return 0;
}
