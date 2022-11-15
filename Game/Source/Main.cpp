#include "Player.h"
#include "Ground.h"

#include "ToyEngine.h"


/**
 * Pong2D �����Դϴ�.
 */
class Pong2D : public GameFramework
{
public:
	/**
	 * Pong2D ������ ����Ʈ �������Դϴ�.
	 * �̶�, �ʱ�ȭ�� �����ϱ� ���ؼ��� Init �޼��带 ȣ���ؾ� �մϴ�.
	 */
	Pong2D() = default;


	/**
	 * Pong2D ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Pong2D() 
	{
		Ground_.reset();
		Player1_.reset();
		Player2_.reset();
	}


	/**
	 * ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Pong2D);


	/**
	 * Pong2D ������ �ʱ�ȭ�մϴ�.
	 * 
	 * @throws ���� �ʱ�ȭ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
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
	 * Pong2D ������ �����մϴ�.
	 * 
	 * @throws ���� ���࿡ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
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
	 * Pong2D ������ ������Ʈ�մϴ�.
	 * 
	 * @throws ���� ������Ʈ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Update() override
	{
		Player1_->Update(*Input_, Timer_.GetDeltaSeconds());
		Player2_->Update(*Input_, Timer_.GetDeltaSeconds());
		Ground_->Update(*Input_, Timer_.GetDeltaSeconds());
	}


	/**
	 * Pong2D ������ ȭ�鿡 �׸��ϴ�.
	 * 
	 * @throws ������ ȭ�鿡 �׸��� �� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
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
	 * ���� Ÿ�̸��Դϴ�.
	 */
	Timer Timer_;


	/**
	 * ���� �÷��̾�1�Դϴ�.
	 */
	std::unique_ptr<Player> Player1_ = nullptr;


	/**
	 * ���� �÷��̾�2�Դϴ�.
	 */
	std::unique_ptr<Player> Player2_ = nullptr;


	/**
	 * ���� �׶����Դϴ�.
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