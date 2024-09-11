class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> connections(n);
        
        for(auto u: paths)
        {
            connections[u[0] - 1].push_back(u[1] - 1);
            connections[u[1] - 1].push_back(u[0] - 1);
        }
        
        vector<int> colors(n);
        
        for(int i = 0; i < n; i++)
        {
            vector<bool> used_neighbor(4);
            
            for(auto n: connections[i])
            {
                if(colors[n] != 0)
                    used_neighbor[colors[n] - 1] = true;
            }
            
            for(int j = 0; j < 4; j++)
            {
                if(used_neighbor[j] == false)
                {
                    colors[i] = j + 1;
                    break;
                }
            }
        }
        
        return colors;
    }
};