/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:09:33 by amine             #+#    #+#             */
/*   Updated: 2022/11/15 18:09:51 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cmd/Kick.hpp"

Kick::Kick() { _cname = "KICK"; }

Kick::~Kick() {}

std::string			Kick::execute(std::string str, User *user, Server &server)
{
	std::cout << "In Kick\n";
}