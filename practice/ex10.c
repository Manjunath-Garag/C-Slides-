
#include<stdio.h>

int main()
{
	int a,b,c,d;

	 printf("here: %d\n",printf("%d %d %d %d",a,b,c,d));
	   printf("here: %d\n",printf("Hello"));
	   printf("%o\n",8);
	   printf("%o\n",15);
	   printf("%o\n",24);
	   printf("%o\n",31);
	   printf("%x\n",16);
	   printf("%x\n",48); 
printf("%hX\n", 0xFFFFFFFF);
printf("%hhX\n", 0xFFFFFFFF);
printf("%3d %3.2d\n", 199, 1);
//scanf("%3d",&a);

printf("%d%%\n",81);

printf("%*d\n", 1, 1);
printf("%*d\n", 2, 100);
printf("%*d\n", 5, 123456);
printf("%0.3f\n", 1.0);
printf("%1.30f\n", 1.0);
printf("hello\rhi this is\r emertxe\n");
printf("hello\rhi this is\b emertxe\n");
printf("Hello \f world \f");
printf("Hello\eworld\ehii");

printf(" HI\"Hello World\"");

int num1 = 123;
printf("%+06d\n", num1);//total lenght is 6 along with "+"
//printf("%*06d\n", num1);//total lenght is 6 along with "-"

float num2 = 1;
char string[] = "Hello world";
printf("%.2f %10.5s\n", num2, string);
printf("%.2f %.5s\n", num2, string);

int ret = printf("%s\n","Hello");//takes null
printf("%d\n",ret);

int ret1 = scanf("%d %d", &b,&d);
printf("ret 1 :%d\n",ret1);
}


