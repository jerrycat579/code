//实现一个经典"猜数字"游戏。给定答案序列和用户猜的序列,统计有多少数字位置正确  (A),有多少数字在两个序列都出现过但位置不对(B)。  输入包含多组数据。每组输入第一行为序列长度n,第二行是答案序列,接下来是若干  猜测序列。猜测序列全0时该组数据结束。n=0时输入结束。
/*样例输入:  4  1355
1123  4335  6551  6135  1355  0000  10  1222456669  1234567891  1122334455  1213151619  1225556667  0000000000  0  样例输出:  Game 1:  (1,1)  (2,0)  (1,2)  (1,2)  (4,0)  Game 2:  (2,4)
(3,2)  (5,0)  (7,0)*/
//问题一：怎么存储猜测序列
//不要忘了scanf数值前的符号除了string外都需要进行标记 
#include<bits/stdc++.h>
using namespace std;
int main()
{  
  int n,m;//n标定序列的长度 
  int round = 1;//定义回合数
  int ans[1000];//不能是用n作为数组长度 必须提前定义长度
  int gue[1000];
  //int A,B = 0;
  while(scanf("%d",&n)==1 && n)//确保n是一个数 且 不为0
  {
    printf("Game %d:\n",round++);
    for(int i = 0;i<n;i++) scanf("%d", &ans[i]);//输入答案序列
    for(;;)
    {
     int A,B = 0;//A，B需要定义在循环内部
     for(int i =0;i<n;i++) 
     {
       scanf("%d", &gue[i]); //输入猜测序列
       if(ans[i] == gue[i]) A++;//判断位置相同

     }
     if(gue[0] == 0) break;
     for(int j = 1;j<=9;j++)
     {
      int c1 = 0;//ans重复出现的次数
      int c2 = 0;//gue重复出现的次数 
      for(int k = 0;k<n;k++)
      {
        if(ans[k]==j) c1++;
        if(gue[k] == j) c2++; 

       }
       if(c1 < c2) B += c1; else B += c2;

     }
     printf(" (%d,%d)\n", A, B-A);
    }
  }
  return 0;
}
   