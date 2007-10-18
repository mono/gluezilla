AC_INIT(README)
AC_CANONICAL_SYSTEM

AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE(xulbrowser,0.1)
AM_MAINTAINER_MODE
AC_PROG_CXX
AC_HEADER_STDC
AC_DISABLE_STATIC
AC_PROG_LIBTOOL

PKG_PROG_PKG_CONFIG

AC_MSG_CHECKING(Gtk+ 2.0)
if pkg-config gtk+-2.0; then
   AC_MSG_RESULT(found)
else
   echo Gtk+ 2.0 development kit is missing
   exit 1
fi

AC_MSG_CHECKING(Mono)
if pkg-config mono; then
   AC_MSG_RESULT(found)
else
   echo You are missing Mono
   echo I was looking for mono.pc file
fi

AC_MSG_CHECKING(Mozilla NSPR pkg-config module name)
mozilla_nspr_pcs="nspr mozilla-nspr firefox-nspr xulrunner-nspr seamonkey-nspr"
for pc in $mozilla_nspr_pcs; do
	if $PKG_CONFIG --exists $pc; then
		AC_MSG_RESULT($pc)
		mozilla_nspr=$pc
		break;
	fi
done

if test -z $mozilla_nspr; then
   echo You need to install the Mozilla NSPR development package.
   exit 1
fi

AC_MSG_CHECKING(Mozilla NSS pkg-config module name)
mozilla_nss_pcs="nss mozilla-nss firefox-nss xulrunner-nss seamonkey-nss"
for pc in $mozilla_nss_pcs; do
	if $PKG_CONFIG --exists $pc; then
		AC_MSG_RESULT($pc)
		mozilla_nss=$pc
		break;
	fi
done

if test -z $mozilla_nss; then
   echo You need to install the Mozilla NSS development package.
   exit 1
fi

AC_MSG_CHECKING(Mozilla XPCOM pkg-config module name)
mozilla_xpcom_pcs="xpcom mozilla-xpcom firefox-xpcom xulrunner-xpcom"
for pc in $mozilla_xpcom_pcs; do
	if $PKG_CONFIG --exists $pc; then
		AC_MSG_RESULT($pc)
		mozilla_xpcom=$pc
		break;
	fi
done

if test -z $mozilla_xpcom; then
   echo You need to install the Mozilla XPCOM development package.
   exit 1
fi

AC_ARG_ENABLE([local],
	AC_HELP_STRING([--enable-local], [Use local gecko (build/)]),
		[
			case "${enableval}" in
				yes) local=yes ;;
				no) local=no ;;
				*) AC_MSG_ERROR(bad value ${enableval} for --enable-local) ;;
			esac
		],
		[local=no])

AC_ARG_ENABLE([optimize],
	AC_HELP_STRING([--enable-optimize], [Enable optimizations (-O2)]),
		[
			case "${enableval}" in
				yes) optimize=yes ;;
				no) optimize=no ;;
				*) AC_MSG_ERROR(bad value ${enableval} for --enable-optimize) ;;
			esac
		],
		[optimize=no])


dnl Remember if the user explicity set CXXFLAGS
if test -n "${CXXFLAGS}"; then
	user_set_cxxflags=yes
fi

#if test "$user_set_cxxflags" != yes; then
	autoconf_default_CXXFLAGS="$CXXFLAGS"
	CXXFLAGS=""
	if test "x${optimize}" == xno ; then
		autoconf_default_CXXFLAGS="-g3"
	else
		autoconf_default_CXXFLAGS="-g -O2"
	fi
#fi

AC_SUBST(autoconf_default_CXXFLAGS)


XPIDL=`pkg-config --variable=libdir $mozilla_xpcom`/xpidl
XPFLAGS=-I`pkg-config --variable=includedir $mozilla_xpcom`

AC_SUBST(XPIDL)
AC_SUBST(XPFLAGS)

XPCOM_PKGS="$mozilla_xpcom"
NSPR_PKGS="$mozilla_nspr"

if test "x${local}" != xno ; then
	XULBROWSER_CFLAGS=`pkg-config --cflags gtk+-2.0 $NSPR_PKGS`
	XULBROWSER_CFLAGS="${XULBROWSER_CFLAGS} -I../build/include"
	
	XULBROWSER_LIBS=`pkg-config --libs gtk+-2.0 $NSPR_PKGS`
	
	#XULBROWSER_LIBS="${XULBROWSER_LIBS} -L/code/mozilla/2.0.0.4/tag/firefox-2.0.0.4/mozilla/obj-xulrunner-gtk2/dist/sdk/lib"
	XULBROWSER_LIBS="${EMBED_LIBS} -L../build/lib"
else
	XULBROWSER_CFLAGS=`pkg-config --cflags gtk+-2.0 $XPCOM_PKGS`
	XULBROWSER_LIBS=`pkg-config --libs gtk+-2.0 $NSPR_PKGS`
	XULLIBDIR=`pkg-config --variable=libdir $XPCOM_PKGS`
	XULBROWSER_LIBS="${XULBROWSER_LIBS} -L${XULLIBDIR}"
fi

XULBROWSER_CFLAGS="-DDEBUG -DFORCE_PR_LOG -DXPCOM_GLUE -fno-rtti ${XULBROWSER_CFLAGS}"
XULBROWSER_LIBS="${XULBROWSER_LIBS} -lxpcomglue"


AC_SUBST(XULBROWSER_CFLAGS)
AC_SUBST(XULBROWSER_LIBS)

AC_OUTPUT([
Makefile
xulbrowser/Makefile
tests/browser/Makefile
])
