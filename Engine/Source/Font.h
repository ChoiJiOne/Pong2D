#pragma once

#include "Macro.h"
#include "Vector.h"

#include <vector>
#include <string>

class Graphics;
struct SDL_Texture;


/**
 * 텍스처 아틀라스의 문자 정보입니다.
 * stbtt_packedchar 구조체를 새롭게 정의한 것입니다.
 */
struct CharacterInfo
{
	int32_t CodePoint;
	Vec2i Position0;
	Vec2i Position1;
	float XOffset;
	float YOffset;
	float XOffset2;
	float YOffset2;
	float XAdvance;
};


/**
 * 폰트에 대응하는 문자들의 텍스처 아틀라스입니다.
 */
class Font
{
public:
	/**
	 * 문자 텍스처 아틀라스 클래스의 생성자입니다.
	 *
	 * @param InGraphics - 텍스처 리소스를 생성할 때 사용할 그래픽스 인스턴스입니다.
	 * @param InPath - 로딩할 폰트 리소스의 경로입니다.
	 * @param InBeginCodePoint - 문자 텍스처 아틀라스의 코드 포인트 시작점입니다.
	 * @param InEndCodePoint - 문자 텍스처 아틀라스의 코드 포인트 끝점입니다.
	 * @param InFontSize - 폰트의 크기입니다.
	 *
	 * @throws 텍스처 아틀라스 생성에 실패하면 C++ 표준 예외를 던집니다.
	 */
	Font(
		Graphics& InGraphics,
		const std::string& InPath,
		int32_t InBeginCodePoint,
		int32_t InEndCodePoint,
		float InFontSize
	);


	/**
	 * 문자 텍스처 아틀라스 클래스 가상 소멸자입니다.
	 */
	virtual ~Font();


	/**
	 * 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Font);


	/**
	 * 코드 포인트에 대응하는 문자 위치 및 크기 정보를 얻습니다.
	 *
	 * @param InCodePoint - 위치 및 정보를 알고 싶은 코드 포인트 값입니다.
	 *
	 * @throws 코드 포인트 값이 범위 내에 없으면 C++ 표준 예외를 던집니다.
	 *
	 * @return 코드 포인트에 대응하는 문자의 위치 및 크기 정보를 반환합니다.
	 */
	const CharacterInfo& GetCharacterInfo(int32_t InCodePoint) const;


	/**
	 * 문자 텍스처 아틀라스를 얻습니다.
	 *
	 * @return 텍스처 아틀라스를 반환합니다.
	 */
	SDL_Texture* GetTextureAtlas() { return TextureAtlas_; }


	/**
	 * 코드 포인트가 범위 내에 포함되는지 확인합니다.
	 *
	 * @param InCodePoint - 범위 검사를 수행할 코드 포인트 값입니다.
	 *
	 * @return 범위 내에 있다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool HasCodePointInRange(int32_t InCodePoint) const;


	/**
	 * 텍스트의 크기를 측정합니다.
	 * 측정 단위는 픽셀 단위입니다.
	 *
	 * @param InText - 측정할 텍스트입니다.
	 * @param OutWidth - 측정한 텍스트의 가로 크기입니다.
	 * @param OutHeight - 측정한 텍스트의 세로 크기입니다.
	 */
	void MeasureText(const std::wstring& InText, int32_t& OutWidth, int32_t& OutHeight) const;


private:
	/**
	 * 트루 타입 폰트를 로딩 합니다.
	 *
	 * @param InPath - 로딩할 트루 타입 폰트 리소스의 경로입니다.
	 * @param OutBuffer - 트루 타입 폰트의 리소스 버퍼입니다.
	 *
	 * @return 트루 타입 폰트 로딩에 성공하면 true, 그렇지 않으면 false를 반환합니다.
	 */
	static bool LoadTrueTypeFontFromFile(const std::string& InPath, std::vector<uint8_t>& OutBuffer);


	/**
	 * 텍스처 아틀라스 비트맵을 생성합니다.
	 * 이때, 텍스처 아틀라스의 가로 세로 크기는 같습니다.
	 *
	 * @param InBuffer - 트루 타입 폰트 리소스 버퍼입니다.
	 * @param InBeginCodePoint - 문자 텍스처 아틀라스의 코드 포인트 시작점입니다.
	 * @param InEndCodePoint - 문자 텍스처 아틀라스의 코드 포인트 끝점입니다.
	 * @param InFontSize - 폰트의 크기입니다.
	 * @param OutCharacterInfos - 텍스처 아틀라스 상의 코드 포인트에 대응하는 문자 위치 및 크기 정보입니다.
	 * @param OutSize - 텍스처 아틀라스 크기입니다.
	 *
	 * @return 생성된 텍스처 아틀라스 비트맵을 반환합니다.
	 */
	static std::shared_ptr<uint8_t[]> GenerateTextureAtlasBitmap(
		const std::vector<uint8_t>& InBuffer,
		int32_t InBeginCodePoint,
		int32_t InEndCodePoint,
		float InFontSize,
		std::vector<CharacterInfo>& OutCharacterInfos,
		int32_t& OutSize
	);


	/**
	 * 텍스처 아틀라스 비트맵으로 부터 텍스처 리소스를 생성합니다.
	 *
	 * @param InGraphics - 텍스처 리소스를 생성할 때 사용할 그래픽스 인스턴스입니다.
	 * @param InBitmap - 텍스처 아틀라스 비트맵입니다.
	 * @param InSize - 텍스처 아틀라스 비트맵의 가로 세로 크기입니다
	 *
	 * @throws 텍스처 리소스 생성에 실패하면 C++ 표준 예외를 던집니다.
	 *
	 * @return 텍스처 아틀라스를 반환합니다.
	 */
	static SDL_Texture* CreateTextureAtlasFromBitmap(
		Graphics& InGraphics,
		const std::shared_ptr<uint8_t[]>& InBitmap,
		const int32_t InSize
	);


private:
	/**
	 * 문자 텍스처 아틀라스의 코드 포인트 시작점입니다.
	 * 이때, 텍스처 아틀라스는 시작점을 포함합니다.
	 */
	int32_t BeginCodePoint_ = 0;


	/**
	 * 문자 텍스처 아틀라스의 코드 포인트 끝점입니다.
	 * 이때, 텍스처 아틀라스는 끝점을 포함합니다.
	 */
	int32_t EndCodePoint_ = 0;


	/**
	 * 텍스처 아틀라스 상의 코드 포인트에 대응하는 문자 위치 및 크기 정보입니다.
	 */
	std::vector<CharacterInfo> CharacterInfos_;


	/**
	 * 텍스처 아틀라스입니다.
	 */
	SDL_Texture* TextureAtlas_ = nullptr;
};