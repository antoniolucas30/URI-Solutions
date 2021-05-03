#include <iostream>
#include <algorithm>

struct Config{

  long cityU, cityV, dist;

};

bool Compare(Config road1, Config road2);
int Find(int city, int *vecCities);
void Union(int city1, int city2, int *cities, int *cityFather);

int main(){
  
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int *cities, *cityFather;
  Config *vecConfig;
  long finalResult = 0, lenCities, lenRoads, cityU, cityV, dist;

  std::cin >> lenCities >> lenRoads;

  cities = new int[lenCities], vecConfig = new Config[lenRoads], cityFather = new int[lenCities]{0};

  for(int i = 0; i < lenCities; i++)
    cities[i] = i;

  for(int i = 0; i < lenRoads; i++){

    std::cin >> cityU >> cityV >> dist;

    cityU--, cityV--;
    
    vecConfig[i].cityU = cityU, vecConfig[i].cityV = cityV, vecConfig[i].dist = dist;

  }

  std::sort(vecConfig, vecConfig + lenRoads, Compare);

  for(int i = 0; i < lenRoads; i++){

    if(Find(vecConfig[i].cityU, cities) != Find(vecConfig[i].cityV, cities)){

      Union(vecConfig[i].cityU, vecConfig[i].cityV, cities, cityFather);
      finalResult += vecConfig[i].dist;

    }

  }

  std::cout << finalResult << '\n';

  return 0;
}

bool Compare(Config road1, Config road2){

  return road1.dist < road2.dist;

}

int Find(int city, int *vecCities){

  if(vecCities[city] == city)
    return city;

  return vecCities[city] = Find(vecCities[city], vecCities);

}

void Union(int city1, int city2, int *cities, int *cityFather){

  int p1 = Find(city1, cities), p2 = Find(city2, cities);

  if(cityFather[p1] > cityFather[p2]){

    cities[p2] = p1;

  }

  else if(cityFather[p2] > cityFather[p1]){

    cities[p1] = p2;

  }

  else{

    cities[p2] = p1;
    cityFather[p1]++;

  }

}
