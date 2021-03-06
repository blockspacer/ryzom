// Ryzom - MMORPG Framework <http://dev.ryzom.com/projects/ryzom/>
// Copyright (C) 2010  Winch Gate Property Limited
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.



#ifndef NL_VIEW_LINK_H
#define NL_VIEW_LINK_H

#include "view_text.h"

/**
 * class implementing a link view
 * \author Cyril 'Hulud' Corvazier
 * \author Nicolas Vizerie
 * \author Nevrax France
 * \date 2003
 */
class CViewLink : public CViewText
{
public:

	// Default constructor
	CViewLink (const TCtorParam &param);

	// The URI
	std::string		Link;

	std::string		LinkTitle;

	// Set the main group
	void	setHTMLView(class CGroupHTML *html);
	bool	getMouseOverShape(std::string &texName, uint8 &rot, NLMISC::CRGBA &col);

protected:

	// The main HTML group
	CGroupHTML		*HTML;
};


#endif // NL_VIEW_LINK_H

/* End of view_link.h */
