/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Invite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:09:07 by amine             #+#    #+#             */
/*   Updated: 2022/11/15 18:09:24 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cmd/Invite.hpp"

Invite::Invite() { _cname = "INVITE"; }

Invite::~Invite() {}

std::string			Invite::execute(std::string str, User *user, Server &server)
{
	std::cout << "In Invite\n";
}