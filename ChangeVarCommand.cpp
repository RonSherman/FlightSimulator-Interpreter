//
// Created by amitnir29 on 06/01/2020.
//

#include "ChangeVarCommand.h"
//x= heading+ 5
int ChangeVarCommand::execute(Compiler* cp) {
	//get the name of var
	string varName = cp->token[cp->index];
	//get the val expression
	string express = cp->token[cp->index+2];
	//somehow calculate the actual float value, using conditionParser
	ConditionParser conParser = ConditionParser();
	double val =conParser.varsFromExp(express, cp);
    cout << varName << " = " << val << endl;
	//TODO parser work properly
	
	//update the symbol table
	cp->getSymbolTable().setValueFromName(varName, val);
	//TODO add connection.send
	cp->connection.senddata("set"+cp->getSymbolTable().getPath(varName),val);
	//cp->connection.senddata(path, value(float));
	return 3;

}