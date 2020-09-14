#ifndef MARS_CALCULATOR_HPP
#define BRANCH_MULTIPLIER 1.1

namespace MARS
{
  class Calculator
  {
  public:
    //JR北海道の幹線データの読み取りを行う関数
    //FIXME : Use function which reads 'fare_data' and returns fare.
    static int
    get_H_main_fare(float calculate_dis)
    {
      if(calculate_dis < 10)
      {
        return 200;
      }
      else
      {
        return 400;
      }
    }

    //JR北海道の地方線データの読み取りを行う関数
    //FIXME : Same as above.
    static int
    get_H_branch_fare(float calculate_dis)
    {
      if(calculate_dis < 10)
      {
        return 300;
      }
      else
      {
        return 600;
      }
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
