#include "marsStation.hpp"

using namespace MARS;

void
Station::raw_create(std::vector<std::string> data)
{
  jp_name = data[0];
  reading = data[1];
  en_name = data[2];
  // for (int i = 3; i < 12; i += 2)
  //   add_next_station(std::pair<Station&, float>(data[i], data[i+1]));
  is_specific_city = std::stoi(data[13]) != 0 ? true : false;
  if (is_specific_city)
  {
    specific_city = data[14];
    specific_city_center = data[15];
  }
}

void
Station::add_next_station(std::pair<Station&, float> next)
{
  this->next.push_back(next);
}

std::string
Station::to_string()
{
  std::stringstream iostr;
  iostr << jp_name << " " << reading << " " << en_name;

  if(is_specific_city)
  {
    iostr << "True" << " " << specific_city << " " << specific_city_center;
  }

  return iostr.str();
}
