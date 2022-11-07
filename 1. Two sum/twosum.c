/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int *output = malloc(sizeof(int) * 2); 
    *returnSize = 2; 
    
    for(int left = 0; left < numsSize; left++){
            for(int i = 0; i < numsSize; i ++){
                    if(i != left){
                        if((nums[i] + nums[left]) == target){

                            output[0] = i;
                            output[1] = left; 
                            return output; 
                        }
                }
                
            }
        
    }
     
    return output; 
}
