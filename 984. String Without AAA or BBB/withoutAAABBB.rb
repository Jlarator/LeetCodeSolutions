# @param {Integer} a
# @param {Integer} b
# @return {String}
def str_without3a3b(a, b)
    total = a + b
    len = 3 - 1; 
    
    max = String::new
    min = String::new
    output = String::new
    maxint = 0
    minint = 0
    
    if(a > b)
        max = "a"
        min = "b"
        maxint = a
        minint = b
    else
        max = "b"
        min = "a"
        maxint = b
        minint = a
    end 
        
    while total > 0
        if minint == maxint
            len = 1
        end 
        
        for i in 1..len
            if maxint > 0
                output << max
                maxint-= 1
                total -= 1
            end
        end
         if minint > 0
                output << min
                minint -= 1
                total -= 1
            end
        
    end 
    return output 
    
end
