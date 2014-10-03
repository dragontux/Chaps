#include "Chip8.h"

// Chip8 class methods
Chip8::Chip8( Emulator *em ){
	emulator = em;
	memory   = NULL;
	rom      = NULL;
}

Chip8::~Chip8( ){
}

void Chip8::step( ){
}

bool Chip8::loadRom( char *romfile ){
	return true;
}
