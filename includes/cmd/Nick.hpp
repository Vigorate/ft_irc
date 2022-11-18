/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:24:18 by amine             #+#    #+#             */
/*   Updated: 2022/11/15 17:38:28 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NICK_HPP
# define NICK_HPP

#include "../lib.hpp"
#include "../Command.hpp"

class Nick : public Command
{
	public:
		Nick();
		virtual ~Nick();

		std::string execute(std::string str, User *user, Server &server);

};

#endif