#pragma once
#include <algorithm/HYAlgorithmPlugin.h>
#include <common/HYPluginFactory.hpp>

namespace hy
{
	class AlgorithmDemo : public HYAlgorithmPlugin
	{
	public:
		AlgorithmDemo() = default;
		virtual ~AlgorithmDemo() = default;

		// Inherited via HYAlgorithmPlugin
		virtual int param(const std::string& file) override;
		virtual int compute(int index = -1, bool force = false, int max = 5) override;
	};

	HYPLUGIN_REGISTER_AUTO("AlgorithmDemo", AlgorithmDemo);
}

