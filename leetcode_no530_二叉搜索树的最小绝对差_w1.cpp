/* ------------------------------------------------------------------|
给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。

 

示例：

输入：

   1
    \
     3
    /
   2

输出：
1

解释：
最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	dfs
* 
*   二叉搜索树的要求：[左-中-右]节点递增
* 
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.1 MB, 在所有 C++ 提交中击败了81.94%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* root, int& minval, int& preval) {
    if (root == NULL) {
        return;
    }
    
    dfs(root->left, minval, preval);

    if (preval == -1) {
        preval = root->val;
    }
    else {
        minval = min(minval, root->val - preval);
        preval = root->val;
    }

    dfs(root->right, minval, preval);
}

int getMinimumDifference(TreeNode* root) {
    int minval = INT_MAX;
    int preval = -1;
    dfs(root, minval, preval);
    return minval;
}