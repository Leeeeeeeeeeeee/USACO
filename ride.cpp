/*
ID: qq267181
TASK: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
  int i;
  int sum1 = 1,sum2 = 1;
  string s1,s2;
  ofstream fout ("ride.out");
  ifstream fin ("ride.in");
  fin >> s1;
  if(s1.length() > 8) exit(1);
  fin >> s2;
  if(s2.length() > 8) exit(1);
  for(i = 0;i < s1.size();i++)
    sum1 = sum1 * (s1[i]-64);
  for(i = 0;i < s2.size();i++)
    sum2 = sum2 * (s2[i]-64);
  if(sum1 % 47 == sum2 % 47)
    fout << "GO" << endl;
  else
    fout << "STAY" << endl;
  return 0;
}
