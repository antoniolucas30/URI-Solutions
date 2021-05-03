#include <iostream>

int main(){
  
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long *vec, totalLen, s1 = 0, s2 = 0;

  std::cin >> totalLen;

  vec = new long[totalLen];

  for(long i = 0; i < totalLen; i++){

    std::cin >> vec[i];
    s1 += vec[i];

  }

  for(long i = (totalLen - 1); i >= 1; i--){
  
    s2 += vec[i], s1 -= vec[i];

    if(s1 == s2){
      
      std::cout << i << '\n';
      break;

    }

  }

  return 0;
}
