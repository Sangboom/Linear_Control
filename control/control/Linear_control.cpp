#pragma once
#define NOMINMAX
#include <iostream>
#include <thread>

#include <time.h>
#include <math.h>
#include "CLinear_actu.h"
#include "crtdbg.h"
#include <list>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int move_count = 0;

CLinear_actu* LM_G;



void move_ac(int position)
{
	LM_G->move_actu(position);
}

void move_linear(float first0, float first1, float second0, float second1) // �� �κ��� linear guide �����̰� �ϴ� �κ�
{
	float angle = ((second1 - first1) / (second0 - first0)); // ������ ��� �� ���⸦ ���
	float Sum_angle = 0;
	Sum_angle += angle;
	float total_angle;
	if (move_count == 3)
	{
		float total_angle = (Sum_angle + angle) / (move_count + 1);
	}
	else
	{
		float total_angle = Sum_angle / move_count;
	}
	// ������ ��� �� ���⸦ ����� �� �޴´�.
	float mola0 = (total_angle * (0 - second0) + second1); //  mola0 �� �������̿���

	float mola1 = (-1) * (0 + mola0); //mola1�� ���� linear guide�� ��� ���Դϴ�. 100���� �Ŵ� ������ ���� �� �ſ��� cm ��
	float linear_y = 0;
	if (mola1 > 0)
	{
		// �������� 0.274 ��ŭ ������ ���ܳ������� ����
		linear_y = mola1 + 0.274;
	}
	else if (mola1 < 0)
	{
		linear_y = mola1 - 0.274;
	}
	if (100 * mola1 > 55)
	{
		move_ac(55);
	}
	else if (100 * mola1 < -55)
	{
		move_ac(-55);
	}
	else
	{
		move_ac(100 * mola1);
	}
	cout << 100 * mola1 << endl;
	//move_ac(0);

}

int main()
{
	// �ϴ� ��� �Ǵ��� Ȯ��
	move_linear(1, 2, 3, 4);


	// Labview���� �ִ´�� �Է� �޾Ƽ�
	// ��ǥ��� ����


	return 0;
}