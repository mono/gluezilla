/*
 * PromptService.h: Custom prompt dialogs
 *
 * Author:
 *	Andreia Gaita  <avidigal@novell.com>
 *
 * Copyright 2007 Novell, Inc. (http://www.novell.com)
 *
 * See the LICENSE file included with the distribution for details.
 * 
 */

#ifndef _PROMPTSERVICE_H_
#define _PROMPTSERVICE_H_

#include "interfaces.h"
#include "BrowserWindow.h"
#define PROMPTSERVICE_CLASSNAME "Prompt Service"

// {77686174-2061-6d20-6920-746F20646F20}
#define PROMPTSERVICE_CID \
{ 0x77686174, 0x2061, 0x6d20, { 0x69, 0x20, 0x74, 0x6F, 0x20, 0x64, 0x6F, 0x20 } }


class PromptService : public nsIPromptService
{
	NS_DECL_ISUPPORTS
	NS_DECL_NSIPROMPTSERVICE

	PromptService ()
	{
	}

	PromptService (BrowserWindow * window);
	~PromptService() {}


private:
	BrowserWindow * browserWindow;

};

//*****************************************************************************
// PromptServiceFactory
//*****************************************************************************   

class PromptServiceFactory : public nsIFactory {
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFACTORY

  PromptServiceFactory ();
  PromptServiceFactory (BrowserWindow * window);
  virtual ~PromptServiceFactory();
  
private:
	BrowserWindow * browserWindow;
};

nsresult NS_NewPromptServiceFactory(nsIFactory** aFactory, BrowserWindow * window);

#endif
