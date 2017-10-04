/******************************************************************************
File: KeyMappings.cpp
Created: 10/3/2017 11:57:46 AM
Copyright (c) 2017 Turn Tactics
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
Purpose: Contains all of the key mapping functions and data for keyboard input
from SDL
Author: James Womack
********************************************************************************/
#include "KeyMappings.h"
#include "../Math/Common.h"
#include <SDL.h>

namespace lse {

	// A map that maps KeyType to a string.
	const containers::UnorderedMap<KeyType, String> gc_keyTextMappings {
		{ KeyType::Key0, "0" }, { KeyType::Key1, "1" },
		{ KeyType::Key2, "2" }, { KeyType::Key3, "3" },
		{ KeyType::Key4, "4" }, { KeyType::Key5, "5" },
		{ KeyType::Key6, "6" }, { KeyType::Key7, "7" },
		{ KeyType::Key8, "8" }, { KeyType::Key9, "9" },
		{ KeyType::KeyA, "a" }, { KeyType::KeyB, "b" },
		{ KeyType::KeyC, "c" }, { KeyType::KeyD, "d" },
		{ KeyType::KeyE, "e" }, { KeyType::KeyF, "f" },
		{ KeyType::KeyG, "g" }, { KeyType::KeyH, "h" },
		{ KeyType::KeyI, "i" }, { KeyType::KeyJ, "j" },
		{ KeyType::KeyL, "l" }, { KeyType::KeyK, "k" },
		{ KeyType::KeyN, "n" }, { KeyType::KeyM, "m" },
		{ KeyType::KeyP, "p" }, { KeyType::KeyO, "o" },
		{ KeyType::KeyR, "r" }, { KeyType::KeyQ, "q" },
		{ KeyType::KeyT, "t" }, { KeyType::KeyS, "s" },
		{ KeyType::KeyV, "v" }, { KeyType::KeyU, "u" },
		{ KeyType::KeyW, "w" }, { KeyType::KeyX, "x" },
		{ KeyType::KeyY, "y" }, { KeyType::KeyZ, "z" },
		{ KeyType::KeyTab, "\t" }, { KeyType::KeyEnter, "\n" },
		{ KeyType::KeyBracketLeft, "[" }, { KeyType::KeyBracketRight, "]" },
		{ KeyType::KeyLeftParenthesis, "(" }, { KeyType::KeyRightParenthesis, ")" },
		{ KeyType::KeyCurlyBracketLeft, "{" }, { KeyType::KeyCurlyBracketRight, "}" },
		{ KeyType::KeyAngleBracketLeft, "{" }, { KeyType::KeyAngleBracketRight, "}" },
		{ KeyType::KeyColon, ":" }, { KeyType::KeySemicolon, ";" },
		{ KeyType::KeyComma, "," }, { KeyType::KeyEnter, "\n" },
		{ KeyType::KeySlash, "/" }, { KeyType::KeyBackslash, "\\" },
		{ KeyType::KeyExclamation, "!" }, { KeyType::KeyAt, "@" },
		{ KeyType::KeyHash, "#" }, { KeyType::KeyPercent, "%" },
		{ KeyType::KeyHat, "^" }, { KeyType::KeyAmpersand, "&" },
		{ KeyType::KeyStar, "*" }, { KeyType::KeyMinus, "-" },
		{ KeyType::KeyUnderscore, "_" }, { KeyType::KeyEquals, "=" },
		{ KeyType::KeyPlus, "+" },
		{ KeyType::KeyApostrophe, "'" }, { KeyType::KeyQuotes, "\"" },
		{ KeyType::KeyBacktick, "`" }, { KeyType::KeyQuestion, "?" },
		{ KeyType::KeyBackspace, "\\backspace\\" }, { KeyType::KeyDelete, "\\delete\\" },
		{ KeyType::KeyDollar, "$" }, { KeyType::KeyHome, "\\home\\" },
		{ KeyType::KeyPageDown, "\\pg-down\\" }, { KeyType::KeyPageUp, "\\pg-up\\" },
		{ KeyType::KeyEnd, "\\end\\" }, { KeyType::KeyInsert, "\\insert\\" },
		{ KeyType::KeyF1, "\\f1\\" }, { KeyType::KeyF2, "\\f2\\" },
		{ KeyType::KeyF3, "\\f3\\" }, { KeyType::KeyF4, "\\f4\\" },
		{ KeyType::KeyF5, "\\f5\\" }, { KeyType::KeyF6, "\\f6\\" },
		{ KeyType::KeyF7, "\\f7\\" }, { KeyType::KeyF8, "\\f8\\" },
		{ KeyType::KeyF9, "\\f9\\" }, { KeyType::KeyF10, "\\f10\\" },
		{ KeyType::KeyF11, "\\f11\\" }, { KeyType::KeyF12, "\\f12\\" },
		{ KeyType::KeyArrowUp, "\\^\\" }, { KeyType::KeyArrowDown, "\\v\\" },
		{ KeyType::KeyArrowLeft, "\\<\\" }, { KeyType::KeyArrowRight, "\\>\\" },
		{ KeyType::KeyPeriod, "." }, { KeyType::KeyPipe, "|" },
		{ KeyType::KeyNone, "" }
	};

	const containers::UnorderedMap<KeyModiferType, String> gc_keyModiferTextMappings {
		{ KeyModiferType::KeyNone, "" }, { KeyModiferType::KeyAlt, "Alt" },
		{ KeyModiferType::KeyCtrl, "Ctrl" }, { KeyModiferType::KeyCtrlAlt, "Ctrl+Alt" },
		{ KeyModiferType::KeyCtrlShift, "Ctrl+Shift" }, { KeyModiferType::KeyCtrlShiftAlt, "Ctrl+Shift+Alt" },
		{ KeyModiferType::KeyShift, "Shift" }, { KeyModiferType::KeyShiftAlt, "Shift+Alt" }
	};

	const containers::UnorderedMap<SDL_Keycode, KeyType> gc_sdlKeyMapping {
		{ SDLK_0, KeyType::Key0 }, { SDLK_1, KeyType::Key1 },
		{ SDLK_2, KeyType::Key2 }, { SDLK_3, KeyType::Key3 },
		{ SDLK_4, KeyType::Key4 }, { SDLK_5, KeyType::Key5 },
		{ SDLK_6, KeyType::Key6 }, { SDLK_7, KeyType::Key7 },
		{ SDLK_8, KeyType::Key8 }, { SDLK_9, KeyType::Key9 },
		{ SDLK_a, KeyType::KeyA }, { SDLK_b, KeyType::KeyB },
		{ SDLK_c, KeyType::KeyC }, { SDLK_d, KeyType::KeyD },
		{ SDLK_e, KeyType::KeyE }, { SDLK_f, KeyType::KeyF },
		{ SDLK_g, KeyType::KeyG }, { SDLK_h, KeyType::KeyH },
		{ SDLK_i, KeyType::KeyI }, { SDLK_j, KeyType::KeyJ },
		{ SDLK_k, KeyType::KeyK }, { SDLK_l, KeyType::KeyL },
		{ SDLK_m, KeyType::KeyM }, { SDLK_n, KeyType::KeyN },
		{ SDLK_o, KeyType::KeyO }, { SDLK_p, KeyType::KeyP },
		{ SDLK_q, KeyType::KeyQ }, { SDLK_r, KeyType::KeyR },
		{ SDLK_s, KeyType::KeyS }, { SDLK_t, KeyType::KeyT },
		{ SDLK_u, KeyType::KeyU }, { SDLK_v, KeyType::KeyV },
		{ SDLK_w, KeyType::KeyW }, { SDLK_x, KeyType::KeyX },
		{ SDLK_y, KeyType::KeyY }, { SDLK_z, KeyType::KeyZ },
		{ SDLK_y, KeyType::KeyY }, { SDLK_z, KeyType::KeyAccent },
	};

	// Maps SDL_Event type to a KeyState type if applicable
	inline KeyState get_sdl_key_state(SDL_Event& e) {
		return e.type == SDL_KEYDOWN ? KeyState::KeyDown
			: e.type == SDL_KEYUP ? KeyState::KeyUp : KeyState::KeyNone;
	}

	inline

		inline String get_text_character(KeyEvent& keyEvent) {
		auto keyStr = gc_keyTextMappings.at(keyEvent.key());

		if(is_alpha_keystroke(keyEvent) && keyEvent.modifier() == KeyModiferType::KeyShift) {
			return to_upper(keyStr);
		}

		return keyStr;
	}

	inline String get_key_event_string(KeyEvent& keyEvent) {
		auto keyStr = to_upper(gc_keyTextMappings.at(keyEvent.key()));
		auto modiferStr = to_upper(gc_keyModiferTextMappings.at(keyEvent.modifier()));

		if(keyStr.length() > 0 && modiferStr.length() > 0) {
			return modiferStr + "+" + keyStr;
		} else if(keyStr.length() > 0) {
			return keyStr;
		} else if(modiferStr.length() > 0) {
			return modiferStr;
		} else {
			return "\\none\\";
		}
	}
}