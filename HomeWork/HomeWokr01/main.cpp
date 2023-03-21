
#include <iostream>

/*
구조체 : 서로 다른 타입의 변수 여러개를 한번에 묶어서
하나의 사용자정의 변수 타입으로 만들어줄 수 있는 기능이다.
struct 구조체 이름
{
	원하는 변수 선언
};
*/
struct MonsterInfo
{
	char	Name[32];
	int		Attack;
	int		Armor;
	int		HP;
	int		MP;
};


/*
프로젝트 속성의 구조체 멤버 맞춤이 기본값 으로 설정이
되어 있을 경우 구조체 내에서 용량이 가장 큰 변수의 크기를
기본값으로 잡아서 메모리를 할당하게 된다.
아래는 8바이트 단위로 잡게 될 것이다.
*/
struct Test
{
	char	A;
	char	B;
	double	Number1;
	int		Number;
	char	C;
};

// 멤버가 없더라도 최소바이트인 1바이트가 할당된다.
// 변수를 선언하게 되면 메모리에 공간이 잡혀야 하므로
// 최소 바이트 수인 1바이트 공간을 차지하게 하여 변수를
// 잡아주는 것이다.
struct Test1
{
};

struct Test2
{
	char	c;
};

int main()
{
	/*
	레퍼런스 : 다른 변수를 참조하여 값을 컨트롤 할 수 있다.
	처음 한번 참조하는 대상이 지정되면 다른 대상을 참조할 수
	없다.
	역참조가 필요 없고 바로 접근이 가능하다.

	레퍼런스는 저장 공간을 반드시 필요로 하는것은 아니다.
	하지만 컴파일러가 구현에 따라서 필요할경우 공간을
	만들수도 있다.
	메모리가 할당될 경우 포인터와 같은 크기의 공간이
	할당된다.
	*/
	int	Number = 100;
	int	Number1 = 200;
	int& Ref = Number;
	int* pNumber = &Number;
	int*& pRef = pNumber;

	Ref = 2020;
	pRef = &Number1;

	std::cout << Number << std::endl;
	std::cout << *pNumber << std::endl;

	// 구조체 선언 뒤에 = {} 을 해주면 구조체의 모든 멤버를
	// 0으로 초기화 해준다.
	MonsterInfo	Monster1 = { "오크", 10, 5, 50, 10 };

	// 선언된 구조체변수. 을 해서 안의 멤버에 접근할 수 있다.
	std::cout << "이름 : " << Monster1.Name << std::endl;
	std::cout << "공격력 : " << Monster1.Attack << std::endl;

	std::cout << "Size : " << sizeof(MonsterInfo) << std::endl;

	std::cout << "Test Size : " << sizeof(Test) << std::endl;

	std::cout << "Test1 Size : " << sizeof(Test1) << std::endl;

	Test1	Test1111;

	std::cout << "Test1 Size : " << sizeof(Test1111) << std::endl;
	std::cout << "Test2 Size : " << sizeof(Test2) << std::endl;

	MonsterInfo	MonsterArray[10] = {};

	MonsterArray[0].Attack = 100;

	MonsterInfo* pMonsterArray = MonsterArray;

	pMonsterArray[0].Attack = 300;

	std::cout << MonsterArray[0].Attack << std::endl;

	pMonsterArray = &Monster1;

	// 역참조와 . 둘중 .이 먼저 연산이 된다.
	// 그러므로 역참조가 먼저 연산이 되게 해야 하기 때문에
	// 괄호로 묶어준다.
	(*pMonsterArray).Attack = 400;

	// (*pMonsterArray). 이 내용을 줄여서
	// pMonsterArray->  로 사용할 수 있다.
	pMonsterArray->Attack = 999;

	std::cout << "Monster1 Attack : " << Monster1.Attack << std::endl;

	return 0;
}
