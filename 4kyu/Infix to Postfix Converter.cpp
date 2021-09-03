#include <string>
#include <vector>
#include <map>

std::map<char, int> opPriority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};

std::string to_postfix(std::string infix)
{
  std::istringstream stringStream(infix);
  std::ostringstream result;
  std::vector<char> operations;
  
  char c;
  while (stringStream >> c)
  { 
    if (c >= '0' && c <= '9')
      result << c;
    else
      if (operations.empty() || c == '(')
        operations.push_back(c);
      else if (c == ')')
      {
        int i = operations.size() - 1;
        while (operations[i] != '(')
        {
          result << operations[i];
          operations.pop_back();
          --i;
        }
        operations.pop_back();
      }
      else
        if (opPriority[c] > opPriority[operations.back()])
          operations.push_back(c);
        else
        {
          while (!operations.empty() && opPriority[c] <= opPriority[operations.back()])
          {
            result << operations.back();
            operations.pop_back();
          }
          operations.push_back(c);
        }
  }
  
  for (int i = operations.size() - 1; i >= 0; --i)
    result << operations[i];
    
  return result.str();
}
