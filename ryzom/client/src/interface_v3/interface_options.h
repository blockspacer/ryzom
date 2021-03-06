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



#ifndef RZ_INTERFACE_LAYER_H
#define RZ_INTERFACE_LAYER_H

#include "nel/misc/smart_ptr.h"


namespace NL3D
{
class UAnimationSet;
}


// ***************************************************************************
class CInterfaceOptionValue
{
public:
	CInterfaceOptionValue()
	{
		_Color= NLMISC::CRGBA::White;
		_Int= 0;
		_Float= 0;
		_Boolean= false;
	}

	const std::string		&getValStr	() const {return _Str;}
	sint32					getValSInt32() const {return _Int;}
	float					getValFloat	() const {return _Float;}
	NLMISC::CRGBA			getValColor	() const {return _Color;}
	bool					getValBool	() const {return _Boolean;}

	void					init(const std::string &str);

	// returned when InterfaceOptions param not found
	static const CInterfaceOptionValue	NullValue;

private:

	std::string		_Str;
	NLMISC::CRGBA	_Color;
	sint32			_Int;
	float			_Float;
	bool			_Boolean;
};


// ***************************************************************************
class CInterfaceOptions : public NLMISC::CRefCount
{

public:

	CInterfaceOptions();
	virtual ~CInterfaceOptions();

	virtual bool parse (xmlNodePtr cur);

	// return NullValue if param not found
	const CInterfaceOptionValue		&getValue(const std::string &sParamName) const;

	// shortcuts to getValue(paramName).getValXXX()
	const std::string		&getValStr		(const std::string &sParamName) const;
	sint32					getValSInt32	(const std::string &sParamName) const;
	float					getValFloat		(const std::string &sParamName) const;
	NLMISC::CRGBA			getValColor		(const std::string &sParamName) const;
	bool					getValBool		(const std::string &sParamName) const;

	// copy basic map only from other CInterfaceOptions (non virtual method)
	void	copyBasicMap(const CInterfaceOptions &other);

protected:

	std::map<std::string, CInterfaceOptionValue> _ParamValue;

};


// ***************************************************************************
class COptionsLayer : public CInterfaceOptions
{

public:
	COptionsLayer();
	~COptionsLayer();
	virtual bool parse (xmlNodePtr cur);

	// Container optimizer

	sint32 Tile_Blank;
	sint32 Tile_M_Header, Tile_M_Scrollbar;
	sint32 Tile_T, Tile_B, Tile_L, Tile_R;
	sint32 Tile_B_Open, Tile_EM_Open, Tile_M_Open;

	sint32 Scrollbar_Offset_X;
	sint32 Scrollbar_W;
	sint32 TxId_B_Scrollbar, W_B_Scrollbar, H_B_Scrollbar;
	sint32 TxId_M_Scrollbar, W_M_Scrollbar, H_M_Scrollbar;
	sint32 TxId_T_Scrollbar, W_T_Scrollbar, H_T_Scrollbar;

	sint32 TxId_L_Header, W_L_Header, H_L_Header;
	sint32 TxId_M_Header, W_M_Header, H_M_Header;
	sint32 TxId_R_Header, W_R_Header, H_R_Header;

	sint32 TxId_TL,		W_TL, H_TL;
	sint32 TxId_T,		W_T,  H_T;
	sint32 TxId_TR,		W_TR, H_TR;
	sint32 TxId_L,		W_L,  H_L;
	sint32 TxId_R,		W_R,  H_R;
	sint32 TxId_Blank,	W_Blank, H_Blank;
	sint32 TxId_BL,		W_BL, H_BL;
	sint32 TxId_B,		W_B,  H_B;
	sint32 TxId_BR,		W_BR, H_BR;

	sint32 TxId_BL_Open, W_BL_Open, H_BL_Open;
	sint32 TxId_B_Open,  W_B_Open,  H_B_Open;
	sint32 TxId_BR_Open, W_BR_Open, H_BR_Open;
	sint32 TxId_EL_Open, W_EL_Open, H_EL_Open;
	sint32 TxId_EM_Open, W_EM_Open, H_EM_Open;
	sint32 TxId_ER_Open, W_ER_Open, H_ER_Open;
	sint32 TxId_E_Open,	 W_E_Open,  H_E_Open;
	sint32 TxId_M_Open,	 W_M_Open,  H_M_Open;

	sint32 TxId_TL_HighLight;
	sint32 TxId_T_HighLight;
	sint32 TxId_TR_HighLight;
	sint32 TxId_L_HighLight;
	sint32 TxId_R_HighLight;
	sint32 TxId_BL_HighLight;
	sint32 TxId_B_HighLight;
	sint32 TxId_BR_HighLight;

	sint32	HeaderH;
};

// ***************************************************************************
class COptionsContainerInsertion : public CInterfaceOptions
{
public:
	COptionsContainerInsertion();
	virtual bool parse (xmlNodePtr cur);

	sint32 TxId_R_Arrow;
	sint32 TxId_L_Arrow;
	sint32 TxId_T_Arrow;
	sint32 TxId_B_Arrow;
	sint32 TxId_InsertionBar;
};

// ***************************************************************************
class COptionsContainerMove : public CInterfaceOptions
{
public:
	COptionsContainerMove();
	virtual bool parse (xmlNodePtr cur);

	sint32 TrackW;
	sint32 TrackH;
	sint32 TrackY;
	sint32 TrackYWithTopResizer;
	sint32 TrackHWithTopResizer;
	sint32 ResizerSize;
};



// ***************************************************************************
/**
 *	read a list of <param> with no name. id auto incremented
 */
class COptionsList : public CInterfaceOptions
{
public:
	COptionsList();
	virtual bool parse (xmlNodePtr cur);

	uint	getNumParams() const {return _NumParams;}

	// get a value by its index (from 0 to numParams)
	const CInterfaceOptionValue		&getValue(uint paramId) const;

private:
	uint		_NumParams;
};

// ***************************************************************************
class CMissionIconList : public CInterfaceOptions
{
public:
	virtual bool parse (xmlNodePtr cur);
	sint32 getBackTexID(uint index) const { return index >= IconBackTexID.size() ? -1 : IconBackTexID[index]; }
	sint32 getTexID(uint index) const { return index >= IconTexID.size() ? -1 : IconTexID[index]; }
private:
	std::vector<sint32> IconBackTexID;
	std::vector<sint32> IconTexID;
};

// ***************************************************************************
/** Describe an animation Set container, used for multiple CCharacter3d for instance
 */
class COptionsAnimationSet : public CInterfaceOptions
{
public:
	COptionsAnimationSet();
	// see code for important release note
	virtual ~COptionsAnimationSet();
	virtual bool parse (xmlNodePtr cur);

	// tool fct to get the face anim name from a name (append "_face" before .anim)
	static std::string	getFaceAnimName(const std::string &animName);

public:
	NL3D::UAnimationSet		*AnimationSet;

	struct	CAnim
	{
		// Indexes in this animation set
		uint		AnimId;
		// true if must apply the race/gender scale to the position (not in rare case)
		bool		ApplyRaceScalePos;
		CAnim()
		{
			AnimId= -1;
			ApplyRaceScalePos= true;
		}
	};

	// Male and female Animation
	std::vector<CAnim>		AnimMale;
	std::vector<CAnim>		AnimFemale;

};

#endif // NL_INTERFACE_LAYER_H

/* End of interface_layer.h */


