#include <set>
#include <string>
#include <map>
#include <sstream>

std::map<char, int> digitMap = {{'A', 2}, {'B', 2}, {'C', 2}, {'D', 3}, {'E', 3}, {'F', 3}, {'G', 4}, {'H', 4}, {'I', 4}, 
                                {'J', 5}, {'K', 5}, {'L', 5}, {'M', 6}, {'N', 6}, {'O', 6}, {'P', 7}, {'Q', 7}, {'R', 7}, 
                                {'S', 7}, {'T', 8}, {'U', 8}, {'V', 8}, {'W', 9}, {'X', 9}, {'Y', 9}, {'Z', 9}};

std::string wordToDigit(const std::string &word)
{
  std::ostringstream result;
  
  for (size_t i = 0; i < word.size(); ++i)
    result << digitMap[word[i]];
  
  return result.str();
}

std::set<std::string> check1800(const std::string &str)
{
  std::string number = str.substr(str.size() - 8, 8);
  
  std::string word = number.substr(0, number.find('-')) + number.substr(number.find('-') + 1);
  word = wordToDigit(word);
  
  std::vector<std::string> firstWordSimilar;
  std::vector<std::string> secondWordSimilar;
  
  for (size_t i = 0; i < 573; ++i)
  {
    std::string tempWord = wordToDigit(preloaded::words[i]);
    if (tempWord == word.substr(0, 3) || tempWord == word.substr(0, 4)) firstWordSimilar.push_back(preloaded::words[i]);
    if (tempWord == word.substr(4, 3) || tempWord == word.substr(3, 4)) secondWordSimilar.push_back(preloaded::words[i]);
  }
  
  std::set<std::string> results;
  
  for (const std::string &f : firstWordSimilar)
    for (const std::string &s : secondWordSimilar)
    {
      if (f.size() + s.size() != 7)
        continue;
      
      std::ostringstream result;
      result << "1-800-" << f << "-" << s;
      
      results.insert(result.str());
    }
  
  return results;
}
