CXX      = g++

# Compiler sucht nur noch im eigenen include-Ordner (wo jetzt auch die Engine liegt)
CXXFLAGS = -std=c++20 -Iinclude 

# Linker sucht im lokalen lib-Ordner nach libquantuum.a und libraylib.a
LDFLAGS  = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL \
           -Llib -lquantuum -lraylib

SRC_DIR   = src
BUILD_DIR = build
TARGET    = $(BUILD_DIR)/main

# Sucht alle Game-Dateien (.cpp) in src/ und Unterordnern
SRCS = $(shell find $(SRC_DIR) -name '*.cpp')
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

.PHONY: all run clean

all: $(TARGET)

# Baut das finale Spiel
$(TARGET): $(OBJS)
	@echo "=== Linking Game ==="
	@$(CXX) $(OBJS) $(LDFLAGS) -o $@
	@echo "=== Game Build Success! ==="

# Kompiliert nur deinen Spiel-Code
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling Game: $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Baut und startet das Spiel direkt
run: all
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)