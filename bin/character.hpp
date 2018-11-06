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

	void handle(const MessageOne one, MessageTwo two)
	{

	}

	void handle()
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

};


#endif // DEMO1_HPP_

