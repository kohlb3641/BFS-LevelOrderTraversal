#include <queue>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
*/

using namespace std;

class Solution {

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<vector<int>> levelSet;
        std::queue<TreeNode*> q;
        if (root == nullptr) return levelSet;
        q.push(root);

        while (!q.empty()) {
            // store the number of nodes at this level
            int numNodes = q.size();
            std::vector<int> curLevel;

            for (int i = 0; i < numNodes; i++) {
                TreeNode* curNode = q.front();
                curLevel.push_back(curNode->val);
                
                if (curNode->left != nullptr) {
                    q.push(curNode->left);
                }
                if (curNode->right != nullptr) {
                    q.push(curNode->right);
                }
                
                // remove from queue and process next element
                q.pop();
            }
            
            levelSet.push_back(curLevel);
        }
        return levelSet;
    }
};
