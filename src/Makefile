CXX = g++
CXXFLAGS = -Wall -g

bubbleblast: main.o board.o tinybubble.o
	$(CXX) $(CXXFLAGS) -o bubbleblast main.o board.o tinybubble.o


main.o: main.cpp board.h tinybubble.h
tinybubble.o: tinybubble.h
board.o: board.h tinybubble.h

clean:
	rm *.o bubbleblast
