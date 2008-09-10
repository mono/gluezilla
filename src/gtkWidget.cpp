/* gtkWidget.cpp: gtk hosting widget for an x handle
 *
 * Author:
 *	Andreia Gaita  <avidigal@novell.com>
 *
 * Copyright 2007 Novell, Inc. (http://www.novell.com)
 *
 * See the LICENSE file included with the distribution for details.
 * 
 */


#include "gtkWidget.h"
#include <gtk/gtkcontainer.h>

static void 	native_embed_widget_class_init(NativeEmbedWidgetClass *klass);
static void 	native_embed_widget_init(NativeEmbedWidget *embed);
static void 	native_embed_widget_destroy(GtkObject *object);
static void 	native_embed_widget_realize(GtkWidget *widget);
static void 	native_embed_widget_unrealize(GtkWidget *widget);
static void 	native_embed_widget_size_allocate(GtkWidget *widget, GtkAllocation *allocation);
static void 	native_embed_widget_map(GtkWidget *widget);
static void 	native_embed_widget_unmap(GtkWidget *widget);
static gboolean native_embed_widget_expose(GtkWidget *widget, GdkEventExpose *event);

static GtkWindowClass *parent_class = NULL;
static GtkBinClass *bin_class = NULL;
guint native_embed_widget_signals[EMBED_LAST_SIGNAL] = { 0 };


G_DEFINE_TYPE (NativeEmbedWidget, native_embed_widget, GTK_TYPE_WINDOW)

static void
native_embed_widget_class_init(NativeEmbedWidgetClass *klass)
{
	PRINT("native_embed_widget_class_init\n");
	GtkWidgetClass *widget_class;
	GtkObjectClass     *object_class;

	widget_class = GTK_WIDGET_CLASS(klass);
	object_class = GTK_OBJECT_CLASS(klass);

	parent_class = (GtkWindowClass*)gtk_type_class(gtk_window_get_type());

	widget_class->realize = native_embed_widget_realize;
	widget_class->unrealize = native_embed_widget_unrealize;
	widget_class->size_allocate = native_embed_widget_size_allocate;
	widget_class->map = native_embed_widget_map;
	widget_class->unmap = native_embed_widget_unmap;
	widget_class->expose_event = native_embed_widget_expose;
	
	object_class->destroy = native_embed_widget_destroy;
	
	native_embed_widget_signals[NEW_WINDOW] =
		gtk_signal_new("new_window",
		GTK_RUN_FIRST,
		G_OBJECT_CLASS_TYPE(klass),
		GTK_SIGNAL_OFFSET(NativeEmbedWidgetClass, new_window),
		gtk_marshal_NONE__POINTER_UINT,
		GTK_TYPE_NONE, 2, GTK_TYPE_POINTER, GTK_TYPE_UINT);


}

static gboolean
native_embed_widget_expose(GtkWidget *widget, GdkEventExpose *event)
{
	PRINT("native_embed_widget_expose\n");
	return FALSE;
}

static void
native_embed_widget_init(NativeEmbedWidget *embed)
{
	PRINT("native_embed_widget_init\n");		
}

GtkWidget *
native_embed_widget_new()
{	
	PRINT("native_embed_widget_new\n");
	NativeEmbedWidget * embed_widget = (NativeEmbedWidget *)g_object_new (GTK_TYPE_NATIVE_EMBED, NULL);

	return GTK_WIDGET(embed_widget);
}

GtkWidget *
native_embed_widget_foreign_new(GdkNativeWindow parent_id)
{
	PRINT("native_embed_widget_new\n");
	NativeEmbedWidget * embed_widget = (NativeEmbedWidget *)g_object_new (GTK_TYPE_NATIVE_EMBED, NULL);

	embed_widget->parent_window = gdk_window_lookup_for_display (gdk_display_get_default (), parent_id);
	
	if (!embed_widget->parent_window)
		embed_widget->parent_window = gdk_window_foreign_new_for_display (gdk_display_get_default (), parent_id);

	return GTK_WIDGET(embed_widget);
}

static void
native_embed_widget_destroy(GtkObject *object)
{
	PRINT("native_embed_widget_destroy\n");
	g_return_if_fail(object != NULL);
	g_return_if_fail(GTK_IS_NATIVE_EMBED(object));
	
	NativeEmbedWidget *embed = GTK_NATIVE_EMBED(object);

	embed->data = NULL;	
	gtk_shutdown (NULL);
}

static void
native_embed_widget_realize(GtkWidget *widget)
{
	PRINT("native_embed_widget_realize\n");

	GtkWindow *window;
	NativeEmbedWidget *embed_widget;
	GdkWindowAttr attributes;
	gint attributes_mask;

	g_return_if_fail(widget != NULL);
	g_return_if_fail(GTK_IS_NATIVE_EMBED(widget));

	embed_widget = GTK_NATIVE_EMBED(widget);


	/* ensure widget tree is properly size allocated */
	if (widget->allocation.x == -1 &&
		widget->allocation.y == -1 &&
		widget->allocation.width == 1 &&
		widget->allocation.height == 1)
	{
		GtkRequisition requisition;
		GtkAllocation allocation = { 0, 0, 200, 200 };
	
		gtk_widget_size_request (widget, &requisition);
		if (requisition.width || requisition.height)
		{
			/* non-empty window */
			allocation.width = requisition.width;
			allocation.height = requisition.height;
		}
		gtk_widget_size_allocate (widget, &allocation);
		
//		_gtk_container_queue_resize (GTK_CONTAINER (widget));
		
		g_return_if_fail (!GTK_WIDGET_REALIZED (widget));
	}

	GTK_WIDGET_SET_FLAGS(widget, GTK_REALIZED);
	
	attributes.window_type = GDK_WINDOW_TOPLEVEL;
	attributes.x = widget->allocation.x;
	attributes.y = widget->allocation.y;
	attributes.width = widget->allocation.width;
	attributes.height = widget->allocation.height;
	attributes.wclass = GDK_INPUT_OUTPUT;
	attributes.visual = gtk_widget_get_visual (widget);
	attributes.colormap = gtk_widget_get_colormap (widget);
	attributes.event_mask = gtk_widget_get_events (widget);
	attributes.event_mask |= (GDK_EXPOSURE_MASK |
				GDK_KEY_PRESS_MASK |
				GDK_KEY_RELEASE_MASK |
				GDK_ENTER_NOTIFY_MASK |
				GDK_LEAVE_NOTIFY_MASK |
				GDK_STRUCTURE_MASK |
				GDK_FOCUS_CHANGE_MASK);
	
	attributes_mask = GDK_WA_X | GDK_WA_Y | GDK_WA_VISUAL | GDK_WA_COLORMAP;
//	attributes_mask |= (window->title ? GDK_WA_TITLE : 0);
//	attributes_mask |= (window->wmclass_name ? GDK_WA_WMCLASS : 0);
	
	if (!embed_widget->parent_window)
		embed_widget->parent_window = gtk_widget_get_parent_window ((GtkWidget*)embed_widget);
	widget->window = gdk_window_new (embed_widget->parent_window, &attributes, attributes_mask);

	gdk_window_set_user_data (widget->window, embed_widget);
	widget->style = gtk_style_attach (widget->style, widget->window);
	gtk_style_set_background (widget->style, widget->window, GTK_STATE_NORMAL);
}

static void
native_embed_widget_unrealize(GtkWidget *widget)
{
	PRINT("native_embed_widget_unrealize\n");
	NativeEmbedWidget *embed_widget;

	g_return_if_fail(widget != NULL);
	g_return_if_fail(GTK_IS_NATIVE_EMBED(widget));
	embed_widget = GTK_NATIVE_EMBED(widget);	
	if (GTK_WIDGET_CLASS(native_embed_widget_parent_class)->unrealize)
    	(* GTK_WIDGET_CLASS(native_embed_widget_parent_class)->unrealize)(widget);
	
}

static void
native_embed_widget_show (GtkWidget *widget)
{
  GTK_WIDGET_SET_FLAGS (widget, GTK_VISIBLE);
  
  gtk_widget_realize (widget);
  gtk_container_check_resize (GTK_CONTAINER (widget));
  gtk_widget_map (widget);
}

static void
native_embed_widget_hide (GtkWidget *widget)
{
  GTK_WIDGET_UNSET_FLAGS (widget, GTK_VISIBLE);
  gtk_widget_unmap (widget);
}

static void
native_embed_widget_size_allocate(GtkWidget *widget, GtkAllocation *allocation)
{
	PRINT("native_embed_widget_size_allocate\n");
	g_return_if_fail(widget != NULL);
	g_return_if_fail(GTK_IS_NATIVE_EMBED(widget));

	GtkBin *bin = GTK_BIN (widget);

	widget->allocation = *allocation;

	PRINT2 ("is realized=%d\n", GTK_WIDGET_REALIZED (widget));
	
	if (GTK_WIDGET_REALIZED (widget))
		gdk_window_move_resize (widget->window,
								allocation->x, allocation->y,
								allocation->width, allocation->height);
	
	
	
	if (bin->child && GTK_WIDGET_VISIBLE (bin->child))
	{
		PRINT ("is visible \n");
		GtkAllocation child_allocation;
	
		child_allocation.x = child_allocation.y = GTK_CONTAINER (widget)->border_width;
		child_allocation.width = MAX (1, (gint)allocation->width - child_allocation.x * 2);
		child_allocation.height = MAX (1, (gint)allocation->height - child_allocation.y * 2);
		
		PRINT3 ("is visible %d %d\n", child_allocation.width, child_allocation.height);
		gtk_widget_size_allocate (bin->child, &child_allocation);
	}
}

static void
native_embed_widget_map(GtkWidget *widget)
{
	PRINT("native_embed_widget_map\n");

	g_return_if_fail(widget != NULL);
	g_return_if_fail(GTK_IS_NATIVE_EMBED(widget));

	GtkBin *bin = GTK_BIN (widget);

	GTK_WIDGET_SET_FLAGS (widget, GTK_MAPPED);
	
	if (bin->child &&
			GTK_WIDGET_VISIBLE (bin->child) &&
			!GTK_WIDGET_MAPPED (bin->child))
		gtk_widget_map (bin->child);
	
	gdk_window_show (widget->window);
}

static void
native_embed_widget_unmap(GtkWidget *widget)
{
	PRINT("native_embed_widget_unmap\n");
	g_return_if_fail(widget != NULL);
	g_return_if_fail(GTK_IS_NATIVE_EMBED(widget));

	GTK_WIDGET_UNSET_FLAGS (widget, GTK_MAPPED);
	gdk_window_hide (widget->window);
}

static void
native_embed_widget_check_resize (GtkContainer *container)
{
  GTK_CONTAINER_CLASS (bin_class)->check_resize (container);
}
