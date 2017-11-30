#include<stdio.h>

int main()
{
int a=20;
{
int a=30; printf("%d\n",a);
}

{
int a=40; printf("%d\n",a);
}

printf("%d\n",a);
}
