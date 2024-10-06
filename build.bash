g++ $(find . -name .git -prune -o -name '*.cpp' -print) -I$(find . -name .git -prune -o -type d -print) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o game
