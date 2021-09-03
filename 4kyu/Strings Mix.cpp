#include <vector>
#include <string>
#include <algorithm>

class Mix
{
public:
  static std::string mix(const std::string &s1, const std::string &s2)
  {
    std::vector<std::string> substrResult;
    
    for (char letter = 'a'; letter <= 'z'; ++letter)
    {
      size_t letterCount1 = std::count(s1.begin(), s1.end(), letter);
      size_t letterCount2 = std::count(s2.begin(), s2.end(), letter);
      if (std::max(letterCount1, letterCount2) < 2) continue;
      
      std::ostringstream tempStr;
      char higherCountString = (letterCount1 < letterCount2) ? '2' : (letterCount1 == letterCount2) ? '=' : '1';
      tempStr << higherCountString << ":" << std::string(std::max(letterCount1, letterCount2), letter);
      
      substrResult.push_back(tempStr.str());
    }
    
    std::sort(substrResult.begin(), substrResult.end(), 
              [&](const std::string &a, const std::string &b)
              {
                if (a.size() == b.size())
                  return a < b;
                else
                  return a.size() > b.size();
              });
    
    std::string result;
    for (size_t i = 0; i < substrResult.size(); ++i)
    {
      result += substrResult[i];
      if (i != substrResult.size() - 1)
        result += '/';
    }
    
    return result;
  }
};
