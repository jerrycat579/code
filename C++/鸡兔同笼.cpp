#include<bits/stdc++.h>
using namespace std;
int main()
{
  int sum = 0;
  for(int i = 10; i<=11 ; i++)
  {
    for(;;)
    {
      sum += i%10;//每次循环先加上各位数
      i = i/10; //然后缩小10倍
      if(i%10 != 0 &&i/10 == 0) 
      {
       sum += i;//如果if语句成立 说明已经是个位数了     
      }
      break;
    }
    cout<<sum;
  }
  return 0;
}
