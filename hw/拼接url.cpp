#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
static int SpliceString(string prefix, string suffix, string& splice_url);
void SpliceURL();
 
static int SpliceString(string prefix, string suffix, string& splice_url)
{
    if ((prefix.empty()) && (suffix.empty()))
    {
        splice_url = "/";
        return -1;
    }
 
    string prefix_temp, suffix_temp;
    string::size_type prefix_pos = prefix.find_first_of('/');
    string::size_type suffix_pos = suffix.find_first_of('/');
    if ((prefix_pos != -1))
    {
        prefix.erase(remove(prefix.begin(), prefix.end(), '/'), prefix.end());
    }
    if ((suffix_pos != -1))
    {
        suffix.erase(remove(suffix.begin(), suffix.end(), '/'), suffix.end());
    }
    if (!prefix.empty())
    {
        prefix_temp = "/" + prefix;
    }
    if (!suffix.empty())
    {
        suffix_temp = "/" + suffix;
    }
    splice_url = prefix_temp + suffix_temp;
    return 1;
}
 
void SpliceURL()
{
    string url_string, prefix_string, suffix_string, splice_url;
    while(getline(cin, url_string))
    {
        prefix_string = url_string.substr(0, url_string.find_first_of(','));
        suffix_string = url_string.erase(0, url_string.find_last_of(',') + 1);
        SpliceString(prefix_string, suffix_string, splice_url);
        printf("%s\n", splice_url.c_str());
    }
}
 
int main()
{
    SpliceURL();
    return 0;
}
/*
■ 题目描述

[拼接url]

给定一个URL前缀和URL后缀，通过”,”分割，需要将其连接为一个完整的URL，如果前缀结尾和后缀开头都没有“/”，需自动补上“/”连接符，如果前缀结尾和后缀开头都为“/”，需自动去重。

约束：不用考虑前后缀URL不合法情况。

输入描述

URL前缀（一个长度小于100的字符串)，URL后缀（一个长度小于100的字符串）。

输出描述

拼接后的URL。

示例1 输入输出示例仅供调试，后台判题数据一般不包含示例

输入

/acm,/bb

输出

/acm/bb

示例2 输入输出示例仅供调试，后台判题数据一般不包含示例

输入

/abc/,/bcd

输出

/abc/bcd

示例3 输入输出示例仅供调试，后台判题数据一般不包含示例

输入

/acd,bef

输出

/acd/bef

示例4 输入输出示例仅供调试，后台判题数据一般不包含示例

输入

,

输出

/
————————————————
版权声明：本文为CSDN博主「jidanzai666」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/jidanzai666/article/details/128358588
*/