#include <stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 67

int h[TABLE_SIZE]={NULL};
int digitSum(int key){
    int sum=0;
    int temp=key;
    while(temp!=0){
        sum+= temp%10;
        temp=temp/10;
    }
    return sum;
}
void insert()
{

 int key,index,i,flag=0,hkey,keysum;
 printf("\nEnter a value to insert into hash table\n");
 scanf("%d",&key);
 keysum = digitSum(key);
 hkey=keysum%TABLE_SIZE;
 for(i=0;i<TABLE_SIZE;i++)
    {

     index=(hkey+i)%TABLE_SIZE;
     if(h[index] == NULL)
     {
        h[index]=key;
         break;
     }
     printf("\ncollision\n");
    }

    if(i == TABLE_SIZE)

     printf("\nElement cannot be inserted\n");
}
void search()
{

 int key,index,i,flag=0,hkey,keysum,compare=0;
 printf("\nenter search element\n");
 scanf("%d",&key);
 keysum = digitSum(key);
 hkey=keysum%TABLE_SIZE;
 for(i=0;i<TABLE_SIZE; i++)
 {
    index=(hkey+i)%TABLE_SIZE;
    compare++;
    if(h[index]==key)
    {
      printf("value is found at index %d",index);
      printf("Total comparisions %d",compare);
      break;
    }
  }
  if(i == TABLE_SIZE)
    printf("\n value is not found\n");
}
void display()
{

  int i;

  printf("\nelements in the hash table are \n");

  for(i=0;i< TABLE_SIZE; i++)

  printf("\nat index %d \t value =  %d",i,h[i]);

}
main()
{
    int opt,i;
    while(1)
    {
        printf("\nPress 1. Insert\t 2. Display \t3. Search \t4.Exit \n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:exit(0);
        }
    }
}