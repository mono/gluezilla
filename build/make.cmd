del idl /F /Q /S
del include /F /Q /S
del lib /F /Q /S

md idl
md include
md include\widget
md include\docshell
md include\dom
md include\xpcom
md include\webbrwsr
md lib
copy %1\idl\*.idl idl
xcopy %1\include\* include /e
copy %1\lib\* lib
copy idl_extras\* idl
xcopy  /E include_extras\* include


xpidl.exe -I %1\idl\ -m header idl\nsIAppShell.idl
move nsIAppShell.h include\widget\
xpidl.exe -I %1\idl\ -m header idl\nsIBaseWindow.idl
move nsIBaseWindow.h include\widget\
xpidl.exe -I %1\idl\ -m header idl\nsIDocShellTreeItem.idl
move nsIDocShellTreeItem.h include\docshell\
xpidl.exe -I %1\idl\ -m header idl\nsIDOMKeyEvent.idl
move nsIDOMKeyEvent.h include\dom\
xpidl.exe -I %1\idl\ -m header idl\nsIWebNavigation.idl
move nsIWebNavigation.h include\docshell\
xpidl.exe -I %1\idl\ -m header idl\nsIProxyObjectManager.idl
move nsIProxyObjectManager.h include\xpcom\
xpidl.exe -I %1\idl\ -m header idl\nsIEmbeddingSiteWindow2.idl
move nsIEmbeddingSiteWindow2.h include\webbrwsr\

