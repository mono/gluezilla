/* Widget.h: controller class
 *
 * Author:
 *	Andreia Gaita  <avidigal@novell.com>
 *
 * Copyright 2007 Novell, Inc. (http://www.novell.com)
 *
 * See the LICENSE file included with the distribution for details.
 * 
 */

#ifndef _WIDGET_H_
#define _WIDGET_H_

#ifndef MAX_PATH
#define MAX_PATH PATH_MAX 
#endif

#include "gluezilla.h"
#include "BrowserWindow.h"

#ifdef DEBUG
#define SHOUT(str)	\
	NS_WARNING(str)
#else
#define SHOUT(str)
#endif
#include <map>

#include "FastDelegate.h"
using namespace fastdelegate;
typedef FastDelegate1<Params*, nsresult> WidgetDelegate;


class Widget 
{
	public:
		Widget (const char * startDir, const char * dataDir)
		{
			this->startDir = startDir;
			this->dataDir = dataDir;
			// delegate initialization

			// initialization and shutdown
			delegates["init"].bind (this, &Widget::Load);
			delegates["create"].bind (this, &Widget::Init);
			delegates["shutdown"].bind (this, &Widget::Shutdown);

			// layout
			delegates["focus"].bind (this, &Widget::Focus);
			delegates["blur"].bind (this, &Widget::Blur);
			delegates["activate"].bind (this, &Widget::Activate);
			delegates["deactivate"].bind (this, &Widget::Deactivate);
			delegates["resize"].bind (this, &Widget::Resize);

			// navigation
			delegates["navigate"].bind (this, &Widget::Navigate);
			delegates["forward"].bind (this, &Widget::Forward);
			delegates["back"].bind (this, &Widget::Back);
			delegates["home"].bind (this, &Widget::Home);
			delegates["stop"].bind (this, &Widget::Stop);
			delegates["reload"].bind (this, &Widget::Reload);
			
			delegates["getDocument"].bind (this, &Widget::GetDocument);
			delegates["getNavigation"].bind (this, &Widget::GetNavigation);
		}
		~Widget() {
			int a = 0;
		}

		nsresult BeginInvoke (Params * params);

		nsresult EndInvoke (Params * params) {
			return delegates[params->name](params);
		}

		// generic targets for delegation

		// initialization and shutdown
		nsresult Load (Params * params) {
			return this->Load (params->events);
		}

		nsresult Init (Params * params) {
			return this->Init (params->hwnd, params->width, params->height);
		}

		nsresult Shutdown (Params * params) {
			this->Shutdown ();
			return NS_OK;
		}

		// layout
		nsresult Focus (Params * params) {
			return this->Focus (params->focus);
		}
		nsresult Blur (Params * params) {
			return this->Blur ();
		}
		nsresult Activate (Params * params) {
			return this->Activate ();
		}
		nsresult Deactivate (Params * params) {
			return this->Deactivate ();
		}
		nsresult Resize (Params * params) {
			return this->Resize (params->width, params->height);
		}

		// navigation
		nsresult Navigate (Params * params) {
			return this->Navigate (params->uri);
		}

		nsresult Forward (Params * params) {
			return this->Forward ();
		}
		nsresult Back (Params * params) {
			return this->Back ();
		}
		nsresult Home (Params * params) {
			return this->Home ();
		}
		nsresult Stop (Params * params) {
			return this->Stop ();
		}
		nsresult Reload (Params * params) {
			return this->Reload (params->option);
		}

		nsresult GetDocument (Params * params) {
			this->GetProxyForDocument ();
			params->document = this->document;
			return NS_OK;
		}

		nsresult GetNavigation (Params * params) {
			this->GetProxyForNavigation ();
			params->navigation = this->webNav;
			return NS_OK;
		}
		// end of generic targets for delegation

		// Initialization and Shutdown
		nsresult Load (CallbackBin * events);
		void Shutdown ();
		nsresult Init (Handle * hwnd, PRUint32 width, PRUint32 height);
		nsresult CreateBrowserWindow ();

		// Layout
		nsresult Focus (FocusOption focus);
		nsresult Blur ();
		nsresult Activate ();
		nsresult Deactivate ();
		nsresult Resize (PRUint32 width, PRUint32 height);

		// Navigation
		nsresult Navigate (const char * uri);
		nsresult Navigate (nsString uri);
		nsresult Forward ();
		nsresult Back ();
		nsresult Home ();
		nsresult Stop ();
		nsresult Reload (ReloadOption option);
	
		// getters
		nsresult GetProxyForDocument ();
		nsresult GetProxyForNavigation ();
		
		Handle * getHandle () { return this->hwnd;}


		// Events
		void EventOnWidgetLoaded	();

		void EventJSStatus			(void);
		void EventLinkStatus		(void);
		void EventDestroyBrowser	(void);
		void EventSizeTo			(PRInt32 x, PRInt32 y);
		void EventFocusNext			(void);
		void EventFocusPrev			(void);
		void EventTitleChanged		(void);
		void EventShowTooltipWindow	(PRInt32 x, PRInt32 y, const char *tipText);
		void EventHideTooltipWindow	(void);
		void EventStateNetStart		(void);
		void EventStateNetStop		(void);
		void EventStateSpecial		(PRUint32 stateFlags, PRInt32 status);
		void EventStateChange		(PRUint32 stateFlags, PRInt32 status);
		void EventProgress			(PRInt32 curTotalProgress, PRInt32 maxTotalProgress);
		void EventProgressAll		(const char *uriString, PRInt32 curTotalProgress, PRInt32 maxTotalProgress);
		void EventLocationChanged	(const char * url);
		void EventStatusChange		(PRInt32 status, const char *message);
		void EventSecurityChange	(PRUint32 state);
		void EventVisibility		(PRBool val);

		PRBool EventDomKeyDown			(KeyInfo keyInfo, ModifierKeys modifiers);
		PRBool EventDomKeyUp			(KeyInfo keyInfo, ModifierKeys modifiers);
		PRBool EventDomKeyPress			(KeyInfo keyInfo, ModifierKeys modifiers);

		PRBool EventMouseDown			(MouseInfo mouseInfo, ModifierKeys modifiers);
		PRBool EventMouseUp				(MouseInfo mouseInfo, ModifierKeys modifiers);
		PRBool EventMouseClick			(MouseInfo mouseInfo, ModifierKeys modifiers);
		PRBool EventMouseDoubleClick	(MouseInfo mouseInfo, ModifierKeys modifiers);
		PRBool EventMouseOver			(MouseInfo mouseInfo, ModifierKeys modifiers);
		PRBool EventMouseOut			(MouseInfo mouseInfo, ModifierKeys modifiers);


		PRBool EventActivate		(void);
		PRBool EventFocusIn			(void);
		PRBool EventFocusOut		(void);

		PRBool EventBeforeURIOpen	(const char* url);

		void EventFocus				(void);
		PRBool EventCreateNewWindow	(void);

		void EventGeneric			(nsString type);




	public:
		const char * startDir;
		const char * dataDir;

		PRBool		isDestroyed;
		PRBool		isChrome;
		PRBool		chromeLoaded;
		PRUint32	chromeMask;

		CallbackBin	*events;

		BrowserWindow *browserWindow;
		nsCOMPtr<nsIDOMHTMLDocument> document;
		nsCOMPtr<nsIWebNavigation> webNav;
	private:
		nsresult GRE_Startup ();
		

		std::map<const char*, WidgetDelegate> delegates;
		
		static PRUint32 widgetCount;

		Handle * hwnd;
		
		PRUint32 width;
		PRUint32 height;
	
		// the appshell we have created
		nsIAppShell *appShell;
};
#endif
