#include<cstdio>
#include<cstdlib>
//using namespace std;

//#define DEBUG

int main(){
	int caseNum;
	scanf("%d",&caseNum);
	while(caseNum-->0){
		int size;
		scanf("%d",&size);
		int *array=new int[size],*maxSumFromLeft=new int[size],*maxSumFromRight=new int[size];
		for(int i=0;i<size;i++){
			scanf("%d",array+i);
			maxSumFromLeft[i]=maxSumFromRight[i]=array[i];
		}
		for(int i=1;i<size;i++)
			if(maxSumFromLeft[i-1]>0)
				maxSumFromLeft[i]+=maxSumFromLeft[i-1];
		for(int i=1;i<size;i++)
			if(maxSumFromLeft[i]<maxSumFromLeft[i-1])
				maxSumFromLeft[i]=maxSumFromLeft[i-1];
		for(int i=size-2;i>=0;i--)
			if(maxSumFromRight[i+1]>0)
				maxSumFromRight[i]+=maxSumFromRight[i+1];
		for(int i=size-2;i>=0;i--)
			if(maxSumFromRight[i]<maxSumFromRight[i+1])
				maxSumFromRight[i]=maxSumFromRight[i+1];
#ifdef DEBUG
		for(int i=0;i<size;i++)
			printf("%d\t",array[i]);
		printf("\n");
		for(int i=0;i<size;i++)
			printf("%d\t",maxSumFromLeft[i]);
		printf("\n");
		for(int i=0;i<size;i++)
			printf("%d\t",maxSumFromRight[i]);
		printf("\n");
#endif
		int maxSum=INT_MIN;
		for(int i=0;i<size-1;i++)
			if(maxSum<maxSumFromLeft[i]+maxSumFromRight[i+1])
				maxSum=maxSumFromLeft[i]+maxSumFromRight[i+1];
		printf("%d\n",maxSum);
		delete[] maxSumFromLeft;
		delete[] maxSumFromRight;
		delete[] array;
	}
	return 0;
}