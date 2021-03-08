//#include<stdio.h>
//int* addToArrayForm(int* A, int ASize, int K, int* returnSize) 
//{
//    int* res = malloc(sizeof(int) * fmax(10, ASize + 1));
//    *returnSize = 0;
//    for (int i = ASize - 1; i >= 0; --i) 
//    {
//        int sum = A[i] + K % 10; //从最低位逐位相加，
//        K /= 10;
//        if (sum >= 10) 
//        {
//            K++;
//            sum -= 10;
//        }
//        res[(*returnSize)++] = sum;
//    }
//    for (; K > 0; K /= 10) //如果k还有高位，逐一取下来放进数组
//    {
//        res[(*returnSize)++] = K % 10;
//    }
//    for (int i = 0; i < (*returnSize) / 2; i++) //旋转数组元素
//    {
//        int tmp = res[i];
//        res[i] = res[(*returnSize) - 1 - i];
//        res[(*returnSize) - 1 - i] = tmp;
//    }
//    return res;
//}

///*
//解题思路：使用三次逆转法，让数组旋转k次   也可以使用创建新数组法（在新数组中排好序，复制到原数组）
//1. 先整体逆转
//2. 逆转子数组[0, k - 1]
//3. 逆转子数组[k, size - 1]
//*/
//void reverse(int* nums, int begin, int end)
//{
//    while (begin < end)
//    {
//        int tmp = nums[begin];
//        nums[begin] = nums[end];
//        nums[end] = tmp;
//
//        ++begin;
//        --end;
//    }
//}
//
//// 三趟逆置倒的思路
//void rotate(int* nums, int numsSize, int k) {
//    if (k > numsSize)
//    {
//        k %= numsSize;
//    }
//
//    reverse(nums, 0, numsSize - 1);
//    reverse(nums, 0, k - 1);
//    reverse(nums, k, numsSize - 1);
//}


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
	int sp1 = 0, sp2 = 0;
	int* res = (int*)malloc((m + n) * sizeof(int));
	memset(res, 0, (m + n) * sizeof(int));
	for (int i = 0; i < nums1Size; i++)
	{
		if (sp1 == m || sp2 == n)
		{
			break;
		}
		if (nums1[sp1] <= nums2[sp2])
		{

		}
	}
}