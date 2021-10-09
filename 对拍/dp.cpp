#include<iostream>
#include<cstdio>
#include<windows.h>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    int ok=0;
    int n=200;
    for(int i=1; i<=n; ++i)
    {
        system("make.exe > make.txt");
        system("std.exe < make.txt > std.txt");
        double begin=clock();
        system("baoli.exe < make.txt > baoli.txt");
        double end=clock();

        double t=(end-begin);
        if(system("fc std.txt baoli.txt"))
        {
            printf("Test:%d Wrong Answer\n",i);
            return 0;
        }
        else if(t>1000) //1秒
        {
            printf("Test:%d Time Limited Enough time %.0lfms\n",i,t);
            printf("TLE\n");
            return 0;
        }
        else
        {
            printf("Test:%d Accepted Time: %.0lfms\n",i,t);
            ok++; //AC数量+1
    	}
    }
    printf("\n");
    double res=100.0*ok/n;
    printf("Total %d tests，AC %d tests。 scores%.1lf。",n,ok,res);

    Sleep(1000);//休眠1秒，为了节约对拍次数。
}
