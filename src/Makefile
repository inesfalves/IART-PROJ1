CXX = g++
CXXFLAGS = -Wall -g

bubbleblast: main.o board.o tinybubble.o solution_graph.o
	$(CXX) $(CXXFLAGS) -o bubbleblast main.o board.o tinybubble.o solution_graph.o


main.o: main.cpp board.h tinybubble.h
tinybubble.o: tinybubble.h
board.o: board.h tinybubble.h
solution_graph.o: solution_graph.h board.h

clean:
	rm *.o bubbleblast
