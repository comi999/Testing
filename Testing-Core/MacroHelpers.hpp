#pragma once

#define GET_MACRO_1(_1, x, ...) x
#define GET_MACRO_2(_1, _2, x, ...) x
#define GET_MACRO_3(_1, _2, _3, x, ...) x
#define GET_MACRO_4(_1, _2, _3, _4, x, ...) x
#define GET_MACRO_5(_1, _2, _3, _4, _5, x, ...) x
#define GET_MACRO_6(_1, _2, _3, _4, _5, _6, x, ...) x
#define GET_MACRO_7(_1, _2, _3, _4, _5, _6, _7, x, ...) x
#define GET_MACRO_8(_1, _2, _3, _4, _5, _6, _7, _8, x, ...) x
#define GET_MACRO_9(_1, _2, _3, _4, _5, _6, _7, _8, _9, x, ...) x
#define GET_MACRO_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, x, ...) x
#define GET_MACRO_11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, x, ...) x
#define GET_MACRO_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, x, ...) x
#define GET_MACRO_13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, x, ...) x
#define GET_MACRO_14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, x, ...) x
#define GET_MACRO_15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, x, ...) x
#define GET_MACRO_16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, x, ...) x
#define GET_MACRO_17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, x, ...) x
#define GET_MACRO_18(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, x, ...) x
#define GET_MACRO_19(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, x, ...) x
#define GET_MACRO_20(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, x, ...) x
#define EXPAND(x) x

#define GET_FIRST_1(_1) _1
#define GET_FIRST_N(_1, ...) _1
#define GET_FIRST(...) EXPAND(GET_MACRO_20(__VA_ARGS__, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_N, \
GET_FIRST_1  )(__VA_ARGS__))

#define GET_NOT_FIRST_1(_1)
#define GET_NOT_FIRST_N(_1, ...) __VA_ARGS__
#define GET_NOT_FIRST(...) EXPAND(GET_MACRO_20(__VA_ARGS__, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_N, \
GET_NOT_FIRST_1  )(__VA_ARGS__))

#define GET_LAST_1(_1) _1
#define GET_LAST_2(_1, _2) _2
#define GET_LAST_3(_1, _2, _3) _3
#define GET_LAST_4(_1, _2, _3, _4) _4
#define GET_LAST_5(_1, _2, _3, _4, _5) _5
#define GET_LAST_6(_1, _2, _3, _4, _5, _6) _6
#define GET_LAST_7(_1, _2, _3, _4, _5, _6, _7) _7
#define GET_LAST_8(_1, _2, _3, _4, _5, _6, _7, _8) _8
#define GET_LAST_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) _9
#define GET_LAST_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10) _10
#define GET_LAST_11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) _11
#define GET_LAST_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) _12
#define GET_LAST_13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) _13
#define GET_LAST_14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) _14
#define GET_LAST_15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) _15
#define GET_LAST_16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) _16
#define GET_LAST_17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) _17
#define GET_LAST_18(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) _18
#define GET_LAST_19(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) _19
#define GET_LAST_20(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20) _20
#define GET_LAST(...) EXPAND(GET_MACRO_20(__VA_ARGS__, \
GET_LAST_20, \
GET_LAST_19, \
GET_LAST_18, \
GET_LAST_17, \
GET_LAST_16, \
GET_LAST_15, \
GET_LAST_14, \
GET_LAST_13, \
GET_LAST_12, \
GET_LAST_11, \
GET_LAST_10, \
GET_LAST_9, \
GET_LAST_8, \
GET_LAST_7, \
GET_LAST_6, \
GET_LAST_5, \
GET_LAST_4, \
GET_LAST_3, \
GET_LAST_2, \
GET_LAST_1  )(__VA_ARGS__))

#define GET_NOT_LAST_1(_1)
#define GET_NOT_LAST_2(_1, _2) _1
#define GET_NOT_LAST_3(_1, _2, _3) _1, _2
#define GET_NOT_LAST_4(_1, _2, _3, _4) _1, _2, _3
#define GET_NOT_LAST_5(_1, _2, _3, _4, _5) _1, _2, _3, _4
#define GET_NOT_LAST_6(_1, _2, _3, _4, _5, _6) _1, _2, _3, _4, _5
#define GET_NOT_LAST_7(_1, _2, _3, _4, _5, _6, _7) _1, _2, _3, _4, _5, _6
#define GET_NOT_LAST_8(_1, _2, _3, _4, _5, _6, _7, _8) _1, _2, _3, _4, _5, _6, _7
#define GET_NOT_LAST_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) _1, _2, _3, _4, _5, _6, _7, _8
#define GET_NOT_LAST_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10) _1, _2, _3, _4, _5, _6, _7, _8, _9
#define GET_NOT_LAST_11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) _1, _2, _3, _4, _5, _6, _7, _8, _9, _10
#define GET_NOT_LAST_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11
#define GET_NOT_LAST_13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12
#define GET_NOT_LAST_14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13
#define GET_NOT_LAST_15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14
#define GET_NOT_LAST_16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15
#define GET_NOT_LAST_17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16
#define GET_NOT_LAST_18(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17
#define GET_NOT_LAST_19(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18
#define GET_NOT_LAST_20(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20) _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19
#define GET_NOT_LAST(...) EXPAND(GET_MACRO_20(__VA_ARGS__, \
GET_NOT_LAST_20, \
GET_NOT_LAST_19, \
GET_NOT_LAST_18, \
GET_NOT_LAST_17, \
GET_NOT_LAST_16, \
GET_NOT_LAST_15, \
GET_NOT_LAST_14, \
GET_NOT_LAST_13, \
GET_NOT_LAST_12, \
GET_NOT_LAST_11, \
GET_NOT_LAST_10, \
GET_NOT_LAST_9, \
GET_NOT_LAST_8, \
GET_NOT_LAST_7, \
GET_NOT_LAST_6, \
GET_NOT_LAST_5, \
GET_NOT_LAST_4, \
GET_NOT_LAST_3, \
GET_NOT_LAST_2, \
GET_NOT_LAST_1  )(__VA_ARGS__))

#define GET_REVERSED_1(...) __VA_ARGS__
#define GET_REVERSED_2(...) GET_LAST(__VA_ARGS__), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_3(...) GET_LAST(__VA_ARGS__), GET_REVERSED_1(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_4(...) GET_LAST(__VA_ARGS__), GET_REVERSED_2(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_5(...) GET_LAST(__VA_ARGS__), GET_REVERSED_3(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_6(...) GET_LAST(__VA_ARGS__), GET_REVERSED_4(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_7(...) GET_LAST(__VA_ARGS__), GET_REVERSED_5(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_8(...) GET_LAST(__VA_ARGS__), GET_REVERSED_6(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_9(...) GET_LAST(__VA_ARGS__), GET_REVERSED_7(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_10(...) GET_LAST(__VA_ARGS__), GET_REVERSED_8(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_11(...) GET_LAST(__VA_ARGS__), GET_REVERSED_9(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_12(...) GET_LAST(__VA_ARGS__), GET_REVERSED_10(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_13(...) GET_LAST(__VA_ARGS__), GET_REVERSED_11(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_14(...) GET_LAST(__VA_ARGS__), GET_REVERSED_12(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_15(...) GET_LAST(__VA_ARGS__), GET_REVERSED_13(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_16(...) GET_LAST(__VA_ARGS__), GET_REVERSED_14(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_17(...) GET_LAST(__VA_ARGS__), GET_REVERSED_15(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_18(...) GET_LAST(__VA_ARGS__), GET_REVERSED_16(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_19(...) GET_LAST(__VA_ARGS__), GET_REVERSED_17(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED_20(...) GET_LAST(__VA_ARGS__), GET_REVERSED_18(GET_NOT_LAST(GET_NOT_FIRST(__VA_ARGS__))), GET_FIRST(__VA_ARGS__)
#define GET_REVERSED(...) EXPAND(GET_MACRO_20(__VA_ARGS__, \
GET_REVERSED_20, \
GET_REVERSED_19, \
GET_REVERSED_18, \
GET_REVERSED_17, \
GET_REVERSED_16, \
GET_REVERSED_15, \
GET_REVERSED_14, \
GET_REVERSED_13, \
GET_REVERSED_12, \
GET_REVERSED_11, \
GET_REVERSED_10, \
GET_REVERSED_9, \
GET_REVERSED_8, \
GET_REVERSED_7, \
GET_REVERSED_6, \
GET_REVERSED_5, \
GET_REVERSED_4, \
GET_REVERSED_3, \
GET_REVERSED_2, \
GET_REVERSED_1  )(__VA_ARGS__))