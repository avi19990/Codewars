#include <string>
#include <vector>
#include <iterator>

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable)
{
  std::vector<T> results;
  
  std::copy_if(iterable.begin(), iterable.end(), std::back_inserter(results), 
            [&](const T &element)
               { 
                 return (results.empty() || results.back() != element); 
               });
  
  return results;
}

std::vector<char> uniqueInOrder(const std::string& iterable)
{
  std::vector<char> results;
  
  std::copy_if(iterable.begin(), iterable.end(), std::back_inserter(results), 
            [&](const char &element)
               { 
                 return (results.empty() || results.back() != element); 
               });
  
  return results;
}
