// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106


#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    if(nums1.size() > nums2.size())
    {
        return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size();
    int n = nums2.size();

    int left = 0;
    int right = m;

    while(left <= right)
    {
        int mid1 = (left + right) / 2;
        int mid2 = (m + n + 1) / 2 - mid1;

        int l1, r1, l2, r2;

        if(mid1 == 0)
            l1 = INT_MIN;
        else
            l1 = nums1[mid1 - 1];

        if(mid1 == m)
            r1 = INT_MAX;
        else
            r1 = nums1[mid1];

        if(mid2 == 0)
            l2 = INT_MIN;
        else
            l2 = nums2[mid2 - 1];

        if(mid2 == n)
            r2 = INT_MAX;
        else
            r2 = nums2[mid2];

        if(l1 <= r2 && l2 <= r1)
        {
            if((m + n) % 2 == 0)
            {
                return (max(l1, l2) + (double)min(r1, r2)) / 2;
            }
            else
            {
                return max(l1, l2);
            }
        }
        else if(l1 > r2)
        {
            right = mid1 - 1;
        }
        else
        {
            left = mid1 + 1;
        }
    }

    return 0.0;
}

int main()
{
    int m, n;

    cout << "Enter size of first array: ";
    cin >> m;

    vector<int> nums1(m);

    
    for(int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }

    cout << "Enter size of second array: ";
    cin >> n;

    vector<int> nums2(n);

  
    for(int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }

    double median = findMedianSortedArrays(nums1, nums2);

    cout << "Median = " << median << endl;

    return 0;
}



