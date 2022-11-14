/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:55:32 by amine             #+#    #+#             */
/*   Updated: 2022/11/14 21:34:35 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
# define USER_HPP

#include "lib.hpp"

class User
{
	//	Constructor
	public:
		User(int fd);
		User(User const &src);
		User &operator=(User const &src);
		
	//	Destructor
		~User();

	//	GS
	void				setFd(int);
	void				setNickname(std::string);
	void				setUsername(std::string);
	void				setHostname(std::string);
	void				setPartial(bool);
	void				setJoin(bool);
	
	int const			&getFd();
	std::string const	&getNickname();
	std::string const	&getUsername();
	std::string const	&getHostname();
	bool				getJoin(); // To change
	bool				getPartial();
	std::string			getPrefix();

	//	Members

	protected:
	//	Variables
		int				_fd;
		std::string		_nick;
		std::string		_nuser;
		std::string		_nhost;
		std::string		_pswrd;
		bool			_join; // To change
		bool			_partial; // To change
};

#endif