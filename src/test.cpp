#include "des.h"
#include "base64.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//解密
int main(int argc,char **argv)
{
	if(argc < 2)
	{
		printf("%s sourefile\n",argv[0]);
		return -1;
	}
	
	char base64[1024] = {0};
	int fd ;
	
	//读文件
	fd = open(argv[1],O_RDWR,0660);
	read(fd,base64,sizeof(base64));
	printf("%s\n",base64);
	close(fd);
	
	//解base64
	char buf[1024] = {0};
	base64_decode(base64, buf);
	printf("buf = %s\n",buf);
	
	//des解密
	char dest[1024] = {0};
	DES_Decrypt_str(buf,"kaerkaer",dest);
	printf("%s\n",dest);

	return 0;
}


