#include "pond.h"



Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 255 };

void Init(void) 
{
	Pond_SetRenderClearColour(black);

	//Pond_SetWindowMode(POND_WINDOW_MODE_FULLSCREEN);
}

void Update(void)
{
	printf("X: %i\n" ,Pond_GetWindowSize().x);
	printf("Y: %i\n" ,Pond_GetWindowSize().y);
	printf("----------------------------------------\n");
}

void Draw(void)
{
	
}

int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	//Pond_SetWindowSize(1820, 980);
	Pond_Run(60);

	return 0;
}