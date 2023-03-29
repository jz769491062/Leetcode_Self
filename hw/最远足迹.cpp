#include <bits/stdc++.h>
 
using namespace std;
vector<int> nums;
 
string str;
 
void init()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
vector <string> getstrings3(const std::string &s, char delim)
{
    vector <string> strings;
    size_t last = 0;
    size_t index = s.find_first_of(delim, last);
    while (index != std::string::npos) {
        strings.push_back(s.substr(last, index - last));
        last = index + 1;
        index = s.find_first_of(delim, last);
    }
    if (index - last > 0) {
        strings.push_back(s.substr(last, index - last));
    }
    return strings;
}
 
int main(int argc, const char *argv[])
{
    init();
    string str;
    cin >> str;
    string res;
    int maxDistance = -1;
    while (true) {
        int leftIndex = str.find_first_of('(');
        int rightIndex = str.find_first_of(')');
        if (leftIndex == std::string::npos || rightIndex == std::string::npos) {
            break;
        }
        string ele = str.substr(leftIndex + 1, rightIndex - leftIndex - 1);
        vector <string> es = getstrings3(ele, ',');
        bool flag = true;
        for (string s: es) {
            if (s.front() == '0') {
                flag = false;
                break;
            }
            if (stoi(s) <= 0 || stoi(s) >= 1000) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            str = str.substr(rightIndex + 1);
            continue;
        }
        int number1 = stoi(es[0]);
        int number2 = stoi(es[1]);
 
        int distance = number1 * number1 + number2 * number2;
        if (distance > maxDistance) {
            res = "(" + es[0] + "," + es[1] + ")";
            maxDistance = distance;
        }
        str = str.substr(rightIndex + 1);
    }
 
    res = (maxDistance == -1) ? "(0,0)" : res;
    cout << res << endl;
    return 0;
}
/*
【最远足迹】

某探险队负责对地下洞穴进行探险。探险队成员在进行探险任务时，随身携带的记录器会不定期地记录自身的坐标，但在记录的间隙中也会记录其他数据。探索工作结束后，探险队需要获取到某成员在探险过程中相对于探险队总部的最远的足迹位置。

仪器记录坐标时，坐标的数据格式为(x,y)，如(1,2)、(100,200)，其中0<x<1000，0<y<1000。同时存在非法坐标，如(01,1)、(1,01)，(0,100)属于非法坐标。
设定探险队总部的坐标为(0,0)，某位置相对总部的距离为：x*x+y*y。
若两个座标的相对总部的距离相同，则第一次到达的坐标为最远的足迹。
若记录仪中的坐标都不合法，输出总部坐标（0,0）。
备注：

不需要考虑双层括号嵌套的情况，比如sfsdfsd((1,2))。

输入描述

字符串，表示记录仪中的数据。

如：ferga13fdsf3(100,200)f2r3rfasf(300,400)

输出描述

字符串，表示最远足迹到达的坐标。

如： (300,400)

示例1 输入输出示例仅供调试，后台判题数据一般不包含示例

输入

ferg(3,10)a13fdsf3(3,4)f2r3rfasf(5,10)

输出

(5,10)

说明

记录仪中的合法坐标有3个： (3,10)， (3,4)， (5,10)，其中(5,10)是相距总部最远的坐标， 输出(5,10)。

示例2 输入输出示例仅供调试，后台判题数据一般不包含示例

输入

asfefaweawfaw(0,1)fe

输出

(0,0)

说明

记录仪中的坐标都不合法，输出总部坐标（0,0）。
————————————————
版权声明：本文为CSDN博主「jidanzai666」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/jidanzai666/article/details/128348947
*/