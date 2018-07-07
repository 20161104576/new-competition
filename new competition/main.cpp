//
//  main.cpp
//  new competition
//
//  Created by fjh on 2018/6/29.
//  Copyright © 2018年 fjh. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <String>
#include <sstream>
#include <fstream>
using namespace std;


void Score()//评委打分
{
    int j,max=0,min=100,m;
    double sf;
    int f[10];
    ifstream fin("/Users/fjh/Desktop/new competition/student.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        max=0;
        min=100;
        sf=0;
        cout <<"姓名,性别,班级,节目类型,电话："<< endl << line << endl; //整行输出
        
        for(j=1;j<=5;j++)//评分
        {
            cout<<"评委 "<<j<<" 给分:";
            cin>>f[j];
            sf=sf+f[j];
            if(max<f[j])
            {
                max=f[j];
            }
            if(min>f[j])
            {
                min=f[j];
            }
        }
        cout<<"去掉最高分:"<<max<<endl;
        cout<<"去掉最低分:"<<min<<endl;
        sf=(sf-max-min)/3;
        cout<<"选手最终得分:"<<sf<<endl;
        
        ofstream outfile("/Users/fjh/Desktop/new competition/write.csv",ios::app);  //写入文件
        outfile<<line<<","<<sf<<endl;
        
        cout<<"继续1，否2"<<endl;//中途结束评分
        cin>>m;
        if(m==0)
        {
            break;
        }
    }
    cout<<"完成"<<endl;
}

void student()//选手信息
{
    int i=0;
    ifstream fin("/Users/fjh/Desktop/new competition/student.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        i++;
        cout<<"第 "<< i <<" 位选手:"<<endl;
        cout <<"姓名,性别,班级,节目类型,电话："<< endl << line << endl;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    // std::cout << "Hello, World!\n";
    int i;
    while(1)
    {
       
        cout<<"      | ********欢迎来比赛打分系统!******** |\n";
        cout<<"      | ------------------------------ |\n";
        cout<<"      |         1.演员信息               |\n";
        cout<<"      |         2.评分信息               |\n";
        cout<<"      |         3.退出系统               |\n";
        cout<<"      | ------------------------------ |\n";
        cout<<"\n 请选择功能：";
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                student();
                break;
                
            case 2:
                Score();
                break;
            case 3:
                return 0;
        }
    }
    
    return 0;
}
