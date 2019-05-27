#include<stdlib.h>
#include<stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include<time.h>
#include"MasterMind.h"



int main(int argc, char *argv[])
{
        int secretCode[4],guessCode[4];
        int wrongGuess,ligne,c=0,c2=1,w,a;
        SDL_Surface *ecran = NULL, *imageDeFond = NULL, *backGround=NULL;
        SDL_Event event;
        SDL_Init(SDL_INIT_VIDEO);
        SDL_Rect positionFond;
        positionFond.x = 0;
        positionFond.y = 0;
        srand(time(NULL));
        SDL_WM_SetIcon(SDL_LoadBMP("Background.bmp"), NULL);
        ecran = SDL_SetVideoMode(628, 600, 32, SDL_HWSURFACE |SDL_DOUBLEBUF);
        SDL_WM_SetCaption("Master Mind", NULL);
        imageDeFond = SDL_LoadBMP("Background.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
        SDL_Delay(1000);
        do
        {
            makeCode(secretCode);
          c=0,c2=1,w=0;
        Menu(imageDeFond,ecran,positionFond);
        for(wrongGuess=1; wrongGuess<=10; wrongGuess++)      //gives 10 rights to guess
            {
                ligne=wrongGuess;
                a=guess(guessCode,ligne,backGround,ecran);
                if(a==2)
                {
                    wrongGuess=12;
                    c2=0;
                }
                else
                {
                    w=codeCheck(secretCode,guessCode,ecran,imageDeFond,ligne,positionFond,backGround);
                    if(w==1)
                    wrongGuess=12;
                }
            }
        if(wrongGuess == 11)        //if player cannot guess correct colors in 10 rounds, he losts
        {
            positionFond.x = 415;
            positionFond.y = 70;
            Fill_Color_Result(secretCode,backGround,ecran);
            imageDeFond = SDL_LoadBMP("YouLose.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
            SDL_Flip(ecran);
        }
        while(c2)
        {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            c2=0;
            c=2;
            break;
        case SDL_MOUSEBUTTONUP:
            if(event.button.button == SDL_BUTTON_LEFT && event.button.x>516 && event.button.x<619 && event.button.y>302 && event.button.y<419)
               {
                  c=2;
                  c2=0;
                  positionFond.x = 0;
                  positionFond.y = 0;
                  imageDeFond = SDL_LoadBMP("Exit.bmp");
                  SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                  SDL_Flip(ecran);
                  SDL_Delay(1000);
                  exit(EXIT_SUCCESS);
               }
             if(event.button.button == SDL_BUTTON_LEFT && event.button.x>408 && event.button.x<512 && event.button.y>302 && event.button.y<419)
              {
                 c=0;
                 c2=0;
              }

             break;
        }
        }
        positionFond.x = 0;
        positionFond.y = 0;
        }while(c<1);
        SDL_FreeSurface(imageDeFond);
        SDL_FreeSurface(backGround);
        SDL_Quit();
        return EXIT_SUCCESS;
}
