/* gluezilla.cpp: external interface
 *
 * Author:
 *	Andreia Gaita  <avidigal@novell.com>
 *
 * Copyright 2007 Novell, Inc. (http://www.novell.com)
 *
 * See the LICENSE file included with the distribution for details.
 * 
 */

#include "gluezilla.h"
#include "Widget.h"

#ifdef NS_UNIX
#include "gtkWidget.h"
GThread    *ui_thread_id;
GAsyncQueue *queuein;
GAsyncQueue *queueout;
#endif

NS_METHOD_(void)
gluezilla_debug (int signal)
{
	PRINT2 ("debug signal: %d\n", signal);
}

NS_METHOD_(Handle*)
gluezilla_init (Platform platform, CallbackBin *events, const char * startDir, const char * dataDir, Platform * mozPlatform)
{
#ifdef NS_UNIX
	if (platform == Winforms) {
		g_type_init();	
		if (!g_thread_supported ()) g_thread_init (NULL);

		queuein = g_async_queue_new ();
		queueout = g_async_queue_new ();
		
		ui_thread_id = g_thread_create (gtk_startup, NULL, TRUE, NULL);
		g_async_queue_pop (queueout);
	}
	*mozPlatform = Gtk;
#endif
#ifdef NS_WIN32
	*mozPlatform = Winforms;
#endif

	Widget *widget = new Widget (strdup(startDir), strdup(dataDir), platform);
	
	Params * p = new Params ();
	p->name = "init";
	p->instance = widget;
	p->events = events;

	nsresult result = widget->BeginInvoke (p);
	if (p)
		delete (p);
	return reinterpret_cast<Handle*>(widget);
}

NS_METHOD_(int)
gluezilla_createBrowserWindow (Handle *instance, Handle *hwnd, PRInt32 width, PRInt32 height)
{
	Widget *widget = reinterpret_cast<Widget *> (instance);
	Handle * handle = hwnd;

	Params * p = new Params ();
	p->name = "create";
	p->instance = widget;
	p->hwnd = hwnd;
	p->width = width;
	p->height = height;

	nsresult result = widget->BeginInvoke (p);
	if (p)
		delete (p);
	return result;
}

/*******************
Layout
*******************/
NS_METHOD_(int) gluezilla_focus (Handle *instance, FocusOption focus)
{
	Widget *widget = reinterpret_cast<Widget *> (instance);

	Params * p = new Params ();
	p->name = "focus";
	p->instance = widget;
	p->focus = focus;

	nsresult result = widget->BeginInvoke (p);
	if (p)
		delete (p);
	return result;
}

NS_METHOD_(int) gluezilla_blur (Handle *instance)
{
	Widget *widget = reinterpret_cast<Widget *> (instance);

	Params * p = new Params ();
	p->name = "blur";
	p->instance = widget;

	nsresult result = widget->BeginInvoke (p);
	if (p)
		delete (p);
	return result;
}

NS_METHOD_(int) gluezilla_activate (Handle *instance)
{
	Widget *widget = reinterpret_cast<Widget *> (instance);

	Params * p = new Params ();
	p->name = "activate";
	p->instance = widget;

	nsresult result = widget->BeginInvoke (p);
	if (p)
		delete (p);
	return result;
}

NS_METHOD_(int) gluezilla_deactivate (Handle *instance)
{
	Widget *widget = reinterpret_cast<Widget *> (instance);

	Params * p = new Params ();
	p->name = "deactivate";
	p->instance = widget;

	nsresult result = widget->BeginInvoke (p);
	if (p)
		delete (p);
	return result;
}

NS_METHOD_(int) gluezilla_resize (Handle *instance, PRUint32 width, PRUint32 height)
{
	Widget *widget = reinterpret_cast<Widget *> (instance);

	Params * p = new Params ();
	p->name = "resize";
	p->instance = widget;
	p->width = width;
	p->height = height;

	nsresult result = widget->BeginInvoke (p);
	if (p)
		delete (p);
	return result;
}

/*******************
Navigation
*******************/
NS_METHOD_(int)
gluezilla_navigate (Handle *instance, const char * uri)
{
	Widget *widget = reinterpret_cast<Widget *> (instance);
	
	Params * p = new Params ();
	p->name = "navigate";
	p->instance = widget;
	p->uri = strdup (uri);

	nsresult result = widget->BeginInvoke (p);
	if (p)
		delete (p);
	return result;
}

NS_METHOD_(PRBool)
gluezilla_forward (Handle *instance)
{
	Widget *widget = reinterpret_cast<Widget *> (instance);
	
	Params * p = new Params ();
	p->name = "forward";
	p->instance = widget;

	nsresult result = widget->BeginInvoke (p);
	if (p)
		delete (p);
	return result;
}

NS_METHOD_(PRBool)
gluezilla_back (Handle *instance)
{
	Widget *widget = reinterpret_cast<Widget *> (instance);
	
	Params * p = new Params ();
	p->name = "back";
	p->instance = widget;

	nsresult result = widget->BeginInvoke (p);
	if (p)
		delete (p);
	return result;
}

NS_METHOD_(int)
gluezilla_home (Handle *instance)
{
	Widget *widget = reinterpret_cast<Widget *> (instance);
	
	Params * p = new Params ();
	p->name = "home";
	p->instance = widget;

	nsresult result = widget->BeginInvoke (p);
	if (p)
		delete (p);
	return result;
}

NS_METHOD_(int)
gluezilla_stop (Handle *instance)
{
	Widget *widget = reinterpret_cast<Widget *> (instance);
	
	Params * p = new Params ();
	p->name = "stop";
	p->instance = widget;

	nsresult result = widget->BeginInvoke (p);
	if (p)
		delete (p);
	return result;
}

NS_METHOD_(int)
gluezilla_reload (Handle *instance, ReloadOption option)
{
	Widget *widget = reinterpret_cast<Widget *> (instance);
	
	Params * p = new Params ();
	p->name = "reload";
	p->instance = widget;
	p->option = option;

	nsresult result = widget->BeginInvoke (p);
	if (p)
		delete (p);
	return result;
}

NS_METHOD_(int)
gluezilla_shutdown (Handle *instance)
{
	Widget *widget = reinterpret_cast<Widget *> (instance);

	Params * p = new Params ();
	p->name = "shutdown";
	p->instance = widget;

	nsresult result = widget->BeginInvoke (p);
	if (p)
		delete (p);
	return result;	
}


NS_METHOD_(nsIDOMHTMLDocument*)
gluezilla_getDomDocument (Handle *instance)
{
	Widget *widget = reinterpret_cast<Widget *> (instance);

	Params * p = new Params ();
	p->name = "getDocument";
	p->instance = widget;

	nsresult result = widget->BeginInvoke (p);
	nsIDOMHTMLDocument * ret (p->document);
	if (p)
		delete (p);
	return ret;
}

NS_METHOD_(nsIWebNavigation*)
gluezilla_getWebNavigation (Handle *instance)
{
	Widget * widget = reinterpret_cast<Widget *> (instance);
	Params * p = new Params ();
	p->name = "getNavigation";
	p->instance = widget;

	nsresult result = widget->BeginInvoke (p);
	nsIWebNavigation * ret (p->navigation);
	if (p)
		delete (p);
	return ret;
}

NS_METHOD_(void)
gluezilla_setString (Handle *instance, nsString & ret)
{
	Widget *widget = reinterpret_cast<Widget *> (instance);
	nsCOMPtr<nsIDOMWindow> domWindow;
	
	widget->browserWindow->webBrowser->GetContentDOMWindow( getter_AddRefs (domWindow) );
	nsCOMPtr<nsIDOMDocument> domDoc;
	domWindow->GetDocument (getter_AddRefs(domDoc));
	nsCOMPtr<nsIDOMNode> node;
	domDoc->GetFirstChild (getter_AddRefs (node));
	node->GetLocalName (ret);

	const PRUnichar * s = (PRUnichar *)ret.get ();
	
}

NS_METHOD_(nsString *)
gluezilla_stringInit()
{
	return new nsString ();
}

NS_METHOD_(nsresult)
gluezilla_stringFinish(nsString * string)
{
	NS_StringContainerFinish (reinterpret_cast<nsStringContainer&> (*string));
	delete string;
	return NS_OK;
}

NS_METHOD_(PRUnichar*)
gluezilla_stringGet(nsString & str)
{
	return (PRUnichar *)str.get ();
}

NS_METHOD_(void)
gluezilla_stringSet(nsString & str, PRUnichar * text)
{
	str.Assign (text);
}

NS_METHOD_(nsIServiceManager*)
gluezilla_getServiceManager()
{
	nsCOMPtr<nsIServiceManager> servMan;
	NS_GetServiceManager (getter_AddRefs (servMan));
	return servMan;
}

NS_METHOD_(void)
gluezilla_getProxyForObject (Handle *instance, REFNSIID iid, nsISupports *object, nsISupports ** result)
{
	Widget *widget = reinterpret_cast<Widget *> (instance);

	Params * p = new Params ();
	p->name = "getProxyForObject";
	p->instance = widget;
	p->object = object;
	p->iid = iid;

	nsresult rv = widget->BeginInvoke (p);

	NS_ADDREF(*result = p->result);
	NS_RELEASE (p->result);

	if (p)
		delete (p);
	return;
}


NS_METHOD_(nsresult)
gluezilla_StringContainerInit (nsStringContainer &aStr)
{
	return NS_StringContainerInit (aStr);
}

NS_METHOD_(void)
gluezilla_StringContainerFinish (nsStringContainer &aStr)
{
	NS_StringContainerFinish (aStr);
}

NS_METHOD_(PRUint32)
gluezilla_StringGetData (const nsAString &aStr, const PRUnichar **aBuf, PRBool *aTerm)
{
	return NS_StringGetData (aStr, aBuf, aTerm);
}

NS_METHOD_(nsresult)
gluezilla_StringSetData (nsAString &aStr, const PRUnichar *aBuf, PRUint32 aCount)
{
	return NS_StringSetData (aStr, aBuf, aCount);
}
	
NS_METHOD_(nsresult)
gluezilla_CStringContainerInit (nsCStringContainer &aStr)
{
	return NS_CStringContainerInit (aStr);
}

NS_METHOD_(void)
gluezilla_CStringContainerFinish (nsCStringContainer &aStr)
{
	NS_CStringContainerFinish (aStr);
}

NS_METHOD_(PRUint32)
gluezilla_CStringGetData (const nsACString &aStr, const char **aBuf, PRBool *aTerm)
{
	return NS_CStringGetData (aStr, aBuf, aTerm);
}

NS_METHOD_(nsresult)
gluezilla_CStringSetData (nsACString &aStr, const char *aBuf, PRUint32 aCount)
{
	return NS_CStringSetData (aStr, aBuf, aCount);
}


#ifdef NS_UNIX
void *
gtk_startup (gpointer data)
{
	PRINT2 ("wakeup_gtk %p starting...\n", g_thread_self ());
	gdk_threads_enter ();	

	int argc = 0;
	char **argv=NULL;
	gtk_init(&argc, &argv);
	//gdk_window_set_debug_updates (TRUE);	
	g_idle_add (gtk_init_done, NULL);
	gtk_main();
	gdk_threads_leave ();

	return NULL;
}

gboolean
gtk_init_done (gpointer data)
{
	PRINT2 ("callback_initdone %p \n", g_thread_self ());	
	int p = 1;
	g_async_queue_push (queueout, &p);
}

gboolean
gtk_shutdown (gpointer data)
{
	PRINT2 ("gtk_shutdown %p \n", g_thread_self ());	
	gtk_exit (0);
	//gdk_threads_enter ();	
	//while (gtk_main_level () != 0)
	//	gtk_main_quit();
	//gdk_threads_leave ();
	//gtk_exit (0);
	//return 0;
}
#endif
