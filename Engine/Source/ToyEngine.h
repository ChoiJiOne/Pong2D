#include <AudioComponent.h>
#include <UIButton.h>
#include <Camera.h>
#include <Color.h>
#include <CommandLineManager.h>
#include <Component.h>
#include <ContentManager.h>
#include <Debug.h>
#include <Font.h>
#include <GameFramework.h>
#include <GameObject.h>
#include <Input.h>
#include <InputComponent.h>
#include <Macro.h>
#include <Math.hpp>
#include <Music.h>
#include <PhysicComponent.h>
#include <RenderComponent.h>
#include <Renderer.h>
#include <RigidBodyComponent.h>
#include <Sound.h>
#include <Text.hpp>
#include <Texture.h>
#include <Timer.h>
#include <Vector.hpp>
#include <Window.h>
#include <World.h>

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