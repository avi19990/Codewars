#include <string>
#include <vector>

std::string emptyStack(std::vector<int> &stack)
{
  std::ostringstream result;
  
  if (stack.size() > 2)
  {
    int rangeEnd = stack.back();
    while (stack.size() > 1) stack.pop_back();
    result << stack.back() << "-" << rangeEnd;
    stack.pop_back();
  }
  else
  {
    for (size_t i = 0; i < stack.size(); ++i)
      result << stack[i] << ((i == stack.size() - 1) ? "" : ",");
    stack.clear();
  }
  
  return result.str();
}

std::string range_extraction(std::vector<int> args)
{
  std::ostringstream result;
  std::vector<int> stack;
  
  for (size_t i = 0; i < args.size(); ++i)
  {
    if (stack.empty() || args[i] - stack.back() == 1)
      stack.push_back(args[i]);
    else
    {
      result << emptyStack(stack) << ",";
      stack.push_back(args[i]);
    }
  }
  
  if (!stack.empty())
    result << emptyStack(stack);
  
  return result.str();
}
