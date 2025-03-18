/*长度为n的环状串有n种表示法,分别为从某个位置开始顺时针得到。例如,图3-4的环
状串  有10种表示:  CGAGTCAGCT,GAGTCAGCTC,AGTCAGCTCG等。在这些表示法中,字典
序最小的称  为"最小表示"。 输入一个长度为n(n≤100)的环状DNA串(只包含A、C、G、
T这4种字符)的一种表示法,你的任务是输出该环状串的最小表示。例如,CTCC的最小表
示是  CCCT,CGAGTCAGCT的最小表示为AGCTCGAGTC。*/
/*思路：首先进行数组的输入 可以进行截断 重新进行数组的比较 截断后就进行更新 然后我
们进行比较时可以从第二个开始毕竟第一个是相同的最小元素*/
//尽快学习指针
 /*思路1（想要依靠求和解决问题 但是求和数目不固定 依旧需要从小比较 导致没有后续思路
 ）：定义一个新数组等于目标数组重复两次 这个数组就包含了我们所有可能的环状串
 //对于任一环状串 我们只需要比较串一半的长度即可
 //先找到数组中的最小值
 for(int i = 0;i<length;i++)
 {
  int a = newcircle[i];
  while()
  else a = newcircle[i+1];
 }*/
#include<bits/stdc++.h>
using namespace std;
#define maxn 105
char circle[maxn];
char tcircle[2*maxn];
char newcircle[maxn];

int main()
{
 //输入目标数组 
 for(int i = 0;i<maxn;i++)
 {
  scanf("%c",&circle[i]);
 }
 //数组长度
 int length = strlen(circle);//数组长度
 //
 for(int j = 0;j <2*length;j++)
 {
  tcircle[j] = circle[j%length];
 }
 //找最小值
 char min = circle[0];
 for(int i = 1;i<length;i++)
 {
  if(min<=circle[i]) min = min;
  else min = circle[i];
 }
 //
 int a;
 for(int i = 0;i<length;i++)
 {
  
  if(circle[i] = min) a =circle[i+1];
  
 }
 
 return 0;
}



