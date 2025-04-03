## 802 Find Eventual Safe States
- In this question, we have been given an adjList already where adj[i] is a vector representing which all nodes is i connected to
## Given concept in question
- A node is terminal-> if there are no outgoing edges from node
- A node is safe if each and every path possible leads to a terminal node or another safe node.(any path shouldnt involve in cycle)

## Example
- let me consider the graph given in the question
# Graph Representation

Here's the graph described by the adjacency list: `[[1,2],[2,3],[5],[0],[5],[],[]]`

## Adjacency List Description:

* **Node 0** points to: 1, 2
* **Node 1** points to: 2, 3
* **Node 2** points to: 5
* **Node 3** points to: 0
* **Node 4** points to: 5
* **Node 5** has no outgoing edges.
* **Node 6** has no outgoing edges.

## Visual Representation 
#### Refer to attahced image
- So here, the terminal nodes are 5 & 6
- Now safe nodes will be 5,6 and some other nodes whose every path leads to terminal node
**1.** Start from 0 0->1->3->0 (one path that doesnt lead to 5/6). So 2 is not safe
**2.** Start from 1 1-3->0->1 (doesnt lead to 5/6)
**3.** Start from 2->5 (Every path leads to terminal)
**4.** 3->0->1->3 (doesnt lead to 5/6)
**4** 4->5 (every path to terminal), 5,6 

## So safe nodes=2,4,5,6
- Now what is one thing we observed, out of given n nodes whose at-least one path leads to a cycle, they wont be a part of answer
- so this question is like Detecting cycle in undirected graph
- every node part of cycle wont contribute to answer
- Rest nodes will do
```cpp
class Solution {
public:
    bool dfs(int node,
    vector<vector<int>>&graph,
    vector<bool>&visited,
    vector<bool>&dfsVisited
    ){
        // step 1 mark current node as visite
        visited[node]=true;
        // step 2 mark dfs visited as true
        dfsVisited[node]=true;
        for(int neighbor:graph[node]){
            // Step 3 process the neighbors
            if(!visited[neighbor]){
                if(dfs(neighbor,graph,visited,dfsVisited)){
                    return true;
                }
            }
            else if(dfsVisited[neighbor]){
                // meaning its visited as well as dfs visited
                return true;
            }
        }
        // MISTAKE: only mark dfsvisited as false, let the visited stay true if u change visited back to true that means a tle infinte loop
        dfsVisited[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool>visited(graph.size(),false);
        vector<bool>dfsVisited(graph.size(),false); // we are interested here
        for(int i=0;i<graph.size();i++){
            if(!visited[i]){
                // so I should do dfs , if they arent visited
                bool a=dfs(i,graph,visited,dfsVisited);
            }
        }
        // now in dfsVisited all nodes which are still false in dfsVisited-> not a part of cycle (thats out answer)
        vector<int> ans; // To store indices where dfsVisited is true

        for (int i = 0; i < dfsVisited.size(); i++) {
            // cout<<"the value at"<<i<<"is"<<dfsVisited[i]<<endl;
            if (!dfsVisited[i]) {
                ans.push_back(i);
            }
        }
        return ans;

    }
};
```