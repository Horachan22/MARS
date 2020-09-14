#include <string>
#ifndef MARS_PATH_HPP

namespace MARS
{
  class FarePath
  {
  public:
    constexpr static char MAIN[] = "Fare_Data/(H)Main_Line_Fare.csv";
    constexpr static char BRANCH[] = "Fare_Data/(H)Branch_Line_Fare.csv";
  };

  class StationPath
  {
  public:
    constexpr static char SASSHO_LINE[] = "Station_Data/JR_Hokkaido/(H)Sassho_Line.csv";
    constexpr static char SEKIHOKU_LINE[] = "Station_Data/JR_Hokkaido/(H)Sekihoku_Line.csv";
    constexpr static char SEKISHO_LINE[] = "Station_Data/JR_Hokkaido/(H)Sekisho_Line.csv";
    constexpr static char SENMO_LINE[] = "Station_Data/JR_Hokkaido/(H)Senmo_Line.csv";
  };
}

#endif  /* end of marsPath.hpp */
