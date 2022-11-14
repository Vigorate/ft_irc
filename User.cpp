/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:02:48 by amine             #+#    #+#             */
/*   Updated: 2022/11/14 21:40:56 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/User.hpp"

User::User(int fd): _fd(fd), _partial(false) {}

User		&User::operator=(User const &src)
{
	if (this == &src)
		return *this;
	this->_fd = src._fd;
	this->_nick = src._nick;
	this->_nhost = src._nhost;
	this->_nuser = src._nuser;
	return *this;
}

User::User(User const &src) { *this = src; }

User::~User() {}

void				User::setJoin(bool join) { _join = join; } // To change
void				User::setPartial(bool partial) { _partial = partial; } // To change
void				User::setFd(int fd) { _fd = fd; }
void				User::setNickname(std::string nick) { _nick = nick; }
void				User::setUsername(std::string nuser) { _nuser = nuser; }
void				User::setHostname(std::string nhost) { _nhost = nhost; }

bool				User::getJoin() { return _join; } // To change
bool				User::getPartial() { return _partial; } // To change
int const			&User::getFd() { return _fd; }
std::string const 	&User::getNickname() { return _nick; }
std::string const 	&User::getUsername() { return _nuser; }
std::string const 	&User::getHostname() { return _nhost; }

std::string			User::getPrefix()
{
	std::string		prefix;

	prefix += ":";
	prefix += _nick;
	prefix += "!";
	prefix += _nuser;
	prefix += "@";
	prefix += _nhost;
	return prefix;
}