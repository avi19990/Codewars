#include <string>

class Fracts
{
public:
  static unsigned long long gcd(unsigned long long a, unsigned long long b)
  {
    while (b != 0)
    {
      unsigned long long c = a % b;
      a = b;
      b = c;
    }
    return a;
  }
  
  static unsigned long long lcm(unsigned long long a, unsigned long long b)
  {
    return a*b / gcd(a, b);
  }
  
  static std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst)
  {
    std::string result;
    unsigned long long D = lst[0][1];
    
    for (std::vector<unsigned long long> &element : lst)
      D = lcm(D, element[1]);

    for (std::vector<unsigned long long> &element : lst)
    {
      result += '(';
      result += std::to_string(element[0] * (D / element[1]));
      result += ',';
      result += std::to_string(D);
      result += ')';
    }
    
    return result;
  }
};
