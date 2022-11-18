#include "Core/AudioComponent.h"
#include "Core/RenderComponent.h"
#include "Core/InputComponent.h"
#include "Core/PhysicComponent.h"
#include "Core/RigidBodyComponent.h"
#include "Core/Camera.h"
#include "Core/GameFramework.h"
#include "Core/GameObject.h"
#include "Core/Renderer.h"
#include "Core/Input.h"
#include "Core/Timer.h"
#include "Core/Window.h"
#include "Core/World.h"

#include "Misc/ColorUtils.h"
#include "Misc/CommandLineUtils.h"
#include "Misc/ContentUtils.h"
#include "Misc/DebugUtils.h"
#include "Misc/MacroUtils.h"
#include "Misc/MathUtils.h"
#include "Misc/TextUtils.h"
#include "Misc/Vector.h"

#include "Resource/Font.h"
#include "Resource/Music.h"
#include "Resource/Sound.h"
#include "Resource/Texture.h"

#include "UI/Button.h"

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