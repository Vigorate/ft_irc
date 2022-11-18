/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:11:17 by amine             #+#    #+#             */
/*   Updated: 2022/11/15 18:11:36 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cmd/Ping.hpp"

Ping::Ping() { _cname = "PING"; }

Ping::~Ping() {}

std::string			Ping::execute(std::string str, User *user, Server &server)
{
	std::cout << "In Ping\n";
}