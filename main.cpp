#include "Chip8.h"
#include <iostream>

int main( int argc, char *argv[] ){
	Emulator *emu;
	
	if ( argc > 1 ){
		std::cout << "Opening rom file " << argv[1] << std::endl;

		emu = new Emulator( argv[1] );
		std::cout << emu << std::endl;

		delete emu;

	} else {
		std::cout << "Usage: chaps [rom file]" << std::endl;
	}

	return 0;
}
