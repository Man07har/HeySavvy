#include <math.h>
#include<bits/stdc++.h>
using namespace std;
int predictAge(int age1, int age2, int age3, int age4, int age5, int age6, int age7, int age8)
{
  int sum_square,divide_num;
  float sq_rt;
 sum_square= pow(age1,2)+pow(age2,2)+pow(age3,2)+pow(age4,2)+pow(age5,2)+pow(age6,2)+pow(age7,2)+pow(age8,2);
  sq_rt=sqrt(sum_square);
  divide_num=sq_rt/2;
  return divide_num;
}
int main(){
cout<<predictAge(1,2,3,4,5,6,7,8);
return 0;
}