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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (root == NULL) {
            return ret;
        }
        //�ⷨ�����һ���ڵ㡣��鵱ǰ�ڵ��ǲ���֮ǰ���ʹ�����back link�ģ�
        TreeNode node(0);
        node.left = root;
        root = &node;
        while (root != NULL) {
            if (root->left == NULL) {
                root = root->right;
            } else {
                TreeNode *tmp = root->left;
                while (tmp->right != NULL && tmp->right != root) {
                    tmp = tmp->right;
                }
                if (tmp->right == NULL) {
                    tmp->right = root; //link back
                    root = root->left;
                } else {
                    vector<int> v;
                    tmp = root->left;
                    while (tmp->right != root) {
                        v.push_back(tmp->val);
                        tmp = tmp->right;
                    }
                    v.push_back(tmp->val);
                    for (int i = v.size() - 1; i >= 0; i --) {
                        ret.push_back(v[i]);
                    }
                    tmp->right = NULL; //recovery
                    root = root->right;
                }
            }
        }
        return ret;
    }
};
