#include <iostream>
//
//
//

long vecGuildas[100100];
long vecPontos[100100];
long vecWins[100100];
long CU;

long find(long guilda){
  if(vecGuildas[guilda] == guilda) return guilda;
  return vecGuildas[guilda] = find(vecGuildas[guilda]);
}

bool join(long guilda1, long guilda2){
  long patriarca1 = find(guilda1), patriarca2 = find(guilda2);
  if(patriarca1 == patriarca2) return false;
  
  vecGuildas[patriarca2] = patriarca1;
  vecPontos[patriarca1] += vecPontos[patriarca2];
  vecWins[patriarca1] += vecWins[patriarca2];
  if(CU == patriarca2) CU = patriarca1;
}
int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long lenVec, lenOp, op, guilda1, guilda2, patriarca1, patriarca2, penis;

  while(std::cin >> lenVec >> lenOp && lenVec != 0 && lenOp != 0){
    penis = 0;
    CU = 0;

    for(long i = 0; i < lenVec; i++){
      
      std::cin >> vecPontos[i];

      vecGuildas[i] = i;
      vecWins[i] = 0;

    }

    for(long i = 0; i < lenOp; i++){

      std::cin >> op >> guilda1 >> guilda2;
      
      guilda1--, guilda2--;

      if(op == 1){

        join(guilda1, guilda2);

      }

      else{

        patriarca1 = find(guilda1), patriarca2 = find(guilda2);

        if(vecPontos[patriarca1] > vecPontos[patriarca2]){
          
          vecWins[patriarca1]++;
          if(CU == patriarca1) penis++;

        }

        if(vecPontos[patriarca1] < vecPontos[patriarca2]){
          

          vecWins[patriarca2]++;
          if(CU == patriarca2) penis++;


        }

      }
    }

    std::cout << penis << '\n';

  }

  return 0;
}


