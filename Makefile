OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG  -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o Cuenca.o Ciudad.o Producto.o Cjt_Productos.o Barco.o
	g++ -o program.exe program.o Cuenca.o Ciudad.o Producto.o Cjt_Productos.o Barco.o

Cuenca.o:  Cuenca.cc Cuenca.hh Ciudad.hh BinTree.hh
	g++ -c Cuenca.cc $(OPCIONS)

Producto.o:  Producto.cc Producto.hh
	g++ -c Producto.cc $(OPCIONS)

Barco.o:  Barco.cc Barco.hh Cjt_Productos.hh
	g++ -c Barco.cc $(OPCIONS)

Cjt_Productos.o:  Cjt_Productos.cc Cjt_Productos.hh Producto.hh
	g++ -c Cjt_Productos.cc $(OPCIONS)

Ciudad.o: Ciudad.cc Ciudad.hh Cjt_Productos.hh
	g++ -c Ciudad.cc $(OPCIONS)

program.o: program.cc Cuenca.hh Cjt_Productos.hh Barco.hh
	g++ -c program.cc $(OPCIONS)

clean:
	rm -f *.o 
	rm -f *.exe

practica.tar:
	tar -cvf practica.tar program.cc Makefile Cuenca.cc Cuenca.hh Barco.cc Barco.hh Ciudad.cc Ciudad.hh Cjt_Productos.cc Cjt_Productos.hh Producto.cc Producto.hh html.zip justificacion.pdf
