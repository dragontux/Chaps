#ifndef _chip8_h
#define _chip8_h
#include <stdint.h>
#include <SDL2/SDL.h>

class Chip8;
class Display;
class Sound;
class Emulator;

class Emulator {
	public:
		 Emulator( );
		 Emulator( char *romfile );
		~Emulator( );

		void run( );
		void pause( );

		bool saveState( char *savefile );

		Chip8   *cpu;
		Display *display;

	private:
		bool running; 
};

class Chip8 {
	public:
		 Chip8( Emulator *em );
		~Chip8( );

		void step( );
		bool loadRom( char *romfile );

	private:
		uint8_t  *memory;
		uint16_t *rom;
		short     registers[16];
		short     mp; // memory pointer
		short     ip; // instruction pointer

		Emulator *emulator;
};

class Display {
	public:
		 Display( Emulator *em );
		~Display( );

		void setPixel( unsigned x, unsigned y );
		void redraw( );

	private:
		bool         *buffer;
		SDL_Window   *window;
		SDL_Renderer *renderer;

		Emulator     *emulator;
};

#endif
