#include <stdio.h>
//#include <stdlib.h>
#define SWAP(X) ((((X)&0x55555555)<<1)+(((X)&0xaaaaaaaa)>>1))
//提取奇数位向左移动1位//提取偶数位向右移动1位
int main()
{
    int n = 11;
    int ret = SWAP(n);
    printf("ret = %d\n", ret);
   // system("pause");
    return 0;
}