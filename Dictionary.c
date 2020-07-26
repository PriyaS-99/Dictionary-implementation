#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node
{
  char data[20];
  char mean[5][20];
  struct node *link;
};

typedef struct node *dictptr;
dictptr first;
void add(dictptr *first,char *word);
int search(dictptr first,char *word);
void display(dictptr first1);

void main()
{
  char word[20];
  int ch,i=0;
  printf("\n\tDICTIONARY\n\n");
  while(1)
  {
    printf("\n\t\t1.ADD WORD\n");
    printf("\t\t2.SEARCH WORD\n");
    printf("\t\t3.DISPLAY DICTIONARY\n");
    printf("\t\t4.EXIT\n");
    printf("\tYOUR CHOICE\n");
    scanf("%d",&ch);

    switch(ch)
    {
      case 1:printf("\nEnter any Word:");
             scanf("%s",word);
             add(&first,word);
             break;
      case 2:printf("\nEnter the word to be searched:");
             scanf("%s",word);
             i=search(first,word);
             if(i==0)
             printf("Word does not exist.");
             break;
        case 3:display(first);
               break;
      case 4:exit(0);
             break;
      default: printf("\nWrong Choice");
          }
  }
}

void clear_buf()
{
        char ch;
        while(((ch=getchar())!=EOF)&&ch!='\n');
}

void add(dictptr *first,char *word)
{
  dictptr temp,trail,cur;
  char m[5][20],cho;
  int i=1,flag;
  flag=search(*first,word);
  if(flag==0)
    {
     temp=(struct node*)malloc(sizeof(struct node));
     strcpy(temp->data,word);
     printf("Enter the first meaning\n");
     clear_buf();
     gets(m[0]);
     strcpy(temp->mean[0],m[0]);
    while(i!=5)
    {
     printf("Do you want to add more meanings(y/n)?\n");
     scanf("%c",&cho);
     if(tolower(cho)=='y')
     {
       printf("Enter the meaning\n");
       clear_buf();
       gets(m[i]);
       strcpy(temp->mean[i],m[i]);
       i++;
     }
     else
        break;
     }
  if(i==5)
     printf("Cannot enter more than 5 meanings\n");
  if(*first==NULL)
   {
     *first=temp;
     temp->link=NULL;
   }
  else if(strcmp(temp->data,(*first)->data)<0)
   {
      temp->link=*first;
      *first=temp;
   }
  else	
   {
     trail=NULL;
     cur=*first;
     while((cur)&&(strcmp(cur->data,temp->data)<0))
     {
       trail=cur;
       cur=cur->link;
     }
     trail->link=temp;
     temp->link=cur;
    }
  }
 else
   printf("Word Already Exists\n");
}


int search(dictptr first,char *word)
{
   dictptr temp;
   int i;
   temp=first;
   while(temp!=NULL)
   {
     if(strcmp(temp->data,word)==0)
     {
       printf("Word: %s\n",temp->data);
       printf("Meanings: ");
       for(i=0;i<5;i++)
       {
         printf("%s    ",temp->mean[i]);
       }
      printf("\n");
      return 1;
     }
     temp=temp->link;
   }
  return 0;
}


void display(dictptr first1)
{

  dictptr temp;
  int i,ch;
  char alpha;
  int count=0;
  temp=first1;
  printf("\n1.COMPLETE DICTIONARY\n2.ALPHABET WISE WORDS\n");
  scanf("%d",&ch);
  clear_buf();	
  switch(ch)						


  {
    case 1:
       if(temp==NULL)
         printf("Dictionary is empty\n");
       else
       {
        while(temp!=NULL)
        {
          printf("Word: %s\n",temp->data);
          printf("Meanings: ");
          for(i=0;i<5;i++)
           {
             printf("%s    ",temp->mean[i]);
           }
          printf("\n");
          temp=temp->link;
        }
      }
    break;
    case 2:printf("Enter the alphabet\n");
           scanf("%c",&alpha);
           if(temp==NULL)
             printf("Dictionary is empty\n");
           else
           {
             while(temp!=NULL)
             {
               if((temp->data[0])==alpha)
               {

                count=1;
                printf("Word: %s\n",temp->data);
                printf("Meanings: ");
                for(i=0;i<5;i++)
                {
                  printf("%s    ",temp->mean[i]);
                }
               }
               printf("\n");
               temp=temp->link;
             }
           }
           if(count==0)
            printf("No word exists in for the entered alphabet\n");
            break;
   default:printf("Invalid Choice\n");
  }
}
