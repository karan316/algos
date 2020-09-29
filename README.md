<h1 align="center">DSA Preparation</h1>

<div align="center">

<a href="https://leetcode.com/hejmadikaran9/"><img src="https://lc.coding.gs/v1/solved/hejmadikaran9.svg?style=for-the-badge&color=ff5983&logo=leetcode"></a>
<a href="" ><img src="https://lc.coding.gs/v1/accepted-rate/hejmadikaran9.svg?style=for-the-badge&logo=leetcode"></a>

</div>

**Difficulty Levels solved :**

🟢 Easy: 50  
 🟡 Medium: 38  
 🔴 Hard: 2  
 🟣 Very Hard: 0  
 ✨ Review

<!-- ## Day 0:

**Topic:** Arrays/Hashing

#### LeetCode

1. 🟡 [Find the duplicate in an array of N+1 integers](https://leetcode.com/problems/find-the-duplicate-number/) _CRUX: Fast and Slow Pointer. Linked list cycle detection. Do while and while loop._ -->

## Day 0:

**Topic:** Arrays/Hashing

#### LeetCode

1. 🟡 [Find the duplicate in an array of N+1 integers](https://leetcode.com/problems/find-the-duplicate-number/) _CRUX: Fast and Slow Pointer. Linked list cycle detection. Do while and while loop._
2. 🟡 [Sort 0, 1 and 2](https://leetcode.com/problems/sort-colors/) _CRUX: Dutch National Flag Algorithm. low, mid and high pointers. Put 0s towards low, 2 towards high, only increment mid if 1_
3. 🟢 [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) _CRUX: Kadane's Algorithm_
4. 🟡 ✨ [Merge Overlapping Sub intervals](https://leetcode.com/problems/merge-intervals/) _CRUX: Sort. For every element, go until next element's first is not mergeable._

#### GeeksForGeeks

5. 🟡 [Find Missing And Repeating](https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1) _CRUX: XOR range with given elements to find X^Y. Create buckets for set and unset bit. XOR both buckets to find X and Y. Traverse again to find X or Y._
6. 🔴 ✨ [Merge Without Extra Space](https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1) _CRUX: Outer for loop calculate nextGap. Inner 3 for loops - compare elements in 1st both and 2nd array_

 <!-- --------------------------------------------------------------------------------------------------------------------- -->

## Day 1:

**Topic:** Arrays/Permutation

#### LeetCode

7. 🟡 ✨ [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) _CRUX: Take two dummy arrays inside the matrix to keep track of row and col which have a zero. Careful about a[0][0]_
8. 🟢 [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) _CRUX: define end values as 1 for every row in each iteration. write down matrix on paper and get the indices from the previous row to add._
9. 🟡 [Next Permutation](https://leetcode.com/problems/next-permutation/) _CRUX: Traverse from back. Find ind1 = i-1 such that a[i-1]<a[i]. Traverse from back again to find ind2 - first ele > a[ind1]. Swap ind1 & ind2. Sort all elements after ind1_
10. 🟢 [Buy and Sell Stock I](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) _CRUX: only two things can happen - you find a min buy price or you find a max profit(prices[i] - buy price)_
11. 🟡 [Rotate Matrix](https://leetcode.com/problems/rotate-image/) _CRUX: Transpose matrix and reverse every row. Transpose - two for loops (0...n, 0...i) swap(m[i][j], m[j][i])_

#### GeeksForGeeks

12. 🔴 ✨ [Inversion Count(Modified Merge Sort)](https://practice.geeksforgeeks.org/problems/inversion-of-array/0) _CRUX:create two indices i and j, i is the index for first half and j is an index of the second half. if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1]…a[mid]) will be greater than a[j]_

## Day 2:

**Topic:** Arrays/Hashing

#### LeetCode

13. 🟡 [Search in a 2D matrix](https://leetcode.com/problems/find-the-duplicate-number/) _CRUX: Fast and Slow Pointer. Linked list cycle detection. Do while and while loop._

<div style="font-size: 10px; font-style: italic; margin-top: 30px" >template credit: [DeepakTalwar/interview-prep-cpp](https://github.com/deepaktalwardt/interview-prep-cpp)</div>
