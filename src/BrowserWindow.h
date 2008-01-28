/* BrowserWindow.h: The browser window class
 *
 * Author:
 *	Andreia Gaita  <avidigal@novell.com>
 *
 * Copyright 2007 Novell, Inc. (http://www.novell.com)
 *
 * See the LICENSE file included with the distribution for details.
 * 
 */


#ifndef _BROWSERWINDOW_H_
#define _BROWSERWINDOW_H_

#include "Widget.h"
#include "EventListener.h"
#include <map>

class Widget;
class EventListener;

class BrowserWindow :	
	public nsIInterfaceRequestor,
	public nsIWebBrowserChrome,
	public nsIWebBrowserChromeFocus,
	public nsIWebProgressListener,
	public nsIURIContentListener,
	public nsSupportsWeakReference,
	public nsIWindowCreator,
//	public nsIEmbeddingSiteWindow,
	public nsIEmbeddingSiteWindow2
{

 public:

	BrowserWindow();

	~BrowserWindow ()
	{
	}


	NS_DECL_ISUPPORTS
	NS_DECL_NSIINTERFACEREQUESTOR
	NS_DECL_NSIWEBBROWSERCHROME
	NS_DECL_NSIWEBBROWSERCHROMEFOCUS
	NS_DECL_NSIWEBPROGRESSLISTENER
	NS_DECL_NSIURICONTENTLISTENER
	NS_DECL_NSIWINDOWCREATOR
	NS_DECL_NSIEMBEDDINGSITEWINDOW
	NS_DECL_NSIEMBEDDINGSITEWINDOW2


	// initialization
	nsresult Create ( Handle * hwnd, PRInt32 width, PRInt32 height);
	nsresult RegisterComponents ();

	// Navigation
	nsresult Navigate (nsString uri);
	nsresult Navigate ();
	nsresult Forward ();
	nsresult Back ();
	nsresult Home ();
	nsresult Stop ();
	nsresult Reload (ReloadOption option);
	
	// layout
	nsresult Focus ();
	nsresult Show ();
	nsresult Resize (PRUint32 width, PRUint32 height);

	// getters / setters
	Handle * getNativeWin () { return this->nativeMozWidget;}

	void setParent (Widget* owner) { this->owner = owner; };
	Widget * getParent () { return this->owner; };

	void setUri (nsString uri) { this->uri = uri; };
	nsString getUri () { return this->uri; };

	nsCOMPtr<nsIWebNavigation> getWebNavigation () { return this->webNav; }
	
	nsresult AttachEvent (nsIDOMEventTarget * target, const char * type, const char * name);
	nsresult DettachEvent (const char * type, const char * name);

	Widget * owner;
	nsCOMPtr<nsIWebBrowser> 	webBrowser;
private:
	
	nsCOMPtr<nsIBaseWindow> 	baseWindow;
	nsCOMPtr<nsIWebNavigation> 	webNav;
	nsCOMPtr<nsISHistory>		sessionHistory;
	nsIPromptService * promptService;

	nsString uri;
	char * statusText;
	PRBool isChrome;
	PRBool isLoaded;
	PRBool isFocused;

	Handle * nativeMozWidget;
	
	std::map<const char*, EventListener *> listeners;
};
  

#endif /* __BrowserWindow_h */
