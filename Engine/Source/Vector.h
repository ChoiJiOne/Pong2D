#pragma once

#include <cstdint>
#include <algorithm>


/**
 * ���п��� �����ϴ� int32_t Ÿ���� 2���� ���� ����ü�Դϴ�.
 */
struct Vec2i
{
	/**
	 * 2���� ������ Ÿ���Դϴ�.
	 */
	using Vector = Vec2i;


	/**
	 * 2���� ������ ���� Ÿ���Դϴ�.
	 */
	using Type = int32_t;


	/**
	 * ������ ũ���Դϴ�.
	 */
	static const std::size_t SIZE = 2;


	/**
	 * ������ �⺻ �������Դϴ�.
	 * �̶�, ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	explicit Vector() noexcept : Vector(0) { }


	/**
	 * �������Դϴ�.
	 *
	 * @param InX - ������ ù ��° �����Դϴ�.
	 * @param InY - ������ �� ��° �����Դϴ�.
	 */
	explicit Vector(Type InX, Type InY) noexcept
	{
		Element_[0] = InX;
		Element_[1] = InY;
	}


	/**
	 * ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param InElement - ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector(const Type& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param InElement - ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector(Type&& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vector(const Vector& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vector(Vector&& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * ������ ���� ������ �Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 * 
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator=(const Vector& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * ������ ���� ������ �Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 * 
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator=(Vector&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * ������ ���ҿ� - ��ȣ�� ���մϴ�.
	 * 
	 * @return ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vector operator-() const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = -Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator+(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator+(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector operator-(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector operator-(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 * �̶�, ���� ����(Dot, Inner Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator*(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 * �̶�, ���� ����(Dot, Inner Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator*(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 * 
	 * @param ������ ������ �ǿ������Դϴ�.
	 * 
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator+=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator+=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator-=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator-=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator*=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator*=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �ֽ��ϴ�.
	 * 
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 * 
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 * 
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	Type& operator[](const int32_t& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �ֽ��ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	Type& operator[](int32_t&& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �����ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	const Type& operator[](const int32_t& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �����ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	const Type& operator[](int32_t&& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * ������ �����Դϴ�.
	 */
	Type Element_[SIZE];


	/**
	 * ������ ù ��° �����Դϴ�.
	 */
	Type& x = Element_[0];


	/**
	 * ������ �� ��° �����Դϴ�.
	 */
	Type& y = Element_[1];
};


/**
 * ���п��� �����ϴ� float Ÿ���� 2���� ���� ����ü�Դϴ�.
 */
struct Vec2f
{
	/**
	 * 2���� ������ Ÿ���Դϴ�.
	 */
	using Vector = Vec2f;


	/**
	 * 2���� ������ ���� Ÿ���Դϴ�.
	 */
	using Type = float;


	/**
	 * ������ ũ���Դϴ�.
	 */
	static const std::size_t SIZE = 2;


	/**
	 * ������ �⺻ �������Դϴ�.
	 * �̶�, ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	explicit Vector() noexcept : Vector(0.0f) { }


	/**
	 * �������Դϴ�.
	 *
	 * @param InX - ������ ù ��° �����Դϴ�.
	 * @param InY - ������ �� ��° �����Դϴ�.
	 */
	explicit Vector(Type InX, Type InY) noexcept
	{
		Element_[0] = InX;
		Element_[1] = InY;
	}


	/**
	 * ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param InElement - ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector(const Type& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param InElement - ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector(Type&& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vector(const Vector& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vector(Vector&& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * ������ ���� ������ �Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator=(const Vector& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * ������ ���� ������ �Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator=(Vector&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * ������ ���ҿ� - ��ȣ�� ���մϴ�.
	 *
	 * @return ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vector operator-() const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = -Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator+(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator+(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector operator-(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector operator-(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 * �̶�, ���� ����(Dot, Inner Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator*(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 * �̶�, ���� ����(Dot, Inner Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator*(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator+=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator+=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator-=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator-=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator*=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator*=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �ֽ��ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	Type& operator[](const int32_t& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �ֽ��ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	Type& operator[](int32_t&& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �����ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	const Type& operator[](const int32_t& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �����ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	const Type& operator[](int32_t&& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * ������ �����Դϴ�.
	 */
	Type Element_[SIZE];


	/**
	 * ������ ù ��° �����Դϴ�.
	 */
	Type& x = Element_[0];


	/**
	 * ������ �� ��° �����Դϴ�.
	 */
	Type& y = Element_[1];
};


/**
 * ���п��� �����ϴ� int32_t Ÿ���� 3���� ���� ����ü�Դϴ�.
 */
struct Vec3i
{
	/**
	 * 3���� ������ Ÿ���Դϴ�.
	 */
	using Vector = Vec3i;


	/**
	 * 3���� ������ ���� Ÿ���Դϴ�.
	 */
	using Type = int32_t;


	/**
	 * ������ ũ���Դϴ�.
	 */
	static const std::size_t SIZE = 3;


	/**
	 * ������ �⺻ �������Դϴ�.
	 * �̶�, ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	explicit Vector() noexcept : Vector(0) { }


	/**
	 * �������Դϴ�.
	 *
	 * @param InX - ������ ù ��° �����Դϴ�.
	 * @param InY - ������ �� ��° �����Դϴ�.
	 * @param InZ - ������ �� ��° �����Դϴ�.
	 */
	explicit Vector(Type InX, Type InY, Type InZ) noexcept
	{
		Element_[0] = InX;
		Element_[1] = InY;
		Element_[2] = InZ;
	}


	/**
	 * ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param InElement - ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector(const Type& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param InElement - ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector(Type&& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vector(const Vector& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vector(Vector&& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * ������ ���� ������ �Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator=(const Vector& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * ������ ���� ������ �Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator=(Vector&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * ������ ���ҿ� - ��ȣ�� ���մϴ�.
	 *
	 * @return ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vector operator-() const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = -Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator+(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator+(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector operator-(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector operator-(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 * �̶�, ���� ����(Dot, Inner Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator*(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 * �̶�, ���� ����(Dot, Inner Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator*(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator+=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator+=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator-=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator-=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator*=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator*=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �ֽ��ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	Type& operator[](const int32_t& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �ֽ��ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	Type& operator[](int32_t&& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �����ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	const Type& operator[](const int32_t& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �����ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	const Type& operator[](int32_t&& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * ������ �����Դϴ�.
	 */
	Type Element_[SIZE];


	/**
	 * ������ ù ��° �����Դϴ�.
	 */
	Type& x = Element_[0];


	/**
	 * ������ �� ��° �����Դϴ�.
	 */
	Type& y = Element_[1];


	/**
	 * ������ �� ��° �����Դϴ�.
	 */
	Type& z = Element_[2];
};


/**
 * ���п��� �����ϴ� float Ÿ���� 3���� ���� ����ü�Դϴ�.
 */
struct Vec3f
{
	/**
	 * 3���� ������ Ÿ���Դϴ�.
	 */
	using Vector = Vec3f;


	/**
	 * 3���� ������ ���� Ÿ���Դϴ�.
	 */
	using Type = float;


	/**
	 * ������ ũ���Դϴ�.
	 */
	static const std::size_t SIZE = 3;


	/**
	 * ������ �⺻ �������Դϴ�.
	 * �̶�, ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	explicit Vector() noexcept : Vector(0.0f) { }


	/**
	 * �������Դϴ�.
	 *
	 * @param InX - ������ ù ��° �����Դϴ�.
	 * @param InY - ������ �� ��° �����Դϴ�.
	 * @param InZ - ������ �� ��° �����Դϴ�.
	 */
	explicit Vector(Type InX, Type InY, Type InZ) noexcept
	{
		Element_[0] = InX;
		Element_[1] = InY;
		Element_[2] = InZ;
	}


	/**
	 * ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param InElement - ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector(const Type& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param InElement - ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector(Type&& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vector(const Vector& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vector(Vector&& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * ������ ���� ������ �Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator=(const Vector& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * ������ ���� ������ �Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator=(Vector&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * ������ ���ҿ� - ��ȣ�� ���մϴ�.
	 *
	 * @return ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vector operator-() const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = -Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator+(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator+(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector operator-(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector operator-(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 * �̶�, ���� ����(Dot, Inner Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator*(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 * �̶�, ���� ����(Dot, Inner Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator*(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator+=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator+=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator-=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator-=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator*=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator*=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �ֽ��ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	Type& operator[](const int32_t& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �ֽ��ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	Type& operator[](int32_t&& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �����ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	const Type& operator[](const int32_t& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �����ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	const Type& operator[](int32_t&& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * ������ �����Դϴ�.
	 */
	Type Element_[SIZE];


	/**
	 * ������ ù ��° �����Դϴ�.
	 */
	Type& x = Element_[0];


	/**
	 * ������ �� ��° �����Դϴ�.
	 */
	Type& y = Element_[1];


	/**
	 * ������ �� ��° �����Դϴ�.
	 */
	Type& z = Element_[2];
};


/**
 * ���п��� �����ϴ� int32_t Ÿ���� 4���� ���� ����ü�Դϴ�.
 */
struct Vec4i
{
	/**
	 * 4���� ������ Ÿ���Դϴ�.
	 */
	using Vector = Vec4i;


	/**
	 * 4���� ������ ���� Ÿ���Դϴ�.
	 */
	using Type = int32_t;


	/**
	 * ������ ũ���Դϴ�.
	 */
	static const std::size_t SIZE = 4;


	/**
	 * ������ �⺻ �������Դϴ�.
	 * �̶�, ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	explicit Vector() noexcept : Vector(0) { }


	/**
	 * �������Դϴ�.
	 *
	 * @param InX - ������ ù ��° �����Դϴ�.
	 * @param InY - ������ �� ��° �����Դϴ�.
	 * @param InZ - ������ �� ��° �����Դϴ�.
	 * @param InW - ������ �� ��° �����Դϴ�.
	 */
	explicit Vector(Type InX, Type InY, Type InZ, Type InW) noexcept
	{
		Element_[0] = InX;
		Element_[1] = InY;
		Element_[2] = InZ;
		Element_[3] = InW;
	}


	/**
	 * ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param InElement - ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector(const Type& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param InElement - ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector(Type&& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vector(const Vector& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vector(Vector&& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * ������ ���� ������ �Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator=(const Vector& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * ������ ���� ������ �Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator=(Vector&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * ������ ���ҿ� - ��ȣ�� ���մϴ�.
	 *
	 * @return ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vector operator-() const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = -Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator+(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator+(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector operator-(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector operator-(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 * �̶�, ���� ����(Dot, Inner Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator*(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 * �̶�, ���� ����(Dot, Inner Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator*(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator+=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator+=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator-=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator-=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator*=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator*=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �ֽ��ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	Type& operator[](const int32_t& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �ֽ��ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	Type& operator[](int32_t&& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �����ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	const Type& operator[](const int32_t& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �����ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	const Type& operator[](int32_t&& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * ������ �����Դϴ�.
	 */
	Type Element_[SIZE];



	/**
	 * ������ ù ��° �����Դϴ�.
	 */
	Type& x = Element_[0];


	/**
	 * ������ �� ��° �����Դϴ�.
	 */
	Type& y = Element_[1];


	/**
	 * ������ �� ��° �����Դϴ�.
	 */
	Type& z = Element_[2];


	/**
	 * ������ �� ��° �����Դϴ�.
	 */
	Type& w = Element_[3];
};


/**
 * ���п��� �����ϴ� float Ÿ���� 4���� ���� ����ü�Դϴ�.
 */
struct Vec4f
{
	/**
	 * 4���� ������ Ÿ���Դϴ�.
	 */
	using Vector = Vec4f;


	/**
	 * 4���� ������ ���� Ÿ���Դϴ�.
	 */
	using Type = float;


	/**
	 * ������ ũ���Դϴ�.
	 */
	static const std::size_t SIZE = 4;


	/**
	 * ������ �⺻ �������Դϴ�.
	 * �̶�, ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	explicit Vector() noexcept : Vector(0.0f) { }


	/**
	 * �������Դϴ�.
	 *
	 * @param InX - ������ ù ��° �����Դϴ�.
	 * @param InY - ������ �� ��° �����Դϴ�.
	 * @param InZ - ������ �� ��° �����Դϴ�.
	 * @param InW - ������ �� ��° �����Դϴ�.
	 */
	explicit Vector(Type InX, Type InY, Type InZ, Type InW) noexcept
	{
		Element_[0] = InX;
		Element_[1] = InY;
		Element_[2] = InZ;
		Element_[3] = InW;
	}


	/**
	 * ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param InElement - ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector(const Type& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param InElement - ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector(Type&& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vector(const Vector& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vector(Vector&& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * ������ ���� ������ �Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator=(const Vector& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * ������ ���� ������ �Դϴ�.
	 *
	 * @param InInstance - ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator=(Vector&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * ������ ���ҿ� - ��ȣ�� ���մϴ�.
	 *
	 * @return ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vector operator-() const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = -Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator+(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator+(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector operator-(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector operator-(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 * �̶�, ���� ����(Dot, Inner Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator*(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 * �̶�, ���� ����(Dot, Inner Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param InInstance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector operator*(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator+=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator+=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator-=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator-=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator*=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector& operator*=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �ֽ��ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	Type& operator[](const int32_t& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �ֽ��ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	Type& operator[](int32_t&& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �����ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	const Type& operator[](const int32_t& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * ������ ���Ҹ� �ε����� �����մϴ�.
	 * �̶�, ������ ���� ������ �� �����ϴ�.
	 *
	 * @param InIndex - ������ �ε��� ���Դϴ�.
	 *
	 * @throws �ε��� ���� ������ ����� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
	 *
	 * @return �ε����� �����ϴ� ���Ҹ� ��ȯ�մϴ�.
	 */
	const Type& operator[](int32_t&& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * ������ �����Դϴ�.
	 */
	Type Element_[SIZE];


	/**
	 * ������ ù ��° �����Դϴ�.
	 */
	Type& x = Element_[0];


	/**
	 * ������ �� ��° �����Դϴ�.
	 */
	Type& y = Element_[1];


	/**
	 * ������ �� ��° �����Դϴ�.
	 */
	Type& z = Element_[2];


	/**
	 * ������ �� ��° �����Դϴ�.
	 */
	Type& w = Element_[3];
};