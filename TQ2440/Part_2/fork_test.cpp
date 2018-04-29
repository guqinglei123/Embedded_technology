#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
 
int main(void) {
   int i;
   pid_t aa;
   for (i=0; i<2; i++) {
      aa = fork();
      printf("%d\n",aa);
      printf("-\n");
   }
   return 0;
}