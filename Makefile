all: Estrella Astro main 

Astro: Astro.hh Astro.cpp
	g++ -c Astro.cpp

Estrella: Estrella.hh Estrella.cpp
	g++ -c Estrella.cpp

main: main.cpp
	g++ main.cpp Estrella.o Astro.o -lsfml-graphics -lsfml-window -lsfml-system -Wall -o main.exe

clean:
	rm main.exe Astro.o Estrella.o