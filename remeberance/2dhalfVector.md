### We can declare a 2-d vector like
vector<vector<int>>vect(rows,vector<int>(cols,-1));
#### But say we dont know the size of cols, or maybe the size of cols is something dynamic. then what?
### and we would like to do like vect[row].push_back(element);
- then we declare like vector<vector<int>>vect(no of rows)