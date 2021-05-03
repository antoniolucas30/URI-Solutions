#include <iostream>

int KnapSack(int *vecQnt, int **tab, int currentCity, int currentBridges, int totalCities, int totalBridges);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int *vecQnt, totalCities, totalBridges, cityU, cityV, **tab;
  std::string ans = "NS";

  while(std::cin >> totalCities >> totalBridges){

    vecQnt = new int[totalCities + 1]{0}, tab = new int*[totalCities + 1];

    for(int i = 0; i < totalCities + 1; i++){
      
      tab[i] = new int[totalBridges + 1];
      
      for(int j = 0; j < totalBridges + 1; j++)
        tab[i][j] = -1;

    }

    for(int i = 0; i < totalBridges; i++){

      
      std::cin >> cityU >> cityV;
      vecQnt[cityU]++, vecQnt[cityV]++;
      

    }

    std::cout << ans[KnapSack(vecQnt, tab, 0, 0, totalCities, totalBridges)] << std::endl;

    for(int i = 0; i < totalCities + 1; i++)
      delete[] tab[i];

    delete[] vecQnt; delete[] tab;

  }

  return 0;
}

int KnapSack(int *vecQnt, int **tab, int currentCity, int currentBridges, int totalCities, int totalBridges){

  if(currentBridges > totalBridges || currentCity > totalCities)
    return 0;

  if(currentBridges == totalBridges)
    return tab[currentCity][currentBridges] = 1;

  if(tab[currentCity][currentBridges] >= 0)
    return tab[currentCity][currentBridges];

  return tab[currentCity][currentBridges] = std::max(KnapSack(vecQnt, tab, currentCity + 1, currentBridges + vecQnt[currentCity], totalCities, totalBridges), KnapSack(vecQnt, tab, currentCity + 1, currentBridges, totalCities, totalBridges));

}
