/*************************************************************************/
/*  shift_jis.h                                                          */
/*************************************************************************/
/*                       This file is part of:                           */
/*                  SHINOBU ENGINE ANIMATION MODULE                      */
/*                      https://ph.eirteam.moe                           */
/*************************************************************************/
/* Copyright (c) 2007-2021 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2021 Godot Engine contributors (cf. AUTHORS.md).   */
/* Copyright (c) 2021 Álex Román Núñez (EIRTeam)                         */
/* Copyright (c) 2021 lox9973                                            */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef SHIFT_JIS_H
#define SHIFT_JIS_H
#include "shift_jis_table.h"
#include <string>

// From: https://stackoverflow.com/a/33170901

static std::string sj2utf8(const std::string &input) {
	std::string output(3 * input.length(), ' '); //ShiftJis won't give 4byte UTF8, so max. 3 byte per input char are needed
	size_t indexInput = 0, indexOutput = 0;

	while (indexInput < input.length()) {
		char arraySection = ((uint8_t)input[indexInput]) >> 4;

		size_t arrayOffset;
		if (arraySection == 0x8)
			arrayOffset = 0x100; //these are two-byte shiftjis
		else if (arraySection == 0x9)
			arrayOffset = 0x1100;
		else if (arraySection == 0xE)
			arrayOffset = 0x2100;
		else
			arrayOffset = 0; //this is one byte shiftjis

		//determining real array offset
		if (arrayOffset) {
			arrayOffset += (((uint8_t)input[indexInput]) & 0xf) << 8;
			indexInput++;
			if (indexInput >= input.length())
				break;
		}
		arrayOffset += (uint8_t)input[indexInput++];
		arrayOffset <<= 1;

		//unicode number is...
		uint16_t unicodeValue = (shiftJIS_convTable[arrayOffset] << 8) | shiftJIS_convTable[arrayOffset + 1];

		//converting to UTF8
		if (unicodeValue < 0x80) {
			output[indexOutput++] = unicodeValue;
		} else if (unicodeValue < 0x800) {
			output[indexOutput++] = 0xC0 | (unicodeValue >> 6);
			output[indexOutput++] = 0x80 | (unicodeValue & 0x3f);
		} else {
			output[indexOutput++] = 0xE0 | (unicodeValue >> 12);
			output[indexOutput++] = 0x80 | ((unicodeValue & 0xfff) >> 6);
			output[indexOutput++] = 0x80 | (unicodeValue & 0x3f);
		}
	}

	output.resize(indexOutput); //remove the unnecessary bytes
	return output;
}
#endif