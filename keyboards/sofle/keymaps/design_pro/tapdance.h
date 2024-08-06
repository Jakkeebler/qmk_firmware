#include QMK_KEYBOARD_H


// Tap Dance Declaration
enum {
    DANCE_ESC,
    DANCE_MINS,
    DANCE_EQL,
    DANCE_LBRC,
    DANCE_RBRC,
    DANCE_0,
    DANCE_1,
    DANCE_2,
    DANCE_3,
    DANCE_5,
    DANCE_7,
    DANCE_8,
    DANCE_A,
    DANCE_B,
    DANCE_C,
    DANCE_D,
    DANCE_E,
    DANCE_F,
    DANCE_G,
    DANCE_H,
    DANCE_I,
    DANCE_J,
    DANCE_K,
    DANCE_L,
    DANCE_N,
    DANCE_O,
    DANCE_P,
    DANCE_Q,
    DANCE_R,
    DANCE_S,
    DANCE_T,
    DANCE_V,
    DANCE_W,
    DANCE_X,
    DANCE_Y,
    DANCE_Z,
    TAP_DANCE_COUNT
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Dance Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Dance Escape
void on_dance_ESC(tap_dance_state_t *state, void *user_data);
void dance_ESC_finished(tap_dance_state_t *state, void *user_data);
void dance_ESC_reset(tap_dance_state_t *state, void *user_data);

// Dance Minus
void on_dance_MINS(tap_dance_state_t *state, void *user_data);
void dance_MINS_finished(tap_dance_state_t *state, void *user_data);
void dance_MINS_reset(tap_dance_state_t *state, void *user_data);

// Dance Equals
void on_dance_EQL(tap_dance_state_t *state, void *user_data);
void dance_EQL_finished(tap_dance_state_t *state, void *user_data);
void dance_EQL_reset(tap_dance_state_t *state, void *user_data);

// Dance Left Bracket
void on_dance_LBRC(tap_dance_state_t *state, void *user_data);
void dance_LBRC_finished(tap_dance_state_t *state, void *user_data);
void dance_LBRC_reset(tap_dance_state_t *state, void *user_data);

// Dance Right Bracket
void on_dance_RBRC(tap_dance_state_t *state, void *user_data);
void dance_RBRC_finished(tap_dance_state_t *state, void *user_data);
void dance_RBRC_reset(tap_dance_state_t *state, void *user_data);

// Dance 0
void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

// Dance 1
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

// Dance 2
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

// Dance 3
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

// Dance 5
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

// Dance 7
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

// Dance 8
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

// Dance A
void on_dance_A(tap_dance_state_t *state, void *user_data);
void dance_A_finished(tap_dance_state_t *state, void *user_data);
void dance_A_reset(tap_dance_state_t *state, void *user_data);

// Dance B
void on_dance_B(tap_dance_state_t *state, void *user_data);
void dance_B_finished(tap_dance_state_t *state, void *user_data);
void dance_B_reset(tap_dance_state_t *state, void *user_data);

// Dance C
void on_dance_C(tap_dance_state_t *state, void *user_data);
void dance_C_finished(tap_dance_state_t *state, void *user_data);
void dance_C_reset(tap_dance_state_t *state, void *user_data);

// Dance D
void on_dance_D(tap_dance_state_t *state, void *user_data);
void dance_D_finished(tap_dance_state_t *state, void *user_data);
void dance_D_reset(tap_dance_state_t *state, void *user_data);

// Dance E
void on_dance_E(tap_dance_state_t *state, void *user_data);
void dance_E_finished(tap_dance_state_t *state, void *user_data);
void dance_E_reset(tap_dance_state_t *state, void *user_data);

// Dance F
void on_dance_F(tap_dance_state_t *state, void *user_data);
void dance_F_finished(tap_dance_state_t *state, void *user_data);
void dance_F_reset(tap_dance_state_t *state, void *user_data);

// Dance G
void on_dance_G(tap_dance_state_t *state, void *user_data);
void dance_G_finished(tap_dance_state_t *state, void *user_data);
void dance_G_reset(tap_dance_state_t *state, void *user_data);

// Dance H
void on_dance_H(tap_dance_state_t *state, void *user_data);
void dance_H_finished(tap_dance_state_t *state, void *user_data);
void dance_H_reset(tap_dance_state_t *state, void *user_data);

// Dance I
void on_dance_I(tap_dance_state_t *state, void *user_data);
void dance_I_finished(tap_dance_state_t *state, void *user_data);
void dance_I_reset(tap_dance_state_t *state, void *user_data);

// Dance J
void on_dance_J(tap_dance_state_t *state, void *user_data);
void dance_J_finished(tap_dance_state_t *state, void *user_data);
void dance_J_reset(tap_dance_state_t *state, void *user_data);

// Dance K
void on_dance_K(tap_dance_state_t *state, void *user_data);
void dance_K_finished(tap_dance_state_t *state, void *user_data);
void dance_K_reset(tap_dance_state_t *state, void *user_data);

// Dance L
void on_dance_L(tap_dance_state_t *state, void *user_data);
void dance_L_finished(tap_dance_state_t *state, void *user_data);
void dance_L_reset(tap_dance_state_t *state, void *user_data);

// Dance N
void on_dance_N(tap_dance_state_t *state, void *user_data);
void dance_N_finished(tap_dance_state_t *state, void *user_data);
void dance_N_reset(tap_dance_state_t *state, void *user_data);

// Dance O
void on_dance_O(tap_dance_state_t *state, void *user_data);
void dance_O_finished(tap_dance_state_t *state, void *user_data);
void dance_O_reset(tap_dance_state_t *state, void *user_data);

// Dance P
void on_dance_P(tap_dance_state_t *state, void *user_data);
void dance_P_finished(tap_dance_state_t *state, void *user_data);
void dance_P_reset(tap_dance_state_t *state, void *user_data);

// Dance Q
void on_dance_Q(tap_dance_state_t *state, void *user_data);
void dance_Q_finished(tap_dance_state_t *state, void *user_data);
void dance_Q_reset(tap_dance_state_t *state, void *user_data);

// Dance R
void on_dance_R(tap_dance_state_t *state, void *user_data);
void dance_R_finished(tap_dance_state_t *state, void *user_data);
void dance_R_reset(tap_dance_state_t *state, void *user_data);

// Dance S
void on_dance_S(tap_dance_state_t *state, void *user_data);
void dance_S_finished(tap_dance_state_t *state, void *user_data);
void dance_S_reset(tap_dance_state_t *state, void *user_data);

// Dance T
void on_dance_T(tap_dance_state_t *state, void *user_data);
void dance_T_finished(tap_dance_state_t *state, void *user_data);
void dance_T_reset(tap_dance_state_t *state, void *user_data);

// Dance V
void on_dance_V(tap_dance_state_t *state, void *user_data);
void dance_V_finished(tap_dance_state_t *state, void *user_data);
void dance_V_reset(tap_dance_state_t *state, void *user_data);

// Dance W
void on_dance_W(tap_dance_state_t *state, void *user_data);
void dance_W_finished(tap_dance_state_t *state, void *user_data);
void dance_W_reset(tap_dance_state_t *state, void *user_data);

// Dance X
void on_dance_X(tap_dance_state_t *state, void *user_data);
void dance_X_finished(tap_dance_state_t *state, void *user_data);
void dance_X_reset(tap_dance_state_t *state, void *user_data);

// Dance Y
void on_dance_Y(tap_dance_state_t *state, void *user_data);
void dance_Y_finished(tap_dance_state_t *state, void *user_data);
void dance_Y_reset(tap_dance_state_t *state, void *user_data);

// Dance Z
void on_dance_Z(tap_dance_state_t *state, void *user_data);
void dance_Z_finished(tap_dance_state_t *state, void *user_data);
void dance_Z_reset(tap_dance_state_t *state, void *user_data);
