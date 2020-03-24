#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

void clrscr()
{
    system("@cls||clear");
}

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

void head()
{
    printf("\t\t\t\t--------------------------------------------\n");
    printf("\t\t\t\t| @  @   @   @   @  @@@  @   @   @   @   @ |\n");
    printf("\t\t\t\t| @  @  @ @  @#  @ #     @# #@  @ @  @#  @ |\n");
    printf("\t\t\t\t| @##@ @###@ @ # @ #  ## @ # @ @###@ @ # @ |\n");
    printf("\t\t\t\t| @  @ @   @ @  #@ #   # @   @ @   @ @  #@ |\n");
    printf("\t\t\t\t| @  @ @   @ @   @  @@@  @   @ @   @ @   @ |\n");
    printf("\t\t\t\t--------------------------------------------\n\n");

}

void tittle_menu()
{
    printf("\t\t\t     \n\t\tP:PLAY \n\t\tQ:QUIT ");


}

int in_menu()
{
    int f;
    printf("\n\t\t 1: 3 LETTERS GAME \n\t\t 2: 4 LETTERS GAME \n\t\t 3: 5 LETTERS GAME \n\n\t\t \n\n\t\t 4:MAIN MENU \n\n\t\t choice =");
    scanf("%d",&f) ;

    return f ;
}

void hangman_fig()
{
    printf("\t\t\t  \n");
    printf("\t\t\t      \n");
    printf("\t\t\t      0 \n");
    printf("\t\t\t     \\|/\n");
    printf("\t\t\t      | \n");
    printf("\t\t\t     / \\\n");
    printf("\t         CAN YOU SAVE ME PLESASE ?  \n\n");
}


void hangman(int a,int score)
{
    switch (a)
    {
    case 1 :
        gotoxy(16,16);
        {
            printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
            printf("  _______\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|_________\n\n");
            printf("\nYour score = %d",score);
            printf("\n\t\t\t\t Chances Left=%d",5-a);

        }
        break;


    case 2 :
        printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
        printf("  _______\n");
        printf("  |/   | \n");
        printf("  |    O \n");
        printf("  |\n");
        printf("  |\n");
        printf("  |\n");
        printf("__|_________\n\n");
        printf("\nYour score = %d",score);
        printf("\n\t\t\t\t Chances Left=%d",5-a);
        break;

    case 3 :
        printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
        printf("  _______\n");
        printf("  |/   | \n");
        printf("  |    O \n");
        printf("  |    |\n");
        printf("  |    |\n");
        printf("  |\n");
        printf("__|_________\n\n");
        printf("\nYour score = %d",score);
        printf("\n\t\t\t\t Chances Left=%d",5-a);
        break;




    case 4 :
        printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
        printf("  _______\n");
        printf("  |/   | \n");
        printf("  |    O \n");
        printf("  |   \\|/\n");
        printf("  |    | \n");
        printf("  |   /\n");
        printf("__|_________\n\n");
        printf("\nYour score = %d",score);
        printf("\n\t\t\t\t Chances Left=%d",5-a);
        break;


    case 5 :
        printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
        printf("  _______\n");
        printf("  |/   | \n");
        printf("  |    X \n");
        printf("  |   \\|/\n");
        printf("  |    | \n");
        printf("  |   / \\\n");
        printf("__|_________\n\n");
        printf("\nTotal score = %d",score);
        printf("\n\t\t\t\t Chances Left=%d",5-a);
        printf("\n\nYOU ARE DEAD ! GAME OVER!");;
        exit(0)  ;
        break;

    }

}


int main()
{
    int life=0,score=0 ;
    int i,j,f;
    int cond = 0;
    char ch ;
    char guess[6]= {'_','_','_','_','_','_' } ;
    char word;
    char word_3[][3]= {"hat","cat","que","rat","pit","sit", "hut","cut","bit","pen"} ;
    char word_4[][4]= {"milk","soft","hard","help","talk"} ;
    char word_5[][5]= {"bread","white","coder","bread","table","tiger","china"} ;
    clrscr() ;
    do
    {
start:
        word=' ';
        i=0,j=0,life=0 ;

        clrscr() ;
        head() ;
        tittle_menu() ;
        ch=getche() ;
        if(ch=='q'||ch=='Q')
        {
            printf("\n\n\\t\t\tExiting The Game") ;
            return 0;
        }
        switch(ch)
        {
        case 'p':
        case 'P':
            clrscr() ;
            head() ;
            hangman_fig() ;
            f = in_menu() ;
            switch(f)
            {
            case 1 :
                clrscr() ;

                for(i=0; i<11; i++)
                {
                    printf("\n LEVEL %d !! GUESS THE WORD  ",i+1) ;
                    cond = 0 ;
                    life=2 ;

                    for(j=0; j<3; j++)
                    {
                        cond = 0;
                        printf("\n%c %c %c",guess[0],guess[1],guess[2]) ;
                        printf("\n\nENTER LETTER \t") ;
                        word = getch() ;
                        if(word>=41&&word<=90)
                            word+=32 ;
                        if(guess[0]==word)   //condition
                        {
                            printf("\nNot again");
                            printf("\n\t\t\t\tScore =%d",score);
                            j--;
                            goto e;

                        }
                        if(guess[1]==word)   //condition
                        {
                            printf("\nNot again");
                            printf("\n\t\t\t\tScore =%d",score);
                            j--;
                            goto e;

                        }
                        if(guess[2]==word)     //condition
                        {
                            printf("\nNot again");
                            printf("\n\t\t\t\tScore =%d",score);
                            j--;
                            goto e;

                        }

                        if(word_3[i][0]==word)      //condition
                        {
                            cond=1;
                            guess[0]=word;
                        }


                        if(word_3[i][1]==word)        //condition
                        {
                            cond=1;
                            guess[1]=word;
                        }

                        if(word_3[i][2]==word)        //condition
                        {
                            cond=1;
                            guess[2]=word;
                        }



                        if(cond==1)                  //condition
                        {
                            printf("\n\nGOOD! NEXT");
                            score++;
                            printf("\n\t\t\t\tScore =%d",score);
                        }

                        else
                        {
                            printf("\n\nTRY AGAIN !");    //condition
                            life++;
                            j--;
                            hangman(life,score);
                        }



                        if(life==5)                      //if hangman 5th steps return
                        {
                            clrscr();
                            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t TOTAL SCORE : %d ",score);

                            clrscr();
                            printf(" ");

                            clrscr();
                            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t TOTAL SCORE : %d ",score);

                            clrscr();
                            printf(" ");

                            clrscr();
                            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t TOTAL SCORE : %d ",score);

                            clrscr();
                            return 0;
                        }
                    }
e:
                    clrscr();
                    printf("\t\t\t\t JUMPING TO LEVEL %d",i+2) ;
                    clrscr();
                    guess[0]='_';
                    guess[1]='_';
                    guess[2]='_';
                    guess[3]='_';
                    guess[4]='_';
                }                    //end of outer loop
                break;
            case 2:
                clrscr();
                for(i=0; i<11; i++)
                {
                    printf("\n LEVEL %d ! GUESS THE LETTER   ",i+1);
                    cond=0;
                    life=1;

                    for(j=0; j<4; j++)
                    {
                        cond=0;
                        printf("\n%c %c %c %c",guess[0],guess[1],guess[2],guess[3]);
                        printf("\n\t\tENTER LETTER  \t");
                        word=getche();
                        if(word>=41&&word<=90)
                            word+=32;
                        if(guess[0]==word)
                        {
                            printf("\nNot again");
                            printf("\n\t\t\t\tScore =%d",score);
                            j--;
                            goto en;

                        }
                        if(guess[1]==word)
                        {
                            printf("\nNot again");
                            printf("\n\t\t\t\tScore =%d",score);
                            j--;
                            goto en;

                        }
                        if(guess[2]==word)
                        {
                            printf("\nNot again");
                            printf("\n\t\t\t\tScore =%d",score);
                            j--;
                            goto en;

                        }
                        if(guess[3]==word)
                        {
                            printf("\nNot again");
                            printf("\n\t\t\t\tScore =%d",score);
                            j--;
                            goto en;

                        }



                        if(word_4[i][0]==word)
                        {
                            cond=1;
                            guess[0]=word;
                        }


                        if(word_4[i][1]==word)
                        {
                            cond=1;
                            guess[1]=word;
                        }

                        if(word_4[i][2]==word)
                        {
                            cond=1;
                            guess[2]=word;
                        }

                        if(word_4[i][3]==word)
                        {
                            cond=1;
                            guess[3]=word;
                        }



                        if(cond==1)
                        {
                            printf("\n\nGOOD! NEXT");
                            score++;
                            printf("\n\t\t\t\tScore =%d",score);
                        }

                        else
                        {
                            printf("\n\nTRY AGAIN !");
                            life++;
                            j--;
                            hangman(life,score);
                        }



                        if(life==5)
                        {

                            clrscr();
                            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t TOTAL SCORE : %d ",score);

                            clrscr();
                            printf(" ");

                            clrscr();
                            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t TOTAL SCORE : %d ",score);

                            clrscr();
                            printf(" ");

                            clrscr();
                            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t TOTAL SCORE : %d ",score);

                            clrscr();
                            return 0;
                        }
                    }
          en:
                    clrscr();
                    printf("\n\n\n\t\t\t   JUMPING TO NEXT LEVEL %d",i+2);



                    clrscr();
                    guess[0]='_';
                    guess[1]='_';
                    guess[2]='_';
                    guess[3]='_';
                    guess[4]='_';
                }
                break;
            case 3:
                clrscr();
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t LOADING ");

                printf("..");


                printf("..");


                printf("..");


                printf("...");
                clrscr();
                for(i=0; i<11; i++)
                {
                    printf("\n LEVEL %d ! GUESS THE LETTER   ",i+1);
                    cond=0;
                    life=0;

                    for(j=0; j<5; j++)
                    {
                        cond=0;
                        printf("\n%c %c %c %c %c",guess[0],guess[1],guess[2],guess[3],guess[4]);
                        printf("\n\ENTER LETTER  \t");
                        word=getche();
                        if(word>=41&&word<=90)
                            word+=32;
                        if(guess[0]==word)
                        {
                            printf("\nNot again");
                            printf("\n\t\t\t\tScore =%d",score);
                            j--;
                            goto end;

                        }
                        if(guess[1]==word)
                        {
                            printf("\nNot again");
                            printf("\n\t\t\t\tScore =%d",score);
                            j--;
                            goto end;

                        }
                        if(guess[2]==word)
                        {
                            printf("\nNot again");
                            printf("\n\t\t\t\tScore =%d",score);
                            j--;
                            goto end;

                        }
                        if(guess[3]==word)        //if word condd before j--
                        {
                            printf("\nNot again");
                            printf("\n\t\t\t\tScore =%d",score);
                            j--;
                            goto end;

                        }
                        if(guess[4]==word)
                        {
                            printf("\nNot again");
                            printf("\n\t\t\t\tScore =%d",score);
                            j--;
                            goto end;
                        }


                        if(word_5[i][0]==word)
                        {
                            cond=1;
                            guess[0]=word;
                        }


                        if(word_5[i][1]==word)
                        {
                            cond=1;
                            guess[1]=word;
                        }

                        if(word_5[i][2]==word)
                        {
                            cond=1;
                            guess[2]=word;
                        }

                        if(word_5[i][3]==word)
                        {
                            cond=1;
                            guess[3]=word;
                        }
                        if(word_5[i][4]==word)
                        {
                            cond=1;
                            guess[4]=word;
                        }


                        if(cond==1)
                        {
                            printf("\n\nGOOD! NEXT");
                            score++;
                            printf("\n\t\t\t\tScore =%d",score);
                        }

                        else
                        {
                            printf("\n\nTRY AGAIN !");
                            life++;
                            j--;
                            hangman(life,score);
                        }



                        if(life==5)
                        {


                            clrscr();
                            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t TOTAL SCORE : %d ",score);

                            clrscr();
                            printf(" ");

                            clrscr();
                            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t TOTAL SCORE : %d ",score);

                            clrscr();
                            printf(" ");

                            clrscr();
                            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t TOTAL SCORE : %d ",score);

                            return 0;
                        }

                    }
end:
                    clrscr();

                    printf("\n\n\n\t\t\t   JUMPING TO NEXT LEVEL %d",i+2);



                    clrscr();
                    guess[0]='_';
                    guess[1]='_';
                    guess[2]='_';
                    guess[3]='_';
                    guess[4]='_';
                }
                break;
            case 4:
                goto start;
                break;
            }
            break;
        default:
            printf("\n\n\t\tINVALID SELECTION\n\n");
        }

        clrscr() ;

    }
    while(ch);
    getch();
}

