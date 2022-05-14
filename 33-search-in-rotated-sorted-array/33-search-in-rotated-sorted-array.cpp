class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int n= nums.size();
        int r= n-1;
        
      //  int mid= l+(r-l)/2;
        
//         while(l<=r)
            
//         {
            
//             int mid= (l+r)/2;
//             if(nums[mid] == target)
//             {
//                 return mid;
//             }
            
//             if(nums[mid] > nums[r])
//             {
//                  if (target < nums[mid] && target >= nums[l])
//                 {
//                     r=mid-1;
//                 }
//                 else
//                 {
//                     l=mid+1;
//                 }
//             }
            
//             else if(nums[mid]< nums[l])
//             {
//                  if (target > nums[mid] && target <= nums[r])
//                 {
//                     l=mid+1;
//                 }
//                 else 
//                 {
//                     r=mid-1;
//                 }
//             }
            
           
//         }
        
         while (l <= r) {
            int mid = (l+r) / 2;
            if (target == nums[mid])
                return mid;
            // there exists rotation; the middle element is in the left part of the array
            if (nums[mid] > nums[r]) {
                if (target < nums[mid] && target >= nums[l])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            // there exists rotation; the middle element is in the right part of the array
            else  {
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            //  else {
            //     if (target < nums[mid])
            //         r = mid - 1;
            //     else
            //         l = mid + 1;
            // }
         }
        
        return -1;
    }
};