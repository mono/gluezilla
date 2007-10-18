/*
 * LocationProvider.h: file location provider
 *
 * Author:
 *	Andreia Gaita  <avidigal@novell.com>
 *
 * Copyright 2007 Novell, Inc. (http://www.novell.com)
 *
 * See the LICENSE file included with the distribution for details.
 * 
 */

#ifndef _LOCATIONPROVIDER_H_
#define _LOCATIONPROVIDER_H_

#include "interfaces.h"
#include "Widget.h"
class Widget;

class LocationProvider : public nsIDirectoryServiceProvider
{
public:
	NS_DECL_ISUPPORTS
	NS_DECL_NSIDIRECTORYSERVICEPROVIDER

	LocationProvider (Widget * widget);
	~LocationProvider ();
private:
	Widget * widget;

protected:
	/* additional members */

};

#endif
