#ifndef __EventListener_h
#define __EventListener_h

#include <interfaces.h>
#include "gluezilla.h"
#include <BrowserWindow.h>

class BrowserWindow;

class EventListener : public nsIDOMEventListener
{
	NS_DECL_ISUPPORTS
	NS_DECL_NSIDOMEVENTLISTENER

public:

	EventListener() {
	  NS_INIT_ISUPPORTS ();
	}
	
	nsresult OnKey (nsCOMPtr <nsIDOMKeyEvent> keyEvent, nsEmbedString type);
	nsresult OnMouse (nsCOMPtr <nsIDOMMouseEvent> mouseEvent, nsEmbedString type);
	nsresult OnEvent (nsEmbedString type);

	
	nsCOMPtr<nsIDOMEventTarget> target;
	BrowserWindow * owner;
	CallbackBin * events;
};

#endif /* __EventListener_h */
