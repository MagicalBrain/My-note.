#pragma once

#ifdef _USRDLL
#ifdef HYDEVICESDK_EXPORTS
#define HYDEVICESDK_API __declspec(dllexport)
#else
#define HYDEVICESDK_API __declspec(dllimport)
#endif
#else
#define HYDEVICESDK_API
#endif 