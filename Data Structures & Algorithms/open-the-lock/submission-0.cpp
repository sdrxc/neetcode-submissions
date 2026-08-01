class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        // removes duplication and sort the deadends 
        unordered_set<string> dead(deadends.begin(), deadends.end());

        if(dead.count("0000"))
        return -1;

        queue<string> q;
        unordered_set<string> visited;

        q.push("0000");
        visited.insert("0000");

        int moves = 0;
        
        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                string curr= q.front();
                q.pop();

                if(curr==target)
                return moves;

                for(int i=0;i<4;i++)
                {
                    string next= curr;

                    // Rotate forward 
                    next[i] = (curr[i]-'0'+1) % 10 + '0';
                    
                    // if the number is not present in deadends and not visited 
                    if(!dead.count(next) && !visited.count(next))
                    {   
                        visited.insert(next);
                        q.push(next);
                    }

                    next = curr;

                    // rotate backward 
                    next[i] = (curr[i] - '0' + 9) % 10 + '0';
                    
                    if(!dead.count(next) && !visited.count(next))
                    {   
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            moves++;
        }

        return -1;

    }
};