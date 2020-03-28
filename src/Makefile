CXX = g++
CXXFLAGS = -Wall -g

bubbleblast: main.o board.o tinybubble.o solution_graph.o menu.o
	$(CXX) $(CXXFLAGS) -o bubbleblast main.o board.o tinybubble.o solution_graph.o menu.o


main.o: main.cpp board.h tinybubble.h solution_graph.h menu.h
tinybubble.o: tinybubble.h
board.o: board.h tinybubble.h
solution_graph.o: solution_graph.h board.h
menu.o: menu.h 

clean:
	rm *.o bubbleblast
