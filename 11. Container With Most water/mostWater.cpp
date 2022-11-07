class Solution {
public:
    int maxArea(vector<int>& height) {
        
    
    int max = 0; 
    int minElement = 0; 
    int volume = 0; 
    int rightMax = 0; 
    
    int len = height.size();  
    
    for(int i = 0; i < len ; i++){
        
        int hint = height[i]; 
        
        if(hint > minElement){
            rightMax = 0;
            

            for(int k = len - 1; k > i; k--){

                if(hint >= rightMax){
                    
                    int kint = height[k]; 
                    
                    if(hint > kint)  minElement = kint;
                    else minElement = hint; 
                                        
                    volume = minElement * (k - i); 
                    if(volume > max)max = volume; 
                    if(hint == rightMax)  k = i; 
                    
                    rightMax = kint; 
                }
            }

        }
    }   
    return max;                 
    }
};
