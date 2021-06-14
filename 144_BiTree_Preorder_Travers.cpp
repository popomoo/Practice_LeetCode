#include <string>
#include <vector>
#include <stack>

using namespace std;
/*Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 struct Command
 {
    string s;
    TreeNode *node;
    Command( string s, TreeNode *node ) : s(s), node(node){}
 };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        stack<Command> stack;
        vector<int> res;

        if( root == nullptr )
            return res;

        stack.push( Command("go", root) );

        while( !stack.empty() )
        {
            Command command = stack.top();
            stack.pop();

            if( command.s == "print" )
                res.push_back( command.node->val );
            else
            {
                if( command.node->right )
                    stack.push( Command("go", command.node->right) );
                if( command.node->left )
                    stack.push( Command("go", command.node->left) );
                stack.push( Command("print", command.node) );
            }
        }
        return res;
    }
};