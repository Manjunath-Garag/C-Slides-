/*
   man gettimeofday
   man localtime
 */

#include<stdio.h>
#include<sys/time.h>	//structure would be declared in the .h file
#include<time.h>

int main()
{

	struct timeval tv;	//we are creating an Object for the Structure. man gettimeofday and see the structure.

	//struct tm *localtime(const time_t *timep);
	struct tm *cur_time;	//man local time.

	gettimeofday(&tv,NULL);	//this will return a time.
	//printf("%d\n",gettimeofday(&tv,NULL) );	

	cur_time = localtime(&tv.tv_sec);	//for this function we take the seconds part from the above OUTPUT line13.(STRUCTURE ATTRIBUTE:tv_sec) and pass the parameter to localtime, (the local time will return a Big number, that would be retrived in the below Printf Statement)

	printf("%d:%d:%d\n",cur_time->tm_hour, cur_time->tm_min, cur_time->tm_sec);

	return;

}
