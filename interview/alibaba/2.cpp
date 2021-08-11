#include <stack>
#include <vector>
#include <functional>
#include <iostream>
using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v):val(v),left(nullptr),right(nullptr){}
    TreeNode():val(0),left(nullptr),right(nullptr){}
};

int main()
{
    int t;
    cin >> t;
    vector<TreeNode*> treeVector;
    function<TreeNode*(vector<int>&)> create_Tree = [](vector<int>&t)->TreeNode*
    {
        stack<int> s;
        
        
    };
    for(int i=0;i<t;i++)
    {
        int n;
        cint >> n;
        vector<int> tmp;
        for(int j = 0;j<n;j++)
        {
            int val;
            cin >> val
            tmp.push_back(val);
        }
        treeVector.push_back(create_Tree(tmp));
    }
    function<bool(TreeNode *)> Judge_Tree = [](TreeNode *root)->bool
    {

    };
    for(auto &tree:treeVector)
    {
        if(Judge_Tree(tree))
            cout << "YES" << endl;
        else    
            cout << "NO" << endl;
    }
}
