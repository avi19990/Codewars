#include <vector>
#include <algorithm>

class Same
{
public :
    static bool comp(std::vector<int>&a, std::vector<int>&b)
    {
      //Test 1: validity of vectors
      if (a.size() != b.size() || a.size() == 0) return false;
      
      //Sort arrays without taking sign into account
      std::sort(a.begin(), a.end(), [](int a, int b){ return (std::abs(a) < std::abs(b)); });
      std::sort(b.begin(), b.end(), [](int a, int b){ return (std::abs(a) < std::abs(b)); });
      
      //Test 2: validity of the pattern
      for (unsigned int i = 0; i < a.size(); ++i)
        if (a[i] * a[i] != b[i])
          return false;
      
      return true;
    }
};
