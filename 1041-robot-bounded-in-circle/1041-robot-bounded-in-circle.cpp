class Solution {
public:
    bool isRobotBounded(string instructions) {
        char cur_dir='N';
        int x=0, y=0;
        
        for(int i=0;i<instructions.size();i++)
        {
            if(instructions[i]=='G')
            {
                y+= cur_dir=='N'?1:0;
                y+= cur_dir=='S'?-1:0;
                x+= cur_dir=='E'?1:0;
                x+= cur_dir=='W'?-1:0;
            }
            else
            {
                char incoming=instructions[i];
                
                if(cur_dir=='N')
                {
                    cur_dir= incoming=='L'?'W':'E';
                }
                else if(cur_dir=='W')
                {
                    cur_dir= incoming=='L'?'S':'N';
                }
                else if(cur_dir=='S')
                {
                    cur_dir= incoming=='L'?'E':'W';
                }
                else if(cur_dir=='E')
                {
                    cur_dir= incoming=='L'?'N':'S';
                }
            }
        }
        
        if(x==0 && y==0 || cur_dir!='N')
        {
            return true;
        }
        return false;
    }
};