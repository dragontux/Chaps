SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)
CPPFLAGS=`sdl2-config --cflags --libs` -Wall -O2

chaps: $(OBJS)
	g++ -o $@ $(OBJS)

clean:
	rm -f $(OBJS) chaps

.PHONY: chaps

