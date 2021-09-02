#include <algorithm>

class DirReduction
{
public:
  static std::vector<std::string> dirReduc(std::vector<std::string> &arr)
  {
    for (int i = 0; i < (int)arr.size() - 1; ++i)
      if ((arr[i] == "NORTH" && arr[i + 1] == "SOUTH") || 
          (arr[i] == "SOUTH" && arr[i + 1] == "NORTH") ||
          (arr[i] == "EAST" && arr[i + 1] == "WEST") ||
          (arr[i] == "WEST" && arr[i + 1] == "EAST"))
      {
        arr.erase(arr.begin() + i, arr.begin() + i + 2);
        i = -1;
      }
    
    return arr;
  }
};
