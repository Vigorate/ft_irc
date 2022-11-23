/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Invite.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:21:18 by amine             #+#    #+#             */
/*   Updated: 2022/11/23 15:20:22 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVITE_HPP
# define INVITE_HPP

#include "../lib.hpp"
#include "../Command.hpp"

class Invite : public Command
{
	public:
		Invite();
		virtual ~Invite();

		std::string		execute(std::string str, User *user, Server &server);

	private:
		bool			checkNick(std::string nick, Server &server);
		bool			checkUserChannel(Channel *chan, std::string name);
		int				getFdName(std::string nick, Server &server);

};

#endif