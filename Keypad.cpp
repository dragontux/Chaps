#include "Chip8.h"

Keypad::Keypad( Emulator *em ){
	emulator = em;
	quit = false;

	for ( int i = 0; i < 16; i++ )
		keys[i] = false;
}

Keypad::~Keypad( ){
}

void Keypad::checkKeys( ){
	SDL_Event e;

	if ( SDL_PollEvent( &e ) != 0 ){
		if ( e.type == SDL_QUIT ){
			quit = true;

		} else if ( e.type == SDL_KEYDOWN ){
			printf( "[%s] Key down\n", __func__ );

			switch( e.key.keysym.sym ){
				case SDLK_1: keys[  1] = true; break;
				case SDLK_2: keys[  2] = true; break;
				case SDLK_3: keys[  3] = true; break;
				case SDLK_4: keys[0xc] = true; break;

				case SDLK_q: keys[  4] = true; break;
				case SDLK_w: keys[  5] = true; break;
				case SDLK_e: keys[  6] = true; break;
				case SDLK_r: keys[0xd] = true; break;

				case SDLK_a: keys[  7] = true; break;
				case SDLK_s: keys[  8] = true; break;
				case SDLK_d: keys[  9] = true; break;
				case SDLK_f: keys[0xe] = true; break;

				case SDLK_z: keys[0xa] = true; break;
				case SDLK_x: keys[  0] = true; break;
				case SDLK_c: keys[0xb] = true; break;
				case SDLK_v: keys[0xf] = true; break;

				default: break;
			}

		} else if ( e.type == SDL_KEYUP ){
			printf( "[%s] Key up\n", __func__ );

			switch( e.key.keysym.sym ){
				case SDLK_1: keys[  1] = false; break;
				case SDLK_2: keys[  2] = false; break;
				case SDLK_3: keys[  3] = false; break;
				case SDLK_4: keys[0xc] = false; break;

				case SDLK_q: keys[  4] = false; break;
				case SDLK_w: keys[  5] = false; break;
				case SDLK_e: keys[  6] = false; break;
				case SDLK_r: keys[0xd] = false; break;

				case SDLK_a: keys[  7] = false; break;
				case SDLK_s: keys[  8] = false; break;
				case SDLK_d: keys[  9] = false; break;
				case SDLK_f: keys[0xe] = false; break;

				case SDLK_z: keys[0xa] = false; break;
				case SDLK_x: keys[  0] = false; break;
				case SDLK_c: keys[0xb] = false; break;
				case SDLK_v: keys[0xf] = false; break;

				default: break;
			}
		}
	}
}

bool Keypad::isSet( unsigned key ){
	bool ret = false;

	if ( key < 16 ){
		ret = keys[key];
	}

	return ret;
}

bool Keypad::quitIsSet( ){
	return quit;
}
