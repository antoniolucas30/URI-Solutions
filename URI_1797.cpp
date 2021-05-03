#include <iostream>

struct Caracteristicas{

  int x, y, AAH;

};

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  bool result = 1;
  long lenVec, AAHMax;
  std::string ans[] = {"OUCH", "YEAH"};
  Caracteristicas currentCaracteristicas, lastCaracteristicas;

  std::cin >> lenVec >> AAHMax;

  for(long i = 0; i < lenVec; i++){

    std::cin >> currentCaracteristicas.x >> currentCaracteristicas.y >> currentCaracteristicas.AAH;

    if(i != 0){

      

    }


    lastCaracteristicas = currentCaracteristicas;
  }

  return 0;
}
