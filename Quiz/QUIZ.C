/*
 *  Quiz Maker : This programm contains code for making Quiz, it will help  *
 * 		 u in making quiz as per ur requirement. Here Sample Quiz of*
 *	         Hex_to_Bin conversion is taken u can change as per ur      *
 *		 requirement.						    *
*/


//Quiz Maker

//Tested by hex2bin  quiz making
//Change Quiz as per ur question and answers...

#include <stdio.h>
#include <conio.h>
#include <windows.h>
//#include <wincon.h>
#include <graphics.h>

//int gdriver=DETECT, gmode;

void scorecard(int);//pass quizno.
void quizbox(int,int,int,int,int);
//void statusmsg(int);

int main(){
    int i;
    char ch;
     for(i=0;i<15;i++){
	if(ch==27)
	    exit(1);
	clrscr();
	textcolor(LIGHTGREEN);
	quizbox(28,1,50,3,2);
	gotoxy(30,2);
	textcolor(YELLOW);
	cprintf("***** QUIZ %d *****",i+1);   //Quiz No. currently executed

	quizbox(23,5,57,11,2);
	textcolor(LIGHTMAGENTA);
	switch(i){
	   //Here formating code is redundant u can make a function and call it
	   //each time...
	   case 0 :  gotoxy(29,6);
		     //Question 1
		     //Enter ur Question instead of "Find Hexadecimal to Binary?"
		     cprintf("Find Hexadecimal to Binary?");
		     gotoxy(29,7);
		     cprintf("For below Given Number!");
		     gotoxy(35,8);
		     cprintf(" %-8s","9.1A");
		     gotoxy(30,9);
		     cprintf("컴컴컴컴컴컴컴컴컴컴");
		     scorecard(i);  //For Testing Current Score
		     //This Comments will be followed to Rest of Questions...
		     //You can also increase or decrease questions...in quiz
		     break;
	   case 1 :  gotoxy(29,6);
		     cprintf("Find Hexadecimal to Binary?");
		     gotoxy(29,7);
		     cprintf("For below Given Number!");
		     gotoxy(35,8);
		     cprintf(" %-8s","BA4");
		     gotoxy(30,9);
		     cprintf("컴컴컴컴컴컴컴컴컴컴");
		     scorecard(i);
		     break;
	   case 2 :  gotoxy(29,6);
		     cprintf("Find Hexadecimal to Binary?");
		     gotoxy(29,7);
		     cprintf("For below Given Number!");
		     gotoxy(35,8);
		     cprintf(" %-8s","C8");
		     gotoxy(30,9);
		     cprintf("컴컴컴컴컴컴컴컴컴컴");
		     scorecard(i);
		     break;
	   case 3 :  gotoxy(29,6);
		     cprintf("Find Hexadecimal to Binary?");
		     gotoxy(29,7);
		     cprintf("For below Given Number!");
		     gotoxy(35,8);
		     cprintf(" %-8s","15");
		     gotoxy(30,9);
		     cprintf("컴컴컴컴컴컴컴컴컴컴");
		     scorecard(i);
		     break;
	   case 4 :  gotoxy(29,6);
		     cprintf("Find Hexadecimal to Binary?");
		     gotoxy(29,7);
		     cprintf("For below Given Number!");
		     gotoxy(35,8);
		     cprintf(" %-8s","D89F");
		     gotoxy(30,9);
		     cprintf("컴컴컴컴컴컴컴컴컴컴");
		     scorecard(i);
		     break;
	   case 5 :  gotoxy(29,6);
		     cprintf("Find Hexadecimal to Binary?");
		     gotoxy(29,7);
		     cprintf("For below Given Number!");
		     gotoxy(35,8);
		     cprintf(" %-8s","64AC");
		     gotoxy(30,9);
		     cprintf("컴컴컴컴컴컴컴컴컴컴");
		     scorecard(i);
		     break;
	   case 6 :  gotoxy(29,6);
		     cprintf("Find Hexadecimal to Binary?");
		     gotoxy(29,7);
		     cprintf("For below Given Number!");
		     gotoxy(35,8);
		     cprintf(" %-8s","9A6");
		     gotoxy(30,9);
		     cprintf("컴컴컴컴컴컴컴컴컴컴");
		     scorecard(i);
		     break;
	   case 7 :  gotoxy(29,6);
		     cprintf("Find Hexadecimal to Binary?");
		     gotoxy(29,7);
		     cprintf("For below Given Number!");
		     gotoxy(35,8);
		     cprintf(" %-8s","CDAC");
		     gotoxy(30,9);
		     cprintf("컴컴컴컴컴컴컴컴컴컴");
		     scorecard(i);
		     break;
	   case 8 :  gotoxy(29,6);
		     cprintf("Find Hexadecimal to Binary?");
		     gotoxy(29,7);
		     cprintf("For below Given Number!");
		     gotoxy(35,8);
		     cprintf(" %-8s","DEAF");
		     gotoxy(30,9);
		     cprintf("컴컴컴컴컴컴컴컴컴컴");
		     scorecard(i);
		     break;
	   case 9 :  gotoxy(29,6);
		     cprintf("Find Hexadecimal to Binary?");
		     gotoxy(29,7);
		     cprintf("For below Given Number!");
		     gotoxy(35,8);
		     cprintf(" %-8s","CAFE");
		     gotoxy(30,9);
		     cprintf("컴컴컴컴컴컴컴컴컴컴");
		     scorecard(i);
		     break;
	   case 10 :  gotoxy(29,6);
		     cprintf("Find Hexadecimal to Binary?");
		     gotoxy(29,7);
		     cprintf("For below Given Number!");
		     gotoxy(35,8);
		     cprintf(" %-8s","FADE");
		     gotoxy(30,9);
		     cprintf("컴컴컴컴컴컴컴컴컴컴");
		     scorecard(i);
		     break;
	   case 11:  gotoxy(29,6);
		     cprintf("Find Hexadecimal to Binary?");
		     gotoxy(29,7);
		     cprintf("For below Given Number!");
		     gotoxy(35,8);
		     cprintf(" %-8s","FEE");
		     gotoxy(30,9);
		     cprintf("컴컴컴컴컴컴컴컴컴컴");
		     scorecard(i);
		     break;
	   case 12 :  gotoxy(29,6);
		     cprintf("Find Hexadecimal to Binary?");
		     gotoxy(29,7);
		     cprintf("For below Given Number!");
		     gotoxy(35,8);
		     cprintf(" %-8s","5C");
		     gotoxy(30,9);
		     cprintf("컴컴컴컴컴컴컴컴컴컴");
		     scorecard(i);
		     break;
	   case 13 :  gotoxy(29,6);
		     cprintf("Find Hexadecimal to Binary?");
		     gotoxy(29,7);
		     cprintf("For below Given Number!");
		     gotoxy(35,8);
		     cprintf(" %-8s","FACE");
		     gotoxy(30,9);
		     cprintf("컴컴컴컴컴컴컴컴컴컴");
		     scorecard(i);
		     break;
	   case 14 :  gotoxy(29,6);
		     cprintf("Find Hexadecimal to Binary?");
		     gotoxy(29,7);
		     cprintf("For below Given Number!");
		     gotoxy(35,8);
		     cprintf(" %-8s","AEC");
		     gotoxy(30,9);
		     cprintf("컴컴컴컴컴컴컴컴컴컴");
		     scorecard(i);
		     break;
	   }
	   textcolor(LIGHTGRAY);
	   gotoxy(55,2);
	   cprintf("Escape to Return");
	   gotoxy(55,3);
	   cprintf("Any key to continue...");
	   flushall();
	   ch=getch();
	}
}


void scorecard(int quizno){
     static int right=0,wrong=0,totattempt=0,currentscore=0;
     char userans[25];

     //Enter answers of quiz respectively for all questions
     //In the below given...array
     //ans1          ans2           ans3      ans4      ans5   and so on....
     char quizans[15][25]={"1001.00011010","101110100100","11001000","10101","1101100010011111","110010010101100","100110100110","1100110110101100","1101111010101111","1100101011111110","1111101011011110","111111101110","1011100","1111101011001110","101011101100"};
     gotoxy(34,10);
     scanf("%s",&userans);
     strupr(userans);
     textcolor(DARKGRAY);
     quizbox(22,12,58,15,2);
     textcolor(LIGHTMAGENTA);
     if(strcmp(quizans[quizno],userans)==0){
	 right++;
	 textcolor(LIGHTGREEN + BLINK);
	 gotoxy(35,13);
	 cprintf("RIGHT!!!");
     }
     else{
	 wrong++;
	 textcolor(LIGHTRED + BLINK);
	 gotoxy(35,13);
	 cprintf("WRONG");
	 textcolor(LIGHTGREEN);
	 gotoxy(24,14);
	 cprintf("Correct Answer is %s",quizans[quizno]);
     }
     totattempt++;
     currentscore=(int)((right * 100)/totattempt);

     textcolor(LIGHTGRAY);
     quizbox(22,16,58,18,2);//for score board
     quizbox(22,19,58,25,2);//for it's details

     textcolor(LIGHTCYAN);
     gotoxy(35,17);
     cprintf("SCORE BOARD");
     textcolor(WHITE);
     gotoxy(25,20);
     cprintf("Total Right       : %d",right);
     gotoxy(25,21);
     cprintf("Total Wrong       : %d",wrong);
     gotoxy(25,22);
     cprintf("Total Attempt     : %d out of 15",totattempt);
     gotoxy(23,23);
     printf("컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�");
     gotoxy(25,24);
     textcolor(YELLOW);
     cprintf("Current Score     : %d",currentscore);
    /* if(quizno==14){
	 getch();
	 statusmsg(currentscore);
	 exit(1);
     }
    */
    return 0;
}





void quizbox(int x1, int y1, int x2, int y2,int linestyle)
{
       int col,row;
       if(linestyle==1){
	for (col = x1; col < x2; col++)
	{
		gotoxy(col, y1);
		cprintf("%c", 196);
		gotoxy(col, y2);
		cprintf("%c", 196);
	}

	for (row = y1; row < y2; row++)
	{
		gotoxy(x1, row);
		cprintf("%c", 179);
		gotoxy(x2, row);
		cprintf("%c", 179);
	}

	gotoxy(x1, y1);
	cprintf("%c", 218);
	gotoxy(x1, y2);
	cprintf("%c", 192);
	gotoxy(x2, y1);
	cprintf("%c", 191);
	gotoxy(x2, y2);
	cprintf("%c", 217);
       }
       else{
	for (col = x1; col < x2; col++)
	{
		gotoxy(col, y1);
		cprintf("%c", 205);
		gotoxy(col, y2);
		cprintf("%c", 205);
	}

	for (row = y1; row < y2; row++)
	{
		gotoxy(x1, row);
		cprintf("%c", 186);
		gotoxy(x2, row);
		cprintf("%c", 186);
	}

	gotoxy(x1, y1);
	cprintf("%c", 201);
	gotoxy(x1, y2);
	cprintf("%c", 200);
	gotoxy(x2, y1);
	cprintf("%c", 187);
	gotoxy(x2, y2);
	cprintf("%c", 188);
	}
}



//Lastly Giving Greet According to Quiz Status
//  Use the section only if u have knowledge of Graphics
/*
void statusmsg(int score){
		initgraph(&gdriver, &gmode,"c:\\tc\\bgi");
		setcolor(LIGHTMAGENTA);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
		outtextxy(5,455,"WebSite          :   www.syntax-example.com");

		setcolor(YELLOW);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,8);
		if(score==100)
		   outtextxy(50,50,"KEEP IT UP!");
		else if(score>=85)
		   outtextxy(50,50,"Well Done!");
		else if(score>=75)
		   outtextxy(100,50,"Good");
		else if(score>=70)
		   outtextxy(20,50,"Practise Require!");
		else if(score>=60)
		   outtextxy(20,50,"Revision Needed!");
		else if(score>=50)
		   outtextxy(50,50,"Work Hard!");
		else
		   outtextxy(50,50,"Read Tutorial!");

		getch();
		closegraph();
}
*/
