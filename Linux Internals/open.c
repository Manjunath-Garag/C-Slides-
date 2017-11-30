/*
man open man read man write

*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#define MAX 10

int main(int argc, char *argv[])
{
	int source_fd;
	int rd_ret;
	int wt_ret;
	char buff[10];
	//open file in read mode.
	source_fd = open(argv[1], O_RDONLY);//file_name or file_descriptor and 2nd parameter is Permission.
//open returns -1 if the files isn't avail or permission isn't granted.
	//checks for error.
	if(source_fd == -1)
	{
		perror("open");			// open:NO such file or Dir.
		return 1;
	}
	do
	{
		//reading MAX bytes from file.
		rd_ret = read(source_fd, buff, MAX);

			//checks for error
			if(rd_ret == -1)
			{
				perror("read");
				return 2;
			}
		//writin to stdout 1:is for FILE DESCRIPTOR STDOUT
		wt_ret = write(1, buff, rd_ret);	//writes to "1" from buff , 4 -bytes at a time.
		if(wt_ret == -1)
		{
			perror("write");
			return 3;
		}
	}while(rd_ret != 0); //do
}//main
