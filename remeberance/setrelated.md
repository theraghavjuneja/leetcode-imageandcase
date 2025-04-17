#### SET RELATED
- Ordered_set does not support .begin() &.end() etc. like making a set from vector is not supported by ordered_set
- But a normal set support it
- A set and ordered_set both keeps element in ascending order by default
- for descenging order again set<int,greater<int>>s;( a custom operator)
- Both have the same complexities
- ordered_set also adds two bonus operations in O(logn)
- find_by_order(k) Gives the iterator to kth smallest element
- order_of_key(x) Count of elements strictly less than x
```cpp
ordered_set<int> oset = {10, 20, 30, 40};

std::cout << *oset.find_by_order(2);     // Output: 30
std::cout << oset.order_of_key(35);      // Output: 3 (10,20,30 < 35)
```
