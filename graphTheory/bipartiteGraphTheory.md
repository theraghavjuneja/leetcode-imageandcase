# Bipartite Graph

A **bipartite graph** is a special type of graph whose vertices can be divided into two disjoint sets \( U \) and \( V \) such that every edge connects a vertex in \( U \) to a vertex in \( V \). No two vertices within the same set are adjacent.

## Properties of Bipartite Graphs
- The graph can be colored using two colors without any two adjacent vertices sharing the same color.
- A graph is bipartite if and only if it does not contain an **odd-length cycle**.
- It is widely used in **matching problems**, such as job assignment and network flow algorithms.

## Example of a Bipartite Graph
Consider the following bipartite graph:

```
    A       B
   / \     / \
  C   D   E   F
```
Here, the vertices can be divided into two sets:
- Set U = {A, B}
- Set V = {C, D, E, F}

## Checking if a Graph is Bipartite (C++ Code)
We can use **Breadth-First Search (BFS)** or **Depth-First Search (DFS)** to check if a graph is bipartite. Below is an implementation using BFS:

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph, int n) {
    vector<int> color(n, -1); // -1 means uncolored
    
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) { // If not yet colored
            queue<int> q;
            q.push(i);
            color[i] = 0; // Start coloring with 0
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) { // If uncolored
                        color[neighbor] = 1 - color[node]; // Assign opposite color
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false; // Conflict found
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> graph = {
        {1, 3}, {0, 2}, {1, 3}, {0, 2} // Bipartite graph example
    };
    int n = graph.size();
    
    if (isBipartite(graph, n))
        cout << "The graph is bipartite." << endl;
    else
        cout << "The graph is not bipartite." << endl;
    
    return 0;
}
```

## Applications of Bipartite Graphs
- **Matching Problems**: Used in job assignment, stable marriage problems.
- **Social Networks**: Representing relations between two types of entities (e.g., users and groups).
- **Scheduling Problems**: Assigning tasks to workers efficiently.

Bipartite graphs are fundamental in graph theory and have many real-world applications in computer science and optimization problems.


# bipartite m we color graph using 2 colors such that no 2 adj nodes have same color

### LINEAR GRAPHS Are always bipartite
### Even Length cycles are always bipartite(graph with even cycle length bipartite)
