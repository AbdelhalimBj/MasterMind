#include<stdlib.h>
#include<stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include<time.h>
#include"MasterMind.h"



void Menu(SDL_Surface *imageDeFond,SDL_Surface *ecran,SDL_Rect positionFond)
{
    imageDeFond = SDL_LoadBMP("Menu.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    SDL_Event event;
    int c=1;
    while(c)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            c= 0;
            exit(EXIT_SUCCESS);
            break;
        case SDL_MOUSEBUTTONUP:
            if ( event.button.button == SDL_BUTTON_LEFT && event.button.x>194 && event.button.x<442 && event.button.y>176 && event.button.y<234)
            {
                imageDeFond = SDL_LoadBMP("MasterMind_2.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
                c= 0;
            }
            if ( event.button.button == SDL_BUTTON_LEFT && event.button.x>194 && event.button.x<442 && event.button.y>236 && event.button.y<297)
            {
                imageDeFond = SDL_LoadBMP("Help.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);

            }
            if ( event.button.button == SDL_BUTTON_LEFT && event.button.x>194 && event.button.x<442 && event.button.y>305 && event.button.y<376)
            {
                imageDeFond = SDL_LoadBMP("High_Score.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);

            }
            if ( event.button.button == SDL_BUTTON_LEFT && event.button.x>194 && event.button.x<442 && event.button.y>383 && event.button.y<430)//Exit
            {
                imageDeFond = SDL_LoadBMP("Exit.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
                SDL_Delay(1000);
                exit(EXIT_SUCCESS);
            }

        }//end switch
        if ( event.type==SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT && event.button.x>7 && event.button.x<133 && event.button.y>537 && event.button.y<599)//return from help
        {
            imageDeFond = SDL_LoadBMP("Menu.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
            SDL_Flip(ecran);
        }
        if ( event.type==SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT && event.button.x>476 && event.button.x<600 && event.button.y>520 && event.button.y<585)//return  from hight score
        {
            imageDeFond = SDL_LoadBMP("Menu.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
            SDL_Flip(ecran);
        }
    }//end while

}//end

/*void choose_Position_Color(int ligne,SDL_Surface *backGround,SDL_Surface *ecran)
{
    int c=1,nombre_Color=0,i;
    SDL_Event event;
    SDL_Rect position,position_2;
    position_2.x=408;
    position_2.y=421;
    backGround = SDL_LoadBMP("Boules_2.bmp");
    SDL_BlitSurface(backGround, NULL, ecran, &position_2);
    SDL_Flip(ecran);
            switch(ligne)
            {
            case 1:
            {
                SDL_WaitEvent(&event);
                switch(event.type)
                {
                    case SDL_MOUSEBUTTONUP :
                    if (event.button.button == SDL_BUTTON_LEFT && event.button.x>26 && event.button.x<70 && event.button.y>9 && event.button.y<53);
                    {
                        nombre_Color++;
                        position.x=26;
                        position.y=9;
                        backGround=Fill_Color(backGround,ecran);
                        SDL_BlitSurface(backGround, NULL, ecran, &position);
                        SDL_Flip(ecran);

                    }

                    if (event.button.button == SDL_BUTTON_LEFT && event.button.x>82 && event.button.x<126 && event.button.y>9 && event.button.y<53);
                    {
                        nombre_Color++;
                        position.x=82;
                        position.y=9;
                        SDL_BlitSurface(Fill_Color(backGround,ecran), NULL, ecran, &position);
                        SDL_Flip(ecran);

                    }
                    if (event.button.button == SDL_BUTTON_LEFT && event.button.x>136 && event.button.x<183 && event.button.y>9 && event.button.y<53);
                    {
                        if(nombre_Color>=4)
                            c=0;

                    }
                    if (event.button.button == SDL_BUTTON_LEFT && event.button.x>194 && event.button.x<238 && event.button.y>9 && event.button.y<53);
                    {
                        nombre_Color++;
                        position.x=194;
                        position.y=9;
                        SDL_BlitSurface(Fill_Color(backGround,ecran), NULL, ecran, &position);
                        SDL_Flip(ecran);
                    }
                    if(event.button.button == SDL_BUTTON_LEFT && event.button.x>251 && event.button.x<295 && event.button.y>9 && event.button.y<53);
                    {
                        nombre_Color++;
                        position.x=251;
                        position.y=9;
                        SDL_BlitSurface(Fill_Color(backGround,ecran), NULL, ecran, &position);
                        SDL_Flip(ecran);
                    }
                    }



          }
            case 2:
            {
                SDL_WaitEvent(&event);
                switch(event.type)
                {
                case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT && event.button.x>26 && event.button.x<70 && event.button.y>69 && event.button.y<113);
                    {
                        nombre_Color++;

                    }
                    if (event.button.button == SDL_BUTTON_LEFT && event.button.x>82 && event.button.x<126 && event.button.y>69 && event.button.y<113);
                    {
                        nombre_Color++;

                    }
                    if (event.button.button == SDL_BUTTON_LEFT && event.button.x>136 && event.button.x<183 && event.button.y>69 && event.button.y<113);
                    {
                        if(nombre_Color>=4)
                            c=0;
                    }
                    if (event.button.button == SDL_BUTTON_LEFT && event.button.x>194 && event.button.x<238 && event.button.y>69 && event.button.y<113);
                    {
                        nombre_Color++;

                    }
                    if (event.button.button == SDL_BUTTON_LEFT && event.button.x>251 && event.button.x<295 && event.button.y>69 && event.button.y<113);
                    {
                        nombre_Color++;

                    }

                }
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                break;
            }
            case 7:
            {
                break;
            }
            case 8:
            {
                break;
            }
            case 9:
            {
                break;
            }
            case 10:
            {
                break;
            }
        }
}




/*SDL_Surface *choose_Position_Color()
{
int continuer = 1;
    SDL_Event event;
    while (continuer)
        {
            SDL_WaitEvent(&event);
            switch(event.type)
                {
                    case SDL_MOUSEBUTTONUP:
{

//Line 1
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>26 && event.button.x<70 && event.button.y>9 && event.button.y<53);
  return Fill_Color();
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>82 && event.button.x<126 && event.button.y>9 && event.button.y<53);
  Fill_Color();
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>136 && event.button.x<183 && event.button.y>9 && event.button.y<53);
  Fill_Color();
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>194 && event.button.x<238 && event.button.y>9 && event.button.y<53);
  Fill_Color();
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>251 && event.button.x<295 && event.button.y>9 && event.button.y<53);
  Fill_Color();
//Line 2
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>26 && event.button.x<70 && event.button.y>69 && event.button.y<113);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>82 && event.button.x<126 && event.button.y>69 && event.button.y<113);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>136 && event.button.x<183 && event.button.y>69 && event.button.y<113);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>194 && event.button.x<238 && event.button.y>69 && event.button.y<113);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>251 && event.button.x<295 && event.button.y>69 && event.button.y<113);
//Line 3
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>26 && event.button.x<70 && event.button.y>129 && event.button.y<173);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>82 && event.button.x<126 && event.button.y>129 && event.button.y<173);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>136 && event.button.x<183 && event.button.y>129 && event.button.y<173);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>194 && event.button.x<238 && event.button.y>129 && event.button.y<173);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>251 && event.button.x<295 && event.button.y>129 && event.button.y<173);
//Line 4
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>26 && event.button.x<70 && event.button.y>190 && event.button.y<234);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>82 && event.button.x<126 && event.button.y>190 && event.button.y<234);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>136 && event.button.x<183 && event.button.y>190 && event.button.y<234);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>194 && event.button.x<238 && event.button.y>190 && event.button.y<234);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>251 && event.button.x<295 && event.button.y>190 && event.button.y<234);
//Line 5
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>26 && event.button.x<70 && event.button.y>250 && event.button.y<294);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>82 && event.button.x<126 && event.button.y>250&& event.button.y<294);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>136 && event.button.x<183 && event.button.y>250 && event.button.y<294);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>194 && event.button.x<238 && event.button.y>250 && event.button.y<294);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>251 && event.button.x<295 && event.button.y>250 && event.button.y<294);
//Line 6
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>26 && event.button.x<70 && event.button.y>310 && event.button.y<354);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>82 && event.button.x<126 && event.button.y>310 && event.button.y<354);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>136 && event.button.x<183 && event.button.y>310 && event.button.y<354);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>194 && event.button.x<238 && event.button.y>310 && event.button.y<354);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>251 && event.button.x<295 && event.button.y>310 && event.button.y<354);
//Line 7
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>26 && event.button.x<70 && event.button.y>370 && event.button.y<414);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>82 && event.button.x<126 && event.button.y>370 && event.button.y<414);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>136 && event.button.x<183 && event.button.y>370 && event.button.y<414);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>194 && event.button.x<238 && event.button.y>370 && event.button.y<414);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>251 && event.button.x<295 && event.button.y>370 && event.button.y<414);
//Line 8
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>26 && event.button.x<70 && event.button.y>430 && event.button.y<474);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>82 && event.button.x<126 && event.button.y>430 && event.button.y<474);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>136 && event.button.x<183 && event.button.y>430 && event.button.y<474);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>194 && event.button.x<238 && event.button.y>430 && event.button.y<474);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>251 && event.button.x<295 && event.button.y>430 && event.button.y<474);
//Line 9
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>26 && event.button.x<70 && event.button.y>490 && event.button.y<534);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>82 && event.button.x<126 && event.button.y>490 && event.button.y<534);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>136 && event.button.x<183 && event.button.y>490 && event.button.y<534);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>194 && event.button.x<238 && event.button.y>490 && event.button.y<534);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>251 && event.button.x<295 && event.button.y>490 && event.button.y<534);
// Line 10
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>26 && event.button.x<70 && event.button.y>545 && event.button.y<589);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>82 && event.button.x<126 && event.button.y>545 && event.button.y<589);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>136 && event.button.x<183 && event.button.y>545 && event.button.y<589);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>194 && event.button.x<238 && event.button.y>545 && event.button.y<589);
if (event.button.button == SDL_BUTTON_LEFT && event.button.x>251 && event.button.x<295 && event.button.y>545 && event.button.y<589);
                        }
            }

}
}


*/

void makeCode(int secretCode[4])
{
    int i, randColor;
    for(i=0; i<4; i++)
    {
        randColor = 1 + rand() % 6;     //creates a number
        switch(randColor)
        {
        case 1:
            secretCode[i]=1;
            break;
        case 2:
            secretCode[i]=2;
            break;
        case 3:
            secretCode[i]=3;
            break;
        case 4:
            secretCode[i]=4;
            break;
        case 5:
            secretCode[i]=5;
            break;
        case 6:
            secretCode[i]=6;
            break;
        }
    }
}
SDL_Surface *Fill_Color()
{
    /*SDL_Rect position;
    position.x=408;
    position.y=420;
    backGround = SDL_LoadBMP("Boules.bmp");
    SDL_BlitSurface(backGround, NULL, ecran, &position);
    SDL_Flip(ecran);*/
    int continuer = 1;
    SDL_Event event;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;

        case SDL_MOUSEBUTTONUP:
        {
            if (event.button.button == SDL_BUTTON_LEFT && event.button.x>415 && event.button.x<459 && event.button.y>425 && event.button.y<469)//Red
                return SDL_LoadBMP("Red.bmp");
            if (event.button.button == SDL_BUTTON_LEFT && event.button.x>490 && event.button.x<534 && event.button.y>425 && event.button.y<469)//Yellow
                return SDL_LoadBMP("Yellow.bmp");
            if (event.button.button == SDL_BUTTON_LEFT && event.button.x>565 && event.button.x<609 && event.button.y>425 && event.button.y<469)//Green
                return SDL_LoadBMP("Green.bmp");
            if (event.button.button == SDL_BUTTON_LEFT && event.button.x>415 && event.button.x<459 && event.button.y>490 && event.button.y<534)//Blue
                return SDL_LoadBMP("Blue.bmp");
            if (event.button.button == SDL_BUTTON_LEFT && event.button.x>490 && event.button.x<534 && event.button.y>490 && event.button.y<534)//Brown
                return SDL_LoadBMP("Brown.bmp");
            if (event.button.button == SDL_BUTTON_LEFT && event.button.x>565 && event.button.x<609 && event.button.y>490 && event.button.y<534)//Rose
                return SDL_LoadBMP("Rose.bmp");

            break;
        }

        }
    }

}

void Fill_Color_Result(int secretCode[4],SDL_Surface *backGround,SDL_Surface *ecran)//la fonction qui donne le resultat final
{
    SDL_Rect positionBackground;
    positionBackground.x=417;
    positionBackground.y=549;
    int i;
    for(i=0; i<4; i++)
    {

        switch(secretCode[i])
        {
        case 1:

            backGround = SDL_LoadBMP("Small_Red.bmp");
            SDL_BlitSurface(backGround, NULL, ecran, &positionBackground);
            SDL_Flip(ecran);
            positionBackground.x=(positionBackground.x)+51;
            break;
        case 2:

            backGround = SDL_LoadBMP("Small_Yellow.bmp");
            SDL_BlitSurface(backGround, NULL, ecran, &positionBackground);
            SDL_Flip(ecran);
            positionBackground.x=(positionBackground.x)+51;
            break;
        case 3:

            backGround = SDL_LoadBMP("Small_Green.bmp");
            SDL_BlitSurface(backGround, NULL, ecran, &positionBackground);
            SDL_Flip(ecran);
            positionBackground.x=(positionBackground.x)+51;
            break;
        case 4:

            backGround = SDL_LoadBMP("Small_Blue.bmp");
            SDL_BlitSurface(backGround, NULL, ecran, &positionBackground);
            SDL_Flip(ecran);
            positionBackground.x=(positionBackground.x)+51;
            break;
        case 5:

            backGround = SDL_LoadBMP("Small_Brown.bmp");
            SDL_BlitSurface(backGround, NULL, ecran, &positionBackground);
            SDL_Flip(ecran);
            positionBackground.x=(positionBackground.x)+51;
            break;
        case 6:

            backGround = SDL_LoadBMP("Small_Rose.bmp");
            SDL_BlitSurface(backGround, NULL, ecran, &positionBackground);
            SDL_Flip(ecran);
            positionBackground.x=(positionBackground.x)+51;
            break;

        }
    }

}

int  pause(SDL_Surface *backGround,SDL_Surface *ecran)
{
    int c=1;
    SDL_Event event;
    SDL_Rect positionFond;
    while(c)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {

            case SDL_MOUSEBUTTONUP:
            {
                if(event.button.button == SDL_BUTTON_LEFT && event.button.x>408 && event.button.x<512 && event.button.y>302 && event.button.y<419)
              {
                return 7;
              }
                if(event.button.button == SDL_BUTTON_LEFT && event.button.x>516 && event.button.x<619 && event.button.y>302 && event.button.y<419)
               {
                  positionFond.x = 0;
                  positionFond.y = 0;
                  backGround = SDL_LoadBMP("Exit.bmp");
                  SDL_BlitSurface(backGround, NULL, ecran, &positionFond);
                  SDL_Flip(ecran);
                  SDL_Delay(1000);
                  exit(EXIT_SUCCESS);
               }
                if (event.button.button == SDL_BUTTON_LEFT && event.button.x>415 && event.button.x<459 && event.button.y>425 && event.button.y<469)//Red
                    return 1;
                if (event.button.button == SDL_BUTTON_LEFT && event.button.x>490 && event.button.x<534 && event.button.y>425 && event.button.y<469)//Yellow
                    return 2;
                if (event.button.button == SDL_BUTTON_LEFT && event.button.x>565 && event.button.x<609 && event.button.y>425 && event.button.y<469)//Green
                    return 3;
                if (event.button.button == SDL_BUTTON_LEFT && event.button.x>415 && event.button.x<459 && event.button.y>490 && event.button.y<534)//Blue
                    return 4;
                if (event.button.button == SDL_BUTTON_LEFT && event.button.x>490 && event.button.x<534 && event.button.y>490 && event.button.y<534)//Brown
                    return 5;
                if (event.button.button == SDL_BUTTON_LEFT && event.button.x>565 && event.button.x<609 && event.button.y>490 && event.button.y<534)//Rose
                    return 6;
            }
        }


    }

}

int guess(int guessCode[4],int ligne,SDL_Surface *backGround,SDL_Surface *ecran)
{
    int i,x;
    SDL_Rect position;

        switch(ligne)
            {
            case 1:
                position.x=26;
                position.y=9;
                break;
            case 2:
                position.x=26;
                position.y=69;
                break;
            case 3:
                position.x=26;
                position.y=129;
                break;
            case 4:
                position.x=26;
                position.y=189;
                break;
            case 5:
                position.x=26;
                position.y=249;
                break;
            case 6:
                position.x=26;
                position.y=309;
                break;
            case 7:
                position.x=26;
                position.y=369;
                break;
            case 8:
                position.x=26;
                position.y=429;
                break;
            case 9:
                position.x=26;
                position.y=489;
                break;
            case 10:
                position.x=26;
                position.y=545;
                break;
            }
for(i=0;i<4;i++)
    {
        x=pause(backGround,ecran);
        switch(x)
        {
        case 7:
            return 2;
        case 1:
            guessCode[i]=1;
            backGround=Fill_Color();
            SDL_BlitSurface(backGround, NULL, ecran, &position);
            SDL_Flip(ecran);
            if(i==1)
                position.x=position.x+112;
                else
            position.x=position.x+56;
            break;
        case 2:
            guessCode[i]=2;
            backGround=Fill_Color();
            SDL_BlitSurface(backGround, NULL, ecran, &position);
            SDL_Flip(ecran);
            if(i==1)
                position.x=position.x+112;
                else
            position.x=position.x+56;
            break;
        case 3:
            guessCode[i]=3;
            backGround=Fill_Color();
            SDL_BlitSurface(backGround, NULL, ecran, &position);
            SDL_Flip(ecran);
            if(i==1)
                position.x=position.x+112;
                else
            position.x=position.x+56;
            break;
        case 4:
            guessCode[i]=4;
            backGround=Fill_Color();
            SDL_BlitSurface(backGround, NULL, ecran, &position);
            SDL_Flip(ecran);
            if(i==1)
                position.x=position.x+112;
                else
            position.x=position.x+56;
            break;
        case 5:
            guessCode[i]=5;
            backGround=Fill_Color();
            SDL_BlitSurface(backGround, NULL, ecran, &position);
            SDL_Flip(ecran);
            if(i==1)
                position.x=position.x+112;
                else
            position.x=position.x+56;
            break;
        case 6:
            guessCode[i]=6;
            backGround=Fill_Color();
            SDL_BlitSurface(backGround, NULL, ecran, &position);
            SDL_Flip(ecran);
            if(i==1)
            position.x=position.x+112;
            else
            position.x=position.x+56;
            break;

        }
    }
return 0;
}

int codeCheck(int secretCode[4],int guessCode[4],SDL_Surface *ecran,SDL_Surface *imageDeFond,int ligne,SDL_Rect positionFond,SDL_Surface *backGround)
{
    int i,j,blackPeg=0,whitePeg=0, checkSecret[4] = {1,1,1,1}, checkGuess[4] = {1,1,1,1};
    for(i=0; i<4; i++) //if secret and guess's position and color are same, blackpeg increases
       {
           if(guessCode[i]==secretCode[i])
        {
            blackPeg++;
            checkSecret[i] = checkGuess[i] = 0;
        }
       }
    for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                if((secretCode[i]==guessCode[j]) &&  checkGuess[i]  &&  checkSecret[j]  &&  i != j)
                {
                    whitePeg++;
                    checkSecret[j] = checkGuess[i] = 0;
                }
            }
        }
        displayGuess(blackPeg,whitePeg,ecran,imageDeFond,ligne);
        if(blackPeg == 4)           //if player guess correct all, than the game finishes
                {
                    positionFond.x = 415;
                    positionFond.y = 70;
                    Fill_Color_Result(secretCode,backGround,ecran);
                    imageDeFond = SDL_LoadBMP("YouWin.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                    return 1;
                }
            return 0;

}

void displayGuess(int blackPeg, int whitePeg,SDL_Surface *ecran,SDL_Surface *imageDeFond,int Ligne)
{
    SDL_Rect positionPeg;
    positionPeg.x=328;
    int i;
    switch(Ligne)
    {
    case 1:
        positionPeg.y=8;
        for(i=0; i<blackPeg; i++)
        {
            switch(i)
            {
            case 1:
                positionPeg.x=367;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=34;
                break;
            case 3:
                positionPeg.x=367;
                break;
            default:
                break;
            }

            imageDeFond = SDL_LoadBMP("Black.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);

        }
        for(i=0; i<whitePeg; i++)
        {
            switch(blackPeg)
            {

            case 1:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=34;
                blackPeg++;
                break;
            case 3:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 4:
                return;
                break;
            default:
                break;
            }
            if(blackPeg==0)
            {
                switch(i)
            {
            case 1:
                positionPeg.x=367;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=34;
                break;
            case 3:
                positionPeg.x=367;
                break;
            default:
                break;
            }

            }
            imageDeFond = SDL_LoadBMP("white.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);
        }
        break;
    case 2:
        positionPeg.y=67;
        for(i=0; i<blackPeg; i++)
        {
            switch(i)
            {
            case 1:
                positionPeg.x=367;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=93;
                break;
            case 3:
                positionPeg.x=367;
                break;
            default:
                break;
            }

            imageDeFond = SDL_LoadBMP("Black.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);

        }
        for(i=0; i<whitePeg; i++)
        {
            switch(blackPeg)
            {

            case 1:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=93;
                blackPeg++;
                break;
            case 3:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 4:
                return;
                break;
            default:
                break;
            }
            if(blackPeg==0)
            {
                switch(i)
                {
                case 1:
                    positionPeg.x=367;
                    break;
                case 2:
                    positionPeg.x=328;
                    positionPeg.y=93;
                    break;
                case 3:
                    positionPeg.x=367;
                    break;
                default:
                    break;
                }

            }
            imageDeFond = SDL_LoadBMP("white.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);
        }
        break;
    case 3:
        positionPeg.y=126;
        for(i=0; i<blackPeg; i++)
        {
            switch(i)
            {
            case 1:
                positionPeg.x=367;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=152;
                break;
            case 3:
                positionPeg.x=367;
                break;
            default:
                break;
            }

            imageDeFond = SDL_LoadBMP("Black.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);

        }
        for(i=0; i<whitePeg; i++)
        {
            switch(blackPeg)
            {

            case 1:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=152;
                blackPeg++;
                break;
            case 3:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 4:
                return;
                break;
            default:
                break;
            }
            if(blackPeg==0)
            {
                switch(i)
                {
                case 1:
                    positionPeg.x=367;
                    break;
                case 2:
                    positionPeg.x=328;
                    positionPeg.y=152;
                    break;
                case 3:
                    positionPeg.x=367;
                    break;
                default:
                    break;
                }

            }
            imageDeFond = SDL_LoadBMP("white.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);
        }

        break;
    case 4:
        positionPeg.y=187;
        for(i=0; i<blackPeg; i++)
        {
            switch(i)
            {
            case 1:
                positionPeg.x=367;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=213;
                break;
            case 3:
                positionPeg.x=367;
                break;
            default:
                break;
            }

            imageDeFond = SDL_LoadBMP("Black.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);

        }
        for(i=0; i<whitePeg; i++)
        {
            switch(blackPeg)
            {

            case 1:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=213;
                blackPeg++;
                break;
            case 3:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 4:
                return;
                break;
            default:
                break;
            }
            if(blackPeg==0)
            {
                switch(i)
                {
                case 1:
                    positionPeg.x=367;
                    break;
                case 2:
                    positionPeg.x=328;
                    positionPeg.y=213;
                    break;
                case 3:
                    positionPeg.x=367;
                    break;
                default:
                    break;
                }

            }
            imageDeFond = SDL_LoadBMP("white.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);
        }

        break;
    case 5:
        positionPeg.y=246;
        for(i=0; i<blackPeg; i++)
        {
            switch(i)
            {
            case 1:
                positionPeg.x=367;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=272;
                break;
            case 3:
                positionPeg.x=367;
                break;
            default:
                break;
            }

            imageDeFond = SDL_LoadBMP("Black.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);

        }
        for(i=0; i<whitePeg; i++)
        {
            switch(blackPeg)
            {

            case 1:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=272;
                blackPeg++;
                break;
            case 3:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 4:
                return;
                break;
            default:
                break;
            }
            if(blackPeg==0)
            {
                switch(i)
                {
                case 1:
                    positionPeg.x=367;
                    break;
                case 2:
                    positionPeg.x=328;
                    positionPeg.y=272;
                    break;
                case 3:
                    positionPeg.x=367;
                    break;
                default:
                    break;
                }

            }
            imageDeFond = SDL_LoadBMP("white.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);
        }

        break;
    case 6:
        positionPeg.y=307;
        for(i=0; i<blackPeg; i++)
        {
            switch(i)
            {
            case 1:
                positionPeg.x=367;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=333;
                break;
            case 3:
                positionPeg.x=367;
                break;
            default:
                break;
            }

            imageDeFond = SDL_LoadBMP("Black.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);

        }
        for(i=0; i<whitePeg; i++)
        {
            switch(blackPeg)
            {

            case 1:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=333;
                blackPeg++;
                break;
            case 3:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 4:
                return;
                break;
            default:
                break;
            }
            if(blackPeg==0)
            {
                switch(i)
                {
                case 1:
                    positionPeg.x=367;
                    break;
                case 2:
                    positionPeg.x=328;
                    positionPeg.y=333;
                    break;
                case 3:
                    positionPeg.x=367;
                    break;
                default:
                    break;
                }

            }
            imageDeFond = SDL_LoadBMP("white.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);
        }

        break;
    case 7:
        positionPeg.y=367;
        for(i=0; i<blackPeg; i++)
        {
            switch(i)
            {
            case 1:
                positionPeg.x=367;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=393;
                break;
            case 3:
                positionPeg.x=367;
                break;
            default:
                break;
            }

            imageDeFond = SDL_LoadBMP("Black.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);

        }
        for(i=0; i<whitePeg; i++)
        {
            switch(blackPeg)
            {

            case 1:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=393;
                blackPeg++;
                break;
            case 3:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 4:
                return;
                break;
            default:
                break;
            }
            if(blackPeg==0)
            {
                switch(i)
                {
                case 1:
                    positionPeg.x=367;
                    break;
                case 2:
                    positionPeg.x=328;
                    positionPeg.y=393;
                    break;
                case 3:
                    positionPeg.x=367;
                    break;
                default:
                    break;
                }

            }
            imageDeFond = SDL_LoadBMP("white.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);
        }

        break;
    case 8:
        positionPeg.y=426;
        for(i=0; i<blackPeg; i++)
        {
            switch(i)
            {
            case 1:
                positionPeg.x=367;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=452;
                break;
            case 3:
                positionPeg.x=367;
                break;
            default:
                break;
            }

            imageDeFond = SDL_LoadBMP("Black.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);

        }
        for(i=0; i<whitePeg; i++)
        {
            switch(blackPeg)
            {

            case 1:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=452;
                blackPeg++;
                break;
            case 3:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 4:
                return;
                break;
            default:
                break;
            }
            if(blackPeg==0)
            {
                switch(i)
                {
                case 1:
                    positionPeg.x=367;
                    break;
                case 2:
                    positionPeg.x=328;
                    positionPeg.y=452;
                    break;
                case 3:
                    positionPeg.x=367;
                    break;
                default:
                    break;
                }

            }
            imageDeFond = SDL_LoadBMP("white.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);
        }
        break;
    case 9:
        positionPeg.y=488;
        for(i=0; i<blackPeg; i++)
        {
            switch(i)
            {
            case 1:
                positionPeg.x=367;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=514;
                break;
            case 3:
                positionPeg.x=367;
                break;
            default:
                break;
            }

            imageDeFond = SDL_LoadBMP("Black.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);

        }
        for(i=0; i<whitePeg; i++)
        {
            switch(blackPeg)
            {

            case 1:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=514;
                blackPeg++;
                break;
            case 3:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 4:
                return;
                break;
            default:
                break;
            }
            if(blackPeg==0)
            {
                switch(i)
                {
                case 1:
                    positionPeg.x=367;
                    break;
                case 2:
                    positionPeg.x=328;
                    positionPeg.y=514;
                    break;
                case 3:
                    positionPeg.x=367;
                    break;
                default:
                    break;
                }

            }
            imageDeFond = SDL_LoadBMP("white.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);
        }

        break;
    case 10:
        positionPeg.y=544;
        for(i=0; i<blackPeg; i++)
        {
            switch(i)
            {
            case 1:
                positionPeg.x=367;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=570;
                break;
            case 3:
                positionPeg.x=367;
                break;
            default:
                break;
            }

            imageDeFond = SDL_LoadBMP("Black.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);

        }
        for(i=0; i<whitePeg; i++)
        {
            switch(blackPeg)
            {

            case 1:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 2:
                positionPeg.x=328;
                positionPeg.y=570;
                blackPeg++;
                break;
            case 3:
                positionPeg.x=367;
                blackPeg++;
                break;
            case 4:
                return;
                break;
            default:
                break;
            }
            if(blackPeg==0)
            {
                switch(i)
                {
                case 1:
                    positionPeg.x=367;
                    break;
                case 2:
                    positionPeg.x=328;
                    positionPeg.y=570;
                    break;
                case 3:
                    positionPeg.x=367;
                    break;
                default:
                    break;
                }

            }
            imageDeFond = SDL_LoadBMP("white.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionPeg);
            SDL_Flip(ecran);
        }
        break;
    }


}


