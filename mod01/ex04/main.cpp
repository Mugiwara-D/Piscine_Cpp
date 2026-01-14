/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:18:55 by maderuel          #+#    #+#             */
/*   Updated: 2024/02/27 17:10:51 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	find_and_replace(std::string &line, std::string target, std::string replace)
{
	int	pos;

	pos = line.find(target);
	line.erase(pos, target.length());
	line.insert(pos, replace);
}

int	main(int ac, char **av)
{
	std::string	line;
	std::string outfileName;
	std::ifstream	infile;
	std::ofstream	outfile;
	size_t	pos;

	if (ac != 4)
	{
		std::cout << "bad number of argument" << std::endl;
		return (1);
	}

	infile.open(av[1]);
	if (!infile)
	{
		std::cout << "infile error" << std::endl;
		return 2;
	}
	outfileName = av[1];
	outfileName.append(".replace");
	outfile.open(outfileName.c_str());
	if (!outfile)
	{
		std::cout << "outfile error" << std::endl;
		return 3;
	}
	while (std::getline(infile, line))
	{
		pos = line.find(av[2]);
		while (pos != std::string::npos)
		{
			find_and_replace(line, av[2], av[3]);
			pos = line.find(av[2]);
		}
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}
