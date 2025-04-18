#### What were heaps?
- Max Heap (max at top). This is the by default Heap which is declared as priority_queue<int>maxHeap
- To declare any custom heap(even minHeap is custom) we do
You're telling priority_queue:

What type you want (int)

Where to store the elements (std::vector<int>)

### 🧠 Think of it this way:
You're telling `priority_queue`:
- **What type** you want (`int`)
- **Where to store the elements** (`std::vector<int>`)
- **How to compare them** (`std::greater<int>` makes smallest at top)

---

### ✅ Correct Syntax:
```cpp
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
```

### 📘 Syntax Breakdown:

```cpp
std::priority_queue<
    T,                      // Type of elements (e.g., int)
    std::vector<T>,         // Container to store elements
    std::greater<T>         // Comparator (min-heap in this case)
> name;
```

---

### 🧠 Think of it this way:
You're telling `priority_queue`:
- **What type** you want (`int`)
- **Where to store the elements** (`std::vector<int>`)
- **How to compare them** (`std::greater<int>` makes smallest at top)

---

### TL;DR:
You **must provide all three** if you're changing the default comparator. So no, you can't skip `vector<int>` unless you're okay with the **default max-heap**.

Let me know if you want to do this with a `struct` or `pair`, too — that gets even more fun �