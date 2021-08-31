#include <string>

std::string highestScoringWord(const std::string &str)
{
  std::string bestWord;
  int bestScore = 0;
  
  std::string tempStr = str;
  while (!tempStr.empty())
  {
    int separatorPos = tempStr.find_first_of(" ");
    std::string word = tempStr.substr(0, separatorPos);
    tempStr.erase(0, separatorPos + 1);

    int currentScore = 0;
    for (const char &letter : word)
      currentScore += letter - 96;
    
    if (currentScore > bestScore)
    {
      bestScore = currentScore;
      bestWord = word;
    }
    
    if (separatorPos == -1)
      break;
  }
  
  return bestWord;
}
