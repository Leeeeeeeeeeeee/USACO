/*
ID: qq267181
TASK: ride
LANG: C++
*/

/*怎么计算？
  从头到尾的检索
  设置一个变量为当前是一个星期的哪个日子
  设置一个变量为当前是当前月的几号，为13号时计数一次
*/

#include <fstream>
using namespace std;

int main(){
  int i,j,z;//循环变量
  int n;//计算的年数为1900-(1900+n-1)
  int weekday_now=2;//0-6分别代表周六、周日、周一、周二、周三、周四、周五，因为1900年1月1日为周一，所以初始化为2
  int weekday_count[7]={0,0,0,0,0,0,0};//存储每个星期是13号的次数
  int year;//当前的年份
  int month_days;//当前月的号数
  ifstream fin ("friday.in");
  ofstream fout ("friday.out");

  //input
  fin >> n;
  //compute
  for(i=0;i<n;i++){
    //1.判断当前年的年份
    year=1900+i;
    for(j=0;j<12;j++){
      //2.判断当前月有几天
      if(j==3 || j==5 || j==8 || j==10){
        month_days=30;
      }else if(j==1){
        if(year%100==0){
          if(year%400==0){
            month_days=29;
          }else{
            month_days=28;
          }
        }else{
          if(year%4==0){
            month_days=29;
          }else{
            month_days=28;
          }
        }
      }else{
        month_days=31;
      }
      //3.进入每个月中，开始计数
      for(z=0;z<month_days;z++){
        if(z==12) weekday_count[weekday_now]++;
        weekday_now++;
        if(weekday_now>6) weekday_now=0;
      }
    }
  }
  //output
  for(i=0;i<7;i++)
    fout << weekday_count[i] << ' ' ;
  fout << endl;

  return 0;
}
