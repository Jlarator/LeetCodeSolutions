
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void moveUp(char*target){
  int len = strlen(target);
  if(target[len - 1] != ' ') return;

  int shift = 0;
  int start = 0; 
  int size = 0;
  int shiftStart = 0; 
  for(int i = len -1; i >= 0; i--){

    if((target[i] == ' ') && (size == 0))shift++;
    if((target[i] != ' ') && (size == 0)) shiftStart = i; 
    if((target[i] != ' ') ) size++;
    if((target[i] == ' ') && size != 0){
      start = i + 1;
      break;
    }
      
  }

  int left = len - 1; 
  for(int i = 0; i < size; i++){
    target[left] = target[shiftStart];
    target[shiftStart] = ' '; 
    left--;
    shiftStart--; 
  }
  
}

void stringCopy(char* target, char* new ){
  //  printf("\nCopying: %s\n", new); 
  int len = strlen(new);

  for(int i = 0; i < len; i++){
    target[i] = new[i]; 
  }  
}

void checkSpaces(char* target, int maxWidth){
  printf("Checking spaces for: |%s|\n",target); 
  moveUp(target); 
  int gaps = 0;
  int spaces = 0;
  char prev = '0' ;
  
  for(int i = 0; i < maxWidth; i++){
    if(prev == ' ' && target[i] != ' ') gaps++; 
    if(target[i] == ' ') spaces++;
    prev = target[i]; 
    //    printf(" %c ", target[i]); 

  }

  // redistribute spaces per gaps
  int spacesPerGap = 0;
  int extra = 0; 
  if(gaps != 0){
    spacesPerGap = spaces / gaps;
    extra = spaces % gaps; 
    //    extra =(extra == 1) ? 0 :extra;     
  }

  printf("Space count = %d | Gaps: %d | Extra: %d\n", spaces, gaps, extra);
    
  char temp[maxWidth];
  int tempIndex = 0;

  for(int i = 0; i < maxWidth; i++){
    if(target[i] != ' '){
      temp[tempIndex] = target[i];
      tempIndex++; 
    }else{
      if(gaps == 0){
	temp[tempIndex] = target[i];	
	tempIndex++; 
      }else{
	
	for(int k = 0; k < spacesPerGap; k++){
	  if(tempIndex == maxWidth - 1) break;
	  if(spaces == 0) break; 
	  temp[tempIndex] = ' ' ;
	  tempIndex++;
	  spaces--;
	
	  if(extra > 0){
	    temp[tempIndex] = ' ';
	    tempIndex++;
	    extra--;
	    spaces--;
	  }	
	}
	
      }
    }    
  }

  for(int i = 0; i < maxWidth; i++){
    target[i] = temp[i]; 
    
  }
  printf("\n"); 
  
}

char ** fullJustify(char ** words, int wordsSize, int maxWidth, int* returnSize){   
  printf("INIt return size %d\n", *returnSize);
  printf("MaxWidth: %d\n", maxWidth);
  printf("Words to process: %d\n", wordsSize); 
	 
  int charCount = 0;      
  int rowCount = 0;     
  int wordCount = 0;      
  int spaces = 0;
  
  for(int i = 0; i < wordsSize; i++){
    charCount += strlen(words[i]);    
    printf("\t<%d> Adding: %d | %s\n",i, strlen(words[i]), words[i]);
    
    if(i + 1 < wordsSize){
      
      if( (charCount + strlen(words[i+1]) + spaces + 1) > maxWidth){
	rowCount++;
	printf("CharCount: %d | RowCount: %d\n", (charCount + spaces), rowCount); 
	charCount = 0;
	spaces = 0; 
      }else{
	spaces++; 
      }
            
    }
  }
  
  printf("Remaining: %d\n", charCount);
  charCount+= spaces; 
  while(charCount > 0){    
    //if(charCount >= maxWidth) rowCount++;
    rowCount++; 
    printf(" %d -> ", charCount); 
    charCount -= maxWidth;
    printf(".. %d \n", charCount); 
  }
  
  printf("Row Count: %d\n", rowCount); 
  char** output;   
  output = (char**)malloc(sizeof(char*) * rowCount);   
    
  for(int ir = 0; ir < rowCount; ir++){        
    output[ir] = (char*)malloc(sizeof(char) * (maxWidth + 1));  
      
    for(int m = 0; m < maxWidth ; m++){    
      output[ir][m] = ' ';    
    }
   output[ir][maxWidth] = '\0';	
    printf(">|%s|<\n", output[ir]); 
  }      

  charCount = 0;
  int nextCount = 0;
  wordCount = 0;
  int wordsIndex = 0;
  int row = 0;
  int index = 0;
  int temp = 0;  
  printf("\n");

  for(int i = 0; i < rowCount; i++){
    printf("Iterating\n");
    
    charCount = strlen(words[wordsIndex]);
    index = 0;
      int wordUsed= 0; 

    while((charCount <= maxWidth) && (wordsIndex < wordsSize)){
      
      temp = charCount; 
      stringCopy(&output[i][index], words[wordsIndex]);	
        wordUsed++; 
      index +=  strlen(words[wordsIndex]) + 1;
      
      printf(" >%s<", words[wordsIndex]); 
      wordsIndex++; // move up to the next word
      if(wordsIndex < wordsSize) charCount += strlen(words[wordsIndex]) + 1;
      
    }
    
    printf("\nDone with: |%s| -> %d\n", output[i], temp); 

    if(((i + 1) < rowCount) && wordUsed > 1) checkSpaces(output[i], maxWidth);

  }
  
  *returnSize = rowCount; 
  printf("\nReturn size assigned to %d\n", *returnSize); 
  return output; 

}
      
      
int main(int argc, char *argv[]){

  int maxWidth = 0;
  int arrLen = 0;

  char **output;
  int size = -1;
  
  if(argc ==2){
    int selection = atoi(argv[1]);

    switch(selection){
      
    case 1:     
      maxWidth = 16;
      arrLen = 6;
      char *arr1[] = {"What", "must", "be", "acknowledgement", "shall", "be"}; // 16
      output = fullJustify(arr1, arrLen, maxWidth, &size);      
      break;
      
    case 2:	
      maxWidth = 17;
      arrLen = 15;
      char *arr2[] = {"The","important","thing","is","not","to","stop","questioning.",
	"Curiosity","has","its","own","reason","for","existing."};  //17
      output = fullJustify(arr2, arrLen, maxWidth, &size);      
      break;
      
    case 3:
      maxWidth = 20;
      arrLen = 18;
      char *arr3[] = {"Science","is","what", "we", "understand", "well", "enough",
		       "to","explain","to","a","computer.","Art","is","everything", "else", "we","do"}; // 20 -> 18      
      output = fullJustify(arr3, arrLen, maxWidth, &size);
      break;

    case 4:
      maxWidth = 15;
      arrLen = 7; 
      char *arr4[] = {"This", "is", "an", "example", "of", "text", "justification."}; // 15 -> 7
      output = fullJustify(arr4, arrLen, maxWidth, &size);
      break; 
    default:
      fprintf(stderr, "Make a valid selection\n");
      exit(0);       
      break; 
      
    }
  }
      
        
 
  printf("Size is %d\n", size);
  
  for(int i = 0; i < size; i++){
    printf("|%s|\n", output[i]); 
  }
  
  for(int i = 0; i < size; i++){
    free(output[i]); 
  }
  free(output); 
  return 0;
  
}
