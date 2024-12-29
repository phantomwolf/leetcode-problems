#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([trie.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
CFLAGS=""
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES([GLIB], [glib-2.0 >= 2.24.1])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset])

# debug option
AC_ARG_ENABLE(debug,
              AS_HELP_STRING([--enable-debug], [enable debugging, default: no]),
              [case "${enableval}" in
                    yes) debug=true ;;
                    no)  debug=false ;;
                    *)   AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
              esac],
              [debug=false])

AM_CONDITIONAL(DEBUG, test x"$debug" = x"true")

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
