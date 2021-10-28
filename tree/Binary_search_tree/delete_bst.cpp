/*
 * @Description: 删除二叉排序树的节点
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-08 15:43:29
 */
#include <iostream>
#include <vector>

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
    /* 插入 */
    BtreeNode* insert_bst(const int val , BtreeNode* root){
        
        if(root == nullptr){
            BtreeNode* node = new BtreeNode{val ,nullptr ,nullptr};
            root = node;
        }
        if(val > root->data)
            root->right = insert_bst(val,root->right);
        else if (val < root->data)
            root->left = insert_bst(val,root->left);

        return root;
    } 

    /* 搜索 */
    BtreeNode* search_bst(const int val ,  BtreeNode* root){
        if(root == nullptr)
            return nullptr;
        if(val == root->data)
            return root;
        else if (val > root->data)
            return search_bst(val, root->right);
        else
            return search_bst(val , root->left);
    }

    
    //查找父节点,迭代版
    BtreeNode* get_parent_bst(BtreeNode* root,BtreeNode * child , int& flag)
    {
        static BtreeNode *parent = nullptr;
        if(root)
        {
            if(root->left ==child) {
                parent = root;
                flag = 0;           // 左孩子
            }

            if(root->right == child ){
                parent =  root;
                flag = 1;          // 右孩子
            }
               
            get_parent_bst(root->left, child, flag);
            get_parent_bst(root->right, child, flag);
        }
        return parent;
    }

    /* 找寻中序遍历中的 cur 前一个节点 即先驱结点 默认该节点是又左右子树的 */
    BtreeNode*  get_hearld_bst(BtreeNode* cur){
        BtreeNode* q = cur->left;
        if(q->right == nullptr)
            return q;
        BtreeNode* p = q->right;
        while(p->right)
            p = p->right;
        return p;

    }

    BtreeNode* delect_bst(const int val , BtreeNode* root){
        BtreeNode* cur = search_bst(val,root);      // 当前需要删除的节点
        BtreeNode* parent = nullptr;                // 其双亲节点
        int flag = 0;                               // 0 -- 左 ， 1 -- 右
        if(!cur)
            return root;
        
        // 情况1 ( 删除的节点为叶子节点 )
        if(cur->left == nullptr && cur->right == nullptr){
            delete cur;
            cur = nullptr;
        }

        // 情况2 ( 该节点只有左节点 或 只有右节点 )
        // 有左子树情况
        else if(cur->left != nullptr && cur->right == nullptr){ 
            parent = get_parent_bst(root, cur , flag);
            if(!flag)
                parent->left = cur->left ;
            else
                parent->right = cur->left ;
            delete cur;
            cur = nullptr;
        }
        // 有右子树
        else if (cur->left == nullptr && cur->right != nullptr) {
            parent = get_parent_bst(root, cur , flag);
            if(!flag)
                parent->left = cur->right ;
            else
                parent->right = cur->right ;
            delete cur;
            cur = nullptr;
        }
        // 情况3 (该节点即有左节点又有右节点)
        else {
            // 方法是 以要删除的节点cur 的先驱节点(按中序遍历结果来看)herald 代替cur ， 在调用
            BtreeNode* hearld = get_hearld_bst(cur);
            int data = hearld->data;
            delect_bst(hearld->data, root);
            cur->data = data;       // 形式上的删除, 将先驱节点数据赋给要删除的节点cur
        }
        return root;
    } 
    
};

int main(){
    std::vector<int> val{50,30,80,20,40,90,35,82,32,85};
    BtreeNode* root = nullptr;
    Solution sl;
    for(auto i : val){
        root = sl.insert_bst(i,root);
    }
    sl.inorder(root);
    
    int va = 3;
    std::cout<<"\ndelete "<< va << std::endl;
    sl.inorder(sl.delect_bst(va,root));
    std::cout<<std::endl;
    return 0;
}