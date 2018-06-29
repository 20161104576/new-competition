//
//  main.cpp
//  new competition
//
//  Created by fjh on 2018/6/29.
//  Copyright © 2018年 fjh. All rights reserved.
//

#include <iostream>
using namespace std;
struct racer{
    char rac_name[20];//选手名字
    char rac_sex;//选手性别
    char rac_class[10];//选手班级
    int rac_number[10];//选手电话号码
    char rac_category;//节目类别
    char rac_proname;//节目名称
};

struct rater{
    char rat_name[20];//裁判名字
    char rat_sex;//裁判性别
    int rat_number[15];//裁判电话号码
};
int main()
{
    int i;
    double score[5];
    double max=-1;
    double min=200;
    double sum=0.0;
    double x=0.0;
    cin >>score[0]>>score[1]>>score[2]>>score[3]>>score[4];
    for (i = 0; i< 5; i++)
    {
        sum = sum + score[i];
        if (score[i] > max)
        {
            max = score[i];
        }
        if (score[i] < min)
        {
            min = score[i];
        }
    }
    sum = sum - max - min;
    x = sum / 3 ;
    cout << "该选手的最后得分:" << x << endl;
    return 0;
}
