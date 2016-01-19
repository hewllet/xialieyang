#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#define body 0  
#define remove 1
#define create 2
#define Move Sleep(300); Paint(remove)
#define malloc_elem (Element*)malloc(sizeof(Element))
typedef struct Element{
	int posx; int posy;
	struct Element *next;
	struct Element *prv;
}Element;
Element* snake = malloc_elem, *food=malloc_elem,*tail=malloc_elem;
void Gotoxy(int x,int y){
	COORD pos; pos.X = x; pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Paint(int no){
	Element *p = snake;
		if (no == body){
			Gotoxy(p->posx, p->posy); printf("@");
			while (p->next != snake)
				p = p->next; Gotoxy(p->posx, p->posy); printf("@");
		}
		else if (no == remove){ Gotoxy(tail->posx, tail->posy); printf(" "); }
		tail->posx = p->posx; tail->posy = p->posy;
}
void Randomxy(int *x,int *y){
	srand((unsigned)time(NULL));
	*x = rand() % 40; *y = rand() % 20;
}
void CreateFood(){
	Randomxy(&food->posx, &food->posy);
	while (snake->posx == food->posx && snake->posy == food->posy)
		Randomxy(&food->posx, &food->posy);
	Gotoxy(food->posx, food->posy); printf("*");
}
void CreateNode(){
	Element *node = (Element*)malloc(sizeof(Element));
	tail->next = node; node->prv = tail; node->next = snake; snake->prv = node;
	node->posx = tail->next->posx; node->posy = tail->next->posy - 1; tail = node;
}
int IsEat(){
	if (snake->posx == food->posx&&snake->posy == food->posy) return 1;
	else return 0;
}
void Init(){
	char kb = 's', default_kb = 's';
	Randomxy(&snake->posx, &snake->posy);
	snake->next = snake; snake->prv = snake;	tail = snake;//构成循环
	Paint(body); CreateFood();
	while (1){
		if (kbhit())kb = getch(); if (kb < 97) kb += 32;
		switch (kb){
		case'w': if (default_kb != 's'){ Move; tail->posy--; }else kb = default_kb; break;
		case 's':if (default_kb != 'w') { Move; tail->posy++; }else kb = default_kb; break;
		case'a':  if (default_kb != 'd') { Move; tail->posx--; }else kb = default_kb; break;
		case'd':  if (default_kb != 'a'){ Move; tail->posx++; }else  kb = default_kb; break;
		}	
		default_kb = kb; snake = tail;  tail = tail->prv; //新的头结点,要一个节点标记蛇身最后一个	
		if (IsEat()) {CreateFood(); CreateNode(); Paint(create);}
		Paint(body);
	}
}
int main(){
	Init();
	return 0;
}
