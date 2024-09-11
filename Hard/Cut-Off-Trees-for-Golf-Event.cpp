#define f first
#define s second

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if(forest[0][0] == 0)
            return -1;

        vector<pair<int, pair<int, int>>> coords;

        for(int i = 0; i < forest.size(); i++)
        {
            for(int j = 0; j < forest[i].size(); j++)
            {
                if(forest[i][j] > 1)
                    coords.push_back(make_pair(forest[i][j], make_pair(i, j)));
            }
        }

        sort(begin(coords), end(coords));

        int dist = get_distance(forest, make_pair(0, 0), coords[0].s);

        if(dist < 0)
            return -1;

        for(int i = 0; i < coords.size() - 1; i++)
        {
            int d = get_distance(forest, coords[i].s, coords[i + 1].s);

            if(d < 0)
                return - 1;

            dist += d;
        }

        return dist;
    }

    int get_distance(vector<vector<int>>& forest, pair<int, int> coord1, pair<int, int> coord2)
    {
        queue<pair<pair<int, int>, int>> Q;
        vector<vector<bool>> visited(forest.size());

        for(int i = 0; i < forest.size(); i++)
        {
            visited[i] = vector<bool>(forest[i].size());
        }

        Q.push(make_pair(coord1, 0));
        visited[coord1.f][coord1.s] = true;

        while(Q.size())
        {
            pair<int, int> coord = Q.front().f;
            int dist = Q.front().s;
            Q.pop();

            if(coord == coord2)
                return dist;

            if(coord.f != 0 && visited[coord.f - 1][coord.s] == false && forest[coord.f - 1][coord.s] != 0)
            {
                Q.push(make_pair(make_pair(coord.f - 1, coord.s), dist + 1));
                visited[coord.f - 1][coord.s] = true;
            }

            if(coord.s != 0 && visited[coord.f][coord.s - 1] == false && forest[coord.f][coord.s - 1] != 0)
            {
                Q.push(make_pair(make_pair(coord.f, coord.s - 1), dist + 1));
                visited[coord.f][coord.s - 1] = true;
            }

            if(coord.f != visited.size() - 1 && visited[coord.f + 1][coord.s] == false && forest[coord.f + 1][coord.s] != 0)
            {
                Q.push(make_pair(make_pair(coord.f + 1, coord.s), dist + 1));
                visited[coord.f + 1][coord.s] = true;
            }

            if(coord.s != visited[coord.f].size() - 1 && visited[coord.f][coord.s + 1] == false && forest[coord.f][coord.s + 1] != 0)
            {
                Q.push(make_pair(make_pair(coord.f, coord.s + 1), dist + 1));
                visited[coord.f][coord.s + 1] = true;
            }
        }

        return -1;
    }
};