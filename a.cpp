#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char Left[3][7];
char Right[3][7];
char result[3][7];
bool IsFake(char c,bool light);//轻的是true，重的是false
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        for(int i;i<3;i++)
        {
            cin>>Left[i]>>Right[i]>>result[i];
        }
        for(char c='A';c<='L';c++)
        {
            if(IsFake(c,true))
            {
                cout<<c<<'is the counterfeit coin and it is light.'<<endl;
                break;
            }
            else if (IsFake(c,false))
            {
                cout<<c<<'is the counterfeit coin and it is heavy.'<<endl;
                break;
            }
        }
    }
   return 0; 
}
bool IsFake(char c,bool light)//light为真就是表明假币是轻的
{
    for(int i=0;i<3;i++)
    {
        char *pLeft,*pRight;//目的是指向天平两边的字符串
       if(light)
       {
           pLeft=Left[i];
           pRight=Right[i];
       }
       else//如果假设假币是重的，则把称量结果左右对换
       {
           pLeft=Right[i];
           pRight=Left[i];
       }
       switch (result[i][0])
       {
       case 'u':
        if(strchr(pRight,c)==NULL)
           {
               return false;
           }
           break;
       case 'e':
       if(strchr(pLeft,c)||strchr(pRight,c))
       {
           return false;
       }
       break;
       case 'd':
       if(strchr(pLeft,c)==NULL)
       {
           return false;
       }
       break;
       }
    }
    return true;
}