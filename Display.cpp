#include "Chip8.h"

// Display class methods
Display::Display( Emulator *em ){
	emulator = em;

	for ( unsigned i = 0; i < PIXELS_WINDOW_X; i++ ){
		for ( unsigned j = 0; j < PIXELS_WINDOW_Y; j++ ){
			unsetPixel( i, j );
		}
	}

	printf( "[%s] Debug: initializing display\n", __func__ );

}

Display::~Display( ){
}

void Display::setPixel( unsigned x, unsigned y ){
	if ( x < PIXELS_WINDOW_X && y < PIXELS_WINDOW_Y ){
		buffer[x][y] = true;
	}
}

bool Display::getPixel( unsigned x, unsigned y ){
	if ( x < PIXELS_WINDOW_X && y < PIXELS_WINDOW_Y ){
		return buffer[x][y];
	}

	return false;
}

void Display::unsetPixel( unsigned x, unsigned y ){
	if ( x < PIXELS_WINDOW_X && y < PIXELS_WINDOW_Y ){
		buffer[x][y] = false;
	}
}

void Display::flipPixel( unsigned x, unsigned y ){
	if ( x < PIXELS_WINDOW_X && y < PIXELS_WINDOW_Y ){
		buffer[x][y] = !buffer[x][y];
	}
}

void Display::redraw( ){
	SDL_Rect rectangle;
	rectangle.w = rectangle.h = PIXEL_WIDTH;

	SDL_RenderClear( emulator->renderer );
	SDL_SetRenderDrawColor( emulator->renderer, 0, 0, 0, 0 );
	SDL_RenderFillRect( emulator->renderer, NULL );

	SDL_SetRenderDrawColor( emulator->renderer, 0xff, 0xff, 0xff, 0xff );

	for ( int j = 0; j < PIXELS_WINDOW_Y; j++ ){
		for ( int i = 0; i < PIXELS_WINDOW_X; i++ ){
			if ( getPixel( i, j ) == true ){
				rectangle.x = 1 + i * PIXEL_WIDTH;
				rectangle.y = 1 + j * PIXEL_HEIGHT;

				SDL_RenderFillRect( emulator->renderer, &rectangle );
			}
		}
	}

	SDL_RenderPresent( emulator->renderer );
}
