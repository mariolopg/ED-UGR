#!/bin/csh
@ inicio = 100
@ fin = 1000000
@ incremento = 500
set ejecutable = ejercicio3_arreglo
set salida = tiempos_bbinaria.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
