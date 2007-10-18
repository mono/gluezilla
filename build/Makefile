GECKOSDK 	= ./gecko-sdk
GECKOIDL 	= $(GECKOSDK)/idl
GECKOBIN 	= $(GECKOSDK)/bin
GECKOINCLUDE 	= $(GECKOSDK)/include
GECKOLIB	= $(GECKOSDK)/lib

XPIDL = $(GECKOBIN)/xpidl
WGET = wget

MAKEHEADER = $(XPIDL) -I ./idl/ -m header

ALL: clean make-headers
    
make-folders: 
	-mkdir ./idl/ 
	-mkdir ./include/ 
	-mkdir ./include/widget
	-mkdir ./include/docshell
	-mkdir ./include/dom
	-mkdir ./lib/
	cp $(GECKOIDL)/*.idl ./idl/
	cp $(GECKOINCLUDE)/*.h ./include/
	cp $(GECKOLIB)/* ./lib/
	cp ./idl_extras/* ./idl/
	cp -R ./include_extras/* ./include/

clean:
	-rm -rf idl
	-rm -rf include
	-rm -rf lib

make-headers: make-folders 
	$(MAKEHEADER) ./idl/nsIAppShell.idl
	mv nsIAppShell.h ./include/widget/
	$(MAKEHEADER) ./idl/nsIBaseWindow.idl
	mv nsIBaseWindow.h ./include/widget/
	$(MAKEHEADER) ./idl/nsIDocShellTreeItem.idl
	mv nsIDocShellTreeItem.h ./include/docshell/
	$(MAKEHEADER) ./idl/nsIDOMKeyEvent.idl
	mv nsIDOMKeyEvent.h ./include/dom/
	$(MAKEHEADER) ./idl/nsIWebNavigation.idl
	mv nsIWebNavigation.h ./include/docshell/
