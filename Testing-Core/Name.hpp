#pragma once
#include <string>
#include <list>
#include <cstdint>
#include "Hash.hpp"

//==========================================================================
using std::list;
using std::string;
using std::to_string;

//==========================================================================
#ifdef _DEBUG
// Force name strings to stick around for human-friendly debugging purposes.
#define ENABLE_NAME_STORAGE
#endif

//==========================================================================
struct Name
{
public:

    static const Name Null;

    Name() 
        : m_String( nullptr )
        , m_Length( 0 )
        , m_Hash( 0 ) 
    {}

    template < size_t N >
    constexpr Name( const char( &C )[ N ] )
        : m_String( C )
        , m_Length( N - 1 )
        , m_Hash( crc32_cpt< N >( C ) )
    {}

    constexpr Name( const char* C, size_t N, crc32_t H )
        : m_String( C )
        , m_Length( int32_t( N ) )
        , m_Hash( H )
    {}

    Name( char* a_String )
        : m_String( a_String )
        , m_Length( a_String ? ( int32_t( strlen( a_String ) ) ) : 0 )
        , m_Hash( a_String ? crc32_impl< sizeof( const char* ) >( a_String ) : 0 )
    {
#ifdef ENABLE_NAME_STORAGE
        if ( a_String )
        {
            GetNameStorage().push_back( a_String );
            m_String = GetNameStorage().back().c_str();
        }
#endif
    }

    Name( char* a_String, size_t a_Length )
        : m_String( a_String )
        , m_Length( int32_t( a_Length ) )
        , m_Hash( crc32_impl< sizeof( const char* ) >( a_String ) )
    {
#ifdef ENABLE_NAME_STORAGE
        GetNameStorage().push_back( a_String );
        m_String = GetNameStorage().back().c_str();
#endif
    }

    Name( const string& a_String )
        : m_String( a_String.c_str() )
        , m_Length( int32_t( a_String.length() ) )
        , m_Hash( crc32_impl< sizeof( const char* ) >( m_String ) )
    {
#ifdef ENABLE_NAME_STORAGE
        GetNameStorage().push_back(a_String);
        m_String = GetNameStorage().back().c_str();
#endif
    }

    Name( crc32_t a_Hash )
        : m_Hash( a_Hash )
        , m_String( 0 )
        , m_Length( 0 )
    {
        m_String = "NameFromDynamicHash";
        m_Length = int32_t( strlen( m_String ) );
    }

    operator string() const { return string( m_String, m_Length ); }
    operator crc32_t() const { return m_Hash; }
    operator const char*() const { return m_String; }
    constexpr char operator []( size_t a_Pos ) { return m_String[ a_Pos ]; }

    constexpr const char* Data() const { return m_String; }
    constexpr int32_t Length() const { return m_Length; }
    constexpr crc32_t Hash() const { return m_Hash; }

    constexpr bool operator==( crc32_t a_CRC32 ) const
    {
        return m_Hash == a_CRC32;
    }

    constexpr bool operator==( const Name& a_Name ) const
    {
        return m_Hash == a_Name.m_Hash;
    }

    constexpr bool operator!=( crc32_t a_CRC32 ) const
    {
        return m_Hash != a_CRC32;
    }

    constexpr bool operator!=( const Name& a_Name ) const
    {
        return m_Hash != a_Name.m_Hash;
    }

private:

#ifdef ENABLE_NAME_STORAGE
    static list< string >& GetNameStorage()
    {
        static list< string > s_NameStorage; return s_NameStorage;
    }
#endif

    const char* m_String;
    int32_t m_Length;
    crc32_t m_Hash;
};

constexpr Name operator ""_N( const char* C, size_t N )
{
    return Name( C, N, crc32_impl2( C, N - 1 ) ^ 0xFFFFFFFF );
}

namespace std
{
    template<>
	struct hash< Name >
	{
		inline size_t operator()( const Name& a_Value ) const
		{
            return a_Value.Hash();
		}
	};
}