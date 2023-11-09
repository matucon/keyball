#ifdef PRECISION_ENABLE

#include QMK_KEYBOARD_H

static const uint16_t PROGMEM down_cpi = PRECISION_CPI;

static uint16_t latest_cpi = 1;
static bool     cpi_state  = false;

// トグルで切り替え
void precision_toggle(bool pressed) {
    if (!pressed) {
        return;
    }
    
    uint16_t current_cpi = keyball_get_cpi();
    if (!cpi_state || down_cpi != current_cpi) {
        latest_cpi = current_cpi;
        keyball_set_cpi(down_cpi);
        cpi_state = true;
    } else {
        keyball_set_cpi(latest_cpi);
        cpi_state = false;
    }
}

// キー押下中だけ切り替え
void precision_switch(bool pressed) {
    if (pressed) {
        if(!cpi_state) {
            latest_cpi = keyball_get_cpi();
        }
        keyball_set_cpi(down_cpi);
    } else {
        keyball_set_cpi(latest_cpi);
    }
}

#endif
