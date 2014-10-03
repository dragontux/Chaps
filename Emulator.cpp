#include "Chip8.h"

Emulator::Emulator( ){
	cpu     = new Chip8( this );
	display = new Display( this );
	running = false;
}

Emulator::Emulator( char *romfile ){
	cpu     = new Chip8( this );
	display = new Display( this );
	running = false;

	cpu->loadRom( romfile );
}

Emulator::~Emulator( ){
	delete cpu;
	delete display;
}

void Emulator::run( ){
}

void Emulator::pause( ){
}
