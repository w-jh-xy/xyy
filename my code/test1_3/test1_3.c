#include <stdio.h>
//#include <stdlib.h>
#define SWAP(X) ((((X)&0x55555555)<<1)+(((X)&0xaaaaaaaa)>>1))
//��ȡ����λ�����ƶ�1λ//��ȡż��λ�����ƶ�1λ
int main()
{
    int n = 11;
    int ret = SWAP(n);
    printf("ret = %d\n", ret);
   // system("pause");
    return 0;
}