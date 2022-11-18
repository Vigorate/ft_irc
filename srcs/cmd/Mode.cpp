/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:09:58 by amine             #+#    #+#             */
/*   Updated: 2022/11/15 18:10:12 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cmd/Mode.hpp"

Mode::Mode() { _cname = "MODE"; }

Mode::~Mode() {}

std::string			Mode::execute(std::string str, User *user, Server &server)
{
	std::cout << "In Mode\n";
}