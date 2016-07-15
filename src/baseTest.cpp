#include "des.h"
#include "base64.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char* enkey = "kaerkaer";

int main(int argc,char ** argv)
{
	/*
	char enkey[] = 
	{
		0x2b, 0x7e, 0x15, 0x16, 
		0x28, 0xae, 0xd2, 0xa6
	};
	*/
	
	  char soure[1024] = {0};
		char dest[1024] = {0};
		char base64[1024] = {0};
		
		if(argc < 3)
		{
			printf("./%s seckey  destkey\n",argv[0]);
			return -1;
		}
		
		//读文件
		int fd = open(argv[1],O_RDWR,0660);
		read(fd,soure,sizeof(soure));
		printf("%s\n",soure);
		printf("fd = %d\n",fd);
		close(fd);
		
		
		//des加密
		DES_Encrypt_str(soure,enkey,dest);
		printf("dest = %s\n",dest);
		
		//base64编码
		int len = strlen(dest);
        base64_encode(dest,base64,178); 
		printf("write base = %s\n",base64);
		
		
		//保存文件
		fd = open(argv[2],O_CREAT | O_RDWR,0660);
		write(fd,base64,strlen(base64));
		printf("fd = %d\n",fd);
		close(fd);
		
		//读取文件
		memset(base64,'\0',1024);
		fd = open(argv[2],O_RDWR,0660);
		read(fd,base64,sizeof(base64));
		printf("read base = %s\n",base64);
		printf("fd = %d\n",fd);
		close(fd);
		
		//base64解密
		char buf[1024] = {0};
		base64_decode(base64, buf);
		printf("buf = %s\n",buf);
		
		//des解密
		memset(soure,'\0',1024);
		printf("1 soure = %s\n",soure);
		DES_Decrypt_str(buf,enkey,soure);
		printf("2 soure = %s\n",soure);
		
		char *str = strtok(soure,"\n");
		printf("str = %s\n",str);
		str = strtok(NULL,"\n");
		printf("str = %s\n",str);

		for(int i = 0; (str = strtok(NULL,"\n")); ++i)
		{
			printf("str = %s\n",str);
		}
		
		int c;
		do{
			c = fgetc(stdin);
		} while (c != '\n' && c != EOF);
		
		return 0;
}
