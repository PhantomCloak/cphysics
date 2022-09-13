build:
	g++ -std=c++17 -Wall ./src/*.cpp ./src/Physics/*.cpp -L/opt/homebrew/Cellar/sdl2/2.0.22/lib -L/opt/homebrew/Cellar/sdl2_gfx/1.0.4/lib -lm -lSDL2 -lSDL2_gfx -g -o cphysics;
run:
	./cphysics;
clean:
	rm cphysics;
