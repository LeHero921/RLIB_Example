.PHONY: default run

default:
	clear
	g++ -std=c++20 -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -Llib -Iinclude -lraylib main.cpp base.cpp resourceLoader.cpp drawHandler.cpp physics.cpp entity.cpp debug.cpp -o main
	clear
	echo "Build Success"

r: default
	./main