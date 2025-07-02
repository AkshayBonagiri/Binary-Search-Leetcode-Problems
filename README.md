# 🛳️ 1) 1101 Capacity To Ship Packages Within D Days
## 📌 Problem Statement

You are given an array `weights` where `weights[i]` is the weight of the `i-th` package, and an integer `days` representing the number of days within which all the packages must be shipped.

Packages are shipped **in order**, and each day, you can ship a **consecutive sequence** of packages. The total weight shipped in one day **cannot exceed the ship's capacity**.

Your task is to return the **least weight capacity** of the ship that will result in all the packages being shipped within the given number of days.
💡 Explanation
This problem is solved using Binary Search on the answer.

Steps:
Minimum Capacity (min) = maximum value in weights
➤ Because the ship must at least carry the heaviest package.

Maximum Capacity (max) = sum of all weights
➤ Because in the worst case, all packages are shipped in 1 day.

Perform binary search between min and max:

For each mid value (capacity guess), simulate the shipping process.

Count how many days are needed if the ship can carry mid weight each day.

If it takes more than days, capacity is too small → search higher.

Else, try lower capacity to find minimum valid one.

Finally, min will hold the smallest valid capacity.
