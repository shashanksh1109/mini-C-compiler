%{
#include "parser.tab.h"
%}

digit   [0-9]
id      [a-zA-Z_][a-zA-Z0-9_]*
ws      [ \t\r\n]+

%%

{digit}+            { yylval.num = atoi(yytext); return NUM; }
{digit}+"."{digit}+ { yylval.num = atof(yytext); return NUM; }
"int"               { return INT; }
"return"            { return RETURN; }
{id}                { yylval.id = strdup(yytext); return ID; }
"="                 { return '='; }
";"                 { return ';'; }
"("                 { return '('; }
")"                 { return ')'; }
"+"                 { return '+'; }
"*"                 { return '*'; }

{ws}                { /* ignore whitespace */ }

.                   { return yytext[0]; }

%%