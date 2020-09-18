#include <fstream>
#include <cstring>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

string tenToN(int num,int n){
  int i=0,j=0;
  char reminders[15];
  int reminders_flag=0,quotient=num;
  memset(reminders,0,sizeof(char)*15);
  string num_new;
  //1.得到倒序的余数
  do{
    reminders[i]=quotient%n+'0';
    if(reminders[i]>'9'){
      switch(reminders[i]){
        case '0'+10:
          reminders[i]='a';
          break;
        case '0'+11:
          reminders[i]='b';
          break;
        case '0'+12:
          reminders[i]='c';
          break;
        case '0'+13:
          reminders[i]='d';
          break;
        case '0'+14:
          reminders[i]='e';
          break;
        case '0'+15:
          reminders[i]='f';
          break;
      }
    }
    quotient = quotient/n;
    i++;
  }while(quotient!=0);
  //2.得到正序的余数
  for(i=14;i>=0;i--){
    if(reminders_flag==0 && reminders[i]==0) continue;
    if(reminders_flag==0 && reminders[i]!=0) reminders_flag=1;
    num_new+=reminders[i];
    j++;
  }
  return num_new;
}
int isPalsquare(string num_s){
  int i=0;
  int digits=num_s.length();
  for(i=0;i<digits;i++){
    if(num_s[i]!=num_s[digits-i-1]) return 0;
    if(i == digits/2 || digits-i-1 == digits/2) break;
  }
  return 1;
}
int main(){
  int i=0;
  int n=0;
  string num_s;
  //input
  ifstream fin("palsquare.in");
  fin >> n;
  //compute && output
  ofstream fout("palsquare.out");
  for(i=1 ; i<=300;i++){
    num_s=tenToN(pow(i,2),n);
    if(isPalsquare(num_s)){
      fout << i << ' ' << num_s << endl;
    }
  }

  return 0;
}
