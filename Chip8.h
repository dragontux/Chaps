#ifndef _chip8_h
#define _chip8_h
#include <stdint.h>
#include <SDL2/SDL.h>

enum constants { 
	PIXEL_WIDTH     = 16,
	PIXEL_HEIGHT    = 16,
	PIXELS_WINDOW_X = 64,
	PIXELS_WINDOW_Y = 32,

	WINDOW_HEIGHT = PIXEL_HEIGHT * PIXELS_WINDOW_Y,
	WINDOW_WIDTH  = PIXEL_WIDTH  * PIXELS_WINDOW_X,
};

class Chip8;
class Display;
class Sound;
class Keypad;
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
		Keypad  *keypad;

		SDL_Window   *window;
		SDL_Renderer *renderer;

	private:
		void init_interface( );
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
		bool getPixel( unsigned x, unsigned y );
		void unsetPixel( unsigned x, unsigned y );
		void flipPixel( unsigned x, unsigned y );

		void redraw( );

	private:
		bool         buffer[64][32];
		Emulator     *emulator;
};

class Keypad {
	public:
		 Keypad( Emulator *em );
		~Keypad( );

		void checkKeys( );
		bool isSet( unsigned keyno );
		bool quitIsSet( );

	private:
		bool keys[16];
		bool quit;

		Emulator *emulator;
};

class Sound {
	// TODO: Impliment this
	;
};

#endif
