The calculator will evaluate expressions containing 4 operators- 
addition, subtraction, multiplication and division and also parenthesis. 
Additionally, it will also evaluate expressions containing assignment operator,
The operands can be numbers or variables. 
lexical analyzer in calc.l ﬁle, grammar rules for parser in a calc.y ﬁle.

To run the command use the following commands in ubuntu terminal.

ﬂex calc.l 
yacc -d calc.y 
g++ -c -w lex.yy.c y.tab.c 
g++ -o mycalc y.tab.o lex.yy.o 
./mycalc <in.txt>out.txt
