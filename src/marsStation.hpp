#include <sstream>
#include <string>
#include <vector>
#include <utility>

#ifndef MARS_STATION_HPP

namespace MARS
{
  class Station
  {
    std::string jp_name;
    std::string reading;
    std::string en_name;
    std::vector<std::pair<Station&, float>> next;
    bool is_specific_city;
    std::string specific_city;
    std::string specific_city_center;

  public:
    void            raw_create                (std::vector<std::string>);
    void            add_next_station          (std::pair<Station&, float>);

    std::string     to_string                 ();
  };
}

#endif  /* end of marsStation.hpp */
