#include"Queue.h"

void main()
{
	SeqQueue Q;
	SeqQueueInit(&Q, 0);
	SeqQueueEn(&Q, 1);
	SeqQueueEn(&Q, 3);
	SeqQueueEn(&Q, 5);
	SeqQueueEn(&Q, 4);
	SeqQueueEn(&Q, 2);
	SeqQueueEn(&Q, 6);
	SeqQueueEn(&Q, 7);
	SeqQueueEn(&Q, 8);

	SeqQueueEn(&Q, 20);

	SeqQueueDe(&Q);
	SeqQueueEn(&Q, 20);
	SeqQueueDe(&Q);
	SeqQueueEn(&Q, 30);
	SeqQueueShow(&Q);

}


//void main()
//{
//	SeqQueue Q;
//	SeqQueueInit(&Q, 0);
//	SeqQueueEn(&Q, 1);
//	SeqQueueEn(&Q, 3);
//	SeqQueueEn(&Q, 5);
//	SeqQueueEn(&Q, 4);
//	SeqQueueEn(&Q, 2);
//	SeqQueueShow(&Q);
//	printf("====================\n");
//	SeqQueueDe(&Q);
//	SeqQueueShow(&Q);
//	int val = SeqQueueBack(&Q);
//	printf("back val = %d\n", val);
//	val = SeqQueueFront(&Q);
//	printf("front val = %d\n", val);
//	SeqQueueEn(&Q, 100);
//	val = SeqQueueBack(&Q);
//	printf("back val = %d\n", val);
//	val = SeqQueueFront(&Q);
//	printf("front val = %d\n", val);
//}
//
//void main()
//{
//	LinkQueue Q;
//	LinkQueueInit(&Q);
//	LinkQueueEn(&Q, 1);
//	LinkQueueEn(&Q, 2);
//	LinkQueueEn(&Q, 3);
//	LinkQueueEn(&Q, 4);
//	LinkQueueEn(&Q, 15);
//	LinkQueueEn(&Q, 6);
//	LinkQueueShow(&Q);
//	printf("==============\n");
//
//	QueueElemType val = LinkQueueFront(&Q);
//	LinkQueueDe(&Q);
//	printf("%d ³ö¶Ó.\n", val);
//	LinkQueueDestroy(&Q);
//}
