class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;

        for(int i = 1; i < points.size(); i++)
        {
            int dist1 = points[i-1][0] - points[i][0];
            int dist2 = points[i-1][1] - points[i][1];

            if(dist1 < 0)
                dist1 *= -1;
            if(dist2 < 0)
                dist2 *= -1;

            time += max(dist1, dist2);
        }

        return time;
    }
};