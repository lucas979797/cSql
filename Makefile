run: repl
	./repl

repl : repl.c aux.c
	gcc -Wall repl.c aux.c -o repl

debug: clean repl.c aux.c
	gcc -Wall -g repl.c aux.c -o repl


clean:
	rm -f ./repl
	rm -rf *.dSYM