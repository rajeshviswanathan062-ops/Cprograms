#include <stdio.h>
#include<string.h>

struct field
{
    char fieldname[20];
    int fieldsize;
};

struct field fields[16];
int sizefield;

char record[2][2][100];
int numberofrecords;

int main()
{
    sizefield=0;
    numberofrecords=0;
    char continueyn;
    do
    {
     createfield();
     printf("do you want to continue");
        scanf(" %c",&continueyn);
        printf("%c",continueyn);
    }while(continueyn=='y');
    writefield();
    add();
    add();
    show();
}

createfield()
{
    printf("enter field name");
    scanf("%19s",fields[sizefield].fieldname);
    printf("enter field size");
    scanf("%d",&fields[sizefield].fieldsize);
    sizefield++;
}

writefield()
{
    for(int i=0;i<sizefield;i++)
    {
        printf("%19s %d",fields[i].fieldname,fields[i].fieldsize);
    }
}


add()
{
    char temp[100];
     for(int i=0;i<sizefield;i++)
     {
        strcpy(temp,"enter ");
      printf("%s",strcat(temp,fields[i].fieldname));
      printf("%d",numberofrecords);
      scanf("%s",record[numberofrecords][i]);
     }
     numberofrecords++;
}

show()
{
    
    for(int i=0;i<numberofrecords;i++)
     for(int j=0;j<sizefield;j++)
      printf(record[i][j]);
}