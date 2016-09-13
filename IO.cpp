#include "IO.h"

SDL_Surface *screen;	// Screen
static Uint32 colors[COLOR_MAX] = { 0x000000ff, 0xff0000ff, 0x00ff00ff, 0x0000ffff,
0x00ffffff, 0xff00ffff, 0xffff00ff, 0xffffffff };


IO::IO(void)
{
	init_graph();
}

void IO::draw_rectangle(int x_1, int y_1, int x_2, int y_2, color c)
{
	 
}

void IO::draw_rectangle(const SDL_Rect* rect, color c)
{
	SDL_FillRect(screen, rect, colors[c]);
}

void IO::clear_screen(void)
{
	SDL_FillRect(screen, NULL, 0x000000);
}

int IO::get_screen_height(void)
{
	return screen->h;
}

int IO::init_graph(void)
{
	const SDL_VideoInfo *info;
	Uint8  video_bpp;
	Uint32 videoflags;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
		return 1;
	}
	atexit(SDL_Quit);

	// Alpha blending doesn't work well at 8-bit color
	info = SDL_GetVideoInfo();
	if (info->vfmt->BitsPerPixel > 8) {
		video_bpp = info->vfmt->BitsPerPixel;
	}
	else {
		video_bpp = 16;
	}
	videoflags = SDL_SWSURFACE | SDL_DOUBLEBUF;

	// Set 640x480 video mode
	screen = SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
	if ((screen = SDL_SetVideoMode(640, 480, video_bpp, videoflags)) == NULL) {
		fprintf(stderr, "Couldn't set %ix%i video mode: %s\n", 640, 480, SDL_GetError());
		return 2;
	}
	return 0;
}

int IO::poll_key(void)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_KEYDOWN:
			return event.key.keysym.sym;
		case SDL_QUIT:
			exit(3);
		}
	}
	return -1;
}

int IO::get_key(void)
{
	SDL_Event event;
	while (true)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
			break;
		if (event.type == SDL_QUIT)
			exit(3);
	};
	return event.key.keysym.sym;
}

int IO::is_key_down(int key)
{
	const Uint8* key_table;
	int num_key;

	SDL_PumpEvents();
	key_table = SDL_GetKeyboardState(&num_key);
	return key_table[key];
}

void IO::update_screen(void)
{
	SDL_RenderPresent();
}


