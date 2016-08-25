#Tyler Forrester
#Makefile for Lab C Makes Main
#July 10, 2016
CXX = g++ 
OBJSL2 = main.o
SRCSL2 = main.cpp
OBJSL3 = InputValid.o
SRCSL3 = InputValid.cpp
HEAD3 = InputValid.hpp
PROG = LabC
#PROGT = Test

all: $(PROG) 

$(PROG): $(OBJSL2) $(OBJSL3) $(HEAD3)
	$(CXX) $(OBJSL2) $(OBJSL3) -o $(PROG)
$(OBJSL2): $(SRCSL2)
	$(CXX) -c $(SRCSL2)
$(OBJSL3): $(SRCSL3) $(HEAD3)
	$(CXX) -c $(SRCSL3)
clean:
	rm -rf $(PROG) *.o *~
