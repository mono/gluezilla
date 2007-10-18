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


//	NS_XPCOM_COMPONENT_REGISTRY_FILE

    if (strcmp(prop, NS_GRE_DIR) == 0)
		rv = GRE_GetGREDirectory(getter_AddRefs(localFile));

    else if (strcmp(prop, NS_APP_DEFAULTS_50_DIR) == 0)
    {
        rv = GRE_GetGREDirectory(getter_AddRefs(localFile));
        if (NS_SUCCEEDED(rv))
            rv = localFile->AppendRelativeNativePath(DEFAULTS_DIR_NAME);
    }
    else if (strcmp(prop, NS_APP_PREF_DEFAULTS_50_DIR) == 0)
    {
        rv = GRE_GetGREDirectory(getter_AddRefs(localFile));
        if (NS_SUCCEEDED(rv)) {
            rv = localFile->AppendRelativeNativePath(DEFAULTS_DIR_NAME);
            if (NS_SUCCEEDED(rv))
                rv = localFile->AppendRelativeNativePath(DEFAULTS_PREF_DIR_NAME);
        }
    }
    else if (strcmp(prop, NS_APP_PROFILE_DEFAULTS_NLOC_50_DIR) == 0 ||
             strcmp(prop, NS_APP_PROFILE_DEFAULTS_50_DIR) == 0)
	{
        rv = GRE_GetGREDirectory(getter_AddRefs(localFile));
        if (NS_SUCCEEDED(rv)) {
            rv = localFile->AppendRelativeNativePath(DEFAULTS_DIR_NAME);
            if (NS_SUCCEEDED(rv))
                rv = localFile->AppendRelativeNativePath(DEFAULTS_PROFILE_DIR_NAME);
        }
    }
    else if (strcmp(prop, NS_APP_USER_PROFILE_50_DIR) == 0 ||
			 strcmp(prop, NS_APP_PREFS_50_DIR) == 0)
	{
		nsEmbedCString file(widget->startDir);
		rv = NS_NewNativeLocalFile(file, PR_TRUE, getter_AddRefs(localFile));

        if (NS_SUCCEEDED(rv)) {
            rv = localFile->AppendRelativeNativePath(PROFILE_ROOT_DIR_NAME);
            if (NS_SUCCEEDED(rv))
                rv = localFile->AppendRelativeNativePath(DEFAULTS_PROFILE_DIR_NAME);
        }
    }
    else if (strcmp(prop, NS_APP_RES_DIR) == 0)
    {
        rv = GRE_GetGREDirectory(getter_AddRefs(localFile));
        if (NS_SUCCEEDED(rv))
            rv = localFile->AppendRelativeNativePath(RES_DIR_NAME);
    }
    else if (strcmp(prop, NS_APP_CHROME_DIR) == 0)
    {
        rv = GRE_GetGREDirectory(getter_AddRefs(localFile));
        if (NS_SUCCEEDED(rv))
            rv = localFile->AppendRelativeNativePath(CHROME_DIR_NAME);
    }
    else if (strcmp(prop, NS_APP_PLUGINS_DIR) == 0)
    {
        rv = GRE_GetGREDirectory(getter_AddRefs(localFile));
        if (NS_SUCCEEDED(rv))
            rv = localFile->AppendRelativeNativePath(PLUGINS_DIR_NAME);
    }
    else if (strcmp(prop, NS_APP_SEARCH_DIR) == 0)
    {
        rv = GRE_GetGREDirectory(getter_AddRefs(localFile));
        if (NS_SUCCEEDED(rv))
            rv = localFile->AppendRelativeNativePath(SEARCH_DIR_NAME);
    }
	else if (strcmp(prop, NS_GRE_COMPONENT_DIR) == 0 ||
		strcmp(prop, NS_XPCOM_COMPONENT_DIR) == 0)
		//||
		//strcmp(prop, NS_XPCOM_COMPONENT_REGISTRY_FILE) == 0 ||
		//strcmp(prop, NS_XPCOM_XPTI_REGISTRY_FILE) == 0)
	{
		rv = GRE_GetGREDirectory(getter_AddRefs(localFile));
        if (NS_SUCCEEDED(rv))
            rv = localFile->AppendRelativeNativePath(COMPONENTS_DIR_NAME);
	}

	
	
    if (localFile && NS_SUCCEEDED(rv))
        return localFile->QueryInterface(NS_GET_IID(nsIFile), (void**)_retval);
        
    return rv;
}
