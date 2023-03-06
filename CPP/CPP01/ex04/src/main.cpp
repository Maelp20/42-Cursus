/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:06:06 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 12:32:08 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>

std::string	ft_replace(std::string buffer, std::string s1, std::string s2)
{
	std::size_t	pos = 0;
	std::size_t s1_size = s1.size();
	std::size_t s2_size = s2.size();

	pos = buffer.find(s1, pos);
	while (pos != std::string::npos)
	{
		buffer.erase(pos, s1_size);
		buffer.insert(pos, s2);
		pos += s2_size;
		pos = buffer.find(s1, pos);
	}
	return (buffer);
}

int	my_sed(std::string filename, std::string s1, std::string s2)
{
	std::ifstream		infile;
	std::ofstream		outfile;
	std::string			outfile_name = filename + ".replace";
	std::stringstream	buffer;

	infile.open(filename.c_str());
	outfile.open(outfile_name.c_str(), std::ios_base::out);
	if (infile.fail())
		return (std::cout << "Failed opening " << filename << std::endl, 1);
	if (outfile.fail())
	{
		std::cout << "File " << filename;
		std::cout << ".replace already exists but doesn't have write rights" << std::endl;
		return (1);
	}
	buffer << infile.rdbuf();
	outfile.copyfmt(infile);
	outfile << ft_replace(buffer.str(), s1, s2);
	infile.close();
	outfile.close();
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "Arguments needed: filename, s1, s2" << std::endl, 1);
	if (!av[1][0])
		return (std::cout << "Filename is empty" << std::endl, 1);
	if (!av[2][0])
		return (std::cout << "String to replace is empty" << std::endl, 1);
	my_sed(av[1], av[2], av[3]);
}