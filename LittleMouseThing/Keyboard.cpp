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
		case Key::Key_BACKSPACE: return SDLK_BACKSPACE; break;
		case Key::Key_TAB: return SDLK_TAB; break;
		case Key::Key_CLEAR: return SDLK_CLEAR; break;
		case Key::Key_RETURN: return SDLK_RETURN; break;
		case Key::Key_PAUSE: return SDLK_PAUSE; break;
		case Key::Key_ESCAPE: return SDLK_ESCAPE; break;
		case Key::Key_SPACE: return SDLK_SPACE; break;
		case Key::Key_EXCLAIM: return SDLK_EXCLAIM; break;
		case Key::Key_QUOTEDBL: return SDLK_QUOTEDBL; break;
		case Key::Key_HASH: return SDLK_HASH; break;
		case Key::Key_DOLLAR: return SDLK_DOLLAR; break;
		case Key::Key_AMPERSAND: return SDLK_AMPERSAND; break;
		case Key::Key_QUOTE: return SDLK_QUOTE; break;
		case Key::Key_LEFTPAREN: return SDLK_LEFTPAREN; break;
		case Key::Key_RIGHTPAREN: return SDLK_RIGHTPAREN; break;
		case Key::Key_ASTERISK: return SDLK_ASTERISK; break;
		case Key::Key_PLUS: return SDLK_PLUS; break;
		case Key::Key_COMMA: return SDLK_COMMA; break;
		case Key::Key_MINUS: return SDLK_MINUS; break;
		case Key::Key_PERIOD: return SDLK_PERIOD; break;
		case Key::Key_SLASH: return SDLK_SLASH; break;
		case Key::Key_0: return SDLK_0; break;
		case Key::Key_1: return SDLK_1; break;
		case Key::Key_2: return SDLK_2; break;
		case Key::Key_3: return SDLK_3; break;
		case Key::Key_4: return SDLK_4; break;
		case Key::Key_5: return SDLK_5; break;
		case Key::Key_6: return SDLK_6; break;
		case Key::Key_7: return SDLK_7; break;
		case Key::Key_8: return SDLK_8; break;
		case Key::Key_9: return SDLK_9; break;
		case Key::Key_COLON: return SDLK_COLON; break;
		case Key::Key_SEMICOLON: return SDLK_SEMICOLON; break;
		case Key::Key_LESS: return SDLK_LESS; break;
		case Key::Key_EQUALS: return SDLK_EQUALS; break;
		case Key::Key_GREATER: return SDLK_GREATER; break;
		case Key::Key_QUESTION: return SDLK_QUESTION; break;
		case Key::Key_AT: return SDLK_AT; break;
		case Key::Key_LEFTBRACKET: return SDLK_LEFTBRACKET; break;
		case Key::Key_BACKSLASH: return SDLK_BACKSLASH; break;
		case Key::Key_RIGHTBRACKET: return SDLK_RIGHTBRACKET; break;
		case Key::Key_CARET: return SDLK_CARET; break;
		case Key::Key_UNDERSCORE: return SDLK_UNDERSCORE; break;
		case Key::Key_BACKQUOTE: return SDLK_BACKQUOTE; break;
		case Key::Key_a: return SDLK_a; break;
		case Key::Key_b: return SDLK_b; break;
		case Key::Key_c: return SDLK_c; break;
		case Key::Key_d: return SDLK_d; break;
		case Key::Key_e: return SDLK_e; break;
		case Key::Key_f: return SDLK_f; break;
		case Key::Key_g: return SDLK_g; break;
		case Key::Key_h: return SDLK_h; break;
		case Key::Key_i: return SDLK_i; break;
		case Key::Key_j: return SDLK_j; break;
		case Key::Key_k: return SDLK_k; break;
		case Key::Key_l: return SDLK_l; break;
		case Key::Key_m: return SDLK_m; break;
		case Key::Key_n: return SDLK_n; break;
		case Key::Key_o: return SDLK_o; break;
		case Key::Key_p: return SDLK_p; break;
		case Key::Key_q: return SDLK_q; break;
		case Key::Key_r: return SDLK_r; break;
		case Key::Key_s: return SDLK_s; break;
		case Key::Key_t: return SDLK_t; break;
		case Key::Key_u: return SDLK_u; break;
		case Key::Key_v: return SDLK_v; break;
		case Key::Key_w: return SDLK_w; break;
		case Key::Key_x: return SDLK_x; break;
		case Key::Key_y: return SDLK_y; break;
		case Key::Key_z: return SDLK_z; break;
		case Key::Key_DELETE: return SDLK_DELETE; break;
		case Key::Key_KP0: return SDLK_KP_1; break;
		case Key::Key_KP1: return SDLK_KP_1; break;
		case Key::Key_KP2: return SDLK_KP_2; break;
		case Key::Key_KP3: return SDLK_KP_3; break;
		case Key::Key_KP4: return SDLK_KP_4; break;
		case Key::Key_KP5: return SDLK_KP_5; break;
		case Key::Key_KP6: return SDLK_KP_6; break;
		case Key::Key_KP7: return SDLK_KP_7; break;
		case Key::Key_KP8: return SDLK_KP_8; break;
		case Key::Key_KP9: return SDLK_KP_9; break;
		case Key::Key_KP_PERIOD: return SDLK_KP_PERIOD; break;
		case Key::Key_KP_DIVIDE: return SDLK_KP_DIVIDE; break;
		case Key::Key_KP_MULTIPLY: return SDLK_KP_MULTIPLY; break;
		case Key::Key_KP_MINUS: return SDLK_KP_MINUS; break;
		case Key::Key_KP_PLUS: return SDLK_KP_PLUS; break;
		case Key::Key_KP_ENTER: return SDLK_KP_ENTER; break;
		case Key::Key_KP_EQUALS: return SDLK_KP_EQUALS; break;
		case Key::Key_UP: return SDLK_UP; break;
		case Key::Key_DOWN: return SDLK_DOWN; break;
		case Key::Key_RIGHT: return SDLK_RIGHT; break;
		case Key::Key_LEFT: return SDLK_LEFT; break;
		case Key::Key_INSERT: return SDLK_INSERT; break;
		case Key::Key_HOME: return SDLK_HOME; break;
		case Key::Key_END: return SDLK_END; break;
		case Key::Key_PAGEUP: return SDLK_PAGEUP; break;
		case Key::Key_PAGEDOWN: return SDLK_PAGEDOWN; break;
		case Key::Key_F1: return SDLK_F1; break;
		case Key::Key_F2: return SDLK_F2; break;
		case Key::Key_F3: return SDLK_F3; break;
		case Key::Key_F4: return SDLK_F4; break;
		case Key::Key_F5: return SDLK_F5; break;
		case Key::Key_F6: return SDLK_F6; break;
		case Key::Key_F7: return SDLK_F7; break;
		case Key::Key_F8: return SDLK_F8; break;
		case Key::Key_F9: return SDLK_F9; break;
		case Key::Key_F10: return SDLK_F10; break;
		case Key::Key_F11: return SDLK_F11; break;
		case Key::Key_F12: return SDLK_F12; break;
		case Key::Key_F13: return SDLK_F13; break;
		case Key::Key_F14: return SDLK_F14; break;
		case Key::Key_F15: return SDLK_F15; break;
		case Key::Key_NUMLOCK: return SDLK_NUMLOCKCLEAR; break;
		case Key::Key_CAPSLOCK: return SDLK_CAPSLOCK; break;
		case Key::Key_SCROLLOCK: return SDLK_SCROLLLOCK; break;
		case Key::Key_RSHIFT: return SDLK_RSHIFT; break;
		case Key::Key_LSHIFT: return SDLK_LSHIFT; break;
		case Key::Key_RCTRL: return SDLK_RCTRL; break;
		case Key::Key_LCTRL: return SDLK_LCTRL; break;
		case Key::Key_RALT: return SDLK_RALT; break;
		case Key::Key_LALT: return SDLK_LALT; break;
		case Key::Key_RGUI: return SDLK_RGUI; break;
		case Key::Key_LGUI: return SDLK_LGUI; break;
		case Key::Key_MODE: return SDLK_MODE; break;
		case Key::Key_HELP: return SDLK_HELP; break;
		case Key::Key_PRINT: return SDLK_PRINTSCREEN; break;
		case Key::Key_SYSREQ: return SDLK_SYSREQ; break;
		case Key::Key_BREAK: return SDLK_PAUSE; break;
		case Key::Key_MENU: return SDLK_MENU; break;
		case Key::Key_POWER: return SDLK_POWER; break;
		default: return -1;
			//case Key::Key_NUMBER_OF_KEYS return SDLK_NUMBER_OF_KEYS; break;
		}
	}

	bool Keyboard::IsKeyHeld(Key key)
	{
		m_keyState = GetState(nullptr);

		//return m_state.at(key);

		return m_keyState[GetSDLScanCode(key)];
	}

	Uint8* Keyboard::GetState(int* numKeys)
	{
		m_keyState = SDL_GetKeyboardState(numKeys);
		return 0;
	}

	SDL_Keymod Keyboard::GetModState()
	{
		return SDL_GetModState();
	}
}
