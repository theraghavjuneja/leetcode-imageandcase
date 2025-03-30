# LC 733 Flood FILL
### Given: image (2-d matrix) where
- image[i][j]=pixel value of imae
- given sr,sc,color 3 integers
### **What to perform**: Flood fill from image[sr][sc]

### How to do flood fill
- image[sr][sc]-> value change to **color(given input)**
- Do the same for each adjacent pixel which has same color with this pixel
- Stops when no more adjacent

### Intitution:
- okay so I need to go to image[sr][sc] process neighbors and so on. This gives me an idea of a queue. Say , there is a tree (or a graph) a queue essentially will push neighbors then pop the current guy. This process continues till queue gets empty
- I can't get any DP intituion here. Dp is generally when I have many paths (generally 2 at a time). I need to go on each and find something like minCost, minDistance. Stuff like that. But here at the current guy, I need to process all neighbors parallerly . So i dont think I can form a recursive relationship. That gives me idea of a queue

### Example
sr=1,sc=1,color=2
```code
1 1 1               1  1  1
1 1 0   changes to  1  2  0
1 0 1               1  0  1
```
- original color was 1 at img[1][1] which got changed to 2
## NOW i need to check neighbors of 2 which have value 1
```code
1 2 1                             2  2  2
2 2 0   Finally, after some steps 2  2  0
1 0 1                             2  0  1
```
SO , i need to keep track of initial color , which I had that's 1. I need to see neighbors of color having value 1 (which is initial coloe)


```cpp
class Solution {
public:
    void bfs(
        vector<vector<int>>&image,
        int initialColor,
        int colorToChange,
        queue<pair<int,int>>&q,
        int rows,
        int cols
    ){
        vector<vector<int>>directions={
            {1,0},
            {0,1},
            {-1,0},
            {0,-1}
        };
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(int i=0;i<directions.size();i++){
                int newX=x+directions[i][0];
                int newY=y+directions[i][1];
                if(newX>=0 && newX<rows 
                && newY>=0 && newY<cols){
                    // if it is in range
                    // i need to check whether the value equals to 1
                    if(image[newX][newY]==initialColor){
                        q.push(make_pair(newX,newY));
                        image[newX][newY]=colorToChange;
                    }
                }
            }


        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        int initialColor=image[sr][sc];
        if(initialColor==color) return image;
        q.push(make_pair(sr,sc));
        image[sr][sc]=color;
        bfs(image,initialColor,color,q,image.size(),image[0].size());
        return image;


    }
};
```