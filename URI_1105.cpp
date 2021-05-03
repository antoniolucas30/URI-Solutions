#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int totalBanks, totalDeb, bankU, bankV, currentMoney;
  std::string ans = "NS";
  long* vecMoney;
  bool flag;

  while(std::cin >> totalBanks >> totalDeb && totalBanks != 0 && totalDeb != 0){

    vecMoney = new long[totalBanks], flag = true;

    for(int i = 0; i < totalBanks; i++)
      std::cin >> vecMoney[i];

    for(int i = 0; i < totalDeb; i++){

      std::cin >> bankU >> bankV >> currentMoney;

      bankU--, bankV--;
      vecMoney[bankV] += currentMoney, vecMoney[bankU] -= currentMoney;

    }

    for(int i = 0; i < totalBanks; i++){

      if(vecMoney[i] < 0){

        flag = false;
        break;

      }

    }

    std::cout << ans[flag] << '\n';

    delete[] vecMoney;

  }

  return 0;
}
