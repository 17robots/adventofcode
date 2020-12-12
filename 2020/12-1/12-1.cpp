#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

const int TOTAL = 2020;

int main()
{
  std::vector<int> report;
  long long finalAnswer;

  // read in the expense report
  std::ifstream istream;
  istream.open("input.txt", std::ios::in);
  if (istream.is_open())
  {
    std::string line;
    std::stringstream ss;
    int num;
    while (std::getline(istream, line))
    {
      ss << line;
      ss >> num;
      report.push_back(num);
    }
  }
  else
  {
    std::cout << "Failed to open the file\n";
    return 1;
  }

  std::sort(report.begin(), report.end(), std::greater<int>()); // sort
  for (auto balance1 : report)
  {
    for (auto balance2 : report)
    {
      const int TARGET = TOTAL - balance1 - balance2;
      if (std::find(report.begin(), report.end(), TARGET) != report.end())
      {
        std::cout << balance1 << " * " << balance2 << " * " << (TOTAL - balance1 - balance2) << "\n";
        std::cout << "Answer: " << (long long)(balance1 * balance2 * (TOTAL - balance1 * balance2)) << '\n';
      }
    }
  }

  return 0;
}