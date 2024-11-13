#include <stdio.h>
#define N 10
typedef struct student
{
    int rno;
    char nm[15];
} STU;
STU k[N];
// modulo division method
int hash(int no)
{
    return no % N;
}
void insert(int no)
{
    int i = 0;
    int hval = hash(no);
    if (k[hval].rno == 0)
    {
        k[hval].rno = no;
        printf("\nName:");
        scanf("%s", k[hval].nm);
        printf("\nInsertion at home address");
        return;
    }
    printf("\nCollision occured");
    for (i = hval + 1; i < N; i++)
    {
        if (k[i].rno == 0)
        {
            k[i].rno = no;
            printf("\nName:");
            scanf("%s", k[i].nm);
            break;
        }
    }
    if (i < N)
    {
        printf("\nInsertion on collision path");
        return;
    }
    for (i = 0; i < hval; i++)
    {
        if (k[i].rno == 0)
        {
            k[i].rno = no;
            printf("\nName:");
            scanf("%s", k[i].nm);
            break;
        }
    }
    if (i == hval)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\nInsertion Successful");
    }
}
void search(int no)
{
    int i = 0;
    int hval = hash(no);
    if (k[hval].rno == no)
    {

        printf("\nName:");
        printf("%s", k[hval].nm);
        printf("\nfound at home address");
        return;
    }
    printf("\nCollision occured");
    for (i = hval + 1; i < N; i++)
    {
        if (k[i].rno == no)
        {

            printf("\nName:");
            printf("%s", k[i].nm);
            break;
        }
    }
    if (i < N)
    {
        printf("\nFound on collision path");
        return;
    }
    for (i = 0; i < hval; i++)
    {
        if (k[i].rno == no)
        {
            printf("\nName:");
            printf("%s", k[i].nm);
            break;
        }
    }
    if (i == hval)
    {
        printf("\nNot Found");
    }
    else
    {
        printf("\nFound on collision path");
    }
}
int main()
{
    int opt, no;
    while (1)
    {
        printf("\nMenu\n1.Insert\n2.Search\n3.Exit\nOption:");
        scanf("%d", &opt);
        if (opt > 2)
        {
            break;
        }
        printf("\nEnter roll no:");
        scanf("%d", &no);
        if (opt == 1)
        {
            insert(no);
        }
        else
        {
            search(no);
        }
    }

    return 0;
}