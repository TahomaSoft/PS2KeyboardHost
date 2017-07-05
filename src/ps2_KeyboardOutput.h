#pragma once

namespace ps2 {
    /** \brief Byte-codes sent back from the Ps2 keyboard to the host.
     *  \details
     *    Entries prefixed by "sc2" are from the standard "Scan Code Set 2".
     *    Those with "sc2ex" are from the same set, but the ones that are prefixed with
     *    the 'extend' byte.  Entries prefixed by "sc3" are from the PS2 scan code set,
     *    which is far simpler, needing only one byte.  Being the simpler option, it is,
     *    of course, widely shunned.  Still, if you're building a device that's using an
     *    old ps2 keyboard to control it, you should strongly consider using that set.
     */
    enum class KeyboardOutput : uint8_t {
        // These are codes returned from this API, rather than from the keyboard itself.
        none            = 0x0,
        garbled         = 0xfe,

        batSuccessful   = 0xaa, // Reset or power-up successful
        batFailure      = 0xfc, // Not so fortunate

        ack             = 0xfa,
        echo            = 0xee,
        nack            = 0xfe,

        unmake          = 0xf0,

        extend          = 0xe0,
        extend1         = 0xe1,

        // "sc2" is short for "ScanCode Set 2".  Similarly for "sc3"
        // "sc2ex" is ScanCode set 2, prefixed by an 'extend' byte

        // There are lots of sources for scancode values; some more complete than others.  This set
        //  is, at best, an approximation.
        sc2_numLock     = 0x77,
        sc2_scrollLock  = 0x7e,
        sc2_capsLock    = 0x58,
        sc2_leftShift   = 0x12,
        sc2_rightShift  = 0x59,
        sc2_leftCtrl    = 0x14,
        sc2_leftAlt     = 0x11,
        sc2_sysRequest  = 0x84, /* Generated by some keyboards by ALT and PRTSCR */
        sc2_esc         = 0x76,
        sc2_backspace   = 0x66,
        sc2_tab         = 0x0d,
        sc2_enter       = 0x5a,
        sc2_space       = 0x29,
        sc2_keypad0     = 0x70,
        sc2_keypad1     = 0x69,
        sc2_keypad2     = 0x72,
        sc2_keypad3     = 0x7a,
        sc2_keypad4     = 0x6b,
        sc2_keypad5     = 0x73,
        sc2_keypad6     = 0x74,
        sc2_keypad7     = 0x6c,
        sc2_keypad8     = 0x75,
        sc2_keypad9     = 0x7d,
        sc2_keypadPeriod = 0x71,
        sc2_keypadPlus  = 0x79,
        sc2_keypadDash  = 0x7b,
        sc2_keypadAsterisk = 0x7c,
        sc2ex_keypadEnter = 0x5a,
        sc2_KeypadEquals = 0x0f,
        sc2_keypadComma = 0x6d,
        sc2ex_keypadForwardSlash = 0x4a,
        sc2_0           = 0x45,
        sc2_1           = 0x16,
        sc2_2           = 0x1e,
        sc2_3           = 0x26,
        sc2_4           = 0x25,
        sc2_5           = 0x2e,
        sc2_6           = 0x36,
        sc2_7           = 0x3d,
        sc2_8           = 0x3e,
        sc2_9           = 0x46,
        sc2_apostrophe  = 0x52, // ' "
        sc2_comma       = 0x41,
        sc2_dash        = 0x4e,
        sc2_period      = 0x49,
        sc2_forwardSlash = 0x4a,
        sc2_openQuote   = 0x0e, // ` ~
        sc2_a           = 0x1c,
        sc2_b           = 0x32,
        sc2_c           = 0x21,
        sc2_d           = 0x23,
        sc2_e           = 0x24,
        sc2_f           = 0x2b,
        sc2_g           = 0x34,
        sc2_h           = 0x33,
        sc2_i           = 0x43,
        sc2_j           = 0x3b,
        sc2_k           = 0x42,
        sc2_l           = 0x4b,
        sc2_m           = 0x3a,
        sc2_n           = 0x31,
        sc2_o           = 0x44,
        sc2_p           = 0x4d,
        sc2_q           = 0x15,
        sc2_r           = 0x2d,
        sc2_s           = 0x1b,
        sc2_t           = 0x2c,
        sc2_u           = 0x3c,
        sc2_v           = 0x2a,
        sc2_w           = 0x1d,
        sc2_x           = 0x22,
        sc2_y           = 0x35,
        sc2_z           = 0x1a,
        sc2_semicolon   = 0x4c,
        sc2_backslash   = 0x5d,
        sc2_europe2     = 0x61, // Extra key left of Z on 102 keyboards
        sc2_openSquareBracket = 0x54,
        sc2_closeSquareBracket = 0x5b,
        sc2_equal       = 0x55,
        sc2_f1          = 0x05,
        sc2_f2          = 0x06,
        sc2_f3          = 0x04,
        sc2_f4          = 0x0c,
        sc2_f5          = 0x03,
        sc2_f6          = 0x0b,
        sc2_f7          = 0x83,
        sc2_f8          = 0x0a,
        sc2_f9          = 0x01,
        sc2_f10         = 0x09,
        sc2_f11         = 0x78,
        sc2_f12         = 0x07,
        sc2_f13         = 0x08,
        sc2_f14         = 0x10,
        sc2_f15         = 0x18,
        sc2_f16         = 0x20,
        sc2_f17         = 0x28,
        sc2_f18         = 0x30,
        sc2_f19         = 0x38,
        sc2_f20         = 0x40,
        sc2_f21         = 0x48,
        sc2_f22         = 0x50,
        sc2_f23         = 0x57,
        sc2_f24         = 0x5f,
        sc2_intl1       = 0x51,
        sc2_intl2       = 0x13,
        sc2_intl3       = 0x6a,
        sc2_intl4       = 0x64,
        sc2_intl5       = 0x67,
        sc2_lang1       = 0xF2,
        sc2_lang2       = 0xF1,
        sc2_lang3       = 0x63,
        sc2_lang4       = 0x62,
        sc2_lang5       = 0x5f,

        sc2ex_rightCtrl = 0x14, // same as sc2_leftCtrl
        sc2ex_rightAlt  = 0x11, // same as sc2_leftAlt
        // Note that rightShift is not in the extended space.
        sc2ex_leftGui   = 0x1f,
        sc2ex_leftWindows = 0x1f,
        sc2ex_rightGui  = 0x27,
        sc2ex_rightWindows = 0x27,

        sc2ex_printScreen = 0x7c, // Note that PS2 keyboards generate a shift keyup&keydown artificially for this keystroke, usually.
        sc2ex_menu      = 0x2f, // "Apps" key in some circles

        sc2ex_home      = 0x6c,
        sc2ex_end       = 0x69,
        sc2ex_pageUp    = 0x7d,
        sc2ex_pageDown  = 0x7a,
        sc2ex_leftArrow = 0x6b,
        sc2ex_rightArrow = 0x74,
        sc2ex_upArrow   = 0x75,
        sc2ex_downArrow = 0x72,
        sc2ex_insert    = 0x70,
        sc2ex_delete    = 0x71,
        sc2ex_nextTrack = 0x4d,
        sc2ex_prevTrack = 0x15,
        sc2ex_stop      = 0x3b,
        sc2ex_play      = 0x34,
        sc2ex_mute      = 0x23,
        sc2ex_volumeUp  = 0x32,
        sc2ex_volumeDown = 0x21,
        sc2ex_mediaSelect = 0x50,
        sc2ex_email     = 0x48,
        sc2ex_calculator = 0x2b,
        sc2ex_myComputer = 0x40,
        sc2ex_webSearch = 0x10,
        sc2ex_webHome   = 0x3a,
        sc2ex_webBack   = 0x38,
        sc2ex_webForward = 0x30,
        sc2ex_webStop   = 0x28,
        sc2ex_webRefresh = 0x20,
        sc2ex_webFavorites = 0x18,
        sc2ex_power     = 0x37,
        sc2ex_sleep     = 0x3f,
        sc2ex_wake      = 0X5e,

        // All the sc3 values come from http://www.computer-engineering.org/ps2keyboard/scancodes3.html
        sc3_a           = 0x1c,
        sc3_b           = 0x32,
        sc3_c           = 0x21,
        sc3_d           = 0x23,
        sc3_e           = 0x24,
        sc3_f           = 0x2b,
        sc3_g           = 0x34,
        sc3_h           = 0x33,
        sc3_i           = 0x43,
        sc3_j           = 0x3b,
        sc3_k           = 0x42,
        sc3_l           = 0x4b,
        sc3_m           = 0x3a,
        sc3_n           = 0x31,
        sc3_o           = 0x44,
        sc3_p           = 0x4d,
        sc3_q           = 0x15,
        sc3_r           = 0x2d,
        sc3_s           = 0x1b,
        sc3_t           = 0x2c,
        sc3_u           = 0x3c,
        sc3_v           = 0x2a,
        sc3_w           = 0x1d,
        sc3_x           = 0x22,
        sc3_y           = 0x35,
        sc3_z           = 0x1a,

        sc3_0           = 0x45,
        sc3_1           = 0x16,
        sc3_2           = 0x1e,
        sc3_3           = 0x26,
        sc3_4           = 0x25,
        sc3_5           = 0x2e,
        sc3_6           = 0x36,
        sc3_7           = 0x3d,
        sc3_8           = 0x3e,
        sc3_9           = 0x46,

        sc3_keypadSlash = 0x4a,
        sc3_keypadAsterisk = 0x7e,
        sc3_keypadDash  = 0x4e,
        sc3_keypadPlus  = 0x7c,
        sc3_keypadEnter = 0x79,
        sc3_keypadPeriod = 0x71,
        sc3_keypad0     = 0x70,
        sc3_keypad1     = 0x69,
        sc3_keypad2     = 0x72,
        sc3_keypad3     = 0x7a,
        sc3_keypad4     = 0x6b,
        sc3_keypad5     = 0x73,
        sc3_keypad6     = 0x74,
        sc3_keypad7     = 0x6c,
        sc3_keypad8     = 0x75,
        sc3_keypad9     = 0x7d,

        sc3_f1          = 0x07,
        sc3_f2          = 0x0f,
        sc3_f3          = 0x17,
        sc3_f4          = 0x1f,
        sc3_f5          = 0x27,
        sc3_f6          = 0x2f,
        sc3_f7          = 0x37,
        sc3_f8          = 0x3f,
        sc3_f9          = 0x47,
        sc3_f10         = 0x4f,
        sc3_f11         = 0x56,
        sc3_f12         = 0x5e,

        sc3_openSquareBracket = 0x54,
        sc3_openQuote   = 0x0e,
        sc3_dash        = 0x4e,

        sc3_insert      = 0x67,
        sc3_home        = 0x6e,
        sc3_pageUp      = 0x6f,
        sc3_delete      = 0x64,
        sc3_end         = 0x65,
        sc3_pageDown    = 0x6d,
        sc3_upArrow     = 0x63,
        sc3_leftArrow   = 0x61,
        sc3_downArrow   = 0x60,
        sc3_rightArrow  = 0x6a,

        sc3_numLock     = 0x76,
        sc3_capsLock    = 0x14,

        sc3_leftShift   = 0x12,
        sc3_leftCtrl    = 0x11,
        sc3_leftGui     = 0x8b,
        sc3_leftWindows = 0x8b,
        sc3_leftAlt     = 0x19,
        sc3_rightShift  = 0x59,
        sc3_rightCtrl   = 0x58,
        sc3_rightGui    = 0x8c,
        sc3_rightWindows = 0x8c,
        sc3_rightAlt    = 0x39,

        sc3_backspace   = 0x66,
        sc3_tab         = 0x0d,
        sc3_space       = 0x29,
        sc3_enter       = 0x5a,

        sc3_equal       = 0x55,
        sc3_backslash   = 0x5c,
        sc3_escape      = 0x08,
        sc3_closeSquareBracket = 0x5b,
        sc3_semicolon   = 0x4c,
        sc3_apostrophe  = 0x52,
        sc3_comma       = 0x41,
        sc3_period      = 0x49,
        sc3_slash       = 0x4a,

        sc3_printScreen = 0x57,
        sc3_scrollLock  = 0x5f,
        sc3_pause       = 0x62,

        sc3_apps        = 0x8d,
        sc3_menu        = 0x8d,
    };
}
