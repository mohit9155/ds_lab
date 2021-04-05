#include <stdio.h>
int h1[100],h2[100],h3[100];
int n1,n2,n3;

int binary(int n,int a[],int key)
{
	int low,high,mid,flag=0;
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
	//	printf("\na[mid]=%d key=%d",a[mid],key);
		if(a[mid]==key)
		{
			flag=1;
				return 1;
		}
		
		else if(a[mid]<key)
			low=mid+1;
		else
			high=mid-1;
	}
	if(flag==0)
		return 0;
}
void cumulative(int n,int h[])
{
	int i;
	for(i=1;i<n;i++)
	{
		h[i]=h[i]+h[i-1];
	}
}
void revcumulative(int n,int h[])
{
	int i;
	for(i=n-1;i>=1;i--)
	{
		h[i]=h[i]-h[i-1];
	}
}
void revArray(int n,int h[])
{
	int i=0,j=n-1,temp;
	while(i<=j)
	{
		temp=h[i];
		h[i]=h[j];
		h[j]=temp;
		i++;
		j--;
	}
}
void inputArray(int n,int h[])
{

	int i;
	printf("\nEnter elements:\n");
	for(i=0;i<n;i++)
	{
		printf("%dth element:",i);
		scanf("%d",&h[i]);
	}
}

void printArray(int n,int h[])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",h[i]);
	}
	printf("\n");
}
void eqstacksprint(int n,int h[],int d)
{
	int i,s=0,top=n-1;
	//printArray(n,h);
	for(i=0;i<n;i++)
	{
		s+=h[i];
	}
	while(s!=d)
	{
		s-=h[top];
		top--;
	}
	printArray(top+1,h);
}
int main()
{

	int min,i,ans1=0,ans2=0,ans3=0,d;
	printf("Enter the size of the first stack:");
	scanf("%d",&n1);
	inputArray(n1,h1);
	revArray(n1,h1);
	cumulative(n1,h1);
	printArray(n1,h1);
	printf("Enter the size of the second stack:");
	scanf("%d",&n2);
	inputArray(n2,h2);
	revArray(n2,h2);
	cumulative(n2,h2);
	printArray(n2,h2);
	printf("Enter the size of the third stack:");
	scanf("%d",&n3);
	inputArray(n3,h3);
	revArray(n3,h3);
	cumulative(n3,h3);
	printArray(n3,h3);
	min=n3<(n1<n2?n1:n2)?n3:(n1<n2?n1:n2);
	//printf("min=%d",min);
	if(min==n3)
	{
		for(i=0;i<n3;i++)
		{
			if(binary(n1,h1,h3[i]) && binary(n2,h2,h3[i]))
			{
				printf("Sum of each stack should be: %d\n",h3[i]);
				d=h3[i];
				ans1=1;
				break;
			}
		}
	}
	else if(min==n2)
	{
		//printf("HIII");
		for(i=0;i<n2;i++)
		{
		//	printf("\n %d",h2[i]);
			if(binary(n1,h1,h2[i])==1 && binary(n3,h3,h2[i])==1)
			{
				printf("Sum of each stack should be: %d\n",h2[i]);
				d=h2[i];
				ans2=1;
				break;
			}
		}
	}
	else
	{
		for(i=0;i<n1;i++)
		{
			if(binary(n2,h2,h1[i]) && binary(n3,h3,h1[i]))
			{
				printf("Sum of each stack should be: %d\n",h1[i]);
				d=h1[i];
				ans3=1;
				break;
			}
		}
	}
	if(ans1==0 && ans2==0 && ans3==0)
		printf("Not possible");
	revcumulative(n1,h1);
	revcumulative(n2,h2);
	revcumulative(n3,h3);
	printf("\n The first stack:\n");
	eqstacksprint(n1,h1,d);
	printf("\n The second stack:\n");
	eqstacksprint(n2,h2,d);
	printf("\n The third stack:\n");
	eqstacksprint(n3,h3,d);
	return 0;
	
	
}
