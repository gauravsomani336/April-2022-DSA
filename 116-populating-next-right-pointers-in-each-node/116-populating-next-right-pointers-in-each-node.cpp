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
    Node* connect(Node* root) {
        
        if(root==NULL)
        {
            return NULL;
        }
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int s= q.size();
            vector<Node*>ans;
            for(int i=0;i<s;i++)
            {
                Node* cur= q.front();
                q.pop();
                ans.push_back(cur);
                
                if(cur->left!=NULL)
                {
                    q.push(cur->left);
                    
                }
                if(cur->right!=NULL)
                {
                    q.push(cur->right);
                    
                }
            }
            
            for(int i=0;i<s;i++)
            {
                if(i==s-1)
                {
                    ans[i]->next=NULL;
                }
                else
                {
                    ans[i]->next=ans[i+1];
                }
            }
        }
        return root;
    }
};