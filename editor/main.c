#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<mem.h>
#include<string.h>
char far *vid=0xB8000000;
char a[50000],*str;
int track[2000],fp=1,lp=21,cl=1,p=0,t=0,eat;

/*This function writes a character into video memory.*/
writechar(char ch,int attr,int row,int col)
{
      char far *v;
      v=vid+row*160+col*2;
      *v=ch;
      v++;
      *v=attr;
}/*End wrotechar*///-----------------------------------------------------------------------/*This function draws a box of given attribute & size*/
drawbox(int r1,int c1,int r2,int c2,int attr)
{     int i,j;
      for(i=r1;i<=r2;i++)
      {   for(j=c1;j<=c2;j++)
       writechar(' ',attr,i,j);
      }
}/*End drawbox*///------------------------------------------------------------------------/*This function draws the screen at starting*/
drawscreen()
{     drawbox(0,0,0,79,120);
      drawbox(24,0,24,79,120);
      drawbox(1,0,23,79,16);
      doubleborder(1,0,23,79,31);
}/*End drawscreen*///------------------------------------------------------------------------/*This function refreshes the screen*/
refreshscreen()
{     int r,c;
      drawbox(2,1,22,78,16);

}/*End Refreshscreen*///-------------------------------------------------------------------------/*This function draws the double border*/
doubleborder(int r1,int c1,int r2,int c2,int attr)
{     int r,c;
      writechar(201,attr,r1,c1);
      writechar(187,attr,r1,c2);
      writechar(200,attr,r2,c1);
      writechar(188,attr,r2,c2);


      for(c=(c1+1);c<=(c2-1);c++)
    writechar(205,attr,r1,c);

      for(c=(c1+1);c<=(c2-1);c++)
    writechar(205,attr,r2,c);

      for(r=(r1+1);r<=(r2-1);r++)
    writechar(186,attr,r,c1);

      for(r=(r1+1);r<=(r2-1);r++)
    writechar(186,attr,r,c2);

}/*End doubleborder*///---------------------------------------------------------------------------/*This function draws border of given attribute & size*/
drawborder(int r1,int c1,int r2,int c2,int attr)
{     int r,c;

      writechar(218,attr,r1,c1);
      writechar(191,attr,r1,c2);
      writechar(192,attr,r2,c1);
      writechar(217,attr,r2,c2);

      r=r1;
      for(c=c1+1;c<=c2-1;c++)
    writechar(196,attr,r,c);

      r=r2;
      for(c=c1+1;c<=c2-1;c++)
    writechar(196,attr,r,c);

      c=c1;
      for(r=r1+1;r<=r2-1;r++)
    writechar(179,attr,r,c);

      c=c2;
      for(r=r1+1;r<=r2-1;r++)
    writechar(179,attr,r,c);

}/*End drawborder*///---------------------------------------------------------------------------/*This function draws a line of given attribute*/
drawline(int r,int c1,int c2,int attr)
{     int i;
      writechar(195,attr,r,c1);
      writechar(180,attr,r,c2);
      for(i=c1+1;i<=c2-1;i++)
       writechar(196,attr,r,i);
}/*End drawline*///---------------------------------------------------------------------------/*This function writes a string in given row & column with given attribute*/
writestring(char *p,int attr,int r,int c)
{     int l,i;
      l=strlen(p);
      for(i=0;i<l;i++)
       {    writechar(*(p+i),attr,r,c);
        c++;
       }
}/*End writestring*///---------------------------------------------------------------------------/*This function saves the content of videomemory from r1,c1 to r2,c2 into main memory using char buffer*/char *savemem(int r1,int c1,int r2,int c2,char *buff)
{     char far *v;
      int i,j,k=0,size;

      size=(r2-r1+1)*(c2-c1+1)*2;
      buff=(char *)malloc(size);

      for(i=r1;i<=r2;i++)
      {    for(j=c1;j<=c2;j++)
     { v=(vid+i*160+j*2);
       *(buff+k)=*v;
       k++;
       v++;
       *(buff+k)=*v;
       k++;
     }
      }
      return(buff);
}/*End savememo*///---------------------------------------------------------------------------/*This function restores the content of main memory into videomemoryfrom r1,c1 to r2,c2 using char buffer*/
restoremem(int r1,int c1,int r2,int c2,char *buff)
{     char far *v;
      int i,j,k=0;


      for(i=r1;i<=r2;i++)
      {    for(j=c1;j<=c2;j++)
      { v=(vid+i*160+j*2);
        *v=*(buff+k);
        k++;
        v++;
        *v=*(buff+k);
        k++;

      }
      }
      free(buff);
}/*End restorememory*///---------------------------------------------------------------------------
savefile()
{     FILE *fp;
      int i,j;
      //char *str="c:\\tc\\ex1";
      fp=fopen(str,"w");
      if(fp==NULL)
      {   return;
      }
      i=0;
      j=track[0];
       while(j<p)
       {  fputc(a[j],fp);
          j++;
          if(j==track[i+1])
         { fputc('\n',fp);
           i++;
         }
       }

      fputc('\n',fp);
      fclose(fp);
}
//------------------------------------------------------------------------
saveasfile()
{     FILE *fp;
      int i,j,r1,c1;
      char *buff;
      buff=savemem(8,18,16,58,buff);
      drawbox(8,18,16,58,120);
      doubleborder(8,18,16,58,127);
      drawbox(10,21,10,55,16);
      setcuserpos(10,21);

      gets(str);
      restoremem(8,18,16,58,buff);

      fp=fopen(str,"w");
      if(fp==NULL)
      {   return;
      }
      i=0;
      j=0;
       while(j<p)
       {  fputc(a[j],fp);
          j++;
          if(j==track[i+1])
         { fputc('\n',fp);
           i++;
         }
       }

      fputc('\n',fp);
      fclose(fp);

}
//------------------------------------------------------------------------
openfile()
{     FILE *fp;
      int i,j,r1,c1;
      char *buff,ch;
      buff=savemem(8,18,16,58,buff);
      drawbox(8,18,16,58,120);
      doubleborder(8,18,16,58,127);
      drawbox(10,21,10,55,16);
      setcuserpos(10,21);

      gets(str);
      restoremem(8,18,16,58,buff);
      //writestring(str,31,1,30);
      fp=fopen(str,"r");
      p=0;
      t=0;
      track[0]=0;
      while(!feof(fp))
      {     ch=fgetc(fp);
        if(ch!='\n')
         {  a[p]=ch;
        p++;
         }
        else
         { track[t+1]=p;
           t++;
         }
      }
      fclose(fp);
      fp=1;
      lp=21;
      cl=1;
      display();
}
//------------------------------------------------------------------------/*This function opens the filemenu*/int Filemenu(char *buff)
{     int i,sc,ac,c,r,r1,c1,flag;
      char *s[]={"New","Open","Save","Save as","Close","Print","Exit"};
      char *s1[]={"Create a new file",
          "Load an existing file from the disk",
          "Save current file",
          "Save current file with new name",
          "Close current file",
          "Prints currently loaded file to printer",
          "Exit the editor"
          };
      union REGS inregs,outregs;

      setcursersize(32,10);          /*Hides the curser*/
      buff=savemem(1,1,12,20,buff);
      drawbox(1,1,11,18,120);
      drawbox(2,19,12,20,7);
      drawbox(12,3,12,18,7);
      drawborder(1,2,11,17,112);

      r=2; c=4;
      for(i=0;i<7;i++)
    { writestring(s[i],112,r,c);
      r++;
      if(i==4)
      {  drawline(r,2,17,112);
         r++;
      }
      if(i==5)
      {  drawline(r,2,17,112);
         r++;
      }
    }


      sc=72; flag=2;
      while(1)
      {    if(sc==72)                 /*Up arrow*/
         { if(flag==1)
         flag=7;
           else
         flag--;
          }
       else/*Down arrow*/
         { if(sc==80)
         { if(flag==7)
              flag=1;
           else
              flag++;
          }
           else
            flag=8;          /*Right or Left arrow*/
         }
       switch(flag)
       {  case 1:
             drawbox(2,3,2,16,32);
             writestring(s[0],32,2,4);
             r=2; i=0;
             writestring(s1[0],112,24,1);
             break;

          case 2:
             drawbox(3,3,3,16,32);
             writestring(s[1],32,3,4);
             r=3; i=1;
             writestring(s1[1],112,24,1);
             break;
          case 3:
             drawbox(4,3,4,16,32);
             writestring(s[2],32,4,4);
             r=4; i=2;
             writestring(s1[2],112,24,1);
             break;
          case 4:
             drawbox(5,3,5,16,32);
             writestring(s[3],32,5,4);
             r=5; i=3;
             writestring(s1[3],112,24,1);
             break;
          case 5:
             drawbox(6,3,6,16,32);
             writestring(s[4],32,6,4);
             r=6; i=4;
             writestring(s1[4],112,24,1);
             break;
          case 6:
             drawbox(8,3,8,16,32);
             writestring(s[5],32,8,4);
             r=8; i=5;
             writestring(s1[5],112,24,1);
             break;
          case 7:
             drawbox(10,3,10,16,32);
             writestring(s[6],32,10,4);
             r=10; i=6;
             writestring(s1[6],112,24,1);
             break;
          case 8:
             if(sc==77)                      /*Right arrow return */
              {    restoremem(1,1,12,20,buff); /*Scancode of Editmenu*/return(18);
              }
              else
              {    if(sc==75)
             {  restoremem(1,1,12,20,buff); /*Left arrow return*//*Scancode of Helpmenu*/return(35);
             }
             else
               {  restoremem(1,1,12,20,buff);/*Return & Escape*/return(sc);
               }
              }
       }
       getcharacter(&sc,&ac);

       drawbox(r,3,r,16,112);
       writestring(s[i],112,r,4);
       drawbox(24,1,24,55,112);
       if(ac==13)
       {   switch(r)
        { case 2: restoremem(1,1,12,20,buff);
              refreshscreen();
              setcuserpos(2,1);
              fp=1;
              cl=1;
              t=0;
              lp=21;
              p=0;
              return(1);
          case 3: readcurser(&r1,&c1);
              restoremem(1,1,12,20,buff);
              openfile();
              setcuserpos(r1,c1);
              return(1);

          case 4: readcurser(&r1,&c1);
              restoremem(1,1,12,20,buff);
              savefile();
              setcuserpos(r1,c1);
              return(1);

          case 5: readcurser(&r1,&c1);
              restoremem(1,1,12,20,buff);
              saveasfile();
              setcuserpos(r1,c1);
              return(1);
          case 6:
          case 8:
          case 10:
              return(0);
        }    }


      }
}/*End filemenu*///-------------------------------------------------------------------------/*This function opens the Editmenu*/int Editmenu(char *buff)
{     int i,sc,ac,r,c,flag;
      char *s[]={"Cut     Ctrl+X","Copy    Ctrl+C","Paste   Ctrl+V","Clear      Del"};
      char *s1[]={"Delete selected text and copies it to buffer",
          "Copies selected text to buffer",
          "Insert buffer contents at current location",
          "Delete selected text without copying it to buffer"
          };
      union REGS inregs,outregs;

      setcursersize(32,10);         /*Hide the cursor*/
      buff=savemem(1,8,7,28,buff);
      drawbox(1,8,6,26,120);
      drawbox(2,27,7,28,7);
      drawbox(7,10,7,26,7);
      drawborder(1,9,6,25,112);

      r=2; c=11;
      for(i=0;i<4;i++)
    { writestring(s[i],112,r,c);
      r++;
    }

      sc=72; flag=2;
      while(1)
      {    if(sc==72)                 /*Up arrow*/
         { if(flag==1)
         flag=4;
           else
         flag--;
          }
       else
         { if(sc==80)         /*Down arrow*/
         { if(flag==4)
              flag=1;
           else
              flag++;
          }
           else
            flag=5;          /*Right or Left arrow*/
         }
       switch(flag)
       {  case 1:
             drawbox(2,10,2,24,32);
             writestring(s[0],32,2,11);
             r=2; i=0;
             writestring(s1[0],112,24,1);
             break;

          case 2:
             drawbox(3,10,3,24,32);
             writestring(s[1],32,3,11);
             r=3; i=1;
             writestring(s1[1],112,24,1);
             break;
          case 3:
             drawbox(4,10,4,24,32);
             writestring(s[2],32,4,11);
             r=4; i=2;
             writestring(s1[2],112,24,1);
             break;
          case 4:
             drawbox(5,10,5,24,32);
             writestring(s[3],32,5,11);
             r=5; i=3;
             writestring(s1[3],112,24,1);
             break;
          case 5:
             if(sc==77)                      /*Right arrow return */
              {    restoremem(1,8,7,28,buff);  /*Scancode of Searchmenu*/return(31);
              }
              else
              {    if(sc==75)
             { restoremem(1,8,7,28,buff);/*Left arrow return */return(33);              /*Scancode of Filemenu*/
             }
             else
               {  restoremem(1,8,7,28,buff);
                  return(sc);              /*Return & Escape*/
               }
              }
         }
       getcharacter(&sc,&ac);

       drawbox(r,10,r,24,112);
       writestring(s[i],112,r,11);
       drawbox(24,1,24,55,112);
     }

}/*End Editmenu*///------------------------------------------------------------------------/*This function opens the Searchmenu*/int Searchmenu(char *buff)
{     int i,sc,ac,r,c,flag;
      char *s[]={  "Find",
           "Repeat Last Find      F3",
           "Replace"
        };
      char *s1[]={"Find specified text",
          "Find next occurence of text specified in previous search",
          "Finds and changes specified text"
          };
      union REGS inregs,outregs;

      setcursersize(32,10);         /*Hide the cursor*/
      buff=savemem(1,14,6,44,buff);
      drawbox(1,14,5,42,120);
      drawbox(2,43,6,44,7);
      drawbox(6,16,6,42,7);
      drawborder(1,15,5,41,112);

      r=2; c=17;
      for(i=0;i<3;i++)
    { writestring(s[i],112,r,c);
      r++;
    }

      sc=72; flag=2;
      while(1)
      {    if(sc==72)                /*Up arrow*/
         { if(flag==1)
         flag=3;
           else
         flag--;
          }
       else
         { if(sc==80)              /*Down arrow*/
         { if(flag==3)
              flag=1;
           else
              flag++;
          }
           else
            flag=4;          /*Right or Left arrow*/
         }
       switch(flag)
       {  case 1:
             drawbox(2,16,2,40,32);
             writestring(s[0],32,2,17);
             r=2; i=0;
             writestring(s1[0],112,24,1);
             break;

          case 2:
             drawbox(3,16,3,40,32);
             writestring(s[1],32,3,17);
             r=3; i=1;
             writestring(s1[1],112,24,1);
             break;
          case 3:
             drawbox(4,16,4,40,32);
             writestring(s[2],32,4,17);
             r=4; i=2;
             writestring(s1[2],112,24,1);
             break;
          case 4:
             if(sc==77)
              {    restoremem(1,14,6,44,buff); /*Right arrow return*/return(47);                 /*Scancode of Viewmenu*/
              }
              else
              {    if(sc==75)
             {  restoremem(1,14,6,44,buff);/*Left arrow return*/return(18);             /*Scancode of Editmenu*/
             }
             else
               {  restoremem(1,14,6,44,buff);
                  return(sc);            /*Return & Escape*/
               }
              }
       }
       getcharacter(&sc,&ac);

       drawbox(r,16,r,40,112);
       writestring(s[i],112,r,17);
       drawbox(24,1,24,56,112);
      }

}/*End Searchmenu*///------------------------------------------------------------------------/*This function opens the Viewmenu*/int Viewmenu(char *buff)
{     int i,sc,ac,r,c,flag;
      char *s[]={  "Split Window Ctrl+F6",
           "Size Window  Ctrl+F8",
           "Close Window Ctrl+F4",
           "1 UNTITLED     Alt+1"
         };
      char *s1[]={"Open a second edit window",
          "Resize the edit window",
          "Close the second edit window",
          "Selects a file to view"
          };
      union REGS inregs,outregs;

      setcursersize(32,10);         /*Hide the cursor*/
      buff=savemem(1,22,8,47,buff);
      drawbox(1,22,7,45,120);
      drawbox(2,46,8,47,7);
      drawbox(8,24,8,45,7);
      drawborder(1,23,7,44,112);

      r=2; c=24;
      for(i=0;i<4;i++)
    { writestring(s[i],112,r,c);
      r++;
      if(i==2)
        {  drawline(r,23,44,112);
           r++;
        }
    }

      sc=72; flag=2;
      while(1)
      {    if(sc==72)             /*Up arrow*/
         { if(flag==1)
         flag=4;
           else
         flag--;
          }
       else
         { if(sc==80)             /*Down arrow*/
         { if(flag==4)
              flag=1;
           else
              flag++;
          }
           else
            flag=5;          /*Right or Left arrow*/
         }
       switch(flag)
       {  case 1:
             drawbox(2,24,2,43,32);
             writestring(s[0],32,2,24);
             r=2; i=0;
             writestring(s1[0],112,24,1);
             break;

          case 2:
             drawbox(3,24,3,43,32);
             writestring(s[1],32,3,24);
             r=3; i=1;
             writestring(s1[1],112,24,1);
             break;
          case 3:
             drawbox(4,24,4,43,32);
             writestring(s[2],32,4,24);
             r=4; i=2;
             writestring(s1[2],112,24,1);
             break;
          case 4:
             drawbox(6,24,6,43,32);
             writestring(s[3],32,6,24);
             r=6; i=3;
             writestring(s1[3],112,24,1);
             break;
          case 5:
             if(sc==77)
              {    restoremem(1,22,8,47,buff);  /*Right arrow return*/return(24);                 /*Scancode of Optionmenu*/
              }
              else
              {    if(sc==75)
             { restoremem(1,22,8,47,buff); /*Left arrow return*/return(31);              /*Scancode of Searchmenu*/
             }
             else
               {  restoremem(1,22,8,47,buff);
                  return(sc);           /*Return & Escape*/
               }
              }
         }
       getcharacter(&sc,&ac);

       drawbox(r,24,r,43,112);
       writestring(s[i],112,r,24);
       drawbox(24,1,24,55,112);
      }


}/*End Viewmenu*///-----------------------------------------------------------------------/*This function opens the Optionmenu*/int Optionmenu(char *buff)
{     int i,sc,ac,r,c,flag;
      char *s[]={"Settings","About"};
      char *s1[]={"Change editor setting",
          "Change editor screen color"
          };
      union REGS inregs,outregs;

      setcursersize(32,10);          /*Hide the cursor*/
      buff=savemem(1,28,5,46,buff);
      drawbox(1,28,4,44,120);
      drawbox(2,45,5,46,7);
      drawbox(5,30,5,44,7);
      drawborder(1,29,4,43,112);

      r=2; c=31;
      for(i=0;i<2;i++)
    { writestring(s[i],112,r,31);
      r++;
    }

      sc=72; flag=2;
      while(1)
      {    if(sc==72)             /*Up arrow*/
         { if(flag==1)
         flag=2;
           else
         flag--;
          }
       else
         { if(sc==80)         /*Down arrow*/
         { if(flag==2)
              flag=1;
           else
              flag++;
          }
           else
            flag=3;          /*Right or Left arrow*/
         }
       switch(flag)
       {  case 1:
             drawbox(2,30,2,42,32);
             writestring(s[0],32,2,31);
             r=2; i=0;
             writestring(s1[0],112,24,1);
             break;

          case 2:
             drawbox(3,30,3,42,32);
             writestring(s[1],32,3,31);
             r=3; i=1;
             writestring(s1[1],112,24,1);
             break;
          case 3:
             if(sc==77)
              {    restoremem(1,28,5,46,buff);  /*Right arrow return*/return(35);                  /*Scancode of Helpmenu*/
              }
              else
              {    if(sc==75)
             {  restoremem(1,28,5,46,buff);/*Left arrow return*/return(47);              /*Scancode of Viewmenu*/
             }
             else
               {  restoremem(1,28,5,46,buff);
                  return(sc);             /*Return & Escape*/
               }
              }
       }
       getcharacter(&sc,&ac);

       drawbox(r,30,r,42,112);
       writestring(s[i],112,r,31);
       drawbox(24,1,24,55,112);
      }

}/*End Optionmenu*///------------------------------------------------------------------------/*This function opens the Helpmenu*/int Helpmenu(char *buff)
{     int i,sc,ac,r,c,flag;
      char *s[]={"Commands","About"};
      char *s1[]={"Help on edit commands",
          "About help"
         };
      union REGS inregs,outregs;

      setcursersize(32,10);          /*Hide the cursor*/
      buff=savemem(1,36,5,52,buff);
      drawbox(1,36,4,50,120);
      drawbox(1,51,5,52,7);
      drawbox(5,36,5,50,7);
      drawborder(1,37,4,49,112);

      r=2; c=39;
      for(i=0;i<2;i++)
    { writestring(s[i],112,r,c);
      r++;
    }

      sc=72; flag=2;
      while(1)
      {    if(sc==72)                 /*Up arrow*/
         { if(flag==1)
         flag=2;
           else
         flag--;
          }
       else
         { if(sc==80)             /*Down arrow*/
         { if(flag==2)
              flag=1;
           else
              flag++;
          }
           else
            flag=3;          /*Right or left arrow*/
         }
       switch(flag)
       {  case 1:
             drawbox(2,38,2,48,32);
             writestring(s[0],32,2,39);
             r=2; i=0;
             writestring(s1[0],112,24,1);
             break;

          case 2:
             drawbox(3,38,3,48,32);
             writestring(s[1],32,3,39);
             r=3; i=1;
             writestring(s1[1],112,24,1);
             break;
          case 3:
             if(sc==77)
              {    restoremem(1,36,5,52,buff);/*Right arrow return*/return(33);                /*Scancode of Filemenu*/
              }
              else
              {    if(sc==75)
             {  restoremem(1,36,5,52,buff);/*Left arrow return*/return(24);            /*Scancode of Optionmenu*/
             }
             else
               {  restoremem(1,36,5,52,buff);
                  return(sc);           /*Return & Escape*/
               }
              }
       }

       getcharacter(&sc,&ac);

       drawbox(r,38,r,48,112);
       writestring(s[i],112,r,39);
       drawbox(24,1,24,55,112);
      }


}/*End Helpmenu*///-----------------------------------------------------------------------/*This function is used to hides the curser*/
setcursersize(int x,int y)
{     union REGS inregs,outregs;
      inregs.h.ah=0x01;
      inregs.h.ch=x;
      inregs.h.cl=y;
      int86(0x10,&inregs,&outregs);
}/*End setcurser*///------------------------------------------------------------------------/*This function sets the cursor at given position*/
setcuserpos(int a,int b)
{     union REGS inregs,outregs;
      inregs.h.ah=0x02;
      inregs.h.bh=0;
      inregs.h.dh=a;
      inregs.h.dl=b;
      int86(0x10,&inregs,&outregs);
}/*End setcurserpos*///-------------------------------------------------------------------------/*This function is used to read current position of curser*/
readcurser(int *p1,int *p2)
{
      union REGS inregs,outregs;
      inregs.h.ah=0x03;
      inregs.h.bh=0;
      int86(0x10,&inregs,&outregs);
      *p1=outregs.h.dh;
      *p2=outregs.h.dl;
}/*End readcurser*///------------------------------------------------------------------------

getcharacter(int *p1,int *p2)
{     union REGS inregs,outregs;
      inregs.h.ah=0;
      int86(0x16,&inregs,&outregs);
      *p1=outregs.h.ah;
      *p2=outregs.h.al;
}
//------------------------------------------------------------------------

display()
{     int i,j,c=1,k=2,m;

      refreshscreen();
      for(i=fp-1;i<=t;i++)
      {      if(i==lp)
        break;
         for(j=track[i]+eat; j<track[i]+eat+77 ;j++)
           {     if(j>=track[i+1] && i!=t)
             break;
             if(a[j]==9)
             {    for(m=0;m<8;m++)
                writechar(32,23,k,c);
             }
             else
             {
             writechar(a[j],23,k,c);
             }
             c++;
           }
         c=1;
         k++;
      }
}
//-------------------------------------------------------------------------
delete1(int temp)
{     int i;
      memmove(a+temp,a+(temp+1),1000-(temp+1));
      p--;
      for(i=cl;i<=t;i++)
     track[i]=track[i]-1;
      display();
}
//------------------------------------------------------------------------
insert(int temp,int ac)
{     int i;
      memmove(a+(temp+1),a+temp,1000-temp);
      p++;
      *(a+temp)=ac;
      for(i=cl;i<=t;i++)
     track[i]=track[i]+1;
}
//-------------------------------------------------------------------------
activescreen(int sc,int ac,int *r,int *c)
{     int r1,c1,k,temp,i;
      readcurser(&r1,&c1);

      switch(sc)
      {      case 71:      if(eat!=0)
               {  eat=0;
                  display();
               }
               readcurser(&r1,&c1);
               c1=1;
               setcuserpos(r1,c1);
               break;

         case 79:      if(t!=(cl-1))
               {  readcurser(&r1,&c1);
                  c1=track[cl]-track[cl-1]+1;
                  if(c1<78)
                 {   if(eat!=0)
                     {  eat=0;
                    display();
                     }
                     setcuserpos(r1,c1);
                 }
                  else
                 {  eat=c1-78;
                    display();
                    readcurser(&r1,&c1);
                    c1=78;
                    setcuserpos(r1,c1);
                 }
               }
               else
               {  readcurser(&r1,&c1);
                  c1=p-track[cl-1]+1;
                  if(c1<78)
                    setcuserpos(r1,c1);
                  else
                 {  eat=c1-78;
                    display();
                    readcurser(&r1,&c1);
                    c1=78;
                    setcuserpos(r1,c1);
                 }
               }
               break;

         case 73:      if(fp!=1)
               {  if(lp>41)
                  {  fp=fp-20;
                 lp=lp-20;
                 cl=cl-20;
                 display();
                   }
                   else
                   { fp=1;
                 lp=21;
                 display();
                 readcurser(&r1,&c1);
                 cl=r1-1;
                   }
               }
               break;

         case 81:      if((fp+20)<t)
               {  fp=fp+20;
                  lp=lp+20;
                  cl=cl+20;
                  display();
                  if((lp-1)>t)
                   {  cl=t+1;
                  readcurser(&r1,&c1);
                  r1=cl-fp+2;
                  setcuserpos(r1,c1);
                }
               }
               break;
         case 83:      if((cl-1)==t || (track[cl-1]+(c1+eat))<=track[cl])
               {   readcurser(&r1,&c1);
                   temp=track[cl-1]+(c1+eat)-1;
                   delete1(temp);
               }
               else
               {   temp=track[cl-1]+(c1+eat)-track[cl]-1;
                   k=temp+track[cl];
                   for(i=track[cl];i<k;i++)
                  insert(i,32);

                   memmove(track+cl,track+(cl+1),99-(cl+1));
                   t--;
                   display();
               }
               break;
         case 14:      readcurser(&r1,&c1);
               temp=track[cl-1]+c1-2;
               delete1(temp);
               c1=c1-1;
               setcuserpos(r1,c1);
               break;
         case 15:      a[p]=ac;
               p++;
               writechar(ac,23,r1,c1);
               c=c1+8;
               break;
         case 72:      if(cl!=1)
               {  if(cl>fp)
                  { cl--;
                readcurser(&r1,&c1);
                r1--;
                setcuserpos(r1,c1);
                  }
                  else
                  { fp--;
                lp--;
                cl--;
                display();
                   // setcuserpos(r1,c1);
                  }
               }
               break;

         case 80:      if(cl!=t+1)
               {  if(cl<lp)
                  {   cl++;
                  readcurser(&r1,&c1);
                  r1++;
                  setcuserpos(r1,c1);
                  }
                  else
                  {   fp++;
                  lp++;
                  cl++;
                  display();
                  }
               }
               break;

         case 77:      if(c1<78)
               {    c1++;
                setcuserpos(r1,c1);
               }
               else
               {    eat++;
                display();
               }
               break;

         case 75:       if(c1!=1)
               {    if((eat+c1)>78)
                {  eat--;
                   display();
                }
                else
                {  c1--;
                   setcuserpos(r1,c1);
                }
               }
               break;

         default:      if(track[cl-1]+c1-1+eat==p)
               {   if(ac==13)
                   { t++;
                 track[t]=track[t-1]+(eat+c1)-1;
                 k=t;
                 t--;
                   if(cl==lp)
                   {  fp++;
                      lp++;
                      display();
                      readcurser(&r1,&c1);
                      c1=1;
                      setcuserpos(r1,c1);
                   }

                   cl++;
                   if(eat!=0)
                   {  eat=0;
                      display();
                   }
                   t=k;
                   if(lp<=21)
                   {  readcurser(&r1,&c1);
                      r1=r1+1;
                      c1=1;
                      setcuserpos(r1,c1);
                   }

                   }
                   else
                   {   if((eat+c1)>= 78)
                   {  a[p]=ac;
                      eat++;
                      setcuserpos(r1,78);
                      display();
                      p++;
                   }
                   else
                   {  writechar(ac,23,r1,c1);
                      a[p]=ac;
                      p++;
                      c1++;
                      setcuserpos(r1,c1);
                   }
                }
               }
               else
               {   readcurser(&r1,&c1);
                  if((track[cl-1]+c1+eat)>track[cl])
                    { readcurser(&r1,&c1);
                      temp=track[cl-1]+(c1+eat)-1;
                      for(i=track[cl];i<temp;i++)
                      insert(i,32);
                     }
                if(ac!=13)
                {  readcurser(&r1,&c1);
                     if(eat==0)
                     {  temp=track[cl-1]+c1-1;
                    insert(temp,ac);
                    display();
                    c1=c1+1;
                    setcuserpos(r1,c1);
                      }
                     else
                     {  temp=track[cl-1]+(c1+eat)-1;
                    insert(temp,ac);
                    eat++;
                    display();
                    c1=78;
                    setcuserpos(r1,c1);
                     }
                }
                else
                {   memmove(track+(cl+1),track+cl,99-cl);
                    *(track+cl)=track[cl-1]+(c1+eat)-1;
                    t++;
                    r1=r1+1;
                    c1=1;
                    display();
                    setcuserpos(r1,c1);
                    cl++;
                }
               }
      }
      *r=r1;
      *c=c1;
}
main()
{     int i,r,c,sc,c1,ac,k,m,exit=0;
      union REGS inregs,outregs;
      char far *v;
      char *buff,*s[]=  {  "File",
               "Edit",
               "Search",
               "View",
               "Option",
               "Help",
               "Line:",
               "Col:"
            };

      clrscr();
      drawscreen();
      track[t]=0;


      c=3;
      writestring(s[0],112,0,c);   /*String,Attribute,Row No,Column No*/
      c=9;
      writestring(s[1],112,0,c);
      c=15;
      writestring(s[2],112,0,c);
      c=23;
      writestring(s[3],112,0,c);
      c=29;
      writestring(s[4],112,0,c);
      c=37;
      writestring(s[5],112,0,c);

      writechar(179,112,24,58);
      writestring(s[6],112,24,61);
      writestring(s[7],112,24,70);
      c=1; r=2;
      setcuserpos(2,1);
      while(!exit)
      { m=77;
    drawbox(24,75,24,77,120);
    c1=eat+c;
    while(c1>0)
      { k=c1%10;
         writechar(k+48,112,24,m);
         c1=c1/10;
         m--;
      }
     m=69;
     r=cl;
     drawbox(24,66,24,69,120);
     while(r>0)
      { k=r%10;
         writechar(k+48,112,24,m);
         r=r/10;
         m--;
      }


      getcharacter(&sc,&ac);

      while(sc!=1 && ac==0 && sc!=77 && sc!=75 && sc!=72 && sc!=15 && sc!=80 && sc!=71 && sc!=79 && sc!=73 && sc!=81 && sc!=83 && sc!=14)
      {  switch(sc)
     {     case 33: writestring(s[0],32,0,3);
            sc = Filemenu(buff);
            if(sc==0)
            exit=1;
            writestring(s[0],112,0,3);
            break;

           case 18: writestring(s[1],32,0,9);
            sc = Editmenu(buff);
            writestring(s[1],112,0,9);
            break;

           case 31: writestring(s[2],32,0,15);
            sc = Searchmenu(buff);
            writestring(s[2],112,0,15);
            break;

           case 47: writestring(s[3],32,0,23);
            sc = Viewmenu(buff);
            writestring(s[3],112,0,23);
            break;

           case 24: writestring(s[4],32,0,29);
            sc = Optionmenu(buff);
            writestring(s[4],112,0,29);
            break;

           case 35: writestring(s[5],32,0,37);
            sc = Helpmenu(buff);
            writestring(s[5],112,0,37);
            break;
           default:
            sc=1;
     }
     setcursersize(5,6);
      }
      if(sc!=1)
      activescreen(sc,ac,&r,&c);
      }
}
