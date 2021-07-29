#include <vector>
#include <iostream>
#include <stack>
#include <queue>

#include <functional>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createTree()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *l1 = new TreeNode(2);
    TreeNode *r1 = new TreeNode(3);
    root->left = l1;
    root->right = r1;
    TreeNode *l2 = new TreeNode(4);
    TreeNode *r2 = new TreeNode(5);
    l1->left = l2;
    l1->right = r2;
    TreeNode *l3 = new TreeNode(6);
    TreeNode *r3 = new TreeNode(7);
    r1->left = l3;
    r1->right = r3;
    return root;
}
/**
 *1.遍历算法
 *    (1).前序遍历(递归&&非递归)
 *    (2).中序遍历(递归&&非递归)
 *    (3).后序遍历(递归&&非递归)
 *    (4).层序遍历
 */

//(1).前序遍历(递归&&非递归)
/*递归*/
void preorderTraverse1(TreeNode *root)
{
    if(root == nullptr)
        return;
    cout << root->val << " ";
    preorderTraverse1(root->left);
    preorderTraverse1(root->right);
}

/*非递归1*/

void preorderTraverse2(TreeNode *root)
{
    if(root == nullptr)
        return;
    stack<TreeNode*> st;
    TreeNode *cur = root;
    while(cur!=nullptr||!st.empty())
    {
        while(cur!=nullptr)
        {
            st.push(cur);
            cout << cur->val << " ";
            cur = cur->left;
        }

        if(!st.empty())
        {
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
    }
}

/*非递归2*/
void preorderTraverse3(TreeNode *root)
{
    if(root == nullptr)
        return;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode *cur = st.top();
        st.pop();
        cout << cur->val << " ";
        if(cur->right!=nullptr)
            st.push(cur->right);
        if(cur->left!=nullptr)
            st.push(cur->left);
    }
}


//(2).中序遍历(递归&&非递归)
/*递归*/
void inorderTraverse1(TreeNode *root)
{
    if(root == nullptr)
        return;
    inorderTraverse1(root->left);
    cout << root->val << " ";
    inorderTraverse1(root->right);
}
/*非递归1*/
void inorderTraverse2(TreeNode *root)
{
    if(root == nullptr)
        return;
    stack<TreeNode*> st;
    TreeNode *cur = root;
    while(cur!=nullptr||!st.empty())
    {
        while(cur!=nullptr)
        {
            st.push(cur);
            cur = cur->left;
        }

        if(!st.empty())
        {
            TreeNode *top = st.top();
            st.pop();
            cout << top->val << " ";
            cur = top->right;
        }
    }
}


//(3).后序遍历(递归&&非递归)
/*递归*/
void postorderTraverse1(TreeNode*root)
{
    if(root == nullptr)
        return;
    postorderTraverse1(root->left);
    postorderTraverse1(root->right);
    cout << root->val << " ";
}
/*非递归*/
void postorderTraverse2(TreeNode*root)
{
    if(root == nullptr)
        return;
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    st1.push(root);
    while(!st1.empty())
    {
        TreeNode *cur = st1.top();
        st1.pop();
        st2.push(cur);
        if(cur->left != nullptr)
            st1.push(cur->left);
        if(cur->right != nullptr)
            st1.push(cur->right);
    }
    while(!st2.empty())
    {
        TreeNode *tmp = st2.top();
        cout << tmp->val << " ";
        st2.pop();
    }
}
//(4)层序遍历
vector<vector<int>> levelTraverse(TreeNode *root)
{
    if(root == nullptr)
        return {};
    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int curLen = q.size();
        res.push_back(vector<int>());
        for(int i = 0;i<curLen;i++)
        {
            auto cur = q.front();
            q.pop();
            res.back().push_back(cur->val);
            if(cur->left!=nullptr)
                q.push(cur->left);
            if(cur->right!=nullptr)
                q.push(cur->right);
        }
    }
    return res;
}

/*
 *2.求树的高度(递归&&非递归)
 *
 * 
 * 
 */

int treeDepth1(TreeNode *root)
{
    if(root == nullptr)
        return 0;
    return max(treeDepth1(root->left),treeDepth1(root->right))+1;
}

//树的深度(递归)

int treeDepth2(TreeNode *root)
{
    if(root == nullptr)
        return 0;
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    while(!q.empty())
    {
        int curLen = q.size();
        for(int i = 0;i<curLen;i++)
        {
            auto cur = q.front();
            q.pop();
            if(cur->left!=nullptr)
                q.push(cur->left);
            if(cur->right != nullptr)
                q.push(cur->right);

        }
        depth++; 
    }
    return depth;
}
//左视图

vector<int> treeLeft(TreeNode *root)
{
    if(root == nullptr)
        return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<int> res;
    while(!q.empty())
    {
        int curLen = q.size();
        for(int i = 0;i<curLen;i++)
        {
            auto cur = q.front();
            q.pop();
            if(cur->left!=nullptr)
                q.push(cur->left);
            if(cur->right != nullptr)
                q.push(cur->right);
            if(i == 0)
                res.push_back(cur->val);
        }

    }
    return res;
}

//右视图
vector<int> treeRight(TreeNode *root)
{
    if(root == nullptr)
        return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<int> res;
    while(!q.empty())
    {
        int curLen = q.size();
        for(int i = 0;i<curLen;i++)
        {
            auto cur = q.front();
            q.pop();
            if(cur->left!=nullptr)
                q.push(cur->left);
            if(cur->right != nullptr)
                q.push(cur->right);
            if(i == curLen-1)
                res.push_back(cur->val);
        }

    }
    return res;
}

//判断第K层有多少个节点
int getNumKthLevel(TreeNode *root,int k)
{
    if(root == nullptr||k<1)
        return 0;
    if(k == 1)
        return 1;
    return getNumKthLevel(root->left,k-1)+getNumKthLevel(root->right,k-1);
}
//求树的叶子节点(递归)
int getNumLeaf1(TreeNode *root)
{
    if(root == nullptr)
        return 0;
    if(root->left==nullptr&&root->right==nullptr)
        return 1;
    return getNumLeaf1(root->left)+getNumLeaf1(root->right);
}   


int getNumLeaf2(TreeNode *root)
{
    if(root == nullptr)
        return {};
    queue<TreeNode*> q;
    q.push(root);
    int leafNum=0;
    while(!q.empty())
    {
        int curLen = q.size();
        for(int i = 0;i<curLen;i++)
        {
            auto cur = q.front();
            q.pop();
            if(cur->left!=nullptr)
                q.push(cur->left);
            if(cur->right != nullptr)
                q.push(cur->right);
            if(cur->left == nullptr&&cur->right == nullptr)
                leafNum++;
        }
    }
    return leafNum;
}

//判断二叉树是否为平衡二叉树
bool isAvgTree(TreeNode *root)
{
    if(root == nullptr)
        return true;
    if(abs(treeDepth1(root->left)-treeDepth1(root->right))>1)
        return false;
    return isAvgTree(root->left)&&isAvgTree(root->right);
}

//树的镜像
TreeNode* treeMirror(TreeNode *root)
{
    if(root == nullptr)
        return root;
    TreeNode *left = treeMirror(root->right);
    TreeNode *right = treeMirror(root->left);
    root->left = left;
    root->right = right;
    return root;
}

int main()
{
    TreeNode* root = createTree();
    cout << "-----------preorderTraverse-----------" << endl;
    preorderTraverse1(root);
    cout << endl;
    preorderTraverse2(root);
    cout << endl;
    preorderTraverse3(root);
    cout << endl;

    cout << "-----------inorderTraverse-----------" << endl;
    inorderTraverse1(root);
    cout << endl;
    inorderTraverse2(root);
    cout << endl;

    cout << "-----------postorderTraverse-----------" << endl;
    postorderTraverse1(root);
    cout << endl;
    postorderTraverse2(root);
    cout << endl;

    cout << "-----------levelorderTraverse-----------" << endl;
    vector<vector<int>> res = levelTraverse(root);
    for_each(res.begin(),res.end(),[](vector<int> tmp){
        for_each(tmp.begin(),tmp.end(),[](int x){cout<<x<<" ";});
        cout << endl;
    });
    cout << endl;
    
    cout << "-----------tree algorithm-----------" << endl;
    int depth1 = treeDepth1(root);
    cout << "the depth of tree <1> is " << depth1;
    cout << endl;
    int depth2 = treeDepth2(root);
    cout << "the depth of tree <2> is " << depth2;
    cout << endl;

    vector<int> resLeft = treeLeft(root);
    cout << "the graph from left is " ;
    for_each(resLeft.begin(),resLeft.end(),[](int x){cout << x <<" ";});
    cout << endl;

    vector<int> resRight = treeRight(root);
    cout << "the graph from right is " ;
    for_each(resRight.begin(),resRight.end(),[](int x){cout << x <<" ";});
    cout << endl;

    int KthNum = getNumKthLevel(root,2);
    cout << "the num of Kth level is " << KthNum;
    cout << endl;

    int LeafNum1 = getNumLeaf1(root);
    cout << "the num of leaf <1> is " << LeafNum1;
    cout << endl;

    
    int LeafNum2 = getNumLeaf2(root);
    cout << "the num of leaf <2> is " << LeafNum2;
    cout << endl;

    bool isAvg = isAvgTree(root);
    cout << " the tree is AvgTree? " << isAvg;
    cout << endl;

    TreeNode *mirrorTree = treeMirror(root);
    preorderTraverse1(mirrorTree);
    cout << endl;
}