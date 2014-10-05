#include "Chip8.h"
#include <unistd.h>

Emulator::Emulator( ){
	init_interface( );

	cpu     = new Chip8( this );
	display = new Display( this );
	keypad  = new Keypad( this );
	running = false;
}

Emulator::Emulator( char *romfile ){
	init_interface( );

	cpu     = new Chip8( this );
	display = new Display( this );
	keypad  = new Keypad( this );
	running = false;

	cpu->loadRom( romfile );
}

Emulator::~Emulator( ){
	delete cpu;
	delete display;
	delete keypad;

	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );

	window = NULL;
	renderer = NULL;

	SDL_Quit( );
}

void Emulator::init_interface( ){
	// initialize sdl stuff
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "[%s] Could not initialize SDL: %s\n", __func__, SDL_GetError( ));
		// throw error here
	}

	window = SDL_CreateWindow( "Chaps Emulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );

	if ( !window ){
		printf( "[%s] Could not create window: %s\n", __func__, SDL_GetError( ));
		// throw error here
	}

	//renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	if ( !renderer ){
		printf( "[%s] Could not create renderer: %s\n", __func__, SDL_GetError( ));
		// throw error here
	}
}

void Emulator::run( ){
	running = true;

	int i, j;
	bool flip = false;

	i = 32;
	j = 16;

	while ( running ){
		display->redraw( );
		keypad->checkKeys( );

		if ( keypad->isSet( 7 ) && i ){      i--; flip = true; };
		if ( keypad->isSet( 5 ) && j ){      j--; flip = true; }
		if ( keypad->isSet( 0 ) && j < 31 ){ j++; flip = true; }
		if ( keypad->isSet( 9 ) && i < 63 ){ i++; flip = true; }

		if ( flip ){
			display->flipPixel( i, j );
			flip = false;
		}

		usleep( 10000 );
		running = keypad->quitIsSet( ) == false;
	}

}

void Emulator::pause( ){
}
