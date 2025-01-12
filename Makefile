all:
	g++ src/app/main.cpp -Iinclude -Llib -o MiniEngine.exe -lmingw32 -lSDL2main -lSDL2