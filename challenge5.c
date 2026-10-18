#include<stdio.h>
#include<math.h>
int main()
{
    int choice,num,step,ans;
    float a,b,c,d,x,root1,root2;
    while(choice != 4)
    {
        printf("\n1st one is Linear Equation \n");
        printf("2nd one is finding the Factorial \n");
        printf("3rd one is Quadratic Equation \n");
        printf("4th one is Now you are allowed to exit or go out \n");
        printf("\nselect between(1-4) choice \n");
        printf("\n____________________________________________________________\n");
        printf("Select any of the above options = ");
        scanf("%d",&choice);
        printf("____________________________________________________________\n");
        if(choice == 1)
        {
            printf(" enter the values of a and b  of eq. (ax+b=0) = ");
            scanf("%f %f",&a ,&b);
            printf("____________________________________________________________\n");
            if(a==0)
            {
                if(b==0)
                {
                    printf("infinitely many solutions exist \n");
                }
                else
                    printf("no solutions exist \n");
            }
            else
            {
                x = -b / a;
                printf("a unique solution exists \n");
                printf("The value of x = %f\n",x);
            }
        }
        else if(choice == 2)
        {
            printf("select and enter a number between (1-12) to find the factorial = ");
            scanf("%d",&num);
            printf("____________________________________________________________\n");
            if(num > 12 || num < 0)
            {
                printf("Enter a number between(1-12) ");
            }
            else
            {
                ans = 1;
                for(step = 1;step <=num ;step++)
                {
                    ans = ans*step;
                }
                printf("%d! = %d\n",num,ans);
            }
        }
        else if(choice == 3)
        {
            printf("Enter the values of a,b,c of the quadratic eq. ");
            scanf("%f %f %f",&a, &b, &c);
            printf("______________________________________\n");
            if (a == 0)
            {
                printf("not a quadratic equation \n");
            }
            else
            {
                d= b * b - 4 * a * c;
                if(d > 0)
                {
                    root1 = (-b + sqrt(d))/(2*a);
                    root2 = (-b - sqrt(d))/(2*a);
                    printf("The two real and distinct roots are = %f and %f \n", root1, root2);
                }
                else if (d == 0)
                {
                    root1 = -b/(2 * a);
                    printf("two equal and real roots= %f\n",root1);
                }
                else
                {
                    printf("no real roots exist \n");
                }
            }
        }
        else if(choice == 4)
        {
            printf("Thank you\n");
        }
        else
        {
            printf("invalid option selected\n select again \n");
        }
    }
    
}


