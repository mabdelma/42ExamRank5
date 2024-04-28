/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:05:07 by mabdelma          #+#    #+#             */
/*   Updated: 2024/04/28 20:05:08 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook(SpellBook const & src)
{
	*this = src;
}

SpellBook & SpellBook::operator=(SpellBook const & src)
{
	_SpellBook = src._SpellBook;
	return (*this);
}

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it) {
		delete it->second;
	}
	_SpellBook.clear();
}

void SpellBook::learnSpell(ASpell* spell)
{
	if (spell)
	{
		_SpellBook[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(std::string const & SpellName)
{
	std::map<std::string, ASpell*>::iterator it = _SpellBook.find(SpellName);
	if (it != _SpellBook.end())
	{
		delete it->second;
		_SpellBook.erase(it);
	}
}

ASpell* SpellBook::createSpell(std::string const &SpellName)
{
	ASpell* tmp = NULL;
	if (_SpellBook.find(SpellName) != _SpellBook.end())
		tmp = _SpellBook[SpellName];
	return (tmp);
}