/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root){
        if(!root){
            return NULL;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            while(k--){
                Node* t = q.front();
                q.pop();
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                if(k == 0){
                    t->next = NULL;
                }
                else{
                    t->next = q.front();
                }
            }
        }
        return root;
    }
};