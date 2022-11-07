class Solution {
    public int minimumDeletions(String s) {
        
        
        int startingA = 0;
        while(s.startsWith("a")){
            s = s.substring(1);
            startingA++;
        }

        int endingB = 0;
        while(s.endsWith("b")){
            endingB++;
            s = s.substring(0, s.length() - 1);
        }

        if(s.isEmpty()) return 0;

        int count = 0;

        Queue<Integer> B = new LinkedList<>();

        for(int i = 0; i < s.length() - 1; i++){
            if(String.valueOf(s.charAt(i)).equals("b")){
                count++;
                if(String.valueOf(s.charAt(i + 1)).equals("a")) {
                    B.add(count);
                }
            }
        }

        Stack<Integer> A = new Stack<>();
        int firstB = count; 
        count = 0;

        for(int i = s.length() - 1; i > 0; i--){
            if(String.valueOf(s.charAt(i)).equals("a")){
                count++;
                if(String.valueOf(s.charAt(i - 1)).equals("b")) A.add(count);
            }
        }

        int num = 0;
        int firstA = A.pop();
        int min = firstA;

        int Asize = A.size();
        int Bsize = B.size();
        
        while(!A.isEmpty()){
            num = B.remove() + A.pop();
            if(num < min) min = num;
        }

        // b b a a a a a | b b 

        if(startingA == 0 && Bsize == 1){
            if(endingB < firstA) return endingB;
        }

        // a a a | b b b a 
        if(endingB == 0 && Asize ==0){
            if(startingA < firstB) return startingA;
        }
        
        if(firstA < min || firstB < min){
            if(firstA < firstB) return firstA; 
            else return firstB; 
        }
        return min;
    
    }
}
