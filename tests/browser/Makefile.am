testdir=$(pkglibdir)
test_SCRIPTS = test.exe

EXTRA_DIST = $(test_sources) $(test_sources_in)
CLEANFILES = test.exe
DISTCLEANFILES = AssemblyInfo.cs Makefile.in

test_sources_in = AssemblyInfo.cs.in
test_generated_sources = $(test_sources_in:.in=)
test_sources = \
	Main.cs \
	Form1.Designer.cs
	

test_build_sources = $(addprefix $(srcdir)/, $(test_sources))
test_build_sources += $(test_generated_sources)

test.exe: $(test_build_sources)
	cp ../../xulbrowser/.libs/libxulbrowser.* .
	gmcs -debug -pkg:dotnet -r:Mono.Mozilla.dll -target:exe -out:$@ $(test_build_sources)

run: test.exe
	cp ../../xulbrowser/.libs/libxulbrowser.* .
	mono --debug test.exe
