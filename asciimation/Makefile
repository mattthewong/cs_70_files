CXX = clang++

CXX_FLAGS = -g -std=c++11 -pedantic -Wall -Wextra

Asciimation: our-movie.cpp asciimation.o sprite.o ncurses-helper.o
	$(CXX) our-movie.cpp -o Asciimation $(CXX_FLAGS) asciimation.o sprite.o ncurses-helper.o -lncurses

asciimation.o: asciimation.cpp asciimation.hpp ncurses-helper.hpp sprite.hpp
	$(CXX) asciimation.cpp -c $(CXX_FLAGS)

sprite.o: sprite.cpp sprite.hpp
	$(CXX) sprite.cpp -c $(CXX_FLAGS)

ncurses-helper.o: ncurses-helper.cpp ncurses-helper.hpp
	$(CXX) ncurses-helper.cpp -c $(CXX_FLAGS)

clean:
	rm -rf *.o Asciimation