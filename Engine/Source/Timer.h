#pragma once

#include <cstdint>


/**
 * Ÿ�̸� Ŭ�����Դϴ�.
 * �̶�, Ÿ�̸� Ŭ������ �����ڴ� �ʱ�ȭ�� �������� �����Ƿ�
 * �ݵ�� Start Ȥ�� Reset �޼��带 ȣ���ؾ� �մϴ�.
 */
class Timer
{
public:
	/**
	 * Ÿ�̸� Ŭ������ �⺻ �������Դϴ�.
	 */
	Timer() = default;


	/**
	 * Ÿ�̸� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	Timer(Timer&& InInstance) noexcept
		: bIsStop_(InInstance.bIsStop_)
		, BaseTime_(InInstance.BaseTime_)
		, PausedTime_(InInstance.PausedTime_)
		, StopTime_(InInstance.StopTime_)
		, PrevTime_(InInstance.PrevTime_)
		, CurrTime_(InInstance.CurrTime_) {}


	/**
	 * Ÿ�̸� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	Timer(const Timer& InInstance) noexcept
		: bIsStop_(InInstance.bIsStop_)
		, BaseTime_(InInstance.BaseTime_)
		, PausedTime_(InInstance.PausedTime_)
		, StopTime_(InInstance.StopTime_)
		, PrevTime_(InInstance.PrevTime_)
		, CurrTime_(InInstance.CurrTime_) {}


	/**
	 * Ÿ�̸� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Timer();


	/**
	 * Ÿ�̸� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	Timer& operator=(Timer&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		bIsStop_ = InInstance.bIsStop_;
		BaseTime_ = InInstance.BaseTime_;
		PausedTime_ = InInstance.PausedTime_;
		StopTime_ = InInstance.StopTime_;
		PrevTime_ = InInstance.PrevTime_;
		CurrTime_ = InInstance.CurrTime_;

		return *this;
	}


	/**
	 * Ÿ�̸� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	Timer& operator=(const Timer& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		bIsStop_ = InInstance.bIsStop_;
		BaseTime_ = InInstance.BaseTime_;
		PausedTime_ = InInstance.PausedTime_;
		StopTime_ = InInstance.StopTime_;
		PrevTime_ = InInstance.PrevTime_;
		CurrTime_ = InInstance.CurrTime_;

		return *this;
	}


	/**
	 * Ÿ�̸��� �� ���� ��Ÿ �ð����� ����ϴ�.
	 * 
	 * @return �� ������ ��Ÿ �ð����� ��ȯ�մϴ�.
	 */
	float GetDeltaSeconds() const;


	/**
	 * Ÿ�̸��� �и��� ������ ��Ÿ �ð����� ����ϴ�.
	 * 
	 * @return �и��� ������ ��Ÿ �ð����� ��ȯ�մϴ�.
	 */
	float GetDeltaMilliseconds() const;


	/**
	 * Ÿ�̸Ӱ� ������ �ð��� ������ ��ü �ð����� ��ȯ�մϴ�.
	 * 
	 * @return Ÿ�̸Ӱ� ���۵� ������ ������ �ð��� ������ ��ü �ð����� ��ȯ�մϴ�.
	 */
	float GetTotalSeconds() const;


	/**
	 * Ÿ�̸Ӱ� ������ �ð��� ������ ��ü �ð����� ��ȯ�մϴ�.
	 *
	 * @return Ÿ�̸Ӱ� ���۵� ������ ������ �ð��� ������ ��ü �ð����� ��ȯ�մϴ�.
	 */
	float GetTotalMilliseconds() const;


	/**
	 * Ÿ�̸��� ��� ���¸� �����մϴ�.
	 */
	void Reset();


	/**
	 * Ÿ�̸Ӹ� �����մϴ�.
	 * �̶�, Ÿ�̸Ӱ� �����Ǿ� �ִٸ� �߽õ� �������� ���۵˴ϴ�.
	 */
	void Start();


	/**
	 * Ÿ�̸Ӹ� ������ŵ�ϴ�.
	 */
	void Stop();


	/**
	 * Ÿ�̸Ӹ� ������Ʈ�մϴ�.
	 */
	void Tick();


private:
	/**
	 * Ÿ�̸��� ���� ���θ� Ȯ���մϴ�.
	 */
	bool bIsStop_ = false;


	/**
	 * Ÿ�̸Ӱ� ���۵� �ð��Դϴ�.
	 */
	uint64_t BaseTime_ = 0ULL;


	/**
	 * Ÿ�̸Ӱ� ������ ������ ���� �ð��� �Դϴ�.
	 */
	uint64_t PausedTime_ = 0ULL;


	/**
	 * Ÿ�̸Ӱ� ������ �ð��Դϴ�.
	 */
	uint64_t StopTime_ = 0ULL;


	/**
	 * ������ Tick ȣ�� �ð��Դϴ�.
	 */
	uint64_t PrevTime_ = 0ULL;


	/**
	 * Tick ȣ�� �ð��Գ��ϴ�.
	 */
	uint64_t CurrTime_ = 0ULL;
};