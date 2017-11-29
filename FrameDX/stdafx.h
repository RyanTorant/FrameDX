// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define NOMINMAX
#include <Windows.h>
#include <d3d11.h>
#include <d3d11_1.h>
#include <d3d11_2.h>
#include <d3d11_3.h>
#include <d3d11_4.h>
#include <dxgi1_2.h>
#include <cinttypes>
#include <string>
#include <functional>
#include <ppl.h>
#include <concurrent_vector.h>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <locale>
#include <codecvt>
#include <thread>

using namespace std;