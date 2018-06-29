//
//  main.cpp
//  new competition
//
//  Created by fjh on 2018/6/29.
//  Copyright © 2018年 fjh. All rights reserved.
//

# include<iostream>
# include<iomanip>
# define N  20   //评委的人数最多为20
# define M  50   //参赛选手的人数最多为50

using namespace std;

float CountAthleteScore(int , float ave, int n, float s[], int m);
void Sort(float a[], int n);
void Print(float a[], int n,int bh[]);
float b[M];
int bh[M];

int main()
{
    int i=0,n,m,r,t=0;
    float s[N],a[M],ave=0.0,sum=0.0;
    char name[20],sex[2];
    cout<<"******欢迎使用评分系统******"<<endl;
    cout<<"   请输入评委个数（>=3)：";
    cin>>n;
    cout<<"   请输入参赛选手个数(>=2)：";
    cin>>m;
    cout<<endl;
    
    
    for(i=0;i<m;i++)
    {cout<<"       选手参赛中     "<<endl;
        cout<<"       编号为：";
        cin>>bh[i];
        a[r++]=CountAthleteScore(bh[i], ave, n,s, m);
    }
    
    
    
    cout<<m<<"这位选手的平均成绩分别是："<<endl;
    for(r=0;r<m;r++)
        cout<<a[r]<<"  ";
    cout<<endl;
    Sort(a, m);
    Print( a, n,bh);
    return 0;
}
