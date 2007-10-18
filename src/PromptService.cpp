/*
 * PromptService.cpp: Custom prompt dialogs
 *
 * Author:
 *	Andreia Gaita  <avidigal@novell.com>
 *
 * Copyright 2007 Novell, Inc. (http://www.novell.com)
 *
 * See the LICENSE file included with the distribution for details.
 * 
 */

#include "PromptService.h"
#include "BrowserWindow.h"
#include "Widget.h"

NS_IMPL_ISUPPORTS1(PromptService, nsIPromptService)

/* void alert (in nsIDOMWindow parent, in wstring title, in wstring text); */
NS_IMETHODIMP 
PromptService::Alert(nsIDOMWindow *parent, const PRUnichar *title, const PRUnichar *text)
{
	browserWindow->owner->events->OnAlert (title, text);
	return NS_OK;
}

/* boolean alertCheck (in nsIDOMWindow parent, in wstring title, in wstring text, in wstring chkMsg, inout boolean chkState); */
NS_IMETHODIMP 
PromptService::AlertCheck(nsIDOMWindow *parent, const PRUnichar *title, const PRUnichar *text, const PRUnichar *chkMsg, PRBool *chkState)
{
	*chkState = browserWindow->owner->events->OnAlertCheck (title, text, chkMsg, chkState);
	return NS_OK;
}

/* boolean confirm (in nsIDOMWindow parent, in wstring title, in wstring text); */
NS_IMETHODIMP 
PromptService::Confirm(nsIDOMWindow *parent, const PRUnichar *title, const PRUnichar *text, PRBool *retval)
{
	*retval = browserWindow->owner->events->OnConfirm (title, text);
	return NS_OK;
}

/* boolean confirmCheck (in nsIDOMWindow parent, in wstring title, in wstring text, in wstring chkMsg, inout boolean chkState); */
NS_IMETHODIMP 
PromptService::ConfirmCheck(nsIDOMWindow *parent, const PRUnichar *title, const PRUnichar *text, 
							const PRUnichar *chkMsg, PRBool *chkState, PRBool *retval)
{
	*retval = browserWindow->owner->events->OnConfirmCheck (title, text, chkMsg, chkState);
	return NS_OK;
}

/* PRInt32 confirmEx (in nsIDOMWindow parent, in wstring title, in wstring text, 
in unsigned long buttonFlags, in wstring title0, in wstring title1, 
in wstring title2, in wstring chkMsg, inout boolean chkState); */
NS_IMETHODIMP 
PromptService::ConfirmEx(nsIDOMWindow * parent, const PRUnichar * title, const PRUnichar *text, 
						 PRUint32 buttonFlags, const PRUnichar *title0, const PRUnichar *title1, 
						 const PRUnichar * title2, const PRUnichar *chkMsg, PRBool *chkState, 
						 PRInt32 *retval)
{
	*chkState = browserWindow->owner->events->OnConfirmEx (title, text, (DialogButtonFlags)buttonFlags, 
												title0, title1, title2, 
												chkMsg, chkState, retval);
	return NS_OK;
}

/* boolean prompt (in nsIDOMWindow parent, in wstring title, in wstring text, inout wstring value, in wstring chkMsg, inout boolean chkState); */
NS_IMETHODIMP 
PromptService::Prompt(nsIDOMWindow * parent, const PRUnichar * title, 
					  const PRUnichar * text, PRUnichar ** value, 
					  const PRUnichar * chkMsg, PRBool * chkState, 
					  PRBool *retval)
{
	*retval = browserWindow->owner->events->OnPrompt (title, text, value);
	return NS_OK;
}

/* boolean promptUsernameAndPassword (in nsIDOMWindow parent, in wstring title, in wstring text, inout wstring username, inout wstring password, in wstring chkMsg, inout boolean chkState); */
NS_IMETHODIMP 
PromptService::PromptUsernameAndPassword(nsIDOMWindow * parent, const PRUnichar * title, 
										 const PRUnichar * text, PRUnichar ** username, PRUnichar ** password, 
										 const PRUnichar * chkMsg, PRBool * chkState, PRBool * retval)
{
	*retval = browserWindow->owner->events->OnPromptUsernameAndPassword 
						(title, text, chkMsg, chkState,	username, password);
	return NS_OK;
}

/* boolean promptPassword (in nsIDOMWindow parent, in wstring title, in wstring text, inout wstring password, in wstring chkMsg, inout boolean chkState); */
NS_IMETHODIMP 
PromptService::PromptPassword(nsIDOMWindow *parent, const PRUnichar *title, 
							  const PRUnichar *text, PRUnichar **password, 
							  const PRUnichar *chkMsg, PRBool *chkState,
							  PRBool *retval)
{
	*retval = browserWindow->owner->events->OnPromptPassword (title, text, chkMsg, chkState, password);
	return NS_OK;
}

/* boolean select (in nsIDOMWindow parent, in wstring title, in wstring text, in PRUint32 count, [array, size_is (count)] in wstring options, out long selection); */
NS_IMETHODIMP 
PromptService::Select(nsIDOMWindow *parent, const PRUnichar *title, const PRUnichar *text, 
					  PRUint32 count, const PRUnichar **options, 
					  PRInt32 *selection, PRBool *retval)
{
	*retval = browserWindow->owner->events->OnSelect (title, text, count, options, selection);
	return NS_OK;
}

//*****************************************************************************


PromptService::PromptService (BrowserWindow * window) {
	browserWindow = window;
}

NS_IMPL_ISUPPORTS1(PromptServiceFactory, nsIFactory)

PromptServiceFactory::PromptServiceFactory() {
}

PromptServiceFactory::PromptServiceFactory (BrowserWindow * window) {
	browserWindow = window;
}


PromptServiceFactory::~PromptServiceFactory() {
}

NS_IMETHODIMP PromptServiceFactory::CreateInstance(nsISupports *aOuter, const nsIID & aIID, void **aResult)
{
  NS_ENSURE_ARG_POINTER(aResult);
  
  *aResult = NULL;  
  PromptService *inst = new PromptService (browserWindow);    
  if (!inst)
    return NS_ERROR_OUT_OF_MEMORY;
    
  nsresult rv = inst->QueryInterface(aIID, aResult);
  if (rv != NS_OK) {  
    // We didn't get the right interface, so clean up  
    delete inst;  
  }  
    
  return rv;
}

NS_IMETHODIMP PromptServiceFactory::LockFactory(PRBool lock)
{
  return NS_OK;
}

//*****************************************************************************

nsresult NS_NewPromptServiceFactory(nsIFactory** aFactory, BrowserWindow * browserWindow)
{
  NS_ENSURE_ARG_POINTER(aFactory);
  *aFactory = nsnull;
  
  PromptServiceFactory *result = new PromptServiceFactory (browserWindow);
  if (!result)
    return NS_ERROR_OUT_OF_MEMORY;
    
  NS_ADDREF(result);
  *aFactory = result;
  
  return NS_OK;
}
