#### Declaration of 1d vector
vector<int>vect(3) - Declares a 1d Vector size 3 each element 0 (default for int)
vector<int>vect (3,-1) : Now here each element is intiialized to -1
### now for 2d
vector<vector<int>>vect(rows,vector<int>(cols));
<!-- type(rows,vector <int>cols) -->
<!-- first row-> row how much -->
<!-- cols tell vecotr of how much size in each row -->

#### For example to declare of size 3*4
vector<vector<int>>vec2D(3,vector<int>(4));

#### Now to initialize
vector<vector<int>>vec2D(3,vector<int>(4,-1));


#### now based on another vector
vector<vector<int>>dp(3,vector<int>(vec.size(),-1));