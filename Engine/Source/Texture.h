#pragma once

#include "Macro.h"

#include <vector>
#include <string>

class Graphics;
struct SDL_Texture;


/**
 * �ؽ�ó ���ҽ��� �����ϴ� Ŭ�����Դϴ�.
 */
class Texture
{
public:
	/**
	 * �ؽ�ó Ŭ������ �������Դϴ�.
	 *
	 * @param InGraphics - �ؽ�ó ���ҽ��� ������ �� ����� �׷��Ƚ� �ν��Ͻ��Դϴ�.
	 * @param InPath - �ε��� �ؽ�ó ���ҽ��� ����Դϴ�.
	 *
	 * @throws
	 * - �ؽ�ó ���� �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * - �ؽ�ó ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	explicit Texture(Graphics& InGraphics, const std::string& InPath);


	/**
	 * �ؽ�ó Ŭ������ �������Դϴ�.
	 * �̶�, �Ķ���ͷ� �Է� ���� SDL_Texture�� �����մϴ�.
	 *
	 * @param InTexture - �ؽ�ó ���ҽ��� �������Դϴ�.
	 *
	 * @throws �Ķ���Ͱ� ��ȿ���� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	explicit Texture(SDL_Texture* InTexture);


	/**
	 * �ؽ�ó Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Texture();


	/**
	 * ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Texture);


	/**
	 * �ؽ�ó ���ҽ��� �����͸� ����ϴ�.
	 *
	 * @return �ؽ�ó ���ҽ��� �����͸� ��ȯ�մϴ�.
	 */
	SDL_Texture* GetTexture() { return Texture_; }


	/**
	 * �ؽ�ó ���ҽ��� ���� ���� ũ�⸦ ����ϴ�.
	 *
	 * @param OutWidth - �ؽ�ó ���ҽ��� ���� ũ���Դϴ�.
	 * @param OutHeight - �ؽ�ó ���ҽ��� ���� ũ���Դϴ�.
	 */
	void GetSize(int32_t& OutWidth, int32_t& OutHeight);


private:
	/**
	 * �ؽ�ó ������ �ε��մϴ�.
	 *
	 * @param InPath - �ε��� �ؽ�ó ���ҽ��� ����Դϴ�.
	 * @param OutBuffer - �ؽ�ó ���ҽ��� ���� ���ҽ��Դϴ�.
	 * @param OutFormat - �ؽ�ó ���ҽ��� �����Դϴ�.
	 * @param OutWidth - �ؽ�ó ���ҽ��� ���� ũ���Դϴ�.
	 * @param OutHeight - �ؽ�ó ���ҽ��� ���� ũ���Դϴ�.
	 *
	 * @return �ؽ�ó ���� �ε��� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	static bool LoadTextureFromFile(
		const std::string& InPath,
		std::vector<uint8_t>& OutBuffer,
		int32_t& OutFormat,
		int32_t& OutWidth,
		int32_t& OutHeight
	);


	/**
	 * �ؽ�ó ���ҽ��� �����մϴ�.
	 *
	 * @param InGraphics - �ؽ�ó ���ҽ��� ������ �� ����� �׷��Ƚ� �ν��Ͻ��Դϴ�.
	 * @param InBuffer - �ؽ�ó ���ҽ��� �����Դϴ�.
	 * @param InFormat - �ؽ�ó ���ҽ��� �����Դϴ�.
	 * @param InWidth - �ؽ�ó ���ҽ��� ���� ũ���Դϴ�.
	 * @param InHeight - �ؽ�ó ���ҽ��� ���� ũ���Դϴ�.
	 *
	 * @throws �ؽ�ó ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return SDL �ؽ�ó ���ҽ��� �����͸� ��ȯ�մϴ�.
	 */
	static SDL_Texture* CreateTextureResource(
		Graphics& InGraphics,
		const std::vector<uint8_t>& InBuffer,
		const int32_t& InFormat,
		const int32_t& InWidth,
		const int32_t& InHeight
	);


private:
	/**
	 * SDL �ؽ�ó ���ҽ��Դϴ�.
	 */
	SDL_Texture* Texture_ = nullptr;
};