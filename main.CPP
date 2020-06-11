#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct list
{
char name[25];
int n;
struct list *next;
}list;
list *head;
FILE *fp;
void save_score()
{
fp=fopen("abc.txt","r");
char name[25];
int n;
list *temp,*temp1,*temp2;
while(fscanf(fp,"%s\t%d\n",name,&n)!=EOF)
{
temp=(list *)malloc(sizeof(list));
strcpy(temp->name,name);
temp->n=n;
temp->next=NULL;
if(head==NULL)
{
head=temp;
}
else
{
temp1=head;
while(temp1!=NULL)
{
temp2=temp1;
temp1=temp1->next;
}
temp2->next=temp;
}
}
list *p,*q;
for(p=head;p!=NULL;p=p->next)
{
for(q=p->next;q!=NULL;q=q->next)
{
int temp;
char ch[25];
if(p->n < q->n)
{
temp=p->n;
p->n=q->n;
q->n=temp;
strcpy(ch,p->name);
strcpy(p->name,q->name);
strcpy(q->name,ch);
}
}
}
fclose(fp);
}
void show()
{
save_score();
list *temp;
temp=head;
int i=0;
char n[10];
while(temp!=NULL)
{
outtextxy(100,160+10*i,temp->name);
itoa(temp->n,n,10);
outtextxy(180,160+10*i,n);
i++;
temp=temp->next;
}
}
void box(int);

void arrow1(int ,int);

void arrow2(int ,int);

void target1(int);

void target2(int);

void target3(int);

int hit(int ,int ,int,int *);

void game1();

void game2();

void game3();

void instruction();

void menu();

int total=0;
int score=0;
void main()
{
head=NULL;
int gd=DETECT,gm;
int ar=0;
char ca[25];
int ch;
char name[25];
initgraph ( &gd, &gm, "C:\\TC\\BGI" );
menu();
char choice;
choice=getch();
switch(choice)
{
case '1':
cleardevice();
printf("enter name");
gets(name);
for(ar=0;ar<6;ar++)
{
score=0;
cleardevice();
setbkcolor(YELLOW);
game1();
total=total+score;
itoa(total,ca,10);
cleardevice();
setbkcolor(YELLOW);
outtextxy(300,300,ca);
delay(2000);
}
if(total>80)
{
outtextxy(10,20,"level 2");
delay(5000);
for(ar=0;ar<5;ar++)
{score=0;
cleardevice();
setbkcolor(BLACK);
game2();
total=total+score;
itoa(total,ca,10);
cleardevice();
setbkcolor(BLACK);
outtextxy(300,300,ca);
delay(2000);
 }
if(total>250)
{
outtextxy(150,80,"level 3");
delay(5000);
for(ar=0;ar<5;ar++)
{score=0;
cleardevice();
setbkcolor(BLACK);
game3();
total=total+score;
itoa(total,ca,10);
cleardevice();
setbkcolor(BLACK);
outtextxy(300,300,ca);
delay(2000);
}
}
else
{outtextxy(250,250,"NOT QUALIFIED FOR LEVEL 3");
delay(10000);
getch();
}
 }
else
{
 outtextxy(250,250,"NOT QUALLIFIED FOR LEVEL 2");
 delay(10000);
 getch();
}
cleardevice();
fflush(stdout);
setbkcolor(YELLOW);
itoa(total,ca,10);
settextstyle(1, HORIZ_DIR, 10);
outtextxy(10,20,name);
outtextxy(100,200,ca);
fp=fopen("abc.txt","a+");
fprintf(fp,"%s\t%d\n",name,total);
fclose(fp);
getch();
break;

case '2':
cleardevice();
instruction();
getch();
break;

case '3':
cleardevice();
show();
getch();
break;

case '4':
exit(1);
}
closegraph();
}
void menu()
{
outtextxy(100,200,"1.play");
outtextxy(100,230,"2.instruction");
outtextxy(100,260,"3.highscore");
outtextxy(100,290,"4.exit");
}
void box(int a)
{
setcolor(4);
rectangle(60,140+a,140,150+a);
rectangle(60,150+a,75,170+a);
arc(75,150+a,270,0,12);
}
void arrow1(int i,int j)
{
setcolor(RED);
line(160+i*4,175+j,230+i*4,175+j);
}
void arrow2(int i, int j)
{setcolor(WHITE);
line(160+5*i*4,172+j,230+5*i*4,172+j);
}
 void arrow3(int i, int j)
{setcolor(RED);
line(160+7*i*4,172+j,230+7*i*4,172+j);
}
void target1(int a)
{
setcolor(RED);
circle(610,10+a%390,30);
circle(500,5+4*a%390,25);
circle(610,190+a%390,15);
circle(500,380-4*a%390,15);
circle(550,380-2*a%390,5);
}
void target2(int a)
{
 setcolor(YELLOW);
 circle(610,10+2*a%390,30);
 circle(500,5+4*a%390,25);
 circle(610,190+a%390,20);
 circle(550,380-5*a%(240+2*a),25);
}
void target3(int a)
{
 setcolor(YELLOW);
 circle(610,10+6*a%390,30);
 circle(500,5+4*a%390,25);
 circle(610,190+a%390,20);
 circle(550,380-5*a%(240+2*a),25);
 circle(550,10+5*a%390,30);
 circle(525,5+4*a%390,25);
 circle(570,190+a%390,20);
 circle(450,380-2*a%(240+2*a),25);
 }
int hit(int a,int b,int c,int *d)
{
int h=1;
if((230+a*4)>=610&&(230+a*4)<=640&&(175+b)>=(c%390-20)&&(175+b)<=(40+c%390)
|| (230+a*4)>=500 &&(230+a*4)<=525&&(175+b)>=(c%300-20)&&(175+b)<=(40+c%300)
|| (230+a*4)>=610 &&(230+a*4)<=625&&(175+b)>=(c%390-190)&&(175+b)<=(40+c%390))
{
*d=20;
h=0;
return h;
}
return h;
}
void game1()
{
int i,x=0,p=0,c=0;
char ch;
int t=1;
int h=1;
for(i=0;x<135&&h==1;i++)
{
cleardevice();
if(kbhit()&&c==0)
{
ch=getch();
fflush(stdin);
if(ch=='w'&&x==0)
{
p=p-10;
}
if(ch=='s'&&x==0)
{
p=p+10;
}
if(ch=='p'&&x==0)
{
t=0;
}
}
box(p);
if(ch=='d')
{
arrow1(x,p);
x++;
c=1;
}
if(t!=0)
{
target1(i);
}
else
{
i=i-1;
target1(i);
}
h=hit(x,p,i,&score);
delay(10);
}
}
void game2()
{
int i,x=0,p=0,c=0;
char ch;
int t=1;
int h=1;
for(i=0;x<135&&h==1;i++)
{
cleardevice();
if(kbhit()&&c==0)
{
ch=getch();
fflush(stdin);
if(ch=='w'&&x==0)
{
p=p-10;
}
if(ch=='s'&&x==0)
{
p=p+10;
}
if(ch=='p'&&x==0)
{
t=0;
}
}
box(p);
if(ch=='d')
{
arrow2(x,p);
x++;
c=1;
}
if(t!=0)
{
target2(i);
}
else
{
i=i-1;
target2(i);
}
h=hit(x,p,i,&score);
delay(10);
}
}
void game3()
{
int i,x=0,p=0,c=0;
char ch;
int t=1;
int h=1;
for(i=0;x<135&&h==1;i++)
{
cleardevice();
setbkcolor(BLACK);
if(kbhit()&&c==0)
{
ch=getch();
fflush(stdin);
if(ch=='w'&&x==0)
{
p=p-10;
}
if(ch=='s'&&x==0)
{
p=p+10;
}
if(ch=='p'&&x==0)
{
t=0;
}
}
box(p);
if(ch=='d')
{
arrow3(x,p);
x++;
c=1;
}
if(t!=0)
{
target3(i);
}
else
{
i=i-1;
target3(i);
}
h=hit(x,p,i,&score);
delay(10);
}
}
void instruction()
{
outtextxy(20,40,"				    INSTRUCTIONS                       ");
outtextxy(20,70,"(1)use letter 'W' to move the shooter above the screen.");
outtextxy(20,90,"(2)use letter 'D' to shoot the arrow.");
outtextxy(20,110,"(3)use letter 'S' to move the shooter down the screen.");
outtextxy(20,130,"				 SPECIAL POP-UPS                       ");
outtextxy(20,150,"(4)use letter 'P' to stop the target.");
outtextxy(20,170,"(5)after every hit the score will increase by 20.");
outtextxy(20,190,"(6)NAME OF PLAYER with his score will be displayed at last.");
}
