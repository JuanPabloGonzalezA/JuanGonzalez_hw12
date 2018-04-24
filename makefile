grafica.png : advection.txt
	python JG_graph.py
advection.txt : a.out
	./a.out > advection.txt
a.out : 
	c++ JG_advection.cpp
clean :
	rm grafica.png advection.txt a.out
