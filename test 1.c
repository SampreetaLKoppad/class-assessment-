#include<stdio.h>
#define NULL 0
struct student
{
  char name[30];
  int rno;
  float ht;
  struct student *link;
};

main()
{
struct student *head,*start,*ptr;
head=NULL;
int ch,pos,count;
struct student* insert_at_front(struct student*,struct student *);
struct student* insert_at_end(struct student*,struct student *);
struct student* delete_at_front(struct student*);
struct student* delete_at_end(struct student*);
void display_SLL(struct student*);
do
{
   printf("1:INSERT A NODE AT FRONT\n");
   printf("2:INSERT A NODE AT END\n");
   printf("3:DELETE A NODE AT FRONT\n");
   printf("4:DELETE A NODE AT END\n");
   printf("5:DISPLAY LINKED LIST\n");
    printf("11:EXIT\n");

   printf("enter your choice\n");
   scanf("%d",&ch);

   switch(ch)
   {
     case 1:ptr=(struct student*)malloc(sizeof(struct student));
            printf("enter name rollno and height of student\n");
            scanf("%s%d%f",&ptr->name,&ptr->rno,&ptr->ht);
            head=insert_at_front(head,ptr);
            break;
    case 2: ptr=(struct student*)malloc(sizeof(struct student));
            printf("enter name rollno and height of student\n");
            scanf("%s%d%f",&ptr->name,&ptr->rno,&ptr->ht);
            head=insert_at_end(head,ptr);
            break;
    case 3: if(head==NULL)
            printf("SLL is empty\n");
            else
            {
               head=delete_at_front(head);
            }
            break;
    case 4:if(head==NULL)
            printf("SLL is empty\n");
            else
            {
               head=delete_at_end(head);
            }
            break;
    case 5: if(head==NULL)
            printf("SLL is empty\n");
            else
            {
              display_SLL(head);
            }
            break;
            case 6: exit(0);break;
    default:printf("Invalid choice\n");break;
   }
}while(ch!=9);
}
struct student* insert_at_front(struct student *head, struct student *ptr)
{
    if(head==NULL)
    {
       head=ptr;
       head->link=NULL;
    }
    else
    {
      ptr->link=head;
      head=ptr;
    }
    return(head);
}

struct student* insert_at_end(struct student *head, struct student *ptr)
{
    struct student *start;
    if(head==NULL)
    {
       head=ptr;
       head->link=NULL;
    }
    else
    {
      start=head;
      while(start->link!=NULL)
      {
         start=start->link;
      }
      start->link=ptr;
      ptr->link=NULL;
    }
    return(head);
}

struct student* delete_at_front(struct student *head)
{
    struct student *cur;
      if(head->link==NULL)
      {
          printf("student deleted is\n");
          printf("name=%s\t rollno=%d\t height=%f\n",head->name,head->rno,head->ht);
          free(head);
          head=NULL;
      }
      else
      {
           cur=head;
           head=head->link;
           printf("student deleted is\n");
          printf("name=%s\t rollno=%d\t height=%f\n",cur->name,cur->rno,cur->ht);
          free(cur);
      }
      return(head);

}


struct student* delete_at_end(struct student *head)
{
    struct student *start,*cur;
      if(head->link==NULL)
      {
          printf("student deleted is\n");
          printf("name=%s\t rollno=%d\t height=%f\n",head->name,head->rno,head->ht);
          free(head);
          head=NULL;
      }
      else
      {
          start=head;
      while(start->link!=NULL)
      {
          cur=start;
         start=start->link;
      }
        printf("student deleted is\n");
          printf("name=%s\t rollno=%d\t height=%f\n",start->name,start->rno,start->ht);
          free(start);
          cur->link=NULL;
      }
      return(head);

}

void display_SLL(struct student *head)
{
   struct student *start;
   start=head;
   while(start->link!=NULL)
   {
       printf("name=%s\t rollno=%d\t height=%f\n",start->name,start->rno,start->ht);
       start=start->link;
   };
     printf("name=%s\t rollno=%d\t height=%f\n",start->name,start->rno,start->ht);

}
