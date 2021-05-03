#include <iostream>

std::string KnapSack(long qntDigit, long eraseDigits, long currentIndex, std::string currentNum, std::string numInput, std::string** matrix);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long qntDigit, eraseDigits;
  std::string currentNum, **matrix;

  while(std::cin >> qntDigit >> eraseDigits && qntDigit != 0 && eraseDigits != 0){

    matrix = new std::string*[qntDigit];

    for(long i = 0; i < qntDigit; i++){

      matrix[i] = new std::string[qntDigit - eraseDigits + 1];

      for(long j = 0; j < qntDigit - eraseDigits + 1; j++)
        matrix[i][j] = "-";

    }

    std::cin >> currentNum;

    std::cout << KnapSack(qntDigit, eraseDigits, 0, "", currentNum, matrix) << '\n';

    for(long i = 0; i < qntDigit; i++)
      delete[] matrix[i];

    delete[] matrix;

  }

  return 0;
}

std::string FuncBiggest(std::string s1, std::string s2){

  long lenS1 = s1.length(), lenS2 = s2.length();

  if(lenS1 > lenS2)
    return s1;
  
  else if(lenS1 < lenS2)
    return s2;

  else{

    for(long i = 0; i < lenS1; i++){

      if(s1[i] > s2[i])
        return s1;

      else if(s1[i] < s2[i])
        return s2;

    }

  }

  return s1;

}

std::string KnapSack(long qntDigit, long eraseDigits, long currentIndex, std::string currentNum, std::string numInput, std::string** matrix){

  long lenStr = currentNum.length();

  if(currentIndex == qntDigit)
    return currentNum;

  if(matrix[currentIndex][lenStr][0] != '-'){

    std::cout << "DE INDEX " << currentIndex << " COM " << lenStr << ' ' << matrix[currentIndex][lenStr] << std::endl;

    return matrix[currentIndex][lenStr];}

  std::string tmpPut = "", tmpDontPut;

  if(currentNum.length() < (qntDigit - eraseDigits))
    tmpPut = KnapSack(qntDigit, eraseDigits, currentIndex + 1, currentNum + numInput[currentIndex], numInput, matrix);

  tmpDontPut = KnapSack(qntDigit, eraseDigits, currentIndex + 1, currentNum, numInput, matrix);

  std::cout << "COMPARANDO " << tmpPut << ' ' << tmpDontPut << " ESTOU BOTANDO DE INDEX " << currentIndex << " COM " << lenStr << ' ' << FuncBiggest(tmpPut, tmpDontPut) << std::endl;

  return matrix[currentIndex][lenStr] = FuncBiggest(tmpPut, tmpDontPut);

}
