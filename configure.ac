AC_INIT(README)
AC_CANONICAL_SYSTEM

AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE(gluezilla,2.4)
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

AC_MSG_CHECKING(Mozilla NSPR)
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

AC_MSG_CHECKING(Mozilla NSS)
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

AC_ARG_ENABLE([xulrunner-1.8],
	AC_HELP_STRING([--enable-xulrunner-1.8], [Force use of xulrunner 1.8]),
		[
			case "${enableval}" in
				yes) oldxul=yes ;;
				no) oldxul=no ;;
				*) AC_MSG_ERROR(bad value ${enableval} for --enable-xulrunner-1.8) ;;
			esac
		],
		[oldxul=no])


XPCOM_PKGS=""
XUL_VERSION=2

if test "x${local}" == xno ; then

	if test "x${oldxul}" != xyes ; then

		AC_MSG_CHECKING(Mozilla XPCOM > 1.8)
		mozilla_xpcom_pcs="libxul-embedding-unstable"
		for pc in $mozilla_xpcom_pcs; do
			if $PKG_CONFIG --exists $pc; then
				AC_MSG_RESULT($pc)
				mozilla_xpcom=$pc
				XUL_VERSION=3
				break;
			fi
		done
	fi

	if test -z $mozilla_xpcom; then
		AC_MSG_RESULT(not found)
		AC_MSG_CHECKING(Mozilla XPCOM 1.8)
		mozilla_xpcom_pcs="xpcom mozilla-xpcom firefox-xpcom xulrunner-xpcom"
		for pc in $mozilla_xpcom_pcs; do
			if $PKG_CONFIG --exists $pc; then
				AC_MSG_RESULT($pc)
				mozilla_xpcom=$pc
				XUL_VERSION=2
				break;
			fi
		done
	fi

	if test -z $mozilla_xpcom; then
		echo You need to install the Mozilla XPCOM development package.
		exit 1
	fi
	
	XPCOM_PKGS="$mozilla_xpcom"
fi

AM_CONDITIONAL([OLDXUL], [test x$XUL_VERSION = x2])

AC_SUBST(XUL_VERSION)

AC_ARG_ENABLE([optimize],
	AC_HELP_STRING([--enable-optimize], [Enable optimizations (-O2)]),
		[
			case "${enableval}" in
				yes) optimize=yes ;;
				no) optimize=no ;;
				*) AC_MSG_ERROR(bad value ${enableval} for --enable-optimize) ;;
			esac
		],
		[optimize=yes])


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


NSPR_PKGS="$mozilla_nspr"

if test "x${local}" != xno ; then
	GLUEZILLA_CFLAGS=`pkg-config --cflags gtk+-2.0 gthread-2.0 $NSPR_PKGS`
	GLUEZILLA_CFLAGS="${GLUEZILLA_CFLAGS} -I../build/include"
	
	GLUEZILLA_LIBS=`pkg-config --libs gtk+-2.0 gthread-2.0 $NSPR_PKGS`
	
	GLUEZILLA_LIBS="${GLUEZILLA_LIBS} -L../build/lib"
else
	GLUEZILLA_CFLAGS=`pkg-config --cflags gtk+-2.0 gthread-2.0 $XPCOM_PKGS $NSPR_PKGS`
	GLUEZILLA_LIBS=`pkg-config --libs gtk+-2.0 gthread-2.0 $NSPR_PKGS`
	XULLIBDIR=`pkg-config --libs-only-L $XPCOM_PKGS`
	GLUEZILLA_LIBS="${GLUEZILLA_LIBS} ${XULLIBDIR}"
fi

if test "x${optimize}" == xno ; then
	GLUEZILLA_CFLAGS="-DDEBUG -DFORCE_PR_LOG ${GLUEZILLA_CFLAGS}"
fi
GLUEZILLA_CFLAGS="-DXPCOM_GLUE -DXPCOM_GLUE_NEEDS_NSPR -fno-rtti -fshort-wchar ${GLUEZILLA_CFLAGS}"
GLUEZILLA_LIBS="${GLUEZILLA_LIBS} -lxpcomglue"


AC_SUBST(GLUEZILLA_CFLAGS)
AC_SUBST(GLUEZILLA_LIBS)

AC_OUTPUT([
Makefile
build/Makefile
src/Makefile
tests/browser/Makefile
])
