/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:10:20 by amine             #+#    #+#             */
/*   Updated: 2022/11/15 18:10:31 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cmd/Nick.hpp"

Nick::Nick() { _cname = "NICK"; }

Nick::~Nick() {}

std::string			Nick::execute(std::string str, User *user, Server &server)
{
	std::cout << "In Nick\n";
}