#ifndef DEMO1_HPP_
#define DEMO1_HPP_

class GameObject 
{
public:

	
};

class Character : public GameObject
{
public:

	Q_PROPERTY()

	int myHealth;

	void handle1(const apex::scene one, MessageTwo two)
	{

	}

	void handle2(const apex::scene& s)
	{

	}

	void handle3(const MessageFour& four, scene& s)
	{
		s.doThings(four);
	}

	void handle4(const HealthEvent& e)
	{
		health -= e;
	}

private:
	int health;
	float timeLeft;
	apex::scene scene;
};


#endif // DEMO1_HPP_

