#include <stdio.h>
#include <string.h>
#include<math.h>
struct student
{
    int id;
    char name[20];
    char phone[11];
};

struct date
{
    int day;
    int month;
    int year;
};

struct accounting
{
    struct date transactiondate;
    char account[20];
    char debitcredit[20];
    int transactionnumber;
};

struct transaction
{
    char text[20];
};

struct student astudent[16];
int sizearray;
struct student tstudent[16];
int sizetemp;
char tname[16][20];
int sizename;

struct accounting aaccounting[16];
int sizeaccounting;

struct transaction atransaction[16];
int sizetransaction;

int main()
{
    sizearray=0;
    sizeaccounting=0;
    sizetransaction=0;
    add();
    //add();
    //change();
    //removes();
    //where();
    //distinct();
    //sort();
    /*int a=aggregate("std");
    printf("%d",a);*/
    //group("count");
    //join();
    show("a");
    /*int a=findStudent(1);
    printf("%d",a);*/
    //stringtodate();
}

struct date stringtodate(char str[])
{
    struct date d;
    sscanf(str, "%d/%d/%d", &d.day, &d.month, &d.year);
    return d;
}

inline add()
{
    /*printf("enter id");
    scanf("%d",&astudent[sizearray].id);
    printf("enter name");
    scanf("%s",astudent[sizearray].name);
    printf("enter phone");
    scanf("%s",astudent[sizearray].phone);
    sizearray++;*/
    
    /*char sdate[11];
    printf("enter date");
    scanf("%11s",sdate);
    aaccounting[sizeaccounting].transactiondate=stringtodate(sdate);
    printf("enter account");
    scanf("%20s",aaccounting[sizeaccounting].account);
    printf("enter debit or credit");
    scanf("%20s",aaccounting[sizeaccounting].debitcredit);
    printf("enter transaction number");
    scanf("%d",&aaccounting[sizeaccounting].transactionnumber);
    sizeaccounting++;*/
    
    printf("enter transaction");
    scanf("%s",atransaction[sizetransaction].text);
}

static inline printStudent(/*struct student *s*/struct accounting *s)
{
    //printf("%d %s %s\n", s->id, s->name, s->phone);
    printf("%d %d %d %s %s %d",s->transactiondate.day,s->transactiondate.month,s->transactiondate.year,s->account,s->debitcredit,s->transactionnumber);
}

inline show(char s[])
{
    if(strcmp(s,"a")==0)
    {
        struct student * restrict pastudent=astudent;
        struct accounting * restrict paaccounting=aaccounting;
     for (int i = 0; i < /*sizearray*/sizeaccounting; i++)
    printStudent(/*&pastudent[i]*/&paaccounting[i]);
    
    }
    if(strcmp(s,"t")==0)
    {
        struct student * restrict ptstudent=tstudent;
     for (int i = 0; i < sizetemp; i++)
    printStudent(&ptstudent[i]);
    }
}

static inline findStudent(int id)
{
    for (int i = 0; i < sizearray; i++)
        if (astudent[i].id == id)
            return i;
    return -1;
}

inline change()
{
    int id;
    char name[20];
    char phone[10];
    printf("Enter id");
    scanf("%d",&id);
    printf("Enter name");
    scanf("%s",name);
    printf("Enter phone");
    scanf("%10s",phone);
    struct student * restrict pastudent=astudent;
            int index = findStudent(id);
if (index != -1)
{
    strcpy(pastudent[index].name, name);
    strcpy(pastudent[index].phone, phone);
}
}

inline removes()
{
    int id;
    int deletedid;
    printf("Enter id");
    scanf("%d",&id);
    struct student * restrict pastudent=astudent;
            deletedid = findStudent(id);
if (deletedid != -1)
{
    for (int j = deletedid + 1; j < sizearray; j++)
        pastudent[j - 1] = pastudent[j];
    sizearray--;
}
}

void copyStudent(struct student *dest, const struct student *src)
{
    dest->id = src->id;
    strcpy(dest->name, src->name);
    strcpy(dest->phone, src->phone);
}

inline where()
{
    int id;
    printf("Enter id");
    scanf("%d",&id);
    int j;
    j=0;
    struct student * restrict ptstudent=tstudent;
    struct student * restrict pastudent=astudent;
    int index = findStudent(id);
if (index != -1)
{
    ptstudent[0] = pastudent[index];
    sizetemp = 1;
}
else
{
    sizetemp = 0;
}
}

 distinct()
{
    int j = 0;
    for(int i = 0; i < sizearray; i++)
    {
        int found = 0;
        /*struct student * restrict ptstudent=tstudent;
        struct student * restrict pastudent=astudent;*/
        for(int k = 0; k < j; k++)
        {
            printf("%d",k);
            if(tstudent[k].id == astudent[i].id)
            {
                found = 1;
                break;
            }
        }
        if(!found)
        {
            tstudent[j] = astudent[i];
            j++;
        }
    }
    sizetemp = j;
}

inline sort()
{
    /*struct student * restrict ptstudent=tstudent;
    struct student * restrict pastudent=astudent;*/
    //printf("%d",sizearray);
    for (int i = 0; i < sizearray; i++)
    tstudent[i] = astudent[i];
sizetemp = sizearray;
        for(int k=0;k<sizetemp;k++)
         for(int l=k;l<sizetemp;l++)
          if(tstudent[k].id>tstudent[l].id)
          {
              struct student temp;
              temp = tstudent[k];
              tstudent[k] = tstudent[l];
              tstudent[l] = temp;
          }
}

inline double aggregate(char method[])
{
    int tsum;
    tsum=0;
    int tcount;
    tcount=0;
    int tsumsquare;
    tsumsquare=0;
    struct student * restrict pastudent=astudent;
    for(int i = 0; i < sizearray; i++)
    {
         tsum+=pastudent[i].id;
         tcount++;
         tsumsquare+=pow(pastudent[i].id,2);
    }
    int tmin;
    int tmax;
    tmin=pastudent[0].id;
    tmax=pastudent[0].id;
    for(int j = 1; j < sizearray; j++)
    {
         if(pastudent[j].id<tmin)
          tmin=astudent[j].id;
         if(pastudent[j].id>tmax)
          tmax=astudent[j].id;
    }
    int tavg;
    tavg=tsum/tcount;
    double avg = (double)tsum / tcount;
    double variance = ((double)tsumsquare / tcount) - avg * avg;
    double tstd = sqrt(variance);
    if(strcmp(method,"sum")==0)
     return tsum;
    if(strcmp(method,"count")==0)
     return tcount;
    if(strcmp(method,"min")==0)
     return tmin;
    if(strcmp(method,"max")==0)
     return tmax;
    if(strcmp(method,"avg")==0)
     return tavg;
    if(strcmp(method,"std")==0)
     return tstd;
}

inline group(char aggregate[])
{
    sizename = 0;
    /*struct student * restrict pastudent=astudent;
    char (*ptname)[20] = tname;*/
    for(int i=0;i<sizearray;i++)
    {
        int found = 0;
        for(int j=0;j<sizename;j++)
        {
            if(strcmp(tname[j], astudent[i].name)==0)
            {
                found = 1;
                break;
            }
        }
        if(!found)
        {
            strcpy(tname[sizename], astudent[i].name);
            sizename++;
        }
    }
    char name[20];
    int sum;
    int count;
    int id;
    sizetemp=0;
    int m;
    m=0;
    for(int k=0;k<sizename;k++)
    {
        sum=0;
        count=0;
     for(int l=0;l<sizearray;l++)
      if(strcmp(tname[k],astudent[l].name)==0)
      {
       strcpy(name,astudent[l].name);
       sum+=astudent[l].id;
       count++;
      }
      if(strcmp(aggregate,"sum")==0)
       id=sum;
      if(strcmp(aggregate,"count")==0)
       id=count;
      tstudent[m].id=id;
      strcpy(tstudent[m].name,name);
      m++;
      sizetemp++;
    }
}

inline join()
{
    int k;
    k=0;
    struct student * restrict pastudent=astudent;
    struct student * restrict ptstudent=tstudent;
    for(int i=0;i<sizearray;i++)
        for(int j=0;j<sizearray;j++)
         if(pastudent[i].id==pastudent[j].id)
         {
          ptstudent[k] = pastudent[i];
          k++;
         }
         sizetemp = k;
}