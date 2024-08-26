#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>



void* resultantEntry(void *arg)
{
	int *val_p = (int *) arg;
	int answer=0;
	int temp=0;
	for(int i=0; i<3;i++)
	{
		temp= val_p[i] * val_p[i+3];
		answer=answer+temp;		
	}
	
	printf("The answer is: %d\n",answer);
		
	pthread_exit((void*)answer);
}

int main()
{
	
	int matrix1[3][3];
	int matrix2[3][3];
	
	printf("Matrix A\n"); 
	for(int i=0; i<3; i++) 
	{
      		for(int j=0;j<3;j++) 	
      		{
         		printf("Enter value [%d][%d]:", i, j);
         		scanf("%d", &matrix1[i][j]);
      		}
   	}
   	
   	printf("Matrix B\n"); 
	for(int i=0; i<3; i++) 
	{
      		for(int j=0;j<3;j++) 	
      		{
         		printf("Enter value [%d][%d]:", i, j);
         		scanf("%d", &matrix2[i][j]);
      		}
   	}
	
	printf("\n"); 
	
	int arr1[6];
	int arr2[6];
	int arr3[6];
	int arr4[6];
	int arr5[6];
	int arr6[6];
	int arr7[6];
	int arr8[6];
	int arr9[6];
	
	int col=0;
	for(int i=0; i<3;i++)
	{
		arr1[i]=matrix1[0][col];
		arr2[i]=matrix1[0][col];
		arr3[i]=matrix1[0][col];
		col=col+1;
	}
	col=0;
	for(int j=0;j<3;j++)
	{
		arr4[j]=matrix1[1][col];
		arr5[j]=matrix1[1][col];
		arr6[j]=matrix1[1][col];
		col=col+1;
	}
	
	col=0;
	for(int k=0;k<3;k++)
	{
		arr7[k]=matrix1[2][col];
		arr8[k]=matrix1[2][col];
		arr9[k]=matrix1[2][col];
		col=col+1;
	}
	int row=0;
	
	for(int i=3; i<6;i++)
	{
		arr1[i]=matrix2[row][0];
		arr4[i]=matrix2[row][0];
		arr7[i]=matrix2[row][0];
		row=row+1;
	}
	row=0;
	
	for(int j=3; j<6;j++)
	{
		arr2[j]=matrix2[row][1];
		arr5[j]=matrix2[row][1];
		arr8[j]=matrix2[row][1];
		row=row+1;
	}
	row=0;
	for(int k=3; k<6;k++)
	{
		arr3[k]=matrix2[row][2];
		arr6[k]=matrix2[row][2];
		arr9[k]=matrix2[row][2];
		row=row+1;
	}
	
	
		
	int temp,temp1;	
	int resultant[3][3];
	pthread_t threadArr[9];
	
	pthread_create(&threadArr[0], NULL,resultantEntry,(void*)&arr1);
	pthread_join(threadArr[0],(void*)&temp);
	temp1=(int*)temp;
	resultant[0][0]=temp1;
	
	pthread_create(&threadArr[1], NULL,resultantEntry,(void*)&arr2);
	pthread_join(threadArr[1],(void*)&temp);
	temp1=(int*)temp;
	resultant[0][1]=temp1;
	
	
	pthread_create(&threadArr[2], NULL,resultantEntry,(void*)&arr3);
	pthread_join(threadArr[2],(void*)&temp);
	temp1=(int*)temp;
	resultant[0][2]=temp1;
	
	
	pthread_create(&threadArr[3], NULL,resultantEntry,(void*)&arr4);
	pthread_join(threadArr[3],(void*)&temp);
	temp1=(int*)temp;
	resultant[1][0]=temp1;
	
	
	pthread_create(&threadArr[4], NULL,resultantEntry,(void*)&arr5);
	pthread_join(threadArr[4],(void*)&temp);
	temp1=(int*)temp;
	resultant[1][1]=temp1;
	
	pthread_create(&threadArr[5], NULL,resultantEntry,(void*)&arr6);
	pthread_join(threadArr[5],(void*)&temp);
	temp1=(int*)temp;
	resultant[1][2]=temp1;
	
	pthread_create(&threadArr[6], NULL,resultantEntry,(void*)&arr7);
	pthread_join(threadArr[6],(void*)&temp);
	temp1=(int*)temp;
	resultant[2][0]=temp1;
	
	pthread_create(&threadArr[7], NULL,resultantEntry,(void*)&arr8);
	pthread_join(threadArr[7],(void*)&temp);
	temp1=(int*)temp;
	resultant[2][1]=temp1;
	
	pthread_create(&threadArr[8], NULL,resultantEntry,(void*)&arr9);
	pthread_join(threadArr[8],(void*)&temp);
	temp1=(int*)temp;
	resultant[2][2]=temp1;

	printf("\nResultant matrix:\n");	
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf(" %d ",resultant[i][j]);
		}
		printf("\n");

	}
	
	

}
//
