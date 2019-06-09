opts = -std=c++11

main: button.o kde_button.o gnome_button.o kde_button_factory.o gnome_button_factory.o main.o
	g++ $(opts) -o main button.o kde_button.o gnome_button.o kde_button_factory.o gnome_button_factory.o main.o

main.o: main.cc
	g++ $(opts) -c -o main.o main.cc

kde_button_factory.o: button_factory.h kde_button_factory.cc
	g++ $(opts) -c -o kde_button_factory.o kde_button_factory.cc

gnome_button_factory.o: button_factory.h gnome_button_factory.cc
	g++ $(opts) -c -o gnome_button_factory.o gnome_button_factory.cc

gnome_button.o: gnome_button.cc
	g++ $(opts) -c -o gnome_button.o gnome_button.cc

kde_button.o: kde_button.cc
	g++ $(opts) -c -o kde_button.o kde_button.cc

button.o: button.cc
	g++ $(opts) -c -o button.o button.cc

.PHONY: clean
clean:
	rm -f *.o main
