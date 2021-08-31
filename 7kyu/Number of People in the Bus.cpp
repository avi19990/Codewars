#include <utility>
#include <vector>

unsigned int number(const std::vector<std::pair<int, int>>& busStops)
{
  unsigned int numberOfPeople = 0;
  
  for (unsigned int i = 0; i < busStops.size(); ++i)
    numberOfPeople += busStops[i].first - busStops[i].second;
  
  return numberOfPeople;
}
