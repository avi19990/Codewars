#include <utility>
#include <vector>
#include <math.h>

class SumSquaredDivisors
{
public:
  static std::vector<long long> findDivisorsOfNum(long long num)
  {
    std::vector<long long> result;
    
    for (long long i = 1; i <= num; ++i)
    {
      if (num % i == 0)
        result.push_back(i);
    }
    
    return result;
  }
  
  static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n)
  {
    std::vector<std::pair<long long, long long>> result;
    
    for (long long i = m; i <= n; ++i)
    {
      std::vector<long long> divisors = findDivisorsOfNum(i);
      
      long long sumOfSquares = 0;
      for (long long &element : divisors)
        sumOfSquares += element * element;
      
      if (sqrt(sumOfSquares) == (int)sqrt(sumOfSquares))
        result.push_back(std::make_pair(i, sumOfSquares));
    }
    
    return result;
  }
};
