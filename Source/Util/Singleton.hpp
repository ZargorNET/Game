#ifndef SFMLTEST_SINGLETON_HPP
#define SFMLTEST_SINGLETON_HPP

class Singleton {
public:
	Singleton(Singleton &other) = delete;

	Singleton(Singleton &&other) = delete;

	Singleton &operator=(Singleton &other) = delete;

	Singleton &operator=(Singleton &&other) = delete;

protected:
	Singleton() = default;

	virtual ~Singleton() = default;
};

#endif //GAME_SINGLETON_HPP
