/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include<stdio.h>
#define MAX_STR_LENGTH 100000

struct TreeNode {
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
};

void helper(struct TreeNode * root, char * str, int * pos) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        (* pos) += sprintf(str + * pos, "%d", root->val);
        return;
    }

    if (root->right == NULL) {
        (* pos) += sprintf(str + * pos, "%d", root->val);
        str[(* pos) ++] = '(';
        helper(root->left, str, pos);
        str[(* pos) ++] = ')';
    } else {
        (* pos) += sprintf(str + * pos, "%d", root->val);
        str[(* pos) ++] = '(';
        helper(root->left, str, pos);
        str[(* pos) ++] = ')';
        str[(* pos) ++] = '(';
        helper(root->right, str, pos);
        str[(* pos) ++] = ')';
    }
}

char * tree2str(struct TreeNode* root) {
    char * res = (char *) malloc (sizeof (char) * MAX_STR_LENGTH);
    int pos = 0;
    helper(root, res, & pos);
    res[pos] = '\0';
    return res;
}
