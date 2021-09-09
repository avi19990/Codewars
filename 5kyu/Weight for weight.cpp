#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>

class WeightSort
{
public:
  static std::string orderWeight(const std::string& weightsString)
  {
    if (weightsString.empty())
      return "";

    std::vector<long long> weights;

    std::istringstream input(weightsString);
    long long weight = 0;
    while (input >> weight)
      weights.push_back(weight);

    std::sort(weights.begin(), weights.end(), 
      [&](long long a, long long b)
      {
        long long tempA = a, tempB = b;
        int aSum = 0, bSum = 0;
        while (tempA > 0)
        {
          aSum += tempA % 10;
          tempA /= 10;
        }
        while (tempB > 0)
        {
          bSum += tempB % 10;
          tempB /= 10;
        }
              
        if (aSum == bSum)
          return std::to_string(a) < std::to_string(b);
        return aSum < bSum;
      });
      
    std::string result;
    for (size_t i = 0; i < weights.size(); ++i)
    {
      result += std::to_string(weights[i]);
      if (i != weights.size() - 1)
        result += " ";
    }

    return result;
  }
};
