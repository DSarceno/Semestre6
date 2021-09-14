#    2021-09-12
#    graph.py
#    Diego Sarceño (dsarceno68@gmail.com)

#    Ajuste realizado para encontrar el factor Gamma en la relación P=K/V^Gamma

#    Codificación del texto: UTF8
#    Compiladores probados: GNUPLOT (Ubuntu 20.04 Linux) 5.2
#    Instrucciones de compilación: no requere nada mas
#    python3 graph.py

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
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


file = open('datos.csv','r')

data = [line.split(',') for line in file]
file.close()

ready = [[float(data[i][j]) for j in range(len(data[i]))] for i in range(len(data))]
print(ready)

time = [ready[i][0] for i in range(len(ready))]
temp = [ready[i][3] for i in range(len(ready))]
pressure = [ready[i][2] for i in range(len(ready))]
volume = [ready[i][1] for i in range(len(ready))]


# INCISO 1
file = open('pv.tsv','w')
for i in range(len(ready)):
    file.write(str(ready[i][1]) + '\t' + str(ready[i][2]) + '\n')
file.close()

# INCISO 2
plt.plot(time, temp,label='Temperatura')
plt.legend()
plt.title('Inciso 2')
plt.xlabel('Tiempo (min)')
plt.ylabel('Temperatura')
plt.xlim(1.58,1.62)
plt.savefig('inciso2.pdf')
plt.show()


# INCISO 3

fig = plt.figure()
ax = Axes3D(fig)
ax.scatter(volume,temp,pressure)
ax.set_xlabel('Volumen')
ax.set_ylabel('Temperatura')
ax.set_zlabel('Presión')
plt.savefig('inciso3.pdf')
plt.show()

