// print next prime number

#include<stdio.h>
int input_collector();
int validity_checker(int);
void prime_finder(int);


int validity_checker(int t)
{
    if(t>=2 && t<=10000) return 1;
    else return 0;
}

void main()
{
    int x;
    x = input_collector();
    if(validity_checker(x))
    {
        prime_finder(x);
    }
    else
    {
        printf("You have entered an invalid number.");
        exit(0);
    }
}

void prime_finder(int num)
{
    int flag=0,n,temp, match=0;
    temp = num+1;
    while(match==0)
    {
        flag=0;
        for(n=2; n<=sqrt(temp); n++)
        {
            if(temp%n==0)
            {
                flag =1;
                break;
            }
        }
        if(flag==0)
        {
            printf("Next Prime number is: %d", temp);
            match++;
            break;
        }
        else
        {
           // printf("One.\n");
            temp++;
        }
    }

}

int input_collector()
{
    int number;
    printf("Enter a number:");
    scanf("%d", &number);
    return number;
}