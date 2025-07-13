#include<glad/glad.h>


struct  TextBasedDebugger
{
	static void APIENTRY  glDebugOutput(GLenum source, GLenum type, unsigned int id, GLenum severity, GLsizei length, const char* message, const void* userParam);
	static GLenum glCheckError_(const char* file, int line);
};



