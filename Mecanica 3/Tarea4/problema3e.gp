#    2021-04-07
#    problema3e.gp
#    Diego Sarceño (dsarceno68@gmail.com)

#    Programa superficies de nivel, sistema tierra luna

#    Codificación del texto: UTF8
#    Compiladores probados: GNUPLOT (Ubuntu 20.04 Linux) 5.2
#    Instrucciones de compilación: no requere nada mas
#    gnuplot problema3e.gp

#    Copyright (C) 2021
#    D. R. Sarceño Ramírez
#    dsarceno68@gmail.com
#
#    This program is free software: you can redistribute it and/or
#    modify it under the terms of the GNU General Public License as
#    published by the Free Software Foundation, either version 3 of
#    the License, or (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#    General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see
#    <http://www.gnu.org/licenses/>.

# PROGRAM
# terminal
set terminal pdf
set output 'problema3e.pdf'

# divisiones en la superficies para una mejor visión
set isosamples 50

# labels
set title 'Curvas de Nivel del Hamiltoniano (Espacio de Estado)'
set xlabel 'x'
set ylabel 'p'

# superficies de nivel
set size ratio -1
set grid
set view map
set key outside
#set nokey
unset surface
set contour base
set cntrparam levels incremental -10,2,10



## plot
# ranges
set xrange [-5:5]
set yrange [-5:5]

# constantes
g = 9.8

splot 0.5*y**2 + 0.5*x**2 t 'H'


# END PROGRAM
