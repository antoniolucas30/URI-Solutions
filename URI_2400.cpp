#include <iostream>

long MergeSort(long* vec, long leftIndex, long rightIndex);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long* vec, totalDancers;

  std::cin >> totalDancers;

  vec = new long[totalDancers];

  for(long i = 0; i < totalDancers; i++)
    std::cin >> vec[i];

  std::cout << MergeSort(vec, 0, totalDancers - 1) << '\n';

  return 0;
}

long MergeFcn(long* vec, long leftIndex, long middleIndex, long rightIndex){

  long* tmpArray = new long[rightIndex - leftIndex + 1], currentLeft = leftIndex, currentRight = middleIndex + 1, index = 0, countInversions = 0;

  while(currentLeft <= middleIndex && currentRight <= rightIndex){

    if(vec[currentLeft] <= vec[currentRight])
      tmpArray[index++] = vec[currentLeft++];

    else{

      tmpArray[index++] = vec[currentRight++];
      countInversions += middleIndex + 1 - currentLeft;

    }

  }

  while(currentLeft <= middleIndex)
    tmpArray[index++] = vec[currentLeft++];

  while(currentRight <= rightIndex)
    tmpArray[index++] = vec[currentRight++];

  for(long i = 0, j = leftIndex; j <= rightIndex; i++, j++)
    vec[j] = tmpArray[i];

  return countInversions;

}

long MergeSort(long* vec, long leftIndex, long rightIndex){

  long middleIndex, inversions = 0;

  if(leftIndex < rightIndex){

    middleIndex = (leftIndex + rightIndex) / 2;

    inversions += MergeSort(vec, leftIndex, middleIndex);
    inversions += MergeSort(vec, middleIndex + 1, rightIndex);

    inversions += MergeFcn(vec, leftIndex, middleIndex, rightIndex);

  }

  return inversions;

}
