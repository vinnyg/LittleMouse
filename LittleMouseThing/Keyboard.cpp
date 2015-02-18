#include "Keyboard.h"

namespace LM
{
	Keyboard::Keyboard() : m_keyState(SDL_GetKeyboardState(nullptr))
	{
	}


	Keyboard::~Keyboard()
	{
	}

	void Keyboard::SetModState(SDL_Keymod modState)
	{
		SDL_SetModState(modState);
	}

	int Keyboard::GetSDLScanCode(Key key)
	{
		switch (key)
		{
		case Key::Key_BACKSPACE: return SDL_SCANCODE_BACKSPACE; break;
		case Key::Key_TAB: return SDL_SCANCODE_TAB; break;
		case Key::Key_CLEAR: return SDL_SCANCODE_CLEAR; break;
		case Key::Key_RETURN: return SDL_SCANCODE_RETURN; break;
		case Key::Key_PAUSE: return SDL_SCANCODE_PAUSE; break;
		case Key::Key_ESCAPE: return SDL_SCANCODE_ESCAPE; break;
		case Key::Key_SPACE: return SDL_SCANCODE_SPACE; break;
		//case Key::Key_EXCLAIM: return SDL_SCANCODE_EXCLAIM; break;
		//case Key::Key_QUOTEDBL: return SDL_SCANCODE_QUOTEDBL; break;
		//case Key::Key_HASH: return SDL_SCANCODE_HASH; break;
		//case Key::Key_DOLLAR: return SDL_SCANCODE_DOLLAR; break;
		//case Key::Key_AMPERSAND: return SDL_SCANCODE_AMPERSAND; break;
		case Key::Key_QUOTE: return SDL_SCANCODE_APOSTROPHE; break;
		//case Key::Key_LEFTPAREN: return SDL_SCANCODE_LEFTPAREN; break;
		//case Key::Key_RIGHTPAREN: return SDL_SCANCODE_RIGHTPAREN; break;
		//case Key::Key_ASTERISK: return SDL_SCANCODE_ASTERISK; break;
		//case Key::Key_PLUS: return SDL_SCANCODE_PLUS; break;
		case Key::Key_COMMA: return SDL_SCANCODE_COMMA; break;
		case Key::Key_MINUS: return SDL_SCANCODE_MINUS; break;
		case Key::Key_PERIOD: return SDL_SCANCODE_PERIOD; break;
		case Key::Key_SLASH: return SDL_SCANCODE_SLASH; break;
		case Key::Key_0: return SDL_SCANCODE_0; break;
		case Key::Key_1: return SDL_SCANCODE_1; break;
		case Key::Key_2: return SDL_SCANCODE_2; break;
		case Key::Key_3: return SDL_SCANCODE_3; break;
		case Key::Key_4: return SDL_SCANCODE_4; break;
		case Key::Key_5: return SDL_SCANCODE_5; break;
		case Key::Key_6: return SDL_SCANCODE_6; break;
		case Key::Key_7: return SDL_SCANCODE_7; break;
		case Key::Key_8: return SDL_SCANCODE_8; break;
		case Key::Key_9: return SDL_SCANCODE_9; break;
		//case Key::Key_COLON: return SDL_SCANCODE_COLON; break;
		case Key::Key_SEMICOLON: return SDL_SCANCODE_SEMICOLON; break;
		//case Key::Key_LESS: return SDL_SCANCODE_LESS; break;
		case Key::Key_EQUALS: return SDL_SCANCODE_EQUALS; break;
		//case Key::Key_GREATER: return SDL_SCANCODE_GREATER; break;
		//case Key::Key_QUESTION: return SDL_SCANCODE_QUESTION; break;
		//case Key::Key_AT: return SDL_SCANCODE_AT; break;
		case Key::Key_LEFTBRACKET: return SDL_SCANCODE_LEFTBRACKET; break;
		case Key::Key_BACKSLASH: return SDL_SCANCODE_BACKSLASH; break;
		case Key::Key_RIGHTBRACKET: return SDL_SCANCODE_RIGHTBRACKET; break;
		//case Key::Key_CARET: return SDL_SCANCODE_CARET; break;
		//case Key::Key_UNDERSCORE: return SDL_SCANCODE_UNDERSCORE; break;
		case Key::Key_BACKQUOTE: return SDL_SCANCODE_GRAVE; break;
		case Key::Key_a: return SDL_SCANCODE_A; break;
		case Key::Key_b: return SDL_SCANCODE_B; break;
		case Key::Key_c: return SDL_SCANCODE_C; break;
		case Key::Key_d: return SDL_SCANCODE_D; break;
		case Key::Key_e: return SDL_SCANCODE_E; break;
		case Key::Key_f: return SDL_SCANCODE_F; break;
		case Key::Key_g: return SDL_SCANCODE_G; break;
		case Key::Key_h: return SDL_SCANCODE_H; break;
		case Key::Key_i: return SDL_SCANCODE_I; break;
		case Key::Key_j: return SDL_SCANCODE_J; break;
		case Key::Key_k: return SDL_SCANCODE_K; break;
		case Key::Key_l: return SDL_SCANCODE_L; break;
		case Key::Key_m: return SDL_SCANCODE_M; break;
		case Key::Key_n: return SDL_SCANCODE_N; break;
		case Key::Key_o: return SDL_SCANCODE_O; break;
		case Key::Key_p: return SDL_SCANCODE_P; break;
		case Key::Key_q: return SDL_SCANCODE_Q; break;
		case Key::Key_r: return SDL_SCANCODE_R; break;
		case Key::Key_s: return SDL_SCANCODE_S; break;
		case Key::Key_t: return SDL_SCANCODE_T; break;
		case Key::Key_u: return SDL_SCANCODE_U; break;
		case Key::Key_v: return SDL_SCANCODE_V; break;
		case Key::Key_w: return SDL_SCANCODE_W; break;
		case Key::Key_x: return SDL_SCANCODE_X; break;
		case Key::Key_y: return SDL_SCANCODE_Y; break;
		case Key::Key_z: return SDL_SCANCODE_Z; break;
		case Key::Key_DELETE: return SDL_SCANCODE_DELETE; break;
		case Key::Key_KP0: return SDL_SCANCODE_KP_1; break;
		case Key::Key_KP1: return SDL_SCANCODE_KP_1; break;
		case Key::Key_KP2: return SDL_SCANCODE_KP_2; break;
		case Key::Key_KP3: return SDL_SCANCODE_KP_3; break;
		case Key::Key_KP4: return SDL_SCANCODE_KP_4; break;
		case Key::Key_KP5: return SDL_SCANCODE_KP_5; break;
		case Key::Key_KP6: return SDL_SCANCODE_KP_6; break;
		case Key::Key_KP7: return SDL_SCANCODE_KP_7; break;
		case Key::Key_KP8: return SDL_SCANCODE_KP_8; break;
		case Key::Key_KP9: return SDL_SCANCODE_KP_9; break;
		case Key::Key_KP_PERIOD: return SDL_SCANCODE_KP_PERIOD; break;
		case Key::Key_KP_DIVIDE: return SDL_SCANCODE_KP_DIVIDE; break;
		case Key::Key_KP_MULTIPLY: return SDL_SCANCODE_KP_MULTIPLY; break;
		case Key::Key_KP_MINUS: return SDL_SCANCODE_KP_MINUS; break;
		case Key::Key_KP_PLUS: return SDL_SCANCODE_KP_PLUS; break;
		case Key::Key_KP_ENTER: return SDL_SCANCODE_KP_ENTER; break;
		case Key::Key_KP_EQUALS: return SDL_SCANCODE_KP_EQUALS; break;
		case Key::Key_UP: return SDL_SCANCODE_UP; break;
		case Key::Key_DOWN: return SDL_SCANCODE_DOWN; break;
		case Key::Key_RIGHT: return SDL_SCANCODE_RIGHT; break;
		case Key::Key_LEFT: return SDL_SCANCODE_LEFT; break;
		case Key::Key_INSERT: return SDL_SCANCODE_INSERT; break;
		case Key::Key_HOME: return SDL_SCANCODE_HOME; break;
		case Key::Key_END: return SDL_SCANCODE_END; break;
		case Key::Key_PAGEUP: return SDL_SCANCODE_PAGEUP; break;
		case Key::Key_PAGEDOWN: return SDL_SCANCODE_PAGEDOWN; break;
		case Key::Key_F1: return SDL_SCANCODE_F1; break;
		case Key::Key_F2: return SDL_SCANCODE_F2; break;
		case Key::Key_F3: return SDL_SCANCODE_F3; break;
		case Key::Key_F4: return SDL_SCANCODE_F4; break;
		case Key::Key_F5: return SDL_SCANCODE_F5; break;
		case Key::Key_F6: return SDL_SCANCODE_F6; break;
		case Key::Key_F7: return SDL_SCANCODE_F7; break;
		case Key::Key_F8: return SDL_SCANCODE_F8; break;
		case Key::Key_F9: return SDL_SCANCODE_F9; break;
		case Key::Key_F10: return SDL_SCANCODE_F10; break;
		case Key::Key_F11: return SDL_SCANCODE_F11; break;
		case Key::Key_F12: return SDL_SCANCODE_F12; break;
		case Key::Key_F13: return SDL_SCANCODE_F13; break;
		case Key::Key_F14: return SDL_SCANCODE_F14; break;
		case Key::Key_F15: return SDL_SCANCODE_F15; break;
		case Key::Key_NUMLOCK: return SDL_SCANCODE_NUMLOCKCLEAR; break;
		case Key::Key_CAPSLOCK: return SDL_SCANCODE_CAPSLOCK; break;
		case Key::Key_SCROLLOCK: return SDL_SCANCODE_SCROLLLOCK; break;
		case Key::Key_RSHIFT: return SDL_SCANCODE_RSHIFT; break;
		case Key::Key_LSHIFT: return SDL_SCANCODE_LSHIFT; break;
		case Key::Key_RCTRL: return SDL_SCANCODE_RCTRL; break;
		case Key::Key_LCTRL: return SDL_SCANCODE_LCTRL; break;
		case Key::Key_RALT: return SDL_SCANCODE_RALT; break;
		case Key::Key_LALT: return SDL_SCANCODE_LALT; break;
		case Key::Key_RGUI: return SDL_SCANCODE_RGUI; break;
		case Key::Key_LGUI: return SDL_SCANCODE_LGUI; break;
		case Key::Key_MODE: return SDL_SCANCODE_MODE; break;
		case Key::Key_HELP: return SDL_SCANCODE_HELP; break;
		case Key::Key_PRINT: return SDL_SCANCODE_PRINTSCREEN; break;
		case Key::Key_SYSREQ: return SDL_SCANCODE_SYSREQ; break;
		case Key::Key_BREAK: return SDL_SCANCODE_PAUSE; break;
		case Key::Key_MENU: return SDL_SCANCODE_MENU; break;
		case Key::Key_POWER: return SDL_SCANCODE_POWER; break;
		default: return -1;
			//case Key::Key_NUMBER_OF_KEYS return SDL_SCANCODE_NUMBER_OF_KEYS; break;
		}
	}

	bool Keyboard::IsKeyHeld(Key key)
	{
		//m_keyState = GetState(nullptr);

		//return m_state.at(key);

		return m_keyState[GetSDLScanCode(key)];
	}

	const Uint8* Keyboard::GetState(int* numKeys)
	{
		//m_keyState = SDL_GetKeyboardState(numKeys);
		return m_keyState;
	}

	SDL_Keymod Keyboard::GetModState()
	{
		return SDL_GetModState();
	}
}
