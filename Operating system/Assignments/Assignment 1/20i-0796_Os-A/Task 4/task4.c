#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>

int main()
{
 int fd1[2];
// int fd2[2];
 pid_t x;
 char inp[200];
 char readbuffer[200];
 
 int counts=0;
 int words=1;
 int lines=0;

 
 	printf("Enter any string \n");
 	fgets(inp, 200, stdin);
 	printf("%s", inp);
   
 int result = pipe(fd1);
	if(result == -1)
	{
		printf("Error in making pipe");
	}
	else
	{	
		x=fork();
		if(x < 0)
		{
			printf("Error in forking");		
		}	
		else if(x > 0) // parent
		{
			close(fd1[0]);// closing read pipe
			write(fd1[1], inp, 200);
			close(fd1[1]);
			wait(NULL);
		}
		else  // child
		{
			close(fd1[1]);
			read(fd1[0],readbuffer,200);
			close(fd1[0]);
			printf("Entered String = %s",readbuffer);
			printf("\n");
			// 2) Count number of characters.
			
			counts= strlen(readbuffer);
			counts -= 1;			// Exclude back slash zero
			printf("Count of string = %i", counts);
			printf("\n");
			
			// 3) count number of words.
			for(int i =0; i < counts ;i++)
			{
				if(readbuffer[i] == ' ' || readbuffer[i] == '.')
					words++;
			}
			
			printf("Count of words = %i", words);
			printf("\n");
			
			// 4) Count number of lines
			for(int i =0; i < counts ;i++)
			{
				if(readbuffer[i] == '.')
				{
					lines++;
				}
			}
			printf("Count of lines = %i", lines);
			printf("\n");
			
			//Creating countfile and copying text in it.
			
			FILE* count;
			count = fopen("countfile.txt", "w+");
			
			fprintf(count, "Total number of characters = %i", counts);
			
			fprintf(count, "\nTotal number of words = %i", words);
			
			fprintf(count, "\nTotal number of lines = %i", lines);
    			
    			// closes the file pointed by demo
    			fclose(count);
			
			exit(0);
		}
	}			
    			
			
return 0;
}

