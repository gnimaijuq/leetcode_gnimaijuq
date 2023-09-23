/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
# include <stdio.h>
struct TreeNode {
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
};

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if (!numsSize) {
        return NULL;
    }
    struct TreeNode * retTN = malloc(sizeof(struct TreeNode));
    memset(retTN, 0, sizeof(struct TreeNode));
    retTN->val = nums[numsSize / 2];
    retTN->left = sortedArrayToBST(nums, numsSize / 2);
    retTN->right = sortedArrayToBST(nums + numsSize / 2 + 1, numsSize - numsSize / 2 - 1);
    return retTN;
}
