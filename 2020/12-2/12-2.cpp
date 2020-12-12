#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

int countChar(std::string password, char desiredChar)
{
}

int main()
{
  std::ifstream is;
  is.open("input.txt", std::ios::in);
  std::string line, range, letter, password;
  std::stringstream ss;
  while (std::getline(is, line, '\n'))
  {
    ss >> line;
    ss << range << letter << password;
  }
  return 0;
}