override TAM ?= 4
		ELEM ?= 7

main: exec
	./exec $(TAM) $(ELEM) >> a.txt

exec:	BParalelaM.c
	gcc BParalelaM.c -fopenmp -o exec

clean:
	rm -f exec a.txt a.out
