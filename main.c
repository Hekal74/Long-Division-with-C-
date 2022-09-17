#include <stdio.h>

int i,j,degree_num,degree_den, shifter;
double cofficient_num[50], cofficient_den[50], result[50],temp[50];

void InputData()
{
    printf("Numerator Degree :");
    scanf("%d",&degree_num);
    for (i=0;i<degree_num;i++)
    {
        printf("Coeffecient of x^%d : ",degree_num-i);
        scanf("%lf",&cofficient_num[i]);
    }
    printf("Constant term :");
    scanf("%lf",&cofficient_num[i]);

    printf("Denominator degree :");
    scanf("%d",&degree_den);
    for (i=0;i<degree_den;i++)
    {
        printf("Coeffecient of x^%d : ",degree_den-i);
        scanf("%lf",&cofficient_den[i]);
    }
    printf("Constant term :");
    scanf("%lf",&cofficient_den[i]);
}

void division ()
{
    shifter = degree_num;
    if (degree_num >= degree_den)
    {
        for (j=0; j<=degree_num; j++)
        {
            if (degree_num-j >= degree_den)
            {
                result[j] = cofficient_num[0]/cofficient_den[0];
                for (i=0;i<=degree_den;i++)
                {
                    temp[i] = result[j] * cofficient_den[i];
                    cofficient_num[i] = cofficient_num[i] - temp[i];
                }
                shifter--;
                for (i=0; i<=shifter; i++)
                    cofficient_num[i] = cofficient_num[i+1];
            }
        }
    }
}


void printing()
{
    printf("The Result is: ");
    for (i=0; i<=degree_num-1; i++)
    {
        if (i==0 && degree_num-degree_den-i >= 0)
        {
            if (result[i]>0)
            {
                if (result[i] == 1)
                {
                    if (degree_num - degree_den - i == 0)
                        printf(" %0.2lf ",result[i]);
                    else if (degree_num - degree_den - i == 1)
                        printf(" x ");
                    else
                        printf(" x^%d ",degree_num - degree_den - i);
                }
                else
                {
                    if (degree_num-degree_den-i==0)
                        printf(" %0.2lf ",result[i]);
                    else if (degree_num-degree_den-i==1)
                        printf(" %0.2lfx ",result[i]);
                    else
                        printf(" %0.2lfx^%d ",result[i],degree_num-degree_den-i);
                }
            }
            else if (result[i]<0)
            {
                if(result[i] == -1)
                {
                    if (degree_num-degree_den-i==0)
                        printf("- %0.2lf ",result[i]);
                    else if (degree_num-degree_den-i==1)
                        printf("- x ");
                    else
                        printf("- x^%d ",degree_num-degree_den-i);
                }
                else
                {
                    if (degree_num-degree_den-i==0)
                        printf("- %0.2lf ",-result[i]);
                    else if (degree_num-degree_den-i==1)
                        printf("- %0.2lfx ",-result[i]);
                    else
                        printf("- %0.2lfx^%d ",-result[i],degree_num-degree_den-i);
                }
            }
        }

        else if (i>0 && degree_num-degree_den-i >= 0)
        {
            if (result[i]>0)
            {
                if (result[i] == 1)
                {
                    if (degree_num-degree_den-i==0)
                        printf("+ %0.2lf ",result[i]);
                    else if (degree_num-degree_den-i==1)
                        printf("+ x ");
                    else
                        printf("+ x^%d ",degree_num-degree_den-i);
                }
                else
                {
                    if (degree_num-degree_den-i==0)
                        printf("+ %0.2lf ",result[i]);
                    else if (degree_num-degree_den-i==1)
                        printf("+ %0.2lfx ",result[i]);
                    else
                        printf("+ %0.2lfx^%d ",result[i],degree_num-degree_den-i);
                }
            }
            else if (result[i]<0)
            {
                if(result[i] == -1)
                {
                    if (degree_num-degree_den-i==0)
                        printf("- %0.2lf ",result[i]);
                    else if (degree_num-degree_den-i==1)
                        printf("- x ");
                    else
                        printf("- x^%d ",degree_num-degree_den-i);
                }
                else
                {
                    if (degree_num-degree_den-i==0)
                        printf("- %0.2lf ",-result[i]);
                    else if (degree_num-degree_den-i==1)
                        printf("- %0.2lfx ",-result[i]);
                    else
                        printf("- %0.2lfx^%d ",-result[i],degree_num-degree_den-i);
                }
            }
        }
    }

    if (shifter >= 0 && cofficient_num[0] != 0)
    {
        if (degree_num>=degree_den)
            printf("+ (");
        else
            printf("(");
        for (i=0;i<=shifter;i++)
        {
            if (i==0)
            {
                if(cofficient_num[i]>0)
                {
                    if (cofficient_num[i]==1)
                    {
                        if (shifter-i==0)
                            printf(" %0.2lf ",cofficient_num[i]);
                        else if (shifter-i==1)
                            printf(" x ");
                        else
                            printf(" x^%d ",shifter-i);
                    }
                    else
                    {
                        if (shifter-i==0)
                            printf(" %0.2lf ",cofficient_num[i]);
                        else if (shifter-i==1)
                            printf(" %0.2lfx ",cofficient_num[i]);
                        else
                            printf(" %0.2lfx^%d ",cofficient_num[i],shifter-i);
                    }
                }
                else if (cofficient_num[i]<0)
                {
                    if (cofficient_num[i]==-1)
                    {
                        if (shifter-i==0)
                            printf("- %0.2lf ",-cofficient_num[i]);
                        else if (shifter-i==1)
                            printf("- x ");
                        else
                            printf("- x^%d ",shifter-i);
                    }
                    else
                    {
                        if (shifter-i==0)
                            printf("- %0.2lf ",-cofficient_num[i]);
                        else if (shifter-i==1)
                            printf("- %0.2lfx ",-cofficient_num[i]);
                        else
                            printf("- %0.2lfx^%d ",-cofficient_num[i],shifter-i);
                    }
                }
            }
            else
            {
                if(cofficient_num[i]>0)
                {
                    if (cofficient_num[i]==1)
                    {
                        if (shifter-i==0)
                            printf("+ %0.2lf ",cofficient_num[i]);
                        else if (shifter-i==1)
                            printf("+ x ");
                        else
                            printf("+ x^%d ",shifter-i);
                    }
                    else
                    {
                        if (shifter-i==0)
                            printf("+ %0.2lf ",cofficient_num[i]);
                        else if (shifter-i==1)
                            printf("+ %0.2lfx ",cofficient_num[i]);
                        else
                            printf("+ %0.2lfx^%d ",cofficient_num[i],shifter-i);
                    }
                }
                else if (cofficient_num[i]<0)
                {
                    if (cofficient_num[i]==-1)
                    {
                        if (shifter-i==0)
                            printf("- %0.2lf ",-cofficient_num[i]);
                        else if (shifter-i==1)
                            printf("- x ");
                        else
                            printf("- x^%d ",shifter-i);
                    }
                    else
                    {
                        if (shifter-i==0)
                            printf("- %0.2lf ",-cofficient_num[i]);
                        else if (shifter-i==1)
                            printf("- %0.2lfx ",-cofficient_num[i]);
                        else
                            printf("- %0.2lfx^%d ",-cofficient_num[i],shifter-i);
                    }
                }
            }
        }
        printf(")/(");
        for (i=0;i<=degree_den;i++)
        {
            if (i==0)
            {
                if(cofficient_den[i]>0)
                {
                    if (cofficient_den[i] == 1)
                    {
                        if (degree_den-i==0)
                            printf(" %0.2lf ",cofficient_den[i]);
                        else if (degree_den-i==1)
                            printf(" x ");
                        else
                            printf(" x^%d ",degree_den-i);
                    }
                    else
                    {
                        if (degree_den-i==0)
                            printf(" %0.2lf ",cofficient_den[i]);
                        else if (degree_den-i==1)
                            printf(" %0.2lfx ",cofficient_den[i]);
                        else
                            printf(" %0.2lfx^%d ",cofficient_den[i],degree_den-i);
                    }
                }
                else if (cofficient_den[i]<0)
                {
                    if (cofficient_den[i] == -1)
                    {
                        if (degree_den-i==0)
                            printf("- %0.2lf ",-cofficient_den[i]);
                        else if (degree_den-i==1)
                            printf("- x ");
                        else
                            printf("- x^%d ",degree_den-i);
                    }
                    else
                    {
                        if (degree_den-i==0)
                            printf("- %0.2lf ",-cofficient_den[i]);
                        else if (degree_den-i==1)
                            printf("- %0.2lfx ",-cofficient_den[i]);
                        else
                            printf("- %0.2lfx^%d ",-cofficient_den[i],degree_den-i);
                    }
                }
            }
            else
            {
                if(cofficient_den[i]>0)
                {
                    if(cofficient_den[i]==1)
                    {
                        if (degree_den-i==0)
                            printf("+ %0.2lf ",cofficient_den[i]);
                        else if (degree_den-i==1)
                            printf("+ x ");
                        else
                            printf("+ x^%d ",degree_den-i);
                    }
                    else
                    {
                        if (degree_den-i==0)
                            printf("+ %0.2lf ",cofficient_den[i]);
                        else if (degree_den-i==1)
                            printf("+ %0.2lfx ",cofficient_den[i]);
                        else
                            printf("+ %0.2lfx^%d ",cofficient_den[i],degree_den-i);
                    }
                }
                else if (cofficient_den[i]<0)
                {
                    if (cofficient_den[i] == -1)
                    {
                        if (degree_den-i==0)
                            printf("- %0.2lf ", -cofficient_den[i]);
                        else if (degree_den-i==1)
                            printf("- x ");
                        else
                            printf("- x^%d ",degree_den-i);
                    }
                    else
                    {
                        if (degree_den-i==0)
                            printf("- %0.2lf ",-cofficient_den[i]);
                        else if (degree_den-i==1)
                            printf("- %0.2lfx ",-cofficient_den[i]);
                        else
                            printf("- %0.2lfx^%d ",-cofficient_den[i],degree_den-i);
                    }
                }
            }
        }
        printf(")\n");
    }
    else
        printf("\n");
}

int main()
{
    InputData();
    division();
    printing();
}

