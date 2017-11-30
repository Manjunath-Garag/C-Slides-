#include <stdio.h>
#include <ctype.h>
int main()
{
float ch;
for ( ; (ch = getchar()) != EOF; )
{
putchar(toupper(ch));
}
puts("EOF Received");
return 0;
}
