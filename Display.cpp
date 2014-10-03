#include "Chip8.h"

// Display class methods
Display::Display( Emulator *em ){
	emulator = em;
	buffer   = new bool[64*32];
}

Display::~Display( ){
	delete buffer;
}

void Display::setPixel( unsigned x, unsigned y ){
}

void Display::redraw( ){
}
