/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:10:58 by amine             #+#    #+#             */
/*   Updated: 2022/11/21 18:12:27 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cmd/Part.hpp"

Part::Part() { _cname = "PART"; }

Part::~Part() {}

std::string						Part::execute(std::string str, User *user, Server &server)
{
	std::vector<std::string>	cmd = str_to_warray(str, " ");
	std::vector<User *>			users;
	std::string					reply;
	std::string					chan;

	if (cmd.size() < 2)
		return reply + "PART: Must indicate channel to part from\r\n";
	chan = cmd[1];
	reply = user->getPrefix() + " " + str + " " + ":" + user->getNickname() + "\r\n";
	users = server.getChannelUsers(chan);
	for (std::vector<User *>::iterator it = users.begin(); it != users.end(); ++it)
		if (send((*it)->getFd(), reply.c_str(), reply.length(), 0) < 0)
		{
			std::cout << "[Send response failed]" << std::endl;
			server.disconnectClient((*it)->getFd());
			return NULL;
		}
	server.getChannel(chan)->rmvUser(user);
	return reply;
}
