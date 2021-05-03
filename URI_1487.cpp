#include <iostream>
#include <utility>
#include <algorithm>

bool Compare(std::pair <long, long> n1, std::pair <long, long> n2);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long result;
  int num, time, current = 0;
  std::pair <long, long>* vec;

  while(std::cin >> num >> time && num != 0 && time != 0){

    vec = new std::pair <long, long>[num], result = 0;

    for(int i = 0; i < num; i++)
      std::cin >> vec[i].first >> vec[i].second;

    std::sort(vec, vec + num, Compare);

    for(int i = 0; i < num; i++){

      result += vec[i].second * (time / vec[i].first);
      time -= vec[i].first * (time / vec[i].first);

      if(time == 0)
        break;

    }

    std::cout << "Instancia " << ++current << '\n' << result << "\n\n";

    delete[] vec;

  }

  return 0;
}

bool Compare(std::pair <long, long> n1, std::pair <long, long> n2){

  double x1 = double(n1.second) / n1.first, x2 = double(n2.second) / n2.first;

  return x1 >= x2;

}
