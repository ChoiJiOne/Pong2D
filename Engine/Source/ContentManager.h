#pragma once

#include <json/json.hpp>
using Json = nlohmann::json;

class Renderer;
class Texture;
class Font;
class Music;
class Sound;


/**
 * ������(ex. �ؽ�ó, ��Ʈ, json ���� ���)�� �߰�, ����, �˻� ���� ������ �����ϴ� Ŭ�����Դϴ�.
 */
class ContentManager
{
public:
	/**
	 * ContentManager�� �ν��Ͻ��� ����ϴ�.
	 * 
	 * @return ContentManager �ν��Ͻ��� �����ڸ� ��ȯ�մϴ�.
	 */
	static ContentManager& Get() { return ContentManager_; }


	/**
	 * �ؽ�ó�� �߰��մϴ�.
	 * 
	 * @param InKey - �ؽ�ó�� �ؽ� Ű���Դϴ�.
	 * @param InRenderer - �ؽ�ó�� ������ �� ����� �������Դϴ�.
	 * @param InPath - �ؽ�ó�� ��� �Դϴ�. �̶�, Content ������ �������� ���ڸ� �����ؾ� �մϴ�.
	 * 
	 * @throws 
	 * - �߰��� �ؽ�ó�� ��ο� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * - �ؽ�ó �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return �߰��� �ؽ�ó�� �����ڸ� ��ȯ�մϴ�.
	 */
	Texture& LoadTexture(const std::size_t& InKey, Renderer& InRenderer, const std::string& InPath);


	/**
	 * ���� ���� �ؽ�ó�� �����մϴ�.
	 * 
	 * @param InKey - ������ �ؽ�ó�� �ؽ� Ű ���Դϴ�.
	 */
	void RemoveTexture(const std::size_t& InKey);


	/**
	 * Ű ���� �����ϴ� �ؽ�ó�� �ִ��� Ȯ���մϴ�.
	 * 
	 * @param InKey - �ؽ�ó�� �ִ��� Ȯ���� Ű ���Դϴ�.
	 * 
	 * @return Ű ���� ���� ���� �ؽ�ó�� Ű �� �̶�� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool HaveTexture(const std::size_t& InKey);


	/**
	 * ���� ���� �ؽ�ó�� ����ϴ�.
	 * 
	 * @param InKey - ����� �Ǵ� �ؽ�ó�� Ű ���Դϴ�.
	 * 
	 * @throws Ű ���� �����ϴ� �ؽ�ó�� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return Ű ���� �����ϴ� �ؽ�ó�� �����ڸ� ��ȯ�մϴ�.
	 */
	Texture& GetTexture(const std::size_t& InKey);


	/**
	 * Ʈ�� Ÿ�� ��Ʈ�� �߰��մϴ�.
	 *
	 * @param InKey - ��Ʈ�� �ؽ� Ű���Դϴ�.
	 * @param InRenderer - ��Ʈ�� ������ �� ����� �������Դϴ�.
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
	Font& LoadFont(
		const std::size_t& InKey, 
		Renderer& InRenderer, 
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
	void RemoveFont(const std::size_t& InKey);


	/**
	 * Ű ���� �����ϴ� ��Ʈ�� �ִ��� Ȯ���մϴ�.
	 *
	 * @param InKey - ��Ʈ�� �ִ��� Ȯ���� Ű ���Դϴ�.
	 *
	 * @return Ű ���� ���� ���� ��Ʈ�� Ű �� �̶�� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool HaveFont(const std::size_t& InKey);


	/**
	 * ���� ���� ��Ʈ�� ����ϴ�.
	 *
	 * @param InKey - ����� �Ǵ� ��Ʈ�� Ű ���Դϴ�.
	 *
	 * @throws Ű ���� �����ϴ� ��Ʈ�� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return Ű ���� �����ϴ� ��Ʈ�� �����ڸ� ��ȯ�մϴ�.
	 */
	Font& GetFont(const std::size_t& InKey);


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
	Json& LoadJson(const std::size_t& InKey, const std::string& InPath);


	/**
	 * ���� ���� Json ��ü�� �����մϴ�.
	 *
	 * @param InKey - ������ Json ��ü�� �ؽ� Ű ���Դϴ�.
	 */
	void RemoveJson(const std::size_t& InKey);


	/**
	 * Ű ���� �����ϴ� Json ��ü�� �ִ��� Ȯ���մϴ�.
	 *
	 * @param InKey - Json ��ü�� �ִ��� Ȯ���� Ű ���Դϴ�.
	 *
	 * @return Ű ���� ���� ���� Json ��ü�� Ű �� �̶�� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool HaveJson(const std::size_t& InKey);


	/**
	 * ���� ���� Json ��ü�� ����ϴ�.
	 *
	 * @param InKey - ����� �Ǵ� Json ��ü�� Ű ���Դϴ�.
	 *
	 * @throws Ű ���� �����ϴ� Json ��ü�� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return Ű ���� �����ϴ� Json ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	Json& GetJson(const std::size_t& InKey);


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
	Music& LoadMusic(const std::size_t& InKey, const std::string& InPath);


	/**
	 * ���� ���� ���� �����մϴ�.
	 *
	 * @param InKey - ������ ������ �ؽ� Ű ���Դϴ�.
	 */
	void RemoveMusic(const std::size_t& InKey);


	/**
	 * Ű ���� �����ϴ� ������ �ִ��� Ȯ���մϴ�.
	 *
	 * @param InKey - ������ �ִ��� Ȯ���� Ű ���Դϴ�.
	 *
	 * @return Ű ���� ���� ���� ������ Ű �� �̶�� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool HaveMusic(const std::size_t& InKey);


	/**
	 * ���� ���� ������ ����ϴ�.
	 *
	 * @param InKey - ����� �Ǵ� ������ Ű ���Դϴ�.
	 *
	 * @throws Ű ���� �����ϴ� ������ ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return Ű ���� �����ϴ� ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Music& GetMusic(const std::size_t& InKey);


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
	Sound& LoadSound(const std::size_t& InKey, const std::string& InPath);


	/**
	 * ���� ���� ���� �����մϴ�.
	 *
	 * @param InKey - ������ ������ �ؽ� Ű ���Դϴ�.
	 */
	void RemoveSound(const std::size_t& InKey);


	/**
	 * Ű ���� �����ϴ� ������ �ִ��� Ȯ���մϴ�.
	 *
	 * @param InKey - ������ �ִ��� Ȯ���� Ű ���Դϴ�.
	 *
	 * @return Ű ���� ���� ���� ������ Ű �� �̶�� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool HaveSound(const std::size_t& InKey);


	/**
	 * ���� ���� ������ ����ϴ�.
	 *
	 * @param InKey - ����� �Ǵ� ������ Ű ���Դϴ�.
	 *
	 * @throws Ű ���� �����ϴ� ������ ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return Ű ���� �����ϴ� ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Sound& GetSound(const std::size_t& InKey);



private:
	/**
	 * ToyEngine Ŭ������ ContentManager�� private �ʵ忡 ������ �� �ֵ��� �մϴ�.
	 */
	friend class ToyEngine;


	/**
	 * ContentManager�� �������Դϴ�.
	 * �̶�, ContentManager�� �����ڴ� �ƹ��� ���۵� �������� �ʽ��ϴ�.
	 */
	ContentManager() {}


	/**
	 * ContentManager�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~ContentManager() {}


	/**
	 * �������� �����ϴ� Ŭ������ �ʱ�ȭ�մϴ�.
	 * �̶�, ToyEngine ���ο��� �ݵ�� ȣ���ؾ� �մϴ�.
	 */
	void Init();


	/**
	 * �������� �����ϴ� Ŭ������ ���ҽ��� �����մϴ�.
	 * �̶�, ToyEngine ���ο��� �ݵ�� ȣ���ؾ� �մϴ�.
	 */
	void Quit();


private:
	/**
	 * ContentManager�� �ν��Ͻ��Դϴ�.
	 * �� �ν��Ͻ��� �� �ϳ��� �����մϴ�.
	 */
	static ContentManager ContentManager_;


	/**
	 * ������ ���ҽ��� ���� ����Դϴ�.
	 */
	std::string ContentPath_;


	/**
	 * ContentManager�� �����ϴ� �ؽ�ó�Դϴ�.
	 */
	std::unordered_map<std::size_t, std::unique_ptr<Texture>> Textures_;


	/**
	 * ContentManager�� �����ϴ� ��Ʈ�Դϴ�.
	 */
	std::unordered_map<std::size_t, std::unique_ptr<Font>> Fonts_;


	/**
	 * ContentManager�� �����ϴ� Json �����Դϴ�.
	 */
	std::unordered_map<std::size_t, Json> Jsons_;


	/**
	 * ContentManager�� �����ϴ� �����Դϴ�.
	 */
	std::unordered_map<std::size_t, std::unique_ptr<Music>> Musics_;


	/**
	 * ContentManager�� �����ϴ� �����Դϴ�.
	 */
	std::unordered_map<std::size_t, std::unique_ptr<Sound>> Sounds_;
};