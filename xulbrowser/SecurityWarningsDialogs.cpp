/*
 * SecurityWarningsDialogs.cpp: Custom security warning dialogs
 *
 * Author:
 *	Andreia Gaita  <avidigal@novell.com>
 *
 * Copyright 2007 Novell, Inc. (http://www.novell.com)
 *
 * See the LICENSE file included with the distribution for details.
 * 
 */

#include "SecurityWarningsDialogs.h"

//static HINSTANCE gInstance;

NS_IMPL_ISUPPORTS1(SecurityWarningDialogs, nsISecurityWarningDialogs)


/* boolean confirmEnteringSecure (in nsIInterfaceRequestor ctx); */
NS_IMETHODIMP SecurityWarningDialogs::ConfirmEnteringSecure(nsIInterfaceRequestor *ctx, PRBool *_retval)
{
    return PR_TRUE;
}

/* boolean confirmEnteringWeak (in nsIInterfaceRequestor ctx); */
NS_IMETHODIMP SecurityWarningDialogs::ConfirmEnteringWeak(nsIInterfaceRequestor *ctx, PRBool *_retval)
{
    return PR_TRUE;
}

/* boolean confirmLeavingSecure (in nsIInterfaceRequestor ctx); */
NS_IMETHODIMP SecurityWarningDialogs::ConfirmLeavingSecure(nsIInterfaceRequestor *ctx, PRBool *_retval)
{
    return PR_TRUE;
}

/* boolean confirmMixedMode (in nsIInterfaceRequestor ctx); */
NS_IMETHODIMP SecurityWarningDialogs::ConfirmMixedMode(nsIInterfaceRequestor *ctx, PRBool *_retval)
{
    return PR_TRUE;
}

/* boolean confirmPostToInsecure (in nsIInterfaceRequestor ctx); */
NS_IMETHODIMP SecurityWarningDialogs::ConfirmPostToInsecure(nsIInterfaceRequestor *ctx, PRBool *_retval)
{
    return PR_TRUE;
}

/* boolean confirmPostToInsecureFromSecure (in nsIInterfaceRequestor ctx); */
NS_IMETHODIMP SecurityWarningDialogs::ConfirmPostToInsecureFromSecure(nsIInterfaceRequestor *ctx, PRBool *_retval)
{
    return PR_TRUE;
}



//*****************************************************************************

NS_IMPL_ISUPPORTS1(SecurityWarningServiceFactory, nsIFactory)

SecurityWarningServiceFactory::SecurityWarningServiceFactory() {
}

SecurityWarningServiceFactory::~SecurityWarningServiceFactory() {
}

NS_IMETHODIMP SecurityWarningServiceFactory::CreateInstance(nsISupports *aOuter, const nsIID & aIID, void **aResult)
{
  NS_ENSURE_ARG_POINTER(aResult);
  
  *aResult = NULL;  
  SecurityWarningDialogs *inst = new SecurityWarningDialogs;    
  if (!inst)
    return NS_ERROR_OUT_OF_MEMORY;
    
  nsresult rv = inst->QueryInterface(aIID, aResult);
  if (rv != NS_OK) {  
    // We didn't get the right interface, so clean up  
    delete inst;  
  }  
    
  return rv;
}

NS_IMETHODIMP SecurityWarningServiceFactory::LockFactory(PRBool lock)
{
  return NS_OK;
}

//*****************************************************************************

nsresult NS_NewSecurityWarningServiceFactory(nsIFactory** aFactory)
{
  NS_ENSURE_ARG_POINTER(aFactory);
  *aFactory = nsnull;
  
  SecurityWarningServiceFactory *result = new SecurityWarningServiceFactory;
  if (!result)
    return NS_ERROR_OUT_OF_MEMORY;
    
  NS_ADDREF(result);
  *aFactory = result;
  
  return NS_OK;
}
