#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

CFLAGS=""
AC_PREREQ([2.69])
AC_INIT([majority-element], [1.0])
AM_INIT_AUTOMAKE([dist-xz])
AC_CONFIG_SRCDIR([src/bm_vote.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdio.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T

# Checks for library functions.

# Debug option
AC_ARG_ENABLE(debug,
              AS_HELP_STRING([--enable-debug], [enable debugging, default: no]),
                             [case "${enableval}" in
                                    yes) debug=true ;;
                                    no)  debug=false ;;
                                    *)   AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
                             esac],
                             [debug=false])

AM_CONDITIONAL(DEBUG, test x"$debug" = x"true")

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
