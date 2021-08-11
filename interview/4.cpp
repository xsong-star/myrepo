#include <thread>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
随着中国经济的增强，无数的企业正在“出海”，作为中国文化的视频传媒佼佼者，爱奇艺也在“出海”的队伍里扬帆起航，但在出海的过程中遇到了一个语言的问题，为了让更多国外用户能体验我们丰富多彩的中国文化，需要将中文的字幕翻译成各国语言，为此，我们的小明同学实现了一个万能翻译的系统，然而由于我们需要翻译的字幕太多，无法第一时间翻译完让用户观看到，聪明的你能帮帮我们的小明同学吗？
要求：
1. 请使用多线程重写translatedAll方法来提升翻译速度
2. 请注意翻译后的line的前后顺序要和输入的List<line>的顺序保持一致，因为字幕的顺序是不能乱的
*/
string s;
vector<int> c;
string res;
void func(int idx)
{
    int l = c[idx];
    int length;
    if(idx == c.size()-1)
        length = s.size()-c[idx];
    else
    {
        length = c[idx+1] - l;
    }
}

int main()
{
    cin>>s;

    c.push_back(0);
    for(int i = 0;i<s.size();i++)
    {
        if(s[i] == ',')
        {
            c.push_back(i);
        }
    }
    int n = c.size();
    vector<thread> tv;
    for(int i = 0;i<n;i++)
    {
        tv.push_back(thread(func,i));
    } 
    
}