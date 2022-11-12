#pragma once

#include <json/json.hpp>
using Json = nlohmann::json;

class Graphics;
class Texture;
class Font;
class Music;
class Sound;


/**
 * ������(ex. �ؽ�ó, ��Ʈ, json ���� ���)�� �߰�, ����, �˻� ���� ������ �����ϴ� Ŭ�����Դϴ�.
 */
class ContentUtils
{
public:
	/**
	 * �������� �����ϴ� Ŭ������ �ʱ�ȭ�մϴ�.
	 */
	static void Init();


	/**
	 * �������� �����ϴ� Ŭ������ ���ҽ��� �����մϴ�.
	 */
	static void Quit();


	/**
	 * �ؽ�ó�� �߰��մϴ�.
	 * 
	 * @param InKey - �ؽ�ó�� �ؽ� Ű���Դϴ�.
	 * @param InGraphics - �ؽ�ó�� ������ �� ����� �׷��Ƚ� �ν��Ͻ��Դϴ�.
	 * @param InPath - �ؽ�ó�� ��� �Դϴ�. �̶�, Content ������ �������� ���ڸ� �����ؾ� �մϴ�.
	 * 
	 * @throws 
	 * - �߰��� �ؽ�ó�� ��ο� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * - �ؽ�ó �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return �߰��� �ؽ�ó�� �����ڸ� ��ȯ�մϴ�.
	 */
	static Texture& LoadTexture(const std::size_t& InKey, Graphics& InGraphics, const std::string& InPath);


	/**
	 * ���� ���� �ؽ�ó�� �����մϴ�.
	 * 
	 * @param InKey - ������ �ؽ�ó�� �ؽ� Ű ���Դϴ�.
	 */
	static void RemoveTexture(const std::size_t& InKey);


	/**
	 * Ű ���� �����ϴ� �ؽ�ó�� �ִ��� Ȯ���մϴ�.
	 * 
	 * @param InKey - �ؽ�ó�� �ִ��� Ȯ���� Ű ���Դϴ�.
	 * 
	 * @return Ű ���� ���� ���� �ؽ�ó�� Ű �� �̶�� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	static bool HaveTexture(const std::size_t& InKey);


	/**
	 * ���� ���� �ؽ�ó�� ����ϴ�.
	 * 
	 * @param InKey - ����� �Ǵ� �ؽ�ó�� Ű ���Դϴ�.
	 * 
	 * @throws Ű ���� �����ϴ� �ؽ�ó�� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return Ű ���� �����ϴ� �ؽ�ó�� �����ڸ� ��ȯ�մϴ�.
	 */
	static Texture& GetTexture(const std::size_t& InKey);


	/**
	 * Ʈ�� Ÿ�� ��Ʈ�� �߰��մϴ�.
	 *
	 * @param InKey - ��Ʈ�� �ؽ� Ű���Դϴ�.
	 * @param InGraphics - ��Ʈ�� ������ �� ����� �׷��Ƚ� �ν��Ͻ��Դϴ�.
	 * @param InPath - ��Ʈ�� ��� �Դϴ�. �̶�, Content ������ �������� ���ڸ� �����ؾ� �մϴ�.
	 * @param InBeginCodePoint - ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �������Դϴ�.
	 * @param InEndCodePoint - ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �����Դϴ�.
	 * @param InFontSize - ��Ʈ�� ũ���Դϴ�.
	 *
	 * @throws
	 * - �߰��� ��Ʈ�� ��ο� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * - ��Ʈ �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return �߰��� ��Ʈ�� �����ڸ� ��ȯ�մϴ�.
	 */
	static Font& LoadFont(
		const std::size_t& InKey, 
		Graphics& InGraphics, 
		const std::string& InPath, 
		int32_t InBeginCodePoint,
		int32_t InEndCodePoint,
		float InFontSize
	);


	/**
	 * ���� ���� ��Ʈ�� �����մϴ�.
	 *
	 * @param InKey - ������ ��Ʈ�� �ؽ� Ű ���Դϴ�.
	 */
	static void RemoveFont(const std::size_t& InKey);


	/**
	 * Ű ���� �����ϴ� ��Ʈ�� �ִ��� Ȯ���մϴ�.
	 *
	 * @param InKey - ��Ʈ�� �ִ��� Ȯ���� Ű ���Դϴ�.
	 *
	 * @return Ű ���� ���� ���� ��Ʈ�� Ű �� �̶�� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	static bool HaveFont(const std::size_t& InKey);


	/**
	 * ���� ���� ��Ʈ�� ����ϴ�.
	 *
	 * @param InKey - ����� �Ǵ� ��Ʈ�� Ű ���Դϴ�.
	 *
	 * @throws Ű ���� �����ϴ� ��Ʈ�� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return Ű ���� �����ϴ� ��Ʈ�� �����ڸ� ��ȯ�մϴ�.
	 */
	static Font& GetFont(const std::size_t& InKey);


	/**
	 * Json ��ü�� �߰��մϴ�.
	 *
	 * @param InKey - Json ��ü�� �ؽ� Ű���Դϴ�.
	 * @param InPath - Json ������ ��� �Դϴ�. �̶�, Content ������ �������� ���ڸ� �����ؾ� �մϴ�.
	 *
	 * @throws
	 * - �߰��� Json ��ü�� ��ο� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * - Json ���� �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return �߰��� Json ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	static Json& LoadJson(const std::size_t& InKey, const std::string& InPath);


	/**
	 * ���� ���� Json ��ü�� �����մϴ�.
	 *
	 * @param InKey - ������ Json ��ü�� �ؽ� Ű ���Դϴ�.
	 */
	static void RemoveJson(const std::size_t& InKey);


	/**
	 * Ű ���� �����ϴ� Json ��ü�� �ִ��� Ȯ���մϴ�.
	 *
	 * @param InKey - Json ��ü�� �ִ��� Ȯ���� Ű ���Դϴ�.
	 *
	 * @return Ű ���� ���� ���� Json ��ü�� Ű �� �̶�� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	static bool HaveJson(const std::size_t& InKey);


	/**
	 * ���� ���� Json ��ü�� ����ϴ�.
	 *
	 * @param InKey - ����� �Ǵ� Json ��ü�� Ű ���Դϴ�.
	 *
	 * @throws Ű ���� �����ϴ� Json ��ü�� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return Ű ���� �����ϴ� Json ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	static Json& GetJson(const std::size_t& InKey);


	/**
	 * ������ �߰��մϴ�.
	 *
	 * @param InKey - ������ �ؽ� Ű���Դϴ�.
	 * @param InPath - ���� ������ ��� �Դϴ�. �̶�, Content ������ �������� ���ڸ� �����ؾ� �մϴ�.
	 *
	 * @throws
	 * - �߰��� ���� ������ ��ο� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * - ���� ���� �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return �߰��� ������ �����ڸ� ��ȯ�մϴ�.
	 */
	static Music& LoadMusic(const std::size_t& InKey, const std::string& InPath);


	/**
	 * ���� ���� ���� �����մϴ�.
	 *
	 * @param InKey - ������ ������ �ؽ� Ű ���Դϴ�.
	 */
	static void RemoveMusic(const std::size_t& InKey);


	/**
	 * Ű ���� �����ϴ� ������ �ִ��� Ȯ���մϴ�.
	 *
	 * @param InKey - ������ �ִ��� Ȯ���� Ű ���Դϴ�.
	 *
	 * @return Ű ���� ���� ���� ������ Ű �� �̶�� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	static bool HaveMusic(const std::size_t& InKey);


	/**
	 * ���� ���� ������ ����ϴ�.
	 *
	 * @param InKey - ����� �Ǵ� ������ Ű ���Դϴ�.
	 *
	 * @throws Ű ���� �����ϴ� ������ ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return Ű ���� �����ϴ� ������ �����ڸ� ��ȯ�մϴ�.
	 */
	static Music& GetMusic(const std::size_t& InKey);


	/**
	 * ������ �߰��մϴ�.
	 *
	 * @param InKey - ������ �ؽ� Ű���Դϴ�.
	 * @param InPath - ���� ������ ��� �Դϴ�. �̶�, Content ������ �������� ���ڸ� �����ؾ� �մϴ�.
	 *
	 * @throws
	 * - �߰��� ���� ������ ��ο� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * - ���� ���� �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return �߰��� ������ �����ڸ� ��ȯ�մϴ�.
	 */
	static Sound& LoadSound(const std::size_t& InKey, const std::string& InPath);


	/**
	 * ���� ���� ���� �����մϴ�.
	 *
	 * @param InKey - ������ ������ �ؽ� Ű ���Դϴ�.
	 */
	static void RemoveSound(const std::size_t& InKey);


	/**
	 * Ű ���� �����ϴ� ������ �ִ��� Ȯ���մϴ�.
	 *
	 * @param InKey - ������ �ִ��� Ȯ���� Ű ���Դϴ�.
	 *
	 * @return Ű ���� ���� ���� ������ Ű �� �̶�� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	static bool HaveSound(const std::size_t& InKey);


	/**
	 * ���� ���� ������ ����ϴ�.
	 *
	 * @param InKey - ����� �Ǵ� ������ Ű ���Դϴ�.
	 *
	 * @throws Ű ���� �����ϴ� ������ ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return Ű ���� �����ϴ� ������ �����ڸ� ��ȯ�մϴ�.
	 */
	static Sound& GetSound(const std::size_t& InKey);


private:
	/**
	 * ������ ���ҽ��� ���� ����Դϴ�.
	 */
	static std::string ContentPath_;


	/**
	 * ContentUtils�� �����ϴ� �ؽ�ó�Դϴ�.
	 */
	static std::unordered_map<std::size_t, std::unique_ptr<Texture>> Textures_;


	/**
	 * ContentUtils�� �����ϴ� ��Ʈ�Դϴ�.
	 */
	static std::unordered_map<std::size_t, std::unique_ptr<Font>> Fonts_;


	/**
	 * ContentUtils�� �����ϴ� Json �����Դϴ�.
	 */
	static std::unordered_map<std::size_t, Json> Jsons_;


	/**
	 * ContentUtils�� �����ϴ� �����Դϴ�.
	 */
	static std::unordered_map<std::size_t, std::unique_ptr<Music>> Musics_;


	/**
	 * ContentUtils�� �����ϴ� �����Դϴ�.
	 */
	static std::unordered_map<std::size_t, std::unique_ptr<Sound>> Sounds_;
};