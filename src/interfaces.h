#ifndef _INTERFACES_H_
#define _INTERFACES_H_

//Gecko Embedding API
#include <nsEmbedAPI.h>

//XPCOM API
#include <nsCOMPtr.h>
#include <nsIComponentManager.h>
#include <nsComponentManagerUtils.h>
#include <nsEmbedCID.h>

//XPCOMGlue API
#include <nsXPCOMGlue.h>

//MozillaString API
#include <nsEmbedString.h>

//WebBrowser
#include <nsIWebBrowser.h>
#include <nsIWebBrowserChrome.h>
#include <nsIWebBrowserFocus.h>
#include <nsIWebBrowserChromeFocus.h>

#if XUL_VERSION > 2
#include <nsIBaseWindow.h>
#include <nsIWebNavigation.h>
#include <nsIDocShellTreeItem.h>
#include <nsIEmbeddingSiteWindow2.h>
#else
#include <widget/nsIBaseWindow.h>
#include <docshell/nsIWebNavigation.h>
#include <docshell/nsIDocShellTreeItem.h>
#include <webbrwsr/nsIEmbeddingSiteWindow2.h>
#endif

#include <nsIEmbeddingSiteWindow.h>
#include <nsIContextMenuListener.h>

// for NS_APPSHELL_CID
#if XUL_VERSION > 2
#include <nsWidgetsCID.h>
#include <nsIAppShell.h>
#else
#include <widget/nsWidgetsCID.h>
#include <widget/nsIAppShell.h>
#endif

// Events
#include <nsIDOMEvent.h>
#include <nsIDOMEventListener.h>
#include <nsIDOMEventTarget.h>
#include <nsIDOMWindow.h>
#if XUL_VERSION > 2
#include <nsIDOMKeyEvent.h>
#else
#include <dom/nsIDOMKeyEvent.h>
#endif
#include <nsIDOMMouseEvent.h>
#include <nsIWebProgress.h>
#include <nsIWebProgressListener.h>
#include <nsIURIContentListener.h>

#include <nsIInterfaceRequestor.h>

#include <nsIWeakReference.h>
#include <nsWeakReference.h>
#include <nsIWeakReferenceUtils.h>

#include <nsISHistory.h>
#include <nsIWindowCreator.h>
#include <nsIWindowWatcher.h>

#include <nsServiceManagerUtils.h>

#include <nsIPromptService.h>
#include <nsISecurityWarningDialogs.h>
#include <nsIComponentRegistrar.h>
#include <nsIGenericFactory.h>

// preferences
#include <nsIPrefBranch.h>
#include <nsIPrefService.h>

// for getting the native mozilla drawing handle
//#include <widget/nsIWidget.h>

// Directory service provider definitions (LocationProvider)
#include "nsDirectoryServiceDefs.h"
#if XUL_VERSION > 2
#include <nsAppDirectoryServiceDefs.h>
#else
#include <xpcom/nsAppDirectoryServiceDefs.h>
#endif
#include "nsIProperties.h"

// psm initialization
#include "nsIX509CertDB.h"

// dom
#include "nsIDOMHTMLDocument.h"
#include "nsIDOMDocument.h"
#include <nsIURI.h>

// proxying objects between threads - another non-frozen interface :/
#if XUL_VERSION > 2
#include "nsIProxyObjectManager.h"
#else
#include "xpcom/nsIProxyObjectManager.h"
#endif


// Mozilla configuration to get compile settings
//#include "mozilla-config.h"

#include <nsIInterfaceRequestorUtils.h>
#if XUL_VERSION > 2
#include "nsIScriptGlobalObjectOwner.h"
#include "nsIScriptGlobalObject.h"
#include "nsIScriptContext.h"
#else
#include "dom/nsIScriptGlobalObjectOwner.h"
#include "gluezilla_nsIScriptGlobalObject.h"
#include "gluezilla_nsIScriptContext.h"
#endif

#define NS_FROZENCALL

#ifdef NS_UNIX
#include <gtk/gtk.h>
#include <gtk/gtkwindow.h>
#include <gdk/gdkx.h>

	#ifdef DEBUG
		#define PRINT(str)	\
			g_print(str)
		#define PRINT2(str, str1)	\
			g_print(str, str1)
		#define PRINT3(str, str1, str2)	\
			g_print(str, str1, str2)
	#else
		#define PRINT(str)
		#define PRINT2(str, str1)
		#define PRINT3(str, str1, str2)
	#endif
#else //TODO: define these for non-unix
	#define PRINT(str)
	#define PRINT2(str, str1)
	#define PRINT3(str, str1, str2)
#endif

#endif
