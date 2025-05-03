## Ninja's Training
##### Problem Statement
#### Okay so we have a ninja who is planning 'N' days long schedule. Each day he can perform either A1,A2 or A3. He can't do the same activity on 2 conesuctive days.. Each day on doing activity, he is given with some points. Think of max points he can earn
- okay so first of all I am given a 2-D array  of N*3 points
```code
   A0   A1   A2
D0 5    10   12
D1 34   45   45
D2
D3
D4
D5
```
- so this is how it looks like

```cpp
BRUTEFORCE (RECURSION)
int f(int lastDay,int day,vector<vector<int>>&points){
    // day represents which day I am on at
    // so i will start with nth day
    if(day==0){
        int answer=-1;
        for(int i=0;i<3;i++){
            if(i!=lastDay){
                answer=max(answer,points[day][i]);
            }
        }
        return answer;
    }
    
    int answer=INT_MIN;
    for(int i=0;i<3;i++){
        if(i!=lastDay){
            int currentValue=points[day][i]+f(i,day-1,points);
            answer=max(answer,currentValue);
        }
    }
    return answer;

}
```

### okay so let me just think of recursion approach.
- See i will start with last Day Dn and there i will try taking each activity. Say i take activity 1, After acitvity 1 i will send a call to day-1 saying last act taken was 1 , so now you can take either 0 or 2.. 
- we will choose a param lastDay that will represents what was activity chosen on last day
- now for any day int currentValue=points[day][i]+f(i,day-1,points); Request for day-1  + today points
- now for day 0, base case say lastDay is 0 . i.e. last day activity done was 0. so for maximum i will return max of grid[currentDay][activity], (for 2 activites)
- and so on...
#### Now for dp,
- see in recursion what is changing? it is day(current day), activity done 
- so we will take a dp of these 2 activity day
- dp[2][1] Till day0,day1,day2 if i take activity 1 on day 2, what is maximum till here?

### this is dp code
```cpp
int f(int lastDay, int day, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if (day == 0) {
        int answer = -1;
        for (int i = 0; i < 3; i++) {
            if (i != lastDay) {
                answer = max(answer, points[day][i]);
            }
        }
        return answer;
    }

    if (dp[day][lastDay] != -1) return dp[day][lastDay];

    int answer = INT_MIN;
    for (int i = 0; i < 3; i++) {
        if (i != lastDay) {
            int currentValue = points[day][i] + f(i, day - 1, points, dp);
            answer = max(answer, currentValue);
        }
    }

    return dp[day][lastDay] = answer;
}

```

#### Now i will try the same using tabulation
```cpp
int ninjaTrainingTabulation(int n,vector<vector<int>>&points){
    vector<vector<int>>dp(n,vector<int>(4,-1)); //4 for last Day, 0,1,2,3(3=No restriction)
    for(int last=0;last<4;last++){
        // for each day , activity, check other 2 activities
        int maxPoints=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxPoints=max(maxPoints,points[0][task]);
            }
        }
        dp[0][last]=maxPoints;
    }
    for(int day=1;day<n;day++){
        // for each day find dp[day][0],dp[day][1],dp[day][2]
        // dp[day][0] will be what? max of points [day][1]+ dp[day-1][1], points [day][2]+dp[day-1][2]
        for(int last=0;last<4;last++){
            int lastDay=last;
            int maxPoints=0;
            for(int task=0;task<3;task++){
                if(task!=lastDay){
                    int currentPoints=points[day][task]+dp[day-1][task];
                    maxPoints=max(maxPoints,currentPoints);
                }
            }
            dp[day][last]=maxPoints;
        }
        
    }
    return dp[n-1][3];
}
```
#### the complexity becomes O(n*4*3) so that averages to O(n) only...