.PHONY: default

default:
	gcc -std=c++17 -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -Llib -Iinclude -lraylib main.cpp -o main
	clear
	echo "Success"