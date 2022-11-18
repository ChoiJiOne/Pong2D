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
 * 엔진을 초기화/해제 하는 클래스입니다.
 * 이때, 반드시 초기에 Init, 마지막에 Quit 메서드를 호출해야 합니다.
 * 이 클래스는 정적 클래스로, 해더 선언만 추가하면 바로 사용할 수 있습니다.
 */
class ToyEngine
{
public:
	/**
	 * ToyEngine을 초기화합니다.
	 */
	static void Init();


	/**
	 * ToyEngine을 해제합니다.
	 */
	static void Quit();
};