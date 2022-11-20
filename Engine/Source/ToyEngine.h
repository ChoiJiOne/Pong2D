#include <AudioComponent.h>
#include <RenderComponent.h>
#include <InputComponent.h>
#include <PhysicComponent.h>
#include <RigidBodyComponent.h>
#include <Camera.h>
#include <GameFramework.h>
#include <GameObject.h>
#include <Renderer.h>
#include <Input.h>
#include <Timer.h>
#include <Window.h>
#include <World.h>
#include <Color.h>
#include <CommandLineUtils.h>
#include <ContentTracker.h>
#include <Debug.h>
#include <Macro.h>
#include <Math.hpp>
#include <Text.hpp>
#include <Vector.hpp>
#include <Font.h>
#include <Music.h>
#include <Sound.h>
#include <Texture.h>
#include <Button.h>

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