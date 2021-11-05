#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GRV,          KC_Q,         KC_W, KC_F, KC_P, KC_G,   KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN,         KC_BSLS,
        LSFT_T(KC_CAPS), KC_A,         KC_R, KC_S, KC_T, KC_D,   KC_H, KC_N, KC_E,    KC_I,   KC_O,            RSFT_T(KC_QUOT),
        LCTL_T(KC_F12),  LALT_T(KC_Z), KC_X, KC_C, KC_V, KC_B,   KC_K, KC_M, KC_COMM, KC_DOT, RALT_T(KC_SLSH), RCTL_T(KC_ESC),
                           LT(4,KC_TAB), KC_SPC, LT(5,KC_DEL),   LT(1,KC_BSPC), KC_SFTENT, LT(2,KC_NO)
    ),

    [1] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,   KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_BTN1,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,   KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, KC_BTN2,
                             KC_NO, KC_NO, MO(7),     KC_TRNS, KC_NO,   KC_NO
    ),

    [2] = LAYOUT(
        KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,   KC_LPRN, KC_LCBR, KC_LBRC, KC_LT,   KC_NO,
        KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,   KC_RPRN, KC_RCBR, KC_RBRC, KC_GT,   KC_NO,
        KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_PMNS, KC_UNDS, KC_PPLS, KC_EQL,  KC_PDOT, KC_GRV,
                               KC_NO, KC_NO, KC_NO,      KC_NO,  KC_NO,   KC_TRNS
    ),

    [3] = LAYOUT(
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                               KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO
    ),

    [4] = LAYOUT(
        KC_GRV,  KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PSLS,
        KC_LSFT, KC_1,    KC_2,  KC_3,    KC_4,   KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PDOT,
        KC_NO,   KC_F1,   KC_F2, KC_F3,   KC_F4,  KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PEQL,
                                 KC_TRNS, KC_NO,  KC_NO,     KC_NO,   KC_NO,   KC_NO
    ),

    [5] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,   KC_P7,   KC_P8, KC_P9, KC_PPLS, KC_PAST,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,   KC_P4,   KC_P5, KC_P6, KC_PMNS, KC_PSLS,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,   KC_P1,   KC_P2, KC_P3, KC_PEQL, KC_NO,
                             KC_NO, KC_NO, KC_TRNS,   KC_TRNS, KC_PENT, KC_P0
    ),

    [6] = LAYOUT(
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                               KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO
    ),
};

#ifdef OLED_ENABLE
void oled_task_user(void) {
    // Vanity Text
    static bool show_vanity_text = true;
    if (show_vanity_text) {
        oled_write_ln_P(PSTR("  Santoku Keyboard"), false);
        oled_write_ln_P(PSTR("       by Tye"), false);
        oled_write_ln_P(PSTR(""), false);
        oled_write_ln_P(PSTR("  Hello, Tamagotono!"), false);
        if (timer_read() > 7500) {
            show_vanity_text = false;
        }
    }
    else {
        uint8_t wpm = get_current_wpm();
        if (wpm < 20) {
            oled_write("      ", false);
        }
        else {
            char wpm_display[9];
            sprintf(wpm_display, "WPM:%d ", get_current_wpm());
            oled_write(wpm_display, false);
        }

        // Host Keyboard Layer Status
        switch (get_highest_layer(layer_state)) {
            case 0:
                oled_write_ln_P(PSTR("Big Mac"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("`   qwfpg | jluy;\\"), false);
                oled_write_ln_P(PSTR("Sh  arstd | hneio'"), false);
                oled_write_ln_P(PSTR("Ct  zxcvb | km,./Es"), false);
                oled_write_ln_P(PSTR("Ta Sp Del | Bk Ent "), false);
                oled_write_ln_P(PSTR("L4 Sp L5  | L1 Sh L2"), false);
                break;
            case 1:
                oled_write_ln_P(PSTR(" Get around! "), true);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("| Hm PgU PgD End"), false);
                oled_write_ln_P(PSTR("| <  ^   v   >  Bt1"), false);
                oled_write_ln_P(PSTR("| M< M^  Mv  M> Bt2"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR(""), false);
                break;
            case 2:
                oled_write_ln_P(PSTR(" Open&Shut Case"), true);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("    |   ( { [ <"), false);
                oled_write_ln_P(PSTR("    |   ) } ] >"), false);
                oled_write_ln_P(PSTR("    | - _ + = . `"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR(""), false);
                break;
            case 3:
                oled_write_ln_P(PSTR("No keys for you!"), true);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR(""), false);
                break;
            case 4:
                oled_write_ln_P(PSTR(" Top Shelf "), true);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("   `!@#$% | ^&*()/"), false);
                oled_write_ln_P(PSTR("    12345 | 67890."), false);
                oled_write_ln_P(PSTR("   F12345 | 78910="), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR(""), false);
                break;
            case 5:
                oled_write_ln_P(PSTR(" 10key FTW! "), true);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("    | 7 8 9 + *"), false);
                oled_write_ln_P(PSTR("    | 4 5 6 - /"), false);
                oled_write_ln_P(PSTR("    | 1 2 3 = "), false);
                oled_write_ln_P(PSTR("    |  Ent 0"), false);
                oled_write_ln_P(PSTR(""), false);
                break;
            case 6:
                oled_write_ln_P(PSTR("No keys for you!"), true);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR(""), false);
                break;
            default:
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("This is not the"), false);
                oled_write_ln_P(PSTR("layer you're"), false);
                oled_write_ln_P(PSTR("looking for"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR(""), false);
        }
    }
}
#endif
