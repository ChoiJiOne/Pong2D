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
		Camera_.reset();
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

		Camera_ = std::make_unique<Camera>(Vec2f(0.0f, 0.0f), 1000.0f, 800.0f);

		Ground_ = std::make_unique<Ground>(World_.get(), Vec2f(0.0f, 0.0f), 900.0f, 450.0f);
		Player1_ = std::make_unique<Player>(World_.get(), Player::EType::PLAYER1, Vec2f(-350.0f, 0.0f), 25.0f, 150.0f, 350.0f);
		Player2_ = std::make_unique<Player>(World_.get(), Player::EType::PLAYER2, Vec2f(+350.0f, 0.0f), 25.0f, 150.0f, 350.0f);
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
		const std::list<GameObject*> Objects = World_->GetAllObject();
		for (auto Object : Objects)
		{
			Object->Update(*Input_, Timer_.GetDeltaSeconds());
		}

		const std::array<GameObject*, 2> Players = { Player1_.get(), Player2_.get() };
		for (auto player : Players)
		{
			if (!Ground_->IsInclude(*player))
			{
				Vec2f Position = player->GetCenter();
				float Distance = Ground_->GetHeight() / 2.0f - player->GetHeight() / 2.0f;

				Position.y = (Position.y > 0.0f) ? Distance : -Distance;

				player->SetCenter(Position);
			}
		}
	}


	/**
	 * Pong2D ������ ȭ�鿡 �׸��ϴ�.
	 * 
	 * @throws ������ ȭ�鿡 �׸��� �� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Render() override
	{
		Graphics_->BeginFrame(ColorUtils::Black);

		const std::list<GameObject*> Objects = World_->GetAllObject();
		for (auto Object : Objects)
		{
			Object->Render(*Graphics_, *Camera_);
		}

		Graphics_->EndFrame();
	}


private:
	/**
	 * ���� Ÿ�̸��Դϴ�.
	 */
	Timer Timer_;

	
	/**
	 * ���� ī�޶��Դϴ�.
	 */
	std::unique_ptr<Camera> Camera_ = nullptr;


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