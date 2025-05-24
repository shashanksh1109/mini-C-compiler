all:
	flex lexer.l
	bison -d parser.y
	gcc -o minic main.c parser.tab.c lex.yy.c ast.c -lfl

clean:
	rm -f *.o *.tab.* lex.yy.c minic