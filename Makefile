# Define compiler and compiler flags for Web (Emscripten)
CC = emcc
CFLAGS = -s USE_GLFW=3 -s USE_WEBGL2=1 -s WASM=1 -O2
LDFLAGS = -s ALLOW_MEMORY_GROWTH=1

# Raylib and project paths
RAYLIB_PATH = /home/jay/workspace/raylib
INCLUDE_FLAGS = -I$(RAYLIB_PATH)/src -I$(RAYLIB_PATH)/src/external
LIBS = $(RAYLIB_PATH)/src/libraylib.a -lGL -lm -lpthread -ldl -lrt -lX11

# Source files (modify this list if you have more files)
SRC = block.cpp blocks.cpp color.cpp game.cpp grid.cpp main.cpp position.cpp

# Output directory for Web build
OUTPUT = web/index.html

# Compilation rules
all:
	$(CC) $(SRC) $(CFLAGS) $(INCLUDE_FLAGS) $(LIBS) \
	--preload-file jet.ttf \
	--preload-file rotate.mp3 \
	--preload-file clear.wav \
	--preload-file daft.wav \
	-o $(OUTPUT) $(LDFLAGS)

clean:
	rm -rf web/*.html web/*.js web/*.wasm
