#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct process
{
    char process_id[10];
    char p_status[50];    
    char value[50];    
    struct process* next;
};
struct process* head = NULL;
void addProcess()
 {
     struct process* ptr;    
     struct process* temp;    
     temp = head;    
     ptr = (struct process*)malloc(sizeof(struct process));    
     printf("Enter Process ID: ");    
     scanf("%s", ptr->process_id);    
     printf("Enter Process Status(Ready, Running, Waiting): ");  
     scanf("%s", ptr->p_status);    
     printf("Enter Value: ");  
     scanf("%s", ptr->value);    
     if (head == NULL)
      {
              head = ptr;
      }    
      else {
        while (temp->next != NULL)
         {
                     temp = temp->next;        
         }
         	temp->next = ptr;    
         }
}
void removeprocess()
 {
     struct process* temp, * previous;    
     temp = head;    
     previous = head;    
     int flag = 0;    
     char processtoberemoved[50];     
     printf("Enter Process Id You want to remove: ");    
     scanf("%s", processtoberemoved);    
     while (temp != NULL) 
     {
             if (strcmp(temp->process_id, processtoberemoved) == 0) 
             { 
                        if (temp != head)                
                        previous->next = temp->next;            
                        else                
                        head = temp->next;            
                        printf("Removed Successfully.\n");            
                        flag = 1;        
             }        
             previous = temp;        
             temp = temp->next;    
      }    
      if (flag == 0)
       {
               printf("Process not found!\n");    
       }
}
void displayAllProcess() 
{
    struct process* temp;    
    temp = head;    
    while (temp != NULL) 
    {
            printf("*All Process*\n");        
            printf("Process Id: %s\n", temp->process_id);        
            printf("Process Status : %s\n", temp->p_status);        
            printf("Priority Value: %s\n", temp->value);
            temp = temp->next;    
    }    
    printf("\n");
}
void displayOnlyreadystate() 
{
    struct process* temp;    
    int count = 0;    
    temp = head;    
    printf("\n");    
    printf("*Only ready state processes*\n");    
    printf("\n");    
    while (temp != NULL) 
    {
            if (strcasecmp(temp->p_status, "ready") == 0) 
            {
                        printf("\n");            
                        printf("Process ID: %s\n", temp->process_id);            
                        printf("Process Status : %s\n", temp->p_status);            
                        printf("Priority Value: %s\n", temp->value);            
                        count++;        
             }        
             temp = temp->next;   
     }

}
void displayhighest() 
{
    struct process* temp = head;         
    printf("*Highest Priority Process*\n");    
    printf("\n"); 
    int max;
    max = head->value; 
    while (temp != NULL) 
    {
            if (max < temp->value)
            {
                       max=temp->value;                        
                       printf("Process ID: %s\n", temp->process_id);
                       printf("Process Status : %s\n", temp->p_status);
                       printf("Priority Value: %s\n", temp->value);
           }        
           temp = temp->next;    
   }   
     

 }
 int main(int argc, char** argv[])
 {
    
     printf("*PCB*\n");
     printf("\n");    
     int ch;    
     do 
     {
             printf("1. Add a new process\n");        
             printf("2. Remove a process\n");        
             printf("3. Display the ready state processes\n");        
             printf("4. Display the highest priority process \n");        
             printf("5. Exit\n");              
             printf("Enter your choice: ");       
             scanf("%d", &ch);        
             switch (ch)        
             {
                     case 1:            
                     addProcess();            
                     displayAllProcess();            
                     break;        
                     case 2:            
                     removeprocess();            
                     displayAllProcess();            
                     break;        
                     case 3:            
                     displayOnlyreadystate();            
                     break;        
                     case 4:            
                     displayhighest();            
                     break;               
                     case 5:            
                     printf("Thank You.\n");            
                     break;        
                     default:            
                     
                     printf("Invalid choice.\n");            
                     break;        
               }    
         } 
         while (ch != 5);    
         return 0;
}