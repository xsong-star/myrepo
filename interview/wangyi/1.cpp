#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int q1,q2,p;
    cin >> q1 >> q2 >> p;
    int x;
    cin >> x;
    vector<vector<int>> ni;
    for(int i = 0;i<x;i++)
    {
        int ni1,ni2;
        cin >> ni1 >> ni2;
        ni.push_back({ni1,ni2,ni1+ni2});
    }
    int y;
    cin >> y;
    vector<int> m;
    
    for(int i = 0;i<y;i++)
    {
        int mj;
        cin >> mj;
        m.push_back(mj);
    }
    /*
        cout << q1 << " " << q2 << " " << p << endl;
        cout << x << endl;
        for_each(ni.begin(),ni.end(),[&](vector<int> t){
            for(int i = 0;i<t.size();i++)
            {
                cout << t[i] << " ";
            }
            cout << endl; 
        });
        cout << y << endl;
        for_each(m.begin(),m.end(),[&](int t){
            cout << t << endl;
        });
    */ 

    int target = q1+q2;

    int lt = q1+q2-p;
    int rt = q1+q2+p;   

    int res_count = 0;
    for(int i = 0;i<x;i++)
    {
        if(lt<=ni[i][ni[i].size()-1]&&ni[i][ni[i].size()-1]<=rt)
            res_count++;
    }
    vector<int> tmp;
    function<void(int)> dfs = [&](int idx)->void
    {
        if(idx == y+1)
            return;
        if(tmp.size()>2)
            return;
        if(tmp.size() == 2)
        {
            if(tmp[0]+tmp[1]<=rt&&tmp[0]+tmp[1]>=lt)
                res_count++;
        }
        
        for(int i = idx;i<y;i++)
        {
            tmp.push_back(m[i]);
            dfs(i+1);
            tmp.pop_back();
        }
    };
    dfs(0);
    cout << res_count << endl;
    return 0;
}