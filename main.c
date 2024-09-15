#include "atlas.h"
#include "attendance_tracker.h"
#include "buckshot_roulette.h"
#include "emergency.h"
#include "medic.h"
#include "networkchart.h"
#include "timetable.h"
#include "todolist.h"
#include "cpi.h"
#include "budget tracker.h"
#include<windows.h>
void clrscr()
{
    system("@cls||clear");
}
void main()
{
    while(1)
    {
        clrscr();
        int choices;
        printf("\n\n\n     WELCOME TO STUDENT MANAGEMENT SYSTEM "); // Project name
        printf("\n-------------------------------------------");
        printf("\n      1.Time table");//
        printf("\n      2.Attedance tracker");//
        printf("\n      3.CPI Calculator");//
        printf("\n      4.To do list");//
        printf("\n      5.Budget tracker");
        printf("\n      6.Network Chart");//
        printf("\n      7.Medical Information");//
        printf("\n      8.Emergency Contact");//
        printf("\n      9.Buckshot roulette");//
        printf("\n      10.Atlas");//
        printf("\n      11.Exit");
        printf("\nPlease select your choice:");
        scanf("%d", &choices);
        if (choices==1)
        {
            clrscr();
            ttmain();
        }
        else if (choices==2)
        {
            clrscr();
            attmain();
        }
        else if (choices==3)
        {
            clrscr();
            cpimain();
        }
        else if (choices==4)
        {
            clrscr();
            tdlmain();
        }
        else if (choices==5)
        {
            clrscr();
            btmain();
        }
        else if (choices==6)
        {
            clrscr();
            ncmain();
        }
        else if (choices==7)
        {
            clrscr();
            mmain();
        }
        else if (choices==8)
        {
            clrscr();
            emain();
        }
        else if (choices==9)
        {
            clrscr();
            brmain();
        }
        else if (choices==10)
        {
            clrscr();
            atlmain();
        }
        else
        {
            break;
        }
    
    
    }
}


