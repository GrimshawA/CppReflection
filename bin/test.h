#define AEON_INVOKABLE __attribute__(( annotate( "AEON_INVOKABLE" ) ))

class GameObject 
{
public:

	AEON_INVOKABLE void setHealth();
	AEON_INVOKABLE void setMaxHealth();
	void AEON_INVOKABLE getStuff();
	void one() AEON_INVOKABLE;

	AEON_INVOKABLE void set1();
	void set2();
	AEON_INVOKABLE void set3();
};

