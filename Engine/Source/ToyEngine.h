#include "Body.h"
#include "Button.h"
#include "ColorUtils.h"
#include "CommandLineUtils.h"
#include "ContentUtils.h"
#include "DebugUtils.h"
#include "Font.h"
#include "GameFramework.h"
#include "GameObject.h"
#include "Input.h"
#include "InputComponent.h"
#include "Graphics.h"
#include "GraphicsComponent.h"
#include "Macro.h"
#include "MathUtils.h"
#include "Music.h"
#include "PhysicComponent.h"
#include "Sound.h"
#include "Text.h"
#include "Texture.h"
#include "Timer.h"
#include "Vector.h"
#include "Window.h"
#include "World.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>
#include <json/json.hpp>
#include <spdlog/spdlog.h>
#include <stb/stb_image.h>
#include <stb/stb_image_resize.h>
#include <stb/stb_image_write.h>
#include <stb/stb_rect_pack.h>
#include <stb/stb_truetype.h>

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <stack>
#include <queue>


/**
 * ������ �ʱ�ȭ/���� �ϴ� Ŭ�����Դϴ�.
 * �̶�, �ݵ�� �ʱ⿡ Init, �������� Quit �޼��带 ȣ���ؾ� �մϴ�.
 * �� Ŭ������ ���� Ŭ������, �ش� ���� �߰��ϸ� �ٷ� ����� �� �ֽ��ϴ�.
 */
class ToyEngine
{
public:
	/**
	 * ToyEngine�� �ʱ�ȭ�մϴ�.
	 */
	static void Init();


	/**
	 * ToyEngine�� �����մϴ�.
	 */
	static void Quit();
};