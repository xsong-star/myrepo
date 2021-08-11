#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;

/*
 *1
 *5
 *1 1 1 1 2
 */

int main()
{
    int T,N;
    cin >> T;
    cin >> N;
    vector<int> A(N);
    vector<string> res;
    for(int k = 0;k<T;k++)
    {
        unordered_set<int> s;
        int sum = 0;
        for(int i = 0;i<N;i++)
        {
            cin >> A[i];
            sum += A[i];
            if(s.count(A[i])!=1)
                s.insert(A[i]);
        }

        vector<bool> dp(sum+1,false);
        dp[0] = true;
        if(s.count(1) == 1)
            dp[1] = true;
        else
        {
            res.push_back(string("No"));
            continue;
        }

        for(int i = 2;i<=sum;i++)
        {
            if(s.count(i) == 1)
            {   
                dp[i]=true;
            }
            else
            {
                for(auto &c:s)
                {
                    if(c<i)
                    {
                        if(dp[i-c]==true)
                            dp[i] = true;
                    }
                }
                if(dp[i]==false)
                {
                    res.push_back(string("No"));
                    continue;
                }
            }
        }
        res.push_back(string("Yes"));
        continue;              
    }
    for(int i = 0;i<T;i++)
    {
        cout << res[i] << endl;
    }
}
