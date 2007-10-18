mono_webbrowser_mozilladir=$(pkglibdir)
mono_webbrowser_mozilla_SCRIPTS = Mono.WebBrowser.Mozilla.dll

EXTRA_DIST = $(mono_webbrowser_mozilla_sources) $(mono_webbrowser_mozilla_sources_in)
CLEANFILES = Mono.WebBrowser.Mozilla.dll
DISTCLEANFILES = AssemblyInfo.cs Makefile.in

mono_webbrowser_mozilla_sources_in = AssemblyInfo.cs.in
mono_webbrowser_mozilla_generated_sources = $(mono_webbrowser_mozilla_sources_in:.in=)
mono_webbrowser_mozilla_sources = \
	MozillaInvoke.cs \
	Callback.cs \
	Delegates.cs \
	IWebBrowser.cs \
	Structs.cs
	

mono_webbrowser_mozilla_build_sources = $(addprefix $(srcdir)/, $(mono_webbrowser_mozilla_sources))
mono_webbrowser_mozilla_build_sources += $(mono_webbrowser_mozilla_generated_sources)

Mono.WebBrowser.Mozilla.dll: $(mono_webbrowser_mozilla_build_sources)
	$(MCS) -target:library -out:$@ $(mono_webbrowser_mozilla_build_sources)
