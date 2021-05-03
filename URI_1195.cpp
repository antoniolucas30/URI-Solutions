#include <iostream>
#include <unordered_map>
#include <vector>

void PreorderTree(std::unordered_map<int, std::vector<int>>& Tree, int currentValue);
void InorderTree(std::unordered_map<int, std::vector<int>>& Tree, int currentValue);
void PostorderTree(std::unordered_map<int, std::vector<int>>& Tree, int currentValue);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::unordered_map <int, std::vector<int>> Tree;
  int testCases, qntNum, valueU, indexMudanca, currentValue, valueRoot, currentCase = 0;

  std::cin >> testCases;

  for(int i = 0; i < testCases; i++){

    std::cin >> qntNum;

    for(int j = 0; j < qntNum; j++){

      std::cin >> valueU;

      if(j == 0)
        Tree[valueU] = {-1,-1}, valueRoot = valueU;

      else{

        currentValue = valueRoot;

        while(true){

          indexMudanca = (valueU > currentValue);

          if(Tree[currentValue][indexMudanca] == -1){

            Tree[currentValue][indexMudanca] = valueU;
            Tree[valueU] = {-1, -1};

            break;
          }

          else
            currentValue = Tree[currentValue][indexMudanca];

        }

      }

    }

    std::cout << "Case " << ++currentCase << ":\nPre.:";
    PreorderTree(Tree, valueRoot);
    std::cout << "\nIn..:";
    InorderTree(Tree, valueRoot);
    std::cout << "\nPost:";
    PostorderTree(Tree, valueRoot);
    std::cout << "\n\n" << std::flush;

    Tree.clear();

  }

  return 0;
}

void PreorderTree(std::unordered_map<int, std::vector<int>>& Tree, int currentValue){

  if(currentValue == -1)
    return;

  std::cout << ' ' << currentValue;
  PreorderTree(Tree, Tree[currentValue][0]);
  PreorderTree(Tree, Tree[currentValue][1]);

}

void InorderTree(std::unordered_map<int, std::vector<int>>& Tree, int currentValue){

  if(currentValue == -1)
    return;

  InorderTree(Tree, Tree[currentValue][0]);
  std::cout << ' ' << currentValue;
  InorderTree(Tree, Tree[currentValue][1]);

}

void PostorderTree(std::unordered_map<int, std::vector<int>>& Tree, int currentValue){

  if(currentValue == -1)
    return;

  PostorderTree(Tree, Tree[currentValue][0]);
  PostorderTree(Tree, Tree[currentValue][1]);
  std::cout << ' ' << currentValue;

}
