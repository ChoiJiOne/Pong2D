#include <ToyEngine.h>

#include "Ball.h"
#include "Player.h"
#include "Ground.h"
#include "Background.h"

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
		Background_.reset();
		Camera_.reset();
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

		ContentManager::Get().LoadFont(Text::GetHash("Font"), *Renderer_, "font\\JetBrainsMono.ttf", 0x20, 0x7E, 128.0f);
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
	}


	/**
	 * Pong2D 게임을 실행합니다.
	 * 
	 * @throws 게임 실행에 실패하면 C++ 표준 예외를 던집니다.
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
	 * Pong2D 게임을 업데이트합니다.
	 * 
	 * @throws 게임 업데이트에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Update() override
	{
		if (Input_->GetKeyPressState(EKeyCode::CODE_ESCAPE) == EPressState::PRESSED)
		{
			bIsDone_ = true;
		}
	}


	/**
	 * Pong2D 게임을 화면에 그립니다.
	 * 
	 * @throws 게임을 화면에 그리는 데 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Render() override
	{
		Renderer_->BeginFrame(Color::Black);

		std::array<GameObject*, 1> Objects = { Background_.get() };
		for (auto Object : Objects)
		{
			Object->Render(*Renderer_, *Camera_);
		}

		Renderer_->DrawText2D(ContentManager::Get().GetFont(Text::GetHash("Font")), L"PONG 2D", Vec2i(500, 400), Color::White);

		Renderer_->EndFrame();
	}


private:
	/**
	 * 게임 타이머입니다.
	 */
	Timer Timer_;


	/**
	 * 게임 카메라입니다.
	 */
	std::unique_ptr<Camera> Camera_ = nullptr;


	/**
	 * 게임의 백그라운드입니다.
	 */
	std::unique_ptr<Background> Background_ = nullptr;
};


int main(int argc, char* argv[])
{
	auto Game = std::make_unique<Pong2D>();
	Game->Init();
	Game->Run();

	return 0;
}