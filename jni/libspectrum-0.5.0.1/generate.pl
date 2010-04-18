if( /LIBSPECTRUM_DEFINE_TYPES/ ) {

  $_ = << "CODE";
#include <stdint.h>

typedef  uint8_t libspectrum_byte;
typedef   int8_t libspectrum_signed_byte;
typedef uint16_t libspectrum_word;
typedef  int16_t libspectrum_signed_word;
typedef uint32_t libspectrum_dword;
typedef  int32_t libspectrum_signed_dword;
typedef uint64_t libspectrum_qword;
typedef  int64_t libspectrum_signed_qword;
CODE
}

if( /LIBSPECTRUM_GLIB_REPLACEMENT/ ) {

  $_ = << "CODE";
#ifndef	FALSE
#define	FALSE	(0)
#endif

#ifndef	TRUE
#define	TRUE	(!FALSE)
#endif

typedef char gchar;
typedef int gint;
typedef long glong;
typedef gint gboolean;
typedef unsigned int guint;
typedef const void * gconstpointer;
typedef void * gpointer;

typedef struct _GSList GSList;

struct _GSList {
    gpointer data;
    GSList *next;
};

typedef void		(*GFunc)		(gpointer	data,
						 gpointer	user_data);

typedef gint		(*GCompareFunc)		(gconstpointer	a,
						 gconstpointer	b);


GSList WIN32_DLL *g_slist_insert_sorted	(GSList		*list,
						 gpointer	 data,
						 GCompareFunc	 func);

GSList WIN32_DLL *g_slist_insert		(GSList		*list,
			 			 gpointer	 data,
			 			 gint		 position);

GSList WIN32_DLL *g_slist_append		(GSList		*list,
						 gpointer	 data);

GSList WIN32_DLL *g_slist_prepend		(GSList		*list,
						 gpointer	 data);

GSList WIN32_DLL *g_slist_remove		(GSList		*list,
						 gpointer	 data);

GSList WIN32_DLL *g_slist_delete_link		(GSList		*list,
				 		 GSList		*link);

guint	WIN32_DLL g_slist_length		(GSList *list);

void	WIN32_DLL g_slist_foreach		(GSList		*list,
						 GFunc		 func,
						 gpointer	 user_data);

void	WIN32_DLL g_slist_free			(GSList		*list);

GSList WIN32_DLL *g_slist_nth		(GSList		*list,
					 guint		n);

GSList WIN32_DLL * g_slist_find_custom	(GSList		*list,
					 gpointer	data,
					 GCompareFunc	func );

gint	WIN32_DLL g_slist_position	(GSList		*list,
					 GSList		*llink);

typedef struct _GHashTable	GHashTable;

typedef guint		(*GHashFunc)		(gconstpointer	key);

typedef gboolean	(*GHRFunc)		(gpointer	key,
						 gpointer	value,
						 gpointer	user_data);

gint	WIN32_DLL g_int_equal (gconstpointer   v,
			       gconstpointer   v2);
guint	WIN32_DLL g_int_hash  (gconstpointer   v);

gint	WIN32_DLL g_str_equal (gconstpointer   v,
			       gconstpointer   v2);
guint	WIN32_DLL g_str_hash  (gconstpointer   v);

GHashTable WIN32_DLL *g_hash_table_new	(GHashFunc	 hash_func,
					 GCompareFunc	 key_compare_func);

void	WIN32_DLL g_hash_table_destroy	(GHashTable	*hash_table);

void	WIN32_DLL g_hash_table_insert	(GHashTable	*hash_table,
					 gpointer	 key,
					 gpointer	 value);

gpointer WIN32_DLL g_hash_table_lookup	(GHashTable	*hash_table,
					 gconstpointer	 key);

guint	WIN32_DLL g_hash_table_foreach_remove	(GHashTable	*hash_table,
						 GHRFunc	 func,
						 gpointer	 user_data);

guint	WIN32_DLL g_hash_table_size (GHashTable	*hash_table);

typedef struct _GArray GArray;

struct _GArray {
  /* Public */
  gchar *data;
  size_t len;

  /* Private */
  guint element_size;
  size_t allocated;
};

GArray* WIN32_DLL g_array_new( gboolean zero_terminated, gboolean clear,
		      guint element_size );
#define g_array_append_val(a,v) g_array_append_vals( a, &(v), 1 );
GArray* WIN32_DLL g_array_append_vals( GArray *array, gconstpointer data, guint len );
#define g_array_index(a,t,i) (*(((t*)a->data)+i))
GArray* WIN32_DLL g_array_set_size( GArray *array, guint length );

#define GINT_TO_POINTER(i)      ((gpointer)  (i))
#define GPOINTER_TO_INT(p)      ((gint)   (p))
CODE
}

if( /LIBSPECTRUM_INCLUDE_GCRYPT/ ) {

  $_ = '';

}

if( /LIBSPECTRUM_SIGNATURE_PARAMETERS/ ) {

  $_ = "/* Signature parameters not stored as libgcrypt is not present */
";

}

if( /LIBSPECTRUM_CAPABILITIES/ ) {

  $_ = << "CODE";

/* we support snapshots etc. requiring zlib (e.g. compressed szx) */
#define	LIBSPECTRUM_SUPPORTS_ZLIB_COMPRESSION	(1)
CODE
}

BEGIN {

  $srcdir = shift;

};

if( /LIBSPECTRUM_SNAP_ACCESSORS/ ) {

  open( DATAFILE, '<' . "${srcdir}/snap_accessors.txt" ) or die "Couldn't open `snap_accessors.txt': $!";

  $_ = '';
  while( <DATAFILE> ) {

    next if /^\s*$/; next if /^\s*#/;

    my( $type, $name, $indexed ) = split;

    my $return_type;
    if( $type =~ /^(.*)\*/ ) {
	$return_type = "$1 WIN32_DLL *";
    } else {
	$return_type = "$type WIN32_DLL";
    }

    if( $indexed ) {

	print << "CODE";
$return_type libspectrum_snap_$name( libspectrum_snap *snap, int idx );
void WIN32_DLL libspectrum_snap_set_$name( libspectrum_snap *snap, int idx, $type $name );
CODE

    } else {

	print << "CODE";
$return_type libspectrum_snap_$name( libspectrum_snap *snap );
void WIN32_DLL libspectrum_snap_set_$name( libspectrum_snap *snap, $type $name );
CODE

    }
  }
}

if( /LIBSPECTRUM_TAPE_ACCESSORS/ ) {

    open( DATAFILE, '<' . "${srcdir}/tape_accessors.txt" )
	or die "Couldn't open `tape_accessors.txt': $!";

    $_ = '';
    while( <DATAFILE> ) {

	# Remove comments and blank lines
	s/#.*//;
	next if /^\s*$/;

	# Skip which block types each accessor applies to
	next if /^\s/;
	
	my( $type, $name, $indexed, undef ) = split;
	
	my $return_type;
	if( $type =~ /^(.*)\*/ ) {
	    $return_type = "$1 WIN32_DLL *";
	} else {
	    $return_type = "$type WIN32_DLL";
	}

	if( $indexed ) {

	  print << "CODE";
$return_type libspectrum_tape_block_$name( libspectrum_tape_block *block, size_t idx );
libspectrum_error WIN32_DLL libspectrum_tape_block_set_$name( libspectrum_tape_block *block, $type \*$name );
CODE

	} else {

	print << "CODE";
$return_type libspectrum_tape_block_$name( libspectrum_tape_block *block );
libspectrum_error WIN32_DLL libspectrum_tape_block_set_$name( libspectrum_tape_block *block, $type $name );
CODE
    
	}
    }

    close DATAFILE or die "Couldn't close `tape_accessors.txt': $!";
}
