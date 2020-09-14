#include <iostream>
#include <string>
#include <utility>
#include <sstream>
#include <fstream>
#include <vector>
#include <array>

#ifndef MARS_FARE_PARSER_HPP
#define MARS_FARE_PARSER_HPP

namespace MARS
{
  class FareParser
  {
    const static std::vector<std::string>
    split(std::string& line,
          const char&  delim)
    {
      std::vector<std::string> data;
      std::string buffer{""};

      for(auto segment:line)
      {
        if(segment != delim)
        {
          buffer += segment;
        }
        else if(segment == delim && buffer !=  "")
        {
          data.push_back(buffer);
          buffer = "";
        }
      }

      if(buffer != "")
      {
        data.push_back(buffer);
      }

      return data;
    }

  public:
    const static std::vector<std::array<int, 2>>
    get_line_fare(std::string filename)
    {
      std::vector<std::array<int, 2>> fare_data;
      std::fstream file_stream(filename, std::ifstream::in);

      std::string line;
      //Skipping over unnecessary data
      for (int i = 0; i < 2; i++)
      {
        getline(file_stream, line);
      }

      while(getline(file_stream, line))
      {
        std::vector<std::string> data = split(line, ',');
        std::array<int, 2> fare{std::stoi(data[0]), std::stoi(data[1])};

        fare_data.push_back(fare);
      }

      file_stream.close();
      return fare_data;
    }
  };
}

#endif  /* end of marsFileParser.hpp */
