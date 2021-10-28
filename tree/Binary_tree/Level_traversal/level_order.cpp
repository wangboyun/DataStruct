/*
 * @Description:    二叉树的层次遍历( 一种广度优先算法 ，BFS)
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-07 10:00:28
 */
#include <iostream>
#include <queue>

struct BtreeNode{
    int data;
    BtreeNode* left;
    BtreeNode* right;
};

class Solution{
public:
    void levelorder(BtreeNode* root){
        std::queue< BtreeNode* > btque;
        btque.push(root);
        while(!btque.empty()){
            //BtreeNode* temp = btque.front();
            std::cout << btque.front()->data << " ";
            if(btque.front()->left)
                btque.push(btque.front()->left);
            if(btque.front()->right)
                btque.push(btque.front()->right);
            btque.pop();
        }
    }

};

int main(){
    BtreeNode root{1,nullptr,nullptr};
    BtreeNode a{2,nullptr,nullptr};
    BtreeNode b{3,nullptr,nullptr};
    BtreeNode c{4,nullptr,nullptr};
    BtreeNode d{5,nullptr,nullptr};
    BtreeNode e{6,nullptr,nullptr};
    root.left = &a;
    root.right = &b;
    a.left = &c;
    a.right = &d;
    b.left = &e;
    Solution sl;
    sl.levelorder(&root);
    std::cout << std::endl;
    return 0;
}