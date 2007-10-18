AM_CXXFLAGS = @autoconf_default_CXXFLAGS@

#bin_PROGRAMS = demo

lib_LTLIBRARIES = libgluezilla.la

INCLUDES = $(GLUEZILLA_CFLAGS)

libgluezilla_la_SOURCES = 	\
	interfaces.h \
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
	gluezilla.cpp	\
	gluezilla.h

libgluezilla_la_LIBADD = $(GLUEZILLA_LIBS)

EXTRA_DIST = FastDelegate.h

debug:
	LD_LIBRARY_PATH=.libs gdb 

valgrind:
	LD_LIBRARY_PATH=.libs valgrind
