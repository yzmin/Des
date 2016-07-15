#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


#ifndef BASE64_H
#define BASE64_H

#ifdef __cplusplus
extern "C" {
#endif

char* base64_encode(char * bindata, char * base64, int binlength);
int base64_decode(char * base64, char * bindata);

#ifdef __cplusplus
}
#endif

#endif /* BASE64_H */