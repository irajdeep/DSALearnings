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
private:
    struct returnVal{
      int val;
      int pos;
      returnVal(int v ,int p) : val(v) , pos(p) {}
      returnVal() {}
    };

    returnVal getMax(vector<int>& nums , int l ,int r){
        returnVal v;
        v.val = INT_MIN;
        for(int i = l ; i <= r ; i++){
            if(nums[i] > v.val){
                v.val = nums[i];
                v.pos = i;
            }
        }
        return v;
    }

    TreeNode* util(vector<int>&nums , int l , int r){
        if( l == r){
            TreeNode *tmp = new TreeNode(nums[l]);
            return tmp;
        }
        if( l > r)  return NULL;

        returnVal x = getMax(nums , l , r);
        TreeNode *root = new TreeNode(x.val);
        int pos = x.pos;

        root->left = util(nums, l , pos - 1);
        root->right = util(nums,  pos + 1 , r);

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums){
        TreeNode *root = util(nums , 0 , (int)nums.size() - 1);
        return root;
    }
};