#ifndef MASTERMIND_H_INCLUDED
#define MASTERMIND_H_INCLUDED

void Menu(SDL_Surface *imageDeFond,SDL_Surface *ecran,SDL_Rect positionFond);
void makeCode(int secretCode[4]);
SDL_Surface *Fill_Color();
int  pause(SDL_Surface *backGround,SDL_Surface *ecran);
void Fill_Color_Result(int secretCode[4],SDL_Surface *backGround,SDL_Surface *ecran);
void choose_Position_Color(int ligne,SDL_Surface *backGround,SDL_Surface *ecran);
int guess(int guessCode[4],int ligne,SDL_Surface *backGround,SDL_Surface *ecran);
int codeCheck(int secretCode[4],int guessCode[4],SDL_Surface *ecran,SDL_Surface *imageDeFond,int ligne,SDL_Rect positionFond,SDL_Surface *backGround);
void displayGuess(int blackPeg, int whitePeg,SDL_Surface *ecran,SDL_Surface *imageDeFond,int Ligne);



#endif // MASTERMIND_H_INCLUDED
