#include <iostream>
#include <algorithm>

struct Animal{

  std::string name;
  int weight;
  int age;
  double height;

};

bool Compare(Animal a1, Animal a2);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long totalTests;
  long totalAnimals;
  long currentAnimals;
  Animal* vecAnimals;

  std::cin >> totalTests;

  for(long i = 0; i < totalTests; i++){

    std::cin >> totalAnimals >> currentAnimals;

    vecAnimals = new Animal[totalAnimals];

    for(long j = 0; j < totalAnimals; j++)
      std::cin >> vecAnimals[j].name >> vecAnimals[j].weight >> vecAnimals[j].age >> vecAnimals[j].height;

    std::sort(vecAnimals, vecAnimals + totalAnimals, Compare);

    std::cout << "CENARIO {" << i + 1 << "}\n";

    for(long j = 0; j < currentAnimals; j++)
      std::cout << j + 1 << " - " << vecAnimals[j].name << '\n';

    delete[] vecAnimals;

  }

  return 0;
}

bool Compare(Animal a1, Animal a2){

  if(a1.weight > a2.weight)
    return true;
  
  else if(a1.weight < a2.weight)
    return false;

  else if(a1.age < a2.age)
    return true;

  else if(a1.age > a2.age)
    return false;

  else if(a1.height < a2.height)
    return true;

  else if(a1.height > a2.height)
    return false;

  return a1.name < a2.name;

}
