
#include<bits/stdc++.h>
#include<windows.h>
#include<graphics.h>
#include<conio.h>
int mx,my,score,life,x,y,ar[100],t;
int j;
struct scores
{
    char name[105];
    int score;
};
FILE *input;
FILE *output;


struct scores hiscore[7];
DWORD screenwidth = GetSystemMetrics(SM_CXSCREEN);
DWORD screenheight = GetSystemMetrics(SM_CYSCREEN);
void start_page();
void level_one();
void level_two();
void one_one();
void one_two();
void level_three();
void one_three();
void level_four();
void level_five();
void one_four();
void gameover();
void pause();
void highscore();


void sort_score()
{
    int i;
    for(int l=0; l<6-1; l++)
        for(i=0; i<6-l-1; i++)
        {
            if(hiscore[i].score<hiscore[i+1].score)
            {
                hiscore[6]=hiscore[i];
                hiscore[i]=hiscore[i+1];
                hiscore[i+1]=hiscore[6];
            }
        }
}



void highscore()
{
    cleardevice();
    char arr[100];
    int i;
    readimagefile("highscore.jpg",0,0,screenwidth,screenheight-100);
    input = fopen("score.txt","r");
    for(i=0; i<5; i++)
    {
        fscanf(input,"%s",&hiscore[i].name);
        fscanf(input,"%d",&hiscore[i].score);
    }
    fclose(input);
    sort_score();

    output= fopen("score.txt","w");
    for (i=0; i<5; i++)
    {
        fprintf(output,"%s\n",hiscore[i].name);
        fprintf(output,"%d\n",hiscore[i].score);

    }
    fclose(output);


    settextstyle(1,HORIZ_DIR,6);
    for(i=0; i<5; i++)
    {
        sprintf(arr,"%d",hiscore[i].score);
        outtextxy(200,180+72*i,hiscore[i].name);

        outtextxy(550,180+72*i,arr);
    }
    delay (100);
    getch();

}
void entername()
{
    int pos=0;

    char user[100],c;
    readimagefile("Entername.jpg",0,0,screenwidth,screenheight);
    while(1)
    {
        if(kbhit())
        {
            user[pos]=getch();
            while(kbhit())
            {
                c=getch();
            }
            if(user[pos]==8)
            {
                if(pos==0) continue;
                pos--;
                user[pos]='\0';
            }
            else
            {
                if(user[pos]=='\r')
                {
                    if(pos==0) continue;
                    user[pos]='\0';
                    break;
                }
                else if(user[pos]==' ')
                    continue;
                else pos++;
                user[pos]='\0';
            }


            setviewport(0,250,screenwidth,450,1);
            clearviewport();
            settextstyle(3,HORIZ_DIR,6);
            outtextxy(230,130,user);
        }
    }
    setviewport(0,0,screenwidth,screenheight,1);
    strcpy(hiscore[5].name,user);
    cleardevice();


}

void pause()
{
    char c;
    readimagefile("pause.jpg",0,0,screenwidth,screenheight);
    c=getch();
    if(c==27)
        start_page();
}
void gameover()
{
    char ar[10];
    cleardevice();
    readimagefile("gameover.jpg",0,0,screenwidth,screenheight);
    hiscore[5].score=score;
    getch();
    highscore();

    start_page();
}



void one_one()
{
    char arr[100],ar[100];
    int x=0,y=0;
    double t;

    while(1)
    {
        for(t=0; t<=72; t++)
        {

            if(t>63 && t<73)
            {
                setcolor(RED);
                sprintf(ar,"  TIME  OVER  ");
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(600,0,ar);
            }
            else
            {
                setcolor(GREEN);
                sprintf(ar,"%.0lf seconds left",9-t/8);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(600,0,ar);
            }
            setcolor(GREEN);
            sprintf(arr,"FINAL DEATH 1");
            settextstyle(3,HORIZ_DIR,4);
            outtextxy(0,0,arr);

            setcolor(WHITE);
            sprintf(arr,"There were 235 apples. I took away 50 of them.");
            settextstyle(1,HORIZ_DIR,4);
            outtextxy(200,200,arr);

            sprintf(arr,"How many apples do I have now?");
            settextstyle(1,HORIZ_DIR,4);
            outtextxy(350,250,arr);

            settextstyle(1,HORIZ_DIR,7);
            outtextxy(screenwidth-50,0,"||");

            setcolor(GREEN);
            sprintf(ar,"SCORE:%d",score);
            settextstyle(3,HORIZ_DIR,4);
            outtextxy(300,0,ar);

            setcolor(RED);
            sprintf(ar,"Life:%d",life);
            settextstyle(3,HORIZ_DIR,4);
            outtextxy(1000,0,ar);


            POINT co;
            GetCursorPos(&co);
            mx=co.x;
            my=co.y;
            if(mx>349 && mx<631 && my>339+30-3 && my<481+30-3)
            {
                setcolor(RED);
                rectangle(350,340,630,480);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(480,390,"0");
            }
            else
            {

                setcolor(WHITE);
                rectangle(350,340,630,480);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(480,390,"0");
            }
            if(mx>749 && mx<1031 && my>339+30-3 && my<481+30-3)
            {
                setcolor(RED);
                rectangle(670+80,340,950+80,480);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(850,390,"185");
            }
            else
            {
                setcolor(WHITE);
                rectangle(670+80,340,950+80,480);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(850,390,"185");
            }


            if(mx>749 && mx<1031 && my<691+30-3 && my>549+30-3)
            {
                setcolor(RED);
                rectangle(670+80,550,950+80,690);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(850,600,"50");
            }
            else
            {
                setcolor(WHITE);
                rectangle(670+80,550,950+80,690);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(850,600,"50");
            }
            if(mx>349 && mx<631 && my<691+30-3 && my>549+30-3)
            {
                setcolor(RED);
                rectangle(350,550,630,690);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(450,600,"235");
            }
            else
            {
                setcolor(WHITE);
                rectangle(350,550,630,690);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(450,600,"235");
            }
            while(ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN,x,y);

            }
            if(x && y && mx>screenwidth-100 && mx<=screenwidth && my>0 && my<=100)
            {
                cleardevice();
                pause();
                cleardevice();
            }
            if(x && y && mx>749 && mx<1031 && my<691+30-3 && my>549+30-3)
            {

                cleardevice();
                score+=5;


                level_two();
            }
            else if(x && y &&
                    ((mx>349 && mx<631 && my<691+30-3 && my>549+30-3) ||
                     (mx>749 && mx<1031 && my>339+30-3 && my<481+30-3) ||
                     (mx>349 && mx<631 && my>339+30-3 && my<481+30-3)))
            {
                break;
            }
            x=0;
            y=0;
            delay(200);

        }
        break;
    }

    cleardevice();
    gameover();

}


void level_one()
{
    FILE *one=fopen("basics.txt","r");
    char q1[100],ar[100],a[100],b[100],c[100],d[100],q2[100];
    int x=0,y=0,l,life=2;
    double t;
    readimagefile("Slide1.jpg",0,0,screenwidth,screenheight);
    delay(2000);
    for(int i=0; i<5; i++)

    {

        cleardevice();

        fscanf(one," %[^\n]",q1);
        fscanf(one," %[^\n]",q2);
        fscanf(one," %[^\n]",a);
        fscanf(one," %[^\n]",b);
        fscanf(one," %[^\n]",c);
        fscanf(one," %[^\n]",d);

        while(1)
        {
            for(t=0; t<=72; t++)
            {

                if(t>63 && t<73)
                {
                    setcolor(RED);
                    sprintf(ar,"  TIME  OVER  ");
                    settextstyle(3,HORIZ_DIR,4);
                    outtextxy(600,0,ar);
                }
                else
                {
                    setcolor(GREEN);
                    sprintf(ar,"%.0lf seconds left",9-t/8);
                    settextstyle(3,HORIZ_DIR,4);
                    outtextxy(600,0,ar);
                }


                setcolor(GREEN);
                sprintf(ar,"LEVEL:1-%d",i+1);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(0,0,ar);


                setcolor(GREEN);
                sprintf(ar,"SCORE:%d",score);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(300,0,ar);

                setcolor(RED);
                sprintf(ar,"Life:%d",life);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(1000,0,ar);

                setcolor(WHITE);

                settextstyle(1,HORIZ_DIR,3);
                l=strlen(q1);
                outtextxy(170+(17*(49-l)/2),170,q1);
                l=strlen(q2);
                outtextxy(170+(17*(49-l)/2),220,q2);

                POINT co;
                GetCursorPos(&co);
                mx=co.x;
                my=co.y;
                settextstyle(1,HORIZ_DIR,7);
                outtextxy(screenwidth-50,0,"||");


                if(mx>259 && mx<931 && my>279+30-3 && my<351+30-3)
                {
                    setcolor(RED);
                    rectangle(260,280,930,350);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,290,a);
                }
                else
                {

                    setcolor(WHITE);
                    rectangle(260,280,930,350);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,290,a);
                }
                if(mx>259 && mx<931 && my>366+30-3 && my<436+30-3)
                {
                    setcolor(RED);
                    rectangle(260,365,930,435);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,376,b);
                }
                else
                {
                    setcolor(WHITE);
                    rectangle(260,365,930,435);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,376,b);
                }


                if(mx>259 && mx<931 && my<521+30-3 && my>451+30-3)
                {
                    setcolor(RED);
                    rectangle(260,450,930,520);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,460,c);
                }
                else
                {
                    setcolor(WHITE);
                    rectangle(260,450,930,520);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,460,c);
                }
                if(mx>259 && mx<931 && my<606+30-3 && my>534+30-3)
                {
                    setcolor(RED);
                    rectangle(260,535,930,605);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,545,d);
                }
                else
                {
                    setcolor(WHITE);
                    rectangle(260,535,930,605);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,545,d);
                }
                while(ismouseclick(WM_LBUTTONDOWN))
                {
                    getmouseclick(WM_LBUTTONDOWN,x,y);

                }
                if(x && y && mx>screenwidth-100 && mx<=screenwidth && my>0 && my<=100)
                {
                    cleardevice();
                    pause();
                    cleardevice();
                }
                if(i==4)
                    if(x && y && mx>259 && mx<931 && my<351+30-3 && my>279+30-3)
                    {
                        x=0;
                        y=0;
                        score++;

                        cleardevice();
                        break;
                    }

                    else if( x && y &&
                             ((mx>259 && mx<931 && my>366+30-3 && my<436+30-3) ||
                              (mx>259 && mx<931 && my<521+30-3 && my>451+30-3) ||
                              (mx>259 && mx<931 && my<606+30-3 && my>534+30-3)))
                    {
                        x=0;
                        y=0;
                        life--;

                        //cleardevice();
                        break;

                    }
                if( i==0)
                    if(x && y && mx>259 && mx<931 && my>366+30-3 && my<436+30-3)
                    {
                        x=0;
                        y=0;
                        score++;

                        cleardevice();
                        break;
                    }

                    else if( x && y &&
                             ((mx>259 && mx<931 && my<351+30-3 && my>279+30-3) ||
                              (mx>259 && mx<931 && my<521+30-3 && my>451+30-3) ||
                              (mx>259 && mx<931 && my<606+30-3 && my>534+30-3)))
                    {
                        x=0;
                        y=0;
                        life--;

                        //     cleardevice();
                        break;

                    }
                if(i==1)
                    if( x && y && mx>259 && mx<931 && my<521+30-3 && my>451+30-3)
                    {
                        x=0;
                        y=0;

                        score++;
                        cleardevice();
                        break;
                    }

                    else if( x && y &&
                             ((mx>259 && mx<931 && my<351+30-3 && my>279+30-3) ||
                              (mx>259 && mx<931 && my>366+30-3 && my<436+30-3) ||
                              (mx>259 && mx<931 && my<606+30-3 && my>534+30-3)))
                    {
                        x=0;
                        y=0;
                        life--;

                        //     cleardevice();
                        break;

                    }
                if(i==2 || i==3)
                    if(x && y && mx>259 && mx<931 && my<606+30-3 && my>534+30-3)
                    {
                        x=0;
                        y=0;

                        score++;
                        cleardevice();
                        break;
                    }

                    else if( x && y &&
                             ((mx>259 && mx<931 && my<351+30-3 && my>279+30-3) ||
                              (mx>259 && mx<931 && my>366+30-3 && my<436+30-3) ||
                              (mx>259 && mx<931 && my<521+30-3 && my>451+30-3)))
                    {
                        x=0;
                        y=0;
                        life--;

                        //     cleardevice();
                        break;

                    }


                x=0;
                y=0;




                delay(200);
            }
            if(t>72)
                life--;
            if(life==0)
                gameover();
            break;

        }

    }
    cleardevice();
    one_one();

}
void level_two()
{
    FILE *one=fopen("humor.txt","r");
    char q1[100],ar[100],a[100],b[100],c[100],d[100],q2[100];
    int x=0,y=0,l,life=2;
    double t;
    readimagefile("Slide2.jpg",0,0,screenwidth,screenheight);
    delay(2000);
    for(int i=0; i<5; i++)

    {

        cleardevice();

        fscanf(one," %[^\n]",q1);
        fscanf(one," %[^\n]",q2);
        fscanf(one," %[^\n]",a);
        fscanf(one," %[^\n]",b);
        fscanf(one," %[^\n]",c);
        fscanf(one," %[^\n]",d);

        while(1)
        {
            for(t=0; t<=72; t++)
            {

                if(t>63 && t<73)
                {
                    setcolor(RED);
                    sprintf(ar,"  TIME  OVER  ");
                    settextstyle(3,HORIZ_DIR,4);
                    outtextxy(600,0,ar);
                }
                else
                {
                    setcolor(GREEN);
                    sprintf(ar,"%.0lf seconds left",9-t/8);
                    settextstyle(3,HORIZ_DIR,4);
                    outtextxy(600,0,ar);
                }


                setcolor(GREEN);
                sprintf(ar,"LEVEL:2-%d",i+1);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(0,0,ar);


                setcolor(GREEN);
                sprintf(ar,"SCORE:%d",score);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(300,0,ar);

                setcolor(RED);
                sprintf(ar,"Life:%d",life);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(1000,0,ar);

                setcolor(WHITE);

                settextstyle(1,HORIZ_DIR,3);
                l=strlen(q1);
                outtextxy(170+(17*(49-l)/2),170,q1);
                l=strlen(q2);
                outtextxy(170+(17*(49-l)/2),220,q2);

                settextstyle(1,HORIZ_DIR,7);
                outtextxy(screenwidth-50,0,"||");

                POINT co;
                GetCursorPos(&co);
                mx=co.x;
                my=co.y;

                if(mx>259 && mx<931 && my>279+30-3 && my<351+30-3)
                {
                    setcolor(RED);
                    rectangle(260,280,930,350);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,290,a);
                }
                else
                {

                    setcolor(WHITE);
                    rectangle(260,280,930,350);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,290,a);
                }
                if(mx>259 && mx<931 && my>366+30-3 && my<436+30-3)
                {
                    setcolor(RED);
                    rectangle(260,365,930,435);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,376,b);
                }
                else
                {
                    setcolor(WHITE);
                    rectangle(260,365,930,435);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,376,b);
                }


                if(mx>259 && mx<931 && my<521+30-3 && my>451+30-3)
                {
                    setcolor(RED);
                    rectangle(260,450,930,520);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,460,c);
                }
                else
                {
                    setcolor(WHITE);
                    rectangle(260,450,930,520);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,460,c);
                }
                if(mx>259 && mx<931 && my<606+30-3 && my>534+30-3)
                {
                    setcolor(RED);
                    rectangle(260,535,930,605);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,545,d);
                }
                else
                {
                    setcolor(WHITE);
                    rectangle(260,535,930,605);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,545,d);
                }
                while(ismouseclick(WM_LBUTTONDOWN))
                {
                    getmouseclick(WM_LBUTTONDOWN,x,y);

                }
                if(x && y && mx>screenwidth-100 && mx<=screenwidth && my>0 && my<=100)
                {
                    cleardevice();
                    pause();
                    cleardevice();
                }
                if(i==0 || i==2)
                    if(x && y && mx>259 && mx<931 && my<351+30-3 && my>279+30-3)
                    {
                        x=0;
                        y=0;
                        score++;

                        cleardevice();
                        break;
                    }

                    else if( x && y &&
                             ((mx>259 && mx<931 && my>366+30-3 && my<436+30-3) ||
                              (mx>259 && mx<931 && my<521+30-3 && my>451+30-3) ||
                              (mx>259 && mx<931 && my<606+30-3 && my>534+30-3)))
                    {
                        x=0;
                        y=0;
                        life--;

                        //cleardevice();
                        break;

                    }
                if( i==1 || i==3)
                    if(x && y && mx>259 && mx<931 && my>366+30-3 && my<436+30-3)
                    {
                        x=0;
                        y=0;
                        score++;

                        cleardevice();
                        break;
                    }

                    else if( x && y &&
                             ((mx>259 && mx<931 && my<351+30-3 && my>279+30-3) ||
                              (mx>259 && mx<931 && my<521+30-3 && my>451+30-3) ||
                              (mx>259 && mx<931 && my<606+30-3 && my>534+30-3)))
                    {
                        x=0;
                        y=0;
                        life--;

                        //     cleardevice();
                        break;

                    }
                if(i==4)
                    if( x && y && mx>259 && mx<931 && my<521+30-3 && my>451+30-3)
                    {
                        x=0;
                        y=0;

                        score++;
                        cleardevice();
                        break;
                    }

                    else if( x && y &&
                             ((mx>259 && mx<931 && my<351+30-3 && my>279+30-3) ||
                              (mx>259 && mx<931 && my>366+30-3 && my<436+30-3) ||
                              (mx>259 && mx<931 && my<606+30-3 && my>534+30-3)))
                    {
                        x=0;
                        y=0;
                        life--;

                        //     cleardevice();
                        break;

                    }



                x=0;
                y=0;




                delay(200);
            }
            if(t>72)
                life--;
            if(life==0)
                gameover();
            break;

        }

    }
    cleardevice();
    one_two();

}
void one_two()
{
    char arr[100],ar[100];
    int x=0,y=0;
    double t;

    while(1)
    {
        for(t=0; t<=72; t++)
        {

            if(t>63 && t<73)
            {
                setcolor(RED);
                sprintf(ar,"  TIME  OVER  ");
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(600,0,ar);
            }
            else
            {
                setcolor(GREEN);
                sprintf(ar,"%.0lf seconds left",9-t/8);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(600,0,ar);
            }
            setcolor(GREEN);
            sprintf(arr,"FINAL DEATH 2");
            settextstyle(3,HORIZ_DIR,4);
            outtextxy(0,0,arr);
            setcolor(WHITE);
            sprintf(arr,"Mary's Father had 5 daughter's.");
            settextstyle(1,HORIZ_DIR,4);
            outtextxy(350,200,arr);
            sprintf(arr,"1.Tana 2.Tene 3.Tini 4.Tono 5.\" ?\"");
            settextstyle(1,HORIZ_DIR,4);
            outtextxy(350,250,arr);


            setcolor(GREEN);
            sprintf(ar,"SCORE:%d",score);
            settextstyle(3,HORIZ_DIR,4);
            outtextxy(300,0,ar);

            setcolor(RED);
            sprintf(ar,"Life:%d",life);
            settextstyle(3,HORIZ_DIR,4);
            outtextxy(1000,0,ar);


            setcolor(CYAN);
            settextstyle(3,HORIZ_DIR,3);
            outtextxy(0,40,"                        YOU MUST ANSWER THIS CORRECTLY TO GO TO THE NEXT LEVEL.KNOW WHERE YOU'RE CLICKING");

            settextstyle(1,HORIZ_DIR,7);
            outtextxy(screenwidth-50,0,"||");

            POINT co;
            GetCursorPos(&co);
            mx=co.x;
            my=co.y;
            if(mx>349 && mx<631 && my>339+30-3 && my<481+30-3)
            {
                setcolor(RED);
                rectangle(350,340,630,480);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(480,390,"Tunu");
            }
            else
            {

                setcolor(WHITE);
                rectangle(350,340,630,480);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(480,390,"Tunu");
            }
            if(mx>749 && mx<1031 && my>339+30-3 && my<481+30-3)
            {
                setcolor(RED);
                rectangle(670+80,340,950+80,480);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(850,390,"Tina");
            }
            else
            {
                setcolor(WHITE);
                rectangle(670+80,340,950+80,480);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(850,390,"Tina");
            }


            if(mx>749 && mx<1031 && my<691+30-3 && my>549+30-3)
            {
                setcolor(RED);
                rectangle(670+80,550,950+80,690);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(850,600,"Tona");
            }
            else
            {
                setcolor(WHITE);
                rectangle(670+80,550,950+80,690);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(850,600,"Tona");
            }
            if(mx>349 && mx<631 && my<691+30-3 && my>549+30-3)
            {
                setcolor(RED);
                rectangle(350,550,630,690);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(450,600,"Tuni");
            }
            else
            {
                setcolor(WHITE);
                rectangle(350,550,630,690);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(450,600,"Tuni");
            }
            while(ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN,x,y);

            }
            if(x && y && mx>screenwidth-100 && mx<=screenwidth && my>0 && my<=100)
            {
                cleardevice();
                pause();
                cleardevice();
            }
            if(x && y && mx>355 && mx<470 && my<250+30-3 && my>201+30-3)
            {

                cleardevice();
                score+=5;


                level_three();
                break;
            }
            else if(x && y &&
                    ((mx>349 && mx<631 && my<691+30-3 && my>549+30-3) ||
                     (mx>749 && mx<1031 && my>339+30-3 && my<481+30-3) ||
                     (mx>349 && mx<631 && my>339+30-3 && my<481+30-3)))
            {
                break;
            }
            x=0;
            y=0;
            delay(200);

        }
        break;
    }

    cleardevice();
    gameover();

}

void level_three()
{
    FILE *one=fopen("mysticmathP1.txt","r");
    char q1[100],ar[100],a[100],b[100],c[100],d[100],q2[100];
    int x=0,y=0,l,life=2;
    double t;
    readimagefile("Slide3.jpg",0,0,screenwidth,screenheight);
    delay(2000);
    for(int i=0; i<5; i++)

    {

        cleardevice();

        fscanf(one," %[^\n]",q1);
        fscanf(one," %[^\n]",q2);
        fscanf(one," %[^\n]",a);
        fscanf(one," %[^\n]",b);
        fscanf(one," %[^\n]",c);
        fscanf(one," %[^\n]",d);

        while(1)
        {
            for(t=0; t<=72; t++)
            {

                if(t>63 && t<73)
                {
                    setcolor(RED);
                    sprintf(ar,"  TIME  OVER  ");
                    settextstyle(3,HORIZ_DIR,4);
                    outtextxy(600,0,ar);
                }
                else
                {
                    setcolor(GREEN);
                    sprintf(ar,"%.0lf seconds left",9-t/8);
                    settextstyle(3,HORIZ_DIR,4);
                    outtextxy(600,0,ar);
                }


                setcolor(GREEN);
                sprintf(ar,"LEVEL:3-%d",i+1);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(0,0,ar);


                setcolor(GREEN);
                sprintf(ar,"SCORE:%d",score);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(300,0,ar);

                setcolor(RED);
                sprintf(ar,"Life:%d",life);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(1000,0,ar);

                setcolor(WHITE);

                settextstyle(1,HORIZ_DIR,3);
                l=strlen(q1);
                outtextxy(170+(17*(49-l)/2),170,q1);
                l=strlen(q2);
                outtextxy(170+(17*(49-l)/2),220,q2);

                settextstyle(1,HORIZ_DIR,7);
                outtextxy(screenwidth-50,0,"||");
                POINT co;
                GetCursorPos(&co);
                mx=co.x;
                my=co.y;

                if(mx>259 && mx<931 && my>279+30-3 && my<351+30-3)
                {
                    setcolor(RED);
                    rectangle(260,280,930,350);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,290,a);
                }
                else
                {

                    setcolor(WHITE);
                    rectangle(260,280,930,350);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,290,a);
                }
                if(mx>259 && mx<931 && my>366+30-3 && my<436+30-3)
                {
                    setcolor(RED);
                    rectangle(260,365,930,435);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,376,b);
                }
                else
                {
                    setcolor(WHITE);
                    rectangle(260,365,930,435);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,376,b);
                }


                if(mx>259 && mx<931 && my<521+30-3 && my>451+30-3)
                {
                    setcolor(RED);
                    rectangle(260,450,930,520);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,460,c);
                }
                else
                {
                    setcolor(WHITE);
                    rectangle(260,450,930,520);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,460,c);
                }
                if(mx>259 && mx<931 && my<606+30-3 && my>534+30-3)
                {
                    setcolor(RED);
                    rectangle(260,535,930,605);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,545,d);
                }
                else
                {
                    setcolor(WHITE);
                    rectangle(260,535,930,605);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,545,d);
                }
                while(ismouseclick(WM_LBUTTONDOWN))
                {
                    getmouseclick(WM_LBUTTONDOWN,x,y);

                }
                if(x && y && mx>screenwidth-100 && mx<=screenwidth && my>0 && my<=100)
                {
                    cleardevice();
                    pause();
                    cleardevice();
                }
                if(i==0 || i==1 || i==3)
                    if(x && y && mx>259 && mx<931 && my<351+30-3 && my>279+30-3)
                    {
                        x=0;
                        y=0;
                        score++;

                        cleardevice();
                        break;
                    }

                    else if( x && y &&
                             ((mx>259 && mx<931 && my>366+30-3 && my<436+30-3) ||
                              (mx>259 && mx<931 && my<521+30-3 && my>451+30-3) ||
                              (mx>259 && mx<931 && my<606+30-3 && my>534+30-3)))
                    {
                        x=0;
                        y=0;
                        life--;

                        //cleardevice();
                        break;

                    }
                if( i==2 || i==4)
                    if(x && y && mx>259 && mx<931 && my>366+30-3 && my<436+30-3)
                    {
                        x=0;
                        y=0;
                        score++;

                        cleardevice();
                        break;
                    }

                    else if( x && y &&
                             ((mx>259 && mx<931 && my<351+30-3 && my>279+30-3) ||
                              (mx>259 && mx<931 && my<521+30-3 && my>451+30-3) ||
                              (mx>259 && mx<931 && my<606+30-3 && my>534+30-3)))
                    {
                        x=0;
                        y=0;
                        life--;

                        //     cleardevice();
                        break;

                    }



                x=0;
                y=0;




                delay(200);
            }
            if(t>72)
                life--;
            if(life==0)
                gameover();
            break;

        }

    }
    cleardevice();
    one_three();

}

void start_page()
{
    life=2;
    score=0;

    int x=0,y=0;
    readimagefile("startpage.jpg",0,0,screenwidth,screenheight);
    for(long long i=1;; i++)
    {





        POINT co;
        GetCursorPos(&co);
        mx=co.x;
        my=co.y;

        if(mx>599 && mx<801 && my<331+30-3 && my>249+30-3)
        {
            setcolor(RED);
            rectangle(600,250,800,330);
            settextstyle(1,HORIZ_DIR,4);
            outtextxy(620,275,"START");
        }
        else
        {

            setcolor(WHITE);
            rectangle(600,250,800,330);
            settextstyle(1,HORIZ_DIR,4);
            outtextxy(620,275,"START");
        }
        if(mx>599 && mx<801 && my>399+30-3 && my<501+30-3)
        {
            setcolor(RED);
            rectangle(600,400,800,500);
            settextstyle(1,HORIZ_DIR,4);
            outtextxy(640,270+150,"HIGH");
            settextstyle(1,HORIZ_DIR,4);
            outtextxy(620,270+180,"SCORE");
        }
        else
        {
            setcolor(WHITE);
            rectangle(600,400,800,500);
            settextstyle(1,HORIZ_DIR,4);
            outtextxy(640,270+150,"HIGH");
            settextstyle(1,HORIZ_DIR,4);
            outtextxy(620,270+180,"SCORE");
        }


        if(mx>599 && mx<801 && my<621+30-3 && my>549+30-3)
        {
            setcolor(RED);
            rectangle(600,550,800,620);
            settextstyle(1,HORIZ_DIR,4);
            outtextxy(640,270+300,"EXIT");
        }
        else
        {
            setcolor(WHITE);
            rectangle(600,550,800,620);
            settextstyle(1,HORIZ_DIR,4);
            outtextxy(640,270+300,"EXIT");
        }
        if(mx>screenwidth-60 && mx<=screenwidth && my>0 && my<=100)
        {
            setcolor(RED);
            settextstyle(1,HORIZ_DIR,7);
            outtextxy(screenwidth-50,0,"?");
        }
        else
        {
            setcolor(WHITE);
            settextstyle(1,HORIZ_DIR,7);
            outtextxy(screenwidth-50,0,"?");
        }
        while(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,x,y);

        }
        if(x && y && mx>screenwidth-100 && mx<=screenwidth && my>0 && my<=100)
        {
            cleardevice();
            readimagefile("inst.jpg",0,0,screenwidth,screenheight);
            getch();
            cleardevice();
            start_page();
        }
        if(x && y && mx>599 && mx<801 && my<501+30-3 && my>398+30-3)
        {


            highscore();
            x=0;
            y=0;
            start_page();

        }
        if(x && y && mx>599 && mx<801 && my<621+30-3 && my>549+30-3)
        {
            closegraph();


        }

        else if(x && y && mx>599 && mx<801 && my<331+30-3 && my>249+30-3)
        {

            cleardevice();
            entername();
            level_one();
            break;
        }
        else
        {
            x=0;
            y=0;
        }

        delay(200);
    }
}

void one_three()
{
    char arr[100],ar[100];
    int x=0,y=0;
    double t;

    while(1)
    {
        for(t=0; t<=72; t++)
        {

            if(t>63 && t<73)
            {
                setcolor(RED);
                sprintf(ar,"  TIME  OVER  ");
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(600,0,ar);
            }
            else
            {
                setcolor(GREEN);
                sprintf(ar,"%.0lf seconds left",9-t/8);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(600,0,ar);
            }
            setcolor(GREEN);
            sprintf(arr,"FINAL DEATH 3");
            settextstyle(3,HORIZ_DIR,4);
            outtextxy(0,0,arr);
            setcolor(WHITE);
            sprintf(arr,"I can be anywhere.LOOK AROUND!");
            settextstyle(1,HORIZ_DIR,4);
            outtextxy(350,200,arr);
            sprintf(arr,"Where am I? Where am I?");
            settextstyle(1,HORIZ_DIR,4);
            outtextxy(350,250,arr);


            setcolor(GREEN);
            sprintf(ar,"SCORE:%d",score);
            settextstyle(3,HORIZ_DIR,4);
            outtextxy(300,0,ar);

            setcolor(RED);
            sprintf(ar,"Life:%d",life);
            settextstyle(3,HORIZ_DIR,4);
            outtextxy(1000,0,ar);


            setcolor(CYAN);
            settextstyle(3,HORIZ_DIR,3);
            outtextxy(0,40,"                        YOU MUST ANSWER THIS CORRECTLY TO GO TO THE NEXT LEVEL.KNOW WHERE YOU'RE CLICKING");


            settextstyle(1,HORIZ_DIR,7);
            outtextxy(screenwidth-50,0,"||");

            POINT co;
            GetCursorPos(&co);
            mx=co.x;
            my=co.y;
            if(mx>349 && mx<631 && my>339+30-3 && my<481+30-3)
            {
                setcolor(RED);
                rectangle(350,340,630,480);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(480,390,"HERE");
            }
            else
            {

                setcolor(WHITE);
                rectangle(350,340,630,480);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(480,390,"HERE");
            }
            if(mx>749 && mx<1031 && my>339+30-3 && my<481+30-3)
            {
                setcolor(RED);
                rectangle(670+80,340,950+80,480);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(850,390,"HERE");
            }
            else
            {
                setcolor(WHITE);
                rectangle(670+80,340,950+80,480);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(850,390,"HERE");
            }


            if(mx>749 && mx<1031 && my<691+30-3 && my>549+30-3)
            {
                setcolor(RED);
                rectangle(670+80,550,950+80,690);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(850,600,"HERE");
            }
            else
            {
                setcolor(WHITE);
                rectangle(670+80,550,950+80,690);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(850,600,"HERE");
            }
            if(mx>349 && mx<631 && my<691+30-3 && my>549+30-3)
            {
                setcolor(RED);
                rectangle(350,550,630,690);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(450,600,"HERE");
            }
            else
            {
                setcolor(WHITE);
                rectangle(350,550,630,690);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(450,600,"HERE");
            }
            if(mx>100 && mx<350 && my<130 && my>85)
            {
                setcolor(RED);

                settextstyle(1,HORIZ_DIR,4);
                outtextxy(100,70,"Hi There :3");
            }
            else
            {
                setcolor(BLACK);

                settextstyle(1,HORIZ_DIR,4);
                outtextxy(100,70,"Hi There :3");
            }
            while(ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN,x,y);

            }
            if(x && y && mx>screenwidth-100 && mx<=screenwidth && my>0 && my<=100)
            {
                cleardevice();
                pause();
                cleardevice();
            }
            if(x && y && mx>100 && mx<350 && my<130 && my>85)
            {

                cleardevice();
                score+=5;


                level_four();
                break;
            }
            else if(x && y &&
                    (((mx>349 && mx<631 && my<691+30-3 && my>549+30-3) ||
                      (mx>749 && mx<1031 && my>339+30-3 && my<481+30-3) ||
                      (mx>349 && mx<631 && my>339+30-3 && my<481+30-3) ||
                      (mx>749 && mx<1031 && my<691+30-3 && my>549+30-3))))
            {
                break;
            }
            x=0;
            y=0;
            delay(200);

        }
        break;
    }

    cleardevice();
    gameover();

}

void level_four()
{
    FILE *one=fopen("mysticmathP2.txt","r");
    char q1[100],ar[100],a[100],b[100],c[100],d[100],q2[100];
    int x=0,y=0,l,life=2;
    double t;
    readimagefile("Slide4.jpg",0,0,screenwidth,screenheight);
    delay(2000);
    for(int i=0; i<5; i++)

    {

        cleardevice();

        fscanf(one," %[^\n]",q1);
        fscanf(one," %[^\n]",q2);
        fscanf(one," %[^\n]",a);
        fscanf(one," %[^\n]",b);
        fscanf(one," %[^\n]",c);
        fscanf(one," %[^\n]",d);

        while(1)
        {
            for(t=0; t<=72; t++)
            {

                if(t>63 && t<73)
                {
                    setcolor(RED);
                    sprintf(ar,"  TIME  OVER  ");
                    settextstyle(3,HORIZ_DIR,4);
                    outtextxy(600,0,ar);
                }
                else
                {
                    setcolor(GREEN);
                    sprintf(ar,"%.0lf seconds left",9-t/8);
                    settextstyle(3,HORIZ_DIR,4);
                    outtextxy(600,0,ar);
                }


                setcolor(GREEN);
                sprintf(ar,"LEVEL:4-%d",i+1);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(0,0,ar);


                setcolor(GREEN);
                sprintf(ar,"SCORE:%d",score);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(300,0,ar);

                setcolor(RED);
                sprintf(ar,"Life:%d",life);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(1000,0,ar);

                setcolor(WHITE);

                settextstyle(1,HORIZ_DIR,3);
                l=strlen(q1);
                outtextxy(170+(17*(49-l)/2),170,q1);
                l=strlen(q2);
                outtextxy(170+(17*(49-l)/2),220,q2);

                settextstyle(1,HORIZ_DIR,7);
                outtextxy(screenwidth-50,0,"||");

                POINT co;
                GetCursorPos(&co);
                mx=co.x;
                my=co.y;

                if(mx>259 && mx<931 && my>279+30-3 && my<351+30-3)
                {
                    setcolor(RED);
                    rectangle(260,280,930,350);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,290,a);
                }
                else
                {

                    setcolor(WHITE);
                    rectangle(260,280,930,350);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,290,a);
                }
                if(mx>259 && mx<931 && my>366+30-3 && my<436+30-3)
                {
                    setcolor(RED);
                    rectangle(260,365,930,435);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,376,b);
                }
                else
                {
                    setcolor(WHITE);
                    rectangle(260,365,930,435);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,376,b);
                }


                if(mx>259 && mx<931 && my<521+30-3 && my>451+30-3)
                {
                    setcolor(RED);
                    rectangle(260,450,930,520);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,460,c);
                }
                else
                {
                    setcolor(WHITE);
                    rectangle(260,450,930,520);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,460,c);
                }
                if(mx>259 && mx<931 && my<606+30-3 && my>534+30-3)
                {
                    setcolor(RED);
                    rectangle(260,535,930,605);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,545,d);
                }
                else
                {
                    setcolor(WHITE);
                    rectangle(260,535,930,605);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,545,d);
                }
                while(ismouseclick(WM_LBUTTONDOWN))
                {
                    getmouseclick(WM_LBUTTONDOWN,x,y);

                }
                if(x && y && mx>screenwidth-100 && mx<=screenwidth && my>0 && my<=100)
                {
                    cleardevice();
                    pause();
                    cleardevice();
                }
                if(i==0)
                    if(x && y && mx>259 && mx<931 && my<351+30-3 && my>279+30-3)
                    {
                        x=0;
                        y=0;
                        score++;

                        cleardevice();
                        break;
                    }

                    else if( x && y &&
                             ((mx>259 && mx<931 && my>366+30-3 && my<436+30-3) ||
                              (mx>259 && mx<931 && my<521+30-3 && my>451+30-3) ||
                              (mx>259 && mx<931 && my<606+30-3 && my>534+30-3)))
                    {
                        x=0;
                        y=0;
                        life--;

                        //cleardevice();
                        break;

                    }
                if( i==2)
                    if(x && y && mx>259 && mx<931 && my>366+30-3 && my<436+30-3)
                    {
                        x=0;
                        y=0;
                        score++;

                        cleardevice();
                        break;
                    }

                    else if( x && y &&
                             ((mx>259 && mx<931 && my<351+30-3 && my>279+30-3) ||
                              (mx>259 && mx<931 && my<521+30-3 && my>451+30-3) ||
                              (mx>259 && mx<931 && my<606+30-3 && my>534+30-3)))
                    {
                        x=0;
                        y=0;
                        life--;

                        //     cleardevice();
                        break;

                    }
                if(i==3 || i==4)
                    if( x && y && mx>259 && mx<931 && my<521+30-3 && my>451+30-3)
                    {
                        x=0;
                        y=0;

                        score++;
                        cleardevice();
                        break;
                    }

                    else if( x && y &&
                             ((mx>259 && mx<931 && my<351+30-3 && my>279+30-3) ||
                              (mx>259 && mx<931 && my>366+30-3 && my<436+30-3) ||
                              (mx>259 && mx<931 && my<606+30-3 && my>534+30-3)))
                    {
                        x=0;
                        y=0;
                        life--;

                        //     cleardevice();
                        break;

                    }
                if(i==1)
                    if(x && y && mx>259 && mx<931 && my<606+30-3 && my>534+30-3)
                    {
                        x=0;
                        y=0;

                        score++;
                        cleardevice();
                        break;
                    }

                    else if( x && y &&
                             ((mx>259 && mx<931 && my<351+30-3 && my>279+30-3) ||
                              (mx>259 && mx<931 && my>366+30-3 && my<436+30-3) ||
                              (mx>259 && mx<931 && my<521+30-3 && my>451+30-3)))
                    {
                        x=0;
                        y=0;
                        life--;

                        //     cleardevice();
                        break;

                    }


                x=0;
                y=0;




                delay(200);
            }
            if(t>72)
                life--;
            if(life==0)
                gameover();
            break;

        }

    }
    cleardevice();
    one_four();

}

void one_four()
{
    char arr[100],ar[100];
    int x=0,y=0;
    double t;
    readimagefile("potato.jpg",0,500,screenwidth,screenheight);
    while(1)
    {
        for(t=0; t<=72; t++)
        {

            if(t>63 && t<73)
            {
                setcolor(RED);
                sprintf(ar,"  TIME  OVER  ");
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(600,0,ar);
            }
            else
            {
                setcolor(GREEN);
                sprintf(ar,"%.0lf seconds left",9-t/8);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(600,0,ar);
            }

            setcolor(GREEN);
            sprintf(arr,"FINAL DEATH 4");
            settextstyle(3,HORIZ_DIR,4);
            outtextxy(0,0,arr);
            setcolor(WHITE);
            sprintf(arr,"Where was the world's first potato found?");
            settextstyle(1,HORIZ_DIR,4);
            outtextxy(235,120,arr);


            setcolor(GREEN);
            sprintf(ar,"SCORE:%d",score);
            settextstyle(3,HORIZ_DIR,4);
            outtextxy(300,0,ar);

            setcolor(RED);
            sprintf(ar,"Life:%d",life);
            settextstyle(3,HORIZ_DIR,4);
            outtextxy(1000,0,ar);

            setcolor(CYAN);
            settextstyle(3,HORIZ_DIR,3);
            outtextxy(0,40,"                        YOU MUST ANSWER THIS CORRECTLY TO GO TO THE NEXT LEVEL.KNOW WHERE YOU'RE CLICKING");

            settextstyle(1,HORIZ_DIR,7);
            outtextxy(screenwidth-50,0,"||");

            POINT co;
            GetCursorPos(&co);
            mx=co.x;
            my=co.y;
            if(mx>349 && mx<631 && my>219+30-3 && my<321+30-3)
            {
                setcolor(RED);
                rectangle(350,220,630,320);
                settextstyle(1,HORIZ_DIR,3);
                outtextxy(390,230+20,"Bakshi Bazar");
            }
            else
            {
                {
                    setcolor(WHITE);
                    rectangle(350,220,630,320);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(390,230+20,"Bakshi Bazar");
                }

            }
            if(mx>749 && mx<1031 && my>219+30-3 && my<321+30-3)
            {
                setcolor(RED);

                rectangle(670+80,220,950+80,320);
                settextstyle(1,HORIZ_DIR,3);
                outtextxy(735+40,230+20,"Meena Bazar");
            }
            else
            {
                setcolor(WHITE);
                rectangle(670+80,220,950+80,320);
                settextstyle(1,HORIZ_DIR,3);
                outtextxy(735+40,230+20,"Meena Bazar");

            }


            if(mx>749 && mx<1031 && my<481+30-3 && my>379+30-3)
            {
                setcolor(RED);
                rectangle(670+80,380,950+80,480);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(755+80,390+20,"Mars");
            }
            else
            {
                setcolor(WHITE);
                rectangle(670+80,380,950+80,480);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(755+80,390+20,"Mars");
            }
            if(mx>349 && mx<631 && my<481+30-3 && my>379+30-3)
            {
                setcolor(RED);
                rectangle(350,380,630,480);
                settextstyle(1,HORIZ_DIR,3);
                outtextxy(370,390+20+5,"Tikatulir mor");
            }
            else
            {
                setcolor(WHITE);
                rectangle(350,380,630,480);
                settextstyle(1,HORIZ_DIR,3);
                outtextxy(370,390+20+5,"Tikatulir mor");
            }

            while(ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN,x,y);

            }
            if(x && y && mx>screenwidth-100 && mx<=screenwidth && my>0 && my<=100)
            {
                cleardevice();
                pause();
                cleardevice();
            }
            if(x && y && my>500)
            {

                cleardevice();
                score+=5;


                level_five();
                break;
            }
            else if(x && y &&
                    (((mx>349 && mx<631 && my<691+30-3 && my>549+30-3) ||
                      (mx>749 && mx<1031 && my>339+30-3 && my<481+30-3) ||
                      (mx>349 && mx<631 && my>339+30-3 && my<481+30-3) ||
                      (mx>749 && mx<1031 && my<691+30-3 && my>549+30-3))))
            {
                break;
            }
            x=0;
            y=0;
            delay(200);

        }
        break;
    }

    cleardevice();
    //gameover();

}
void level_five()
{
    FILE *one=fopen("memory.txt","r");
    char q1[100],ar[100],a[100],b[100],c[100],d[100],q2[100];
    int x=0,y=0,l,life=2;
    double t;
    readimagefile("Slide5.jpg",0,0,screenwidth,screenheight);
    delay(2000);
    for(int i=0; i<5; i++)

    {

        cleardevice();

        fscanf(one," %[^\n]",q1);
        fscanf(one," %[^\n]",q2);
        fscanf(one," %[^\n]",a);
        fscanf(one," %[^\n]",b);
        fscanf(one," %[^\n]",c);
        fscanf(one," %[^\n]",d);

        while(1)
        {
            for(t=0; t<=72; t++)
            {

                if(t>63 && t<73)
                {
                    setcolor(RED);
                    sprintf(ar,"  TIME  OVER  ");
                    settextstyle(3,HORIZ_DIR,4);
                    outtextxy(600,0,ar);
                }
                else
                {
                    setcolor(GREEN);
                    sprintf(ar,"%.0lf seconds left",9-t/8);
                    settextstyle(3,HORIZ_DIR,4);
                    outtextxy(600,0,ar);
                }


                setcolor(GREEN);
                sprintf(ar,"LEVEL:1-%d",i+1);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(0,0,ar);


                setcolor(GREEN);
                sprintf(ar,"SCORE:%d",score);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(300,0,ar);

                setcolor(RED);
                sprintf(ar,"Life:%d",life);
                settextstyle(3,HORIZ_DIR,4);
                outtextxy(1000,0,ar);

                setcolor(WHITE);

                settextstyle(1,HORIZ_DIR,3);
                l=strlen(q1);
                outtextxy(170+(17*(49-l)/2),170,q1);
                l=strlen(q2);
                outtextxy(170+(17*(49-l)/2),220,q2);

                settextstyle(1,HORIZ_DIR,7);
                outtextxy(screenwidth-50,0,"||");
                POINT co;
                GetCursorPos(&co);
                mx=co.x;
                my=co.y;

                if(mx>259 && mx<931 && my>279+30-3 && my<351+30-3)
                {
                    setcolor(RED);
                    rectangle(260,280,930,350);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,290,a);
                }
                else
                {

                    setcolor(WHITE);
                    rectangle(260,280,930,350);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,290,a);
                }
                if(mx>259 && mx<931 && my>366+30-3 && my<436+30-3)
                {
                    setcolor(RED);
                    rectangle(260,365,930,435);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,376,b);
                }
                else
                {
                    setcolor(WHITE);
                    rectangle(260,365,930,435);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,376,b);
                }


                if(mx>259 && mx<931 && my<521+30-3 && my>451+30-3)
                {
                    setcolor(RED);
                    rectangle(260,450,930,520);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,460,c);
                }
                else
                {
                    setcolor(WHITE);
                    rectangle(260,450,930,520);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,460,c);
                }
                if(mx>259 && mx<931 && my<606+30-3 && my>534+30-3)
                {
                    setcolor(RED);
                    rectangle(260,535,930,605);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,545,d);
                }
                else
                {
                    setcolor(WHITE);
                    rectangle(260,535,930,605);
                    settextstyle(1,HORIZ_DIR,3);
                    outtextxy(270,545,d);
                }
                while(ismouseclick(WM_LBUTTONDOWN))
                {
                    getmouseclick(WM_LBUTTONDOWN,x,y);

                }
                if(x && y && mx>screenwidth-100 && mx<=screenwidth && my>0 && my<=100)
                {
                    cleardevice();
                    pause();
                    cleardevice();
                }
                if(i==2 || i==3 || i==4)
                    if( x && y && mx>259 && mx<931 && my<521+30-3 && my>451+30-3)
                    {
                        x=0;
                        y=0;

                        score+=2;
                        cleardevice();
                        break;
                    }

                    else if( x && y &&
                             ((mx>259 && mx<931 && my<351+30-3 && my>279+30-3) ||
                              (mx>259 && mx<931 && my>366+30-3 && my<436+30-3) ||
                              (mx>259 && mx<931 && my<606+30-3 && my>534+30-3)))
                    {
                        x=0;
                        y=0;
                        life--;

                        //     cleardevice();
                        break;

                    }
                if(i==0 || i==1)
                    if(x && y && mx>259 && mx<931 && my<606+30-3 && my>534+30-3)
                    {
                        x=0;
                        y=0;

                        score+=2;
                        cleardevice();
                        break;
                    }

                    else if( x && y &&
                             ((mx>259 && mx<931 && my<351+30-3 && my>279+30-3) ||
                              (mx>259 && mx<931 && my>366+30-3 && my<436+30-3) ||
                              (mx>259 && mx<931 && my<521+30-3 && my>451+30-3)))
                    {
                        x=0;
                        y=0;
                        life--;

                        //     cleardevice();
                        break;

                    }


                x=0;
                y=0;




                delay(200);
            }
            if(t>72)
                life--;
            if(life==0)
                gameover();
            break;

        }

    }
    cleardevice();
    gameover();


}


int main()
{

    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C://TC//BGI");

    initwindow(screenwidth,screenheight,"sfsfs");
    score=0;
    life=2;
    start_page();


    getch();
    closegraph();

}

