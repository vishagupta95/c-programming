#include <stdarg.h>
#include <stdio.h>
#define INT 0
#define STR 1


#define CAT(X,Y) X##_##Y
#define TEMPLATE(X,Y) CAT(X,Y)

/*
 * The goal of macro TEMPLATE(X,Y) is to have a keyword that enables us to concatenate X and Y with an underscore 
 * in between, like this: X_Y, so that writing TEMPLATE(function,type) may translate to function_type.
*/

void foo( int type, ... )
{
    va_list ap;
    int i;
    char *s;
    va_start( ap, type );
    switch( type ) {
    case INT:
        i = va_arg( ap, int );
        printf( "INT: %i\n", i );
        break;
    case STR:
        s = va_arg( ap, char * );
        printf( "STR: %s\n", s );
        break;
    default:
        break;
    }
    va_end( ap );
}
#define SWAP( type, a, b ) {                    \
        type t;                                 \
        t = a;                                  \
        a = b;                                  \
        b = t;                                  \
    }
int main_x( void )
{
    foo( INT, 3 );
    foo( STR, "baz" );
    int ia = 0, ib = 3;
    SWAP( int, ia, ib );
    printf( "%i %i\n", ia, ib );
    float fa = 0.5, fb = 3.14;
    SWAP( float, fa, fb );
    printf( "%f %f\n", fa, fb );
    return 0;
}
define define_list(type) \
\
    struct _list_##type; \
    \
    typedef struct \
    { \
        int (*is_empty)(const struct _list_##type*); \
        size_t (*size)(const struct _list_##type*); \
        const type (*front)(const struct _list_##type*); \
        void (*push_front)(struct _list_##type*, type); \
    } _list_functions_##type; \
    \
    typedef struct _list_elem_##type \
    { \
        type _data; \
        struct _list_elem_##type* _next; \
    } list_elem_##type; \
    \
    typedef struct _list_##type \
    { \
        size_t _size; \
        list_elem_##type* _first; \
        list_elem_##type* _last; \
        _list_functions_##type* _functions; \
    } List_##type; \
    \
    List_##type* new_list_##type(); \
    bool list_is_empty_##type(const List_##type* list); \
    size_t list_size_##type(const List_##type* list); \
    const type list_front_##type(const List_##type* list); \
    void list_push_front_##type(List_##type* list, type elem); \
    \
    bool list_is_empty_##type(const List_##type* list) \
    { \
        return list->_size == 0; \
    } \
    \
    size_t list_size_##type(const List_##type* list) \
    { \
        return list->_size; \
    } \
    \
    const type list_front_##type(const List_##type* list) \
    { \
        return list->_first->_data; \
    } \
    \
    void list_push_front_##type(List_##type* list, type elem) \
    { \
        ... \
    } \
    \
    _list_functions_##type _list_funcs_##type = { \
        &list_is_empty_##type, \
        &list_size_##type, \
        &list_front_##type, \
        &list_push_front_##type, \
    }; \
    \
    List_##type* new_list_##type() \
    { \
        List_##type* res = (List_##type*) malloc(sizeof(List_##type)); \
        res->_size = 0; \
        res->_first = NULL; \
        res->_functions = &_list_funcs_##type; \
        return res; \
    }

#define is_empty(collection) \
    collection->_functions->is_empty(collection)

#define size(collection) \
    collection->_functions->size(collection)

#define front(collection) \
    collection->_functions->front(collection)

#define push_front(collection, elem) \
    collection->_functions->push_front(collection, elem)


#define List(type) \
    List_##type

#define new_list(type) \
    new_list_##type()

/* Define the data structures you need */
#define_list(int)
#define_list(float)

int main()
{
    List(int)* a = new_list(int);
    List(float)* b = new_list(float);

    push_front(a, 5);
    push_front(b, 5.2);
}


