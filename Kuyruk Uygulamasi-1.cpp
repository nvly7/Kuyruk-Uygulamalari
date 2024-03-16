#include<stdio.h>

struct Queue{
	int data[100];
	int on;
	int ust;
	int arka;
};
void QueueBaslat(struct Queue*queue){
	queue->on=-1;
	queue->arka=-1;
}
int QueueDolu(struct Queue*queue){
	return (queue->arka+1)%100==queue->on;
}
int QueueBos(struct Queue*queue){
	return queue->on==-1;
}
int QueueFull(struct Queue*queue){
 	return queue->ust==100-1;
 }
void Enqueue(struct Queue*queue,int deger){
	if(QueueFull(queue)){
		printf("Queue dolu.\n");
		return;
	}
	if(QueueBos(queue)){
		queue->on=0;
		queue->arka=0;
	}
	else{
		queue->arka=(queue->arka+1)%100;
	}
	queue->data[queue->arka]=deger;
}
int dequeue(struct Queue*queue){
	if(QueueBos(queue)){
		printf("Queue bos.\n");
		return-1;
	}
	int deger=queue->data[queue->on];
	if(queue->on==queue->arka){
		queue->on=-1;
		queue->arka=-1;
	}
	else{
		queue->on=(queue->on+1)%100;
	}
	return deger;
}

struct Stack{
	int data[100];
	int ust;
};
 void StackBaslat(struct Stack* stack){
 	stack->ust=-1;
 }
 int StackFull(struct Stack*stack){
 	return stack->ust==100-1;
 }
 int StackBos(struct Stack*stack){
 	return stack->ust==-1;
 }
 void push(struct Stack*stack,int deger){
 	if(StackFull(stack)){
 		printf("Stack dolu.\n");
 		return;
	 }
	 stack->data[stack->ust-1];
 }
 

int main(){
	
	struct Queue queue;
	struct Stack stack;
	int secim;
	int deger;
	StackBaslat(&stack);
	QueueBaslat(&queue);
	
	while(1){
		printf("1.Stack Deger Cikar\n");
		printf("2.Queue Deger Cikar\n");
		printf("Seciminizi yapiniz:");
		scanf("%d",&secim);
		
		switch(secim){
			case 1:
				printf("Deger giriniz:");
				scanf("%d",&deger);
				push(&stack,deger);
				printf("Deger Satck e eklendi.\n");
				break;
			case 2:
				printf("Deger giriniz:");
				scanf("%d",&deger);
				Enqueue(&queue,deger);
				printf("Deger Queue eklendi.\n");
				break;
			default:printf("Gecersiz secim!");
			return 0;	
		}
		
	}
	return 0;
}
