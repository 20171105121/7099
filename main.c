
#include<stdio.h>
struct student
{
    int numbers;
    char name[10];
    char sex[10];
    int  birth;
    char  classes[15];
    char phone[15];
    int score[10];
    int min;
    int max;
    int average;
};
int main()
{
    
    
    struct student s[100];
    FILE *fp1,*fp2;
    int i=0,a,j;
    char bt[100];
    fp1=fopen("/Users/s20171105121/Desktop/studentdata.csv","r");
    if(fp1==NULL)
    {
        printf("error");
        return -1;
    }
    else
    {
        
        fscanf(fp1,"%s",bt);
        while(!feof(fp1))
        {
            fscanf(fp1,"%d,%[^,],%[^,],%d,%[^,],%[^,]",&s[i].numbers,s[i].name,s[i].sex,&s[i].birth,s[i].classes,s[i].phone);
            for(a=0;a<5;a++)
            {
                fscanf(fp1,",%d",&s[i].score[a]);
                
            }
            
            i++;
        }
        
        fclose(fp1);
        
    }
    j=i;
    for(i=0;i<j;i++)
    {
        s[i].min=s[i].score[0];
        s[i].max=s[i].score[0];
        
    }
    
    
    for(i=0;i<j;i++)
    {
        for(a=0;a<5;a++)
        {
            if(s[i].score[a]<s[i].min)
            {
                s[i].min=s[i].score[a];
            }
            if(s[i].score[a]>s[i].max)
            {
                s[i].max=s[i].score[a];
            }
        }
    }
    
    
    j=i;
    for(i=0;i<j;i++)
    {
        s[i].average=(s[i].score[0]+s[i].score[1]+s[i].score[2]+s[i].score[3]+s[i].score[4]-s[i].min-s[i].max)/3;
    }
    //printf("%d",s[1].average);
    fp2=fopen("/Users/s20171105121/Desktop/studentdata1.csv","w");
    fprintf(fp2,"%s,average",bt);
    printf("%s,average",bt);
    i=0;
    while(i<j)
    {
        fprintf(fp2,"%d,%s,%s,%d,%s,%s",
                s[i].numbers,s[i].name,s[i].sex,s[i].birth,s[i].classes,
                s[i].phone);
        printf("%d,%s,%s,%d,%s,%s",
               s[i].numbers,s[i].name,s[i].sex,s[i].birth,s[i].classes,
               s[i].phone);
        for(a=0;a<5;a++)
        {
            fprintf(fp2,",%d",s[i].score[a]);
            printf(",%d",s[i].score[a]);
        }
        fprintf(fp2,",%d",s[i].average);
        fprintf(fp2,"\n");
        printf(",%d",s[i].average);
        printf(fp2,"\n");
        
        i++;
    }
    fclose(fp2);
    
    return 0;
}
