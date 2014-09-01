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
    vector<int> inorderTraversal(TreeNode *root) {
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
                    //never visit root
                    tmp->right = root;
                    root = root->left;
                } else {
                    ret.push_back(root->val);
                    tmp = root->left;
                    while (tmp->right != root) {
                        tmp = tmp->right;
                    }
                    tmp->right = NULL;
                    root = root->right;
                }
            }
        }
        return ret;
    }
};