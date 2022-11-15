/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Invoker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:38:11 by amine             #+#    #+#             */
/*   Updated: 2022/11/15 00:47:35 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Invoker.hpp"
#include "includes/Server.hpp"

Invoker::Invoker()
{
	_cmds.push_back(new Ping());
	_cmds.push_back(new Nick());
	_cmds.push_back(new Part());
	_cmds.push_back(new Join());
	_cmds.push_back(new Notice());
	_cmds.push_back(new Privmsg()); 
	_cmds.push_back(new Kick());
	_cmds.push_back(new Quit());
	_cmds.push_back(new Invite());
	_cmds.push_back(new Mode());	
}

Invoker::~Invoker()
{
	std::vector<Command *>::iterator it = _cmds.begin();
	std::vector<Command *>::iterator ite = _cmds.end();

	for (; it != ite; ++it)
		delete *it;
}

std::string			Invoker::parser(std::vector<std::string> buff, User *user, Server &server)
{
	std::vector<std::string>::iterator	it = buff.begin();
	std::vector<std::string>::iterator	ite = buff.end();
	std::vector<std::string>			cmd;
	std::string							reply;
	for (; it != ite; ++it)
	{
		cmd = str_to_warray(*it, " ");
		for (std::vector<Command *>::iterator i = _cmds.begin(); i != _cmds.end(); ++i)
		{
			if (cmd[0] == (*i)->getName())
			{
				reply = ((*i)->execute(*it, user, server));
				return reply;
			}
		}
	}
	return reply;
}