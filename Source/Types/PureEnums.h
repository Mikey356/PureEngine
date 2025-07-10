#pragma once
#include <cstdint>

enum class API
{
	OPENGL,
	VULKAN,
	UDEFINED
};

enum class WindowedMode
{
	WINDOWED,
	FULLSCREEN
};

enum Alignment
{
	CENTERED, 
	CENTERED_HORIZONTAL,
	CENTERED_VERTICAL,
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_RIGHT	
};


enum class TextureWrapMode
{
	REPEAT,
	MIRRORED_REPEAT,
	CLAMP_TO_EDGE,
	CLAMP_TO_BORDER,
	UNDEFINED
};

enum class TextureFilter
{
	NEAREST,
	LINEAR,
	LINEAR_MIPMAP,
	UNDEFINED
};

enum class Axis
{
	x,
	y,
	z,
	NONE
};

enum class CameraView
{
	PERSPECTIVE,
	ORTHO,
	FRONT,
	BACK,
	LEFT,
	RIGHT,
	TOP,
	BOTTOM,
	UNDEFINED
};