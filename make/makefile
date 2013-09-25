###########################################################################
#	FILE NAME :	makefile					  #
#       PURPOSE   :	compile the code				  #
#	DATE      :	21/09/13					  #
#	TEAM 	  : 	Nalini Deswal 				  	  #
#			Narendra Nalli  				  #
#			Pankaj Kashyap   				  #
###########################################################################

OBJ = ../obj/
INC = ../include/
SRC = ../src/
BIN = ../bin/

all : $(BIN)kst

$(BIN)kst : $(OBJ)sort.o $(OBJ)unionfind.o  $(OBJ)kruskal.o $(OBJ)main.o
	g++ -g -o $(BIN)kst $(OBJ)sort.o $(OBJ)unionfind.o $(OBJ)kruskal.o $(OBJ)main.o -I$(INC)

$(OBJ)sort.o : $(SRC)sort.cpp $(INC)header.h
	g++ -g -o $(OBJ)sort.o -c $(SRC)sort.cpp -I$(INC)

$(OBJ)unionfind.o : $(SRC)unionfind.cpp $(INC)header.h
	g++ -g -o $(OBJ)unionfind.o -c $(SRC)unionfind.cpp -I$(INC)

$(OBJ)kruskal.o : $(SRC)kruskal.cpp $(INC)header.h
	g++ -o $(OBJ)kruskal.o -c $(SRC)kruskal.cpp -I$(INC)

$(OBJ)main.o : $(SRC)main.cpp $(INC)header.h
	g++ -o $(OBJ)main.o -c $(SRC)main.cpp -I$(INC)

clean :
	rm ../obj/*
	rm ../bin/*

plot :
	dot -Tps input_graph.gv -o input.ps
	dot -Tps output_graph.gv -o output.ps

display :
	gv input.ps
	gv output.ps
