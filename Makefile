.PHONY: default

default:
	g++ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -Llib -Iinclude -lraylib main.cpp player.cpp physics.cpp entity.cpp debug.cpp -o main
	clear
	echo "Success"