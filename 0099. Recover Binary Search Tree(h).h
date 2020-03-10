/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void recoverTree(TreeNode* root) {

        while(root->right&&traval_and_find_in_right(root->right,root)){
            if(root->left){
                while(traval_and_find_in_left(root->left,root)){

                }
            }
        }

        while(root->left&&traval_and_find_in_left(root->left,root)){
            if(root->right){
                while(traval_and_find_in_right(root->right,root)){

                }
            }
        }
        if(root->right){ 
            recoverTree(root->right);
        }
        if(root->left){
            recoverTree(root->left);
        }
    }
    bool traval_and_find_in_right(TreeNode *current,TreeNode *root){
        bool re=false;
        if(current->val<root->val){
            int temp=current->val;
            current->val=root->val;
            root->val=temp;
            re=true;
        }
        if(current->left){
            re=re||traval_and_find_in_right(current->left,root);
        }
        if(current->right){
            re=re||traval_and_find_in_right(current->right,root);
        }
        return re;
    }
    bool traval_and_find_in_left(TreeNode *current,TreeNode *root){
        bool re=false;
        if(current->val>root->val){
            int temp=current->val;
            current->val=root->val;
            root->val=temp;
            re=true;
        }
        if(current->left){
            re=re||traval_and_find_in_left(current->left,root);
        }
        if(current->right){
            re=re||traval_and_find_in_left(current->right,root);
        }
        return re;
    }

};