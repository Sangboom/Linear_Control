
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

// LM_G = new CLinear_actu();

void move_ac(int position)
{
	LM_G->move_actu(position);
}

void move_linear(float first0, float first1, float second0, float second1) // 이 부분이 linear guide 움직이게 하는 부분
{
	float angle = ((second1 - first1) / (second0 - first0)); // 두점을 잡고 그 기울기를 계산
	float Sum_angle = 0;
	Sum_angle += angle;
	float total_angle=0;
	if (move_count == 3)
	{
		float total_angle = (Sum_angle + angle) / (move_count + 1);
	}
	else
	{
		float total_angle = Sum_angle / move_count;
	}
	// 두점을 잡고 그 기울기를 계산한 걸 받는다.
	float mola0 = (total_angle * (0 - second0) + second1); //  mola0 는 직선식이예요

	float mola1 = (-1) * (0 + mola0); //mola1은 이제 linear guide가 닿는 곳입니다. 100곱한 거는 스케일 맞춰 준 거예요 cm 로
	float linear_y = 0;
	if (mola1 > 0)
	{
		// 이은택이 0.274 만큼 공간을 남겨놓으려고 빼놈
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

void initialize() 
{
	LM_G = new CLinear_actu();
}

int main()
{
	// 일단 제어가 되는지 확인
	printf("ddd");
	move_linear(1, 2, 3, 4);


	// Labview에서 주는대로 입력 받아서
	// 좌표대로 제어


	return 0;
}