#include <ToyEngine.h>

#include "Ball.h"
#include "Player.h"
#include "Ground.h"
#include "ScoreBoard.h"
#include "Background.h"

/**
 * Pong2D �����Դϴ�.
 */
class Pong2D : public GameFramework
{
public:
	/**
	 * Pong2D ������ �����Դϴ�.
	 */
	enum class EGameState : int32_t
	{
		START = 0,
		PLAY  = 1,
		PAUSE = 2,
		DONE  = 3
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
		ResetButton_.reset();
		ContinueButton_.reset();
		QuitButton_.reset();
		StartButton_.reset();
		ScoreBoard_.reset();
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

		int32_t Width = 1000, Height = 800;
		Window_ = std::make_unique<Window>(
			WindowConstructorParam{
				"Pong2D",
				200, 200,
				Width, Height,
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

				StartButton_->SetPosition(Vec2f(static_cast<float>(Width) / 2.0f, static_cast<float>(Height) * 2.0f / 3.0f));
				ContinueButton_->SetPosition(Vec2f(static_cast<float>(Width) / 2.0f, static_cast<float>(Height) * 2.0f / 3.0f));
				ResetButton_->SetPosition(Vec2f(static_cast<float>(Width) / 2.0f, static_cast<float>(Height) * 2.0f / 3.0f));
				QuitButton_->SetPosition(Vec2f(static_cast<float>(Width) / 2.0f, static_cast<float>(Height) * 5.0f / 6.0f));
			}
		);
		Input_->RegisterWindowEvent(
			EWindowEvent::CODE_FOCUS_LOST,
			[&]() {
				CurrentGameState_ = EGameState::PAUSE;
			}
		);
		Input_->RegisterWindowEvent(
			EWindowEvent::CODE_HIDDEN,
			[&]() {
				CurrentGameState_ = EGameState::PAUSE;
			}
		);

		ContentManager::Get().LoadMusic(Text::GetHash("Background"), "audio\\Background.mp3");
		ContentManager::Get().LoadSound(Text::GetHash("Click"), "audio\\Click.mp3");
		ContentManager::Get().LoadSound(Text::GetHash("Collision"), "audio\\Collision.mp3");
		ContentManager::Get().LoadFont(Text::GetHash("Font256"), *Renderer_, "font\\JetBrainsMono.ttf", 0x20, 0x7E, 256.0f);
		ContentManager::Get().LoadFont(Text::GetHash("Font128"), *Renderer_, "font\\JetBrainsMono.ttf", 0x20, 0x7E, 128.0f);
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
			400.0f
		);

		Player2_ = std::make_unique<Player>(
			World_.get(),
			Text::GetHash("Player2"),
			Player::EType::PLAYER2,
			Vec2f(+350.0f, 0.0f),
			25.0f,
			150.0f,
			400.0f
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
			400.0f
		);

		ScoreBoard_ = std::make_unique<ScoreBoard>(
			World_.get(),
			Text::GetHash("ScoreBoard"),
			Vec2f(0.0f, 300.0f),
			400.0f,
			100.0f,
			Color::Cyan
		);

		StartButton_ = std::make_unique<UIButton>(
			Vec2f(static_cast<float>(Width) / 2.0f, static_cast<float>(Height) * 2.0f / 3.0f),
			300.0f,
			80.0f,
			L"START",
			Text::GetHash("Font32"),
			Color::Cyan,
			Color::White,
			[&]() {
				CurrentGameState_ = EGameState::PLAY;
				Timer_.Start();
				ContentManager::Get().GetSound(Text::GetHash("Click")).Play();
			},
			0.98f
		);

		QuitButton_ = std::make_unique<UIButton>(
			Vec2f(static_cast<float>(Width) / 2.0f, static_cast<float>(Height) * 5.0f / 6.0f),
			300.0f,
			80.0f,
			L"QUIT",
			Text::GetHash("Font32"),
			Color::Cyan,
			Color::White,
			[&]() { bIsDone_ = true; },
			0.98f
		);

		ContinueButton_ = std::make_unique<UIButton>(
			Vec2f(static_cast<float>(Width) / 2.0f, static_cast<float>(Height) * 2.0f / 3.0f),
			300.0f,
			80.0f,
			L"CONTINUE",
			Text::GetHash("Font32"),
			Color::Cyan,
			Color::White,
			[&]() {
				CurrentGameState_ = EGameState::PLAY;
				Timer_.Start();
				ContentManager::Get().GetMusic(Text::GetHash("Background")).Resume();
				ContentManager::Get().GetSound(Text::GetHash("Click")).Play();
			},
			0.95f
		);

		ResetButton_ = std::make_unique<UIButton>(
			Vec2f(static_cast<float>(Width) / 2.0f, static_cast<float>(Height) * 2.0f / 3.0f),
			300.0f,
			80.0f,
			L"RESET",
			Text::GetHash("Font32"),
			Color::Cyan,
			Color::White,
			[&]() {
				CurrentGameState_ = EGameState::PLAY;
				Timer_.Reset();
				Player1_->Reset();
				Player2_->Reset();
				Ball_->Reset();

				ContentManager::Get().GetMusic(Text::GetHash("Background")).Play(true);
				ContentManager::Get().GetSound(Text::GetHash("Click")).Play();
			},
			0.95f
		);

		ContentManager::Get().GetMusic(Text::GetHash("Background")).Play(-1);
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
		if (CurrentGameState_ == EGameState::PLAY)
		{
			if (Input_->GetKeyPressState(EKeyCode::CODE_ESCAPE) == EPressState::PRESSED)
			{
				CurrentGameState_ = EGameState::PAUSE;
			}

			std::array<GameObject*, 5> Objects = { Ground_.get(), Player1_.get(), Player2_.get(), Ball_.get(), ScoreBoard_.get() };
			for (auto Object : Objects)
			{
				Object->Update(*Input_, Timer_.GetDeltaSeconds());
			}

			if (Player1_->GetScore() >= WinnerScore || Player2_->GetScore() >= WinnerScore)
			{
				CurrentGameState_ = EGameState::DONE;
			}
		}
		else
		{
			std::array<UIButton*, 2> Buttons;

			switch (CurrentGameState_)
			{
			case EGameState::START:
				Buttons = { StartButton_.get(), QuitButton_.get() };
				break;

			case EGameState::PAUSE:
				Buttons = { ContinueButton_.get(), QuitButton_.get() };
				break;

			case EGameState::DONE:
				Buttons = { ResetButton_.get(), QuitButton_.get() };
				break;
			}

			for (auto Button : Buttons)
			{
				Button->Update(*Input_);
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
		Renderer_->BeginFrame(Color::Black);

		Background_->Render(*Renderer_, *Camera_);

		if (CurrentGameState_ == EGameState::PLAY)
		{
			std::array<GameObject*, 5> Objects = { Ground_.get(), Player1_.get(), Player2_.get(), Ball_.get(), ScoreBoard_.get() };
			for (auto Object : Objects)
			{
				Object->Render(*Renderer_, *Camera_);
			}
		}
		else
		{
			int32_t Width = 0, Height = 0;
			Window_->GetSize(Width, Height);

			Vec2f TitlePosition(
				static_cast<float>(Width) / 2.0f,
				static_cast<float>(Height) / 3.0f
			);

			Renderer_->DrawText2D(
				ContentManager::Get().GetFont(Text::GetHash("Font256")),
				L"PONG 2D",
				Math::ConvertPixelCoordinate(TitlePosition),
				Color::Cyan
			);

			std::array<UIButton*, 2> Buttons;

			switch (CurrentGameState_)
			{
			case EGameState::START:
				Buttons = { StartButton_.get(), QuitButton_.get() };
				break;

			case EGameState::PAUSE:
				Buttons = { ContinueButton_.get(), QuitButton_.get() };
				break;

			case EGameState::DONE:
				Buttons = { ResetButton_.get(), QuitButton_.get() };
				break;
			}

			for (auto Button : Buttons)
			{
				Button->Render(*Renderer_);
			}
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
	 * �÷��̾ �̱������ ���� �� �����Դϴ�.
	 */
	int32_t WinnerScore = 5;


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
	 * ���� ���ھ� �����Դϴ�.
	 */
	std::unique_ptr<ScoreBoard> ScoreBoard_ = nullptr;


	/**
	 * ���� ���� ��ư�Դϴ�.
	 */
	std::unique_ptr<UIButton> StartButton_ = nullptr;


	/**
	 * ���� ���� ��ư�Դϴ�.
	 */
	std::unique_ptr<UIButton> QuitButton_ = nullptr;


	/**
	 * ������ ��� �����մϴ�.
	 */
	std::unique_ptr<UIButton> ContinueButton_ = nullptr;


	/**
	 * ������ �����ϰ� �����մϴ�.
	 */
	std::unique_ptr<UIButton> ResetButton_ = nullptr;
};


int main(int argc, char* argv[])
{
	auto Game = std::make_unique<Pong2D>();
	Game->Init();
	Game->Run();

	return 0;
}