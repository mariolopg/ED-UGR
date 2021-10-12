#!/bin/csh
@ inicio = 500
@ fin = 300000
@ incremento = 500
set ejecutable = borrado_list
set salida = tiempos_borrado_list.dat

@ i = $inicio
echo > $salida
make $ejecutable
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
