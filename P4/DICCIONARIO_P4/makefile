BIN=bin
OBJ=obj
SRC=src
INCLUDE=inc
RES=result
DAT=data
CPPFLAGS = -g -I$(INCLUDE) -I$(SRC) -o

# Ejecutar

main_dic: $(BIN)/main_dic
	./$< 

# Crear ejecutables

$(BIN)/main_dic: $(SRC)/main_dic.cpp $(SRC)/diccionario.cpp 
	g++ $(CPPFLAGS) $@ $<
	
# Otras reglas

documentacion:
	doxygen doc/Doxyfile

doxygen:
	firefox doc/html/index.html

clean:
	rm $(BIN)/*