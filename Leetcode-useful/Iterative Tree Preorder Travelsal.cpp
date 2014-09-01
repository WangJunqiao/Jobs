/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (root == NULL) {
            return ret;
        }
        //�ⷨ����鵱ǰ�ڵ��ǲ���֮ǰ���ʹ�����back link�ģ�
        while (root != NULL) {
            if (root->left == NULL) {
                ret.push_back(root->val);
                root = root->right;
            } else {
                TreeNode *tmp = root->left;
                while (tmp->right != NULL && tmp->right != root) {
                    tmp = tmp->right;
                }
                if (tmp->right == NULL) {
                    //never visit root;
                    ret.push_back(root->val);
                    tmp->right = root; //back link
                    root = root->left;
                } else {
                    //already visit root
                    tmp->right = NULL;
                    root = root->right;
                }
            }
        }
        return ret;
    }
};