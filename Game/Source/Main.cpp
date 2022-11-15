#include "ToyEngine.h"


/**
 * Pong2D 게임입니다.
 */
class Pong2D : public GameFramework
{
public:
	/**
	 * Pong2D 게임의 디폴트 생성자입니다.
	 * 이때, 초기화를 수행하기 위해서는 Init 메서드를 호출해야 합니다.
	 */
	Pong2D() = default;


	/**
	 * Pong2D 게임의 가상 소멸자입니다.
	 */
	virtual ~Pong2D() 
	{

	}


	/**
	 * 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Pong2D);


	/**
	 * Pong2D 게임을 초기화합니다.
	 * 
	 * @throws 게임 초기화에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Init() override
	{
		GameFramework::Init();

		Window_ = std::make_unique<Window>(
			WindowConstructorParam{
				"Pong2D",
				200, 200,
				1000, 800,
				EWindowFlags::SHOWN
			}
		);

		Graphics_ = std::make_unique<Graphics>(
			*Window_, 
			EGraphicsFlags::ACCELERATED | EGraphicsFlags::PRESENTVSYNC
		);

		Input_ = std::make_unique<Input>();

		CenterPosition = Vec2i(500, 400);
	}


	/**
	 * Pong2D 게임을 실행합니다.
	 * 
	 * @throws 게임 실행에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Run() override
	{
		Timer_.Reset();

		while (!bIsDone_ && !Input_->Tick())
		{
			Timer_.Tick();

			Update();
			Render();
		}
	}


	/**
	 * Pong2D 게임을 업데이트합니다.
	 * 
	 * @throws 게임 업데이트에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Update() override
	{

	}


	/**
	 * Pong2D 게임을 화면에 그립니다.
	 * 
	 * @throws 게임을 화면에 그리는 데 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Render() override
	{
		Graphics_->BeginFrame(ColorUtils::Black);

		Graphics_->EndFrame();
	}


private:
	/**
	 * 게임 타이머입니다.
	 */
	Timer Timer_;


	/**
	 * Pong2D 게임의 중심 지점입니다.
	 */
	Vec2i CenterPosition;
};


int main(int argc, char* argv[])
{
	auto Game = std::make_unique<Pong2D>();
	Game->Init();
	Game->Run();

	return 0;
}