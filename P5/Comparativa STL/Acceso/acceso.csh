#!/bin/csh
@ inicio = 500
@ fin = 500000
@ incremento = 500
set ejecutable = acceso_set
set salida = tiempos_acceso_set.dat

@ i = $inicio 
echo > $salida
make $ejecutable
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
