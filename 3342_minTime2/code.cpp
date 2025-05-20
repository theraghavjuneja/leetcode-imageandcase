class Solution {
public:
    int bfs(int startX, int startY, int endX, int endY, vector<vector<bool>>& visited, vector<vector<int>>& moveTime) {
        using T = pair<int, pair<int, pair<int,int>>>;
        priority_queue<T, vector<T>, greater<T>> minHeap;
        minHeap.push({0, {1,{startX, startY}}}); //2 means next room will be 1 second time
        visited[startX][startY] = true;

        vector<vector<int>> directions = {
            {0, 1}, {1, 0},{-1,0},{0,-1}
        };

        while (!minHeap.empty()) {
            auto element=minHeap.top();
            minHeap.pop();
            int x = element.second.second.first;
            int y = element.second.second.second;
            int time=element.first;
            int timeForAdjacent=element.second.first;
            int newTime=1; //time for next room
            if(timeForAdjacent==1){
                newTime=2;
            }
            if (x == endX && y == endY) {
                return time;
            }

            for (const auto& d : directions) {
                int newX = x + d[0];
                int newY = y + d[1];

                if ((newX >= 0 && newX <= endX) && (newY >= 0 && newY <= endY) && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    if (time >= moveTime[newX][newY]) {
                        minHeap.push({time+timeForAdjacent,{newTime,{newX,newY}}});
                    } else {
                        minHeap.push({moveTime[newX][newY] + timeForAdjacent, {newTime,{newX, newY}}});
                    }
                }
            }
        }

        return -1;
    }
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int endX = moveTime.size() - 1;
        int endY = moveTime[0].size() - 1;
        vector<vector<bool>> visited(endX + 1, vector<bool>(endY + 1, false));
        return bfs(0, 0, endX, endY, visited, moveTime);
    }
};