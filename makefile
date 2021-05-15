EXEC = Project2
READERS = card.h deck.h SortedLinkedList.h rank.h pokerhand.h
		  #(listing all header files)
OBJECTS = card.o deck.o SortedLinkedList.o rank.o pokerhand.o
          #(listing all object files)
$(EXEC) : $(OBJECTS) Project2.o
	g++ $^ -o $@
testPA2 : testPA2.o $(OBJECTS)
	g++ $^ -o $@
Project2.o : PA2.cpp
	g++ -c $^ -o $@
testPA2.o : testPA2.cpp
	g++ -c $^ -o $@
%.o : %.cpp %.h
	g++ -c $<
clean :
	rm -i *.o
	rm -i `find ./ -type f -executable`
