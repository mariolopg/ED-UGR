SRC = src
INC = include
OBJ = obj
DAT = datos
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -o
FUENTES = $(SRC)/rutas_aereas.cpp $(SRC)/Punto.cpp $(SRC)/Ruta.cpp $(SRC)/almacen_rutas.cpp $(SRC)/imagen.cpp $(SRC)/imagenES.cpp
INCLUDES = $(INC)/Pais.h $(INC)/Paises.h $(INC)/imagen.h $(INC)/almacen_rutas.h

# Ejecución
rutas_aereas: $(BIN)/rutas_aereas
	./$< $(DAT)/paises.txt $(DAT)/imagenes/mapas/mapa1.ppm $(DAT)/imagenes/banderas/ $(DAT)/almacen_rutas.txt $(DAT)/imagenes/aviones/avion5.ppm $(DAT)/imagenes/aviones/mascara_avion5.pgm

# Crear ejecutables

$(BIN)/rutas_aereas: $(FUENTES) $(INCLUDES)
	g++ $(CPPFLAGS) $@ $^	

# ************ Crear Objetos ******************

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	g++ -g -c -o $@  -I./$(INC) $<

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	g++ -g -c -o $@  -I./$(INC) $<

$(OBJ)/Pais.o:  $(INC)/Pais.h
	g++ $(CPPFLAGS) -o $@ $<

$(OBJ)/Paises.o:  $(INC)/Paises.h
	g++ $(CPPFLAGS) -o $@ $<

$(OBJ)/rutas_aereas.o:  $(SRC)/rutas_aereas.cpp 
	g++ $(CPPFLAGS) -o $@ $<

$(OBJ)/almacen_rutas.o:  $(SRC)/almacen_rutas.cpp 
	g++ $(CPPFLAGS) -o $@ $<

$(OBJ)/Ruta.o:  $(SRC)/Ruta.cpp 
	g++ $(CPPFLAGS) -o $@ $<

$(OBJ)/Punto.o:  $(SRC)/Punto.cpp 
	g++ $(CPPFLAGS) -o $@ $<


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Visualizar documentación ******************
doxygen:
	firefox doc/html/index.html

# ************ Limpieza ************
clean:
	-rm $(OBJ)/* $(BIN)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
