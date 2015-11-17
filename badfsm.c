// substate machine
//

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

int main (int argc, char *argv[]){
	if(SDL_Init(SDL_INIT_EVENTS)){
		fprintf(stderr, "OOPS: %s\n", SDL_GetError());
	}
	typedef enum state_t{
		zero,
		one,
		two
	}state_t;
	typedef enum substate_t{
		subzero,
		subone,
		subtwo
	}substate_t;
	SDL_Event	ev;
	bool		run = 1;
	state_t		state = zero;
	substate_t	substate = subtwo;
	SDL_Window	*window;

	window = SDL_CreateWindow("test",
			0, 0,
			640, 480,
			SDL_WINDOW_SHOWN);
	if(window == NULL){
		SDL_Log("WINDOW CRAPPED FOO");
		return 1;
	}

	while(run){
		while(SDL_PollEvent(&ev)){
			if(ev.type == SDL_KEYDOWN){
				SDL_Log("STATE %d", state);
				SDL_Log("SUBSTATE %d", substate);
				switch(state){
					case zero:
						if(ev.key.keysym.sym == SDLK_q)
							state = one;
						break;
					case one:
						if(ev.key.keysym.sym == SDLK_u)
							state = two;
						break;
					case two:
						switch(substate){
							case subtwo:
								if(ev.key.keysym.sym == SDLK_a)
									substate = subone;
								break;
							case subone:
								if(ev.key.keysym.sym == SDLK_b)
									substate = subzero;
								break;
							case subzero:
								if(ev.key.keysym.sym == SDLK_c)
									run = 0;
								break;
						}
						break;
				}
			}
		}
		SDL_Delay(20);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
