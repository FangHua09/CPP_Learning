/*
练习 13.28：TreeNode 和 BinStrTree，实现默认构造与必要拷贝控制
// 深拷贝
*/
#include <string>
using namespace std;

class TreeNode
{
private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;

public:
    // 默认构造
    TreeNode(TreeNode *left, TreeNode *right, const string &s = "") : left(left), right(right), value(s) {}

    // 拷贝构造
    TreeNode(const TreeNode &orgi)
    {
        // 递归深拷贝子树
        value = orgi.value;
        count = orgi.count;
        if (orgi.left)
        {
            left = new TreeNode(*orgi.left);
        }
        else
        {
            left = nullptr;
        }

        if (orgi.right)
        {
            right = new TreeNode(*orgi.right);
        }
        else
        {
            right = nullptr;
        }
    }

    // 拷贝赋值运算符
    TreeNode &operator=(const TreeNode &rhs)
    {
        // 先处理拷贝构造的事，再处理析构的事
        if (&rhs == this)
            return *this; // 自赋值保护，上面的作废
        delete left;
        delete right;
        count = rhs.count;
        value = rhs.value;
        if (rhs.left)
        {
            left = new TreeNode(*rhs.left);
        }
        else
        {
            left = nullptr;
        }

        if (rhs.right)
        {
            right = new TreeNode(*rhs.right);
        }
        else
        {
            right = nullptr;
        }
    }

    // 析构
    ~TreeNode()
    {
        if (left)
        {
            delete left;
        }

        if (right)
        {
            delete right;
        }
    }
};

class BinStrTree
{
private:
    TreeNode *root;

public:
    // 默认构造
    BinStrTree() : root(nullptr) {}

    // 拷贝构造
    BinStrTree(const BinStrTree &orgi)
    {
        // 拷贝构造：拷贝整棵树，调用TreeNode拷贝构造
        if (orgi.root)
        {
            root = new TreeNode(*orgi.root);
        }
        else
        {
            root = nullptr;
        }
    }

    // 拷贝赋值运算符
    BinStrTree &operator=(const BinStrTree &rhs)
    {
        // 如果自赋值
        if (rhs.root == this->root)
            return *this;
        delete root; // 释放当前树
        if (rhs.root)
        {
            root = new TreeNode(*rhs.root);
        }
        else
        {
            root = nullptr;
        }
        return *this;
    }

    // 析构
    ~BinStrTree()
    {
        delete root; // 释放根节点，TreeNode析构会递归释放整棵树
    }
};
