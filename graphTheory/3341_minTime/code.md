# Dungeon Pathfinding: A Time-Travel Maze Solver

## The Problem in Plain English

Imagine you're in a dungeon with rooms arranged in a grid. Each room has a specific time when it becomes available to enter. You start at the top-left room (0,0) at time zero and want to reach the bottom-right room as quickly as possible.

The catch? You can only move to adjacent rooms (up, down, left, right), and each move takes exactly 1 second. But here's the tricky part - you can only enter a room when its "moveTime" has been reached. If you arrive too early, you need to wait outside until that time.

## Why I Chose a Priority Queue (and not regular BFS or DP)

My first thought was "this sounds like a shortest path problem," which typically screams BFS (Breadth-First Search). But there's a twist here:

### Regular BFS wouldn't work because:
- A standard BFS with a regular queue assumes all moves have equal cost (1 second)
- But in this problem, the actual time to reach a room varies due to the waiting time

### Dynamic Programming wouldn't be straightforward because:
- DP works best when we can build solutions from smaller subproblems
- The time-based constraints create dependencies that aren't easily expressed in a DP state
- The optimal path isn't necessarily the one with the fewest steps

### Why Priority Queue (Dijkstra's algorithm) is perfect:
- It lets us process rooms in order of "earliest arrival time" rather than "fewest steps"
- When multiple paths to a room exist, we'll find the one with the earliest arrival time first
- We can elegantly handle the waiting time by adjusting the cost before adding to the queue

## How My Solution Works

1. **Setting up the maze solver:**
   - I use a priority queue that sorts by arrival time (lowest first)
   - The queue holds: {time, {x-coordinate, y-coordinate}}
   - I track visited cells to avoid processing the same room twice

2. **Exploring the dungeon:**
   - Start at position (0,0) with time=0
   - For each room, explore all four adjacent rooms (up, down, left, right)
   - Check if the next room is valid (within bounds and not visited)

3. **Handling the time constraints:**
   - If I arrive at a room before its moveTime, I have to wait:
     ```cpp
     if (time >= moveTime[newX][newY]) {
         minHeap.push({time + 1, {newX, newY}});  // Can enter immediately, just add 1s for movement
     } else {
         minHeap.push({moveTime[newX][newY] + 1, {newX, newY}});  // Need to wait until moveTime, then add 1s
     }
     ```

4. **Finding the fastest path:**
   - Since the priority queue always gives us the cell with the minimum time,
   - The first time we reach the end cell (bottom-right) is guaranteed to be the fastest

## Why This Works Better Than Alternatives

A regular queue would process rooms in order of "steps from the start," which ignores the fact that a path with more steps but less waiting might be faster overall.

DP would struggle with the time dependency without getting very complex. 

The priority queue elegantly handles the "earliest arrival time" ordering, making it easy to account for both movement time AND waiting time.

## Real-World Analogy

It's like planning a trip across a city where certain roads only open at specific times. The shortest path isn't necessarily the fastest - you might take a longer route to avoid waiting for a road to open. The priority queue helps us find the path that gets us to our destination earliest, not the path with the fewest turns.

## Time and Space Complexity

- **Time Complexity:** O(nm log(nm)) where n and m are the dimensions of the grid. Each cell can be pushed onto the priority queue at most once, and each push/pop operation costs O(log(nm)).
  
- **Space Complexity:** O(nm) for the visited array and the priority queue.

This approach is efficient and directly addresses the unique constraints of this dungeon problem - making it a perfect match for a priority queue solution.

```cpp
class Solution {
public:
    int bfs(int startX, int startY, int endX, int endY, vector<vector<bool>>& visited, vector<vector<int>>& moveTime) {
        using T = pair<int, pair<int, int>>;
        priority_queue<T, vector<T>, greater<T>> minHeap;
        minHeap.push({0, {startX, startY}});
        visited[startX][startY] = true;

        vector<vector<int>> directions = {
            {0, 1}, {1, 0},{-1,0},{0,-1}
        };

        while (!minHeap.empty()) {
            auto [time, coord] = minHeap.top();
            minHeap.pop();
            int x = coord.first;
            int y = coord.second;

            if (x == endX && y == endY) {
                return time;
            }

            for (const auto& d : directions) {
                int newX = x + d[0];
                int newY = y + d[1];

                if ((newX >= 0 && newX <= endX) && (newY >= 0 && newY <= endY) && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    if (time >= moveTime[newX][newY]) {
                        minHeap.push({time + 1, {newX, newY}});
                    } else {
                        minHeap.push({moveTime[newX][newY] + 1, {newX, newY}});
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

```