# 🛳️ 1) 1101 Capacity To Ship Packages Within D Days

## 📌 Problem Statement

You are given an array `weights` where `weights[i]` is the weight of the `i-th` package, and an integer `days` representing the number of days within which all the packages must be shipped.

Packages are shipped **in order**, and each day, you can ship a **consecutive sequence** of packages. The total weight shipped in one day **cannot exceed the ship's capacity**.

Your task is to return the **least weight capacity** of the ship that will result in all the packages being shipped within the given number of days.

---

## 💡 Explanation

This problem is solved using **Binary Search on the answer**.

### 🧭 Steps:

- **Minimum Capacity (`min`)** = maximum value in `weights`  
  ➤ Because the ship must at least carry the heaviest package.

- **Maximum Capacity (`max`)** = sum of all weights  
  ➤ Because in the worst case, all packages are shipped in 1 day.

- Perform **binary search** between `min` and `max`:

  - For each **`mid`** value (capacity guess), simulate the shipping process.
  - Count how many **days** are needed if the ship can carry `mid` weight each day.
  - If it takes **more than `days`**, the capacity is **too small** → search higher.
  - Else, try **lower capacity** to find the **minimum valid one**.

---

## ✅ Final Step

- At the end, `min` will hold the **smallest valid capacity** required to ship all packages within the given number of days.

---

## 🔢 Code for 1101. Capacity To Ship Packages Within D Days

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool canShip(vector<int>& weights, int capacity, int days) {
    int total = 0, d = 1;
    for (int w : weights) {
        if (total + w > capacity) {
            d++;
            total = 0;
        }
        total += w;
    }
    return d <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int start = 0, end = 0;
    for (int w : weights) {
        start = max(start, w);
        end += w;
    }

    while (start < end) {
        int mid = start + (end - start) / 2;
        if (canShip(weights, mid, days)) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}
```

---

# 🍌 2) 875 Koko Eating Bananas

## 📝 Problem Statement

Koko loves bananas and wants to eat all the piles within `h` hours. Each hour she can eat up to `k` bananas from a single pile. If the pile has fewer bananas than `k`, she eats them all and waits for the next hour.  
Find the **minimum integer speed `k`** such that Koko can finish all the bananas in `h` hours.

---

## 💡 Explanation

We use **binary search on `k`** (eating speed):

- **Start** = 1 (minimum speed)  
- **End** = max element in `piles` (maximum possible speed)  
- For each `mid` value, calculate total hours Koko takes using that speed.  
- If total hours > `h`, speed is too slow → search right  
- Else, try slower speed → search left  
- We stop when `start == end`, which gives the **minimum valid `k`**.

---

## ⏱️ Time Complexity

**O(N * log M)** where:  
- `N` = number of piles  
- `M` = maximum pile size (search space)

---

## ✅ Final Step

Return `start`, which is the **minimum eating speed** to finish all bananas in time.

---

## 🍌 Code for 875. Koko Eating Bananas

```cpp
#include <iostream>
#include <vector>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int start = 1, end = *max_element(piles.begin(), piles.end());

    while (start < end) {
        int mid = start + (end - start) / 2;
        int hours = 0;

        for (int p : piles) {
            hours += (p + mid - 1) / mid; // ceil(p / mid)
        }

        if (hours > h) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start;
}
```
