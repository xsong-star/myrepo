/*
求滑动窗口平均数最大增幅
时间限制： 1000MS
内存限制： 65536KB
题目描述：
一个自然数数组arr，有大小为k的数据滑动窗口从数组头部往数组尾部滑动，窗口每次滑动一位，窗口最后一位到达数组末尾时滑动结束。
窗口每次滑动后，窗口内k个整数的平均值相比滑动前会有一个变化幅度百分比p。
输入描述
输入数组和窗口大小k，数组和窗口大小用英文冒号分隔，数组内自然数用英文逗号分隔
输出描述
滑动开始到结束后出现的最大p值
样例输入
5,6,8,26,50,48,52,55,10,1,2,1,20,5:3
样例输出
475.00%
提示
过程如下：
滑动窗口位置                                            窗口平均值        平均值增幅
----------------------------------       -------         --------

[5  6  8] 26  50  48  52  55  10  1  2  1  20  5          6.33 

 5 [6  8  26] 50  48  52  55  10  1  2  1  20  5          13.33        110.53%

 5  6 [8  26  50] 48  52  55  10  1  2  1  20  5          28.00        110.00%

 5  6  8 [26  50  48] 52  55  10  1  2  1  20  5          41.33        47.62%

 5  6  8  26 [50  48  52] 55  10  1  2  1  20  5          50.00        20.97%

 5  6  8  26  50 [48  52  55] 10  1  2  1  20  5          51.67        3.33%

 5  6  8  26  50  48 [52  55  10] 1  2  1  20  5          39.00        -24.52%

 5  6  8  26  50  48  52 [55  10  1] 2  1  20  5          22.00         -43.59%

 5  6  8  26  50  48  52  55 [10  1  2] 1  20  5          4.33           -80.30%

 5  6  8  26  50  48  52  55  10 [1  2  1] 20  5          1.33           -69.23%

 5  6  8  26  50  48  52  55  10  1 [2  1  20] 5          7.67            475.00%

 5  6  8  26  50  48  52  55  10  1  2 [1  20  5]        8.67             13.04%
 */

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
string input = "5,6,8,26,50,48,52,55,10,1,2,1,20,5:3";
istringstream ss(input);
string token;

int main(){
    while(getline(ss, token, ',')) {
        cout << token << endl;
    }
    return 0;
}