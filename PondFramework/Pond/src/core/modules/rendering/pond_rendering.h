#pragma once

#include "../../sdl/pond_sdl.h"
#include "../../pond_core.h"
#include "../../pond_basic_structs.h"
#include <memory.h>

extern App app;

POND_API typedef struct Pond_Texture
{
	SDL_Texture* p_textureData;

} Pond_Texture;

POND_API typedef struct Pond_Rect
{
	int x;
	int y;
	int w;
	int h;

} Pond_Rect;

POND_API typedef struct Pond_Sprite
{
	Pond_Texture* p_texture;
	
	Pond_Rect spriteRect;

	Pond_Colour colour;

	double rotationAngle;
	Pond_Vector2Int rotationAnchor;
	bool flipX;
	bool flipY;

} Pond_Sprite;


static Pond_Colour renderClearColour = { 0,0,0,255 };

int RenderScene(void);
int PrepareScene(void);

typedef enum POND_TEXTURE_BLEND_MODE
{
	POND_TEXTURE_BLEND_MODE_NO_BLENDING = 0,
	POND_TEXTURE_BLEND_MODE_BLENDING,

} POND_TEXTURE_BLEND_MODE;

/// <summary>
/// Sets the render clear colour.
/// The Renderer clears the screen at the start of each frame with the clear colour.
/// </summary>
/// <param name="_col">- the colour to set as render clear colour</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_SetRenderClearColour(Pond_Colour _col);

/// <summary>
/// Returns a Pond_Colour with given RGBA-values.
/// </summary>
/// <param name="_r">- R value</param>
/// <param name="_g">- G value</param>
/// <param name="_b">- B value</param>
/// <param name="_a">- A value</param>
/// <returns>returns the Pond_Colour</returns>
POND_API Pond_Colour Pond_GetColour(int _r, int _g, int _b, int _a);

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// Shapes
#pragma region Shapes

/// <summary>
/// Renders a pixel at x and y with colour to the screen.
/// </summary>
/// <param name="_x">- the x-pos of the pixel to render</param>
/// <param name="_y">- the y-pos of the pixel to render</param>
/// <param name="_col">- the colour of the pixel</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_DrawPixel(int _x, int _y, Pond_Colour _col);

/// <summary>
/// Renders a line between two coordinates with colour to the screen.
/// </summary>
/// <param name="_x1">- x pos of 1. coordinate of line</param>
/// <param name="_y1">- y pos of 1. coordinate of line</param>
/// <param name="_x2">- x pos of 2. coordinate of line</param>
/// <param name="_y2">- x pos of 2. coordinate of line</param>
/// <param name="_col">- the colour of the line</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_DrawLine(int _x1, int _y1, int _x2, int _y2, Pond_Colour _col);

/// <summary>
/// Renders a polygon by drawing lines between passed points. 
/// </summary>
/// <param name="_points">- the points to be connected by lines</param>
/// <param name="_arraysize">- the amounts of points</param>
/// <param name="_col">- the colour of the polygon lines</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_DrawPolygon(Pond_Vector2Int _points[], int _arraysize, Pond_Colour _col);

/// <summary>
/// Renders a rectangle by giving top-left and bottom-right coordinates with colour to the screen.
/// </summary>
/// <param name="_x1">- x pos of the top-left coordinate of the rectangle</param>
/// <param name="_y1">- y pos of the top-left coordinate of the rectangle</param>
/// <param name="_x2">- x pos of the bottom-right coordinate of the rectangle</param>
/// <param name="_y2">- y pos of the bottom-right coordinate of the rectangle</param>
/// <param name="_col">- the colour of the rectangle</param>
/// <param name="_fill">- true or 1 if the rectangle should be filled, false or 0 if not</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_DrawRect(int _x1, int _y1, int _x2, int _y2, Pond_Colour _col, bool _fill);

/// <summary>
/// Renders a rectangle by giving a coordinate, width and height values.
/// </summary>
/// <param name="">- x pos of the rectangle, corresponds to the top-left position of the rectangle</param>
/// <param name="_y">- y pos of the rectangle, corresponds to the top-left position of the rectangle</param>
/// <param name="_w">- width of the rectangle</param>
/// <param name="_h">- height of the rectangle</param>
/// <param name="_col">- the colour of the rectangle</param>
/// <param name="_fill">- true or 1 if the rectangle should be filled, false or 0 if not</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_DrawRectByDimensions(int _x, int _y, int _w, int _h, Pond_Colour _col, bool _fill);

/// <summary>
/// Renders a circle around passed coordinate with passed radius and colour.
/// </summary>
/// <param name="_x">- the x pos of the circle center</param>
/// <param name="_y">- the y pos of the circle center</param>
/// <param name="_radius">- the radius of the circle</param>
/// <param name="_col">- the colour of the circle</param>
/// <param name="_fill">- true or 1 if the circle should be filled, false or 0 if not</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_DrawCircle(int _x, int _y, int _radius, Pond_Colour _col, bool _fill);
static int DrawCircleAlgorithm(int _x, int _y, int _radius);

#pragma endregion


// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// Texture & Sprite
#pragma region Texture & Sprite

/// <summary>
/// Draws a texture at passed coordinates with passed scale.
/// The texture will be drawn with its top-left corner at passed coordinates.
/// </summary>
/// <param name="_tex">- the Pond_Texture to draw</param>
/// <param name="_x">- the x pos of the left side of the texture</param>
/// <param name="_y">- the y pos of the top side of the texture</param>
/// <param name="_xscale">- the x scale to draw the texture at</param>
/// <param name="_yscale">- the y scale to draw the texture at</param>
/// <param name="_alpha">- the alpha value to draw the texture with. (Ranges 0-255)</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_DrawTexture(Pond_Texture* _tex, int _x, int _y, float _xscale, float _yscale, int _alpha);

/// <summary>
/// Draws a portion of a texture at passed coordinates with passed scale.
/// The texture will be drawn with its top-left corner at passed coordinates. 
/// </summary>
/// <param name="_tex">- the Pond_Texture to draw</param>
/// <param name="_portion">- the portion of the texture as a Pond_Rect</param>
/// <param name="_x">- the x pos of the left side of the texture</param>
/// <param name="_y">- the y pos of the top side of the texture</param>
/// <param name="_xscale">- the x scale to draw the texture at</param>
/// <param name="_yscale">- the y scale to draw the texture at</param>
/// <param name="_alpha">- the alpha value to draw the texture with. (Ranges 0-255)</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_DrawTexturePortion(Pond_Texture* _tex, Pond_Rect _portion, int _x, int _y, float _xscale, float _yscale, int _alpha);

/// <summary>
/// Draws a portion of a texture at passed coordinates with passed scale, colour tint and rotation around anchor.
/// The texture will be drawn with its top-left corner at passed coordinates.
/// </summary>
/// <param name="_tex">- the Pond_Texture to draw</param>
/// <param name="_x">- the x pos of the left side of the texture</param>
/// <param name="_y">- the y pos of the top side of the texture</param>
/// <param name="_xscale">- the x scale to draw the texture at</param>
/// <param name="_yscale">- the y scale to draw the texture at</param>
/// <param name="_colourtint">- colour tint of the texture</param>
/// <param name="_rotationangle">- rotation angle to draw</param>
/// <param name="_rotationanchor">- anchor to rotate around as Pond_Vector2Int</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_DrawTextureAdvanced(Pond_Texture* _tex, Pond_Rect _portion, int _x, int _y, float _xscale, float _yscale, Pond_Colour _colourtint, int _rotationangle, Pond_Vector2Int _rotationanchor);

/// <summary>
/// Draws a sprite at passed coordinates with passed scale.
/// The Sprite will be drawn with its top-left corner at passed coordinates.
/// It is to note that Pond_Sprite saves data such as colour, rotation, sprite portion and if its flipped at it's axes.
/// </summary>
/// <param name="_sprite">- the Pond_Sprite to draw</param>
/// <param name="_x">- the x pos of the left side of the sprite</param>
/// <param name="_y">- the y pos of the top side of the sprite</param>
/// <param name="_xscale">- x-scale of the sprite</param>
/// <param name="_yscale">- y-scale of the sprite</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_DrawSprite(Pond_Sprite* _tex, int _x, int _y, float _xscale, float _yscale);

/// <summary>
/// Loads a texture-file and returns a Pond_Texture pointer.
/// Returned pointer is allocated in memory. (Can be freed with Pond_FreeTexture)
/// Blendmode determines if texture should have a blur. (Pixel Art should have no blending)
/// </summary>
/// <param name="_filepath">- the filepath of the texture</param>
/// <param name="_blendmode">- the blendmode of the texture</param>
/// <returns>returns the pointer to allocated Pond_Texture</returns>
POND_API Pond_Texture* Pond_LoadTexture(char* _filepath, POND_TEXTURE_BLEND_MODE _blendmode);
static SDL_Texture* LoadTexture(char* _filepath, POND_TEXTURE_BLEND_MODE _blendmode);

/// <summary>
/// Frees passed texture from memory.
/// </summary>
/// <param name="_p_texture">- the Pond_Texture to free</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_FreeTexture(Pond_Texture* _p_texture);

/// <summary>
/// Not supported anymore.
/// </summary>
/// <param name="_rendermode"></param>
/// <returns></returns>
POND_API int Pond_SetTextureScaleQuality(int _rendermode);
static int SetTextureBlendMode(POND_TEXTURE_BLEND_MODE _quality);

/// <summary>
/// Allocates a Pond_Sprite in memory and returns the pointer. (Can be freed with Pond_FreeSprite)
/// Pond_Sprite has the passed texture as texture-data.
/// </summary>
/// <param name="_p_texture">- the texture the Pond_Sprite should have</param>
/// <returns>returns allocated Pond_Sprite</returns>
POND_API Pond_Sprite* Pond_InitSprite(Pond_Texture* _p_texture);

// POND_API Pond_Sprite* Pond_InitSprite(char* _filepath, E_ImportQuality _quality);

/// <summary>
/// Frees passed Pond_Sprite from memory.
/// </summary>
/// <param name="_p_sprite">- the Pond_Sprite to free</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_FreeSprite(Pond_Sprite* _p_sprite);

// POND_API int Pond_SetSpriteValues(Pond_Rect _spriterect, Pond_Colour _colour, double _rotationangle, SDL_Point _rotationanchor, bool _flipx, bool _flipy);

/// <summary>
/// Sets the texture-data of the passed Pond_Sprite to passed Pond_Texture.
/// </summary>
/// <param name="_p_sprite">- the Pond_Sprite to change the texture-data of</param>
/// <param name="_p_texture">- the new texture-data of the Pond_Sprite</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_SetSpriteTexture(Pond_Sprite* _p_sprite, Pond_Texture* _p_texture);

/// <summary>
/// Sets the portion to draw of passed Pond_Sprite.
/// </summary>
/// <param name="_p_sprite">- the Pond_Sprite to change</param>
/// <param name="_x">- the x coordinate of portion in texture</param>
/// <param name="_y">- the y coordinate of portion in texture</param>
/// <param name="_w">- the width of portion in texture</param>
/// <param name="_h">- the height of portion in texture</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_SetSpriteRect(Pond_Sprite* _p_sprite, int _x, int _y, int _w, int _h);

/// <summary>
/// Sets the colour of passed Pond_Sprite.
/// </summary>
/// <param name="_p_sprite">- the Pond_Sprite to change</param>
/// <param name="_r">- the red value</param>
/// <param name="_g">- the green value</param>
/// <param name="_b">- the blue value</param>
/// <param name="_a">- the alpha value</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_SetSpriteColour(Pond_Sprite* _p_sprite, int _r, int _g, int _b, int _a);

/// <summary>
/// Sets the rotation angle of passed Pond_Sprite.
/// </summary>
/// <param name="_p_sprite">- the Pond_Sprite to change</param>
/// <param name="_rotationangle">- the rotation angle</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_SetSpriteRotation(Pond_Sprite* _p_sprite, double _rotationangle);

/// <summary>
/// Sets the rotation anchor of passed Pond_Sprite.
/// Rotation of Pond_Sprite rotates around anchor.
/// </summary>
/// <param name="_p_sprite">- the Pond_Sprite to change</param>
/// <param name="_x">- the x coordinate of the rotation anchor in texture of Pond_Sprite</param>
/// <param name="_y">- the y coordinate of the rotation anchor in texture of Pond_Sprite</param>
/// <returns>returns 1 if successful</returns>
POND_API int Pond_SetSpriteRotationAnchor(Pond_Sprite* _p_sprite, int _x, int _y);

/// <summary>
/// Returns the size of passed Pond_Texture as Pond_Vector2Int.
/// </summary>
/// <param name="_p_texture">- the Pond_Texture</param>
/// <returns>returns size of Pond_Texture as Pond_Vector2Int</returns>
POND_API Pond_Vector2Int Pond_GetTextureSize(Pond_Texture* _p_texture);

#pragma endregion


