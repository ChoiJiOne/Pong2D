#include "Player.h"
#include "Ground.h"

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
		Ground_.reset();
		Player1_.reset();
		Player2_.reset();
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

		World_ = std::make_unique<World>(1000.0f, 800.0f);

		Ground_ = std::make_unique<Ground>(World_.get(), Vec2f(500.0f, 400.0f), 900.0f, 450.0f);
		Player1_ = std::make_unique<Player>(World_.get(), Player::EType::PLAYER1, Vec2f(150.0f, 400.0f), 25.0f, 150.0f, 300.0f);
		Player2_ = std::make_unique<Player>(World_.get(), Player::EType::PLAYER2, Vec2f(850.0f, 400.0f), 25.0f, 150.0f, 300.0f);
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
		Player1_->Update(*Input_, Timer_.GetDeltaSeconds());
		Player2_->Update(*Input_, Timer_.GetDeltaSeconds());
		Ground_->Update(*Input_, Timer_.GetDeltaSeconds());
	}


	/**
	 * Pong2D 게임을 화면에 그립니다.
	 * 
	 * @throws 게임을 화면에 그리는 데 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Render() override
	{
		Graphics_->BeginFrame(ColorUtils::Black);

		Ground_->Render(*Graphics_);
		Player1_->Render(*Graphics_);
		Player2_->Render(*Graphics_);

		Graphics_->EndFrame();
	}


private:
	/**
	 * 게임 타이머입니다.
	 */
	Timer Timer_;


	/**
	 * 게임 플레이어1입니다.
	 */
	std::unique_ptr<Player> Player1_ = nullptr;


	/**
	 * 게임 플레이어2입니다.
	 */
	std::unique_ptr<Player> Player2_ = nullptr;


	/**
	 * 게임 그라운드입니다.
	 */
	std::unique_ptr<Ground> Ground_ = nullptr;
};


int main(int argc, char* argv[])
{
	auto Game = std::make_unique<Pong2D>();
	Game->Init();
	Game->Run();

	return 0;
}