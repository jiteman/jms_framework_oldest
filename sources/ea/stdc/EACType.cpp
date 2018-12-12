///////////////////////////////////////////////////////////////////////////////
// EACType.cpp
//
// Copyright (c) 2007 Criterion Software Limited and its licensors. All Rights Reserved.
// Created by Paul Pedriana
///////////////////////////////////////////////////////////////////////////////


#include "ea/stdc/internal/Config.h"
#include "ea/stdc/EACType.h"
#include "ea/asserts/eaassert.h"


// Here we define character types in a simplistic way for the first 
// 256 characters of the Unicode standard. We assume that char16_t refers 
// to a wide unicode character of at least 8 bits (and usually 16 or 32 bits).

#define wctrl  EASTDC_WCTYPE_CONTROL_1
#define wmotn  EASTDC_WCTYPE_MOTION
#define wspac  EASTDC_WCTYPE_SPACE_1
#define wpunc  EASTDC_WCTYPE_PUNCT
#define wdigi  EASTDC_WCTYPE_DIGIT
#define whexd  EASTDC_WCTYPE_XDIGIT
#define wlowc  EASTDC_WCTYPE_LOWER
#define wuppc  EASTDC_WCTYPE_UPPER
#define wdhex  (EASTDC_WCTYPE_XDIGIT | EASTDC_WCTYPE_DIGIT)
#define wlhex  (EASTDC_WCTYPE_XDIGIT | EASTDC_WCTYPE_LOWER)
#define wuhex  (EASTDC_WCTYPE_XDIGIT | EASTDC_WCTYPE_UPPER)


namespace EA
{
namespace StdC
{


EASTDC_API uint8_t EASTDC_WCTYPE_MAP[256] =
{
    wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wmotn, wmotn, wmotn, wmotn, wmotn, wctrl, wctrl,
    wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl,
    wspac, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc,
    wdhex, wdhex, wdhex, wdhex, wdhex, wdhex, wdhex, wdhex, wdhex, wdhex, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc,
    wpunc, wuhex, wuhex, wuhex, wuhex, wuhex, wuhex, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc,
    wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wpunc, wpunc, wpunc, wpunc, wpunc,
    wpunc, wlhex, wlhex, wlhex, wlhex, wlhex, wlhex, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc,
    wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wpunc, wpunc, wpunc, wpunc, wctrl,
    wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl,
    wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl,
    wspac, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wctrl, wpunc, wpunc,
    wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc,
    wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc,
    wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc,
    wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc,
    wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wpunc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc
};


EASTDC_API uint8_t EASTDC_WLOWER_MAP[256] =
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
    ' ',  '!',  '"',  '#',  '$',  '%',  '&',  '\'', '(',  ')',  '*',  '+',  ',',  '-',  '.',  '/',
    '0',  '1',  '2',  '3',  '4',  '5',  '6',  '7',  '8',  '9',  ':',  ';',  '<',  '=',  '>',  '?',
    '@',  'a',  'b',  'c',  'd',  'e',  'f',  'g',  'h',  'i',  'j',  'k',  'l',  'm',  'n',  'o',
    'p',  'q',  'r',  's',  't',  'u',  'v',  'w',  'x',  'y',  'z',  '[',  '\\', ']',  '^',  '_',
    '`',  'a',  'b',  'c',  'd',  'e',  'f',  'g',  'h',  'i',  'j',  'k',  'l',  'm',  'n',  'o',
    'p',  'q',  'r',  's',  't',  'u',  'v',  'w',  'x',  'y',  'z',  '{',  '|',  '}',  '~',  0x7F,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
    0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
    0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
    0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
    0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF
};


EASTDC_API uint8_t EASTDC_WUPPER_MAP[256] =
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
    ' ',  '!',  '"',  '#',  '$',  '%',  '&',  '\'', '(',  ')',  '*',  '+',  ',',  '-',  '.',  '/',
    '0',  '1',  '2',  '3',  '4',  '5',  '6',  '7',  '8',  '9',  ':',  ';',  '<',  '=',  '>',  '?',
    '@',  'A',  'B',  'C',  'D',  'E',  'F',  'G',  'H',  'I',  'J',  'K',  'L',  'M',  'N',  'O',
    'P',  'Q',  'R',  'S',  'T',  'U',  'V',  'W',  'X',  'Y',  'Z',  '[',  '\\', ']',  '^',  '_',
    '`',  'A',  'B',  'C',  'D',  'E',  'F',  'G',  'H',  'I',  'J',  'K',  'L',  'M',  'N',  'O',
    'P',  'Q',  'R',  'S',  'T',  'U',  'V',  'W',  'X',  'Y',  'Z',  '{',  '|',  '}',  '~',  0x7F,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
    0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
    0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
    0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
    0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF
};


} // namespace StdC
} // namespace EA


#undef wctrl
#undef wmotn
#undef wspac
#undef wpunc
#undef wdigi
#undef whexd
#undef wlowc
#undef wuppc
#undef wdhex
#undef wlhex
#undef wuhex










