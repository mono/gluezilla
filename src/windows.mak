!IF "$(CFG)" == ""
CFG=Debug
!MESSAGE No configuration specified. Defaulting to Debug.
!ENDIF 

!IF "$(CFG)" != "Debug" && "$(CFG)" != "Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "makefile.mak" CFG="Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Debug"
!MESSAGE "Release"
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 


OBJDIR=

cc=cl.exe
cflags=/D "XPCOM_GLUE" /D "NO_BUILD_REFCNT_LOGGING" /D "_WINDLL" /FD /EHsc /Fo"$(OBJDIR)\\" /Fd"$(OBJDIR)\\" /nologo /c /TP /wd4005 /wd4996 -I../build/include -I../build/include/xpcom -I../build/include/string -I../build/include/nspr

!IF  "$(CFG)" == "Debug"
cdebug=/Od /D "DEBUG" /D "_MBCS" /RTC1 /RTCc /MDd /Gy /W3 /ZI 
!ELSE 
cdebug=/O2 /MT
!ENDIF 

link="$(VCINSTALLDIR)\bin\link.exe"
lflags=/LIBPATH:../build/lib /DLL xpcomglue.lib /NOLOGO /MANIFEST /MANIFESTFILE:".\\gluezilla.dll.intermediate.manifest" 

!IF  "$(CFG)" == "Debug"
ldebug=/NODEFAULTLIB:msvcrt /DEBUG /PDB:"gluezilla.pdb"  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib
!ELSE 
ldebug=/DLL /NODEFAULTLIB:"libcmt" advapi32.lib
!ENDIF 

mt="$(VCINSTALLDIR)\bin\mt.exe"

!IF  "$(CFG)" == "Debug"
manifest=".\gluezilla.dll.nonsp1.debug.manifest"
!ELSE 
manifest=".\gluezilla.dll.nonsp1.manifest"
!ENDIF 

src= \
	SecurityWarningsDialogs.cpp \
	PromptService.cpp \
	LocationProvider.cpp \
	BrowserWindow.cpp \
	Widget.cpp \
	gluezilla.cpp

objs= \
	"$(OBJDIR)\SecurityWarningsDialogs.obj" \
	"$(OBJDIR)\PromptService.obj" \
	"$(OBJDIR)\LocationProvider.obj" \
	"$(OBJDIR)\BrowserWindow.obj" \
	"$(OBJDIR)\Widget.obj" \
	"$(OBJDIR)\gluezilla.obj"

clean:
	-@erase "$(OBJDIR)\*.obj"
	-@erase "gluezilla.dll"

all : gluezilla.dll

.cpp{$(OBJDIR)}.obj::
	if not exist "$(OBJDIR)/$(NULL)" mkdir "$(OBJDIR)"
   $(cc) $(cdebug) $(cflags) $(src)
	

gluezilla.dll:: gluezilla.obj $(objs)
  $(link) $(ldebug) $(lflags) -out:gluezilla.dll $(objs)
  $(mt) /outputresource:".\gluezilla.dll;#2" /manifest "$(manifest)"
