#ifndef __ACGBWRUNTIME_MD5_H__
#define __ACGBWRUNTIME_MD5_H__

///////////////////////////////////////////////////////////////////////////
// MD5 加密算法
#ifndef POINTER
typedef unsigned char *POINTER; 
#endif // POINTER

#ifndef UINT2
typedef unsigned short int UINT2; 
#endif // UINT2

#ifndef UINT4
typedef unsigned long int UINT4; 
#endif // UINT4

typedef struct
{
	UINT4 state[4]; 
	UINT4 count[2]; 
	unsigned char buffer[64]; 
} MD5_CTX; 

void MD5Init(MD5_CTX *); 
void MD5Update(MD5_CTX *, unsigned char *, unsigned int); 
void MD5Final(unsigned char [16], MD5_CTX *); 

// 将字符串编码为16个字节的二进制码
void MD5_Encode(char *inBuf, unsigned char outBuf[16]);

// 将由MD5_Encode函数生成的16个字节的二进制码转换成32个字节的字符串(第个字节转换为两位)
void MD5_ToString(unsigned char inBuf[16], char outBuf[33]);

// MD5_ToString() 函数的互逆函数
void MD5_ToCode(char inBuf[33], unsigned char outBuf[16]);

//MD5加密变成32字节,lpszTxt < 256
BOOL MakeMD5Txt32(LPCTSTR lpszTxt,CString &szMD5);//MD5加密变成32字节,lpszTxt < 256

///////////////////////////////////////////////////////////////////////////

#endif // end of __ACGBWRUNTIME_MD5_H__