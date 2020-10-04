<h1 align="center">DSA Preparation</h1>

<div align="center">

<a href="https://leetcode.com/hejmadikaran9/"><img src="https://lc.coding.gs/v1/solved/hejmadikaran9.svg?style=for-the-badge&color=ff5983&logo=leetcode"></a>
<a href="" ><img src="https://lc.coding.gs/v1/accepted-rate/hejmadikaran9.svg?style=for-the-badge&logo=leetcode"></a>

</div>

**Problems Solved**

🟢 Easy: 52  
🟡 Medium: 44  
🔴 Hard: 4  
🔥 Review

<!-- Template
## Day 0:

**Topic:** Arrays/Hashing

#### LeetCode

1. 🟡 [Find the duplicate in an array of N+1 integers](https://leetcode.com/problems/find-the-duplicate-number/) _CRUX: Fast and Slow Pointer. Linked list cycle detection. Do while and while loop._ <div style="font-weight: bold">Time Complexity : O(N)</div> -->

## Day 1:

**Topic:** Arrays/Hashmap

#### LeetCode

1. 🟡 [Find the duplicate in an array of N+1 integers](https://leetcode.com/problems/find-the-duplicate-number/) _CRUX: Fast and Slow Pointers. Linked list cycle detection. Do while and while loop._ <div style="font-weight: bold">Time Complexity : O(N)</div>
2. 🟡 [Sort 0, 1 and 2](https://leetcode.com/problems/sort-colors/) _CRUX: Dutch National Flag Algorithm. low, mid and high pointers. Put 0s towards low, 2 towards high, only increment mid if 1_
3. 🟢 [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) _CRUX: Kadane's Algorithm_ <div style="font-weight: bold">Time Complexity : O(N)</div>
4. 🟡 🔥 [Merge Overlapping Sub intervals](https://leetcode.com/problems/merge-intervals/) _CRUX: Sort. For every element, go until next element's first is not mergeable._<div style="font-weight: bold">Time Complexity : O(N^2)</div>

#### GeeksForGeeks

5. 🟡 [Find Missing And Repeating](https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1) _CRUX: XOR range with given elements to find X^Y. Create buckets for set and unset bit. XOR both buckets to find X and Y. Traverse again to find X or Y._<div style="font-weight: bold">Time Complexity : O(5N) ~ O(N)</div>
6. 🔴 🔥 [Merge Without Extra Space](https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1) _CRUX:Take a new array and add elements from both arrays in sorted order. Optimal(O(1) space): Outer for loop calculate nextGap. Inner 3 for loops - compare elements in 1st both and 2nd array_ <div style="font-weight: bold">Time Complexity : O(logN)(gap/2) x O(N)(traverse the array)</div>

 <!-- --------------------------------------------------------------------------------------------------------------------- -->

## Day 2:

**Topic:** Arrays/Permutation

#### LeetCode

7. 🟡 🔥 [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) _CRUX: Take two dummy arrays inside the matrix to keep track of row and col which have a zero. Careful about a[0][0]_<div style="font-weight: bold">Time Complexity : O(2(MxN)) (traverse the matrix twice)</div>
8. 🟢 [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) _CRUX: define end values as 1 for every row in each iteration. write down matrix on paper and get the indices from the previous row to add._<div style="font-weight: bold">Time Complexity : O(N^2)</div>
9. 🟡 [Next Permutation](https://leetcode.com/problems/next-permutation/) _CRUX: Traverse from back. Find ind1 = i-1 such that a[i-1]<a[i]. Traverse from back again to find ind2 - first ele > a[ind1]. Swap ind1 & ind2. Sort/Reverse(prefer) all elements after ind1_<div style="font-weight: bold">Time Complexity : O(3N)</div>
10. 🟢 [Buy and Sell Stock I](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) _CRUX: only two things can happen - you find a min buy price or you find a max profit(prices[i] - buy price)_<div style="font-weight: bold">Time Complexity : O(N)</div>
11. 🟡 [Rotate Matrix](https://leetcode.com/problems/rotate-image/) _CRUX: Transpose matrix and reverse every row. Transpose - two for loops (0...n, 0...i) swap(m[i][j], m[j][i])_<div style="font-weight: bold">Time Complexity : O(2N^2)</div>

#### GeeksForGeeks

12. 🔴 🔥 [Inversion Count(Modified Merge Sort)](https://practice.geeksforgeeks.org/problems/inversion-of-array/0) _CRUX:create two indices i and j, i is the index for first half and j is an index of the second half. if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1]…a[mid]) will be greater than a[j]_<div style="font-weight: bold">Time Complexity : O(NlogN)</div>

 <!-- --------------------------------------------------------------------------------------------------------------------- -->

## Day 3:

**Topic:** Arrays/Maths

#### LeetCode

13. 🟡 [Search in a 2D matrix I](https://leetcode.com/problems/search-a-2d-matrix/) _CRUX: Consider entire matrix as sorted array and do binary search. m[mid/m][mid%m] to get the actual mid._<div style="font-weight: bold">Time Complexity : O(log(NxM))</div>
14. 🟡 🔥 [Search in a 2D matrix II](https://leetcode.com/problems/search-a-2d-matrix/) _CRUX: Place pointer at m[0][n-1]. if target < pointer move left else move down. Lesser ele will be on left, greater will be on right. if out of bounds ele doesn't exist._<div style="font-weight: bold">Time Complexity : O(M+N)</div>
15. 🟡 [Power(x^n)](https://leetcode.com/problems/powx-n/) _CRUX: if even power square x and / pow by 2. if odd power multiply ans with x and pow--. if pow <0 return 1/ans_<div style="font-weight: bold">Time Complexity : O(logN)(n/2)</div>
16. 🟢 [Majority Element (> N/2)](https://leetcode.com/problems/majority-element/) _CRUX: Moore's voting algorithm. when majority candidate gets cancelled by minority ele, new majority candidate is found ._<div style="font-weight: bold">Time Complexity : O(N)</div>
17. 🟡 🔥 [Majority Element (> N/3)](https://leetcode.com/problems/majority-element-ii/) _CRUX: extended Moore's voting algorithm. You only get the probable candidates in first traversal. Reverify by traversing again [Check this](https://leetcode.com/problems/majority-element-ii/discuss/63537/My-understanding-of-Boyer-Moore-Majority-Vote)._<div style="font-weight: bold">Time Complexity : O(N)</div>

 <!-- --------------------------------------------------------------------------------------------------------------------- -->

## Day 4:

**Topic:** Dynamic Programming/Hashmap

#### LeetCode

18. 🟡 🔥 [Grid Unique Paths](https://leetcode.com/problems/unique-paths/) _CRUX: DP would sum of upper and left cell. Optimal: m+n-2Cm-1_<div style="font-weight: bold">Time Complexity : O(N-1)(if r = n-1) or O(m-1)(if r = m-1)</div>
19. 🔴 🔥 [Reverse pairs(Modified Merge Sort)](https://leetcode.com/problems/reverse-pairs/) _CRUX: During Merge calculate count until a[i]> 2LL x a[j] or j is out of bounds._<div style="font-weight: bold">Time Complexity : O(NlogN)(merge sort) + O(N)(moving i) + O(N)(moving j)</div>
20. 🟢 [Two Sum](https://leetcode.com/problems/two-sum/) _CRUX: If complement of element exists in the hashmap, add the indices to the result else add the ele,index to the hashmap_ <div style="font-weight: bold">Time Complexity : O(N)</div>

## Day 5:

**Topic:** Hashing/Arrays

#### LeetCode

21. 🔴 🔥 [4SUM](https://leetcode.com/problems/4sum) _CRUX: BRUTE FORCE: sort -> three pointers(3 for loops) find the remainder using binary search in the elements after 3rd pointer(N^3logN) OPTIMAL: sort->two loops(0..n)(i+1..n) loop left=j+1, right = n if two sum less than req target left++ else if .. right++ else push to result_<div style="font-weight: bold">Time Complexity : O(N^3)</div>
22. 🔴 [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) _CRUX: NAIVE: sort the array and count consecutive sequences. OPTIMAL: Add all elements in a hash set. start counting from the minimum possible number. increment count if num+1 is there in the hash set. [Check this](https://www.youtube.com/watch?v=qgizvmgeyUM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=21)_<div style="font-weight: bold">Time Complexity : O(N)</div>

## Day 6:

**Topic:** Hashing/Arrays

#### LeetCode

23. 🟢 [Number of Recent Pushes](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3480/) _CRUX: Keep a window range. increment low if it falls out of the interval._<div style="font-weight: bold">Time Complexity : O(N)</div>
24. 🟡 [Longest Substring without repeating characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) _CRUX: Sliding window(i,j). Keep a count map. If next(j+1) character is repeating then decrement the count of ith character and i++ else increment the count of (j+1)th character, j++ and calculate max length_

#### GeeksForGeeks

25. 🟡 🔥 [Max subarray with sum zero](https://practice.geeksforgeeks.org/home/) _CRUX: whenever sum is zero update the count. if sum not zero and sum does not exist in the map insert it. if it exists then update the max count if the number of subarray elements is greater than the previous count._ <div style="font-weight: bold">Time Complexity : O(NlogN)</div>

## Day 7:

**Topic:** Backtracking/XOR/Hashing

#### LeetCode

26. 🟡 🔥 [Combination Sum](https://leetcode.com/problems/combination-sum/) _CRUX: Try all possible solutions using DFS [ Check this.](https://leetcode.com/problems/combination-sum-iii/discuss/427713#:~:text=The%20time%20complexity%20is%20O,is%20at%20most%202%5EN%20.)_<div style="font-weight: bold">Time Complexity : O(2^N) (Size of the solution space tree)</div>

#### GeeksForGeeks

27. 🟡 🔥 [Counting Subarray with XOR as K](https://www.geeksforgeeks.org/count-number-subarrays-given-xor/)_CRUX: X^Y = Z also implies Y = Z^X. if y = xr ^ k existed in the map which means we found freq[y] number of more sub arrays because we had found y freq number of times already and given that current prefix xor is xr there could only be a subarray with value equal to k. increment the prefix xor count_<div style="font-weight: bold">Time Complexity : O(NlogN) (logN average search time for map. for unordered_map best is O(1) worst is O(N))</div>

## Day 8:

**Topic:** Linked List/Hashing/Set

#### LeetCode

28. 🟢 [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) _CRUX: Take 3 pointers and reverse the links. NOTE: Last pointer should not go to NULL->NEXT. RECURSIVE: swap by add/subtract start and end values. Take a new pointer going till one before end pointer and call reverse with new end_<div style="font-weight: bold">Time Complexity : O(N)</div>

29. 🟢 [Middle of Linked List](https://leetcode.com/problems/middle-of-the-linked-list/) _CRUX: fast and slow pointers_<div style="font-weight: bold">Time Complexity : O(N)</div>

30. 🟢 [Merge two sorted linked lists](https://leetcode.com/problems/merge-two-sorted-lists/) _CRUX: Take one link pointer and head. Start linking from the lesser value until one of the two list pointers become NULL. Don't forget to link the remaining list in the end._<div style="font-weight: bold">Time Complexity : O(N)</div>
31. 🟡 🔥 [Count of K diff Pairs in an array](https://leetcode.com/problems/k-diff-pairs-in-an-array/) _CRUX: assume b-a = k. if nums[i]-k(a) was already seen then insert nums[i]-k into the smaller number set. if nums[i]+k(b+k) was already seen then insert nums[i] into the smaller number set. insert the current number in already seen set. the length of the set of smaller numbers is the answer._<div style="font-weight: bold">Time Complexity : O(N)</div>

## Day 9:

**Topic:** Arrays

#### LeetCode

32. 🟡 [Remove Covered Intervals](https://leetcode.com/problems/remove-covered-intervals/) _CRUX: for every interval check if it can be merged in any of the other intervals. if yes then increase count and break to avoid merging multiple times. remaining elements = total elements - mergeable elements._<div style="font-weight: bold">Time Complexity : O(N^2)</div>
<div style="font-size: 10px; font-style: italic; margin-top: 100px" >template credit: [DeepakTalwar/interview-prep-cpp](https://github.com/deepaktalwardt/interview-prep-cpp)</div>
