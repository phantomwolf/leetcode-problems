#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([simple-hashing], [1.0])
AM_INIT_AUTOMAKE([dist-xz])
AC_CONFIG_SRCDIR([integer_hash.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
CFLAGS=""
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
