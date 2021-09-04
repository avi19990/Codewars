#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map)
{
  if (snail_map[0].empty())
    return {};
  
  std::vector<int> result;
  
  if (snail_map[0].size() == 1)
    return {snail_map[0][0]};
  
  int direction = 0;
  int xLeft = 0, xRight = snail_map.size() - 1;
  int yUp = 0, yDown = snail_map.size() - 1;
  
  while (xLeft != xRight || yUp != yDown)
  {
    if (direction == 0)
    {
      for (int i = xLeft; i <= xRight; ++i)
        result.push_back(snail_map[yUp][i]);
      ++yUp;
    }
    else if (direction == 1)
    {
      for (int i = yUp; i <= yDown; ++i)
        result.push_back(snail_map[i][xRight]);
      --xRight;
    }
    else if (direction == 2)
    {
      for (int i = xRight; i >= xLeft; --i)
        result.push_back(snail_map[yDown][i]);
      --yDown;
    }
    else
    {
      for (int i = yDown; i >= yUp; --i)
        result.push_back(snail_map[i][xLeft]);
      ++xLeft;
    }
    
    direction = (direction + 1) % 4;
  }
  
  result.push_back(snail_map[yUp][xLeft]);
  
  return result;
}
