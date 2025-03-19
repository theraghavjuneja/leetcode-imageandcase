#### The question is a very straightforward one but difficult to code

- Initially, I tried creating just a vector of size 26 (1D vector) and in each iteration, I tried pushing numbers.
- For instance, say I have `w`, then I will do `vector[w index]++`, `vector[y index]++` for `y`, and so on.
- But I realized with this, I am unable to keep track, since I would need to:

  1. Traverse `i`th character of each vote.
  2. Check which is max.
  3. Check if any other is there which is max.
  4. If any other is there, go to 2nd, 3rd, and `n`th index.
  5. This whole process will result in a very long code.

---

### After 45 minutes, I thought of keeping a 2D grid something like:

|   | 0th | 1st | 2nd | 3rd |
|---|-----|-----|-----|-----|
| A |     |     |     |     |
| B |     |     |     |     |
| C |     |     |     |     |
| D |     |     |     |     |
| . |     |     |     |     |
| . |     |     |     |     |
| Z |     |     |     |     |

(Size: `26 * vote[0].size()`)

- Now I traversed all votes and stored everything here.
- For instance, for test case 2, this looks like:

A 0 0 0 0 
B 0 0 0 0
 ... 
W 1 0 0 1
X 1 1 0 0
Y 0 1 1 0
Z 0 0 1 1

markdown
Copy code

---

### Now let me read the question again:

- It says I will check column `0` first.
  - Max of that column will be the first element in string.
  - If no max exists, I will check column `1` and so on.

- Now this can be implemented using **a custom sort**.

---

### Implementation of Custom Sort:

- Let's say I know the 4 different elements that come in my answer (which are `W, X, Y, Z` for this test case).
- For that, I can maintain an `unordered_set` and convert it to a vector later on.
- My answer will just be a **rearrangement of `W, X, Y, Z`** in any sorted order.

#### Sorting Logic:
1. I sort using `sort(vec.begin(), vec.end())` with a **custom comparator**.
2. Say `vect[0] = W`, `vect[1] = X`.

   - This custom sort will go to **row W** of the 2D vector and **row X** of the 2D vector.
   - It will check:
     1. **Which has col 0 greater?** (`W` or `X`)
        - It finds both have the same: `1 & 1`.
     2. **Which has col 2 greater?**
        - It finds `X`, so now the custom sort knows that `X` will come before `W`.

```cpp
if (rankCount[a - 'A'][rank] != rankCount[b - 'A'][rank])
    // Higher rank should come first
    return rankCount[a - 'A'][rank] > rankCount[b - 'A'][rank]; 
    // Higher rank votes come first (this is done for each column of the 2 rows)
If both had equal votes in each rank, it would return alphabetically (a < b), which follows ASCII order.
Sorting X and Y:
Since col 0 of X > col 0 of Y, X comes before Y.
Similarly, this process continues for all elements.
Conclusion:
Based on this, my custom sort determines the placement of each element.
The sorted vector is returned.
