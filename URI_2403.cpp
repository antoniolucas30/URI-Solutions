#include <iostream>
#include <vector>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long tasks, totalDependencies, taskU, taskV, lenNode, *vecTasks;
  std::vector <std::vector <int>> Graph;
  std::vector <int> Result;
  bool flag;

  std::cin >> tasks >> totalDependencies;

  Graph.resize(tasks); vecTasks = new long[tasks]{0};

  for(long i = 0; i < totalDependencies; i++){

    std::cin >> taskU >> taskV;

    Graph[taskU].push_back(taskV);
    vecTasks[taskV]++;

  }

  for(long i = 0; i < tasks; i++){

    flag = false;

    for(long j = 0; j < tasks; j++){

      if(vecTasks[j] == 0){

        flag = true;

        Result.push_back(j);
        lenNode = Graph[j].size();

        for(long k = 0; k < lenNode; k++)
          vecTasks[Graph[j][k]]--;

      }

    }

    if(!flag)
      break;

  }

  if(!flag)
    std::cout << "*\n";

  else{

    for(long i = 0; i < tasks; i++)
      std::cout << Result[i] << '\n';

  }

  delete[] vecTasks;

  return 0;
}
