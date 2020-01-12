//
// Created by amitnir29 on 06/01/2020.
//

#include "Parser.h"
#include "Compiler.h"
/*#include "openServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "ChangeVarCommand.h"*/
#include "Command.h"
#include "openServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "ChangeVarCommand.h"
void Parser::parsing(Compiler *cp) {
    cout <<"commnd is: " <<  cp->token[cp->index] << endl;
   //while (cp->index < cp->token.size()) {
    if (this->commands.find(cp->token[cp->index]) != this->commands.end())
    {
		//cout <<"inside loop" <<cp->token[cp->index]<<endl;
        cp->index += this->commands.at(cp->token[cp->index])->execute(cp);
    }
    else {
        ChangeVarCommand* changevar;
        cp->index += changevar->execute(cp);
    }
  //}
}

void Parser::createmap() {
    openServerCommand* openServerCommand1 = new openServerCommand();
    ConnectCommand* connectCommand = new ConnectCommand();
    DefineVarCommand* defineVarCommand = new DefineVarCommand();
    PrintCommand* printCommand = new PrintCommand();
    SleepCommand* sleepCommand = new SleepCommand();
    WhileCommand* whileCommand = new WhileCommand;
    IfCommand* ifCommand = new IfCommand();
	
	commands.insert({"openDataServer", openServerCommand1});
    commands.insert({"connectControlClient", connectCommand});
    commands.insert({"var", defineVarCommand});
    commands.insert({"Print", printCommand});
    commands.insert({"Sleep", sleepCommand});
    commands.insert({"while",whileCommand});
    commands.insert({"if", ifCommand});
	//commands["openDataServer"] = openServerCommand1;
	/*commands["connectControlClient"]=connectCommand;
	commands["var"]=defineVarCommand;
	commands["Print"] =printCommand ;
	commands["Sleep"] =sleepCommand;
	commands["while"]=whileCommand ;
	commands["if"]=ifCommand ;*/

}

Parser::Parser() {}