#include <pond.h>

void Init(void);
void Update(void);
void Draw(void);

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 500

Pond_Colour black = { 0, 0, 0, 0 };

Pond_Colour red = { 255, 100, 100, 255 };

float size = 0;
float growth = 1;

int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_InitAudioSystem(8, 10, 20);
	Pond_Run(60, WINDOW_WIDTH, WINDOW_HEIGHT, "Pond Demo", 1);

	return 0;
}

void Init(void)
{
	Pond_SetWindowMode(POND_WINDOW_MODE_WINDOWED);
	Pond_SetRenderClearColour(black);
	Pond_SetWindowResizable(1);
}

void Update(void)
{
	if (size > 100 || size < 0)
		growth *= -1;

	size += growth;
	
}

void Draw(void)
{
	Pond_DrawCircle(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, size, red, 1);
}