#include <iostream>
#include <algorithm>

struct Country{

  std::string name;
  int gold, silver, bronze;

};

bool Compare(Country n1, Country n2);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Country* vec;
  std::string countryName;
  int lenVec, gold, silver, bronze;

  std::cin >> lenVec;

  vec = new Country[lenVec];

  for(int i = 0; i < lenVec; i++){

    std::cin >> countryName >> gold >> silver >> bronze;

    vec[i] = {countryName, gold, silver, bronze};

  }

  std::sort(vec, vec + lenVec, Compare);

  for(int i = 0; i < lenVec; i++){

    std::cout << vec[i].name << ' ' << vec[i].gold << ' ' << vec[i].silver << ' ' << vec[i].bronze << '\n';

  }
  
  return 0;
}

bool Compare(Country n1, Country n2){

  if(n1.gold > n2.gold)
    return 1;
  
  else if(n2.gold > n1.gold)
    return 0;

  else if(n1.silver > n2.silver)
    return 1;

  else if(n2.silver > n1.silver)
    return 0;

  else if(n1.bronze > n2.bronze)
    return 1;

  else if(n2.bronze > n1.bronze)
    return 0;

  else
    return n1.name <= n2.name;

}
