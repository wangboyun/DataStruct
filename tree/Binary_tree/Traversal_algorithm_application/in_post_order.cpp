/*
 * @Description: 根据中序与后序遍历序列建立二叉树
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-07 11:09:31
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root){
        if(root == nullptr)
            return;

        //先中序遍历左节点
        inorder(root->left);
        
        std::cout << root->val<< " ";
        inorder(root->right);
    }

    void creatTree(vector<int>& inorder, vector<int>& postorder,
    int in_left , int in_right , int po_left, int po_right, TreeNode* root) {
        root->val = postorder[po_right];
        root->left = new TreeNode;
        root->right = new TreeNode;
        int m = in_left;
        while(inorder[m] != postorder[po_right])
            m++;
        if(m == in_left){
            //无左子树
            root->left = nullptr;
        }
        else {
            // 左子树
            creatTree(inorder,postorder,in_left,m-1,po_left,po_left+m-1-in_left,root->left);
        }
        if(m == in_right){
            // 无右子树
            root->right = nullptr;
        }
        else {
            creatTree(inorder,postorder,m+1,in_right,po_right-in_right+m,po_right-1,root->right);
        }
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode;
        int pleft = 0;
        int pright = postorder.size() - 1;
        int inleft = 0;
        int inright = inorder.size() - 1;
        creatTree(inorder,postorder,inleft,inright,pleft,pright,root);
        return root;
    }
};

int main(){
    TreeNode* root;
    vector<int> inorder{1,2,3,4};
    vector<int> postorder{3,4,2,1};
    Solution sl;
    root = sl.buildTree(inorder,postorder);
    sl.inorder(root);
    std::cout << std::endl;
    return 0;
}
