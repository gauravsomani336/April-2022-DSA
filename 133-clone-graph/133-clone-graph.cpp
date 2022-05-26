/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node * u, unordered_set<Node*>&vis, unordered_map<Node*, Node*>&um)
    {
        vis.insert(u);
        Node* ucopy= new Node(u->val);
        
        um[u]=ucopy;
        
        for(auto x: u->neighbors)
        {
            if(vis.find(x)==vis.end())
            {
                dfs(x, vis, um);
            }
        }
    }
    
    void addEdge(unordered_map<Node*,Node*>&um)
    {
        for(auto it: um)
        {
            for(auto x: it.first->neighbors)
            {
                it.second->neighbors.push_back(um[x]);
            }
        }
    }
    
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            return NULL;
        }
        unordered_map<Node *, Node*>um;
        unordered_set<Node*>vis;
        dfs(node, vis, um);
        addEdge(um);
        return um[node];
    }
};