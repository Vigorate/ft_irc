/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:52:57 by amine             #+#    #+#             */
/*   Updated: 2022/11/15 15:37:53 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Server.hpp"

Server::Server(): _socket()
{ 
	FD_ZERO(&_set);
}

Server::Server(Server const &src) { *this = src; }

Server::~Server() {}

Server	&Server::operator=(Server const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_socket = rhs._socket;
	return (*this);
}

bool			Server::isWordInArray(std::vector<std::string> warray, std::string word)
{
	std::vector<std::string>::iterator it = warray.begin();
	std::vector<std::string>::iterator ite = warray.end();

	for(; it != ite; it++)
	{
		if ((*it).find(word) != std::string::npos) 
				return true;
	}
	return false;
}

int				Server::_fdMax()
{
	std::vector<int>::iterator it = _fdtab.begin();
	std::vector<int>::iterator ite = _fdtab.end();
	int		i = _socket.getSfd();

	if (_fdtab.empty())
		return i;
	for (; it != ite; ++it)
		if (*it > i)
			i = *it;
	return i;
}

bool			Server::checkRequestFormatFull(std::vector<std::string> warray)
{
	if (this->isWordInArray(warray, "CAP")
		&& this->isWordInArray(warray, "NICK")
		&& this->isWordInArray(warray, "USER")
		&& this->isWordInArray(warray, "PASS"))
		return true;
	return false;
}

bool			Server::checkRequestFormatIncomp(std::vector<std::string> warray)
{
	if (this->isWordInArray(warray, "CAP")
		|| this->isWordInArray(warray, "NICK")
		|| this->isWordInArray(warray, "USER")
		|| this->isWordInArray(warray, "PASS"))
		return true;
	return false;
}


bool			Server::_checkPassword(std::vector<std::string> warray)
{
//	size_t pos = 0;
	std::vector<std::string>::iterator it = warray.begin();
	std::vector<std::string>::iterator ite = warray.end();

	for(; it != ite; it++){
		if ((*it).find("PASS") != std::string::npos) {
//			pos = (*it).find("PASS");
			std::string pswrd = (*it).substr(5);
			if (pswrd == _socket.getPswrd())
			{ return true; }
		}
	}
	return false;
}

void			Server::_disconnectClient(int fd)
{
	(void)fd;
}

void			Server::sendReply(std::string reply, User &user)
{
	if (send(user.getFd(), reply.c_str(), reply.length(), 0) < 0)
		_disconnectClient(user.getFd());
}

bool			Server::ifJoinServer(int fd)
{
	std::vector<User *>::iterator it = _users.begin();
	std::vector<User *>::iterator ite = _users.end();

	for(; it != ite; it++)
	{
		if ((*it)->getFd() == fd && (*it)->getJoin())
			return true;
	}
	return false;
}

bool			Server::_isNickAvailable(User *user, std::string nick)
{
	std::vector<User *>::iterator 	it = _users.begin();
	std::vector<User *>::iterator 	ite = _users.end();
	std::string						err = ":";

	for (; it != ite; ++it)
	{
		if ((*it)->getNickname() == nick)
		{
			err += ERR_NICKNAMEINUSE(nick);
			send(user->getFd(), err.c_str(), err.length(), 0);
			return false;
		}
	}
	return true;
}

void			Server::addUser(std::vector<std::string> warray, int fd)
{
	User								*user = NULL;
	std::vector<std::string>::iterator	it = warray.begin();
	std::vector<std::string>::iterator	ite = warray.end();
	std::vector<User *>::iterator		uit = _users.begin();
	std::vector<User *>::iterator		uite = _users.end();

	for (; uit != uite; ++uit)
	{
		if ((*uit)->getFd() == fd)
		{
			user = (*uit);
			break;
		}
	}

	std::string							nick;

	for (; it != ite; ++it)
		if ((*it).find("NICK") != std::string::npos)
			if (_isNickAvailable(user, (*it).substr(5)))
				user->setNickname(nick);
	for (it = warray.begin(); it != ite; ++it)
		if ((*it).find("USER") != std::string::npos)
		{
			std::string	tmp = (*it).substr(5);
			int			len = tmp.find(" ");
			user->setUsername(tmp.substr(0, len));
		}

	std::string							reply;

	if (user->getNickname() != "" && user->getUsername() != "")
	{
		user->setPartial(false);
		reply = user->getPrefix();
		reply += RPL_WELCOME(user->getNickname(), user->getUsername(), user->getHostname());
		reply += "\r\n";
		sendReply(reply, *user);
		user->setJoin(true);
	}
}

void			Server::_manageRequest(int const fd)
{
	bzero(_buff, BUFF_SIZE);
	std::cout << "Hereasdasd" << std::endl;
	if (recv(fd, _buff, BUFF_SIZE, 0) <= 0)
	{
		_disconnectClient(fd);
		return;
	}

	std::cout << "\n		CLIENT :\n" << _buff << std::endl;

	std::vector<std::string>	warray = str_to_warray(_buff, "\r\n");
	bool						cmd = true;
	bool						full = false;

	for (std::vector<std::string>::iterator itee = warray.begin(); itee != warray.end(); ++itee)
		std::cout << "Line : " << *itee << std::endl;

	if (checkRequestFormatFull(warray) && _checkPassword(warray) && !ifJoinServer(fd)) // Full user connect
	{
		addUser(warray, fd);
		cmd = false;
		full = true;
	}
	// Incomplete user connect
	if (cmd && ifJoinServer(fd))
	{
//		Invoker		inv;
		
	}
}

void			Server::_connectClient()
{
	int					c_fd;
	struct sockaddr_in 	c_addr;
	socklen_t			len = sizeof(c_addr);

	if ((c_fd = accept(_socket.getSfd(), (struct sockaddr *)&c_addr, &len)) < 0)
		printexit("accept failed", 1);
	if (fcntl(c_fd, F_SETFL, O_NONBLOCK) < 0)
		printexit("fcntl failed", 1);

	User	*user = new User(c_fd);
	
	user->setNickname("");
	user->setHostname(std::string(inet_ntoa(c_addr.sin_addr)));
	_users.push_back(user);
	_fdtab.push_back(c_fd);
	FD_SET(c_fd, &_set);
}

void			Server::initServer(const short &port, const std::string &pswrd)
{
	int		rval;

 	_socket.initSock(port, pswrd);
	FD_ZERO(&_set);
	FD_SET(_socket.getSfd(), &_set);
	
	while (1) // Add switch later
	{
		_rset = _set;
		if ((rval = select(_fdMax() + 1, &_rset, NULL, NULL, NULL)) < 0)
			continue;
		for (int fd = 0; fd <= _fdMax(); ++fd)
		{
			if (FD_ISSET(fd, &_rset))
			{
				if (fd == _socket.getSfd())
				{
					_connectClient();
					break;
				}
				else
				{
					_manageRequest(fd);
					continue;
				}
			}
		}
	}
}
