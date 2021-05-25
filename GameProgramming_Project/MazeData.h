#pragma once
#include "headers_WhatIneed.h"

/*
미로 기본 형태 ↓
		{ {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		}
*/


class MazeData
{
private : 
	// 1번째 숫자 -> 맵 개수 , 2번째 숫자 -> Y ( 벽 포함 ), 3번째 숫자 X ( 벽 포함 )
	// 1 -> 벽, 0 -> 길, 2 -> 시작지점 3-> 골

	int mazeMap[5][12][12] ={
		{{1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		 {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
		 {1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
		 {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
		 {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1},
		 {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		 {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
		 {1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1},
		},
		{ {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		 {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		 {1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
		 {1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
		 {1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
		 {1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
		 {1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1},
		 {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1},
		},
		{ {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		 {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		 {1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		 {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		 {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		 {1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
		 {1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		 {1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
		 {1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
		 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1},
		},
		{ {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1},
		 {1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		 {1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		 {1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		 {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
		 {1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1},
		 {1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1},
		 {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
		 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1},
		},
		{ {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1},
		 {1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		 {1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		 {1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
		 {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		 {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		 {1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
		 {1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1},
		 {1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1},
		 {1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1},
		 {1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
		 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1},
		}
	};
	int mazeCount = 5;
public:
	void getMaze(int arr[][12]);
};

