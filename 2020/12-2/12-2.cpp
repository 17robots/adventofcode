#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

int countChar(std::string password, char desiredChar)
{
  int count = 0;
  for (auto item : password)
  {
    if (item == desiredChar)
      count++;
  }
  return count;
}

int main()
{
  std::ifstream is;
  is.open("input.txt", std::ios::in);
  std::string line, range, letter, password;
  std::stringstream ss;
  int validPasswords = 0;
  while (std::getline(is, line, '\n'))
  {
    ss << line;
    ss >> range >> letter >> password;

    char desiredChar = letter.at(0);
    int min = std::stoi(range.substr(0, range.find("-")));
    int max = std::stoi(range.substr(range.find("-") + 1));
    if ((password.at(min - 1) == desiredChar && password.at(max - 1) != desiredChar) || (password.at(min - 1) != desiredChar && password.at(max - 1) == desiredChar))
      validPasswords++;
  }
  std::cout << "Valid Passwords: " << validPasswords;
  return 0;
}