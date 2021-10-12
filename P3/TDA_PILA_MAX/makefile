BIN=bin
OBJ=obj
SRC=src
INCLUDE=inc
RES=result
DAT=data
CPPFLAGS = -g -I$(INCLUDE) -I$(SRC) -o

# Ejecutar
usopilasmax_vector: $(BIN)/usopilasmax_vector
	./$< 

usopilasmax_cola: $(BIN)/usopilasmax_cola
	./$< 

usopilasmax: $(BIN)/usopilasmax
	./$< 

usopilas: $(BIN)/usopilas
	./$< 

# Crear ejecutables

$(BIN)/usopilas : $(SRC)/usopilas.cpp 
	g++ $(CPPFLAGS) $(BIN)/usopilas $(SRC)/usopilas.cpp 

$(BIN)/usopilasmax : $(SRC)/usopilasmax.cpp $(SRC)/pila_max.cpp
	g++ $(CPPFLAGS) $@ $^

$(BIN)/usopilasmax_cola : $(SRC)/usopilasmax_cola.cpp $(SRC)/Pila_max_Cola.cpp 
	g++ $(CPPFLAGS) $@ $^

$(BIN)/usopilasmax_vector: $(SRC)/usopilasmax_vector.cpp $(SRC)/Pila_max_Cola.cpp 
	g++ $(CPPFLAGS) $@ $^
	
# Otras reglas

clean:
	-rm $(OBJ)/* $(BIN)/*

documentacion:
	doxygen doc/Doxyfile

doxygen:
	firefox doc/html/index.html