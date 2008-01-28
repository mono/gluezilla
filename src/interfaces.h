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
#include <widget/nsIBaseWindow.h>
#include <docshell/nsIWebNavigation.h>
#include <docshell/nsIDocShellTreeItem.h>
#include <nsIEmbeddingSiteWindow.h>
#include <webbrwsr/nsIEmbeddingSiteWindow2.h>

// for NS_APPSHELL_CID
#include <widget/nsWidgetsCID.h>
#include <widget/nsIAppShell.h>

// Events
#include <nsIDOMEvent.h>
#include <nsIDOMEventListener.h>
#include <nsIDOMEventTarget.h>
#include <nsIDOMWindow.h>
#include <dom/nsIDOMKeyEvent.h>
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
#include <xpcom/nsAppDirectoryServiceDefs.h>
#include "nsIProperties.h"

// psm initialization
#include "nsIX509CertDB.h"

// dom
#include "nsIDOMHTMLDocument.h"
#include "nsIDOMDocument.h"
#include <nsIURI.h>

// proxying objects between threads - another non-frozen interface :/
#include "xpcom/nsIProxyObjectManager.h"

/* XRE API */
//#include "xulapp/nsXULAppAPI.h" 

// Mozilla configuration to get compile settings
#include "mozilla-config.h"

#define NS_FROZENCALL
#define XRE_API(type, name, params) \
  typedef type (NS_FROZENCALL * name##Type) params; \
  extern name##Type name NS_HIDDEN;

XRE_API(nsresult,
	XRE_InitEmbedding, (nsILocalFile *aLibXULDirectory,
						nsILocalFile *aAppDirectory,
						nsIDirectoryServiceProvider *aAppDirProvider,
						nsStaticModuleInfo const *aStaticComponents,
						PRUint32 aStaticComponentCount))

XRE_API(void, XRE_TermEmbedding, ())

XRE_API(PRBool,
		GRE_GetCurrentProcessDirectory,
		(char* buffer))


#ifdef MOZ_WIDGET_GTK2
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
