/*
 * LocationProvider.cpp: file location provider
 *
 * Author:
 *	Andreia Gaita  <avidigal@novell.com>
 *
 * Copyright 2007 Novell, Inc. (http://www.novell.com)
 *
 * See the LICENSE file included with the distribution for details.
 * 
 */

#include "LocationProvider.h"

#define PROFILE_ROOT_DIR_NAME       nsEmbedCString("Profiles")
#define DEFAULTS_DIR_NAME           nsEmbedCString("defaults")
#define DEFAULTS_PREF_DIR_NAME      nsEmbedCString("pref")
#define DEFAULTS_PROFILE_DIR_NAME   nsEmbedCString("profile")
#define RES_DIR_NAME                nsEmbedCString("res")
#define CHROME_DIR_NAME             nsEmbedCString("chrome")
#define PLUGINS_DIR_NAME            nsEmbedCString("plugins")
#define SEARCH_DIR_NAME             nsEmbedCString("searchplugins")
#define COMPONENTS_DIR_NAME         nsEmbedCString("components")
#if defined(XP_MAC)
#define COMPONENT_REGISTRY_NAME NS_LITERAL_CSTRING("Component Registry")
#define COMPONENT_DIRECTORY     NS_LITERAL_CSTRING("Components")
#else
#define COMPONENT_REGISTRY_NAME NS_LITERAL_CSTRING("compreg.dat")
#define COMPONENT_DIRECTORY     NS_LITERAL_CSTRING("components")
#endif 

#define XPTI_REGISTRY_NAME      NS_LITERAL_CSTRING("xpti.dat")

NS_IMPL_ISUPPORTS1(LocationProvider, nsIDirectoryServiceProvider)

LocationProvider::LocationProvider(Widget * widget)
{
  this->widget = widget;
}

LocationProvider::~LocationProvider()
{
  /* destructor code */
}

/* nsIFile getFile (in string prop, out PRBool persistent); */
NS_IMETHODIMP 
LocationProvider::GetFile(const char *prop, PRBool *persistent, nsIFile **_retval)
{
    nsCOMPtr<nsILocalFile>  localFile;
    nsresult rv = NS_ERROR_FAILURE;

    *_retval = nsnull;
    *persistent = PR_TRUE;


    if (strcmp(prop, NS_GRE_DIR) == 0)
		rv = GetAvailableRuntime (getter_AddRefs(localFile));

    else if (strcmp(prop, NS_APP_DEFAULTS_50_DIR) == 0)
    {
        rv = GetAvailableRuntime (getter_AddRefs(localFile));
        if (NS_SUCCEEDED(rv))
            rv = localFile->AppendRelativeNativePath(DEFAULTS_DIR_NAME);
    }
    else if (strcmp(prop, NS_APP_PREF_DEFAULTS_50_DIR) == 0)
    {
        rv = GetAvailableRuntime (getter_AddRefs(localFile));
        if (NS_SUCCEEDED(rv)) {
            rv = localFile->AppendRelativeNativePath(DEFAULTS_DIR_NAME);
            if (NS_SUCCEEDED(rv))
                rv = localFile->AppendRelativeNativePath(DEFAULTS_PREF_DIR_NAME);
        }
    }
    else if (strcmp(prop, NS_APP_PROFILE_DEFAULTS_NLOC_50_DIR) == 0 ||
             strcmp(prop, NS_APP_PROFILE_DEFAULTS_50_DIR) == 0)
	{
        rv = GetAvailableRuntime (getter_AddRefs(localFile));
        if (NS_SUCCEEDED(rv)) {
            rv = localFile->AppendRelativeNativePath(DEFAULTS_DIR_NAME);
            if (NS_SUCCEEDED(rv))
                rv = localFile->AppendRelativeNativePath(DEFAULTS_PROFILE_DIR_NAME);
        }
    }
    else if (strcmp(prop, NS_APP_USER_PROFILE_50_DIR) == 0 ||
			 strcmp(prop, NS_APP_PREFS_50_DIR) == 0)
	{

        nsCOMPtr<nsIProperties>
          directoryService(do_GetService(NS_DIRECTORY_SERVICE_CONTRACTID, &rv));
        if (NS_FAILED(rv))
            return rv;

        rv = directoryService->Get(NS_APP_USER_PROFILES_ROOT_DIR, NS_GET_IID(nsIFile), getter_AddRefs(localFile));
		
//		nsEmbedCString file(widget->startDir);
//		rv = NS_NewNativeLocalFile(file, PR_TRUE, getter_AddRefs(localFile));

//      if (NS_SUCCEEDED(rv)) {
//          rv = localFile->AppendRelativeNativePath(PROFILE_ROOT_DIR_NAME);
//          if (NS_SUCCEEDED(rv))
//              rv = localFile->AppendRelativeNativePath(DEFAULTS_PROFILE_DIR_NAME);
//      }
    }
    else if (strcmp(prop, NS_APP_RES_DIR) == 0)
    {
        rv = GetAvailableRuntime (getter_AddRefs(localFile));
        if (NS_SUCCEEDED(rv))
            rv = localFile->AppendRelativeNativePath(RES_DIR_NAME);
    }
    else if (strcmp(prop, NS_APP_CHROME_DIR) == 0)
    {
        rv = GetAvailableRuntime (getter_AddRefs(localFile));
        if (NS_SUCCEEDED(rv))
            rv = localFile->AppendRelativeNativePath(CHROME_DIR_NAME);
    }
    //else if (strcmp(prop, NS_APP_PLUGINS_DIR) == 0)
    //{
    //    rv = GetAvailableRuntime (getter_AddRefs(localFile));
    //    if (NS_SUCCEEDED(rv))
    //        rv = localFile->AppendRelativeNativePath(PLUGINS_DIR_NAME);
    //}
    //else if (strcmp(prop, NS_APP_SEARCH_DIR) == 0)
    //{
    //    rv = GetAvailableRuntime (getter_AddRefs(localFile));
    //    if (NS_SUCCEEDED(rv))
    //        rv = localFile->AppendRelativeNativePath(SEARCH_DIR_NAME);
    //}
	else if (strcmp(prop, NS_GRE_COMPONENT_DIR) == 0 ||
		strcmp(prop, NS_XPCOM_COMPONENT_DIR) == 0)
	{
		rv = GetAvailableRuntime (getter_AddRefs(localFile));
        if (NS_SUCCEEDED(rv))
            rv = localFile->AppendRelativeNativePath(COMPONENTS_DIR_NAME);
	}
	else if (strcmp (prop, NS_XPCOM_COMPONENT_REGISTRY_FILE) == 0)
	{
		nsEmbedCString file(widget->dataDir);
		rv = NS_NewNativeLocalFile(file, PR_TRUE, getter_AddRefs(localFile));
		if (NS_SUCCEEDED(rv))
		{
			PRBool exists;
			rv = localFile->AppendNative(COMPONENT_DIRECTORY);
			if (NS_FAILED(rv)) return rv;
			rv = localFile->Exists (&exists);
			if (NS_FAILED(rv)) return rv;
			if (!exists)
				rv = localFile->Create(nsIFile::DIRECTORY_TYPE, 0700);
			if (NS_FAILED(rv)) return rv;
	        rv = localFile->AppendNative(COMPONENT_REGISTRY_NAME);
		}
	}
	else if (strcmp(prop, NS_XPCOM_XPTI_REGISTRY_FILE) == 0)
	{
		nsEmbedCString file(widget->dataDir);
		rv = NS_NewNativeLocalFile(file, PR_TRUE, getter_AddRefs(localFile));
		if (NS_SUCCEEDED(rv))
		{
			PRBool exists;
			rv = localFile->AppendNative(COMPONENT_DIRECTORY);
			if (NS_FAILED(rv)) return rv;
			rv = localFile->Exists (&exists);
			if (NS_FAILED(rv)) return rv;
			if (!exists)
				rv = localFile->Create(nsIFile::DIRECTORY_TYPE, 0700);
			if (NS_FAILED(rv)) return rv;
	        rv = localFile->AppendNative(XPTI_REGISTRY_NAME);           
		}
	}
	
    if (localFile && NS_SUCCEEDED(rv))
        return localFile->QueryInterface(NS_GET_IID(nsIFile), (void**)_retval);
        
    return rv;
}

static char runtimePath[MAX_PATH] = "";

char const * GetAvailableRuntime ()
{
	// we've already done this...
	if (*runtimePath)
		return runtimePath;

#if XUL_VERSION == 2
	const char* xpcomLocation = GRE_GetXPCOMPath();
	if (xpcomLocation)
	{
		strcpy(runtimePath, xpcomLocation);
		return runtimePath;
	}
#endif

	static const GREVersionRange version = {
#if XUL_VERSION == 2
	"1.8", PR_TRUE,
	"1.8", PR_TRUE
#else
	"1.9", PR_TRUE,
	"9.9", PR_TRUE
#endif
	};

	GRE_GetGREPathWithProperties(&version, 1,
							   nsnull, 0,
							   runtimePath, MAX_PATH);
	if (*runtimePath)
		return runtimePath;

	return nsnull;
}

nsresult GetAvailableRuntime(nsILocalFile* *_retval)
{
  NS_ENSURE_ARG_POINTER(_retval);
  nsresult rv = NS_ERROR_FAILURE;

  // Get the path of the GRE which is compatible with our embedding application
  // from the registry

  const char *pGREDir = GetAvailableRuntime ();
  if(!pGREDir)
    return NS_ERROR_FAILURE;

  nsCOMPtr<nsILocalFile> xpcomPath;
  nsEmbedCString leaf(pGREDir);
  rv = NS_NewNativeLocalFile(leaf, PR_TRUE, getter_AddRefs(xpcomPath));

  if (NS_FAILED(rv))
    return rv;

  nsCOMPtr<nsIFile> directory;
  rv = xpcomPath->GetParent(getter_AddRefs(directory));
  if (NS_FAILED(rv))
    return rv;

  return CallQueryInterface(directory, _retval);
}
