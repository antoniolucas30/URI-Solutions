#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int testCases, goals, totR, totG, totB;
  char t1, t2;

  std::cin >> testCases;

  for(int i = 0; i < testCases; i++){

    totR = 0, totG = 0, totB = 0;

    std::cin >> goals;

    for(int j = 0; j < goals; j++){

      std::cin >> t1 >> t2;

      if(t1 == 'R' && t2 == 'B') totR += 1;
      else if(t1 == 'R' && t2 == 'G') totR += 2;
      else if(t1 == 'G' && t2 == 'B') totG += 2;
      else if(t1 == 'G' && t2 == 'R') totG += 1;
      else if(t1 == 'B' && t2 == 'G') totB += 1;
      else if(t1 == 'B' && t2 == 'R') totB += 2;

    }

    if(totR > totG && totR > totB)
      std::cout << "red" << std::endl;
    else if(totG > totR && totG > totB)
      std::cout << "green" << std::endl;
    else if(totB > totR && totB > totG)
      std::cout << "blue" << std::endl;
    else if(totB == totG && totB == totR)
      std::cout << "trempate" << std::endl;
    else
      std::cout << "empate" << std::endl;

  }

  return 0;
}
