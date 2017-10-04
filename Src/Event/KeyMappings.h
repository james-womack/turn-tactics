/******************************************************************************
File: KeyMappings.h
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
#pragma once

#include "../Common.h"
#include "../Math/Common.h"

namespace lse
{
  // Enum of all possible keyboard presses in turn tactics
  // This is split into two shorts where the upper short is the group
  // the key is in and the lower short is what the key is.
  // You can use the following masks to mask off this enum class after a call
  // to to_integral(enumVar) to convert it to its unerlying type (UInt32)
  // 0x0001FFFF is all alpha characters (a,b,c,d...)
  // 0x0002FFFF is all numeric characters (0, 1, 2, 3, ...)
  // 0x0003FFFF is alpha-numeric characters
  // 0x0004FFFF is Symbols
  // 0x0008FFFF is Command Characters
  // 0x0010FFFF is F-Row
  enum class KeyType : UInt32
  {
    KeyNone = 0,
    // Alpha Characters start
    KeyA = 0x00010000,
    KeyB,
    KeyC,
    KeyD,
    KeyE,
    KeyF,
    KeyG,
    KeyH,
    KeyI,
    KeyJ,
    KeyK,
    KeyL,
    KeyM,
    KeyN,
    KeyO,
    KeyP,
    KeyQ,
    KeyR,
    KeyS,
    KeyT,
    KeyU,
    KeyV,
    KeyW,
    KeyX,
    KeyY,
    KeyZ,

    // Numeric Characters start
    Key1 = 0x00020000,
    Key2,
    Key3,
    Key4,
    Key5,
    Key6,
    Key7,
    Key8,
    Key9,
    Key0,

    // Symbol Characters start
    KeyMinus = 0x00040000,
    KeyPlus,
    KeyBracketLeft,
    KeyBracketRight,
    KeyBackslash,
    KeySlash,
    KeyPeriod,
    KeySemicolon,
    KeyApostrophe,
    KeyStar,
    KeyComma,
    KeyAngleBracketLeft,
    KeyAngleBracketRight,
    KeyQuestion,
    KeyPipe,
    KeyCurlyBracketLeft,
    KeyCurlyBracketRight,
    KeyQuotes,
    KeyColon,
    KeyBacktick,
    KeyAccent,
    KeyExclamation,
    KeyAt,
    KeyHash,
    KeyDollar,
    KeyPercent,
    KeyHat,
    KeyAmpersand,
    KeyLeftParenthesis,
    KeyRightParenthesis,
    KeyUnderscore,
    KeyEquals,

    // Control Characters start
    KeyTab = 0x00080000,
    KeyBackspace,
    KeyEsc,
    KeyHome,
    KeyInsert,
    KeyDelete,
    KeyPageDown,
    KeyPageUp,
    KeyScrollLock,
    KeyPauseBreak,
    KeyArrowUp,
    KeyArrowDown,
    KeyArrowLeft,
    KeyArrowRight,
    KeyEnter,
    KeyEnd,

    // F-keys start
    KeyF1 = 0x00100000,
    KeyF2,
    KeyF3,
    KeyF4,
    KeyF5,
    KeyF6,
    KeyF7,
    KeyF8,
    KeyF9,
    KeyF10,
    KeyF11,
    KeyF12,
  };

  // The keys that can be held down to create key combinations
  enum class KeyModiferType : Int8
  {
    KeyNone,
    KeyShift,
    KeyCtrl,
    KeyAlt,
    KeyCtrlShift,
    KeyCtrlAlt,
    KeyShiftAlt,
    KeyCtrlShiftAlt
  };

  enum class KeyState : Int8
  {
    KeyNone,
    KeyUp,
    KeyDown
  };

  // An event that represents a keypress from the user
  // and any modifers specified from it
  struct KeyEvent
  {
    KeyEvent(KeyType key, KeyModiferType modifer, KeyState state) :
      m_key(key), m_modifier(modifer), m_state(state)
    {
      
    }

    // The key that is down or KeyNone if no key is down
    KeyType key() const {
      return m_key;
    }

    // The modifer key down or KeyNone if no modifier is down
    KeyModiferType modifier() const
    {
      return m_modifier;
    }

    // The state of the key
    KeyState state() const
    {
      return m_state;
    }

  private:
    KeyType m_key;
    KeyModiferType m_modifier;
    KeyState m_state;
  };

  // This gets the textual representation of the key event (as if you pressed
  // the key combination into a text editor)
  String get_text_character(KeyEvent& keyEvent);
  // This gets the plain english description of the key combination of the key
  // event
  String get_key_event_string(KeyEvent& keyEvent);
  
  // Returns if the key combination would produce a character on the screen
  constexpr auto is_alpha_keystroke(KeyEvent& keyEvent) -> bool
  {
    const auto keyVal = to_integral(keyEvent.key());
    return (keyVal & 0x00010000) != 0 
      && (keyEvent.modifier() == KeyModiferType::KeyNone 
      || keyEvent.modifier() == KeyModiferType::KeyShift);
  }

  // Returns if the key combination would produce a number on the screen
  constexpr auto is_numeric_keystroke(KeyEvent& keyEvent) -> bool
  {
    const auto keyVal = to_integral(keyEvent.key());
    return (keyVal & 0x00020000) != 0 
      && keyEvent.modifier() == KeyModiferType::KeyNone;
  }

  // Returns if the key combination would produce a alphanumeric character on the screen
  constexpr auto is_alphanumeric_keystroke(KeyEvent& keyEvent) -> bool
  {
    return is_alpha_keystroke(keyEvent) || is_numeric_keystroke(keyEvent);
  }

  // Returns if the key combination would produce a symbol character on screen
  constexpr auto is_symbol_keystroke(KeyEvent& keyEvent) -> bool {
    const auto keyVal = to_integral(keyEvent.key());
    return (keyVal & 0x00040000) != 0 
      && (keyEvent.modifier() == KeyModiferType::KeyNone
      || keyEvent.modifier() == KeyModiferType::KeyShift);
  }

  // Returns if the key combination would produce text
  constexpr auto is_text_keystroke(KeyEvent& keyEvent) ->  bool {
    return is_alphanumeric_keystroke(keyEvent) || is_symbol_keystroke(keyEvent);
  }

  // Returns if the key combination is a control character
  constexpr auto is_control_keystroke(KeyEvent& keyEvent) -> bool {
    const auto keyVal = to_integral(keyEvent.key());
    return (keyVal & 0x00080000) != 0;
  }

  // Returns if the key combination is a function row keystroke
  constexpr auto is_function_row_keystroke(KeyEvent& keyEvent) -> bool {
    const auto keyVal = to_integral(keyEvent.key());
    return (keyVal & 0x00100000) != 0;
  }
}
