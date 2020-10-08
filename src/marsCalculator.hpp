#include "marsFareParser.hpp"
#include <math.h>

#ifndef MARS_CALCULATOR_HPP
#define BRANCH_MULTIPLIER 1.1
#define STUDENT_DISCOUNT_MULTIPLIER 0.8
#define ROUND_DISCOUNT_MULTIPLIER 0.9

namespace MARS
{
  class Calculator
  {
  public:
    //JR北海道の幹線データの読み取りを行う関数
    static int
    get_H_main_fare(float calculate_dis)
    {
      int pay;
      auto fare_data = FareParser::get_line_fare("Fare_Data/(H)Main_Line_Fare.csv");
      for(auto fare : fare_data)
      {
        if(calculate_dis >= fare[0])
        {
          pay = fare[1];
        }
        else
        {
          break;
        }
      }

      return pay;
    }

    //JR北海道の地方線データの読み取りを行う関数
    static int
    get_H_branch_fare(float calculate_dis)
    {
      int pay;
      auto fare_data = FareParser::get_line_fare("Fare_Data/(H)Branch_Line_Fare.csv");
      for(auto fare:fare_data)
      {
        if(calculate_dis >= fare[0])
        {
          pay = fare[1];
        }
        else
        {
          break;
        }
      }

      return pay;
    }

    //学割運賃の計算
    static int
    get_student_discount_fare(float main_dis,
                              float branch_dis,
                              int fare)
    {
      if(main_dis + branch_dis > 100)
      {
        return floor(fare * STUDENT_DISCOUNT_MULTIPLIER / 10) * 10;
      }

      return fare;
    }

    //往復運賃の計算
    static int
    get_roundtrip_fare(float main_dis,
                       float branch_dis,
                       int fare)
    {
      if(main_dis + branch_dis > 600)
      {
        return floor(fare * 2 * ROUND_DISCOUNT_MULTIPLIER / 10) * 10;
      }

      return fare * 2;
    }

    //JR北海道のみを利用したときの運賃
    static int
    get_H_fare(float main_dis,
               float branch_dis)
    {
      int fare = 0;
      float calculate_dis = 0;

      if(branch_dis == 0)
      {
        fare = get_H_main_fare(main_dis);
      }
      else if(main_dis == 0)
      {
        fare = get_H_branch_fare(branch_dis);
      }
      else if(main_dis + branch_dis < 10)
      {
        calculate_dis = main_dis + branch_dis;
        fare = get_H_branch_fare(calculate_dis);
      }
      else
      {
        calculate_dis = main_dis + branch_dis * BRANCH_MULTIPLIER;
        fare = get_H_main_fare(calculate_dis);
      }

      return fare;
    }
  };
}

#endif /* end of marsCalculator.hpp */
