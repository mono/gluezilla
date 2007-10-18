AM_CXXFLAGS = @autoconf_default_CXXFLAGS@

#bin_PROGRAMS = demo

lib_LTLIBRARIES = libxulbrowser.la

INCLUDES = $(XULBROWSER_CFLAGS)

libxulbrowser_la_SOURCES = 	\
	SecurityWarningsDialogs.cpp	\
	SecurityWarningsDialogs.h	\
	PromptService.cpp	\
	PromptService.h	\
	LocationProvider.cpp	\
	LocationProvider.h	\
	BrowserWindow.cpp	\
	BrowserWindow.h	\
	Widget.cpp	\
	Widget.h	\
	gtkWidget.cpp	\
	gtkWidget.h	\
	xulbrowser.cpp	\
	xulbrowser.h

libxulbrowser_la_LIBADD = $(XULBROWSER_LIBS)

debug:
	LD_LIBRARY_PATH=.libs gdb 

valgrind:
	LD_LIBRARY_PATH=.libs valgrind
