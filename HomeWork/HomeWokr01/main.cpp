
#include <iostream>

/*
����ü : ���� �ٸ� Ÿ���� ���� �������� �ѹ��� ���
�ϳ��� ��������� ���� Ÿ������ ������� �� �ִ� ����̴�.
struct ����ü �̸�
{
	���ϴ� ���� ����
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
������Ʈ �Ӽ��� ����ü ��� ������ �⺻�� ���� ������
�Ǿ� ���� ��� ����ü ������ �뷮�� ���� ū ������ ũ�⸦
�⺻������ ��Ƽ� �޸𸮸� �Ҵ��ϰ� �ȴ�.
�Ʒ��� 8����Ʈ ������ ��� �� ���̴�.
*/
struct Test
{
	char	A;
	char	B;
	double	Number1;
	int		Number;
	char	C;
};

// ����� ������ �ּҹ���Ʈ�� 1����Ʈ�� �Ҵ�ȴ�.
// ������ �����ϰ� �Ǹ� �޸𸮿� ������ ������ �ϹǷ�
// �ּ� ����Ʈ ���� 1����Ʈ ������ �����ϰ� �Ͽ� ������
// ����ִ� ���̴�.
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
	���۷��� : �ٸ� ������ �����Ͽ� ���� ��Ʈ�� �� �� �ִ�.
	ó�� �ѹ� �����ϴ� ����� �����Ǹ� �ٸ� ����� ������ ��
	����.
	�������� �ʿ� ���� �ٷ� ������ �����ϴ�.

	���۷����� ���� ������ �ݵ�� �ʿ�� �ϴ°��� �ƴϴ�.
	������ �����Ϸ��� ������ ���� �ʿ��Ұ�� ������
	������� �ִ�.
	�޸𸮰� �Ҵ�� ��� �����Ϳ� ���� ũ���� ������
	�Ҵ�ȴ�.
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

	// ����ü ���� �ڿ� = {} �� ���ָ� ����ü�� ��� �����
	// 0���� �ʱ�ȭ ���ش�.
	MonsterInfo	Monster1 = { "��ũ", 10, 5, 50, 10 };

	// ����� ����ü����. �� �ؼ� ���� ����� ������ �� �ִ�.
	std::cout << "�̸� : " << Monster1.Name << std::endl;
	std::cout << "���ݷ� : " << Monster1.Attack << std::endl;

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

	// �������� . ���� .�� ���� ������ �ȴ�.
	// �׷��Ƿ� �������� ���� ������ �ǰ� �ؾ� �ϱ� ������
	// ��ȣ�� �����ش�.
	(*pMonsterArray).Attack = 400;

	// (*pMonsterArray). �� ������ �ٿ���
	// pMonsterArray->  �� ����� �� �ִ�.
	pMonsterArray->Attack = 999;

	std::cout << "Monster1 Attack : " << Monster1.Attack << std::endl;

	return 0;
}
