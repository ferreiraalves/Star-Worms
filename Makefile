FONTES = main.c background.c players.c projetil.c mira.c loadtexture.c obstacle.c vento.c hearth.c
OBJETOS = main.o background.o players.o projetil.o mira.o loadtexture.o obstacle.o vento.o hearth.o

all:	main clean run

main : $(OBJETOS)
	gcc $(OBJETOS) -o main -lGL -lglut -lGLU -lm -lSOIL
	

$(OBJETOS) : $(FONTES)
	gcc -c $(FONTES)

clean :
	-@ rm -f $(OBJETOS)

run:
	./main
