#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>

class System
{
protected:
	static SDL_Renderer* renderer;

public:
	System();

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	~System();
};	

#endif // !SYSTEM_H