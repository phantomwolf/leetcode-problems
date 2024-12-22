#!/bin/bash
aclocal \
&& autoheader \
&& autoconf \
&& automake --foreign --add-missing
