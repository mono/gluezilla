/*
 * SecurityWarningsDialogs.h: Custom security warning dialogs
 *
 * Author:
 *	Andreia Gaita  <avidigal@novell.com>
 *
 * Copyright 2007 Novell, Inc. (http://www.novell.com)
 *
 * See the LICENSE file included with the distribution for details.
 * 
 */

#ifndef _SECURITYWARNINGSDIALOGS_H_
#define _SECURITYWARNINGSDIALOGS_H_

#include "interfaces.h"

#define SECURITYWARNINGSDIALOGS_CLASSNAME "Security Warning Dialogs"


// {696E7465-7265-7374-696E-67206C696665}
#define SECURITYWARNINGSDIALOGS_CID \
{ 0x696E7465, 0x7265, 0x7374, { 0x69, 0x6E, 0x67, 0x20, 0x6C, 0x69, 0x66, 0x65 } }

static NS_DEFINE_CID(kSECURITYWARNINGSDIALOGS_CID, SECURITYWARNINGSDIALOGS_CID);

class SecurityWarningDialogs : public nsISecurityWarningDialogs
{
public:
	NS_DECL_ISUPPORTS
	NS_DECL_NSISECURITYWARNINGDIALOGS
	
	SecurityWarningDialogs() {};
	virtual ~SecurityWarningDialogs() {};	
protected:
};


//*****************************************************************************
// SecurityWarningServiceFactory
//*****************************************************************************   

class SecurityWarningServiceFactory : public nsIFactory {
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFACTORY

  SecurityWarningServiceFactory();
  virtual ~SecurityWarningServiceFactory();
  
};

nsresult NS_NewSecurityWarningServiceFactory(nsIFactory** aFactory);

#endif
