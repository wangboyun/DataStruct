/*
 * @Description: 二叉排序树的查找算法
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-08 10:48:57
 */
#include <iostream>

struct BtreeNode{
    int data;
    BtreeNode* left;
    BtreeNode* right;
};

class Solution{
public:
    bool search_bst(const int val , const BtreeNode* root){
        if(root == nullptr)
            return false;
        if(val == root->data)
            return true;
        else if (val > root->data)
            return search_bst(val, root->right);
        else
            return search_bst(val , root->left);
    }
    
};

int main(){
    BtreeNode root{50,nullptr,nullptr};
    BtreeNode a{30,nullptr,nullptr};
    BtreeNode b{80,nullptr,nullptr};
    BtreeNode c{20,nullptr,nullptr};
    BtreeNode d{40,nullptr,nullptr};
    BtreeNode e{90,nullptr,nullptr};
    BtreeNode f{35,nullptr,nullptr};
    BtreeNode g{82,nullptr,nullptr};
    BtreeNode h{32,nullptr,nullptr};
    BtreeNode k{85,nullptr,nullptr};
    root.left = &a;
    root.right = &b;
    a.left = &c;
    a.right = &d;
    d.left = &f;
    f.left = &h;
    b.right = &e;
    e.left = &g;
    g.right = &k;
    Solution sl;
    int val = 32;
    std::cout << sl.search_bst(val,&root)<< std::endl;
    return 0;
}