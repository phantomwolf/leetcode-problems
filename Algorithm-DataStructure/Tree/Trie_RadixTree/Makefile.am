bin_PROGRAMS = trie
trie_SOURCES = trie.c
trie_LDADD  = $(GLIB_LIBS)

if DEBUG
AM_CFLAGS 	= -g -std=c99 $(GLIB_CFLAGS) -pipe -Wall
AM_CXXFLAGS = -g -std=c++11 $(GLIB_CFLAGS) -pipe -Wall
else
AM_CFLAGS 	= -O2 -std=c99 $(GLIB_CFLAGS) -pipe
AM_CXXFLAGS = -O2 -std=c++11 $(GLIB_CFLAGS) -pipe
endif
