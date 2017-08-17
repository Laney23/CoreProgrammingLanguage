# Summary #

This code tokenizes a given CORE program, then parses it, executes it, and pretty prints the given CORE program with the corresponding code executions.

## CORE Language ##
The abstract syntax tree for the CORE programming language is defined as:
<prog>	    ::=    program <decl seq> begin <stmt seq> end
<decl seq>	::=    <decl> | <decl> <decl seq>
<stmt seq>	::=    <stmt> | <stmt> <stmt seq>
<decl>		    ::=	int  <id list>;
<id list>		::=	<id> | <id>, <id list>
<stmt>		::=	<assign>|<if>|<loop>|<in>|<out>
<assign>		::=	<id> = <exp>;
<if>				::=	if <cond> then <stmt seq> end;
|       if <cond> then <stmt seq> else <stmt seq> end;
<loop>		::=	while <cond> loop <stmt seq> end;
<input>		::=	read <id list>;
<output>		::=	write <id list>;
<cond>       ::=	<comp> | !<cond>
|       [<cond> && <cond>] | [<cond> or <cond>]
<comp>	    ::=   (<op> <comp op> <op>)
<exp>         ::=   <fac>|<fac>+<exp>|<fac>-<exp>
<fac>          ::=   <op> | <op> * <fac>
<op>           ::=  <int> | <id> | (<exp>)
<comp op> ::=  != | == | < | > | <= | >=
<id>            ::=  <let> | <let><id> | <let><int>
<let>           ::=  A | B | C | ... | X | Y | Z
<int>           ::=  <digit> | <digit><int>
<digit>        ::=  0 | 1 | 2 | 3 | ... | 9

The reserved words are:
* program
* begin
* end
* int
* if
* then
* else
* while
* loop
* read
* write

Special symbols are:
* ;
* ,
* =
* !
* [
* ]
* &&
* ||
* (
* )
* +
* -
* *
* !=
* ==
* <
* >
* <=
* >=
