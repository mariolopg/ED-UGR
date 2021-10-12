CPP=$(wildcard *.cpp)
EXE=$(basename $(CPP))
# Modifica aquí para ajustar el nivel de optimización (de 0 a 3):
CPPFLAGS=-O0
DAT=tiempos_busqueda.dat tiempos_ej2.dat

.PHONY: default clean tiempos

default: $(EXE)

clean:
	rm -f $(EXE) $(DAT)

# Modifica aquí para cambiar los puntos de inicio, fin y los saltos:
inicio_busq=100
fin_busq=1000000
incremento=1000

tiempos: $(DAT)

tiempos_busqueda.dat: busqueda_lineal
	for (( i=$(inicio_busq); i < $(fin_busq); i+=$(incremento) )); do \
		cmd="./$< $$i 10000"; \
		echo -en "\r$$cmd"; \
		$$cmd >> $@; \
	done

tiempos_ej2.dat: ejercicio2
	@echo "Ejecutando $<"
	./$< > $@
