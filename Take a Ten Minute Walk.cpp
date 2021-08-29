#include<vector>

bool isValidWalk(std::vector<char> walk) {
  //Test 1: lenght of the walk
  bool isLengthCorrect = walk.size() == 10;
  
  //Test 2: return to the start
  int horizontalChange = 0, verticalChange = 0;
  for (unsigned int i = 0; i < walk.size(); ++i)
  {
    switch (walk[i])
    {
    case 'e':
        ++horizontalChange;
        break;
    case 'n':
        ++verticalChange;
        break;
    case 'w':
        --horizontalChange;
        break;
    case 's':
        --verticalChange;
        break;
    }
  }
  bool isPositionCorrect = horizontalChange == 0 && verticalChange == 0;
  
  return isLengthCorrect && isPositionCorrect;
}
