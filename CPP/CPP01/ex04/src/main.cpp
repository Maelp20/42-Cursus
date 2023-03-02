/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:06:06 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/02 18:36:32 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	operate_sed(std::string buffer, std::string oldstr, std::string newstr)
{
	(void)oldstr;
	(void)newstr;
	(void)buffer;
}

int	my_sed(std::string filename, std::string s1, std::string s2)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		outfile_name = filename + ".replace";
	std::string		buffer;

	infile.open(filename.c_str());
	if (infile.fail())
		return (std::cout << "Failed opening " << filename << std::endl, 1);
	infile >> buffer;
	std::cout << buffer << std::endl;
	outfile.open(outfile_name.c_str(), std::ios_base::out);
	outfile.copyfmt(infile);
	operate_sed(buffer, s1, s2);
	outfile << buffer;
	infile.close();
	outfile.close();
	return (0);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	my_sed("./test", "lol", "hey");
}