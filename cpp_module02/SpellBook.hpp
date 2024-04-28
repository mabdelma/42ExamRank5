/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:05:02 by mabdelma          #+#    #+#             */
/*   Updated: 2024/04/28 20:05:04 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ASpell.hpp"
#include <map>

class SpellBook
{
	private :
		SpellBook(SpellBook const & src);
		SpellBook & operator=(SpellBook const & src);
		std::map < std::string, ASpell*> _SpellBook;
	public :
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell*);
		void forgetSpell(std::string const &);
		ASpell* createSpell(std::string const &);
};