#include<stdio.h>
#include<signal.h>
#include<unistd.h>

snooze_alarm(set)
{
	alarm(set);
}

void handler(int arg)
{
	if(arg==SIGALRM)
	{
		printf("Alarm Occured\n");
	}
}

int main()
{
	int set=10;
	snooze_alarm(set);
	signal(SIGALRM, handler);
	while(1)
	{
		pause();
		printf("1:Alarm snooze\n 2:exit\n");
		if(getchar() == '1')
			snooze_alarm(set);
		else
			break;
	}

}

