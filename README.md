# Summary #

This code tokenizes a given CORE program, then parses it, executes it, and pretty prints the given CORE program with the corresponding code executions.

# Use #
Call the program as follows:

`./core_interpreter coreProgram inputData`

Where both `coreProgram` and `inputData` are files located in the current directory and `core_interpreter` is the compiled program name.

## CORE Language ##
The abstract syntax tree for the CORE programming language (with the corresponding token number in parenthesis) is defined as:
1.   \<prog>	        ::=    program \<decl seq> begin \<stmt seq> end
2.   \<decl seq>	::=    \<decl> | \<decl> \<decl seq>
3.   \<stmt seq>	::=    \<stmt> | \<stmt> \<stmt seq>
4.   \<decl>		    ::=	int  \<id list>;
5.   \<id list>		    ::=	\<id> | \<id>, \<id list>
6.   \<stmt>		    ::=	\<assign> | \<if> | \<loop> | \<in> | \<out>
7.   \<assign>		::=	\<id> = \<exp>;
8.   \<if>				::=	if \<cond> then \<stmt seq> end;     |     if \<cond> then \<stmt seq> else \<stmt seq> end;
9.   \<loop>		    ::=	while \<cond> loop \<stmt seq> end;
10. \<input>		    ::=	read \<id list>;
11. \<output>		::=	write \<id list>;
12. \<cond>         ::=	\<comp> | !\<cond>   |   [\<cond> && \<cond>]   |   [\<cond> || \<cond>]
13. \<comp>	        ::=   (\<op> \<comp op> \<op>)
14. \<exp>           ::=   \<fac>|\<fac>+\<exp>|\<fac>-\<exp>
15. \<fac>            ::=   \<op> | \<op> * \<fac>
16. \<op>             ::=  \<int> | \<id> | (\<exp>)
17. \<comp op>   ::=    != | == | \< | \> | \<= | \>=
18. \<id>              ::=  \<let> | \<let>\<id> | \<let>\<int>
19. \<let>             ::=  A | B | C | ... | X | Y | Z
20. \<int>             ::=  \<digit> | \<digit>\<int>
21. \<digit>          ::=  0 | 1 | 2 | 3 | ... | 9

The reserved words are:
* program (1)
* begin (2)
* end (3)
* int (4)
* if (5)
* then (6)
* else (7)
* while (8)
* loop (9)
* read (10)
* write (11)

Special symbols are:
* ; (12)
* , (13)
* = (14)
* ! (15)
* [ (16)
* ] (17)
* && (18)
* || (19)
* ( (20)
* ) (21)
* \+ (22)
* \- (23)
* \* (24)
* != (25)
* == (26)
* < (27)
* \> (28)
* <= (29)
* \>= (30)
* Numbers (31)
* Identifiers (32)
* EOF Marker (33)

All identifiers must start with an uppercase letter and be followed by zero or more uppercase letters or digits. All integers most be positive (unsigned).


