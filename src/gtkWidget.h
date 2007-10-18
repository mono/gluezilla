/* gtkWidget.h: gtk hosting widget for an x handle
 *
 * Author:
 *	Andreia Gaita  <avidigal@novell.com>
 *
 * Copyright 2007 Novell, Inc. (http://www.novell.com)
 *
 * See the LICENSE file included with the distribution for details.
 * 
 */

#ifndef _GTKWIDGET_H_
#define _GTKWIDGET_H_


#include <gtk/gtk.h>
#include <gtk/gtkwindow.h>
#include <gdk/gdkx.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define GTK_TYPE_NATIVE_EMBED             (native_embed_widget_get_type())
#define GTK_NATIVE_EMBED(obj)             GTK_CHECK_CAST((obj), GTK_TYPE_NATIVE_EMBED, NativeEmbedWidget)
#define GTK_NATIVE_EMBED_CLASS(klass)     GTK_CHECK_CLASS_CAST((klass), GTK_TYPE_NATIVE_EMBED, NativeEmbedWidgetClass)
#define GTK_IS_NATIVE_EMBED(obj)          GTK_CHECK_TYPE((obj), GTK_TYPE_NATIVE_EMBED)
#define GTK_IS_NATIVE_EMBED_CLASS(klass)  GTK_CHECK_CLASS_TYPE((klass), GTK_TYPE_NATIVE_EMBED)

typedef struct _NativeEmbedWidget      NativeEmbedWidget;
typedef struct _NativeEmbedWidgetClass NativeEmbedWidgetClass;

struct _NativeEmbedWidget
{
	GtkWindow window;	
	GdkWindow *parent_window;
	
	GtkBin    bin;
	void     *data;
	GtkWidget * vbox;
};

struct _NativeEmbedWidgetClass
{
	GtkWindowClass parent_class;
	
	void (* new_window) (NativeEmbedWidget *embed, 
						NativeEmbedWidget **newEmbed,
						guint chromemask);
	
};

GtkWidget* native_embed_widget_new (void);
GtkWidget* native_embed_widget_foreign_new (GdkNativeWindow parent_id);


enum {
  LINK_MESSAGE,
  JS_STATUS,
  LOCATION,
  TITLE,
  PROGRESS,
  PROGRESS_ALL,
  NET_STATE,
  NET_STATE_ALL,
  NET_START,
  NET_STOP,
  NEW_WINDOW,
  VISIBILITY,
  DESTROY_BROWSER,
  OPEN_URI,
  SIZE_TO,
  DOM_KEY_DOWN,
  DOM_KEY_PRESS,
  DOM_KEY_UP,
  DOM_MOUSE_DOWN,
  DOM_MOUSE_UP,
  DOM_MOUSE_CLICK,
  DOM_MOUSE_DBL_CLICK,
  DOM_MOUSE_OVER,
  DOM_MOUSE_OUT,
  SECURITY_CHANGE,
  STATUS_CHANGE,
  DOM_ACTIVATE,
  DOM_FOCUS_IN,
  DOM_FOCUS_OUT,
  EMBED_LAST_SIGNAL
};

extern guint native_embed_widget_signals[EMBED_LAST_SIGNAL];


#ifdef __cplusplus
}
#endif

// --- gluezilla gtk definitions -- //

void * gtk_startup (gpointer data);
gboolean gtk_init_done (gpointer data);
gboolean gtk_shutdown (gpointer data);

// --- end of gluezilla gtk definitions -- //



#endif /* _GTKWIDGET_H */
