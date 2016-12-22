OBJS = main.o Linked_List.o
CXX = g++-6
DEBUG = -g
CXXFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

main : $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o main

main.o : main.cpp Linked_List.h Linked_List.cpp
	$(CXX) $(CXXFLAGS) main.cpp

Linked_List.o : Linked_List.h Linked_List.cpp
	$(CXX) $(CXXFLAGS) Linked_List.cpp	

clean:
	\rm *.o *main