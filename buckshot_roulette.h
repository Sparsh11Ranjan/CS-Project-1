#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<unistd.h>
#define red "\x1b[31m"
#define green "\x1b[32m"
#define yellow "\x1b[33m"
#define white "\x1b[37m"

typedef struct stats{
    int hp;
    int item[5];
}character;
int go_on(character *you,character *dealer)
{
    if (you->hp<=0 || dealer->hp<=0)
    {
        if (you->hp<=0)
        {
            printf(red"You dont have the strength to get up anymore.\n");
            Sleep(3000);
            printf("Your vision gets blurry and ears tinging.\n");
            printf("You Died");
            printf(white"");
            Sleep(3000);
            return 0;
        }
        else
        {
            printf("The dealer isnt waking up anymore.\n");
            Sleep(3000);
            printf(green"A box of money is lying on the doorstep.\n");
            printf(white"You Won!!");
            Sleep(3000);
            return 0;
        }
        
        
    }
    
}
void clearscreen()
{
    system("@cls||clear");
}
void your_items(character *you)
{
    printf("%d handcuff %d beer can %d x ray glass %d cigar %d gun powder.\n",you->item[0],you->item[1],you->item[2],you->item[3],you->item[4]);
}
int Round(character *you,character *dealer)
{
    int i,bullets;
    static int round=1;
    if (round<=2)
    {
        bullets=3+((round-1)*2);
    }
    else
    {
        bullets=8;
    }
    int gun[bullets];
    printf("Round %d",round);
    printf("\nThe dealer draws the bullets...\n");
    printf("There are %d bullets this round.\n",bullets);
    Sleep(1700);
    
    int blank=0,live=0;
    for (i = 0; i < bullets; i++)
    {
        int bullet=(rand());
        gun[i]=bullet%2;
        if (gun[i]==0)
        {
            blank++;
        }
        
    }
    live=bullets-blank;
    printf("There are %d Live and %d blank bullets.\n",live,blank);
    Sleep(1700);
    printf("\nBeing blind,he loads the gun randomly...\n");
    Sleep(5000);
    printf("The dealer offers you items randomly.\nYou get:");
    for (int i = 0; i < 3; i++)
    {
        (you->item[rand()%5])++;
    }
    Sleep(800);   
    your_items(you);
    printf("The dealer draws his items...\n ");
    Sleep(800);
    printf("He has: ");
    for (int i = 0; i < 3; i++)
    {
        dealer->item[rand()%5]++;
    }   
    printf("%d handcuff,%d beer can,%d x ray glass,%d cigar & %d gun powder.\n",dealer->item[0],dealer->item[1],dealer->item[2],dealer->item[3],dealer->item[4]);
    Sleep(1000);
    printf("The dealer offers you play first.\n");
    Sleep(6000);
    int turn=1;
    
    int you_cuffed=0;
    int dealer_cuffed=0;
    int cont;
    int just_cuffed_you=0;
    int just_cuffed_dealer=0;
    for (int i = 0; i < bullets; i++)
    {
        int dmg=1;
        
        if (turn==1)
        {
            turn_you:
            clearscreen();
            printf("Your turn...\n");
            Sleep(1000);
            if (you_cuffed==1)
            {
                printf("Your hands are tied by handcuffs, you are forced to skip the turn.");
                Sleep(3000);
                just_cuffed_you=0;
                goto turn_dealer;
            }
            
            int action;
            choosing:
            printf("Dealer is at %d HP\nYou are at %d HP.\n",dealer->hp,you->hp);
            printf("What will you do?\n1. Shoot\n2. Use item");
            scanf("%d",&action);
            clearscreen();
            if (action==1)
            {
                int choice;
                
                printf("\nWho do you shoot?\n1.Dealer\n2.Yourself\n3. Think a bit more.\n");
                scanf("%d",&choice);
                clearscreen();
                if (choice==1)
                {
                    printf("You aim at the dealer and pull the trigger.\n");
                    Sleep(2000);
                    if (gun[i]==1)
                    {
                        printf(red"The bullet was live. The dealer lost %d HP.\n",dmg);
                        (dealer->hp)-=dmg;
                        cont=go_on(you,dealer);
                        if (cont==0)
                        {
                            return 0;
                        }
                        
                        live--;
                        if (just_cuffed_dealer==0 && dealer_cuffed==1)
                        {
                            printf("The dealer breaks his cuffs.");
                            Sleep(3000);
                            dealer_cuffed=0;
                        }
                        
                        printf(white"The dealer gets the turn.\n");
                        Sleep(4000);
                        turn=0;
                        continue;
                    }
                    else if (gun[i]==0)
                    {
                        printf(yellow"The bullet was blank. The dealer gets the turn.\n");
                        printf(white"");
                        blank--;
                        if (just_cuffed_dealer==0 && dealer_cuffed==1)
                        {
                            printf("The dealer breaks his cuffs.");
                            Sleep(3000);
                            dealer_cuffed=0;
                        }
                        Sleep(4000);
                        turn=0;
                        continue;
                    }
                    
                    
                }
                if (choice==2)
                {
                    printf("You aim the gun at your head, there a hint of fear in your eyes.\n");
                    Sleep(1500);
                    printf("You pull the trigger.\n");
                    Sleep(2000);
                    if (gun[i]==1)
                    {
                        printf(red"The bullet was live. You lost %d HP\n",dmg);
                        (you->hp)-=dmg;
                        cont=go_on(you,dealer);
                        if (cont==0)
                        {
                            return 0;
                        }
                        live--;
                        Sleep(3000);
                        if (just_cuffed_dealer==0 && dealer_cuffed==1)
                        {
                            printf("The dealer breaks his cuffs.");
                            Sleep(3000);
                            dealer_cuffed=0;
                        }
                        printf(white"The dealer gets the turn.\n");
                        
                        turn=0;
                        continue;
                    }
                    else if (gun[i]==0)
                    {
                        printf(yellow"The bullet was blank. You let out a sigh of relief\n");
                        Sleep(800);
                        blank--;
                        printf(white"You retain your turn\n");
                        Sleep(2000);
                        i++;
                        goto choosing;
                        
                    }
                    
                    

                }
                if (choice==3)
                {
                    clearscreen();
                    goto choosing;
                }
                
                
                

            }
            if (action==2)
            {
                int back=0;
                while(back==0)
                {
                    your_items(you);
                    printf("1)Handcuffs\n2)Beer can\n3)X ray glass\n4)cigar\n5)gunpowder\n");
                    printf("Enter 9 key to go back:");
                    int item_choice;
                    scanf("%d",&item_choice);
                    if (item_choice==1 && (you->item[0]>0))
                    {
                        printf("You cuff the dealer. He cant play his next round.\n");
                        Sleep(3000);
                        dealer_cuffed=1;
                        just_cuffed_dealer=1;
                        (you->item[0])--;
                        continue;
                    }
                    if (item_choice==1 && (you->item[0]==0))
                    {
                        printf("You dont have any more of this item.\n");
                        Sleep(2000);
                    }
                    
                    
                    if (item_choice==2 && (you->item[1])>0)
                    {
                        clearscreen();
                        printf("You chug a beer can.\n");
                        Sleep(1200);
                        printf("You pump the shotgun.\n");
                        Sleep(1200);
                        if (i==0)
                        {
                            printf("A blank ammo ejects.\n");
                            blank--;
                            i++;
                            Sleep(1200);
                        }
                        else
                        {
                            printf("A live ammo gets ejected.\n");
                            live--;
                            i++;
                            Sleep(1200);
                        }
                        
                        
                        (you->item[1])--;
                        continue;
                    }
                    else if(item_choice==2 && (you->item[1])==0)
                    {
                        printf("You dont have any more of this item.\n");
                        Sleep(2000);
                    }
                    if (item_choice==3 && (you->item[2])>0)
                    {
                        clearscreen();
                        printf("You use the special glass to view the currently loaded bullet.\n");
                        Sleep(1200);
                        if (gun[i]==0)
                        {
                            printf("Its a blank bullet.\n");
                            Sleep(1200);
                        }
                        else
                        {
                            printf("Its a Live bullet.\n");
                            Sleep(1200);
                        }
                        
                        
                        (you->item[2])--;
                        continue;
                    }
                    else if(item_choice==3 && (you->item[2])>0)
                    {
                        printf("You dont have any more of this item.\n");
                        Sleep(2000);
                    }
                    if (item_choice==4 && (you->item[3])>0)
                    {
                        clearscreen();
                        printf("You pop a cigar.\nYour lungs gets filled with toxic fumes, yet somehow ");
                        printf(green"your HP increases by 1.\n");
                        printf(white"");
                        Sleep(2000);
                        (you->hp)++;
                        (you->item[3])--;
                        continue;
                    }
                    else if(item_choice==4 && (you->item[3])==0)
                    {
                        printf("You dont have any more of this item.\n");
                        Sleep(2000);
                    }
                    if (item_choice==5 && (you->item[4])>0)
                    {
                        clearscreen();
                        printf("You pour special gun powder in the barrel... Damage of next bullet is now twice.\n");
                        Sleep(3000);
                        dmg+=1;
                        (you->item[4])--;
                        continue;
                    }
                    else if(item_choice==5 && (you->item[4])==0)
                    {
                        printf("You dont have any more of this item.\n");
                        Sleep(2000);
                    }
                    else 
                    {
                        goto choosing;
                    }
                    
                }

                
            }
        }
        if (turn==0)
        {
            if (dealer_cuffed==1)
            {
                printf("The dealer is cuffed and cannot take this turn.");
                Sleep(3000);
                just_cuffed_dealer=0;
                goto turn_you;
            }
            
            turn_dealer:
            clearscreen();
            printf("Dealer's turn...\n");
            Sleep(1400);
            printf("He ponders for a while, there is an emptiness in his eyes\n");
            Sleep(2000);
            using_items:
            
            if (((float)live/(live+blank)<0.50 && (float)live/(live+blank)>0.40 && dealer->item[0]>0) || (((float)live/(live+blank)>0.60) && (bullets-i)>1 && dealer->item[0]>0) && you_cuffed!=1)
            {
                printf(yellow"The dealer uses handcuffs on you. You cant play your next turn.\n");
                printf(white"");
                you_cuffed=1;
                just_cuffed_you=1;
                Sleep(1500);
                (dealer->item[0])--;
            }
            if ((float)live/(live+blank)>0.40 && (float)live/(live+blank)<0.60 && dealer->item[2]>0 )
            {
                (dealer->item[2])--;
                printf("The dealer uses special glasses to view the currently loaded bullet\n");
                Sleep(3000);
                printf("Dealer: Interesting...\n");
                Sleep(4500);
                if (gun[i]==1)
                {
                    goto shoot_you;
                }
                else
                {
                    goto shoot_self;
                }
                
            }
            if ((float)live/(live+blank)<0.50 && (float)live/(live+blank)>0.40 && dealer->item[1]>0)
            {
                (dealer->item[1])--;
                printf("The dealer chugs a beer can. He pumps the shotgun\n");
                if (i==1)
                {
                    printf(yellow"A live bullet gets ejected.\n");
                    printf(white"");
                    i++;
                    goto using_items;
                }
                else if (i==0)
                {
                    printf(yellow"A blank ejects out\n");
                    printf(white"");
                    i++;
                    goto using_items;
                }
                
            }
            
            
            if ((dealer->hp)<8 && dealer->item[3]>0)
            {
                printf(yellow"The dealer smokes a cigar. his HP increased by 1\n");
                printf(white"");
                dealer->hp++;
                (dealer->item[3])--;
                Sleep(2000);
                clearscreen();
                goto using_items;
            }
            if ((float)live/(live+blank)>=0.50 && dealer->item[4]>0 )
            {
                printf(yellow"The dealer uses the special gunpowder. The next bullet damage is doubled.\n");
                printf(white"");
                dmg=2;
                Sleep(4500);
                (dealer->item[4])--;
            }

            

            
            if (live>=blank)
            {
                shoot_you:
                printf("The dealer points the gun at you and pulls the trigger.\n");
                Sleep(3000);
                if (gun[i]==1)
                {
                    clearscreen();
                    printf(red"The bullet was live, You get shot in your head.\nYou lost %d HP.\n",dmg);
                    printf(white"");
                    Sleep(2000);
                    (you->hp)-=dmg;
                    cont=go_on(you,dealer);
                    if (cont==0)
                    {
                        return 0;
                    }
                    live--;
                    turn=1;
                    if (just_cuffed_you==0 && you_cuffed==1)
                    {
                        printf("You break free of your cuffs.");
                        printf(white"");
                        Sleep(3000);
                        you_cuffed=0;
                    }
                    continue;
                    
                    
                    
                }
                
                if (gun[i]==0)
                {
                    clearscreen();
                    printf("You hear a click.\n");
                    Sleep(1000);
                    printf(white"The bullet was a blank.\n");
                    Sleep(4000);
                    blank--;
                    turn=1;
                    if (just_cuffed_you==0 && you_cuffed==1)
                    {
                        printf("You break free of your cuffs.");
                        Sleep(3000);
                        you_cuffed=0;
                    }
                    continue;
                    
                }
            }
            else
            {
                shoot_self:
                printf("The dealer points the gun himself and pulls the trigger.\n");
                Sleep(4000);
                if (gun[i]==1)
                {
                    clearscreen();
                    printf(green"The bullet was live, he got shot in his head.\nDealer lost %d HP.\n",dmg);
                    printf(white"");
                    Sleep(2000);
                    (dealer->hp)-=dmg;
                    cont=go_on(you,dealer);
                    if (cont==0)
                    {
                        return 0;
                    }
                    live--;
                    turn=1;
                    if (just_cuffed_you==0 && you_cuffed==1)
                    {
                        printf("You break free of your cuffs.");
                        Sleep(3000);
                        you_cuffed=0;
                    }
                    continue;
                    
                }
                if (gun[i]==0)
                {
                    clearscreen();
                    printf("You hear a click. \n");
                    Sleep(1000);
                    printf(green"The bullet was a blank.\nThe dealer retains his turn.\n");
                    printf(white"");
                    Sleep(4000);
                    blank--;
                    if (just_cuffed_you==0 && you_cuffed==1)
                    {
                        printf("You break free of your cuffs.");
                        Sleep(3000);
                        you_cuffed=0;
                    }
                    
                    
                }
            }
            

            
        }
        
        
        clearscreen();
    }
    
    

    
    
    
    
    
    round++;
}

int br_main_menu()
{
    int choice;
    printf(white"\n\n\n\n       Buckshot Roulette          ");
    printf("\n       1.Start game             ");
    printf("\n       2.Rules              ");
    printf("\n       3.Exit             \n");
    scanf("%d",&choice);
    return choice;
}
int rules()
{
    int exit;
    printf("\n\n\n\n8 bullets... some live, some blank.\n");
    printf("You never know which is which ;)\n");
    printf("Try your luck. Shoot your shots\n");
    printf("Defeat your enemy, Earn your $bucks$\n\n");
    printf("%cYou both have some HP, each shot deals 1 dmg to HP.\n",(char)26);
    printf("%cYou can choose to shoot yourself and get the turn again if you live\n",(char)26);
    printf("%cElse the opponent gets the turn\n",(char)26);
    printf("%cIf you choose to shoot the opponent, irrespective of hit or not\nThe opponent will have his turn\n",(char)26);
    printf("%cThere are items which can influence the tide of the game\n",(char)26);
    printf("1. Handcuffs: Forces the opponent to skip their turn\n");
    printf("2. Beer can: Eject the currently loaded bullet\n");
    printf("3. X-Ray glass: View the currently loaded bullet\n");
    printf("4: Cigar: Increase HP by 1\n");
    printf("5. Gun powder:Doubles the damage of the next bullet (Non Stackable)\n\n");
    printf("Enter 0 to exit");
    scanf("%d",&exit);
    return 0;



}
void game()
{
    character dealer,you;
    dealer.hp=8;
    you.hp=8;
    printf("The dealer emerges from the darkness");
    int n=3;
    while(n--)
    {
        Sleep(1200);
        printf(".");
    }
    Sleep(1200);
    for (int i = 0; i < 5; i++)
    {
        you.item[i]=0;
        dealer.item[i]=0;
    }
    int game_over;
    next_round:
    game_over=Round(&you,&dealer);
    if (game_over!=0)
    {
        goto next_round;
    }
    
    
    
    

    

}
void brmain()
{
    srand(time(NULL));
    while (1<2)
    {
        int choice=br_main_menu
    ();
        if (choice==1)
        {
            clearscreen();
            game();
        }
        else if (choice==2)
        {
            clearscreen();
            rules();
            clearscreen();
            continue;
        }
        else if (choice==3)
        {
            break;
        }
    }
    
    

}