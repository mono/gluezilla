/* gluezilla.h: external interface and helpers
 *
 * Author:
 *	Andreia Gaita  <avidigal@novell.com>
 *
 * Copyright 2007 Novell, Inc. (http://www.novell.com)
 *
 * See the LICENSE file included with the distribution for details.
 * 
 */

#ifndef _XULEMBED_H_
#define _XULEMBED_H_

#include "interfaces.h"

#ifdef NS_WIN32
#define NS_EXPORT_(type) __declspec(dllexport) type __stdcall
#define STDCALL __stdcall
#else
#define STDCALL 
#endif

#ifdef __cplusplus
extern "C"
{
#endif

	typedef void * Handle;

	typedef enum
	{
		RELOAD_NONE = 0,
		RELOAD_PROXY = 1,
		RELOAD_FULL = 2
	} ReloadOption;

	typedef enum 
	{
		FOCUS_NONE = 0,
		FOCUS_FIRST = 1,
		FOCUS_LAST = 2
	} FocusOption;

	typedef enum
	{
		EMBED_FLAG_START = 1,
		EMBED_FLAG_REDIRECTING = 2,
		EMBED_FLAG_TRANSFERRING = 4,
		EMBED_FLAG_NEGOTIATING = 8,
		EMBED_FLAG_STOP = 16,
		EMBED_FLAG_IS_REQUEST = 65536,
		EMBED_FLAG_IS_DOCUMENT = 131072,
		EMBED_FLAG_IS_NETWORK = 262144,
		EMBED_FLAG_IS_WINDOW = 524288,
		EMBED_FLAG_RESTORING = 16777216
	} EmbedProgressFlags;

	typedef struct _SizeInfo
	{
		PRUint32 width;
		PRUint32 height;
	} SizeInfo;

	typedef struct _ModifierKeys
	{
		PRBool altKey;
		PRBool ctrlKey;
		PRBool metaKey;
		PRBool shiftKey;
	} ModifierKeys;

	typedef struct _MouseInfo
	{
		PRUint16 button;
		PRInt32 clientX;
		PRInt32 clientY;
		PRInt32 screenX;
		PRInt32 screenY;
	} MouseInfo;

	typedef struct _KeyInfo
	{
		PRUint32 charCode;
		PRUint32 keyCode;
	} KeyInfo;

	typedef enum
	{
		BUTTON_POS_0  	= 1,
		BUTTON_POS_1 	= 256,
		BUTTON_POS_2 	= 65536,
		BUTTON_TITLE_OK 	= 1,
		BUTTON_TITLE_CANCEL 	= 2,
		BUTTON_TITLE_YES 	= 3,
		BUTTON_TITLE_NO 	= 4,
		BUTTON_TITLE_SAVE 	= 5,
		BUTTON_TITLE_DONT_SAVE 	= 6,
		BUTTON_TITLE_REVERT 	= 7,
		BUTTON_TITLE_IS_STRING 	= 127,
		BUTTON_POS_0_DEFAULT 	= 0,
		BUTTON_POS_1_DEFAULT 	= 16777216,
		BUTTON_POS_2_DEFAULT 	= 33554432,
		BUTTON_DELAY_ENABLE 	= 67108864,
		STD_OK_CANCEL_BUTTONS 	= 513
	} DialogButtonFlags;

	typedef enum
	{
		Winforms = 1,
		Gtk = 2
	} Platform;

	typedef struct _CallbackBin
	{
		void (STDCALL *OnWidgetLoaded)		();

		void (STDCALL *OnStateChange)		(PRInt32 status, PRUint32 stateFlags);
		
		void (STDCALL *OnProgress)			(PRInt32 curTotalProgress, PRInt32 maxTotalProgress);
		void (STDCALL *OnLocationChanged)	(const char * url);
		void (STDCALL *OnStatusChange)		(const PRUnichar *message, PRInt32 status);
	    
		//return true to abort/consume
		PRBool (STDCALL *OnDomKeyDown)		(KeyInfo keyInfo, ModifierKeys modifiers, nsIDOMNode * node);
		PRBool (STDCALL *OnDomKeyUp)		(KeyInfo keyInfo, ModifierKeys modifiers, nsIDOMNode * node);
		PRBool (STDCALL *OnDomKeyPress)		(KeyInfo keyInfo, ModifierKeys modifiers, nsIDOMNode * node);
		
		PRBool (STDCALL *OnMouseDown)		(MouseInfo mouseInfo, ModifierKeys modifiers, nsIDOMNode * node);
		PRBool (STDCALL *OnMouseUp)			(MouseInfo mouseInfo, ModifierKeys modifiers, nsIDOMNode * node);
		PRBool (STDCALL *OnMouseClick)		(MouseInfo mouseInfo, ModifierKeys modifiers, nsIDOMNode * node);
		PRBool (STDCALL *OnMouseDoubleClick)(MouseInfo mouseInfo, ModifierKeys modifiers, nsIDOMNode * node);
		PRBool (STDCALL *OnMouseOver)		(MouseInfo mouseInfo, ModifierKeys modifiers, nsIDOMNode * node);
		PRBool (STDCALL *OnMouseOut)		(MouseInfo mouseInfo, ModifierKeys modifiers, nsIDOMNode * node);

		PRBool (STDCALL *OnActivate)		(void);
		PRBool (STDCALL *OnFocus)			(void);
		PRBool (STDCALL *OnBlur)		(void);

		void (STDCALL *OnAlert)				(const PRUnichar * title, const PRUnichar * text);
		PRBool (STDCALL *OnAlertCheck)		(const PRUnichar * title, const PRUnichar * text, const PRUnichar * chkMsg, PRBool * chkState);
		PRBool (STDCALL *OnConfirm)			(const PRUnichar * title, const PRUnichar * text);
		PRBool (STDCALL *OnConfirmCheck)	(const PRUnichar * title, const PRUnichar * text, const PRUnichar * chkMsg, PRBool * chkState);

		PRBool (STDCALL *OnConfirmEx)		(const PRUnichar * title, const PRUnichar * text, DialogButtonFlags flags, 
											 const PRUnichar * title0, const PRUnichar * title1, const PRUnichar * title2, 
											 const PRUnichar * chkMsg, PRBool * chkState, PRInt32 * retVal);
		
		PRBool (STDCALL *OnPrompt)			(const PRUnichar * title, const PRUnichar * text, 
											 PRUnichar ** retVal);
		
		PRBool (STDCALL *OnPromptUsernameAndPassword)	
											(const PRUnichar * title, const PRUnichar * text, 
											 const PRUnichar * chkMsg, PRBool * chkState,
											 PRUnichar ** username, PRUnichar ** password);
		
		PRBool (STDCALL *OnPromptPassword)	(const PRUnichar * title, const PRUnichar * text, 
											 const PRUnichar * chkMsg, PRBool * chkState, 
											 PRUnichar ** password);

		PRBool (STDCALL *OnSelect)			(const PRUnichar * title, const PRUnichar * text, 
											 PRUint32 count, const PRUnichar ** list, 
											 PRInt32 * retVal);


		void (STDCALL *OnLoad)			();
		void (STDCALL *OnUnload)		();
		
		void (STDCALL *OnGeneric)			(const PRUnichar* type);

	} CallbackBin;				

	// Function Exports

	// initialization
	NS_EXPORT_(void) gluezilla_debug (int signal);
	
	NS_EXPORT_(Handle *) gluezilla_init (Platform platform, Platform * mozPlatform);
	NS_EXPORT_(Handle *) gluezilla_createBrowserWindow (CallbackBin *events, 
														Handle *hwnd, PRInt32 width, PRInt32 height, 
														const char * startDir, const char * dataDir, 
														Platform platform);

	// layout
	NS_EXPORT_(int) gluezilla_focus (Handle *instance, FocusOption focus);
	NS_EXPORT_(int) gluezilla_blur (Handle *instance);
	NS_EXPORT_(int) gluezilla_activate (Handle *instance);
	NS_EXPORT_(int) gluezilla_deactivate (Handle *instance);
	NS_EXPORT_(int) gluezilla_resize (Handle *instance, PRUint32 width, PRUint32 height);

	// Navigation
	NS_EXPORT_(int) gluezilla_navigate (Handle *instance, const char * uri);
	NS_EXPORT_(PRBool) gluezilla_forward (Handle *instance);
	NS_EXPORT_(PRBool) gluezilla_back (Handle *instance);
	NS_EXPORT_(int) gluezilla_home (Handle *instance);
	NS_EXPORT_(int) gluezilla_stop (Handle *instance);
	NS_EXPORT_(int) gluezilla_reload (Handle *instance, ReloadOption option);

	// shutdown
	NS_EXPORT_(int) gluezilla_shutdown (Handle *instance);

	// DOM
	NS_EXPORT_(nsIDOMHTMLDocument*) gluezilla_getDomDocument (Handle *instance);
	NS_EXPORT_(nsIWebNavigation*) gluezilla_getWebNavigation (Handle *instance);

	// string helper methods
	NS_EXPORT_(nsString*) gluezilla_stringInit ();
	NS_EXPORT_(nsresult) gluezilla_stringFinish (nsString * string);
	NS_EXPORT_(PRUnichar*) gluezilla_stringGet(nsString & str);
	NS_EXPORT_(void) gluezilla_stringSet(nsString & str, PRUnichar * text);
	
	NS_EXPORT_(void) gluezilla_getProxyForObject (Handle *instance, REFNSIID iid, nsISupports *object, nsISupports ** result);
	
	NS_EXPORT_(nsresult) 	gluezilla_StringContainerInit (nsStringContainer &aStr);
	NS_EXPORT_(void) 		gluezilla_StringContainerFinish (nsStringContainer &aStr);
	NS_EXPORT_(PRUint32) 	gluezilla_StringGetData (const nsAString &aStr, const PRUnichar **aBuf, PRBool *aTerm);
	NS_EXPORT_(nsresult) 	gluezilla_StringSetData (nsAString &aStr, const PRUnichar *aBuf, PRUint32 aCount);
	
	NS_EXPORT_(nsresult) 	gluezilla_CStringContainerInit (nsCStringContainer &aStr);
	NS_EXPORT_(void) 		gluezilla_CStringContainerFinish (nsCStringContainer &aStr);
	NS_EXPORT_(PRUint32) 	gluezilla_CStringGetData (const nsACString &aStr, const char **aBuf, PRBool *aTerm);
	NS_EXPORT_(nsresult) 	gluezilla_CStringSetData (nsACString &aStr, const char *aBuf, PRUint32 aCount);

	NS_EXPORT_(nsIServiceManager*) gluezilla_getServiceManager();
	NS_EXPORT_(char*) gluezilla_evalScript (Handle *instance, const char * script);

#ifdef __cplusplus
}
#endif				/* __cplusplus */


class Widget;

struct Params {

	const char * name;
	Widget * instance;
	
	union {
		struct {
			char * string;
		};
		struct {
			Handle * hwnd;
			PRInt32 width;
			PRInt32 height;
		};
		struct {
			CallbackBin *events;
		};
		struct {
			ReloadOption option;
		};
		struct {
			FocusOption focus;
		};
		struct {
			nsIDOMHTMLDocument * document;
		};
		struct {
			nsIWebNavigation * navigation;
		};
		struct {
			nsIID iid;
			nsISupports * object;
			nsISupports * result;
		};
	};
};


#endif
