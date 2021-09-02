#include <string>
#include <algorithm>

class RomanHelper
{
private:
  std::string roman[13];
  unsigned int integer[13];
  
public:
  RomanHelper()
    : roman {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"},
      integer {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000}
  {
    
  }
  
  std::string to_roman(unsigned int n)
  {
    std::ostringstream result;
    
    for (int i = 12; i >= 0; --i)
      if (n >= integer[i])
      {
        n -= integer[i];
        result << roman[i];
        ++i;
      }
    
    return result.str();
  }
  
  int from_roman(std::string rn)
  {
    int result = 0;
    
    for (int i = 12; i >= 0; --i)
      if (rn.rfind(roman[i], 0) != std::string::npos)
      {
        result += integer[i];
        rn.erase(0, roman[i].size());
        ++i;
      }
    
    return result;
  }
} RomanNumerals;
