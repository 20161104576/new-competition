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


float CountAthleteScore(int , float ave, int n, float s[], int m)
{
    int j,k,r=0;
    static int w=0;
    float t,sum=0.0;
    ave=0.0;
    
    cout<<"请输入该选手的成绩："<<endl;
    for(k=0;k<n;k++)//不加花括号会出现错误
    {
        cout<<endl;
        cout<<"输入第"<<k+1<<"位评委给分: ";
        cin>>s[k];
        if((s[k]>10)||(s[k]<0))
        {
            cout<<"第"<<k+1<<"位评委输入时出现错误,请重新输入"<<endl;
            k--;
        }
    }
    
    
    
    for(k=0;k<n-1;k++)     //对每位选手的成绩排序，以便去掉最低分和最高分;
    {
        for(j=k+1;j<n;j++)
            if(s[k]<s[j])
            {
                t=s[k];
                s[k]=s[j];
                s[j]=t;
            }
    }
    cout<<"对评委给分由高到低进行排序："<<endl;
    for(k=0;k<n;k++)
        cout<<s[k]<<"  ";
    cout<<endl;
    cout<<"去掉一个最高分"<<s[0]<<",一个最低分"<<s[n-1]<<",后的结果："<<endl;
    for(k=0;k<n-2;k++)
        
    {
        cout<<s[k+1]<<"  ";
        sum=sum+s[k+1];
    }
    cout<<endl;
    ave= sum/float(n-2);
    b[w++]=ave;
    cout<<"该选手平均分="<<ave<<endl;
    return ave;
    cout<<"*************************"<<endl;
    
}
void Sort(float a[],  int m)
{
    
    int j;
    int r;
    float t;
    for(r=0;r<m-1;r++)     //对平均成绩进行排序;
    {
        for(j=0;j<m-1-r;j++)
            if(a[j]<a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
    }
    cout<<"由高到低排序后的成绩为："<<endl;
    for(r=0;r<m;r++)
        cout<<a[r]<<"  ";
    cout<<endl;
    cout<<"************************"<<endl;
    cout<<"************************"<<endl;
}













