class Solution {
    public String intToRoman(int num) {
        
        String output = ""; 
                
        while(num > 999){
            output += "M"; 
            num -= 1000; 
        }
        
        if(num > 399){ // if num is 399 < num <= 999; 
            
            if(num > 899){
                output += "CM"; 
                num -= 900; 
            }else if(num < 500){
                output += "CD"; 
                num -= 400; 
            }else if(num > 499 && num < 900){
                output += "D"; 
                num -= 500; 
            }
        }
        
        while(num > 99){
            output += "C";
            num -= 100; 
        }
        
        if(num > 39){            
            if(num > 89){
                output += "XC"; 
                num -= 90; 
            }else if(num > 49 && num < 90){
                output += "L"; 
                num -= 50; 
            }else{
                output += "XL"; 
                num -= 40; 
            }
        }
            
        while(num > 9){
            output += "X"; 
            num -= 10; 
        }
        
        if(num > 3){
            if(num == 9){
                output += "IX"; 
                num -= 9; 
            }else if (num > 4 && num < 9){
                output += "V"; 
                num -= 5; 
            }else if (num == 4){
                output += "IV"; 
                num -= 4; 
            }
       }
        
        while(num > 0){
            output += "I";
            num --; 
        }
                
        return output;         
    }
}
