#pragma once

#include <json/json.hpp>
using Json = nlohmann::json;

class Renderer;
class Texture;
class Font;
class Music;
class Sound;


/**
 * 컨텐츠(ex. 텍스처, 폰트, json 파일 등등)를 추가, 삭제, 검색 등의 관리를 수행하는 클래스입니다.
 */
class ContentManager
{
public:
	/**
	 * ContentManager의 인스턴스를 얻습니다.
	 * 
	 * @return ContentManager 인스턴스의 참조자를 반환합니다.
	 */
	static ContentManager& Get() { return ContentManager_; }


	/**
	 * 텍스처를 추가합니다.
	 * 
	 * @param InKey - 텍스처의 해쉬 키값입니다.
	 * @param InRenderer - 텍스처를 생성할 때 사용할 렌더러입니다.
	 * @param InPath - 텍스처의 경로 입니다. 이때, Content 폴더를 기준으로 인자를 전달해야 합니다.
	 * 
	 * @throws 
	 * - 추가할 텍스처가 경로에 없으면 C++ 표준 예외를 던집니다.
	 * - 텍스처 로딩에 실패하면 C++ 표준 예외를 던집니다.
	 * 
	 * @return 추가한 텍스처의 참조자를 반환합니다.
	 */
	Texture& LoadTexture(const std::size_t& InKey, Renderer& InRenderer, const std::string& InPath);


	/**
	 * 관리 중인 텍스처를 삭제합니다.
	 * 
	 * @param InKey - 삭제할 텍스처의 해쉬 키 값입니다.
	 */
	void RemoveTexture(const std::size_t& InKey);


	/**
	 * 키 값에 대응하는 텍스처가 있는지 확인합니다.
	 * 
	 * @param InKey - 텍스처가 있는지 확인할 키 값입니다.
	 * 
	 * @return 키 값이 관리 중인 텍스처의 키 값 이라면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool HaveTexture(const std::size_t& InKey);


	/**
	 * 관리 중인 텍스처를 얻습니다.
	 * 
	 * @param InKey - 대상이 되는 텍스처의 키 값입니다.
	 * 
	 * @throws 키 값에 대응하는 텍스처가 없으면 C++ 표준 예외를 던집니다.
	 * 
	 * @return 키 값에 대응하는 텍스처의 참조자를 반환합니다.
	 */
	Texture& GetTexture(const std::size_t& InKey);


	/**
	 * 트루 타입 폰트를 추가합니다.
	 *
	 * @param InKey - 폰트의 해쉬 키값입니다.
	 * @param InRenderer - 폰트를 생성할 때 사용할 렌더러입니다.
	 * @param InPath - 폰트의 경로 입니다. 이때, Content 폴더를 기준으로 인자를 전달해야 합니다.
	 * @param InBeginCodePoint - 문자 텍스처 아틀라스의 코드 포인트 시작점입니다.
	 * @param InEndCodePoint - 문자 텍스처 아틀라스의 코드 포인트 끝점입니다.
	 * @param InFontSize - 폰트의 크기입니다.
	 *
	 * @throws
	 * - 추가할 폰트가 경로에 없으면 C++ 표준 예외를 던집니다.
	 * - 폰트 로딩에 실패하면 C++ 표준 예외를 던집니다.
	 *
	 * @return 추가한 폰트의 참조자를 반환합니다.
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
	 * 관리 중인 폰트를 삭제합니다.
	 *
	 * @param InKey - 삭제할 폰트의 해쉬 키 값입니다.
	 */
	void RemoveFont(const std::size_t& InKey);


	/**
	 * 키 값에 대응하는 폰트가 있는지 확인합니다.
	 *
	 * @param InKey - 폰트가 있는지 확인할 키 값입니다.
	 *
	 * @return 키 값이 관리 중인 폰트의 키 값 이라면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool HaveFont(const std::size_t& InKey);


	/**
	 * 관리 중인 폰트를 얻습니다.
	 *
	 * @param InKey - 대상이 되는 폰트의 키 값입니다.
	 *
	 * @throws 키 값에 대응하는 폰트가 없으면 C++ 표준 예외를 던집니다.
	 * 
	 * @return 키 값에 대응하는 폰트의 참조자를 반환합니다.
	 */
	Font& GetFont(const std::size_t& InKey);


	/**
	 * Json 객체를 추가합니다.
	 *
	 * @param InKey - Json 객체의 해쉬 키값입니다.
	 * @param InPath - Json 파일의 경로 입니다. 이때, Content 폴더를 기준으로 인자를 전달해야 합니다.
	 *
	 * @throws
	 * - 추가할 Json 객체가 경로에 없으면 C++ 표준 예외를 던집니다.
	 * - Json 파일 로딩에 실패하면 C++ 표준 예외를 던집니다.
	 *
	 * @return 추가한 Json 객체의 참조자를 반환합니다.
	 */
	Json& LoadJson(const std::size_t& InKey, const std::string& InPath);


	/**
	 * 관리 중인 Json 객체를 삭제합니다.
	 *
	 * @param InKey - 삭제할 Json 객체의 해쉬 키 값입니다.
	 */
	void RemoveJson(const std::size_t& InKey);


	/**
	 * 키 값에 대응하는 Json 객체가 있는지 확인합니다.
	 *
	 * @param InKey - Json 객체가 있는지 확인할 키 값입니다.
	 *
	 * @return 키 값이 관리 중인 Json 객체의 키 값 이라면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool HaveJson(const std::size_t& InKey);


	/**
	 * 관리 중인 Json 객체를 얻습니다.
	 *
	 * @param InKey - 대상이 되는 Json 객체의 키 값입니다.
	 *
	 * @throws 키 값에 대응하는 Json 객체가 없으면 C++ 표준 예외를 던집니다.
	 *
	 * @return 키 값에 대응하는 Json 객체의 참조자를 반환합니다.
	 */
	Json& GetJson(const std::size_t& InKey);


	/**
	 * 뮤직을 추가합니다.
	 *
	 * @param InKey - 뮤직의 해쉬 키값입니다.
	 * @param InPath - 뮤직 파일의 경로 입니다. 이때, Content 폴더를 기준으로 인자를 전달해야 합니다.
	 *
	 * @throws
	 * - 추가할 뮤직 파일이 경로에 없으면 C++ 표준 예외를 던집니다.
	 * - 뮤직 파일 로딩에 실패하면 C++ 표준 예외를 던집니다.
	 *
	 * @return 추가한 뮤직의 참조자를 반환합니다.
	 */
	Music& LoadMusic(const std::size_t& InKey, const std::string& InPath);


	/**
	 * 관리 중인 뮤직 삭제합니다.
	 *
	 * @param InKey - 삭제할 뮤직의 해쉬 키 값입니다.
	 */
	void RemoveMusic(const std::size_t& InKey);


	/**
	 * 키 값에 대응하는 뮤직이 있는지 확인합니다.
	 *
	 * @param InKey - 뮤직이 있는지 확인할 키 값입니다.
	 *
	 * @return 키 값이 관리 중인 뮤직의 키 값 이라면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool HaveMusic(const std::size_t& InKey);


	/**
	 * 관리 중인 뮤직을 얻습니다.
	 *
	 * @param InKey - 대상이 되는 뮤직의 키 값입니다.
	 *
	 * @throws 키 값에 대응하는 뮤직이 없으면 C++ 표준 예외를 던집니다.
	 *
	 * @return 키 값에 대응하는 뮤직의 참조자를 반환합니다.
	 */
	Music& GetMusic(const std::size_t& InKey);


	/**
	 * 사운드을 추가합니다.
	 *
	 * @param InKey - 사운드의 해쉬 키값입니다.
	 * @param InPath - 사운드 파일의 경로 입니다. 이때, Content 폴더를 기준으로 인자를 전달해야 합니다.
	 *
	 * @throws
	 * - 추가할 사운드 파일이 경로에 없으면 C++ 표준 예외를 던집니다.
	 * - 사운드 파일 로딩에 실패하면 C++ 표준 예외를 던집니다.
	 *
	 * @return 추가한 사운드의 참조자를 반환합니다.
	 */
	Sound& LoadSound(const std::size_t& InKey, const std::string& InPath);


	/**
	 * 관리 중인 사운드 삭제합니다.
	 *
	 * @param InKey - 삭제할 사운드의 해쉬 키 값입니다.
	 */
	void RemoveSound(const std::size_t& InKey);


	/**
	 * 키 값에 대응하는 사운드이 있는지 확인합니다.
	 *
	 * @param InKey - 사운드이 있는지 확인할 키 값입니다.
	 *
	 * @return 키 값이 관리 중인 사운드의 키 값 이라면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool HaveSound(const std::size_t& InKey);


	/**
	 * 관리 중인 사운드을 얻습니다.
	 *
	 * @param InKey - 대상이 되는 사운드의 키 값입니다.
	 *
	 * @throws 키 값에 대응하는 사운드이 없으면 C++ 표준 예외를 던집니다.
	 *
	 * @return 키 값에 대응하는 사운드의 참조자를 반환합니다.
	 */
	Sound& GetSound(const std::size_t& InKey);



private:
	/**
	 * ToyEngine 클래스는 ContentManager의 private 필드에 접근할 수 있도록 합니다.
	 */
	friend class ToyEngine;


	/**
	 * ContentManager의 생성자입니다.
	 * 이때, ContentManager의 생성자는 아무런 동작도 수행하지 않습니다.
	 */
	ContentManager() {}


	/**
	 * ContentManager의 가상 소멸자입니다.
	 */
	virtual ~ContentManager() {}


	/**
	 * 컨텐츠를 관리하는 클래스를 초기화합니다.
	 * 이때, ToyEngine 내부에서 반드시 호출해야 합니다.
	 */
	void Init();


	/**
	 * 컨텐츠를 관리하는 클래스의 리소스를 정리합니다.
	 * 이때, ToyEngine 내부에서 반드시 호출해야 합니다.
	 */
	void Quit();


private:
	/**
	 * ContentManager의 인스턴스입니다.
	 * 이 인스턴스는 단 하나만 존재합니다.
	 */
	static ContentManager ContentManager_;


	/**
	 * 컨텐츠 리소스의 폴더 경로입니다.
	 */
	std::string ContentPath_;


	/**
	 * ContentManager이 관리하는 텍스처입니다.
	 */
	std::unordered_map<std::size_t, std::unique_ptr<Texture>> Textures_;


	/**
	 * ContentManager이 관리하는 폰트입니다.
	 */
	std::unordered_map<std::size_t, std::unique_ptr<Font>> Fonts_;


	/**
	 * ContentManager이 관리하는 Json 파일입니다.
	 */
	std::unordered_map<std::size_t, Json> Jsons_;


	/**
	 * ContentManager이 관리하는 뮤직입니다.
	 */
	std::unordered_map<std::size_t, std::unique_ptr<Music>> Musics_;


	/**
	 * ContentManager이 관리하는 사운드입니다.
	 */
	std::unordered_map<std::size_t, std::unique_ptr<Sound>> Sounds_;
};