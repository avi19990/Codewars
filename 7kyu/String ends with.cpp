#include <string>

bool solution(std::string const &str, std::string const &ending)
{
  return str.find(ending, str.size() - ending.size()) != std::string::npos;
}
