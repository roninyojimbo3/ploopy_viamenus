#if defined(TAP_DANCE_ENABLE)

    #if defined(BETTER_DRAGSCROLL_TAPDANCE)
        #include "better_dragscroll.h"
        void dragscrolltd_fin(tap_dance_state_t *state, void *user_data){
            dprintf("fin; pressed:%d count:%d \n", state->pressed, state->count);
            if(state->count >= 2){
                better_dragscroll_toggle(true);
            }
            else{
                better_dragscroll_momentary(true);
            }
        }
        void dragscrolltd_rst(tap_dance_state_t *state, void *user_data){
            if(state->count < 2){
                better_dragscroll_momentary(false);
            }
        }
    #endif // BETTER_DRAGSCROLL_TAPDANCE

#if defined(NANO2_CLICK_TAPDANCE)
    static bool nano_dragging = false;

    void nano_click_finished(tap_dance_state_t *state, void *user_data) {
        if (state->count == 1) {
            if (state->pressed) {
                register_code(MS_BTN1);   // hold = hold left click for drag
                nano_dragging = true;
            } else {
                tap_code(MS_BTN1);        // single tap = left click
            }
        } else {
            tap_code(MS_BTN2);            // double tap or more = right click
        }
    }

    void nano_click_reset(tap_dance_state_t *state, void *user_data) {
        if (nano_dragging) {
            unregister_code(MS_BTN1);     // release left click after drag
            nano_dragging = false;
        }
    }
#endif // NANO2_CLICK_TAPDANCE

    tap_dance_action_t tap_dance_actions[] = {
        #if defined(BETTER_DRAGSCROLL_TAPDANCE) || defined(BETTER_DRAGSCROLL_TAPDANCE_FN_ADVANCE)
            [TD_DRAGSCROLL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dragscrolltd_fin, dragscrolltd_rst),
        #endif // BETTER_DRAGSCROLL_TAPDANCE

        #if defined(NANO2_CLICK_TAPDANCE)
            [TD_NANO_CLICK] = ACTION_TAP_DANCE_FN(nano_click_finished),
        #endif // NANO2_CLICK_TAPDANCE
    };

#endif // TAP_DANCE_ENABLE
