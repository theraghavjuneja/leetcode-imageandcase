In C++, the **`lower_bound`** and **`upper_bound`** functions are part of the `<algorithm>` header and are used with **sorted containers**, such as `vector`, to perform **binary search operations** efficiently.

### 🔑 Definitions:
- `lower_bound`: Returns an iterator pointing to the **first element** in the range `[first, last)` which **is not less than (i.e. ≥)** the given value.
- `upper_bound`: Returns an iterator pointing to the **first element** in the range `[first, last)` which **is greater than (i.e. >)** the given value.

---

### ✅ Example with `vector`:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {10, 20, 20, 20, 30, 40, 50};
    
    // The value to search for
    int val = 20;

    // lower_bound
    auto low = std::lower_bound(vec.begin(), vec.end(), val);
    // upper_bound
    auto up = std::upper_bound(vec.begin(), vec.end(), val);
// for vector to get index just subtract by vec.begin()
    std::cout << "lower_bound of " << val << " is at index: " << (low - vec.begin()) << "\n";
    std::cout << "upper_bound of " << val << " is at index: " << (up - vec.begin()) << "\n";

    return 0;
}
```

### 🧠 Output:
```
lower_bound of 20 is at index: 1
upper_bound of 20 is at index: 4
```

---

### ✅ Example with `set`:
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> s = {10, 20, 30, 40, 50};

    int val = 30;

    auto low = s.lower_bound(val); // ≥ 30
    auto up = s.upper_bound(val);  // > 30
// for set index doesnt matter check if it is not equal to s.end()
// if it is not just print *low() , (here to_string(*low()) done due to ternary operator, i will be printing either this or not found which is string)
// as long as only val i sneeded *low() is sufficient
    std::cout << "lower_bound of " << val << " is: " << (low != s.end() ? std::to_string(*low) : "not found") << "\n";
    std::cout << "upper_bound of " << val << " is: " << (up != s.end() ? std::to_string(*up) : "not found") << "\n";

    return 0;
}
```

### 🧠 Output:
```
lower_bound of 30 is: 30
upper_bound of 30 is: 40
```

---

Let me know if you want a version where we manually implement these without using STL too.