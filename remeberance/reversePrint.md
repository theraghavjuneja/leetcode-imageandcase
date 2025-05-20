### For printing the 2-d grid in the reverse order we can 
```cpp
int rows,cols // assuming they just have been taken from soemwhere
for (int col = 0; col < cols; col++) {
    for (int row = 0; row < rows; row++) {
        cout << grid[row][col] << " ";
    }
    cout << endl;
}

```