/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Notice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:10:38 by amine             #+#    #+#             */
/*   Updated: 2022/11/15 18:10:50 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cmd/Notice.hpp"

Notice::Notice() { _cname = "NOTICE"; }

Notice::~Notice() {}

std::string			Notice::execute(std::string str, User *user, Server &server)
{
	std::cout << "In Notice\n";
}