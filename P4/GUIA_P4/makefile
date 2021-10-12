BIN=bin
OBJ=obj
SRC=src
INC=inc
RES=result
DAT=data

usoguia: $(SRC)/usoguia.cpp $(SRC)/guiatlf.cpp $(INC)/guiatlf.h
	g++  -o $(BIN)/usoguia -I./$(INC) $(SRC)/usoguia.cpp $(SRC)/guiatlf.cpp

documentacion:
	doxygen doc/Doxyfile

doxygen:
	firefox doc/html/index.html

clean:
	rm $(BIN)/*