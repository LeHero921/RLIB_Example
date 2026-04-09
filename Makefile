# 1. Variablen definieren (Macht das Makefile flexibler)
CXX      = g++
CXXFLAGS = -std=c++20 -Iinclude
LDFLAGS  = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -Llib -lraylib

# 2. Verzeichnisse
BUILD_DIR = build

# 3. Dateien automatisch erfassen oder explizit auflisten
SRCS = main.cpp base.cpp resourceLoader.cpp drawHandler.cpp input.cpp animation.cpp entity.cpp physics.cpp debug.cpp

# Wandelt die .cpp Namen in .o Namen um und setzt das Build-Verzeichnis davor
# Aus "main.cpp" wird "build/main.o"
OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Das fertige Programm
TARGET = $(BUILD_DIR)/main

# Diese Targets erzeugen keine Dateien
.PHONY: all run clean

# Standard-Target
all: $(TARGET)

# 4. Der Linker-Schritt: Baut das finale Programm aus den .o Dateien
$(TARGET): $(OBJS)
	@echo "Linking..."
	$(CXX) $(OBJS) $(LDFLAGS) -o $@
	@echo "Build Success"

# 5. Der Kompilier-Schritt: Baut aus jeder .cpp eine .o Datei im build-Ordner
# Das Pipe-Symbol '|' stellt sicher, dass der build-Ordner existiert, 
# bevor kompiliert wird.
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 6. Erstellt das Build-Verzeichnis, falls es nicht existiert
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Führt das Programm aus (und baut es vorher, falls nötig)
run: all
	./$(TARGET)

# Säubert das Projekt (löscht den Build-Ordner)
clean:
	rm -rf $(BUILD_DIR)