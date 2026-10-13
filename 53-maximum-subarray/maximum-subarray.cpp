class Solution {
public:
    int maxSubArray(vector<int>& nums) {
//         int maxSum = INT_MIN;
//         int n = nums.size();
//         for(int i = 0;i<n;i++)
//         {
//             int currentSum = 0;
//             for(int j = i; j<n;j++)
//             {
//                 currentSum += nums[j];
//                 if (currentSum>maxSum)
//                 {
//                     maxSum = currentSum;
//                 }
//             }
//         }
//         return maxSum;
        
//     }
// };

int sum = 0;
int maxi = nums[0];
for(int i = 0;i<nums.size();i++)
{
    sum+= nums[i];
    if(sum>maxi)
    maxi = sum;
    if(sum<0)
    sum = 0;
}
return maxi;
    }
};