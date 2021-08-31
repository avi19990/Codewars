#include <map>
#include <algorithm>

class StockList
{
public:
  static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories)
  {
    //Test 1: validity of vectors
    if (lstOfArt.size() == 0 || categories.size() == 0) return "";
    
    std::map<char, int> results;
    
    //Counting and saving required categories to map
    for (std::string &book : lstOfArt)
    {
      char category = book[0];
      int quantity = std::stoi(book.substr(book.find(" ") + 1));
      
      if (std::find(categories.begin(), categories.end(), std::string(1, category)) != categories.end())
        results[category] += quantity;
    }
    
    //Generating result string
    std::string resultString;
    for (unsigned int i = 0; i < categories.size(); ++i)
    {
      resultString += "(";
      resultString += categories[i];
      resultString += " : ";
      resultString += std::to_string(results[categories[i][0]]);
      resultString += ")";
      
      if (i != categories.size() - 1)
        resultString += " - ";
    }
    
    return resultString;
  }
};
