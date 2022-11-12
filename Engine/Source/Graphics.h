#pragma once

#include "Macro.h"
#include "ColorUtils.h"

class Body;
class Window;
class Texture;
class Font;
struct SDL_Renderer;


/**
 * �׷��Ƚ� �ɼ� �÷����Դϴ�.
 * 
 * @see https://wiki.libsdl.org/SDL_RendererFlags
 */
enum class EGraphicsFlags : int32_t
{
	SOFTWARE = 0x00000001,
	ACCELERATED = 0x00000002,
	PRESENTVSYNC = 0x00000004,
	TARGETTEXTURE = 0x00000008
};


/**
 * �׷��Ƚ� �ɼ� �÷����� or ������ �����մϴ�.
 *
 * @param InLhs - or ������ ���� �ǿ������Դϴ�.
 * @param InRhs - or ������ ���� �ǿ������Դϴ�.
 *
 * @return or ������ ������ ����� ��ȯ�մϴ�.
 */
inline EGraphicsFlags operator|(const EGraphicsFlags& InLhs, const EGraphicsFlags& InRhs)
{
	return static_cast<EGraphicsFlags>(static_cast<uint32_t>(InLhs) | static_cast<uint32_t>(InRhs));
}


/**
 * ���� ���� �׷��Ƚ� ���� ó���� �ϴ� Ŭ�����Դϴ�.
 */
class Graphics
{
public:
	/**
	 * �׷��Ƚ� Ŭ������ �������Դϴ�.
	 * @see https://wiki.libsdl.org/SDL_CreateRenderer
	 * 
	 * @param InWindow - �׷��Ƚ� Ŭ���� �ʱ�ȭ �� ������ ������ Ŭ������ �ν��Ͻ��Դϴ�.
	 * @param InFlags - �׷��Ƚ� ���� �ɼ��Դϴ�.
	 * 
	 * @throws �ʱ�ȭ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @see https://wiki.libsdl.org/SDL_CreateRenderer
	 */
	explicit Graphics(Window& InWindow, const EGraphicsFlags& InFlags);


	/**
	 * �׷��Ƚ� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Graphics();


	/**
	 * ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Graphics);


	/**
	 * ������ �������� �����մϴ�.
	 *
	 * @param InColor - �����۸� ��� �����Դϴ�.
	 *
	 * @throws ����� �ʱ�ȭ�� ������ ���, C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void BeginFrame(const LinearColor& InColor);


	/**
	 * ������ �������� �����ϰ�, �����۸� ȭ�鿡 ǥ���մϴ�.
	 */
	void EndFrame();


	/**
	 * SDL �������� �����͸� ����ϴ�.
	 *
	 * @return SDL �������� �����͸� ��ȯ�մϴ�.
	 */
	SDL_Renderer* GetRenderer() { return Renderer_; }


	/**
	 * �����ۿ� 2D ���� �׸��ϴ�.
	 *
	 * @param InPosition - ���� ��ġ�Դϴ�.
	 * @param InColor - ���� �����Դϴ�.
	 *
	 * @throws �������� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void DrawPoint2D(const Vec2i& InPosition, const LinearColor& InColor);


	/**
	 * �����ۿ� 2D ���� �׸��ϴ�.
	 *
	 * @param InPosition0 - ������ �� �����Դϴ�.
	 * @param InPosition1 - ������ �ٸ� �� �����Դϴ�.
	 * @param InColor - ������ �����Դϴ�.
	 *
	 * @throws �������� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void DrawLine2D(const Vec2i& InPosition0, const Vec2i& InPosition1, const LinearColor& InColor);


	/**
	 * �����ۿ� 2D �簢���� �׸��ϴ�.
	 *
	 * @param InPosition0 - �簢���� ���� ������Դϴ�.
	 * @param InPosition1 - �簢���� ������ �ϴ����Դϴ�.
	 * @param InColor - �簢���� �����Դϴ�.
	 *
	 * @throws �������� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void DrawRect2D(const Vec2i& InPosition0, const Vec2i& InPosition1, const LinearColor& InColor);


	/**
	 * �����ۿ� 2D �簢���� �׸��ϴ�.
	 *
	 * @param InCenterPosition - �簢���� �߽��� ��ġ�� ȭ����� ��ǥ�Դϴ�.
	 * @param InWidth - �簢���� ���� �����Դϴ�.
	 * @param InHeight - �簢���� ���� �����Դϴ�.
	 * @param InColor - �簢���� �����Դϴ�.
	 *
	 * @throws �������� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void DrawRect2D(const Vec2i& InCenterPosition, int32_t InWidth, int32_t InHeight, const LinearColor& InColor);


	/**
	 * �����ۿ� ä�� 2D �簢���� �׸��ϴ�.
	 *
	 * @param InPosition0 - ä�� �簢���� ���� ������Դϴ�.
	 * @param InPosition1 - ä�� �簢���� ������ �ϴ����Դϴ�.
	 * @param InColor - ä�� �簢���� �����Դϴ�.
	 *
	 * @throws �������� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void DrawFillRect2D(const Vec2i& InPosition0, const Vec2i& InPosition1, const LinearColor& InColor);


	/**
	 * �����ۿ� ä�� 2D �簢���� �׸��ϴ�.
	 *
	 * @param InCenterPosition - �簢���� �߽��� ��ġ�� ȭ����� ��ǥ�Դϴ�.
	 * @param InWidth - �簢���� ���� �����Դϴ�.
	 * @param InHeight - �簢���� ���� �����Դϴ�
	 * @param InColor - �簢���� �����Դϴ�.
	 *
	 * @throws �������� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void DrawFillRect2D(const Vec2i& InCenterPosition, int32_t InWidth, int32_t InHeight, const LinearColor& InColor);


	/**
	 * ����ۿ� �ؽ�ó�� �׸��ϴ�.
	 * �̶�, ȸ�� ������ 60�й� �����Դϴ�.
	 *
	 * @param InTexture - �����ۿ� �׸� �ؽ�ó�Դϴ�.
	 * @param InPosition0 - �ؽ�ó�� ���� ����� ��ġ�� ȭ����� ��ǥ�Դϴ�.
	 * @param InPosition1 - �ؽ�ó�� ���� ����� ��ġ�� ȭ����� ��ǥ�Դϴ�.
	 * @param InRotateAngle - �������� �ؽ�ó�� ȸ�� �����Դϴ�.
	 *
	 * @throws �������� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void DrawTexture2D(Texture& InTexture, const Vec2i& InPosition0, const Vec2i& InPosition1, float InRotateAngle = 0.0f);


	/**
	 * ����ۿ� �ؽ�ó�� �׸��ϴ�.
	 * �̶�, ȸ�� ������ 60�й� �����Դϴ�.
	 *
	 * @param InTexture - �����ۿ� �׸� �ؽ�ó�Դϴ�.
	 * @param InCenterPosition - �ؽ�ó�� �߽��� ��ġ�� ȭ����� ��ǥ�Դϴ�.
	 * @param InWidth- ����ۿ� �������� �ؽ�ó�� ���� ũ�� �Դϴ�
	 * @param InHeight- ����ۿ� �������� �ؽ�ó�� ���� �ؽ�ó ��� ���� ũ�� �����Դϴ�.
	 * @param InRotateAngle - �������� �ؽ�ó�� ȸ�� �����Դϴ�.
	 *
	 * @throws �������� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void DrawTexture2D(Texture& InTexture, const Vec2i& InCenterPosition, int32_t InWidth, int32_t InHeight, float InRotateAngle = 0.0f);


	/**
	 * ����ۿ� �ؽ�ó ������ �׸��ϴ�.
	 * �̶�, ȸ�� ������ 60�й� �����Դϴ�.
	 *
	 * @param InTexture - �����ۿ� �׸� �ؽ�ó�Դϴ�.
	 * @param InCenterPosition - �ؽ�ó�� �߽��� ��ġ�� ȭ����� ��ǥ�Դϴ�.
	 * @param InRotateAngle - �������� �ؽ�ó�� ȸ�� �����Դϴ�.
	 *
	 * @throws �������� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void DrawTexture2D(Texture& InTexture, const Vec2i& InCenterPosition, float InRotateAngle = 0.0f);


	/**
	 * �����ۿ� �ؽ�Ʈ�� �׸��ϴ�.
	 *
	 * @param InFont- Ʈ�� Ÿ�� ��Ʈ�Դϴ�.
	 * @param InText - �����ۿ� �׸� �ؽ�Ʈ�Դϴ�.
	 * @param InCenterPosition - �ؽ�Ʈ�� �߽��� ��ġ�� ȭ����� ��ǥ�Դϴ�.
	 * @param InColor - �ؽ�Ʈ�� �����Դϴ�.
	 *
	 * @throws �������� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void DrawText2D(Font& InFont, const std::wstring& InText, const Vec2i& InCenterPosition, const LinearColor& InColor);


	/**
	 * �����ۿ� ������Ʈ ��ü�� �ܰ����� �׸��ϴ�.
	 * 
	 * @param InBody - �ܰ����� �׸� ������Ʈ�� ��ü�Դϴ�.
	 * @param InColor - �ܰ����� �����Դϴ�.
	 * 
	 * @throws �������� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void DrawBodyOutline(Body& InBody, const LinearColor& InColor);


private:
	/**
	 * SDL �������� �÷� ���¸� �����մϴ�.
	 *
	 * @param InColor - ������ SDL �������� �÷� �����Դϴ�.
	 *
	 * @throws ���� ���� ������ ������ ���, C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void SetDrawColor(const LinearColor& InColor);


	/**
	 * SDL �������� �÷� ���¸� �����մϴ�.
	 *
	 * @param InRed - ������ SDL �������� �÷� Red�� �Դϴ�.
	 * @param InGreen - ������ SDL �������� �÷� Green�� �Դϴ�.
	 * @param InBlue - ������ SDL �������� �÷� Blue�� �Դϴ�.
	 * @param InAlpha - ������ SDL �������� �÷� Alpha�� �Դϴ�.
	 *
	 * @throws ���� ���� ������ ������ ���, C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void SetDrawColor(uint8_t InRed, uint8_t InGreen, uint8_t InBlue, uint8_t InAlpha);


private:
	/**
	 * �׷��Ƚ� ������ �����ϴ� SDL �������Դϴ�.
	 */
	SDL_Renderer* Renderer_ = nullptr;
};