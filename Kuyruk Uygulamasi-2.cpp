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
 int pop(Stack* stack) {
    if (StackBos(stack)) {
        printf("Stack bos.\n");
        return -1;
    }

    return stack->data[stack->ust--];
}
 
 void Ekle(Stack* stack, Queue* queue) {
    int deger;
    printf("Eklemek istediðiniz deðeri girin: ");
    scanf("%d", &deger);

    push(stack, deger);
    Enqueue(queue, deger);
}

void BulveSil(Stack* stack, Queue* queue) {
    int deger;
    printf("Silmek istediginiz degeri giriniz: ");
    scanf("%d", &deger);
    
    int stackbulundu = 0;
    int queuebulundu = 0;

    Stack tempStack;
    StackBaslat(&tempStack);

    while (!StackBos(stack)) {
        int tempDeger = pop(stack);
        if (tempDeger == deger) {
            stackbulundu = 1;
        } else {
            push(&tempStack, tempDeger);
        }
    }

    while (!StackBos(&tempStack)) {
        push(stack, pop(&tempStack));
    }
    Queue tempQueue;
    QueueBaslat(&tempQueue);
    
    while (!QueueBos(queue)) {
        int tempDeger = dequeue(queue);
        if (tempDeger == deger) {
            queuebulundu = 1;
        } else {
            Enqueue(&tempQueue, tempDeger);
        }
    }
    while (!QueueBos(&tempQueue)) {
        Enqueue(queue, dequeue(&tempQueue));
    }

    if (stackbulundu && queuebulundu) {
        printf("Deger Stack ve Queue bulundu ve silindi.\n");
    } else if (stackbulundu) {
        printf("Deger Stack bulundu ve silindi.\n");
    } else if (queuebulundu) {
        printf("Deger Queue bulundu ve silindi.\n");
    } else {
        printf("Deger bulunamadý.\n");
    }
}

void BulveGoster(Stack* stack, Queue* queue) {
    int deger;
    printf("Gostermek istediginiz degeri giriniz: ");
    scanf("%d", &deger);
    int stackbulundu=0;
    int queuebulundu=0;

    Stack tempStack;
    StackBaslat(&tempStack);

    while (!StackBos(stack)) {
        int tempdeger = pop(stack);
        if (tempdeger ==deger) {
            stackbulundu=1;
            printf("Deger Stack de bulundu.\n");
        }
        push(&tempStack, tempdeger);
    }
    while (!StackBos(&tempStack)) {
        push(stack, pop(&tempStack));
    }

    Queue tempQueue;
    QueueBaslat(&tempQueue);

    while (!QueueBos(queue)) {
        int tempdeger = dequeue(queue);
        if (tempdeger == deger) {
            queuebulundu= 1;
            printf("Deger queue de bulundu.\n");
        }
        Enqueue(&tempQueue, tempdeger);
    }
    while (!QueueBos(&tempQueue)) {
        Enqueue(queue, dequeue(&tempQueue));
    }
    if (!stackbulundu && !queuebulundu) {
        printf("Deger bulunamadý.\n");
    }
}

void TumunuListele(Stack* stack, Queue* queue) {
    printf("Stack:\n");
    if (StackBos(stack)) {
        printf("Bos.\n");
    } else {
        Stack tempStack;
        StackBaslat(&tempStack);
        while (!StackBos(stack)) {
            int deger= pop(stack);
            printf("%d",deger);
            push(&tempStack,deger);
        }
        while (!StackBos(&tempStack)) {
            push(stack, pop(&tempStack));
        }
        printf("\n");
    }

    printf("Queue:\n");
    if (QueueBos(queue)) {
        printf("Bos.\n");
    } else {
        Queue tempQueue;
        QueueBaslat(&tempQueue);
        while (!QueueBos(queue)) {
            int deger=dequeue(queue);
            printf("%d",deger);
            Enqueue(&tempQueue,deger);
        }
        while (!QueueBos(&tempQueue)) {
            Enqueue(queue, dequeue(&tempQueue));
        }
        printf("\n");
    }
}

int main() {
    Stack stack;
    Queue queue;
    int secim;

    StackBaslat(&stack);
    QueueBaslat(&queue);

    while (1) {
        printf("Islem seciniz:\n");
        printf("1.Ekle\n");
        printf("2.Bul ve Sil\n");
        printf("3.Bul ve Goster\n");
        printf("4.Tumunu Listele\n");
        printf("5.Cikis\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                Ekle(&stack, &queue);
                break;
            case 2:
                BulveSil(&stack, &queue);
                break;
            case 3:
                BulveGoster(&stack, &queue);
                break;
            case 4:
                TumunuListele(&stack, &queue);
                break;
            case 5:
                printf("Programdan cikiliyor.\n");
                return 0;
            default:
                printf("Gecersiz secim!\n");
                break;
        }
        printf("\n");
    }

    return 0;
}

