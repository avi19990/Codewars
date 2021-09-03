#include <string>

std::string sum_strings(const std::string& a, const std::string& b)
{
  size_t numLength = a.size() > b.size() ? a.size() : b.size();
  std::string result(numLength, ' ');
  std::string::reverse_iterator iterR = result.rbegin();
  
  bool reminder = 0;
  for (std::string::const_reverse_iterator iterA = a.rbegin(), iterB = b.rbegin();;)
  {
    bool isADone = iterA == a.rend();
    bool isBDone = iterB == b.rend();
    
    if (isADone && isBDone)
    {
      if (reminder)
        result.insert(0, "1");
      break;
    }
    
    int digitA = (isADone) ? 0 : *iterA - '0', digitB = (isBDone) ? 0 : *iterB - '0';
    *iterR = ((digitA + digitB + reminder) % 10) + '0';
    reminder = (int)((digitA + digitB + reminder) / 10);
      
    ++iterR;
    if (!isADone) ++iterA;
    if (!isBDone) ++iterB;
  }
  
  return result;
}
