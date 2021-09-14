#    2021-09-12
#    ajuste.gp
#    Diego Sarceño (dsarceno68@gmail.com)

#    Ajuste realizado para encontrar el factor Gamma en la relación P=K/V^Gamma

#    Codificación del texto: UTF8
#    Compiladores probados: GNUPLOT (Ubuntu 20.04 Linux) 5.2
#    Instrucciones de compilación: no requere nada mas
#    gnuplot ajuste.gp

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
set output 'ajuste.pdf'

# labels
set title 'Ajuste P-V'
set xlabel 'V'
set ylabel 'P'

# superficies de nivel
set size ratio -1
set grid
set view map
#set key outside
set nokey
set contour base


f(x) = a*x**(-b)

fit f(x) 'pv.tsv' using 1:2 via a,b



stats "pv.tsv" using 1:2

## plot
# ranges
#set xrange [-1.5:1.5]
#set yrange [-1.5:1.5]



plot 'pv.tsv' using 1:2, f(x)


# END PROGRAM
