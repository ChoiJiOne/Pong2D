#pragma once

#include <json/json.hpp>
using Json = nlohmann::json;

class Graphics;
class Texture;
class Font;
class Music;
class Sound;


/**
 * 컨텐츠(ex. 텍스처, 폰트, json 파일 등등)를 추가, 삭제, 검색 등의 관리를 수행하는 클래스입니다.
 */
class ContentUtils
{
public:
	/**
	 * 컨텐츠를 관리하는 클래스를 초기화합니다.
	 */
	static void Init();


	/**
	 * 컨텐츠를 관리하는 클래스의 리소스를 정리합니다.
	 */
	static void Quit();


	/**
	 * 텍스처를 추가합니다.
	 * 
	 * @param InKey - 텍스처의 해쉬 키값입니다.
	 * @param InGraphics - 텍스처를 생성할 때 사용할 그래픽스 인스턴스입니다.
	 * @param InPath - 텍스처의 경로 입니다. 이때, Content 폴더를 기준으로 인자를 전달해야 합니다.
	 * 
	 * @throws 
	 * - 추가할 텍스처가 경로에 없으면 C++ 표준 예외를 던집니다.
	 * - 텍스처 로딩에 실패하면 C++ 표준 예외를 던집니다.
	 * 
	 * @return 추가한 텍스처의 참조자를 반환합니다.
	 */
	static Texture& LoadTexture(const std::size_t& InKey, Graphics& InGraphics, const std::string& InPath);


	/**
	 * 관리 중인 텍스처를 삭제합니다.
	 * 
	 * @param InKey - 삭제할 텍스처의 해쉬 키 값입니다.
	 */
	static void RemoveTexture(const std::size_t& InKey);


	/**
	 * 키 값에 대응하는 텍스처가 있는지 확인합니다.
	 * 
	 * @param InKey - 텍스처가 있는지 확인할 키 값입니다.
	 * 
	 * @return 키 값이 관리 중인 텍스처의 키 값 이라면 true, 그렇지 않다면 false를 반환합니다.
	 */
	static bool HaveTexture(const std::size_t& InKey);


	/**
	 * 관리 중인 텍스처를 얻습니다.
	 * 
	 * @param InKey - 대상이 되는 텍스처의 키 값입니다.
	 * 
	 * @throws 키 값에 대응하는 텍스처가 없으면 C++ 표준 예외를 던집니다.
	 * 
	 * @return 키 값에 대응하는 텍스처의 참조자를 반환합니다.
	 */
	static Texture& GetTexture(const std::size_t& InKey);


	/**
	 * 트루 타입 폰트를 추가합니다.
	 *
	 * @param InKey - 폰트의 해쉬 키값입니다.
	 * @param InGraphics - 폰트를 생성할 때 사용할 그래픽스 인스턴스입니다.
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
	static Font& LoadFont(
		const std::size_t& InKey, 
		Graphics& InGraphics, 
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
	static void RemoveFont(const std::size_t& InKey);


	/**
	 * 키 값에 대응하는 폰트가 있는지 확인합니다.
	 *
	 * @param InKey - 폰트가 있는지 확인할 키 값입니다.
	 *
	 * @return 키 값이 관리 중인 폰트의 키 값 이라면 true, 그렇지 않다면 false를 반환합니다.
	 */
	static bool HaveFont(const std::size_t& InKey);


	/**
	 * 관리 중인 폰트를 얻습니다.
	 *
	 * @param InKey - 대상이 되는 폰트의 키 값입니다.
	 *
	 * @throws 키 값에 대응하는 폰트가 없으면 C++ 표준 예외를 던집니다.
	 * 
	 * @return 키 값에 대응하는 폰트의 참조자를 반환합니다.
	 */
	static Font& GetFont(const std::size_t& InKey);


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
	static Json& LoadJson(const std::size_t& InKey, const std::string& InPath);


	/**
	 * 관리 중인 Json 객체를 삭제합니다.
	 *
	 * @param InKey - 삭제할 Json 객체의 해쉬 키 값입니다.
	 */
	static void RemoveJson(const std::size_t& InKey);


	/**
	 * 키 값에 대응하는 Json 객체가 있는지 확인합니다.
	 *
	 * @param InKey - Json 객체가 있는지 확인할 키 값입니다.
	 *
	 * @return 키 값이 관리 중인 Json 객체의 키 값 이라면 true, 그렇지 않다면 false를 반환합니다.
	 */
	static bool HaveJson(const std::size_t& InKey);


	/**
	 * 관리 중인 Json 객체를 얻습니다.
	 *
	 * @param InKey - 대상이 되는 Json 객체의 키 값입니다.
	 *
	 * @throws 키 값에 대응하는 Json 객체가 없으면 C++ 표준 예외를 던집니다.
	 *
	 * @return 키 값에 대응하는 Json 객체의 참조자를 반환합니다.
	 */
	static Json& GetJson(const std::size_t& InKey);


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
	static Music& LoadMusic(const std::size_t& InKey, const std::string& InPath);


	/**
	 * 관리 중인 뮤직 삭제합니다.
	 *
	 * @param InKey - 삭제할 뮤직의 해쉬 키 값입니다.
	 */
	static void RemoveMusic(const std::size_t& InKey);


	/**
	 * 키 값에 대응하는 뮤직이 있는지 확인합니다.
	 *
	 * @param InKey - 뮤직이 있는지 확인할 키 값입니다.
	 *
	 * @return 키 값이 관리 중인 뮤직의 키 값 이라면 true, 그렇지 않다면 false를 반환합니다.
	 */
	static bool HaveMusic(const std::size_t& InKey);


	/**
	 * 관리 중인 뮤직을 얻습니다.
	 *
	 * @param InKey - 대상이 되는 뮤직의 키 값입니다.
	 *
	 * @throws 키 값에 대응하는 뮤직이 없으면 C++ 표준 예외를 던집니다.
	 *
	 * @return 키 값에 대응하는 뮤직의 참조자를 반환합니다.
	 */
	static Music& GetMusic(const std::size_t& InKey);


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
	static Sound& LoadSound(const std::size_t& InKey, const std::string& InPath);


	/**
	 * 관리 중인 사운드 삭제합니다.
	 *
	 * @param InKey - 삭제할 사운드의 해쉬 키 값입니다.
	 */
	static void RemoveSound(const std::size_t& InKey);


	/**
	 * 키 값에 대응하는 사운드이 있는지 확인합니다.
	 *
	 * @param InKey - 사운드이 있는지 확인할 키 값입니다.
	 *
	 * @return 키 값이 관리 중인 사운드의 키 값 이라면 true, 그렇지 않다면 false를 반환합니다.
	 */
	static bool HaveSound(const std::size_t& InKey);


	/**
	 * 관리 중인 사운드을 얻습니다.
	 *
	 * @param InKey - 대상이 되는 사운드의 키 값입니다.
	 *
	 * @throws 키 값에 대응하는 사운드이 없으면 C++ 표준 예외를 던집니다.
	 *
	 * @return 키 값에 대응하는 사운드의 참조자를 반환합니다.
	 */
	static Sound& GetSound(const std::size_t& InKey);


private:
	/**
	 * 컨텐츠 리소스의 폴더 경로입니다.
	 */
	static std::string ContentPath_;


	/**
	 * ContentUtils이 관리하는 텍스처입니다.
	 */
	static std::unordered_map<std::size_t, std::unique_ptr<Texture>> Textures_;


	/**
	 * ContentUtils이 관리하는 폰트입니다.
	 */
	static std::unordered_map<std::size_t, std::unique_ptr<Font>> Fonts_;


	/**
	 * ContentUtils이 관리하는 Json 파일입니다.
	 */
	static std::unordered_map<std::size_t, Json> Jsons_;


	/**
	 * ContentUtils이 관리하는 뮤직입니다.
	 */
	static std::unordered_map<std::size_t, std::unique_ptr<Music>> Musics_;


	/**
	 * ContentUtils이 관리하는 사운드입니다.
	 */
	static std::unordered_map<std::size_t, std::unique_ptr<Sound>> Sounds_;
};