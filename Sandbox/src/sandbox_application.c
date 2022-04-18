#include "pond.h"

void Init(void) 
{
	Pond_Console_PrintLine("Initialising FrogEngine2D!");
	Pond_Console_PrintWarning("Oh oh");
	Pond_Console_Print("Oh oh!");

}

void Update(void)
{

}

void Draw(void)
{

}


int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_Run(60);

	return 0;
}