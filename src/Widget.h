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

class BrowserWindow;

class Widget 
{
	public:
		Widget (const char * startDir, const char * dataDir, Platform platform)
		{
			this->startDir = startDir;
			this->dataDir = dataDir;
			this->platform = platform;
			// delegate initialization

			// initialization and shutdown
			delegates["init"].bind (this, &Widget::Init);
			delegates["create"].bind (this, &Widget::Create);
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
			delegates["getProxyForObject"].bind (this, &Widget::GetProxyForObject);
			delegates["evalScript"].bind (this, &Widget::EvalScript);
			delegates["getServiceManager"].bind (this, &Widget::GetServiceManager);
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
		nsresult Init (Params * params) {
			return this->Init (params->events);
		}

		nsresult Create (Params * params) {
			return this->Create (params->hwnd, params->width, params->height);
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
			return this->Navigate (params->string);
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

		nsresult GetProxyForObject (Params * params) {
			nsCOMPtr<nsISupports> result;
			this->GetProxyForObject (params->iid, params->object, getter_AddRefs(result));

			NS_ADDREF(params->result = result);
			return NS_OK;
		}
		
		nsresult EvalScript (Params * params) {
			params->string = this->EvalScript (params->string);
			return 0;
		}

		
		nsresult GetServiceManager (Params * params) {
			nsCOMPtr<nsIServiceManager> result;
			nsCOMPtr<nsIServiceManager> servMan;
			NS_GetServiceManager (getter_AddRefs (servMan));
			this->GetProxyForObject (nsIServiceManager::GetIID(), servMan, getter_AddRefs (result));
			NS_ADDREF(params->result = result);
			return NS_OK;
		}
		
		// end of generic targets for delegation

		// Initialization and Shutdown
		nsresult Init (CallbackBin * events);
		void Shutdown ();
		nsresult Create (Handle * hwnd, PRUint32 width, PRUint32 height);
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
		nsresult GetProxyForObject (REFNSIID iid, nsISupports *object, void **result);
		
		char * EvalScript (const char * script);

		Handle * getHandle () { return this->hwnd;}


		// Events
		PRBool EventActivate		(void);
		void EventGeneric			(nsString type);




	public:
		const char * startDir;
		const char * dataDir;

		PRBool		isDestroyed;
		PRBool		isChrome;
		PRBool		chromeLoaded;
		PRUint32	chromeMask;

		CallbackBin	*events;

		BrowserWindow * browserWindow;
		nsCOMPtr<nsIDOMHTMLDocument> document;
		nsCOMPtr<nsIWebNavigation> webNav;
	private:
		nsresult GRE_Startup ();
		

		std::map<const char*, WidgetDelegate> delegates;
		
		static PRUint32 widgetCount;

		Handle * hwnd;
		
		PRUint32 width;
		PRUint32 height;

		Platform platform;
	
		// the appshell we have created
		nsIAppShell *appShell;
};
#endif
