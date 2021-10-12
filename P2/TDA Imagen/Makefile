BIN=bin
OBJ=obj
SRC=src
INC=inc
RES=result
DAT=data

# Ejecución
morph: $(BIN)/morphing
	./$<  $(DAT)/castillo.pgm $(DAT)/gal.ppm $(RES)/morphing/castillo_galaxia/casgal

ac: $(BIN)/aumentoContraste
	./$<  $(DAT)/mandrill.ppm $(RES)/mandrill.pgm

zoom: $(BIN)/zoom
	./$<  $(DAT)/earth.ppm $(RES)/earth_zoom.pgm 0 0 150 150

umb: $(BIN)/umbralizacion
	./$<  $(DAT)/peppers.ppm $(RES)/peppers_umbral.pgm

rgb: $(BIN)/RGBaGris
	./$<  $(DAT)/mandrill.ppm $(RES)/mandrill_gris.pgm

ne: $(BIN)/negativo
	./$<  $(DAT)/cameraman.pgm $(RES)/cameraman_neg.pgm

# Crear ejecutables

$(BIN)/morphing: $(OBJ)/morphing.o $(OBJ)/imagenES.o $(OBJ)/Imagen.o
	g++ -g -o $@ $^	

$(BIN)/aumentoContraste: $(OBJ)/aumentoContraste.o $(OBJ)/imagenES.o $(OBJ)/Imagen.o
	g++ -g -o $@ $^	

$(BIN)/zoom: $(OBJ)/zoom.o $(OBJ)/imagenES.o $(OBJ)/Imagen.o
	g++ -g -o $@ $^	

$(BIN)/umbralizacion: $(OBJ)/umbralizacion.o $(OBJ)/imagenES.o $(OBJ)/Imagen.o
	g++ -g -o $@ $^	

$(BIN)/RGBaGris: $(OBJ)/RGBaGris.o $(OBJ)/imagenES.o $(OBJ)/Imagen.o
	g++ -g -o $@ $^

$(BIN)/negativo: $(OBJ)/negativo.o $(OBJ)/imagenES.o
	g++ -g -o $@ $^

# Crear objetos

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	g++ -g -c -o $@  -I./$(INC) $<

$(OBJ)/Imagen.o: $(SRC)/Imagen.cpp $(INC)/Imagen.h
	g++ -g -c -o $@  -I./$(INC) $<

$(OBJ)/morphing.o : $(SRC)/morphing.cpp
	g++ -g -c -o  $@ -I./$(INC)  $^

$(OBJ)/aumentoContraste.o: $(SRC)/aumentoContraste.cpp
	g++ -g -c -o  $@ -I./$(INC) $(SRC)/aumentoContraste.cpp

$(OBJ)/zoom.o: $(SRC)/zoom.cpp
	g++ -g -c -o  $@ -I./$(INC) $^

$(OBJ)/umbralizacion.o: $(SRC)/umbralizacion.cpp
	g++ -g -c -o  $@ -I./$(INC)  $^

$(OBJ)/RGBaGris.o: $(SRC)/RGBaGris.cpp
	g++ -g -c -o  $@ -I./$(INC)  $^

$(OBJ)/negativo.o : $(SRC)/negativo.cpp
	g++ -g -c -o  $@ -I./$(INC)  $^

# Otras reglas

clean:
	-rm $(OBJ)/* $(BIN)/*

clean_morph:
	-rm $(RES)/morphing/* 

documentacion:
	doxygen doc/Doxyfile

doxygen:
	firefox doc/html/index.html
