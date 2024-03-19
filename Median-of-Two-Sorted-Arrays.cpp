class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { // find median of two sorted arrays
        int totalSize = nums1.size() + nums2.size();

        return (totalSize % 2 == 0) ? 
        (findNthValue(nums1, nums2, totalSize / 2) + findNthValue(nums1, nums2, totalSize / 2 + 1)) / 2 :
        findNthValue(nums1, nums2, totalSize / 2 + 1);
    }

    double findNthValue(vector<int>& nums1, vector<int>& nums2, int N)      // find the N'th value of two sorted arrays
    {
        int n = nums1.size(), m = nums2.size();

        if(n > m)                                                           // swap the arrays so that nums1 is smaller
        {
            nums1.swap(nums2);
            n = nums1.size(), m = nums2.size();
        }     

        if(n == 0)
            return nums2[N - 1];                                                        

        if(n >= N && nums1[N - 1] <= nums2[0])
            return nums1[N - 1];
        if(m >= N && nums2[N - 1] <= nums1[0])
            return nums2[N - 1];

        int beg = 0, nums1idx, nums2idx, fin = min(n - 1, N); 

        nums1idx = (beg + fin) / 2;
        nums2idx = N - nums1idx - 2;

        while(beg < fin)                                                   // binary search for the N'th value
        {
            if(nums1idx != n - 1 && nums1[nums1idx + 1] < nums2[nums2idx])
                beg = nums1idx + 1;
            else
                fin = nums1idx;
            
            nums1idx = (beg + fin) / 2;
            nums2idx = N - nums1idx - 2;
        }

        return max(nums1[nums1idx], nums2[nums2idx]);
    }
};