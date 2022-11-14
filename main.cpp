/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:41:48 by amine             #+#    #+#             */
/*   Updated: 2022/11/14 21:27:58 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.hpp"
#include "includes/Server.hpp"
#include "includes/Socket.hpp"

int		main(int ac, char **av)
{
	Server	serv;

	if (ac != 3)
		printexit("Argument must be port and password\n", 1);
	for (int i = 0; av[1][i]; ++i)
		if (av[1][i] > '9' || av[1][i] < '0')
			printexit("Port must be only numerical\n", 1);
	serv.initServer(atoi(av[1]), av[2]);
}