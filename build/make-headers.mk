


GECKOSDK 	= ./gecko-sdk
GECKOIDL 	= $(GECKOSDK)/idl
GECKOBIN 	= $(GECKOSDK)/bin
GECKOINCLUDE 	= $(GECKOSDK)/include
GECKOLIB	= $(GECKOSDK)/lib

XPIDL = $(GECKOBIN)/xpidl
WGET = wget

MAKEHEADER = $(XPIDL) -I ./idl/ -m header -o ./include/ 

ALL: make-headers
    



make-folders: 
	-mkdir ./idl/ 
	-mkdir ./include/ 
	-mkdir ./lib/
	cp $(GECKOIDL)/*.idl ./idl/
	cp $(GECKOINCLUDE)/*.h ./include/
	cp $(GECKOLIB)/* ./lib/
	cp ./idl_extras/* ./idl/

clean-folders:
	-rm -rf idl
	-rm -rf include
	-rm -rf lib

make-headers: make-folders 
	$(MAKEHEADER) ./idl/nsISupports.idl
	$(MAKEHEADER) ./idl/nsIEmbeddingSiteWindow.idl
	$(MAKEHEADER) ./idl/nsIWindowCreator.idl
	$(MAKEHEADER) ./idl/nsIWebBrowser.idl
	$(MAKEHEADER) ./idl/nsIWebBrowserSetup.idl
	$(MAKEHEADER) ./idl/nsIWebBrowserChrome.idl
	$(MAKEHEADER) ./idl/nsIWebProgress.idl
	$(MAKEHEADER) ./idl/nsIWebProgressListener.idl
	$(MAKEHEADER) ./idl/nsIWebBrowserChromeFocus.idl
	$(MAKEHEADER) ./idl/nsIBaseWindow.idl
	$(MAKEHEADER) ./idl/nsIEventQueue.idl
	$(MAKEHEADER) ./idl/nsIEventQueueService.idl
	$(MAKEHEADER) ./idl/nsCWebBrowser.idl 

