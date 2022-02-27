#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct customer
{
  char nm[100];
  int ph;
  float reward;
  struct customer *link;
};
typedef struct customer co;
struct Bill
{
  char name[100];
  int price;
  int quantity;
  struct bill*link;
};
typedef struct Bill bl;

bl* billaccept(FILE*,bl*,int*);



bl* billaccept(FILE*fp,bl*start,int*cnt)
{
    int i, sl[50], price[50],billuse;
    char nm[50][100];
     printf("The items present are\n");
	  for (i = 0; i <100; i++)
	    {
	      fscanf (fp, "%d%s%d", &sl[i], nm[i], &price[i]);
	      if (sl[i] == 0)
		  break;
	      printf ("%d %s %d\n",sl[i],nm[i],price[i]);
	    }
	  printf("Enter the option to choose\n");
	  scanf("%d",&billuse);
	  bl*t,*l,*p;
      t=(bl*)malloc(sizeof(bl));
      printf("Enter quantity");
      scanf("%d",&(t->quantity));
      strcpy(t->name,nm[billuse]);
      t->price=((price[billuse])*(t->quantity));
	  if(start==0)
	  {
	      (*cnt)++;
	      return t;
	  }
	  for(l=start;l!=0;p=l,l=l->link);
	  p->link=t;
	  (*cnt)++;
	  return start;
}

co*customeraccept(co*first,co**temp)
{
    co*t,*cur,*prev;
    t=(co*)malloc(sizeof(co));
    printf("Enter your name\n");
    scanf("%s",t->nm);
    printf("Enter your phone number\n");
    scanf("%d",t->ph);
    if(first==0)
    {
        return t;
    }
    for(cur=first;cur!=0;prev=cur,cur=cur->link)
    {
        if(cur->ph==t->ph)
        {
          (*temp)=cur;
        return first;
        }
    }
    (*temp)=t;
    t->link=first;
    first=t;
    return first;
}

void billing(co*temp,co*first,bl*start,int cnt)
{
  float*sum=0;
  sum=display(start,cnt,sum);
  
}

void display(bl*start,int cnt,float*sum)
{
  int i=1;
  bl*t;

  for(t=start;t!=0;t=t->link)
  {
    printf("%d\t%s\t%d\t%d\n",i,t->name,t->quantity,t->price);
    i++;
    (*sum)+=(t->price);
  }
}


int main ()
{
  int ch,cnt;
  float sum;
  co *first = 0,*temp=0;
  bl *start = 0;
  FILE *fp;
  for(;;)
    { first =customeraccept(first,&temp);
  for (;;)
    {
     
      printf("What would you like to have\n");
      printf ("press\n1.Beverages\n2.Starters\n3.Combos\n4.Display cart\n5.Proceed to buy\n");
      scanf ("%d", &ch);
      switch (ch)
	{
	case 1:
	  fp = fopen ("Breverages.txt", "r");
	  start=billaccept(fp,start,&cnt);
    break;
	case 2:
	  fp = fopen ("Starters.txt", "r");
	  start=billaccept(fp,start,&cnt);
    break;
  case 3:
	  fp = fopen ("Combos.txt", "r");
	  start=billaccept(fp,start,&cnt);
    break;
  case 4:
    display(start,cnt,&sum);
    break;
  
	}
    }
}	
	