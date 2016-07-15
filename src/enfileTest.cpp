#include "des.h"
#include "base64.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
	if(argc < 4)
	{
		printf("./enfile seckey enkey dekey\n");
		return -1;
	}	
	printf("开始加密!\n");
	DES_Encrypt(argv[1],"12345678",argv[2]);
	printf("加密完成！\n");	
	DES_Decrypt(argv[2],"12345678",argv[3]);
	printf("解密完成!\n");

	return 0;
}
