#!/bin/csh
@ inicio = 500
@ fin = 500000
@ incremento = 500
set ejecutable = busqueda_unordered_set
set salida = tiempos_busqueda_unordered_set.dat

@ i = $inicio
echo > $salida
make $ejecutable
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
