#include <stdio.h>
#include "marsCalculator.hpp"

using namespace MARS;

int
main(int argc,
     char** argv)
{
  //FIXME : Use distance calculator
  float main_dis = 0;
  float branch_dis = 655.9;
  int fare = Calculator::get_H_fare(main_dis, branch_dis);
  int student_discount_fare = Calculator::get_student_discount_fare(main_dis, branch_dis,fare);
  int round_fare = Calculator::get_roundtrip_fare(main_dis, branch_dis, fare);
  int round_student_discount_fare = Calculator::get_roundtrip_fare(main_dis, branch_dis, student_discount_fare);
  printf("運賃:%d円\n", fare);
  printf("運賃[往復]:%d円\n", round_fare);
  if(fare != student_discount_fare)
  {
    printf("運賃[学割]:%d円\n", student_discount_fare);
  }
  if(student_discount_fare * 2 != round_student_discount_fare)
  {
    printf("運賃[復学割]:%d円\n", round_student_discount_fare);
  }

  return 0;
}
