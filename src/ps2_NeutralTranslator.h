
/*
  The PS2 keyboard output is pretty complicated.  It needs to be so in order to
  be used in a general-purpose computer, and the general purpose computer has
  dedicated hardware to translate this complicated code into something useful
  to applications.  This translator provides that kind of thing to the Arduino.
  It translates the keycodes into a made-up, but at least predictable, coding.
  
  Author's Note (2017/7/1) This is a port of the translation that's done in the
  PS2KeyAdvanced library (https://github.com/techpaul/PS2KeyAdvanced).  I kept
  it here only because I hope to make this library a superset of all of the
  assorted PS2 libraries currently available.  While PS2KeyAdvanced has great
  functionality, I feel like this translation mechanism (which you can't turn off
  in that library) is a poor choice.  You should either go all the way to
  ASCII (and be your own keyboard controller) or have a nicely packaged collection
  of buttons.  If you're a nicely packaged collection of buttons, then you'd be
  better off switching to the PS2 ScanCode set and mapping between the keycode
  there and the function you want to enable when it's pressed.  Having a layer
  like this in between just costs you bytes and adds a new way to have things
  go wrong.  So I can't recommend using this class at all, but perhaps there's a
  use-case I failed to imagine.
*/
#pragma once
#include "ps2_KeyboardOutput.h"

namespace ps2
{
    enum KeyCode : uint16_t {
        PS2_NONE = 0x0,

        /* Flags/bit masks for status bits in returned unsigned int value */
        PS2_SHIFT   = 0x4000,
        PS2_CTRL    = 0x2000,
        PS2_ALT      = 0x800,
        PS2_GUI      = 0x200,

        PS2_MODIFIERS = 0xff00,

        /* Returned keycode definitions */
        /* Do NOT change these codings as you will break base
        functionality use PS2KeyMap for that and internationalisation */
        PS2_KEY_NUM         = 0x01,
        PS2_KEY_SCROLL      = 0x02,
        PS2_KEY_CAPS        = 0x03,
        PS2_KEY_PRTSCR      = 0x04,
        PS2_KEY_PAUSE       = 0x05,
        PS2_KEY_L_SHIFT     = 0x06,
        PS2_KEY_R_SHIFT     = 0x07,
        PS2_KEY_L_CTRL      = 0x08,
        PS2_KEY_R_CTRL      = 0x09,
        PS2_KEY_L_ALT       = 0x0A,
        PS2_KEY_R_ALT       = 0x0B,
        /* Sometimes called windows key */
        PS2_KEY_L_GUI       = 0x0C,
        PS2_KEY_R_GUI       = 0x0D,
        PS2_KEY_MENU        = 0x0E,
        /* Break is CTRL + PAUSE generated inside keyboard */
        PS2_KEY_BREAK       = 0x0F,
        /* Generated by some keyboards by ALT and PRTSCR */
        PS2_KEY_SYSRQ       = 0x10,
        PS2_KEY_HOME        = 0x11,
        PS2_KEY_END         = 0x12,
        PS2_KEY_PGUP        = 0x13,
        PS2_KEY_PGDN        = 0x14,
        PS2_KEY_L_ARROW     = 0x15,
        PS2_KEY_R_ARROW     = 0x16,
        PS2_KEY_UP_ARROW    = 0x17,
        PS2_KEY_DN_ARROW    = 0x18,
        PS2_KEY_INSERT      = 0x19,
        PS2_KEY_DELETE      = 0x1A,
        PS2_KEY_ESC         = 0x1B,
        PS2_KEY_BS          = 0x1C,
        PS2_KEY_TAB         = 0x1D,
        PS2_KEY_ENTER       = 0x1E,
        PS2_KEY_SPACE       = 0x1F,
        PS2_KEY_KP0         = 0x20,
        PS2_KEY_KP1         = 0x21,
        PS2_KEY_KP2         = 0x22,
        PS2_KEY_KP3         = 0x23,
        PS2_KEY_KP4         = 0x24,
        PS2_KEY_KP5         = 0x25,
        PS2_KEY_KP6         = 0x26,
        PS2_KEY_KP7         = 0x27,
        PS2_KEY_KP8         = 0x28,
        PS2_KEY_KP9         = 0x29,
        PS2_KEY_KP_DOT      = 0x2A,
        PS2_KEY_KP_ENTER    = 0x2B,
        PS2_KEY_KP_PLUS     = 0x2C,
        PS2_KEY_KP_MINUS    = 0x2D,
        PS2_KEY_KP_TIMES    = 0x2E,
        PS2_KEY_KP_DIV      = 0x2F,
        PS2_KEY_0           = 0x30,
        PS2_KEY_1           = 0x31,
        PS2_KEY_2           = 0x32,
        PS2_KEY_3           = 0x33,
        PS2_KEY_4           = 0x34,
        PS2_KEY_5           = 0x35,
        PS2_KEY_6           = 0x36,
        PS2_KEY_7           = 0x37,
        PS2_KEY_8           = 0x38,
        PS2_KEY_9           = 0x39,
        PS2_KEY_APOS        = 0x3A, // '
        PS2_KEY_COMMA       = 0x3B,
        PS2_KEY_MINUS       = 0x3C,
        PS2_KEY_DOT         = 0x3D,
        PS2_KEY_DIV         = 0x3E,
        /* Some Numeric keyboards have an '=' on right keypad */
        PS2_KEY_KP_EQUAL    = 0x3F,
        PS2_KEY_SINGLE      = 0x40, // `
        PS2_KEY_A           = 0x41,
        PS2_KEY_B           = 0x42,
        PS2_KEY_C           = 0x43,
        PS2_KEY_D           = 0x44,
        PS2_KEY_E           = 0x45,
        PS2_KEY_F           = 0x46,
        PS2_KEY_G           = 0x47,
        PS2_KEY_H           = 0x48,
        PS2_KEY_I           = 0x49,
        PS2_KEY_J           = 0x4A,
        PS2_KEY_K           = 0x4B,
        PS2_KEY_L           = 0x4C,
        PS2_KEY_M           = 0x4D,
        PS2_KEY_N           = 0x4E,
        PS2_KEY_O           = 0x4F,
        PS2_KEY_P           = 0x50,
        PS2_KEY_Q           = 0x51,
        PS2_KEY_R           = 0x52,
        PS2_KEY_S           = 0x53,
        PS2_KEY_T           = 0x54,
        PS2_KEY_U           = 0x55,
        PS2_KEY_V           = 0x56,
        PS2_KEY_W           = 0x57,
        PS2_KEY_X           = 0x58,
        PS2_KEY_Y           = 0x59,
        PS2_KEY_Z           = 0x5A,
        PS2_KEY_SEMI        = 0x5B,
        PS2_KEY_BACK        = 0x5C,
        PS2_KEY_OPEN_SQ     = 0x5D,
        PS2_KEY_CLOSE_SQ    = 0x5E,
        PS2_KEY_EQUAL       = 0x5F,
        /* Some Numeric keypads have a comma key */
        PS2_KEY_KP_COMMA    = 0x60,
        PS2_KEY_F1          = 0x61,
        PS2_KEY_F2          = 0x62,
        PS2_KEY_F3          = 0x63,
        PS2_KEY_F4          = 0x64,
        PS2_KEY_F5          = 0x65,
        PS2_KEY_F6          = 0x66,
        PS2_KEY_F7          = 0x67,
        PS2_KEY_F8          = 0x68,
        PS2_KEY_F9          = 0x69,
        PS2_KEY_F10         = 0x6A,
        PS2_KEY_F11         = 0x6B,
        PS2_KEY_F12         = 0x6C,
        PS2_KEY_F13         = 0x6D,
        PS2_KEY_F14         = 0x6E,
        PS2_KEY_F15         = 0x6F,
        PS2_KEY_F16         = 0x70,
        PS2_KEY_F17         = 0x71,
        PS2_KEY_F18         = 0x72,
        PS2_KEY_F19         = 0x73,
        PS2_KEY_F20         = 0x74,
        PS2_KEY_F21         = 0x75,
        PS2_KEY_F22         = 0x76,
        PS2_KEY_F23         = 0x77,
        PS2_KEY_F24         = 0x78,
        PS2_KEY_NEXT_TR     = 0x79,
        PS2_KEY_PREV_TR     = 0x7A,
        PS2_KEY_STOP        = 0x7B,
        PS2_KEY_PLAY        = 0x7C,
        PS2_KEY_MUTE        = 0x7D,
        PS2_KEY_VOL_UP      = 0x7E,
        PS2_KEY_VOL_DN      = 0x7F,
        PS2_KEY_MEDIA       = 0x80,
        PS2_KEY_EMAIL       = 0x81,
        PS2_KEY_CALC        = 0x82,
        PS2_KEY_COMPUTER    = 0x83,
        PS2_KEY_WEB_SEARCH  = 0x84,
        PS2_KEY_WEB_HOME    = 0x85,
        PS2_KEY_WEB_BACK    = 0x86,
        PS2_KEY_WEB_FORWARD = 0x87,
        PS2_KEY_WEB_STOP    = 0x88,
        PS2_KEY_WEB_REFRESH = 0x89,
        PS2_KEY_WEB_FAVOR   = 0x8A,
        PS2_KEY_EUROPE2     = 0x8B,
        PS2_KEY_POWER       = 0x8C,
        PS2_KEY_SLEEP       = 0x8D,
        PS2_KEY_WAKE        = 0x90,
        PS2_KEY_INTL1       = 0x91,
        PS2_KEY_INTL2       = 0x92,
        PS2_KEY_INTL3       = 0x93,
        PS2_KEY_INTL4       = 0x94,
        PS2_KEY_INTL5       = 0x95,
        PS2_KEY_LANG1       = 0x96,
        PS2_KEY_LANG2       = 0x97,
        PS2_KEY_LANG3       = 0x98,
        PS2_KEY_LANG4       = 0x99,
        PS2_KEY_LANG5       = 0xA0,
    };
    inline KeyCode operator |(KeyCode code, KeyCode modifiers) { return (KeyCode)((uint16_t)code | (uint16_t)modifiers); }
    inline KeyCode operator &(KeyCode code, KeyCode modifiers) { return (KeyCode)((uint16_t)code & (uint16_t)modifiers); }
    inline KeyCode &operator |=(KeyCode &code, KeyCode modifiers) { return code = (KeyCode)((uint16_t)code | (uint16_t)modifiers); }
    inline KeyCode &operator &=(KeyCode &code, KeyCode modifiers) { return code = (KeyCode)((uint16_t)code & (uint16_t)modifiers); }
    inline KeyCode operator ~(KeyCode code) { return (KeyCode)(~(uint16_t)code); }

    class NeutralTranslator {
        bool isUnmake : 1;
        bool isExtended : 1;
        bool isExtended1 : 1;
        bool haveGotExtended1FirstByte : 1;
        KeyCode modifiers = PS2_NONE;

    public:
        NeutralTranslator() { }

        /**
         * If a scancode is read from the PS2 interface itself, it should be sent here.
         */
        KeyCode translatePs2Keycode(KeyboardOutput code) {
            KeyCode result = PS2_NONE;
            if (code == KeyboardOutput::none) {
                return PS2_NONE;
            }
            if (code == KeyboardOutput::unmake) {
                this->isUnmake = true;
                return PS2_NONE;
            }
            if (code == KeyboardOutput::extend) {
                this->isExtended = true;
                return PS2_NONE;
            }
            if (code == KeyboardOutput::extend1) {
                this->isExtended1 = true;
                return PS2_NONE;
            }

            if (this->isExtended1) {
                if (!this->haveGotExtended1FirstByte) {
                    this->haveGotExtended1FirstByte = true;
                    // Don't care about the actual content of the thing, because, oddly, there's only one
                    //   key that uses Extended-1 mode
                    return PS2_NONE;
                }
                if (!this->isUnmake) {
                    result = KeyCode::PS2_KEY_BREAK;
                }
                this->reset();
                return result;
            }

            KeyCode modifier = this->translateModifier(code);
            if (modifier != KeyCode::PS2_NONE) {
                if (this->isUnmake) {
                    this->modifiers &= ~modifier;
                }
                else {
                    this->modifiers |= modifier;
                }
                this->reset();
                return PS2_NONE;
            }

            if (this->isUnmake) {
                if (this->isExtended1 && !this->haveGotExtended1FirstByte) {
                    this->haveGotExtended1FirstByte = true;
                }
                else {
                    this->reset();
                }
                // Don't care about unmake
                return PS2_NONE;
            }

            KeyCode translatedCode = this->isExtended
                ? translateExtended(code)
                : translateNonExtended(code);
            if (translatedCode != PS2_NONE) {
                result = translatedCode | this->modifiers;
            }

            this->reset();
            return result;
        }

        void reset()
        {
            this->isUnmake = false;
            this->isExtended = false;
            this->isExtended1 = false;
            this->haveGotExtended1FirstByte = false;
        }

    private:
        KeyCode translateModifier(KeyboardOutput inputCode)
        {
            switch (inputCode) {
                case KeyboardOutput::sc2_leftShift: return KeyCode::PS2_SHIFT;
                case KeyboardOutput::sc2_rightShift: return KeyCode::PS2_SHIFT;
                case KeyboardOutput::sc2_leftCtrl: return KeyCode::PS2_CTRL;
                case KeyboardOutput::sc2_leftAlt: return KeyCode::PS2_ALT;
                case KeyboardOutput::sc2ex_leftGui: return KeyCode::PS2_GUI;
                case KeyboardOutput::sc2ex_rightGui: return KeyCode::PS2_GUI;
                default: return KeyCode::PS2_NONE;
            }
        }

        KeyCode translateNonExtended(KeyboardOutput inputCode)
        {
            // This switch statements might make a bad bargain - they trade
            //  time-efficiency for program size.
            switch (inputCode) {
                case KeyboardOutput::sc2_numLock: return KeyCode::PS2_KEY_NUM;
                case KeyboardOutput::sc2_scrollLock: return KeyCode::PS2_KEY_SCROLL;
                case KeyboardOutput::sc2_capsLock: return KeyCode::PS2_KEY_CAPS;
                case KeyboardOutput::sc2_leftShift: return KeyCode::PS2_KEY_L_SHIFT;
                case KeyboardOutput::sc2_rightShift: return KeyCode::PS2_KEY_R_SHIFT;
                case KeyboardOutput::sc2_leftCtrl: return KeyCode::PS2_KEY_L_CTRL;
                case KeyboardOutput::sc2_leftAlt: return KeyCode::PS2_KEY_L_ALT;
                case KeyboardOutput::sc2_sysRequest: return KeyCode::PS2_KEY_SYSRQ;
                case KeyboardOutput::sc2_esc: return KeyCode::PS2_KEY_ESC;
                case KeyboardOutput::sc2_backslash: return KeyCode::PS2_KEY_BACK;
                case KeyboardOutput::sc2_tab: return KeyCode::PS2_KEY_TAB;
                case KeyboardOutput::sc2_enter: return KeyCode::PS2_KEY_ENTER;
                case KeyboardOutput::sc2_space: return KeyCode::PS2_KEY_SPACE;
                case KeyboardOutput::sc2_keypad0: return KeyCode::PS2_KEY_KP0;
                case KeyboardOutput::sc2_keypad1: return KeyCode::PS2_KEY_KP1;
                case KeyboardOutput::sc2_keypad2: return KeyCode::PS2_KEY_KP2;
                case KeyboardOutput::sc2_keypad3: return KeyCode::PS2_KEY_KP3;
                case KeyboardOutput::sc2_keypad4: return KeyCode::PS2_KEY_KP4;
                case KeyboardOutput::sc2_keypad5: return KeyCode::PS2_KEY_KP5;
                case KeyboardOutput::sc2_keypad6: return KeyCode::PS2_KEY_KP6;
                case KeyboardOutput::sc2_keypad7: return KeyCode::PS2_KEY_KP7;
                case KeyboardOutput::sc2_keypad8: return KeyCode::PS2_KEY_KP8;
                case KeyboardOutput::sc2_keypad9: return KeyCode::PS2_KEY_KP9;
                case KeyboardOutput::sc2_keypadPeriod: return KeyCode::PS2_KEY_KP_DOT;
                case KeyboardOutput::sc2_keypadPlus: return KeyCode::PS2_KEY_KP_PLUS;
                case KeyboardOutput::sc2_keypadDash: return KeyCode::PS2_KEY_KP_MINUS;
                case KeyboardOutput::sc2_keypadAsterisk: return KeyCode::PS2_KEY_KP_TIMES;
                case KeyboardOutput::sc2_KeypadEquals: return KeyCode::PS2_KEY_KP_EQUAL;
                case KeyboardOutput::sc2_0: return KeyCode::PS2_KEY_0;
                case KeyboardOutput::sc2_1: return KeyCode::PS2_KEY_1;
                case KeyboardOutput::sc2_2: return KeyCode::PS2_KEY_2;
                case KeyboardOutput::sc2_3: return KeyCode::PS2_KEY_3;
                case KeyboardOutput::sc2_4: return KeyCode::PS2_KEY_4;
                case KeyboardOutput::sc2_5: return KeyCode::PS2_KEY_5;
                case KeyboardOutput::sc2_6: return KeyCode::PS2_KEY_6;
                case KeyboardOutput::sc2_7: return KeyCode::PS2_KEY_7;
                case KeyboardOutput::sc2_8: return KeyCode::PS2_KEY_8;
                case KeyboardOutput::sc2_9: return KeyCode::PS2_KEY_9;
                case KeyboardOutput::sc2_apostrophe: return KeyCode::PS2_KEY_APOS;
                case KeyboardOutput::sc2_comma: return KeyCode::PS2_KEY_COMMA;
                case KeyboardOutput::sc2_dash: return KeyCode::PS2_KEY_MINUS;
                case KeyboardOutput::sc2_period: return KeyCode::PS2_KEY_DOT;
                case KeyboardOutput::sc2_forwardSlash: return KeyCode::PS2_KEY_DIV;
                case KeyboardOutput::sc2_openQuote: return KeyCode::PS2_KEY_SINGLE;
                case KeyboardOutput::sc2_a: return KeyCode::PS2_KEY_A;
                case KeyboardOutput::sc2_b: return KeyCode::PS2_KEY_B;
                case KeyboardOutput::sc2_c: return KeyCode::PS2_KEY_C;
                case KeyboardOutput::sc2_d: return KeyCode::PS2_KEY_D;
                case KeyboardOutput::sc2_e: return KeyCode::PS2_KEY_E;
                case KeyboardOutput::sc2_f: return KeyCode::PS2_KEY_F;
                case KeyboardOutput::sc2_g: return KeyCode::PS2_KEY_G;
                case KeyboardOutput::sc2_h: return KeyCode::PS2_KEY_H;
                case KeyboardOutput::sc2_i: return KeyCode::PS2_KEY_I;
                case KeyboardOutput::sc2_j: return KeyCode::PS2_KEY_J;
                case KeyboardOutput::sc2_k: return KeyCode::PS2_KEY_K;
                case KeyboardOutput::sc2_l: return KeyCode::PS2_KEY_L;
                case KeyboardOutput::sc2_m: return KeyCode::PS2_KEY_M;
                case KeyboardOutput::sc2_n: return KeyCode::PS2_KEY_N;
                case KeyboardOutput::sc2_o: return KeyCode::PS2_KEY_O;
                case KeyboardOutput::sc2_p: return KeyCode::PS2_KEY_P;
                case KeyboardOutput::sc2_q: return KeyCode::PS2_KEY_Q;
                case KeyboardOutput::sc2_r: return KeyCode::PS2_KEY_R;
                case KeyboardOutput::sc2_s: return KeyCode::PS2_KEY_S;
                case KeyboardOutput::sc2_t: return KeyCode::PS2_KEY_T;
                case KeyboardOutput::sc2_u: return KeyCode::PS2_KEY_U;
                case KeyboardOutput::sc2_v: return KeyCode::PS2_KEY_V;
                case KeyboardOutput::sc2_w: return KeyCode::PS2_KEY_W;
                case KeyboardOutput::sc2_x: return KeyCode::PS2_KEY_X;
                case KeyboardOutput::sc2_y: return KeyCode::PS2_KEY_Y;
                case KeyboardOutput::sc2_z: return KeyCode::PS2_KEY_Z;
                case KeyboardOutput::sc2_semicolon: return KeyCode::PS2_KEY_SEMI;
                case KeyboardOutput::sc2_backspace: return KeyCode::PS2_KEY_BS;
                case KeyboardOutput::sc2_openSquareBracket: return KeyCode::PS2_KEY_OPEN_SQ;
                case KeyboardOutput::sc2_closeSquareBracket: return KeyCode::PS2_KEY_CLOSE_SQ;
                case KeyboardOutput::sc2_equal: return KeyCode::PS2_KEY_EQUAL;
                case KeyboardOutput::sc2_europe2: return KeyCode::PS2_KEY_EUROPE2;
                case KeyboardOutput::sc2_f1: return KeyCode::PS2_KEY_F1;
                case KeyboardOutput::sc2_f2: return KeyCode::PS2_KEY_F2;
                case KeyboardOutput::sc2_f3: return KeyCode::PS2_KEY_F3;
                case KeyboardOutput::sc2_f4: return KeyCode::PS2_KEY_F4;
                case KeyboardOutput::sc2_f5: return KeyCode::PS2_KEY_F5;
                case KeyboardOutput::sc2_f6: return KeyCode::PS2_KEY_F6;
                case KeyboardOutput::sc2_f7: return KeyCode::PS2_KEY_F7;
                case KeyboardOutput::sc2_f8: return KeyCode::PS2_KEY_F8;
                case KeyboardOutput::sc2_f9: return KeyCode::PS2_KEY_F9;
                case KeyboardOutput::sc2_f10: return KeyCode::PS2_KEY_F10;
                case KeyboardOutput::sc2_f11: return KeyCode::PS2_KEY_F11;
                case KeyboardOutput::sc2_f12: return KeyCode::PS2_KEY_F12;
                case KeyboardOutput::sc2_f13: return KeyCode::PS2_KEY_F13;
                case KeyboardOutput::sc2_f14: return KeyCode::PS2_KEY_F14;
                case KeyboardOutput::sc2_f15: return KeyCode::PS2_KEY_F15;
                case KeyboardOutput::sc2_f16: return KeyCode::PS2_KEY_F16;
                case KeyboardOutput::sc2_f17: return KeyCode::PS2_KEY_F17;
                case KeyboardOutput::sc2_f18: return KeyCode::PS2_KEY_F18;
                case KeyboardOutput::sc2_f19: return KeyCode::PS2_KEY_F19;
                case KeyboardOutput::sc2_f20: return KeyCode::PS2_KEY_F20;
                case KeyboardOutput::sc2_f21: return KeyCode::PS2_KEY_F21;
                case KeyboardOutput::sc2_f22: return KeyCode::PS2_KEY_F22;
                case KeyboardOutput::sc2_f23: return KeyCode::PS2_KEY_F23;
                case KeyboardOutput::sc2_f24: return KeyCode::PS2_KEY_F24;
                case KeyboardOutput::sc2_keypadComma: return KeyCode::PS2_KEY_KP_COMMA;
                case KeyboardOutput::sc2_intl1: return KeyCode::PS2_KEY_INTL1;
                case KeyboardOutput::sc2_intl2: return KeyCode::PS2_KEY_INTL2;
                case KeyboardOutput::sc2_intl3: return KeyCode::PS2_KEY_INTL3;
                case KeyboardOutput::sc2_intl4: return KeyCode::PS2_KEY_INTL4;
                case KeyboardOutput::sc2_intl5: return KeyCode::PS2_KEY_INTL5;
                case KeyboardOutput::sc2_lang1: return KeyCode::PS2_KEY_LANG1;
                case KeyboardOutput::sc2_lang2: return KeyCode::PS2_KEY_LANG2;
                case KeyboardOutput::sc2_lang3: return KeyCode::PS2_KEY_LANG3;
                case KeyboardOutput::sc2_lang4: return KeyCode::PS2_KEY_LANG4;
                // case KeyboardOutput::sc2_LANG5: return KeyCode::PS2_KEY_LANG5;
                default: return KeyCode::PS2_NONE;
            };
        }
        
        KeyCode translateExtended(KeyboardOutput inputCode)
        {
            switch (inputCode) {
                case KeyboardOutput::sc2ex_printScreen: return KeyCode::PS2_KEY_PRTSCR;
                case KeyboardOutput::sc2ex_rightCtrl: return KeyCode::PS2_KEY_R_CTRL;
                case KeyboardOutput::sc2ex_rightAlt: return KeyCode::PS2_KEY_R_ALT;
                case KeyboardOutput::sc2ex_leftGui: return KeyCode::PS2_KEY_L_GUI;
                case KeyboardOutput::sc2ex_rightGui: return KeyCode::PS2_KEY_R_GUI;
                case KeyboardOutput::sc2ex_menu: return KeyCode::PS2_KEY_MENU;
                // case KeyboardOutput::sc2_BREAK: return KeyCode::PS2_KEY_BREAK; // <- This doesn't match up with how my keyboards work; I think it's an error
                case KeyboardOutput::sc2ex_home: return KeyCode::PS2_KEY_HOME;
                case KeyboardOutput::sc2ex_end: return KeyCode::PS2_KEY_END;
                case KeyboardOutput::sc2ex_pageUp: return KeyCode::PS2_KEY_PGUP;
                case KeyboardOutput::sc2ex_pageDown: return KeyCode::PS2_KEY_PGDN;
                case KeyboardOutput::sc2ex_leftArrow: return KeyCode::PS2_KEY_L_ARROW;
                case KeyboardOutput::sc2ex_rightArrow: return KeyCode::PS2_KEY_R_ARROW;
                case KeyboardOutput::sc2ex_upArrow: return KeyCode::PS2_KEY_UP_ARROW;
                case KeyboardOutput::sc2ex_downArrow: return KeyCode::PS2_KEY_DN_ARROW;
                case KeyboardOutput::sc2ex_insert: return KeyCode::PS2_KEY_INSERT;
                case KeyboardOutput::sc2ex_delete: return KeyCode::PS2_KEY_DELETE;
                case KeyboardOutput::sc2ex_keypadEnter: return KeyCode::PS2_KEY_KP_ENTER;
                case KeyboardOutput::sc2ex_keypadForwardSlash: return KeyCode::PS2_KEY_KP_DIV;
                case KeyboardOutput::sc2ex_nextTrack: return KeyCode::PS2_KEY_NEXT_TR;
                case KeyboardOutput::sc2ex_prevTrack: return KeyCode::PS2_KEY_PREV_TR;
                case KeyboardOutput::sc2ex_stop: return KeyCode::PS2_KEY_STOP;
                case KeyboardOutput::sc2ex_play: return KeyCode::PS2_KEY_PLAY;
                case KeyboardOutput::sc2ex_mute: return KeyCode::PS2_KEY_MUTE;
                case KeyboardOutput::sc2ex_volumeUp: return KeyCode::PS2_KEY_VOL_UP;
                case KeyboardOutput::sc2ex_volumeDown: return KeyCode::PS2_KEY_VOL_DN;
                case KeyboardOutput::sc2ex_mediaSelect: return KeyCode::PS2_KEY_MEDIA;
                case KeyboardOutput::sc2ex_email: return KeyCode::PS2_KEY_EMAIL;
                case KeyboardOutput::sc2ex_calculator: return KeyCode::PS2_KEY_CALC;
                case KeyboardOutput::sc2ex_myComputer: return KeyCode::PS2_KEY_COMPUTER;
                case KeyboardOutput::sc2ex_webSearch: return KeyCode::PS2_KEY_WEB_SEARCH;
                case KeyboardOutput::sc2ex_webHome: return KeyCode::PS2_KEY_WEB_HOME;
                case KeyboardOutput::sc2ex_webBack: return KeyCode::PS2_KEY_WEB_BACK;
                case KeyboardOutput::sc2ex_webForward: return KeyCode::PS2_KEY_WEB_FORWARD;
                case KeyboardOutput::sc2ex_webStop: return KeyCode::PS2_KEY_WEB_STOP;
                case KeyboardOutput::sc2ex_webRefresh: return KeyCode::PS2_KEY_WEB_REFRESH;
                case KeyboardOutput::sc2ex_webFavorites: return KeyCode::PS2_KEY_WEB_FAVOR;
                case KeyboardOutput::sc2ex_power: return KeyCode::PS2_KEY_POWER;
                case KeyboardOutput::sc2ex_sleep: return KeyCode::PS2_KEY_SLEEP;
                case KeyboardOutput::sc2ex_wake: return KeyCode::PS2_KEY_WAKE;
                default: return KeyCode::PS2_NONE;
            }
        }
    };
}