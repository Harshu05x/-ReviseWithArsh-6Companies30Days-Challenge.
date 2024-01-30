# Find in Mountain Array

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/find-in-mountain-array/description/)

You may recall that an array arr is a mountain array if and only if:
- arr.length >= 3
- There exists some i with 0 < i < arr.length - 1 such that:
    - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given a mountain array mountainArr, return the minimum index such that mountainArr.
get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:
- MountainArray.get(k) returns the element of the array at index k (0-indexed).
- MountainArray.length() returns the length of the array.

Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

### Sample Input
```
array = [1,2,3,4,5,3,1], target = 3
```

### Sample Output
```
2

Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
```

### Solution
```cpp
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int n;
    int findInMountainArray(int target, MountainArray& m) {
        n = m.length();
        int centre = find1(n, m);
        int l = find2(0, centre, m, target);
        int r = find3(centre + 1, n - 1, m, target);
        if (l != -1)
            return l;
        return r;
    }
    int find1(int n, MountainArray& m) {
        int low = 1;
        int high = n - 2;
        while (high >= low) {
            int mid = (high + low) / 2;
            int l, r;
            if (mid != 0)
                l = m.get(mid - 1);
            if (mid != n - 1)
                r = m.get(mid + 1);
            int k = m.get(mid);
            if (k > l && k > r)
                return mid;
            else if (k > l)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return m.get(high) > m.get(low) ? high : low;
    }
    int find2(int low, int high, MountainArray& m, int key) {
        int ans = -1;
        while (high >= low) {
            int mid = (high + low) / 2;
            int k = m.get(mid);
            if (k == key)
                ans = mid;
            if (k >= key) {

                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
    int find3(int low, int high, MountainArray& m, int key) {
        int ans = -1;
        while (high >= low) {
            int mid = (high + low) / 2;
            int k = m.get(mid);
            if (k == key)
                ans = mid;
            if (k > key) {

                low = mid + 1;
            } else
                high = mid - 1;
        }
        return ans;
    }
};
```
