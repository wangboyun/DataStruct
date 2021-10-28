/*
 * @Description: 根据先序与中序遍历序列建立二叉树
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-07 11:09:31
 */
 
#include <iostream>
#include <vector>
using namespace std;

struct BtreeNode{
    int data;
    BtreeNode* left;
    BtreeNode* right;
};

class Solution{
public:
    void inorder(BtreeNode* root){
        if(root == nullptr)
            return;

        //先中序遍历左节点
        inorder(root->left);
        
        std::cout << root->data<< " ";
        inorder(root->right);
    }

    
    void pre_in_order(vector<int>& preorder , vector<int>& inorder ,
                int pre_left, int pre_right, int in_left , int in_right, BtreeNode* root){

        root->data = preorder[pre_left];
        root->left = new BtreeNode;
        root->right = new BtreeNode;
        int m = in_left;
        while (inorder[m] != preorder[pre_left])
            m++;
        if(m == in_left){
            root->left = nullptr;
        } 
        else {
            pre_in_order(preorder, inorder, pre_left + 1 ,pre_left + m - in_left , in_left, m-1, root->left);
        }
        if(m == in_right)
            root->right = nullptr;
        else
            pre_in_order(preorder, inorder, pre_left + m - in_left +1, pre_right ,m+1, in_right,root->right);
    }

};

int main(){
    BtreeNode root;
    vector<int> preorder{1,2,3,4,5,6,7};
    vector<int> inorder{3,2,4,1,5,7,6};
    Solution sl;
    int pre_left = 0;   int pre_right = preorder.size()-1;
    int in_left = 0;   int in_right = inorder.size()-1;
    sl.pre_in_order(preorder,inorder,pre_left,pre_right,in_left,in_right,&root);
    sl.inorder(&root);
    std::cout << std::endl;
    return 0;
}