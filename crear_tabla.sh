#!/bin/bash

set terminal png size 1000,1000
set output 'grafico.png'
set key right bottom
set xlabel "Etiqueta eje X"
set ylabel "Etiqueta Eje Y"
plot 'tiempos.txt' using 1:3 t "Datos columna 2 frente a 1" w l, \
'tiempos.txt' using 1:2 t "Datos columna 3 frente a 1" 