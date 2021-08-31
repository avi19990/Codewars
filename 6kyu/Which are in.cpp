#include <algorithm>

class WhichAreIn
{
public:
  static std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2)
  {
    //Test 1: validity of vectors
    if (array1.size() == 0 || array2.size() == 0) return std::vector<std::string>();
    
    //Test 2: appearence of array1 elements as substrings of array2 elements
    std::vector<std::string> results;
    for (std::string &wordA : array1)
    {
      //Test 2.1: is element of array1 already in results
      if (std::find(results.begin(), results.end(), wordA) != results.end())
        continue;
      
      //Test 2.2: is element of array1 a substring of any element in array2
      for (std::string &wordB : array2)
        if (wordB.find(wordA) != std::string::npos)
        {
          results.push_back(wordA);
          break;
        }
    }
    
    std::sort(results.begin(), results.end());
    
    return results;
  }
};
