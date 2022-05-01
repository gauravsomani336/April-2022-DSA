class Solution {
public:
    typedef unordered_map<string, unordered_map<string,double> >Graph;
    Graph graph;
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n=queries.size();
        vector<double>res(n, -1.0);
        
        buildgraph(equations, values);
        for(int i=0;i<queries.size();i++)
        {
            unordered_map<string, bool>visited;
            res[i]= dfs(queries[i][0], queries[i][1], visited);
        }
        
        return res;
    }
    
    void buildgraph(vector<vector<string>>& equations, vector<double>& values)
    {
        for(int i=0;i<equations.size();i++)
        {
            graph[equations[i][0]].insert({equations[i][1],values[i]});
            graph[equations[i][1]].insert({equations[i][0],(double)1/values[i]});
        }
    }
    
    double dfs(string s, string d, unordered_map<string, bool>&visited)
    {
        if(graph.find(s)==graph.end())
        {
            return -1.0;
        }
         if(s.compare(d)==0)
        {
            return 1.0;
        }
        
        if(graph[s].find(d)!=graph[s].end())
        {
            return graph[s][d];
        }
        

        
       
        
        visited[s]=true;
        
        for(auto it: graph[s])
        {
            if(visited[it.first]==false)
            {
                double ans= dfs(it.first, d, visited);
                if(ans!= -1.0)
                {
                   return (double)ans * (it.second);
                }
            }
        }
        
        return -1.0;
        
    }
};