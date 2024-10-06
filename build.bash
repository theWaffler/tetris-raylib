g++ $(find . -name '*.cpp') -I$(find . -type d) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o game
