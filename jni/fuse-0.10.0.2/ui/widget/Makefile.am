## Process this file with automake to produce Makefile.in
## Copyright (c) 2001,2002 Philip Kendall

## $Id: Makefile.am 3624 2008-05-22 17:23:16Z zubzero $

## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License along
## with this program; if not, write to the Free Software Foundation, Inc.,
## 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
##
## Author contact information:
##
## E-mail: philip-fuse@shadowmagic.org.uk

AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = -I$(srcdir)/../..

noinst_LIBRARIES = libwidget.a

libwidget_a_SOURCES = \
	browse.c \
	debugger.c \
	error.c \
	filesel.c \
	memory.c \
	menu.c \
	menu_data.c \
	options.c \
	picture.c \
	pokefinder.c \
	query.c \
	roms.c \
	select.c \
	text.c \
	widget.c

INCLUDES = @GTK_CFLAGS@ @GLIB_CFLAGS@ @LIBSPEC_CFLAGS@ @SDL_CFLAGS@

BUILT_SOURCES = menu_data.c \
		options.c \
		options.h \
		fuse.font

menu_data.c: $(srcdir)/../../perl/cpp-perl.pl $(srcdir)/../../menu_data.dat $(srcdir)/../../menu_data.pl ../../config.h
	@PERL@ $(srcdir)/../../perl/cpp-perl.pl ../../config.h $(srcdir)/../../menu_data.dat | @PERL@ -I$(srcdir)/../../perl $(srcdir)/../../menu_data.pl widget > $@.tmp && mv $@.tmp $@

options.c: $(srcdir)/../../perl/cpp-perl.pl ../../config.h $(srcdir)/options.pl $(srcdir)/../options.dat $(srcdir)/../../perl/Fuse.pm $(srcdir)/../../perl/Fuse/Dialog.pm
	@PERL@ $(srcdir)/../../perl/cpp-perl.pl ../../config.h $(srcdir)/../options.dat | @PERL@ -I$(srcdir)/../../perl $(srcdir)/options.pl - > $@.tmp && mv $@.tmp $@

options.h: $(srcdir)/../../perl/cpp-perl.pl ../../config.h $(srcdir)/options-header.pl $(srcdir)/../options.dat $(srcdir)/../../perl/Fuse.pm $(srcdir)/../../perl/Fuse/Dialog.pm
	@PERL@ $(srcdir)/../../perl/cpp-perl.pl ../../config.h $(srcdir)/../options.dat | @PERL@ -I$(srcdir)/../../perl $(srcdir)/options-header.pl - > $@.tmp && mv $@.tmp $@

fuse.font: $(srcdir)/mkfusefont.pl $(srcdir)/fuse.font.sbf
	@PERL@ $(srcdir)/mkfusefont.pl $(srcdir)/fuse.font.sbf > $@.tmp && mv $@.tmp $@

noinst_HEADERS = widget.h widget_internals.h \
		 options.h options.pl options-header.pl

pkgdata_DATA = fuse.font

EXTRA_DIST = mkfusefont.pl \
	     fuse.font.sbf

CLEANFILES = menu_data.c \
	     options.c \
	     options.h \
	     fuse.font
