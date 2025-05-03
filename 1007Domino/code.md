```cpp
class Solution {
public:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int topRotations = 0, bottomRotations = 0;
        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return -1; //i cant make as both of them arent equal
            }
            if (tops[i] != target) topRotations++;
            if (bottoms[i] != target) bottomRotations++;
        }
        return min(topRotations, bottomRotations);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = check(tops[0], tops, bottoms);
        if (result != -1 || tops[0] == bottoms[0]) {
            return result;
        } else { //i should also check whether i can get answer from bottom
            return check(bottoms[0], tops, bottoms);
        }
    }
};

```
- see either top will be the answer or i will get from bottom or it will be -1
- rotation= if element is not equal to wat it was already
- see why this works? Example initially =2,5 then 3,4 (Now these are all 4 diff elements. So not possible as on rotating any of these neither the top is same nor the bottom is same.) so as a reference we take tops[0], bottoms[0] etc.
