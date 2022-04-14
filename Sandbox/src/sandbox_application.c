#include <frog_engine.h>
#include <stdio.h>

void Init(void) 
{
	FrogEngine_Print("Initialising FrogEngine2D!\n");
}

void Update(void)
{

}

void Draw(void)
{

}


int main(void)
{
	FrogEngine_Init(&Init, &Update, &Draw);
	FrogEngine_Run(60);

	return 0;
}