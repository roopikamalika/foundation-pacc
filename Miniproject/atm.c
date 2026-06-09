#include <stdio.h>

int main()
{
    int choice;
    float balance = 10000, amount;
    float min_balance = 5000;

    while(1)
    {
        printf("\n===== KVB ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Current Balance = Rs. %.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);

                if(amount > 0)
                {
                    balance += amount;
                    printf("Deposit Successful!\n");
                    printf("Updated Balance = Rs. %.2f\n", balance);
                }
                else
                {
                    printf("Invalid Amount!\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);

                if(amount > 0)
                {
                    if(balance - amount >= min_balance)
                    {
                        balance -= amount;
                        printf("Withdrawal Successful!\n");
                        printf("Remaining Balance = Rs. %.2f\n", balance);
                    }
                    else
                    {
                        printf("Minimum balance of Rs. 5000 must be maintained!\n");
                    }
                }
                else
                {
                    printf("Invalid Amount!\n");
                }
                break;

            case 4:
                printf("Thank You for Using KVB ATM!\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}