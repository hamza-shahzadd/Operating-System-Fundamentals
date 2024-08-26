#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>

char fname[20];
int g = -1;
 
// The function to be executed by all threads
void *myThreadFun(void *vargp)
{
	// enter file name
    // Store the value argument passed to this thread
    int *cas = (int *)vargp;
    g++;
    int a =*cas;
     a = g + a; 
     char ch = (char)a;// type cast to character
     int count=0;
     //////////////////////////////// 
     FILE *fp;
     char cha;
	fp = fopen(fname, "r");
   while(fp)
   {
      cha = fgetc(fp);
      if(cha==ch || cha == ch-32)     // this condition also counts capital of a certain alphabet.
         {
         	count++;
         }
      if(cha ==EOF)
      {
      	break;
      }
   }
   fclose(fp);
    
     
    
    printf("Albhabet: %c, count: %d\n", ch,count);
    
    pthread_exit((void*)count);
    
    // Return count and add it in main//
}
 
int main()
{
    pthread_t tid[26];
    int j=97;
    int total[26];
    int ans=0;
    
    	printf("Enter file name \n");
    	scanf("%s",fname);
    // Let us create three threads
    for (int i = 0; i < 26; i++)
    {
        pthread_create(&tid[i], NULL, myThreadFun, (void *)&j);
    }	
   	
   	int result;
   	
    for(int j = 0; j < 26; j++)
    {
    	 pthread_join(tid[j],(void*)&result);
    	 int answer = (int *)result;
    	 total[j]=answer;
    }	
    
    for(int k=0;k<26;k++)
    {
    	ans=ans+total[k];
    }
      
    printf("Total count = %d\n",ans);
    pthread_exit(NULL);
    
  
    
    return 0;
}
