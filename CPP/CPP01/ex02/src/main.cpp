/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:53:43 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/02 15:06:02 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main (void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	ptr = &str;
	std::string&	ref = str;

	std::cout << &str << std::endl;
	std::cout << ptr << std::endl;
	std::cout << &ref << std::endl;

	std::cout << str << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
	return (0);
}

/*int	main (void)
{
// Une reference est constante, dereferencee et jamais nulle.
// On ne peut changer ce vers quoi elle fait reference.
// Cela permet d'etre sur qu'elle pointe vers quelque chose.
// En revanche on peut toujours changer la valeur contenue dans la variable.
	std::string		str = "HI THIS IS BRAIN";
	std::string*	ptr = &str;
	std::string&	ref = str;

	std::cout << "adresse de str (&str):  " << &str << std::endl;
	std::cout << "contenu de ptr (ptr):   " << ptr << std::endl;
	std::cout << "ref dereference (&ref): " << &ref << std::endl;

	std::cout << "contenu de str (str):   " << str << std::endl;
	std::cout << "ptr dereference (*ptr): " << *ptr << std::endl;
	std::cout << "contenu de ref (ref):   " << ref << std::endl;

	str = "BRAIN IS HUNGRY";

	std::cout << "adresse de str (&str):  " << &str << std::endl;
	std::cout << "contenu de ptr (ptr):   " << ptr << std::endl;
	std::cout << "ref dereference (&ref): " << &ref << std::endl;

	std::cout << "contenu de str (str):   " << str << std::endl;
	std::cout << "ptr dereference (*ptr): " << *ptr << std::endl;
	std::cout << "contenu de ref (ref):   " << ref << std::endl;
	return (0);
}*/