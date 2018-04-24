import numpy as np
import matplotlib.pyplot as plt

datos=np.loadtxt('advection.txt')
sep = int(700/4)
tiempo = np.arange(0,701,sep)##arreglo con los tiempos que estan en el archico
print tiempo
for t in tiempo:
	x=datos[datos[:,0]==t,1]#para cada tiempo que imprimi en la columna 1, obtengo x y y (que imprimi en columna 2 y 3)
	y=datos[datos[:,0]==t,2]
	try:
		plt.plot(x,y,label=r'$t='+ str(t) + r'$')
	except:
		print t
plt.xlabel(r'$x$')
plt.ylabel(r'$y(x,t)$')
plt.legend()
plt.ylim(0,1)
plt.title('Grafica')
plt.savefig('grafica.png')
	
