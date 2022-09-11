build:
	clang++ -std=c++17 ./src/*.cpp -lm -lSDL2 -lSDL2_gfx -g -o 2dphysics;
run:
	./2dphysics;
clean:
	rm 2dphysics;
