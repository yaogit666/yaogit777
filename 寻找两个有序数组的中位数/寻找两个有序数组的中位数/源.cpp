class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		for (int i = 0; i < nums2.size(); i++)
		{
			nums1.push_back(nums2[i]);
		}
		sort(nums1.begin(), nums1.end());
		int lenth = nums1.size();
		double n = 0;
		if (lenth % 2 == 0)
		{
			n = (nums1[lenth / 2 - 1] + nums1[lenth / 2]) / 2.0;
		}
		else
		{
			n = nums1[lenth / 2];
		}
		return n;
	}
};