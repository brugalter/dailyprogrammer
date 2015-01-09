#include<stdio.h>
#include<stdlib.h>

#define BASE 10

int main (int argc, char** args) {

  char** endpoints = (char**)calloc(100, sizeof (char));
  long** returnval = (long**)calloc(100, sizeof (long));
  long remains[15];

  int endPointCount = 1, i = 1, j = 0; 
  long total = 0, remainder = 0, sum = 0;
  *(endpoints + 1) = *(args + 1);

  while (1) {
  
    if (i == 1) { 
      *(returnval + i) = (long*)strtol(&**(endpoints + i), &*(endpoints+i), BASE);
      endPointCount++;
    } else {
      *(returnval + i) = (long*)strtol(&**(endpoints + (i-1)), &*(endpoints+i), BASE);
      endPointCount++;
    }
  
    if (**(endpoints + i) != '+') {
      *(endpoints +i ) = '\0';
      break;
    }
  
    i++;
  } 
  
  i=1;
  while (*(returnval + i) != '\0') {
    printf("%15d\n", *(returnval + i));
    total += (long)*(returnval + i);
    i++;
  }
  
  printf("---------------\n");
  printf("%15d\n", total);
  printf("---------------\n");

  for(i=0; i<15; i++) 
    remains[i] = 0;
 
  while (1) {
    sum = 0;
    for(i=1; i <= endPointCount; i++) {
      if(*(returnval + i) != '\0') {
        remainder = (long)&**(returnval + i) % 10;
        sum = sum + remainder;
        *(returnval + i) = (long*)((long)&**(returnval + i) / 10);
      }
    }
    
    remains[j] = (long)sum/10;
    j++;

    if(sum == 0)
      break;
  }

  for(i=13; i >= 0; --i) {
    if (remains[i] == 0 ) {
      printf(" ");
    } else {
      printf("%d", remains[i]);
    }
  }

  free(endpoints);
  free(returnval);
  return 0;
}
