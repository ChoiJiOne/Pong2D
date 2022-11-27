#include <ToyEngine.h>

#include "Ball.h"
#include "Player.h"
#include "Ground.h"
#include "Background.h"

/**
 * Pong2D �����Դϴ�.
 */
class Pong2D : public GameFramework
{
public:
	/**
	 * ���� ������ �����Դϴ�.
	 * 
	 * START : ������ ���� �����Դϴ�.
	 * SETTING : ������ �⺻���� ������ �����ϴ� �����Դϴ�.
	 * PLAY : ������ �÷����ϰ� �ִ� �����Դϴ�.
	 * PAUSE : ������ ������ �����Դϴ�. 
	 * DONE : ������ ����� �����Դϴ�.
	 */
	enum class EGameState : int32_t
	{
		START   = 0,
		SETTING = 1,
		PLAY    = 2,
		PAUSE   = 3,
		DONE    = 4
	};

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
		QuitButton_.reset();
		SettingButton_.reset();
		StartButton_.reset();
		Ball_.reset();
		Player2_.reset();
		Player1_.reset();
		Ground_.reset();
		Background_.reset();
		Camera_.reset();
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
				EWindowFlags::SHOWN | EWindowFlags::RESIZABLE
			}
		);

		Renderer_ = std::make_unique<Renderer>(
			*Window_, 
			ERendererFlags::ACCELERATED | ERendererFlags::PRESENTVSYNC
		);

		Input_ = std::make_unique<Input>();
		Input_->RegisterWindowEvent(EWindowEvent::CODE_CLOSE, [&]() { bIsDone_ = true; });
		Input_->RegisterWindowEvent(
			EWindowEvent::CODE_RESIZED, 
			[&]() {
				int32_t Width = 0, Height = 0;
				Window_->GetSize(Width, Height);

				Camera_->SetSize(static_cast<float>(Width), static_cast<float>(Height));
				Background_->SetSize(static_cast<float>(Width), static_cast<float>(Height));
			}
		);

		ContentManager::Get().LoadFont(Text::GetHash("Font128"), *Renderer_, "font\\JetBrainsMono.ttf", 0x20, 0x7E, 128.0f);
		ContentManager::Get().LoadFont(Text::GetHash("Font64"), *Renderer_, "font\\JetBrainsMono.ttf", 0x20, 0x7E, 64.0f);
		ContentManager::Get().LoadFont(Text::GetHash("Font32"), *Renderer_, "font\\JetBrainsMono.ttf", 0x20, 0x7E, 32.0f);
		ContentManager::Get().LoadTexture(Text::GetHash("Space"), *Renderer_, "texture\\Space.png");
		ContentManager::Get().LoadTexture(Text::GetHash("PaddleRed"), *Renderer_, "texture\\PaddleRed.bmp");
		ContentManager::Get().LoadTexture(Text::GetHash("PaddleBlue"), *Renderer_, "texture\\PaddleBlue.bmp");
		ContentManager::Get().LoadTexture(Text::GetHash("Ball"), *Renderer_, "texture\\Ball.png");

		World_ = std::make_unique<World>();

		Camera_ = std::make_unique<Camera>(Vec2f(0.0f, 0.0f), 1000.0f, 800.0f, 0.0f, 100.0f);

		Background_ = std::make_unique<Background>(
			World_.get(),
			Text::GetHash("Background"),
			Vec2f(0.0f, 0.0f),
			1000.0f,
			800.0f
		);

		Player1_ = std::make_unique<Player>(
			World_.get(),
			Text::GetHash("Player1"),
			Player::EType::PLAYER1,
			Vec2f(-350.0f, 0.0f),
			25.0f,
			150.0f,
			350.0f
		);

		Player2_ = std::make_unique<Player>(
			World_.get(),
			Text::GetHash("Player2"),
			Player::EType::PLAYER2,
			Vec2f(+350.0f, 0.0f),
			25.0f,
			150.0f,
			350.0f
		);

		Ground_ = std::make_unique<Ground>(
			World_.get(),
			Text::GetHash("Ground"),
			Vec2f(0.0f, 0.0f),
			900.0f,
			450.0f,
			20.0f
		);

		Ball_ = std::make_unique<Ball>(
			World_.get(),
			Text::GetHash("Ball"),
			Vec2f(0.0f, 0.0f),
			15.0f,
			10.0f,
			300.0f
		);


		std::size_t Font32Key = Text::GetHash("Font32");

		StartButton_ = std::make_unique<Button>(
			Vec2f(500.0f, 400.0f),
			300.0f,
			80.0f,
			L"START",
			Font32Key,
			Color::Blue,
			Color::Black,
			[&]() {
				CurrentGameState_ = EGameState::PLAY;
			},
			0.95f
		);

		SettingButton_ = std::make_unique<Button>(
			Vec2f(500.0f, 500.0f),
			300.0f,
			80.0f,
			L"SETTING",
			Font32Key,
			Color::Blue,
			Color::Black,
			[&]() {
				CurrentGameState_ = EGameState::SETTING;
			},
			0.95f
		);

		QuitButton_ = std::make_unique<Button>(
			Vec2f(500.0f, 600.0f),
			300.0f,
			80.0f,
			L"QUIT",
			Font32Key,
			Color::Blue,
			Color::Black,
			[&]() {
				bIsDone_ = true;
			},
			0.95f
		);
	}


	/**
	 * Pong2D ������ �����մϴ�.
	 * 
	 * @throws ���� ���࿡ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Run() override
	{
		Timer_.Reset();

		while (!bIsDone_)
		{
			Input_->Tick();
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
		if (Input_->GetKeyPressState(EKeyCode::CODE_ESCAPE) == EPressState::PRESSED)
		{
			bIsDone_ = true;
		}

		std::array<Button*, 3> Buttons = { StartButton_.get(), SettingButton_.get(), QuitButton_.get() };
		std::array<GameObject*, 4> Objects = { Ground_.get(), Player1_.get(), Player2_.get(), Ball_.get() };

		switch (CurrentGameState_)
		{
		case EGameState::START:
			for (auto Object : Buttons)
			{
				Object->Update(*Input_);
			}
			break;

		case EGameState::SETTING:
			break;

		case EGameState::PLAY:
			for (auto Object : Objects)
			{
				Object->Update(*Input_, Timer_.GetDeltaSeconds());
			}
			break;

		case EGameState::PAUSE:
			break;

		case EGameState::DONE:
			break;
		}
	}


	/**
	 * Pong2D ������ ȭ�鿡 �׸��ϴ�.
	 * 
	 * @throws ������ ȭ�鿡 �׸��� �� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Render() override
	{
		Renderer_->BeginFrame(Color::Black);

		Background_->Render(*Renderer_, *Camera_);

		std::array<Button*, 3> Buttons = { StartButton_.get(), SettingButton_.get(), QuitButton_.get() };
		std::array<GameObject*, 4> Objects = {  Ground_.get(), Player1_.get(), Player2_.get(), Ball_.get() };

		switch (CurrentGameState_)
		{
		case EGameState::START:
			for (auto Object : Buttons)
			{
				Object->Render(*Renderer_);
			}
			break;

		case EGameState::SETTING:
			break;

		case EGameState::PLAY:
			for (auto Object : Objects)
			{
				Object->Render(*Renderer_, *Camera_);
			}
			break;

		case EGameState::PAUSE:
			break;

		case EGameState::DONE:
			break;
		}

		Renderer_->EndFrame();
	}


private:
	/**
	 * ���� ���� �����Դϴ�.
	 */
	EGameState CurrentGameState_ = EGameState::START;


	/**
	 * ���� Ÿ�̸��Դϴ�.
	 */
	Timer Timer_;


	/**
	 * ���� ī�޶��Դϴ�.
	 */
	std::unique_ptr<Camera> Camera_ = nullptr;


	/**
	 * ������ ��׶����Դϴ�.
	 */
	std::unique_ptr<Background> Background_ = nullptr;


	/**
	 * ���� �׶����Դϴ�.
	 */
	std::unique_ptr<Ground> Ground_ = nullptr;


	/**
	 * ���� �÷��̾�1�Դϴ�.
	 */
	std::unique_ptr<Player> Player1_ = nullptr;


	/**
	 * ���� �÷��̾�2�Դϴ�.
	 */
	std::unique_ptr<Player> Player2_ = nullptr;


	/**
	 * ���� ���Դϴ�.
	 */
	std::unique_ptr<Ball> Ball_ = nullptr;


	/**
	 * ���� ���� ��ư�Դϴ�.
	 */
	std::unique_ptr<Button> StartButton_ = nullptr;


	/**
	 * ���� ���� ��ư�Դϴ�.
	 */
	std::unique_ptr<Button> SettingButton_ = nullptr;


	/**
	 * ���� ���� ��ư�Դϴ�.
	 */
	std::unique_ptr<Button> QuitButton_ = nullptr;
};


int main(int argc, char* argv[])
{
	auto Game = std::make_unique<Pong2D>();
	Game->Init();
	Game->Run();

	return 0;
}