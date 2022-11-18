/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:10:58 by amine             #+#    #+#             */
/*   Updated: 2022/11/15 18:11:11 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cmd/Part.hpp"

Part::Part() { _cname = "PART"; }

Part::~Part() {}

std::string			Part::execute(std::string str, User *user, Server &server)
{
	std::cout << "In Part\n";
}